/****************************************Copyright (c)**************************************************
**
**
**--------------File Info-------------------------------------------------------------------------------
** File name:           Driver2200.h
** Last modified Date:  2012-12-31
** Last Version:        1.0
** Descriptions:        �������������Ϣ
**------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2012-12-31
** Version:             1.00
** Descriptions:        The original version
**------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:        
********************************************************************************************************/

#ifndef __DRIVER2200_H
#define __DRIVER2200_H

/*********************************************************************************************************
  ����������Ϣͷ�ļ�
*********************************************************************************************************/
#include "..\DrvLib\GPIO\GPIO.h"
#include "..\DrvLib\Uart\uart.h"
#include "..\DrvLib\I2C\I2C.h"
#include "..\DrvLib\Timer\Timer.h"
#include "..\DrvLib\SPI\SPI.h"         

#include "..\DrvLib\PWM\PWM.h"
#include "..\DrvLib\ADC\ADC.h"

#include "..\DrvLib\EINT\EINT.h"
#include "..\DrvLib\RTC\RTC.h"
#include "..\DrvLib\WDT\WDT.h"
#include "..\DrvLib\PLL\PLL.h"
#include "..\DrvLib\Power\Power.h"
#include "..\DrvLib\CAN\CAN.h" 

#include "..\DrvLib\CAN\FullCANAF.h" 
#include "..\DrvLib\EMC\EMC.h"

/*********************************************************************************************************
  ����������HOOKS�ṹ�嶨��
*********************************************************************************************************/
struct driver_hooks{
    void (*pRS485Dir_Out)   (INT32U ulPinCtl);                          /*   RS-485������Ƶ��õĺ���   */
                                                                        /*   ulPinCtl: �������ű���     */
    void (*pRS485Dir_In)    (INT32U ulPinCtl);                          /*   RS-485������Ƶ��õĺ���   */
                                                                        /*   ulPinCtl: �������ű���     */                                                                    

    void (*pSpiCsEnable)    (INT32U ulPinCtl);                          /*   SPIƬѡʹ�ܵ��õĺ���      */
                                                                        /*   ulPinCtl: �������ű���     */
    void (*pSpiCsDisable)   (INT32U ulPinCtl);                          /*   SPIƬѡ���ܵ��õĺ���      */
                                                                        /*   ulPinCtl: �������ű���     */  
    void*(*pSysHeapMalloc)  (INT32U ulSize);                            /*   �ڴ滺����������õĺ���   */
                                                                        /*   ulSize: �����ֽڴ�С       */
    void (*pSysHeapFree)    (void *pvPrt);                              /*   �ڴ滺�����ͷŵ��õĺ���   */
                                                                        /*   pvPrt: ����ָ��            */    
  
    void (*pUartVicEnable)  (void);                                     /*   Uart�ж�ʹ�ܵ��õĺ���     */
    void (*pUartVicDisable) (void);                                     /*   Uart�жϽ��ܵ��õĺ���     */
    
    void (*pSpiVicEnable)   (void);                                     /*   Spi�ж�ʹ�ܵ��õĺ���      */
    void (*pSpiVicDisable)  (void);                                     /*   Spi�жϽ��ܵ��õĺ���      */
    
    void (*pI2cVicEnable)   (void);                                     /*   I2c�ж�ʹ�ܵ��õĺ���      */
    void (*pI2cVicDisable)  (void);                                     /*   I2c�жϽ��ܵ��õĺ���      */
    
    void (*pWdtVicEnable)   (void);                                     /*   Wdt�ж�ʹ�ܵ��õĺ���      */
    void (*pWdtVicDisable)  (void);                                     /*   Wdt�жϽ��ܵ��õĺ���      */

    void (*pCanVicEnable)   (void);                                     /*   Can�ж�ʹ�ܵ��õĺ���      */
    void (*pCanVicDisable)  (void);                                     /*   Can�жϽ��ܵ��õĺ���      */

    void (*pAdcVicEnable)   (void);                                     /*   Adc�ж�ʹ�ܵ��õĺ���      */
    void (*pAdcVicDisable)  (void);                                     /*   Adc�жϽ��ܵ��õĺ���      */
    
    void (*pRtcVicEnable)   (void);                                     /*   Rtc�ж�ʹ�ܵ��õĺ���      */
    void (*pRtcVicDisable)  (void);                                     /*   Rtc�жϽ��ܵ��õĺ���      */
    
    void (*pTimerVicEnable)   (void);                                   /*   Timer�ж�ʹ�ܵ��õĺ���    */
    void (*pTimerVicDisable)  (void);                                   /*   Timer�жϽ��ܵ��õĺ���    */
};

typedef struct driver_hooks  DRIVER_HOOKS;
typedef struct driver_hooks* PDRIVER_HOOKS;

/*********************************************************************************************************
  ���������ڲ����� �û�����ɾ��
*********************************************************************************************************/
#define OPERATE_SUCCESS     0
#define OPERATE_FAIL        0xFF
    /*
     *  ������汾��
     */
#define __uiGDriver2200_Ver 0x10081732                                  /*  V3.2�汾                   */
    /*
     *  ������HOOK����
     */
extern const DRIVER_HOOKS GdhDrvHooksTbl;
extern const DRIVER_HOOKS __GdhDrvHooks;
/*********************************************************************************************************
** Function name:           sysDriveLibVerGet
** Descriptions:            ��������汾��
** input parameters:        None
** output parameters:       None
** Returned value:          �����汾��
*********************************************************************************************************/
INT32U sysDriveLibVerGet(void);

#endif                                                                  /*  __DEVICECONFIG_H            */ 
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
