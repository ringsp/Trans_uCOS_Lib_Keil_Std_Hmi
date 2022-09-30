/****************************************Copyright (c)****************************************************
**                               
**                                      
**                                 
**
**--------------------------------------------------------------------------------------------------------
** File name:           ModbusUser.h
** Last modified Date:  2013-11-30
** Last Version:        2.0
** Descriptions:        Modbus��������û�ʹ�õĺ궨�弰���ֺ���������
**
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-11-30
** Version:             2.0
** Descriptions:
**
**--------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:
**
*********************************************************************************************************/
#ifndef __MODBUSUSER_H
#define __MODBUSUSER_H


#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************
    ModbusЭ�鶨��ĳ������
*********************************************************************************************************/
#define EXCEPTION_CODE_1              1
#define EXCEPTION_CODE_2              2
#define EXCEPTION_CODE_3              3
#define EXCEPTION_CODE_4              4
#define EXCEPTION_CODE_5              5
#define EXCEPTION_CODE_6              6

/*********************************************************************************************************
    �������س������
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

/*********************************************************************************************************
    ZY/ModbusЭ��ջ�Զ���������
*********************************************************************************************************/
#define MB_FUN_NOT_DEF                0x80                              /* δ���幦�ܴ���               */
#define MB_THE_CH_BUSY                0x81                              /* �ܵ�æ������ʹ��             */
#define MB_RESPONSE_TIME_OUT          0x82                              /* Ӧ��ʱ                     */
#define MB_PARAMETER_ERR              0x83                              /* ��������                     */
#define MB_INVALID_CH                 0x84                              /* ��Ч�Ĺܵ�                   */
#define MB_INVALID_MOD                0x85                              /* ��Ч��ģʽ                   */
#define MB_INVALID_BAUD               0x85                              /* ��Ч�Ĳ�����                 */
#define MB_MALLOC_ERR                 0x86                              /* �����ڴ����                 */
#define MB_OS_EVENT                   0x87                              /* ����OS��Դ����               */

/*********************************************************************************************************
                      ����Ϊ�����ش���
                ����ΪZY/Modbus2.0Э��ջ״̬��
*********************************************************************************************************/
#define MB_SENT_REQUEST               0x90                              /* ��������                     */
#define MB_WAITE_RESPONSIONING        0x91                              /* ���ڴ���                     */
#define MB_POLL_DELAY                 0x92
#define MB_WAITING_POLL_DELAY         0x93
#define MB_WAITING_FOR_REPLY          0x94
#define MB_WAITING_SENDING            0x95
#define MB_PROCESSING_REPLY           0x96                              /* Ӧ����                     */
#define MB_WAITE_HANDLE               0x97                              /* �ȴ�����                     */
#define MB_RESPONSIONING_HANDLE       0x98

#define MB_DELETE_EVENT_LIST          0x99                              /* ɾ���¼��б���               */
#define MB_RECEIVE_EVENT              0xA0                              /* �����¼�                     */
#define MB_RECEIVE_DATA               0xA1                              /* ��������                     */
#define MB_RECEIVE_FRAME              0xA2                              /*  �ӻ����յ�����ʱ����
                                                                            MB_RESPONSIONING_HANDLE
                                                                            ��һ����ֵ                  */
#define MB_WAITE_RECEIVE              0xA3                              /* �ȴ���������״̬             */
#define MB_SEND_EVENT                 0xA4                              /* �����¼�״̬                 */
#define MB_SEND_DATA                  0xA5                              /* ��������״̬                 */
#define MB_TIME_OUT_HANDLE            0xA6                              /* ��ʱ����                     */



/*********************************************************************************************************
    ����㲥��ַ
*********************************************************************************************************/
#define    BROADCAST_ADDRESS          0



typedef struct __master_poll {
    OS_EVENT       *pSem;
    INT8U           ucChnl; 
    INT8U           ucId;
    INT8U           ucExceptionCode;
    INT8U         (*pfFunc2PDU)(void *pvPara);
    void          (*pfFuncParse)(INT8U *pucOut, void *pvIn);
    void           *pvPara;
    struct __master_poll *pNext;
    INT8U           ucRsv18;
    
} __MASTER_POLL, *__PMASTER_POLL; 



/*********************************************************************************************************
    PDU֡��������ṹ
*********************************************************************************************************/
typedef struct __PDU_RESPONSE{
    uint8*   PDUDataPtr;                                                /*  ��������ָ��,���ܴ��봦��
                                                                            �����轫��������ݰ����ڸ�
                                                                            ָ��Ŀ�ʼλʼ              */
    uint8    PDUByteLength;                                             /* ��������������               */
    uint8    ExceptionCode;                                             /*  ��Ϊ������쳣���룬
                                                                            ����������Ϊ0               */
}PDU_RESPONSE;



/*********************************************************************************************************
    MODBUS�豸���ò������ݽṹ
    Ӧ�ó����ʼ������ʱʹ�ø����ݽṹ
*********************************************************************************************************/
typedef struct __MB_CFG{
    INT8U   ch;                                                         /* ���ùܵ���(0~MB_MAX_CH-1)    */
    INT8U   node_addr;                                                  /* �ڵ��ַ(1~255)��ֵΪ0��ʾΪ */
                                                                        /* ���豸                       */
    INT8U   modbus_mode;                                                /* ��·��Э��,MB_RTU_MODE('R'), */
                                                                        /* MB_ASC                       */
                                                                        /* II_MODE('A'),MB_TCP_MODE('T' */
                                                                        /* )                            */

    ////
    INT32U  BaudRate;                                                   /* ������(1200��2400��4800��9600*/
                                                                        /* 19200��38400��57600��115200) */
    ////
    INT8U   bits;                                                       /* �ַ�����:00(5λ�ַ�)01(6λ)10*/
                                                                        /* (7λ)11(8λ)                 */
    INT8U   parity;                                             /* ��żУ��:0,��У�飻1,��У��;2,żУ�� */
    INT8U   stops;                                                      /* ֹͣλ:0Ϊ1λ��1Ϊ2λ��      */

    INT8U   wr_en;                                                      /* дʹ�ܣ�������               */
    
    ////
    /*
     *   �������ݽṹ
     */
    INT16U  usADUBufSize;                                               /* ADU��������С                */
    
    ////
    INT8U   *pucADUPtr;                                                 /* ADU������ָ��                */
    
    ////
    INT16U  usQSendSize;                                                /* �ײ�UART�������ͻ�������С   */
    ////
    INT8U   *puqSendBuf;                                                /* �ײ�UART�������ͻ�����ָ��   */
    
    ////
    struct __MBDSTR *mbdPtr;                                            /* ������Ϣ�ڴ�ָ��             */

    /*
     *   �ײ�������Ϣ���ݽṹ
     */
    void    *pvDriver;
    INT8U   (*PortCfg)  (struct __MB_CFG *mb_ch);                       /* ��UART���������ݽṹ         */
    
    void    (*SendData) (INT8U ucCh,INT8U *ucBuf,INT16U usLen);
                                                                        /* �������ݺ���ָ��             */
    void    (*ExitPort) (void *pDriver);                                /* �˳�Modbus����ʱʹ�øú���   */
}MB_CFG;

/*********************************************************************************************************
    Modbus�ܵ���Ϣ������ݽṹ
*********************************************************************************************************/
typedef struct __MBDSTR {
    INT8U           ucChnl;                                             /*  ͨ����                      */// 0x00
    INT8U           ucNodeAddr;                                         /*  վ�� 0: ��վ 1~255 ��վ     */// 0x01    
    INT8U           ucModbusMode;                                       /*  Modbusģʽ                  */// 0x02
    
    INT32U          uiBaudRate;                                         /*  ���ڲ�����                  */// 0x04
    
    INT8U           ucDataBits;                                         /*  ��������λ                  */// 0x08
    INT8U           ucParity;                                           /*  ����У�鷽ʽ                */// 0x09
    INT8U           ucStopBits;                                         /*  ����ֹͣλ                  */// 0x0A
    INT8U           ucWrEn;                                             /*  дʹ��                      */// 0x0B
    
    INT8U           ucT15Ticks;                                         /*  T15������                   */// 0x0C        
    INT8U           ucT35Ticks;                                         /*  T35������                   */// 0x0D
    INT16U          usAsciiRcvLen;                                      /*  ASCII���ճ���               */// 0x0E     
    
    INT8U           ucIsAsciiRcvStart;                                  /*  ASCII������ʼ��־           */// 0x10    
    INT8U           ucIsAsciiRcvEnd;                                    /*  ASCII������ɱ�־           */// 0x11    
    INT8U           ucStatus;                                           /*  ����״̬��־                */// 0x12     
    
    INT32U          uiResponseTime;                                     /*  ��������ʱ������          */// 0x14    
    
    __MASTER_POLL  *pmpCurrent;                                         /*  ��ǰҪ�������������        */// 0x18           
    
    void           *pvDriver;                                           /*  ָ��Ӳ��������ָ��          */// 0x1C     
                                                                        /*  ���ݷ��ͺ���ָ��            */// 0x20     
    void          (*pfSendData)(INT8U ucChnl, 
                                INT8U *pucBuf, 
                                INT16U usLen);
    
    //INT8U         (*pfPortCfg)(MB_CFG *pmc);                            /*  Ӳ���˿����ú���ָ��        */// 0x24          
    void         (*pfExitPort)(void *pDriver);                         /*  Ӳ���˿��˳�����ָ��        */// 0x24   
    
    struct __MBDSTR*pmbdList;                                           /*  �������modbusͨ��          */// 0x28    
    
    INT8U          *pucPduData;                                         /*  PDU���ݰ�ָ��               */// 0x2C    
    INT8U           ucIsReady;                                          /*  ���ݾ�����־                */// 0x30    
    INT8U           ucCmdCode;                                          /*  ������                      */// 0x31    
    INT8U           ucPduDataLen;                                       /*  PDU���ݳ���                 */// 0x32    
    INT8U           ucExceptionCode;                                    /*  modbus�ܵ��쳣����          */// 0x33    
    INT16U          usAduBufSize;                                       /*  ADU���ݳ���                 */// 0x34    
    
    INT8U          *pucAduData;                                         /*  ADU����ָ��                 */// 0x38    
    
    INT8U           ucDstAddr;                                          /*  ��������Ŀ��վ��            */// 0x3C     
    
    INT16U          usRtuRcvLen;                                        /*  RTU���ճ���                 */// 0x3E    
    
    INT8U           ucIsRtuRcvStart;                                    /*  RTU������ʼ��־             */// 0x40    
    INT8U           ucIsRtuRcvEnd;                                      /*  RTU������ɱ�־             */// 0x41    
    
    __MASTER_POLL  *pmpList;                                            /*  �������������              */// 0x44     
    
    
    struct __MBDSTR*pNext;                                              /*  modbusͨ��˫���������һ��  */// 0x48    
    struct __MBDSTR*pPrev;                                              /*  modbusͨ��˫�������ǰһ��  */// 0x4C    
    
}MBDSTR, *PMBDSTR;

/*********************************************************************************************************
    ���庯��ָ������
*********************************************************************************************************/
typedef void  (*fptr)       (uint8  ch,PDU_RESPONSE *Response);
typedef uint8 (*f2pduptr)   (void  *ParameterPtr);
typedef void  (*f2parseptr) (uint8 *PDUPtr,void *ParameterPtr);


/*********************************************************************************************************
    Modsub�ӻ��Զ���Ĺ�����ṹ
    Modbus Slaver Protocol Stack use.
*********************************************************************************************************/
typedef struct _SUD_FUN_CODE{
    uint8     Code;                                                     /* ���������                 */
    void     *NextPtr;                                                  /*ָ����һ���û����幦�ܴ���ָ��*/
    void     (*Function)(uint8 ch,PDU_RESPONSE *Response);              /* ��������֡PCU���ݴ�����    */
}SUD_FUN_CODE;

/*********************************************************************************************************
    Modsub�����Զ���Ĺ�����ṹ
    Modbus Master Protocol Stack use.
*********************************************************************************************************/
typedef struct _MUD_FUN_CODE{
    uint8     Code;                                                     /* �����������                 */
    void     *NextPtr;                                                  /* ָ���¸��û����幦�ܴ���ָ�� */
    uint8   (*f2pdu)( void *ParameterPtr );                             /* ��װ����֡��PDU���ݺ���ָ��  */
    void    (*f2parse)(uint8 *PDUPtr,void *ParameterPtr);
                                                                        /* ����Ӧ��֡��PDU���ݺ���ָ��  */
}MUD_FUN_CODE;

/*********************************************************************************************************
    Modbus�ӻ����ݴ������ĺ���ָ�����ݽṹ
*********************************************************************************************************/
typedef struct __DATA_HANDLE_FUN {
    uint8 (*GetDiscrete)     (uint8 ch,uint8  *DisInputsV,uint16 Address);
    uint8 (*GetCoils)        (uint8 ch,uint8  *DisInputsV,uint16 Address);
    uint8 (*SetCoil)         (uint8 ch,uint16  Address,   uint8  CoilValue);
    uint8 (*GetInputRegValue)(uint8 ch,uint16 *ValuePtr,  uint16 Address);
    uint8 (*GetRegValue)     (uint8 ch,uint16 *ValuePtr,  uint16 Address);
    uint8 (*SetRegValue)     (uint8 ch,uint16  Address,   uint16 Value);
} DATA_HANDLE_FUN;

/*********************************************************************************************************
    Modbus ������غ궨��
*********************************************************************************************************/
#define   MB_UART0_CH                0                                  /* Modbus UART0�ܵ�             */
#define   MB_UART1_CH                1                                  /* Modbus UART1�ܵ�             */
#define   MB_UART2_CH                2                                  /* Modbus UART2�ܵ�             */
#define   MB_UART3_CH                3                                  /* Modbus UART3�ܵ�             */

#define   MB_UART_8BIT               8                                  /* ����λΪ8λ                  */
#define   MB_UART_7BIT               7                                  /* ����λΪ8λ                  */
#define   MB_UART_1STOP              1                                  /* 1λֹͣλ                    */
#define   MB_NONE_PARITY             0                                  /* ����żУ��λ                 */

#define   MB_RTU_MODE                'R'                                /* Modbus RTUģʽ               */
#define   MB_TCP_MODE                'T'                                /* Modbus TCPģʽ               */
#define   MB_ASCII_MODE              'A'                                /* Modbus ASCIIģʽ             */


#define   COIL_ON                     0xff00                            /* д����ȦֵΪ1�ĺ궨��        */
#define   COIL_OFF                    0x0000                            /* д����ȦֵΪ0�ĺ궨��        */
/*********************************************************************************************************
** Function name:           MB_UartInit
**
** Descriptions:            ModbusЭ��ջ������ʼ��
**
** input parameters:        None
** Returned value:          None
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern void MB_UartInit(void);


/*********************************************************************************************************
** Function name:           MB_UartChCfg
**
** Descriptions:            ����Modbus�ܵ���
**
** input parameters:        mb_ch���ӻ�������Ϣ���ݽṹָ��
** Returned value:          ���óɹ�����MB_NO_ERR(0)�������ط���ֵ��
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern uint8 MB_UartChCfg(MB_CFG *mb_ch);

/********************************************************************************************************
** Function name:           MB_UartExitCfg
**
** Descriptions:            ���øú������ͷ�Modbus�ܵ�ռ�õ���Դ��
**
** input parameters:        ch,�ͷŵĹܵ���
** Returned value:          None
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
extern void MB_UartExitCfg(uint8 ch );

/*********************************************************************************************************
** Function name:           MB_UartReceOneChar
**
** Descriptions:            ����һ���ַ�����
**                          Ҫ��:���յ�һ���ַ�����������ú�������
**
** input parameters:        ch,���յ����ݵĹܵ���
**                          ReceCharacter,���յ����ַ�
**                          err,����ֵ��ʱ�����ַ���������żЧ�����
** Returned value:          None
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern void MB_UartReceOneChar(uint8 ch,uint8 ReceCharacter,uint8 err);



/*********************************************************************************************************
** Function name:           MB_UartTmrUpdate
**
** Descriptions:            Modbusʱ�䴦������T15��T13���¼���Эջ״̬�¼���
**                          �ú�����Ҫ��500uS������һ�Ρ�
** input parameters:        None
** Returned value:          None
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
extern void MB_UartTmrUpdate(void);


/********************************************************************************************************
** Function name:           MBS_UDFCodeAdd
**
** Descriptions:            Modbus�ӻ�ջ��ʼ���û��Զ��幦�ܴ���,�ú���ʹ���˶�̬�����ڴ档
**
** input parameters:        code_ptr,�û��Զ��幦�ܴ���ṹָ��
** Returned value:          ��������Զ��幦�ܴ��뷵��0�������س������
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
extern uint8 MBS_UDFCodeAdd(SUD_FUN_CODE * code_ptr);


/********************************************************************************************************
** Function name:           MBM_UDFCodeAdd
**
** Descriptions:            Modbus����ջ��ʼ���û��Զ��幦�ܴ���,�ú���ʹ���˶�̬�����ڴ档
**
** input parameters:        request_ptr,�û��Զ��幦�ܴ���ṹָ��
** Returned value:          ��������Զ��幦�ܴ��뷵��0�������س������
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
extern uint8 MBM_UDFCodeAdd(MUD_FUN_CODE *request_ptr);




/********************************************************************************************************
** Function name:           MB_UartMServe
**
** Descriptions:            Modbus����ջ����������,����uC/OS-IIϵͳ��ʹ�á�
**
** input parameters:        *pdata���������ָ�룬��ʹ�á�
** Returned value:          None
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
extern void MB_UartMServe    (void *pdata);


/********************************************************************************************************
** Function name:           MB_UartSServe
**
** Descriptions:            Modbus�ӻ�ջ����������,����uC/OS-IIϵͳ��ʹ�á�
**
** input parameters:        *pdata���������ָ�룬��ʹ�á�
** Returned value:          None
**
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**-------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
extern void MB_UartSServe    (void *pdata);


#ifdef __cplusplus
}
#endif                                                                  /* __cplusplus                  */
#endif                                                                  /* __MODBUSUSER_H               */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
