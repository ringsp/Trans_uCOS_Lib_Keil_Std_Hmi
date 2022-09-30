/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn                                   
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpUartDrv.h
** Latest modified Date:    2019-01-25
** Latest Version:          1.0
** Descriptions:            UART ���������ӿ��ļ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2019-01-25
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#ifndef __TPUART_DRV_H
#define __TPUART_DRV_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  ������Ϣ
*********************************************************************************************************/
#define       __UART_CHNL_BASE          2                               /*  UARTͨ����ʶ                */
#define       __TP_UART1              __UART_CHNL_BASE + UART1          /*  UART1ͨ����ʶ               */
#define       __TP_UART2              __UART_CHNL_BASE + UART2          /*  UART2ͨ����ʶ               */
#define       __TP_UART3              __UART_CHNL_BASE + UART3          /*  UART3ͨ����ʶ               */
#define       __TP_UART4              __UART_CHNL_BASE + UART4          /*  UART4ͨ����ʶ               */
#define       __TP_UART5              __UART_CHNL_BASE + UART5          /*  UART5ͨ����ʶ               */
#define       __TP_UART6              __UART_CHNL_BASE + UART6          /*  UART6ͨ����ʶ               */
#define       __TP_UART7              __UART_CHNL_BASE + UART7          /*  UART7ͨ����ʶ               */
#define       __TP_UART8              __UART_CHNL_BASE + UART8          /*  UART8ͨ����ʶ               */

    
#define     __TPUART_REMOTE_TIMEOUT     1000                             /*  Զ�̷��ʳ�ʱʱ��(ms)        */

    /*
     *  �ڲ�����ṹ
     */
struct __serial_frame_del {
    INT8U       ucXor;
    TP_PACKET  *ptpPacket;  
    INT16U      usLen;
    INT16U      usLenTmep;
    INT16U      usBufLenRd;
    INT32U      ulId;
    INT8U       ucState;
};
typedef struct __serial_frame_del   __SERIAL_FRAME_DEL;
typedef struct __serial_frame_del  *__PSERIAL_FRAME_DEL;


/*********************************************************************************************************
  �ӿں����б�
*********************************************************************************************************/

extern const TP_DRV_INFO  GtdiUart1DrvInfo;
extern const TP_DRV_INFO  GtdiUart2DrvInfo;
extern const TP_DRV_INFO  GtdiUart3DrvInfo;
extern const TP_DRV_INFO  GtdiUart4DrvInfo;
extern const TP_DRV_INFO  GtdiUart5DrvInfo;
extern const TP_DRV_INFO  GtdiUart6DrvInfo;
extern const TP_DRV_INFO  GtdiUart7DrvInfo;
extern const TP_DRV_INFO  GtdiUart8DrvInfo;
#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TPUART_DRV_H              */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

