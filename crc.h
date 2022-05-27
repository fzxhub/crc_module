#ifndef _CRC_H
#define _CRC_H

/********************************************************************************************/
//Data type definition: adapt to different compilers and operating systems
/********************************************************************************************/
typedef  unsigned char		crc_uint8;
typedef  unsigned short		crc_uint16;
typedef  unsigned int		crc_uint32;
/********************************************************************************************/

/********************************************************************************************/
//Adapt to a compiler with or without BOOL
/********************************************************************************************/
//typedef  bool				crc_bool;
typedef  char				crc_bool;
#define  crc_true			1		// true  or 1
#define  crc_false			0		// false or 0
/********************************************************************************************/

//CRC Calculate
crc_uint8  Crc_Calculate_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout);
crc_uint16 Crc_Calculate_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout);
crc_uint32 Crc_Calculate_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout);
//CRC Check
crc_bool   Crc_Check_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout);
crc_bool   Crc_Check_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout);
crc_bool   Crc_Check_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout);
//CRC8
crc_uint8  Crc_Calculate_Crc8(crc_uint8* data, crc_uint32 len);
crc_uint8  Crc_Calculate_Crc8_Itu(crc_uint8* data, crc_uint32 len);
crc_uint8  Crc_Calculate_Crc8_Rohc(crc_uint8* data, crc_uint32 len);
crc_uint8  Crc_Calculate_Crc8_Maxim(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8_Itu(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8_Rohc(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8_Maxim(crc_uint8* data, crc_uint32 len);
//CRC32
crc_uint32 Crc_Calculate_Crc32(crc_uint8* data, crc_uint32 len);
crc_uint32 Crc_Calculate_Crc32_Mpeg2(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc32(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc32_Mpeg2(crc_uint8* data, crc_uint32 len);
//CRC16
crc_uint16 Crc_Calculate_Crc16_Ibm(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_Maxim(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_Usb(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_Modbus(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_Ccitt(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_CcittFalse(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_X25(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_Xmosem(crc_uint8* data, crc_uint32 len);
crc_uint16 Crc_Calculate_Crc16_Dnp(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Ibm(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Maxim(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Usb(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Modbus(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Ccitt(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_CcittFalse(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_X25(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Xmosem(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Dnp(crc_uint8* data, crc_uint32 len);

#endif