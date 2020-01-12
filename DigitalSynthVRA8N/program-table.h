#pragma once

const uint8_t PROGRAM_NUMBER_DEFAULT = 0;

// PRESET for SAXduino                            #0   #1   #2   #3   #4   #5             
//                                                SAX  CLA  FLU  SAW  SQU  NEUTRAL        
const uint8_t g_preset_table_OSC1_2_WAVE    [] = {0  , 127, 127, 0  , 127, 0  , 0  , 0  };
const uint8_t g_preset_table_OSC_MIX        [] = {0  , 0  , 0  , 32 , 64 , 0  , 0  , 0  };
const uint8_t g_preset_table_OSC2_COARSE    [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_OSC2_FINE      [] = {72 , 72 , 72 , 48 , 72 , 72 , 72 , 72 };

const uint8_t g_preset_table_SUB_WAVE       [] = {64 , 64 , 64 , 127, 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_SUB_LEVEL      [] = {0  , 0  , 8  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_EG_TO_PITCH    [] = {64 , 64 , 64 , 80 , 80 , 64 , 64 , 64 };
const uint8_t g_preset_table_EG_TO_P_TGT    [] = {0  , 0  , 0  , 127, 0  , 0  , 0  , 0  };

const uint8_t g_preset_table_CUTOFF         [] = {100, 64 , 0  , 100, 127, 127, 127, 127};
const uint8_t g_preset_table_RESONANCE      [] = {0  , 0  , 0  , 64 , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_EG_TO_CUTOFF   [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_AMP_EG         [] = {127, 127, 127, 127, 0  , 127, 127, 127};

const uint8_t g_preset_table_ATTACK         [] = {16 , 16 , 32 , 16 , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_DECAY          [] = {32 , 32 , 32 , 32 , 16 , 0  , 0  , 0  };
const uint8_t g_preset_table_SUSTAIN        [] = {96 , 127, 127, 96 , 0  , 127, 127, 127};
const uint8_t g_preset_table_RELEASE        [] = {0  , 127, 127, 0  , 0  , 127, 127, 127};

const uint8_t g_preset_table_LFO_WAVE       [] = {32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 };
const uint8_t g_preset_table_LFO_RATE       [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_LFO_TO_PITCH   [] = {66 , 66 , 66 , 66 , 66 , 66 , 66 , 66 };
const uint8_t g_preset_table_LFO_TO_CUTOFF  [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };

const uint8_t g_preset_table_LFO_DEPTH      [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_EG_TO_LFO_RATE [] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_LFO_TO_P_TGT   [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_LFO_FADE_TIME  [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };

const uint8_t g_preset_table_P_BEND_RANGE   [] = {2  , 2  , 2  , 2  , 2  , 2  , 2  , 2  };
const uint8_t g_preset_table_PITCH_TO_CUTOFF[] = {127, 64 , 127, 127, 64 , 127, 127, 127};
const uint8_t g_preset_table_EXP_TO_CUTOFF  [] = {88 , 88 , 88 , 112, 64 , 88 , 88 , 88 };
const uint8_t g_preset_table_EXP_TO_AMP_LEV [] = {127, 127, 127, 127, 127, 127, 127, 127};

const uint8_t g_preset_table_PORTAMENTO     [] = {0  , 0  , 0  , 0  , 32 , 0  , 0  , 0  };
const uint8_t g_preset_table_LEGATO         [] = {127, 127, 0  , 127, 127, 127, 127, 127};
const uint8_t g_preset_table_KEY_ASSIGN     [] = {127, 127, 127, 127, 127, 127, 127, 127};
const uint8_t g_preset_table_EXP_BY_VEL     [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };

const uint8_t g_preset_table_OSC_LEVEL      [] = {107, 120, 120, 107, 80 , 80 , 80 , 80 };
const uint8_t g_preset_table_RESONANCE_LIMIT[] = {96 , 96 , 96 , 96 , 127, 127, 127, 127};
const uint8_t g_preset_table_AMP_LEVEL      [] = {127, 127, 127, 127, 127, 127, 127, 127};
const uint8_t g_preset_table_DAMP_AND_ATTACK[] = {64 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
