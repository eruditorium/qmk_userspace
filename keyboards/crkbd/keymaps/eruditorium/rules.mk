# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
OLED_ENABLE = yes

MOUSEKEY_ENABLE = no        # Mouse keys (+4700)
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode

QMK_SETTINGS = no
DYNAMIC_MACRO_ENABLE = no
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = no
DYNAMIC_KEYMAP_LAYER_COUNT = 3
RGB_LIGHT_ENABLE = no

# auto shift
AUTO_SHIFT_ENABLE = no

# https://docs.qmk.fm/#/feature_caps_word
# make sure COMMAND_ENABLE = no
#CAPS_WORD_ENABLE = yes

# https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-execution
DEFERRED_EXEC_ENABLE = yes

# to reduce size of firmware
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
# Add these flags to your rules.mk file: EXTRAFLAGS += -flto
# Drashna, on QMK issue 3224, paraphrased
LTO_ENABLE = no
EXTRAFLAGS += -Os -flto
EXTRAFLAGS += -DNO_ACTION_MACRO
EXTRAFLAGS += -DNO_ACTION_FUNCTION
EXTRAFLAGS += -DNO_DEBUG
EXTRAFLAGS += -DNO_PRINT
