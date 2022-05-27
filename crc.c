#include "crc.h"

/********************************************************************************************/
//function: 8BIT High and low Reverse
//data    ：8BIT
//return  : Reverse
/********************************************************************************************/
crc_uint8 Reverse_Bit8(crc_uint8 data)
{

	data = ((data >> 1) & 0x55) | ((data << 1) & 0xAA);
	data = ((data >> 2) & 0x33) | ((data << 2) & 0xCC);
	data = ((data >> 4) & 0x0F) | ((data << 4) & 0xF0);
	return data;
}
/********************************************************************************************/
//function: 16BIT High and low Reverse
//data    ：16BIT
//return  : Reverse
/********************************************************************************************/
crc_uint16 Reverse_Bit16(crc_uint16 data)
{
	data = ((data >> 1) & 0x5555) | ((data << 1) & 0xAAAA);
	data = ((data >> 2) & 0x3333) | ((data << 2) & 0xCCCC);
	data = ((data >> 4) & 0x0F0F) | ((data << 4) & 0xF0F0);
	data = ((data >> 8) & 0x00FF) | ((data << 8) & 0xFF00);
	return data;
}
/********************************************************************************************/
//function: 32BIT High and low Reverse
//data    ：32BIT
//return  : Reverse
/********************************************************************************************/
crc_uint32 Reverse_Bit32(crc_uint32 data)
{
	data = ((data >> 1) & 0x55555555) | ((data << 1) & 0xAAAAAAAA);
	data = ((data >> 2) & 0x33333333) | ((data << 2) & 0xCCCCCCCC);
	data = ((data >> 4) & 0x0F0F0F0F) | ((data << 4) & 0xF0F0F0F0);
	data = ((data >> 8) & 0x00FF00FF) | ((data << 8) & 0xFF00FF00);
	data = ((data >> 16) & 0x0000FFFF) | ((data << 16) & 0xFFFF0000);
	return data;
}
/********************************************************************************************/
//function: Calculate CRC8
//data    : source data
//len     : source length
//poly    : polynomial
//init    : initial value
//xorout  : result XOR value
//refin   : input data inversion (crc_true or crc_false)
//refout  : output data inversion (crc_true or crc_false)
//return  : results of CRC8 
/********************************************************************************************/
crc_uint8 Crc_Calculate_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint8	value = init;
	crc_uint8	temp = 0;

	while (len--)
	{
		temp = *(data++);
		if (refin == crc_true) temp = Reverse_Bit8(temp);
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x80) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	value ^= xorout;
	if (refout == crc_true) return  Reverse_Bit8(value);
	else return value;
}
/********************************************************************************************/
//function: Calculate CRC16
//data    : source data
//len     : source length
//poly    : polynomial
//init    : initial value
//xorout  : result XOR value
//refin   : input data inversion (crc_true or crc_false)
//refout  : output data inversion (crc_true or crc_false)
//return  : results of CRC16 
/********************************************************************************************/
crc_uint16 Crc_Calculate_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint16	value = init;
	crc_uint16	temp = 0;

	while (len--)
	{
		temp = *(data++);
		if (refin == crc_true) temp = Reverse_Bit16(temp);
		else temp = temp << 8;
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x8000) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	value ^= xorout;
	if (refout == crc_true) return  Reverse_Bit16(value);
	else  return value;
}
/********************************************************************************************/
//function: Calculate CRC32
//data    : source data
//len     : source length
//poly    : polynomial
//init    : initial value
//xorout  : result XOR value
//refin   : input data inversion (crc_true or crc_false)
//refout  : output data inversion (crc_true or crc_false)
//return  : results of CRC32 
/********************************************************************************************/
crc_uint32 Crc_Calculate_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint32	value = init;
	crc_uint32	temp = 0;

	while (len--)
	{
		temp = *(data++);
		if (refin == crc_true) temp = Reverse_Bit32(temp);
		else temp = temp << 24;
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x80000000) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	value ^= xorout;
	if (refout == crc_true) return  Reverse_Bit32(value);
	else  return value;
}
/********************************************************************************************/
//function: Check CRC8
//data    : source data + results of CRC8 
//len     : source length
//poly    : polynomial
//init    : initial value
//xorout  : result XOR value
//refin   : input data inversion (crc_true or crc_false)
//refout  : output data inversion (crc_true or crc_false)
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_8(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}
/********************************************************************************************/
//function: Check CRC16
//data    : source data + results of CRC16 
//len     : source length
//poly    : polynomial
//init    : initial value
//xorout  : result XOR value
//refin   : input data inversion (crc_true or crc_false)
//refout  : output data inversion (crc_true or crc_false)
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_16(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}
/********************************************************************************************/
//function: Check CRC32
//data    : source data + results of CRC32 
//len     : source length
//poly    : polynomial
//init    : initial value
//xorout  : result XOR value
//refin   : input data inversion (crc_true or crc_false)
//refout  : output data inversion (crc_true or crc_false)
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_32(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}
/********************************************************************************************/
//function: Calculate CRC8 (conventional)
//data    : source data
//len     : source length
//return  : results of CRC8
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0x00, 0x00, crc_false, crc_false);
}
/********************************************************************************************/
//function: Check CRC8 (conventional)
//data    : source data + results of CRC8
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc8(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0x00, 0x00, crc_false, crc_false);
}
/********************************************************************************************/
//function: Calculate CRC8 (ITU)
//data    : source data
//len     : source length
//return  : results of CRC8
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Itu(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0x00, 0x55, crc_false, crc_false);
}
/********************************************************************************************/
//function: Check CRC8 (ITU)
//data    : source data + results of CRC8
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Itu(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0x00, 0x55, crc_false, crc_false);
}
/********************************************************************************************/
//function: Calculate CRC8 (ROHC)
//data    : source data
//len     : source length
//return  : results of CRC8
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Rohc(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0xFF, 0x00, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC8 (ROHC)
//data    : source data + results of CRC8
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Rohc(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0xFF, 0x00, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC8 (MAXIM)
//data    : source data
//len     : source length
//return  : results of CRC8
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Maxim(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x31, 0x00, 0x00, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC8 (MAXIM)
//data    : source data + results of CRC8
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Maxim(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x31, 0x00, 0x00, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC32 (conventional)
//data    : source data
//len     : source length
//return  : results of CRC32
/********************************************************************************************/
crc_uint32 Crc_Calculate_Crc32(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_32(data, len, 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC32 (conventional)
//data    : source data + results of CRC32
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc32(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_32(data, len, 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC32 (MPEG2)
//data    : source data
//len     : source length
//return  : results of CRC32
/********************************************************************************************/
crc_uint32 Crc_Calculate_Crc32_Mpeg2(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_32(data, len, 0x04C11DB7, 0xFFFFFFFF, 0x00000000, crc_false, crc_false);
}
/********************************************************************************************/
//function: Check CRC32 (MPEG2)
//data    : source data + results of CRC32
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc32_Mpeg2(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_32(data, len, 0x04C11DB7, 0xFFFFFFFF, 0x00000000, crc_false, crc_false);
}
/********************************************************************************************/
//function: Calculate CRC16 (IBM)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Ibm(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x8005, 0x0000, 0x0000, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (IBM)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Ibm(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x8005, 0x0000, 0x0000, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC16 (MAXIM)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Maxim(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x8005, 0x0000, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (MAXIM)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Maxim(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x8005, 0x0000, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC16 (USB)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Usb(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x8005, 0xFFFF, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (USB)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Usb(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x8005, 0xFFFF, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC16 (MODBUS)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Modbus(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x8005, 0xFFFF, 0x0000, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (MODBUS)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Modbus(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x8005, 0xFFFF, 0x0000, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC16 (CCITT)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Ccitt(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x1021, 0x0000, 0x0000, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (CCITT)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Ccitt(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x1021, 0x0000, 0x0000, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC16 (CCITTFALSE)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_CcittFalse(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x1021, 0xFFFF, 0x0000, crc_false, crc_false);
}
/********************************************************************************************/
//function: Check CRC16 (CCITTFALSE)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_CcittFalse(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x1021, 0xFFFF, 0x0000, crc_false, crc_false);
}
/********************************************************************************************/
//function: Calculate CRC16 (X25)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_X25(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x1021, 0xFFFF, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (X25)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_X25(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x1021, 0xFFFF, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Calculate CRC16 (XMODEM)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Xmosem(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x1021, 0x0000, 0x0000, crc_false, crc_false);
}
/********************************************************************************************/
//function: Check CRC16 (XMODEM)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Xmosem(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x1021, 0x0000, 0x0000, crc_false, crc_false);
}
/********************************************************************************************/
//function: Calculate CRC16 (DNP)
//data    : source data
//len     : source length
//return  : results of CRC16
/********************************************************************************************/
crc_uint16 Crc_Calculate_Crc16_Dnp(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_16(data, len, 0x3D65, 0x0000, 0xFFFF, crc_true, crc_true);
}
/********************************************************************************************/
//function: Check CRC16 (DNP)
//data    : source data + results of CRC16
//len     : source length
//return  : compare the results(crc_true or crc_false)
/********************************************************************************************/
crc_bool Crc_Check_Crc16_Dnp(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_16(data, len, 0x3D65, 0x0000, 0xFFFF, crc_true, crc_true);
}