/****************************************Copyright (c)****************************************************
**                              
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           wdt.h
** Last modified Date:  2013-03-15
** Last Version:        1.0
** Descriptions:        wdt驱动外部头文件
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-03-15
** Version:             V1.0
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/
#ifndef _WDT_H_
#define _WDT_H_

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  WDT 相关索引
*********************************************************************************************************/
#define WDT0                0                                           /*  WDT的ID号                   */

#define WDT0_IRQ_CHN        0                                           /*  WDT中断通道号               */

/*********************************************************************************************************  
** Function name:           wdtInit  
** Descriptions:            初始化看门狗,初始化完毕后将立即运行  
** Input parameters:        uiId            器件子设备号  
**                          pcArg           参数输入字符串
**                          pRsv            保留参数  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS 操作失败  
**                          -OPERATE_FAIL   操作成功   
** Example:                 char cWdtarg[ ] = " WdtTimerOut=10 ";   
**                          WdtInit( 0, cWdtarg, NULL );                            
**                                        
*********************************************************************************************************/
extern INT32S wdtInit(INT32U ulId, char *pucArg, void *pvRsv);

/*********************************************************************************************************  
** Function name:           wdtFeed  
** Descriptions:            喂狗  
** Input parameters:        uiId            器件子设备号,只能输入0,因为看门狗只有一个  
**                          pRsv            保留参数  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS 操作失败  
**                          -OPERATE_FAIL   操作成功                           
*********************************************************************************************************/ 
extern INT32S wdtFeed(INT32U ulId);


/*********************************************************************************************************
** Function name:       wdtIsr
** Descriptions:        看门狗中断响应函数
** input parameters:    ulId                子设备号
** output parameters:   None
** Returned value:      None
*********************************************************************************************************/
extern void wdtIsr(INT32U ulId);

#ifdef __cplusplus 
    }
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  _WDT_H_                     */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
