/****************************************Copyright (c)****************************************************
**                          Beijing Hengfengli Technology CO.,LTD.
**                                      
**                                 http://www.hengfengli.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpUsr.c
** Latest modified Date:    2018-11-25
** Latest Version:          1.0
** Descriptions:            AnyPort协议栈用户接口文件
**
**--------------------------------------------------------------------------------------------------------
** Created by:              超人力霸王
** Created date:            2018-11-25
** Version:                 1.0
** Descriptions:            The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#include "..\USER_CODE\cfg_file\config.h"

/*********************************************************************************************************
** Function name:           tpUsrInit
** Descriptions:            AnyPort协议栈用户层初始化
** input parameters:        none
** output parameters:       none
** Returned value:          none
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
void tpUsrInit (void)
{
 
    OSTimeTickHookSet(tpTick);
    /*
     *  添加功能端口取驱动
     */     
    tpKeyInit();                                                        /*  按键端口加载                */
 
    /*
     *  添加通讯驱动
     */
    tpDrvsInit();   
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

