/****************************************Copyright (c)****************************************************
**                              
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           RTC.h
** Last modified Date:  2013-08-22  
** Last Version:        V1.0       
** Descriptions:        LPC2200 RTC驱动
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-08-22
** Version:             V1.0
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/
#ifndef _RTC_H_
#define _RTC_H_
#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                */

/*********************************************************************************************************
  RTC 相关索引
*********************************************************************************************************/
#define  RTC0              0

/*********************************************************************************************************
  RTC 中断通道号
*********************************************************************************************************/
#define  RTC0_IRQ_CHN      13

/*********************************************************************************************************
  RTC 模式配置命令
*********************************************************************************************************/
#define  SET_TIME          0                                            /*  设置时间值宏定义            */
#define  SET_ALARM         1                                            /*  报警中断宏定义              */
#define  SET_SECINT        2                                            /*  秒中断宏定义                */
#define  SET_MININT        3                                            /*  分钟中断宏定义              */
#define  SET_HOURINT       4                                            /*  小时中断宏定义              */
#define  SET_DOMINT        5                                            /*  日期（月）中断宏定义        */
#define  SET_DOWINT        6                                            /*  星期中断宏定义              */
#define  SET_MONINT        7                                            /*  月中断宏定义                */
#define  SET_YEARINT       8                                            /*  年中断宏定义                */

/*********************************************************************************************************
  RTC 读时间命令
*********************************************************************************************************/
#define  READ_TIME         0                                            /*  读取当前时间值宏定义        */
#define  READ_ALARM        1                                            /*  读取报警时间值宏定义        */

/*********************************************************************************************************
  RTC 时间结构体
*********************************************************************************************************/
struct rtc_time
{
    INT16U usYear;                                                      /*  当前年                      */
    INT8U  ucMonth;                                                     /*  当前月                      */
    INT8U  ucDay;                                                       /*  在月里面几号                */
    INT8U  ucWeek;                                                      /*  星期几（0-6）               */
    INT8U  ucHour;                                                      /*  小时                        */
    INT8U  ucMinute;                                                    /*  分钟                        */
    INT8U  ucSecond;                                                    /*  秒                          */
} ;
typedef struct rtc_time RTC_TIME;
/*********************************************************************************************************  
** Function name:           rtcInit  
** Descriptions:            RTC初始化函数 
** Input parameters:        uiId            rtc器件号
**                          pcArg           格式化字符串参数指针 
**                          pRsv            保留参数                                       
** 
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS 操作成功  
**                          -OPERATE_FAIL   操作失败  
*********************************************************************************************************/   
extern INT32S rtcInit (INT32U uiId, char *pcArg, void *pRsv);

/*********************************************************************************************************  
** Function name:           rtcSetMode  
** Descriptions:            RTC设置模式参数，能够设置增量中断，报警中断，和清除中断  
** Input parameters:        uiId                    器件编号，默认为0  
**                          uiMode                  要设置参数的类型，类型种类如下  
**                                  SET_TIME        设置时间
**                                  SET_SECINT      秒增量中断  
**                                  SET_MININT      分钟增量中断  
**                                  SET_HOURINT     小时增量中断  
**                                  SET_DOMINT      月里面天数增量中断  
**                                  SET_DOWINT      星期值增量中断  
**                                  SET_MONINT      月值增量中断  
**                                  SET_YEARINT     年值增量中断   
**                                  SET_ALARM       报警中断   
**                          pcArg                   当上面的uiArgMode为RTC_MODE_ALARM时，传入字符串参数指针，  
**                                                  用来设置报警值，否则可传入空指针。  
**                                                  传入的参数格式为关键字0=值0[空格]关键字1=值1[空格].....  
**                                         关键字:  Year  范围0-4095  
**                                                  Month 月，范围1-12  
**                                                  Day   日期（月），1-31  
**                                                  Hour  小时，0-23  
**                                                  Min   分钟，0-59  
**                                                  Sec   秒  ，0-59  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS         操作成功   
**                          -OPERATE_FAIL           操作失败
**                          
*********************************************************************************************************/   
extern INT32S rtcSetMode (INT32U uiId, INT32U uiMode, char  *pcArg);

/*********************************************************************************************************  
** Function name:           rtcTimeRead  
** Descriptions:            RTC获取时间函数  
** Input parameters:        uiId                    器件编号 
**                          uiCmd                   读取命令码
**                                  READ_TIME       读取rtc当前时间
**                                  READ_ALARM      读取报警时间 
** Output parameters:       prt                     读取的时间保存指针 
**                                                  例如输出时间"2007-6-23 3 12:35:40\r\n"  
** Returned value:          OPERATE_SUCCESS         操作成功
**                          -OPERATE_FAIL           操作成功
**                          
*********************************************************************************************************/
extern INT32S rtcTimeRead(INT32U ulId, RTC_TIME *prtcTime, INT32U ulCmd);

/*********************************************************************************************************
** Function name:           rtcIsr
** Descriptions:            RTC中断服务程序
** Input parameters:        uiId            rtc器件号
** Output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void rtcIsr(INT32U ulId);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  _RTC_H_                     */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
