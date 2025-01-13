CUSTOM_MATRIX = lite

VPATH += drivers/gpio
SRC += matrix.c mcp23018.c
I2C_DRIVER_REQUIRED = yes

MCU_LDSCRIPT = STM32F303xB





# Rollercole:
PERMISSIVE_HOLD_ENABLE = yes
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
SRC += features/achordion.c

