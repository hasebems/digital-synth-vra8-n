#pragma once

const uint8_t PROGRAM_NUMBER_DEFAULT = 0;

#if !defined(ENABLE_VOLTAGE_CONTROL) || !defined(USE_PITCH_CV_IN)

// PRESET                                       #0   #1   #2   #3   #4   #5   #6   #7   
const uint8_t g_preset_table_OSC_WAVE     [] = {0  , 0  , 0  , 127, 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_OSC_MIX      [] = {64 , 64 , 64 , 64 , 0  , 64 , 0  , 0  };
const uint8_t g_preset_table_OSC2_COARSE  [] = {71 , 64 , 64 , 64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_OSC2_FINE    [] = {68 , 72 , 66 , 72 , 68 , 60 , 64 , 64 };

const uint8_t g_preset_table_SUB_OSC_WAVE [] = {127, 0  , 0  , 0  , 127, 127, 0  , 0  };
const uint8_t g_preset_table_SUB_OSC_LEVEL[] = {127, 127, 127, 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_PITCH_EG_AMT [] = {64 , 62 , 64 , 64 , 64 , 72 , 64 , 64 };
const uint8_t g_preset_table_PITCH_EG_TGT [] = {0  , 127, 0  , 0  , 0  , 127, 0  , 0  };

const uint8_t g_preset_table_FILTER_CUTOFF[] = {64 , 16 , 16 , 112, 112, 100, 127, 127};
const uint8_t g_preset_table_FILTER_RESO  [] = {96 , 80 , 127, 0  , 0  , 64 , 0  , 0  };
const uint8_t g_preset_table_CUTOFF_EG_AMT[] = {82 , 112, 94,  64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_AMP_EG_ON    [] = {127, 0  , 127, 0  , 127, 127, 127, 127};

const uint8_t g_preset_table_EG_ATTACK    [] = {0  , 0  , 0  , 0  , 0  , 16 , 0  , 0  };
const uint8_t g_preset_table_EG_DECAY     [] = {64 , 96 , 96 , 96 , 0  , 32 , 0  , 0  };
const uint8_t g_preset_table_EG_SUSTAIN   [] = {127, 0  , 0  , 0  , 127, 96 , 127, 127};
const uint8_t g_preset_table_EG_RELEASE   [] = {127, 127, 127, 127, 127, 0  , 127, 127};

const uint8_t g_preset_table_LFO_WAVE     [] = {0  , 0  , 32 , 127, 0  , 32 , 0  , 0  };
const uint8_t g_preset_table_LFO_RATE     [] = {64 , 64 , 64 , 80 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_PITCH_LFO_AMT[] = {66 , 66 , 64 , 88 , 66 , 66 , 64 , 64 };
const uint8_t g_preset_table_CO_LFO_AMT   [] = {64 , 64 , 40 , 64 , 64 , 64 , 64 , 64 };

const uint8_t g_preset_table_LFO_DEPTH    [] = {8  , 8  , 0  , 0  , 0  , 8  , 0  , 0  };
const uint8_t g_preset_table_LFO_RT_EG_AMT[] = {64 , 64 , 64 , 72 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_PITCH_LFO_TGT[] = {127, 0  , 0  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_LFO_FADE_TIME[] = {64 , 64 , 0  , 0  , 0  , 64 , 0  , 0  };

const uint8_t g_preset_table_PB_RANGE     [] = {2  , 2  , 2  , 2  , 12 , 2  , 2  , 2  };
const uint8_t g_preset_table_CC86         [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_CO_EXP_AMT   [] = {64 , 64 , 64 , 64 , 64 , 106, 64 , 64 };
const uint8_t g_preset_table_AMP_EXP_AMT  [] = {0  , 0  , 0  , 0  , 0  , 127, 0  , 0  };

const uint8_t g_preset_table_PORTAMENTO   [] = {0  , 32 , 32 , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_LEGATO       [] = {0  , 127, 127, 0  , 0  , 127, 0  , 0  };
const uint8_t g_preset_table_KEY_ASSIGN   [] = {0  , 64 , 0  , 127, 0  , 127, 0  , 0  };
const uint8_t g_preset_table_EXP_BY_VEL   [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };

const uint8_t g_preset_table_OSC_LEVEL    [] = {80 , 80 , 80 , 80 , 80 , 120, 80 , 80 };
const uint8_t g_preset_table_RESO_LIMIT   [] = {127, 127, 127, 127, 127, 96 , 127, 127};
const uint8_t g_preset_table_AMP_LEVEL    [] = {127, 127, 127, 127, 127, 114, 127, 127};
const uint8_t g_preset_table_DAMP_ATK     [] = {0  , 0  , 0  , 0  , 0  , 64 , 0  , 0  };







#else  // defined(ENABLE_VOLTAGE_CONTROL) && defined(USE_PITCH_CV_IN)

// PRESET                                       #0   #1   #2   #3   #4   #5   #6   #7   
const uint8_t g_preset_table_OSC_WAVE     [] = {0  , 0  , 0  , 0  , 127, 0  , 0  , 0  };
const uint8_t g_preset_table_OSC_MIX      [] = {64 , 64 , 64 , 64 , 64 , 0  , 64 , 0  };
const uint8_t g_preset_table_OSC2_COARSE  [] = {64 , 71 , 64 , 64 , 64 , 64 , 64 , 64 };
const uint8_t g_preset_table_OSC2_FINE    [] = {68 , 68 , 72 , 66 , 72 , 68 , 60 , 64 };

const uint8_t g_preset_table_SUB_OSC_WAVE [] = {0  , 127, 0  , 0  , 0  , 127, 127, 0  };
const uint8_t g_preset_table_SUB_OSC_LEVEL[] = {127, 127, 127, 127, 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_PITCH_EG_AMT [] = {64 , 64 , 62 , 64 , 64 , 64 , 72 , 64 };
const uint8_t g_preset_table_PITCH_EG_TGT [] = {0  , 0  , 127, 0  , 0  , 0  , 127, 0  };

const uint8_t g_preset_table_FILTER_CUTOFF[] = {64 , 64 , 16 , 16 , 112, 112, 100, 127};
const uint8_t g_preset_table_FILTER_RESO  [] = {64 , 96 , 80 , 127, 0  , 0  , 64 , 0  };
const uint8_t g_preset_table_CUTOFF_EG_AMT[] = {64 , 82 , 112, 94,  64 , 64 , 64 , 64 };
const uint8_t g_preset_table_AMP_EG_ON    [] = {127, 127, 0  , 127, 0  , 127, 127, 127};

const uint8_t g_preset_table_EG_ATTACK    [] = {0  , 0  , 0  , 0  , 0  , 0  , 16 , 0  };
const uint8_t g_preset_table_EG_DECAY     [] = {64 , 64 , 96 , 96 , 96 , 0  , 32 , 0  };
const uint8_t g_preset_table_EG_SUSTAIN   [] = {127, 127, 0  , 0  , 0  , 127, 96 , 127};
const uint8_t g_preset_table_EG_RELEASE   [] = {127, 127, 127, 127, 127, 127, 0  , 127};

const uint8_t g_preset_table_LFO_WAVE     [] = {0  , 0  , 0  , 32 , 127, 0  , 32 , 0  };
const uint8_t g_preset_table_LFO_RATE     [] = {64 , 64 , 64 , 64 , 80 , 64 , 64 , 64 };
const uint8_t g_preset_table_PITCH_LFO_AMT[] = {65 , 66 , 66 , 64 , 88 , 66 , 66 , 64 };
const uint8_t g_preset_table_CO_LFO_AMT   [] = {64 , 64 , 64 , 40 , 64 , 64 , 64 , 64 };

const uint8_t g_preset_table_LFO_DEPTH    [] = {16 , 8  , 8  , 0  , 0  , 0  , 8  , 0  };
const uint8_t g_preset_table_LFO_RT_EG_AMT[] = {64 , 64 , 64 , 64 , 72 , 64 , 64 , 64 };
const uint8_t g_preset_table_PITCH_LFO_TGT[] = {0  , 127, 0  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_LFO_FADE_TIME[] = {0  , 64 , 64 , 0  , 0  , 0  , 64 , 0  };

const uint8_t g_preset_table_PB_RANGE     [] = {30 , 2  , 2  , 2  , 2  , 12 , 2  , 2  };
const uint8_t g_preset_table_CC86         [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_CO_EXP_AMT   [] = {64 , 64 , 64 , 64 , 64 , 64 , 106, 64 };
const uint8_t g_preset_table_AMP_EXP_AMT  [] = {0  , 0  , 0  , 0  , 0  , 0  , 127, 0  };

const uint8_t g_preset_table_PORTAMENTO   [] = {0  , 0  , 32 , 32 , 0  , 0  , 0  , 0  };
const uint8_t g_preset_table_LEGATO       [] = {0  , 0  , 127, 127, 0  , 0  , 127, 0  };
const uint8_t g_preset_table_KEY_ASSIGN   [] = {127, 0  , 64 , 0  , 127, 0  , 127, 0  };
const uint8_t g_preset_table_EXP_BY_VEL   [] = {0  , 0  , 0  , 0  , 0  , 0  , 0  , 0  };

const uint8_t g_preset_table_OSC_LEVEL    [] = {80 , 80 , 80 , 80 , 80 , 80 , 120, 80 };
const uint8_t g_preset_table_RESO_LIMIT   [] = {127, 127, 127, 127, 127, 127, 96 , 127};
const uint8_t g_preset_table_AMP_LEVEL    [] = {127, 127, 127, 127, 127, 127, 114, 127};
const uint8_t g_preset_table_DAMP_ATK     [] = {0  , 0  , 0  , 0  , 0  , 0  , 64 , 0  };

#endif