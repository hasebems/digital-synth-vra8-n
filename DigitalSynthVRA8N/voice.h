#include "common.h"

template <uint8_t T>
class Voice {
  static uint8_t m_count;
  static uint8_t m_eg0_decay_sustain;
  static uint8_t m_eg1_decay_sustain;
  static uint8_t m_active_note_number;
  static uint8_t m_on_note[16];
  static uint8_t m_output_error;
  static uint8_t m_portamento;
  static boolean m_legato;

public:
  INLINE static void initialize() {
    m_active_note_number = NOTE_NUMBER_INVALID;
    for (uint8_t i = 0; i < 16; ++i) {
      m_on_note[i] = 0x00;
    }
    m_output_error = 0;
    m_portamento = 0;
    m_legato = true;
    IOsc<0>::initialize();
    IFilter<0>::initialize();
    IAmp<0>::initialize();
    IEnvGen<0>::initialize();
    IEnvGen<1>::initialize();
    set_env_decay(0);
    set_amp_env_sus(0);
  }

  INLINE static void note_on(uint8_t note_number, uint8_t velocity) {
    static_cast<void>(velocity);
    set_on_note(note_number);
    if (m_legato) {
      // Single Trigger and Auto Portamento
      uint8_t n = get_active_on_note();
      if (m_active_note_number != NOTE_NUMBER_INVALID) {
        m_active_note_number = n;
        IOsc<0>::set_portamento(m_portamento);
        IOsc<0>::note_on(n);
      } else {
        m_active_note_number = n;
        IOsc<0>::set_portamento(0);
        IOsc<0>::note_on(n);
        IEnvGen<0>::note_on();
        IEnvGen<1>::note_on();
      }
    } else {
      // Multi Trigger and Portamento On
      m_active_note_number = note_number;
      IOsc<0>::set_portamento(m_portamento);
      IOsc<0>::note_on(note_number);
      IEnvGen<0>::note_on();
      IEnvGen<1>::note_on();
    }
  }

  INLINE static void note_off(uint8_t note_number) {
    if (m_legato) {
      clear_on_note(note_number);
      uint8_t n = get_active_on_note();
      if (n == NOTE_NUMBER_INVALID) {
        all_note_off();
      }
      else {
        m_active_note_number = n;
        IOsc<0>::set_portamento(m_portamento);
        IOsc<0>::note_on(n);
      }
    } else {
      if (m_active_note_number == note_number) {
        all_note_off();
      }
    }
  }

  INLINE static void all_note_off() {
    for (uint8_t i = 0; i < 16; ++i) {
      m_on_note[i] = 0x00;
    }
    m_active_note_number = NOTE_NUMBER_INVALID;
    IEnvGen<0>::note_off();
    IEnvGen<1>::note_off();
  }

  INLINE static void control_change(uint8_t controller_number, uint8_t controller_value) {
    switch (controller_number) {
    case FILTER_CUTOFF:
      IFilter<0>::set_cutoff(controller_value);
      break;
    case FILTER_RESO:
      IFilter<0>::set_resonance(controller_value);
      break;
    case FILTER_EG_AMT:
      IFilter<0>::set_env_amt(controller_value);
      break;
    case OSC_COLOR_1:
      IOsc<0>::set_waveform(controller_value);
      if (controller_value < 32) {
        IOsc<0>::set_sub_osc_level((31 - controller_value) << 2);
      } else if (controller_value >= 96) {
        IOsc<0>::set_sub_osc_level((controller_value - 96) << 2);
      } else {
        IOsc<0>::set_sub_osc_level(0);
      }
      break;
    case CC30:
      IOsc<0>::set_lfo_rate(controller_value);
      break;
    case CC31:
      IOsc<0>::set_lfo_depth<0>(controller_value);
      break;
    case MODULATION:
      IOsc<0>::set_lfo_depth<1>(controller_value);
      break;
    case MOD_RATE:
      IOsc<0>::set_detune(controller_value);
      break;
    case MOD_DEPTH:
      IOsc<0>::set_mix(controller_value);
      break;
    case CC25:
      IOsc<0>::set_detune_noise_gen_amt(controller_value);
      break;
    case PORTAMENTO:
      m_portamento = controller_value;
      break;
    case CC24:
      if (controller_value < 64) {
        if (m_legato) {
          m_legato = false;
          all_note_off();
        }
      } else {
        if (!m_legato) {
          m_legato = true;
          all_note_off();
        }
      }
      break;
    case FILTER_EG:
      set_env_decay(controller_value);
      break;
    case AMP_EG:
      set_amp_env_sus(controller_value);
      break;
    case ALL_NOTES_OFF:
    case OMNI_MODE_OFF:
    case OMNI_MODE_ON:
    case MONO_MODE_ON:
    case POLY_MODE_ON:
      all_note_off();
      break;
    }
  }

  INLINE static void pitch_bend(uint8_t lsb, uint8_t msb) {
    uint16_t pitch_bend = (msb << 7) + lsb - 8192;
    IOsc<0>::set_pitch_bend(pitch_bend);
  }

  INLINE static int8_t clock() {
    m_count++;

    int16_t osc_output = IOsc<0>::clock(m_count);
    uint8_t env_gen_output_0 = IEnvGen<0>::clock(m_count);
    int16_t filter_output = IFilter<0>::clock(m_count, osc_output, env_gen_output_0);
    uint8_t env_gen_output_1 = IEnvGen<1>::clock(m_count);
    int16_t amp_output = IAmp<0>::clock(filter_output, env_gen_output_1);

    // error diffusion
    int16_t output = amp_output + m_output_error;
    m_output_error = low_byte(output);
    return high_sbyte(output);
  }

private:
  INLINE static void set_env_decay(uint8_t controller_value) {
    IEnvGen<0>::set_decay(controller_value);
    IEnvGen<0>::set_sustain(false);
  }

  INLINE static void set_amp_env_sus(uint8_t controller_value) {
    IEnvGen<1>::set_decay(controller_value);
    IEnvGen<1>::set_sustain(true);
  }

  INLINE static void set_on_note(uint8_t note_number) {
    m_on_note[note_number >> 3] |= (1 << (note_number & 0x07));
  }

  INLINE static void clear_on_note(uint8_t note_number) {
    m_on_note[note_number >> 3] &= ~(1 << (note_number & 0x07));
  }

  INLINE static uint8_t get_active_on_note() {
    return get_lowest_on_note();
  }

  INLINE static uint8_t get_highest_on_note() {
    uint8_t highest_on_note = NOTE_NUMBER_INVALID;
    for (int8_t i = 15; i >= 0; --i) {
      if (m_on_note[i] != 0x00) {
        if        (m_on_note[i] & 0x80) {
          highest_on_note = (i << 3) + 7;
        } else if (m_on_note[i] & 0x40) {
          highest_on_note = (i << 3) + 6;
        } else if (m_on_note[i] & 0x20) {
          highest_on_note = (i << 3) + 5;
        } else if (m_on_note[i] & 0x10) {
          highest_on_note = (i << 3) + 4;
        } else if (m_on_note[i] & 0x08) {
          highest_on_note = (i << 3) + 3;
        } else if (m_on_note[i] & 0x04) {
          highest_on_note = (i << 3) + 2;
        } else if (m_on_note[i] & 0x02) {
          highest_on_note = (i << 3) + 1;
        } else if (m_on_note[i] & 0x01) {
          highest_on_note = (i << 3) + 0;
        }
        break;
      }
    }
    return highest_on_note;
  }

  INLINE static uint8_t get_lowest_on_note() {
    uint8_t lowest_on_note = NOTE_NUMBER_INVALID;
    for (uint8_t i = 0; i < 16; ++i) {
      if (m_on_note[i] != 0x00) {
        if        (m_on_note[i] & 0x01) {
          lowest_on_note = (i << 3) + 0;
        } else if (m_on_note[i] & 0x02) {
          lowest_on_note = (i << 3) + 1;
        } else if (m_on_note[i] & 0x04) {
          lowest_on_note = (i << 3) + 2;
        } else if (m_on_note[i] & 0x08) {
          lowest_on_note = (i << 3) + 3;
        } else if (m_on_note[i] & 0x10) {
          lowest_on_note = (i << 3) + 4;
        } else if (m_on_note[i] & 0x20) {
          lowest_on_note = (i << 3) + 5;
        } else if (m_on_note[i] & 0x40) {
          lowest_on_note = (i << 3) + 6;
        } else if (m_on_note[i] & 0x80) {
          lowest_on_note = (i << 3) + 7;
        }
        break;
      }
    }
    return lowest_on_note;
  }
};

template <uint8_t T> uint8_t Voice<T>::m_count;
template <uint8_t T> uint8_t Voice<T>::m_eg0_decay_sustain;
template <uint8_t T> uint8_t Voice<T>::m_eg1_decay_sustain;
template <uint8_t T> uint8_t Voice<T>::m_active_note_number;
template <uint8_t T> uint8_t Voice<T>::m_on_note[16];
template <uint8_t T> uint8_t Voice<T>::m_output_error;
template <uint8_t T> uint8_t Voice<T>::m_portamento;
template <uint8_t T> boolean Voice<T>::m_legato;
