/****************************************Copyright (c)**************************************************
**
**
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           uart.h
** Last modified Date:  2013-03-15
** Last Version:        1.00
** Descriptions:        uart�����ⲿͷ����
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-03-15
** Version:             1.00
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/
#ifndef __UART_H
#define __UART_H
#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  UART �������
*********************************************************************************************************/
#define  UART0              0                                           /*  UART0 ID ��                 */
#define  UART1              1                                           /*  UART1 ID ��                 */
#define  UART2              2                                           /*  UART2 ID ��                 */
#define  UART3              3                                           /*  UART3 ID ��                 */
#define  UART4              4                                           /*  UART4 ID ��                 */
#define  UART5              5                                           /*  UART5 ID ��                 */
/*********************************************************************************************************
    UART�豸�ж�ͨ����
*********************************************************************************************************/
#define  UART0_IRQ_CHN      6                                           /*  UART0�ж�ͨ����             */
#define  UART1_IRQ_CHN      7                                           /*  UART1�ж�ͨ����             */

/*********************************************************************************************************
  UART ģʽ��������
*********************************************************************************************************/
#define  SET_BAUDRATE       0                                           /*  ���ڲ�����                  */
#define  SET_CTRLMODE       1                                           /*  ����ģʽ                    */
#define  SET_TIMEOUT        2                                           /*  ��ʱ����                    */
#define  SET_MODEM          3                                           /*  UART1 Modem����             */
#define  SET_RS485          4                                           /*  RS485����                   */
#define  SET_FLOWTYPE       5                                           /*  ��������������              */
#define  SET_SPRINGCH       6                                           /*  �������ô����ַ�            */
#define  SET_SPRINGPT       7                                           /*  �������ý����жϴ�����      */

/*********************************************************************************************************
  �û��ɵ��õĹ��Ӻ���
*********************************************************************************************************/
struct uartHooks {
    /*
     *  ���Ӻ�����
     */
    void        (*pModemState)(void *pRsv, INT8U ucMsr);                /*  Modem״̬�仯���õĺ���     */
                                                                        /*  pRsv: ����,�û���Ҫ����     */
                                                                        /*  ucMsr:   MSR�Ĵ�����ֵ      */

    void        (*pSendEnd)(void *pRsv);                                /*  ���ݰ����ͽ������õĺ���    */
                                                                        /*  pRsv: ����,�û���Ҫ����     */

    void        (*pReceive)(void *pRsv,INT8U ucRbr, INT8U ucLsr);       /*  ���յ��ַ����õĺ���        */
                                                                        /*  pRsv:  ����,�û���Ҫ����    */
                                                                        /*  ucRbr: ���յ����ַ�         */
                                                                        
    void        (*pLineErr)(void *pRsv, INT8U ucLcr);
                                                                        /*  ��·״̬�����жϵ��õĺ���  */
                                                                        /*  pRsv: ����,�û���Ҫ����     */
                                                                        /*  ucLcr: ��·״̬�Ĵ��������� */

    /*
     *  ��������
     */
    char        cSpringChar;                                            /*  �������ַ�                  */
    void      (*pSpringFunction)(void *pRsv);                           /*  ���յ��������ַ�����õĺ���*/
                                                                        /*  pRsv: ����,�û���Ҫ����     */
};
typedef struct uartHooks    UART_HOOKS;
typedef struct uartHooks*   PUART_HOOKS;


/*********************************************************************************************************  
** Function name:           uartInit  
** Descriptions:            ���ڳ�ʼ�����ж�����  
** input parameters:        uiId            ���豸��  
**                          pcArg           �ַ���ָ��  
**                          pRsv            ��������  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS �����ɹ�  
**                          -OPERATE_FAIL   ����ʧ��  
** Example:                 char pcArg[]="BaudRate=9600,DataBits=8,StopBits=1,Parity=NONE,RtsControl=NONE";   
**                          uartInit(0,pcArg,0);   
*********************************************************************************************************/ 
extern INT32S uartInit(INT32U ulId, char *pucArg, void *pvRsv);

/*********************************************************************************************************  
** Function name:           uartSetMode  
** Descriptions:            ���ô��ڵĲ���  
** input parameters:        uiId            ���豸��  
**                          uiCmd           ���������
**                          SET_BAUDRATE    ���ڲ�����
**                          SET_CTRLMODE    ����ģʽ
**                          SET_TIMEOUT     ��ʱ����
**                          SET_MODEM       UART1 Modem����
**                          SET_RS485       RS485����
**                          SET_FLOWTYPE    ��������������
**                          SET_SPRINGCH    �������ô����ַ�
**                          SET_SPRINGPT    �������ý����жϴ�����
**                          pcArg           �ַ���ָ��  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS �����ɹ�  
**                          -OPERATE_FAIL   ����ʧ��      
** Examples:                char pUart[]="DataBits=8 StopBits=1 Parity=NONE RtsControl=NONE";  
**                              
*********************************************************************************************************/   
extern INT32S uartSetMode(INT32U ulId, INT32U ulCmd, char *pucArg);

/*********************************************************************************************************  
** Function name:           uartGetState  
** Descriptions:            ��ȡ��ǰ���ڵĲ���  
** input parameters:        uiId            ���豸��  
**                          pcArg           �ַ���ָ��  
** Output parameters:       pcArg           ����ַ�������  
** Returned value:          OPERATE_SUCCESS �����ɹ�  
**                          -OPERATE_FAIL   ����ʧ��  
*********************************************************************************************************/   
extern INT32S uartGetState (INT32U uiId, char * pcArg);

/*********************************************************************************************************  
** Function name:           rs485Input  
** Descriptions:            rs485�ý���״̬ 
** input parameters:        uiId            ���豸��  
**                          
** Output parameters:       
** Returned value:          OPERATE_SUCCESS �����ɹ�  
**                          -OPERATE_FAIL   ����ʧ��  
*********************************************************************************************************/   
extern INT32S rs485Input(INT32U uiId);

/*********************************************************************************************************  
** Function name:           rs485Output  
** Descriptions:            rs485�÷���״̬ 
** input parameters:        uiId            ���豸��  
**                          
** Output parameters:       
** Returned value:          OPERATE_SUCCESS �����ɹ�  
**                          -OPERATE_FAIL   ����ʧ��  
*********************************************************************************************************/   
extern INT32S rs485Output(INT32U uiId);

   
/*********************************************************************************************************  
** Function name:           uartFifoFlush  
** Descriptions:            ��ս��ջ���Queue����  
** input parameters:        uiId            UART���豸��  
**                          uiWhichFifo     TX_FIFO-���Ͷ���
**                                          RX_FIFO-���ն���  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS �����ɹ�  
**                          -OPERATE_FAIL   ����ʧ��  
*********************************************************************************************************/   
extern INT32S uartFifoFlush (INT32U uiId, INT32U uiWhichFifo);

/*********************************************************************************************************  
** Function name:           uartRead  
** Descriptions:            �Ӵ����豸��ȡ����  
** input parameters:        uiId            ���豸��
**                          uiSize          ��ȡ�����ݸ���  
**                           
** Output parameters:       pucBuf          ���淵�����ݵ��ַ���ָ���ַ    
** Returned value:          ʵ�ʶ�ȡ�����ݸ���  
*********************************************************************************************************/   
extern INT32S uartRead (INT32U uiId, INT8U *pucBuf, INT32U uiSize);

/*********************************************************************************************************  
** Function name:           uartWrite  
** Descriptions:            �򴮿��豸д����  
** input parameters:        uiId            ���豸��  
**                          pucBuf          ������ݵ��ַ���ָ���ַ  
**                          uiSize          һ��д������ݸ���  
**                            
** Output parameters:       NONE  
** Returned value:          ʵ�ʷ��͵����ݸ���  
*********************************************************************************************************/
extern INT32S uartWrite(INT32U ulId, INT8U *pucBuf, INT32U ulSize); 
                           
/*********************************************************************************************************  
** Function name:           uartDirectWrite  
** Descriptions:            �򴮿��豸ֱ�ӷ�������  
** input parameters:        uiId            ���豸��  
**                          pucBuf          �������ݵĻ���
**                          uiSize          �������ݸ���                              
** Output parameters:       NONE  
** Returned value:          ʵ�ʷ��͵����ݸ���
*********************************************************************************************************/  
extern INT32S uartDirectWrite(INT32U ulId, INT8U *pucBuf, INT32U ulSize);

/*********************************************************************************************************  
** Function name:           uartIsr  
** Descriptions:            UART�жϷ������  
** input parameters:        uiId            ���豸��  
** Output parameters:       NONE  
** Returned value:          ��  
*********************************************************************************************************/  
extern void uartIsr(INT32U ulId);

#ifdef __cplusplus
    }
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __UART_H                    */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
