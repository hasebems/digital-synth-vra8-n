

A4_PITCH = 440.0

MIDI_CH             = 0
SAMPLING_RATE       = 31250
FREQUENCY_MAX       = 15624
BIT_DEPTH           = 8
NOTE_NUMBER_MIN     = 24
NOTE_NUMBER_MAX     = 84
NOTE_NUMBER_INVALID = 255

OSC_CONTROL_INTERVAL_BITS   = 3
OSC_CONTROL_INTERVAL        = 0x01 << OSC_CONTROL_INTERVAL_BITS
OSC_PHASE_RESOLUTION_BITS   = 24
OSC_TUNE_TABLE_STEPS_BITS   = 8
OSC_TUNE_DENOMINATOR_BITS   = 12
OSC_WAVE_TABLE_AMPLITUDE    = 96
OSC_WAVE_TABLE_SAMPLES_BITS = 8
OSC_DETUNE_MUL_NUM_BITS     = 4
OSC_DETUNE_FREQ_MIN         = 64
OSC_DETUNE_FREQ_MAX         = 0
FILTER_CONTROL_INTERVAL     = 0x08
FILTER_CUTOFF_THROUGH_RATE  = 8
FILTER_TABLE_FRACTION_BITS  = 14
ENV_GEN_CONTROL_INTERVAL    = 0x08
ENV_GEN_LEVEL_MAX           = 0xFFFF
ENV_GEN_LEVEL_RELEASE_STEP  = 0x1600
ENV_GEN_DECAY_FACTOR        = 248
AMP_ENV_AMT_MAX             = 240
AMP_ENV_AMT_STEP            = 16

DATA_BYTE_MAX         = 0x7F
STATUS_BYTE_INVALID   = 0x7F
DATA_BYTE_INVALID     = 0x80
STATUS_BYTE_MIN       = 0x80
NOTE_OFF              = 0x80
NOTE_ON               = 0x90
CONTROL_CHANGE        = 0xB0
PITCH_BEND            = 0xE0
SYSTEM_MESSAGE_MIN    = 0xF0
SYSTEM_EXCLUSIVE      = 0xF0
TIME_CODE             = 0xF1
SONG_POSITION         = 0xF2
SONG_SELECT           = 0xF3
TUNE_REQUEST          = 0xF6
EOX                   = 0xF7
REAL_TIME_MESSAGE_MIN = 0xF8
ACTIVE_SENSING        = 0xFE

UNISON        = 16
OSC_WAVEFORM  = 17
OSC_DETUNE    = 18
FILTER_NG_AMT = 19

FILTER_CUTOFF = 20
FILTER_RESO   = 21
FILTER_EG_AMT = 22
EG_DECAY      = 23

EG_ATTACK     = 24
DETUNE_NG_AMT = 25
DETUNE_EG_AMT = 26
AMP_EG        = 27

VELOCITY_SENS = 28
CUTOFF_V_SENS = 29
PORTAMENTO    = 30
UNISON_OPTION = 31

DAMPER_PEDAL  = 64

ALL_NOTES_OFF = 123
OMNI_MODE_OFF = 124
OMNI_MODE_ON  = 125
MONO_MODE_ON  = 126
POLY_MODE_ON  = 127

OSC_WAVEFORM_SAW     = 0
OSC_WAVEFORM_SQ      = 127
