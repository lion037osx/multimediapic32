#include "spiTsc2046.h"
#include <GenericTypeDefs.h>
//#include "../ConfigHardware.h"
#include "../config/ConfigHardware.h"
#include <plib.h>
#include "../HardwareProfile.h"

void initSpi(void){
TOUCH_SCREEN_SCK_TRIS=OUTPUT;
TOUCH_SCREEN_SDI_TRIS=INPUT;
TOUCH_SCREEN_SDO_TRIS=OUTPUT;
TOUCH_SCREEN_CS_TRIS=OUTPUT;
CFG_SPI_SDI_DIGITAL();
}