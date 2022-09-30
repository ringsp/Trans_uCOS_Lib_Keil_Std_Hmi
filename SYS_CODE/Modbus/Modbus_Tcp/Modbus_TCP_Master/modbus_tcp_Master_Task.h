/****************************************Copyright (c)**************************************************
**                               Guangzou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File Name:           modbus_tcp_Master_Task.h
** Last modified Date:  2008-3-17
** Last Version:        1.0
** Descriptions:        MODBUS_TCP_CLIENT HEAD FILE
**
**------------------------------------------------------------------------------------------------------
** Created By:          liudikai
** Created date:        2008-3-17
** Version:             1.0
** Descriptions:        First version
**
**------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
********************************************************************************************************/
#ifndef __MODBUS_TCP_MASTER_TASK_H
#define __MODBUS_TCP_MASTER_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MODBUS_TCP_GLOBALS
#define MODBUS_TCP_EXT
#else
#define MODBUS_TCP_EXT extern
#endif
/*******************************************************************************************************
**                             modbus������
*******************************************************************************************************/
#define READ_COILS                                1
#define READ_DIS_INPUT                            2
#define READ_MUL_REGS                             3
#define READ_INPUT_REG                            4
#define WRITE_SING_COIL                           5
#define WRITE_SING_REG                            6
#define WRITE_MULT_COIL                           15
#define WRITE_MULT_REG                            16
#define MASK_WRITE_REG                            22
#define READ_WRITE_REG                            23
/********************************************************************************************************
**                          MODBUS/TCP��������ʹ��
********************************************************************************************************/
#define MODBUS_TCP_MASTER_INSIDE_EN               1
#if MODBUS_TCP_MASTER_INSIDE_EN
#define    MB_TCP_READ_COILS_EN                   1                     /* ����Ȧ                       */
#define    MB_TCP_READ_DIS_INPUT_EN               1                     /* ����ɢ������                 */
#define    MB_TCP_READ_HOLD_REG_EN                1                     /* �����ּĴ���                 */
#define    MB_TCP_READ_INPUT_REG_EN               1                     /* ������Ĵ���                 */
#define    MB_TCP_WRITE_SING_COIL_EN              1                     /* д������Ȧ                   */
#define    MB_TCP_WRITE_SING_REG_EN               1                     /* д�����Ĵ���                 */
#define    MB_TCP_WRITE_MULT_COIL_EN              1                     /* д�����Ȧ                   */
#define    MB_TCP_WRITE_MULT_REG_EN               1                     /* д����Ĵ���                 */
#define    MB_TCP_MASK_WRITE_REG_EN               1                     /* �������μĴ���ָ��           */
#define    MB_TCP_READ_WRITE_REG_EN               1                     /* ��д����Ĵ���               */
#endif
/********************************************************************************************************
**                          MODBUS/TCP����������
********************************************************************************************************/
#define MB_NO_ERR                                 0x00                  /* �޴���                       */
#define ILLEGAL_FUNCTION                          0x01                  /* ��Ч���ܴ���                 */
#define ILLEGAL_DATA_ADDR                         0x02                  /* ��Ч��ַ                     */
#define ILLEGAL_DATA_VALUE                        0x03                  /* ��Ч����ֵ                   */
#define SLAVE_DEVICE_FAILURE                      0x04                  /* ���豸����                   */
#define ACKNOWLEDGE                               0x05                  /* ȷ��                         */
#define SLAVE_DEVICE_BUSY                         0x06                  /* ���豸æ                     */
#define MEMORY_PARITY_ERR                         0x08                  /* �洢Ч��ʧ��                 */
#define GATEWAY_PATH_UNABLE                       0x0A                  /* ����·��������               */
#define GATEWAY_TARGET_DEV_FAIL                   0x0B                  /* ����Ŀ���豸��Ӧʧ��         */
                                                                        /* ZY/ModbusTcpЭ��ջ�������� */
                                                                        /* ��                           */
#define MODBUS_TCP_FUN_NOT_DEF                    0x90                  /* δ���幦�ܴ���               */
#define MODBUS_TCP_PARAMETER_ERR                  0x91                  /* ��������                     */
#define MODBUS_TCP_THE_CH_BUSY                    0x92                  /* �ܵ�æ������ʹ��             */
#define MODBUS_TCP_RESPONSE_TIME_OUT              0x93                  /* Ӧ��ʱ                     */
#define MODBUS_TCP_PARITY_FUN_ERR                 0x94                  /* Ӧ���������               */
#define MODBUS_TCP_SEND_ERROR                     0x95                  /* ��������֡ʧ��               */
#define MODBUS_TCP_RECV_ERROR                     0x96                  /* ����Ӧ��֡ʧ��               */

/********************************************************************************************************
**                          MODBUS/TCP����״̬��
********************************************************************************************************/
                                                                        /* #define COIL_OFF  0          */
                                                                        /* #define COIL_ON   0xff00     */


#define MB_TCP_WAITE_HANDLE                       0xB0                  /* ����״̬                     */
#define MB_TCP_RECEIVE_DATA                       0xB1                  /* ����Ӧ������                 */
#define MB_TCP_SEND_DATA                          0xB2                  /* ��������                     */
#define MB_TCP_TIME_OUT_HANDLE                    0xB3                  /* ��Ӧ��ʱ                     */
#define MB_TCP_WAITING_FOR_REPLY                  0xB4                  /* �ȴ�Ӧ��                     */
#define MB_TCP_REPLY_RIGHT                        0xB5                  /* Ӧ����ȷ                     */
#define MB_TCP_DELETE_EVENT_HANDLE                0xB6                  /* ɾ�����¼�                   */
#define MB_TCP_WAITE_FOR_DELETE                   0xB7                  /* �ȴ�ɾ�����¼�               */

/********************************************************************************************************
**                          MODBUS/TCP������������
********************************************************************************************************/
#define TASK_MB_TCP_MASTER_ID                     6
#define TASK_MB_TCP_MASTER_PRIO                   6
#define TASK_MB_TCP_MASTER_STACK_SIZE             128
    MODBUS_TCP_EXT OS_STK task_mb_tcp_master_stack[TASK_MB_TCP_MASTER_STACK_SIZE];
/********************************************************************************************************
**                             Structure Define
********************************************************************************************************/
typedef struct
{
    uint8     Link_Num;                                                 /* modbus_tcp���Ӻ�             */
    uint8     state;                                                    /* modbusͨ��״̬               */
    uint8     resent_id;                                                /* ��ǰID��                     */
    uint8     function;                                                 /* ��ǰ������                   */
    uint16    unit_id_num;                                              /* modbus_tcp�������ʶ��     */
    uint16    timeout;                                                  /* modbus_tcp��ʱʱ��ֵ         */
    uint16    Time_Tick;                                                /* modbus_tcp��ʱӦ���ʱ��     */
                                                                        /* ��λ��ms(����)               */
    uint8     Modbus_Tcp_RecBuf[MAX_MB_TCP_REC_BUF_SIZE];               /* modbus_tcp���ջ�����         */
    uint8     Modbus_Tcp_SenBuf[MAX_MB_TCP_SEN_BUF_SIZE];               /* modbus_tcp���ͻ�����         */
    uint8    *user_buf_ptr;                                             /* modbus_tcp�û��������ݵ�ַָ */
                                                                        /* ��                           */
    uint16    send_len;                                                 /* modbus_tcp����֡����         */
    uint8     ret;                                                      /* modbus_tcp����ֵ             */
    OS_EVENT  *mbm_handle_event_ptr;                                    /* modbus_tcp�����ź���         */
    OS_EVENT  *mbm_handle_event_over_ptr;                               /* modbus_tcp�ȴ���Ӧ�ź���     */

    uint16    RStartAddr;                                               /* ����ʼ��ַ                   */
    uint16    RQuantity;                                                /* ������                       */
    uint16    WStartAddr;                                               /* д��ʼ��ַ                   */
    uint16    WQuantity;                                                /* д����                       */
}MODBUS_TCP_S;

    MODBUS_TCP_EXT INT8U  Modbus_Tcp_MasterInit(void);

    MODBUS_TCP_EXT void   MB_TCP_TimeHandle(void);
#ifdef __cplusplus
    extern "}"
#endif
#endif
/********************************************************************************************************
**                              End Of File
********************************************************************************************************/