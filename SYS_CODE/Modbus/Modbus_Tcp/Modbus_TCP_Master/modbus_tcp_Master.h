/****************************************Copyright (c)**************************************************
**                               Guangzou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:           MODBUS_TCP_MASTER.h
** Last modified Date:  2008-3-17
** Last Version:        1.0
** Descriptions:        modbus_tcp_client_function source file
**------------------------------------------------------------------------------------------------------
** Created by:          liudikai
** Created date:        2008-3-17
** Version:             1.0
** Descriptions:        The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
********************************************************************************************************/
#ifndef __MODBUS_TCP_MASTER_H
#define __MODBUS_TCP_MASTER_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef MODBUS_TCP_GLOBALS
#define MODBUS_TCP_EXT

#else
#define MODBUS_TCP_EXT extern
#endif

#if MODBUS_TCP_MASTER_INSIDE_EN
/*********************************************************************************************************
** Function name:           MB_TCP_ReadCoils
**
** Descriptions:            ��ȡ��Ȧֵ��0x01
**
** input parameters:        Link_num,       TCP���Ӻ�
**                          ID��            �ӻ���ַ
**                          StartAddress��  ��Ȧ��ʼ��ַ
**                          Quantity��      ��Ȧ����
**                          ReaValuePtr��   ������Ȧֵ��ָ��
**                          time_out��      ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺      (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_READ_COILS_EN
MODBUS_TCP_EXT uint8  MB_TCP_ReadCoils( uint8  Link_num,
                                        uint8  ID,
                                        uint16 StartAddress,
                                        uint16 Quantity,
                                        uint8  *ReaValuePtr,
                                        uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_ReadDisInputs
**
** Descriptions:            ��ȡ��ɢ��������0x02
**
** input parameters:        Link_num,       TCP���Ӻ�
**                          ID��            �ӻ���ַ
**                          StartAddress��  ��ɢ��������ʼ��ַ
**                          Quantity��      ��ɢ����������
**                          ReaValuePtr��   ������ɢ������ֵ��ָ��
**                          time_out��      ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺      (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_READ_DIS_INPUT_EN
MODBUS_TCP_EXT uint8  MB_TCP_ReadDisInputs( uint8  Link_num,
                                            uint8  ID,
                                            uint16 StartAddress,
                                            uint16 Quantity,
                                            uint8  *ReaValuePtr,
                                            uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_ReadHoldReg
**
** Descriptions:            ��ȡ���ּĴ���ֵ��ָ�����Ϊ��0x03��
**
** input parameters:        Link_num,        TCP���Ӻ�
**                          ID��             �ӻ���ַ
**                          StartAddress��   �Ĵ�����ʼ��ַ
**                          Quantity��       �Ĵ�������
**                          ReaValuePtr��    ��������Ĵ���ֵ��ָ��
**                          time_out��       ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺       (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_READ_HOLD_REG_EN
MODBUS_TCP_EXT  uint8  MB_TCP_ReadHoldReg(  uint8  Link_num,
                                            uint8  ID,
                                            uint16 StartAddress,
                                            uint16 Quantity,
                                            uint16 *ReaValuePtr,
                                            uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_ReadInputReg
**
** Descriptions:            ��ȡ����Ĵ���ֵ��ָ�����Ϊ��0x04��
**
** input parameters:        Link_num,         TCP���Ӻ�
**                          ID��              �ӻ���ַ
**                          StartAddress��    ����Ĵ�����ʼ��ַ
**                          Quantity��        ����Ĵ�������
**                          ReaValuePtr��     �����������Ĵ���ֵ��ָ��
**                          time_out��        ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺        (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_READ_INPUT_REG_EN
MODBUS_TCP_EXT  uint8  MB_TCP_ReadInputReg( uint8  Link_num,
                                            uint8  ID,
                                            uint16 StartAddress,
                                            uint16 Quantity,
                                            uint16 *ReaValuePtr,
                                             uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_WriteSingleCoil
**
** Descriptions:            д����Ȧ������ָ�����Ϊ��0x05��
**
** input parameters:        Link_num,       TCP���Ӻ�
**                          ID��            �ӻ���ַ
**                          OutAddress��    д����Ȧ�ĵ�ַ(0x0000~0xffff)
**                          OutValue��      д����Ȧ��ֵCOIL_OFF��COIL_ON
**                          time_out��      ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺      (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_WRITE_SING_COIL_EN
MODBUS_TCP_EXT  uint8  MB_TCP_WriteSingleCoil(  uint8  Link_num,
                                                uint8  ID,
                                                uint16 OutAddress,
                                                uint16 OutValue,
                                                uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_WriteSingleReg
**
** Descriptions:            д���Ĵ���������0x06
**
** input parameters:        Link_num,       TCP���Ӻ�
**                          ID��            �ӻ���ַ
**                          OutAddress��    д��ĵ�ַ(0x0000~0xffff)
**                          OutValue��      д���ֵ(0x0000~0xffff)
**                          time_out��      ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺      (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_WRITE_SING_REG_EN
MODBUS_TCP_EXT uint8  MB_TCP_WriteSingleReg(  uint8  Link_num,
                                              uint8  ID,
                                              uint16 OutAddress,
                                              uint16 OutValue,
                                              uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_WriteMultipleCoils
**
** Descriptions:            д����Ȧ������0x0f
**
** input parameters:        Link_num,         TCP���Ӻ�
**                          ID��              �ӻ���ַ
**                          StartAddress��    д����Ȧ����ʼ��ַ(0x0000~0xffff)
**                          Quantity��        д�����Ȧ������
**                         *ValuePtr��        д�����ݵ�ָ��
**                          time_out��        ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺        (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_WRITE_MULT_COIL_EN
MODBUS_TCP_EXT  uint8  MB_TCP_WriteMultipleCoils( uint8  Link_num,
                                                  uint8  ID,
                                                  uint16 StartAddress,
                                                  uint16 Quantity,
                                                  uint8  *ValuePtr,
                                                  uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_WriteMultipleReg
**
** Descriptions:            д��Ĵ���������0x10
**
** input parameters:        Link_num,         TCP���Ӻ�
**                          ID��              �ӻ���ַ
**                          StartAddress��    д��Ĵ�������ʼ��ַ(0x0001~0xffff)
**                          Quantity��        д��Ĵ���������(0x0001~0x0078)
**                         *ValuePtr��        д��Ĵ������ݵ�ָ��
**                          time_out��        ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺        (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_WRITE_MULT_REG_EN
MODBUS_TCP_EXT  uint8  MB_TCP_WriteMultipleReg( uint8  Link_num,
                                                uint8  ID,
                                                uint16 StartAddress,
                                                uint16 Quantity,
                                                uint16 *ValuePtr,
                                                uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_MaskWriteReg
**
** Descriptions:            ����д�Ĵ������������Or_MaskֵΪ�㣬��ô����ǵ�ǰ���ݺ�And_Mask�ļ�
**                          �߼�AND���룩�����And_MaskֵΪ�㣬�������Or_Maskֵ��0x16
**
** input parameters:        Link_num,        TCP���Ӻ�
**                          ID��             �ӻ���ַ
**                          Addr��           д��Ĵ����ĵ�ַ(0x0001~0xffff)
**                          And_Mask��       ����д������
**                          Or_Mask��        ����д������
**                          time_out��       ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺       (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_MASK_WRITE_REG_EN
MODBUS_TCP_EXT  uint8  MB_TCP_MaskWriteReg( uint8  Link_num,
                                            uint8  ID,
                                            uint16 Addr,
                                            uint16 And_Mask,
                                            uint16 Or_Mask,
                                            uint16 time_out );
#endif
/*********************************************************************************************************
** Function name:           MB_TCP_ReadWriteMultipleReg
**
** Descriptions:            ͬʱд����Ĵ�����������д��������0x17
**
** input parameters:        Link_num,        TCP���Ӻ�
**                          ID��             �ӻ���ַ
**                          WStartAddr��     д��Ĵ�������ʼ��ַ(0x0001~0xffff)
**                          WQuantity��      д��Ĵ���������
**                          RStartAddr��     �����Ĵ�������ʼ��ַ(0x0001~0xffff)
**                          RQuantity��      �����Ĵ���������
**                         *DataPtr��        д��Ĵ�����ָ��Ͷ������ݴ��ָ��
**                          time_out��       ��Ӧ��ʱʱ�䣬��λms
** Returned value:          ��ɴ��룺       (��modbus.h�ļ����쳣�����)
**
** Created by:              Liudikai
** Created Date:            2008-03-18
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if    MB_TCP_READ_WRITE_REG_EN
MODBUS_TCP_EXT  uint8  MB_TCP_ReadWriteMultipleReg( uint8 Link_num,
                                                    uint8 ID,
                                                    uint16 WStartAddr,
                                                    uint16 WQuantity,
                                                    uint16 RStartAddr,
                                                    uint16 RQuantity,
                                                    uint16 *DataPtr,
                                                    uint16 time_out );
#endif
#endif

#ifdef __cplusplus
    extern "}"
#endif
#endif
/********************************************************************************************************
**                                            End Of File
********************************************************************************************************/
