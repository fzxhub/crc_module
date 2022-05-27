#include "crc.h"
#include "stdio.h"
#include "string.h"

void main()
{
    crc_uint8 data[] = "1234567890";
    crc_uint32 crc[15];
    crc[0 ] = Crc_Calculate_Crc8            (data, strlen(data));
    crc[1 ] = Crc_Calculate_Crc8_Itu        (data, strlen(data));
    crc[2 ] = Crc_Calculate_Crc8_Rohc       (data, strlen(data));
    crc[3 ] = Crc_Calculate_Crc8_Maxim      (data, strlen(data));
    crc[4 ] = Crc_Calculate_Crc32           (data, strlen(data));
    crc[5 ] = Crc_Calculate_Crc32_Mpeg2     (data, strlen(data));
    crc[6 ] = Crc_Calculate_Crc16_Ibm       (data, strlen(data));
    crc[7 ] = Crc_Calculate_Crc16_Maxim     (data, strlen(data));
    crc[8 ] = Crc_Calculate_Crc16_Usb       (data, strlen(data));
    crc[9 ] = Crc_Calculate_Crc16_Modbus    (data, strlen(data));
    crc[10] = Crc_Calculate_Crc16_Ccitt     (data, strlen(data));
    crc[11] = Crc_Calculate_Crc16_CcittFalse(data, strlen(data));
    crc[12] = Crc_Calculate_Crc16_X25       (data, strlen(data));
    crc[13] = Crc_Calculate_Crc16_Xmosem    (data, strlen(data));
    crc[14] = Crc_Calculate_Crc16_Dnp       (data, strlen(data));

    for(int i = 0; i < sizeof(crc)/4; i++)
    {
        printf("CRC[%d]:%08X\n",i,crc[i]);
    }
}