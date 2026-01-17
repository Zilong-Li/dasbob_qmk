

# Bootloader selection
BOOTLOADER = rp2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
COMBO_ENABLE = no          # Enable comnos
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
TAP_DANCE_ENABLE = no      # Enable tap dance
UNICODE_ENABLE = yes        # Unicode
AUDIO_ENABLE = yes          # Audio output
SPLIT_KEYBOARD = yes        # Use shared split_common code
REPEAT_KEY_ENABLE = yes     # Repeat key!
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
WPM_ENABLE = yes
LTO_ENABLE = yes
SERIAL_DRIVER = vendor
AUDIO_DRIVER = pwm_hardware
