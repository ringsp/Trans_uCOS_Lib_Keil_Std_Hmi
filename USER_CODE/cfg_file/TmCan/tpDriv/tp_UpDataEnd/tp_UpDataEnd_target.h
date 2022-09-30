/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpDataEnd_target.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            端口驱动目标板支持代码
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2014-08-25
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
#ifndef __TP_UPDATA_END_TARGET_H
#define __TP_UPDATA_END_TARGET_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */
/*********************************************************************************************************
  包含头文件
*********************************************************************************************************/
#include ".\tp_UpDataEnd_cfg.h"

/*********************************************************************************************************
** Function name:           tpUpDataEndInit
** Descriptions:            端口初始化
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void tpUpDataEndInit(void);

/*********************************************************************************************************
** Function name:           tpUpDataEndDel
** Descriptions:            端口卸载
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void tpUpDataEndDel (void);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TP_UPDATA_END_TARGET_H    */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
