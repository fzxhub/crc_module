#include "crc.h"

/********************************************************************************************/
//功能：8BIT的数据变量按位反转（不是取反：0与7调换、1与6调换。。。）
//输入：data：8BIT源数据
//返回：反转后的数据
/********************************************************************************************/
crc_uint8 Reverse_Bit8(crc_uint8 data)
{

	data = ((data >> 1) & 0x55) | ((data << 1) & 0xAA);
	data = ((data >> 2) & 0x33) | ((data << 2) & 0xCC);
	data = ((data >> 4) & 0x0F) | ((data << 4) & 0xF0);
	return data;
}
/********************************************************************************************/
//功能：16BIT的数据变量按位反转（不是取反：0与15调换、1与14调换。。。）
//输入：data：16BIT源数据
//返回：反转后的数据
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
//功能：32BIT的数据变量按位反转（不是取反：0与31调换、1与30调换。。。）
//输入：data：32BIT源数据
//返回：反转后的数据
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
//功能：计算CRC8
//输入：data  ：要计算的源数据
//输入：len   ：要计算的源数据的长度
//输入：poly  ：多项式值
//输入：init  ：计算初始值
//输入：xorout：结果数据要异或的值
//输入：refin ：输入数据是否反转
//输入：refout：输出结果是否反转
//返回：CRC数据
/********************************************************************************************/
crc_uint8 Crc_Calculate_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint8	value = init;
	crc_uint8	temp = 0;

	while (len--)
	{
		temp = *(data++);
		//输入数据反转
		if (refin == crc_true) temp = Reverse_Bit8(temp);
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x80) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	//输出数据异或操作
	value ^= xorout;
	//输出数据反转
	if (refout == crc_true) return  Reverse_Bit8(value);
	//输出数据不反转
	else return value;
}
/********************************************************************************************/
//功能：计算CRC16
//输入：data  ：要计算的源数据
//输入：len   ：要计算的源数据的长度
//输入：poly  ：多项式值
//输入：init  ：计算初始值
//输入：xorout：结果数据要异或的值
//输入：refin ：输入数据是否反转
//输入：refout：输出结果是否反转
//返回：CRC数据
/********************************************************************************************/
crc_uint16 Crc_Calculate_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint16	value = init;
	crc_uint16	temp = 0;

	while (len--)
	{
		temp = *(data++);
		//输入数据反转
		if (refin == crc_true) temp = Reverse_Bit16(temp);
		//输入数据不反转
		else temp = temp << 8;
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x8000) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	//输出数据异或操作
	value ^= xorout;
	//输出数据反转
	if (refout == crc_true) return  Reverse_Bit16(value);
	//输出数据不反转
	else  return value;
}

/********************************************************************************************/
//功能：计算CRC32
//输入：data  ：要计算的源数据
//输入：len   ：要计算的源数据的长度
//输入：poly  ：多项式值
//输入：init  ：计算初始值
//输入：xorout：结果数据要异或的值
//输入：refin ：输入数据是否反转
//输入：refout：输出结果是否反转
//返回：CRC数据
/********************************************************************************************/
crc_uint32 Crc_Calculate_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint32	value = init;
	crc_uint32	temp = 0;

	while (len--)
	{
		temp = *(data++);
		//输入数据反转
		if (refin == crc_true) temp = Reverse_Bit32(temp);
		//输入数据不反转
		else temp = temp << 24;
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x80000000) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	//输出数据异或操作
	value ^= xorout;
	//输出数据反转
	if (refout == crc_true) return  Reverse_Bit32(value);
	//输出数据不反转
	else  return value;
}

/********************************************************************************************/
//功能：检查CRC8
//输入：data  ：要检查的源数据
//输入：len   ：要检查的源数据的长度
//输入：poly  ：多项式值
//输入：init  ：计算初始值
//输入：xorout：结果数据要异或的值
//输入：refin ：输入数据是否反转
//输入：refout：输出结果是否反转
//返回：成功/失败
/********************************************************************************************/
crc_bool Crc_Check_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_8(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}

/********************************************************************************************/
//功能：检查CRC16
//输入：data  ：要检查的源数据
//输入：len   ：要检查的源数据的长度
//输入：poly  ：多项式值
//输入：init  ：计算初始值
//输入：xorout：结果数据要异或的值
//输入：refin ：输入数据是否反转
//输入：refout：输出结果是否反转
//返回：成功/失败
/********************************************************************************************/
crc_bool Crc_Check_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_16(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}

/********************************************************************************************/
//功能：检查CRC32
//输入：data  ：要检查的源数据
//输入：len   ：要检查的源数据的长度
//输入：poly  ：多项式值
//输入：init  ：计算初始值
//输入：xorout：结果数据要异或的值
//输入：refin ：输入数据是否反转
//输入：refout：输出结果是否反转
//返回：成功/失败
/********************************************************************************************/
crc_bool Crc_Check_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_32(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}
/********************************************************************************************/
//功能：计算CRC8（常规）
//输入：data  ：要计算的源数据
//输入：len   ：要计算的源数据的长度
//返回：CRC数据
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0x00, 0x00, crc_false, crc_false);
}
/********************************************************************************************/
//功能：检查CRC8（常规）
//输入：data  ：要检查的源数据
//输入：len   ：要检查的源数据的长度
//返回：成功/失败
/********************************************************************************************/
crc_bool Crc_Check_Crc8(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0x00, 0x00, crc_false, crc_false);
}
/********************************************************************************************/
//功能：计算CRC8（ITU）
//输入：data  ：要计算的源数据
//输入：len   ：要计算的源数据的长度
//返回：CRC数据
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Itu(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0x00, 0x55, crc_false, crc_false);
}
/********************************************************************************************/
//功能：检查CRC8（ITU）
//输入：data  ：要检查的源数据
//输入：len   ：要检查的源数据的长度
//返回：成功/失败
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Itu(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0x00, 0x55, crc_false, crc_false);
}

/********************************************************************************************/
//功能：计算CRC8（ROHC）
//输入：data  ：要计算的源数据
//输入：len   ：要计算的源数据的长度
//返回：CRC数据
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Rohc(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0xFF, 0x00, crc_true, crc_true);
}
/********************************************************************************************/
//功能：检查CRC8（ROHC）
//输入：data  ：要检查的源数据
//输入：len   ：要检查的源数据的长度
//返回：成功/失败
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Rohc(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0xFF, 0x00, crc_true, crc_true);
}


