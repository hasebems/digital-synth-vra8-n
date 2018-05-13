

A4_PITCH = 440.0

MIDI_CH             = 0
SAMPLING_RATE       = 31250
FREQUENCY_MAX       = 15624
BIT_DEPTH           = 8
NOTE_NUMBER_MIN     = 0
NOTE_NUMBER_MAX     = 120
NOTE_NUMBER_INVALID = 255

OSC_CONTROL_INTERVAL_BITS   = 3
OSC_CONTROL_INTERVAL        = 0x01 << OSC_CONTROL_INTERVAL_BITS
OSC_PHASE_RESOLUTION_BITS   = 24
OSC_TUNE_TABLE_STEPS_BITS   = 8
OSC_TUNE_DENOMINATOR_BITS   = 9
OSC_WAVE_TABLE_AMPLITUDE    = 96
OSC_WAVE_TABLE_SAMPLES_BITS = 8
OSC_DETUNE_MUL_NUM_BITS     = 4
OSC_DETUNE_FREQ_MIN         = 64
OSC_DETUNE_FREQ_MAX         = 0
FILTER_CONTROL_INTERVAL     = 0x08
FILTER_CUTOFF_THROUGH_RATE  = 16
FILTER_TABLE_FRACTION_BITS  = 14
ENV_GEN_CONTROL_INTERVAL    = 0x08
ENV_GEN_LEVEL_MAX           = 0xFE00
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

MODULATION    = 1

OSC_COLOR_1   = 16
OSC_COLOR_2   = 17
MOD_RATE      = 18
MOD_DEPTH     = 19

FILTER_CUTOFF = 20
FILTER_RESO   = 21
FILTER_EG_AMT = 22
FILTER_EG     = 23

CC104         = 104
CC105         = 105
CC106         = 106
CC107         = 107

CC108         = 108
CC109         = 109
CC110         = 110
CC111         = 111

CC24          = 24
FLUCTUATION   = 25
PORTAMENTO    = 26
AMP_EG        = 27

CC28          = 28
CC29          = 29
CC30          = 30
CC31          = 31

ALL_NOTES_OFF = 123
OMNI_MODE_OFF = 124
OMNI_MODE_ON  = 125
MONO_MODE_ON  = 126
POLY_MODE_ON  = 127

OSC_WAVEFORM_SAW     = 0
OSC_WAVEFORM_TRI     = 64
OSC_WAVEFORM_SQ      = 127
