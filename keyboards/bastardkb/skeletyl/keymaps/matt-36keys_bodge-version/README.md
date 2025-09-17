I have one skeletyl where the c6 pin suddenly didnt work on the left side.
A bodge wire has been added from the c6 col to the mosi pin, which is GP23.
A config.h in this dir remaps this on the left hand side only.

Solved only with help from @casuanoob and @burkfers.

/* SPI & PMW3360 settings. */
pin naming:

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define POINTING_DEVICE_CS_PIN GP16
