/****************************************Copyright (c)**************************************************
**                               
**                                      
**                                 
**
**--------------File Info-------------------------------------------------------------------------------
** File name:           RequestFun.h
** Last modified Date:  2013-11-30
** Last Version:        2.0
** Descriptions:
**
**------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-11-30
** Version:             2.0
** Descriptions:
**
**------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
********************************************************************************************************/
#ifndef __REQUESTFUN_H
#define __REQUESTFUN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************
    Modbus ��������������ݽṹ
*********************************************************************************************************/
typedef struct __request_data {
    INT8U               ucChnl;                                         /*  ����Ӳ��ͨ����              */
    INT16U              usRStartAddr;                                   /*  ���ݶ���ַ                  */
    
    INT16U              usRSize;                                        /*  �����ݸ���                  */
    INT16U              usWStartAddr;                                   /*  ����д��ַ                  */
    
    INT16U              usWSize;                                        /*  д���ݸ���                  */
    void               *pvData;                                         /*  ��д���ݴ�ŵ�ַ            */     
}__REQUEST_DATA, __PREQUEST_DATA;


/*********************************************************************************************************
** Function name:           MB_UartReadCoils
**
** Descriptions:            ��ȡ��Ȧֵ��0x01
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          StartAddress����Ȧ��ʼ��ַ
**                          Quantity����Ȧ����
**                          ReaValuePtr��������Ȧֵ��ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U MB_UartReadCoils01(INT8U  ch,
                  INT8U  ID,
                  INT16U StartAddress,
                  INT16U Quantity,
                  INT8U *ReaValuePtr);

#define  OSReadCoils    MB_UartReadCoils01

/*********************************************************************************************************
** Function name:           MB_UartReadDisInputs02
**
** Descriptions:            ��ȡ��ɢ��������0x02
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          StartAddress����ɢ��������ʼ��ַ
**                          Quantity����ɢ����������
**                          ReaValuePtr��������ɢ������ֵ��ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
INT8U MB_UartReadDisInputs02(INT8U  ch,
                      INT8U  ID,
                      INT16U StartAddress,
                      INT16U Quantity,
                      INT8U *ReaValuePtr);
                      
#define OSReadDisInputs        MB_UartReadDisInputs02

/*********************************************************************************************************
** Function name:           MB_UartReadHoldReg03
**
** Descriptions:            ��ȡ���ּĴ���ֵ��ָ�����Ϊ��0x03��
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          StartAddress���Ĵ�����ʼ��ַ
**                          Quantity���Ĵ�������
**                          ReaValuePtr����������Ĵ���ֵ��ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U MB_UartReadHoldReg03(INT8U ch,
                    INT8U ID,
                    INT16U StartAddress,
                    INT16U Quantity,
                    INT16U *ReaValuePtr);                               /* �����ּĴ���                 */

#define OSReadHoldReg    MB_UartReadHoldReg03

/*********************************************************************************************************
** Function name:           MB_UartReadInputReg04
**
** Descriptions:            ��ȡ����Ĵ���ֵ��ָ�����Ϊ��0x04��
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          StartAddress������Ĵ�����ʼ��ַ
**                          Quantity������Ĵ�������
**                          ReaValuePtr�������������Ĵ���ֵ��ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U MB_UartReadInputReg04( INT8U  ch,
                      INT8U  ID,
                      INT16U StartAddress,
                      INT16U Quantity,
                      INT16U *ReaValuePtr);
 #define OSReadInputReg        MB_UartReadInputReg04

/*********************************************************************************************************
** Function name:           MB_UartWriteSingleCoil05
**
** Descriptions:            д����Ȧ������ָ�����Ϊ��0x04��
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          OutAddress��д����Ȧ�ĵ�ַ(0x0000~0xffff)
**                          OutValue��д����Ȧ��ֵCOIL_OFF��COIL_ON
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              ZhouLishan
** Created Date:            2006/06/06
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U MB_UartWriteSingleCoil05(INT8U ch,
                        INT8U  ID,
                        INT16U OutAddress,
                        INT16U OutValue);
 #define OSWriteSingleCoil    MB_UartWriteSingleCoil05
 
/*********************************************************************************************************
** Function name:           MB_UartWriteSingleReg06
**
** Descriptions:            д���Ĵ���������0x06
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          OutAddress��д��ĵ�ַ(0x0000~0xffff)
**                          OutValue��д���ֵ(0x0000~0xffff)
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U MB_UartWriteSingleReg06(INT8U ch,
                       INT8U  ID,
                       INT16U OutAddress,
                       INT16U OutValue);



/*********************************************************************************************************
** Function name:           MB_UartWriteMultipleCoils15
**
** Descriptions:            д����Ȧ������0x0f
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          StartAddress��д����Ȧ����ʼ��ַ(0x0000~0xffff)
**                          Quantity��д�����Ȧ������
**                          *ValuePtr��д�����ݵ�ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U  MB_UartWriteMultipleCoils15(INT8U ch,
                            INT8U ID,
                            INT16U StartAddress,
                            INT16U Quantity,
                            INT8U *ValuePtr);
                            
#define WriteMultipleCoils0f     MB_UartWriteMultipleCoils15
#define WriteMultipleCoils0F     MB_UartWriteMultipleCoils15
#define OSWriteMultipleCoils     MB_UartWriteMultipleCoils15

/*********************************************************************************************************
** Function name:           MB_UartWriteMultipleReg16
**
** Descriptions:            д��Ĵ���������0x10
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          StartAddress��д��Ĵ�������ʼ��ַ(0x0001~0xffff)
**                          Quantity��д��Ĵ���������(0x0001~0x0078)
**                          *ValuePtr��д��Ĵ������ݵ�ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              ZhouLishan
** Created Date:            2006/06/06
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U  MB_UartWriteMultipleReg16(INT8U  ch,
                          INT8U  ID,
                          INT16U StartAddress,
                          INT16U Quantity,
                          INT16U *ValuePtr)    ;


/*********************************************************************************************************
** Function name:           MB_UartMaskWriteReg22
**
** Descriptions:            ����д�Ĵ������������Or_MaskֵΪ�㣬��ô����ǵ�ǰ���ݺ�And_Mask�ļ�
**                          �߼�AND���룩�����And_MaskֵΪ�㣬�������Or_Maskֵ��0x16
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          Addr��д��Ĵ����ĵ�ַ(0x0001~0xffff)
**                          And_Mask������д������
**                          Or_Mask������д������
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              ZhouLishan
** Created Date:            2006/06/06
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern INT8U  MB_UartMaskWriteReg22(INT8U  ch,
                      INT8U  ID,
                      INT16U Addr,
                      INT16U And_Mask,
                      INT16U Or_Mask);
                      
#define OSMaskWriteReg     MB_UartMaskWriteReg22
#define MaskWriteReg16     MB_UartMaskWriteReg22


/*********************************************************************************************************
** Function name:           ReadWriteMultipleReg23
**
** Descriptions:            ͬʱд����Ĵ�����������д��������0x17
**
** input parameters:        ch,ModbusͨѶ�ܵ�
**                          ID���ӻ���ַ
**                          WStartAddr��д��Ĵ�������ʼ��ַ(0x0001~0xffff)
**                          WQuantity��д��Ĵ���������
**                          RStartAddr�������Ĵ�������ʼ��ַ(0x0001~0xffff)
**                          RQuantity�������Ĵ���������
**                          *DataPtr��д��Ĵ�����ָ��Ͷ������ݴ��ָ��
** Returned value:          ��ɴ��룺(��modbus.h�ļ����쳣�����)
**
** Created by:              ZhouLishan
** Created Date:            2006/06/06
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
INT8U  ReadWriteMultipleReg23(INT8U   ch,
                              INT8U   ID,
                              INT16U  WStartAddr,
                              INT16U  WQuantity,
                              INT16U  RStartAddr,
                              INT16U  RQuantity,
                              INT16U *DataPtr);
                              
#define OSReadWriteMultipleReg     ReadWriteMultipleReg23
#define ReadWriteMultipleReg17     ReadWriteMultipleReg23

#ifdef __cplusplus
}
#endif                                                                  /* __cplusplus                  */
#endif                                                                  /* __REQUESTFUN_H               */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
