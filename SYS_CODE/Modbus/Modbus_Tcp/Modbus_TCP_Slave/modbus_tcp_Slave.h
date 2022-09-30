/****************************************Copyright (c)**************************************************
**                               Guangzou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File Name:           MODBUS_TCP.h
** Last modified Date:  2006-9-13
** Last Version:        1.0
** Descriptions:        MODBUS_TCP HEAD FILE
**
**------------------------------------------------------------------------------------------------------
** Created By: liudikai
** Created date:   2006-11-10
** Version: 1.0
** Descriptions: First version
**
**------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
********************************************************************************************************/
#ifndef __MODBUS_TCP_SLAVE_H
#define __MODBUS_TCP_SLAVE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MODBUS_TCP_GLOBALS
#define MODBUS_TCP_EXT
#else
#define MODBUS_TCP_EXT extern
#endif


/*********************************************************************************************************
**                       modbus ��������ѡ��
*********************************************************************************************************/
#define MODBUS_SERVER_INSIDE_EN         1

#if MODBUS_SERVER_INSIDE_EN

/*********************************************************************************************************
** Define which Function code be use in the Modbus Master Protocol Stac
*********************************************************************************************************/                                                                        /* k .                          */
#define    TCP_READ_COILS_EN            1                               /* ����Ȧ                       */
#define    TCP_READ_DIS_INPUT_EN        1                               /* ����ɢ������                 */
#define    TCP_READ_HOLD_REG_EN         1                               /* �����ּĴ���                 */
#define    TCP_READ_INPUT_REG_EN        1                               /* ������Ĵ���                 */
#define    TCP_WRITE_SING_COIL_EN       1                               /* д������Ȧ                   */
#define    TCP_WRITE_SING_REG_EN        1                               /* д�����Ĵ���                 */
#define    TCP_WRITE_MULT_COIL_EN       1                               /* д�����Ȧ                   */
#define    TCP_WRITE_MULT_REG_EN        1                               /* д����Ĵ���                 */
#define    TCP_MASK_WRITE_REG_EN        1                               /* �������μĴ���ָ��           */
#define    TCP_READ_WRITE_REG_EN        1                               /* ��д����Ĵ���               */

#endif


/*********************************************************************************************************
** modbus ������
*********************************************************************************************************/    
#define READ_COILS                      1
#define READ_DIS_INPUT                  2
#define READ_MUL_REGS                   3
#define READ_INPUT_REG                  4
#define WRITE_SING_COIL                 5
#define WRITE_SING_REG                  6
#define WRITE_MULT_COIL                 15
#define WRITE_MULT_REG                  16
#define MASK_WRITE_REG                  22
#define READ_WRITE_REG                  23

/*********************************************************************************************************
** �������س������  ModbusЭ�鶨��ĳ������
*********************************************************************************************************/ 
#define MB_NO_ERR                     0x00                              /* �޴���                       */
#define ILLEGAL_FUNCTION              0x01                              /* ��Ч���ܴ���                 */
#define ILLEGAL_DATA_ADDR             0x02                              /* ��Ч��ַ                     */
#define ILLEGAL_DATA_VALUE            0x03                              /* ��Ч����ֵ                   */
#define SLAVE_DEVICE_FAILURE          0x04                              /* ���豸����                   */
#define ACKNOWLEDGE                   0x05
#define SLAVE_DEVICE_BUSY             0x06
#define MEMORY_PARITY_ERR             0x08
#define GATEWAY_PATH_UNABLE           0x0A
#define GATEWAY_TARGET_DEV_FAIL       0x0B
#define MB_TREATED_WRONG              -1

/*********************************************************************************************************
** �����û����ʺ��� (���û���д)
*********************************************************************************************************/ 
#define MODBUS_SLAVER_INSIDE_EN        1

extern  uint8 MB_TCP_GetDiscrete (uint8 ch,uint8 *DisInputsV,uint16 Address);   /* ��ȡ��Ȧֵ           */
extern  uint8 MB_TCP_GetCoils    (uint8 ch,uint8 *DisInputsV,uint16 Address);   /* ��ȡ��Ȧֵ           */
extern  uint8 MB_TCP_SetCoil     (uint8 ch,uint16 Address,uint8 CoilValue);     /* ������Ȧֵ           */
extern  uint8 MB_TCP_GetInputRegValue(uint8 ch,uint16 *ValuePtr,uint16 Address);/* ������Ĵ���ֵ       */                                                                      
extern  uint8 MB_TCP_GetRegValue (uint8 ch,uint16 *ValuePtr,uint16 Address);    /* �����ּĴ���ֵ       */                                                                       
extern  uint8 MB_TCP_SetRegValue (uint8 ch,uint16 Address,uint16 Value);        /* д���ּĴ���ֵ       */
                                                                        
/********************************************************************************************************
**                             Structure Define
********************************************************************************************************/

typedef struct __RW_PARAMET
{
    uint8      ch;                                                      /* ch,ModbusͨѶ�ܵ�            */
    uint16     RStartAddr;                                              /* ����ʼ��ַ                   */
    uint16     RQuantity;                                               /* ������                       */
    uint16     WStartAddr;                                              /* д��ʼ��ַ                   */
    uint16     WQuantity;                                               /* д����                       */
                                                                  /* uint16 *DataPtr; ���������ֵ��ָ��*/

}RW_PARAMET,READ_PARAMET,WRITE_PARAMET;

typedef struct
{
    int16    Treated_len;
    int16    Send_len;
}MOD_LEN;

/*********************************************************************************************************
** MODBUS_TCP������
*********************************************************************************************************/ 
    MODBUS_TCP_EXT MOD_LEN ModbusTcp_Server_Process(uint8 *modbus_req,uint8 *modbus_resp);
#ifdef __cplusplus
    extern "}"
#endif
#endif

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
