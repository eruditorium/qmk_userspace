# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
OLED_ENABLE = no
ENCODER_MAP_ENABLE = no

VIAL_ENABLE = no
QMK_SETTINGS = no
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
AUTO_SHIFT = no

DYNAMIC_MACRO_ENABLE = no
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes

# https://docs.qmk.fm/#/feature_caps_word
# make sure COMMAND_ENABLE = no
CAPS_WORD_ENABLE = yes

#-----------------------------------------------------------------------------
# getreuer
#-----------------------------------------------------------------------------
# https://github.com/getreuer/qmk-keymap

# SRC += features/achordion.c
# SRC += features/autocorrection.c
# SRC += features/custom_shift_keys.c
SRC += features/select_word.c


#-----------------------------------------------------------------------------
# sunaku
#-----------------------------------------------------------------------------

# https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-execution
DEFERRED_EXEC_ENABLE = yes

