BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
MIDI_ENABLE = no            # MIDI controls
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE= yes     # OLED display
QMK_SETTINGS = no
DYNAMIC_MACRO_ENABLE = yes
COMBO_ENABLE = no
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = no
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

#

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
OLED_ENABLE = yes

# to reduce size of firmware
# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
# Add these flags to your rules.mk file: EXTRAFLAGS += -flto
# Drashna, on QMK issue 3224, paraphrased
EXTRAFLAGS += -flto
LTO_ENABLE = yes



# https://docs.qmk.fm/#/feature_caps_word
# make sure COMMAN_ENABLE = no
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


