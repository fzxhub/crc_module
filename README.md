# CRC
This is a CRC calculation and check the code, C/C++ code written. Support CRC8, CRC16, CRC32. Support computing mode to add polynomial, initial value, output XOR value, input data inversion, output data inversion. A variety of common CRC are also given.

这是一个CRC计算和校验的代码模块，用C编写的代码。支持CRC8, CRC16, CRC32。支持计算方式添加多项式、初始值、输出异或值、输入数据反演、输出数据反演。各种常见的CRC也给出了函数。

## 优点

1. C编写，支持CRC8, CRC16, CRC32常规算法
2. 可自定义多项式、初始值、输出异或值、输入数据反演、输出数据反演
3. 不使用查表法，不占用内存，使用CPU实时计算

## 使用说明

常用算法的计算函数，传入要计算的数据和长度，就可返回CRC结果。

```c
//CRC8
crc_uint8  Crc_Calculate_Crc8(crc_uint8* data, crc_uint32 len);
crc_uint8  Crc_Calculate_Crc8_Itu(crc_uint8* data, crc_uint32 len);
crc_uint8  Crc_Calculate_Crc8_Rohc(crc_uint8* data, crc_uint32 len);
crc_uint8  Crc_Calculate_Crc8_Maxim(crc_uint8* data, crc_uint32 len);
//CRC32
crc_uint32 Crc_Calculate_Crc32(crc_uint8* data, crc_uint32 len);
crc_uint32 Crc_Calculate_Crc32_Mpeg2(crc_uint8* data, crc_uint32 len);
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
```

当收到CRC结果，我们需要校验结果是否正确时，将收到的CRC结果拼接到源数据的尾部一同输入到一下函数，可返回是否校验通过。

```c
crc_bool   Crc_Check_Crc8(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8_Itu(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8_Rohc(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc8_Maxim(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc32(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc32_Mpeg2(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Ibm(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Maxim(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Usb(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Modbus(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Ccitt(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_CcittFalse(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_X25(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Xmosem(crc_uint8* data, crc_uint32 len);
crc_bool   Crc_Check_Crc16_Dnp(crc_uint8* data, crc_uint32 len);

```

当需要个性定制多项式、初始值、输出异或值、输入数据反演、输出数据反演使用一下函数。

```c
//CRC Calculate
crc_uint8  Crc_Calculate_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout);
crc_uint16 Crc_Calculate_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout);
crc_uint32 Crc_Calculate_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout);
//CRC Check
crc_bool   Crc_Check_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout);
crc_bool   Crc_Check_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout);
crc_bool   Crc_Check_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout);

```
