/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn  
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               SeverEn.c
** Latest modified Date:    2022-09-18
** Latest Version:          1.0
** Descriptions:            监控主机使能设置菜单项
**
**--------------------------------------------------------------------------------------------------------
** Created by:              超人力霸王
** Created date:            2022-09-18
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

#include    "..\..\..\main.h"
/*********************************************************************************************************
  外部声明
*********************************************************************************************************/


/*********************************************************************************************************
  函数声明
*********************************************************************************************************/
static INT32S __menuItemCreate(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemDel(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemOnKey(MENU_ITEM_INFO *pmiibThis, INT32U uiKeyCode);
static INT32S __menuItemParamFmt(MENU_ITEM_INFO *pmiiThis, void *pvRsv);

/*********************************************************************************************************
  全局变量定义
*********************************************************************************************************/


/*********************************************************************************************************
  内部使用变量
*********************************************************************************************************/
const MENU_ITEM_FUNC GmifServerEn = {
    __menuItemCreate,
    __menuItemDel,
    __menuItemOnKey,
    __menuItemParamFmt
};

static char * __SscEnStr[2] = {"开", "关"};
/*********************************************************************************************************
** Function name:           menuItemCreate
** Descriptions:            创建菜单项
** input parameters:        pmiiThis    菜单项信息
** output parameters:       none
** Returned value:          SYS_OK      成功
**                          负数        错误,绝对值参考sys_if.h
*********************************************************************************************************/
static INT32S __menuItemCreate (MENU_ITEM_INFO *pmiiThis)
{
    pmiiThis = pmiiThis;
   /*  
    *  添加用户代码        
    *  ............
    */
    pmiiThis->pvPara = (void *)&Gdp.ucDir;
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           menuItemDel
** Descriptions:            删除菜单项
** input parameters:        pmpiThis    菜单项信息
** output parameters:       none
** Returned value:          SYS_OK      成功
**                          负数        错误,绝对值参考sys_if.h
*********************************************************************************************************/
static INT32S __menuItemDel (MENU_ITEM_INFO *pmiiThis)
{
    pmiiThis = pmiiThis;
   /*  
    *  添加用户代码        
    *  ............
    */
    return SYS_OK;    
}

/*********************************************************************************************************
** Function name:           menuItemOnKey
** Descriptions:            菜单项按键响应函数
** input parameters:        pmiiThis    菜单项信息
**                          usLen       待处理数据长度
**                          pvData      待处理数据指针
** output parameters:       none
** Returned value:          SYS_OK      成功
**                          负数        错误,绝对值参考sys_if.h
*********************************************************************************************************/
static INT32S __menuItemOnKey (MENU_ITEM_INFO *pmiiThis, INT32U uiKeyCode)
{    
    static INT8U    __SucEnFlag = 0;
    unsigned int    uiLen;    
    INT32U         *puiKeyCode;
    
    char            scParamFmt[32] = {0};
    INT32U          uiX, uiY;
    pmiiThis = pmiiThis;
   /*  
    *  添加用户代码        
    *  ............
    */
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    
    //puiKeyCode = ((INT32U *)pvData)[0];

    switch(uiKeyCode) {
        case JP_K:
        case JP_0:
            __SucEnFlag = 0;
            uiLen = strlen(pmiiThis->pmiib->pcTitle);
            guiPrintf(pmiiThis->ucX + uiLen * 8, pmiiThis->ucY, 1, "?%s", __SscEnStr[__SucEnFlag]);
        break;
        case JP_M:
        case JP_1:
            __SucEnFlag = 1;
            uiLen = strlen(pmiiThis->pmiib->pcTitle);
            guiPrintf(pmiiThis->ucX + uiLen * 8, pmiiThis->ucY, 1, "?%s", __SscEnStr[__SucEnFlag]);    
        break;
        
        case JP_B:
            if (!__GucEntered) {
                __SucEnFlag = Gdp.ucAsqStrebEn & 0x01; 
                guiPrintf(uiX, uiY, 1, "?");
                break;
            }
            if (__SucEnFlag) {
                ((INT32U *)pmiiThis->pvPara)[0] |= 1;
            } else {
                ((INT32U *)pmiiThis->pvPara)[0] &= ~1;
            }
            //GdiDevInfo.ucPressureEn[2] = __SucEnFlag;
            if (1) {                         /*  参数保存失败                */
                //提示保存参数错误
                eepromWrite(0, (INT8U *)&Gdp, sizeof(DEV_PARA));;
            } else {
 
            }
            pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
            guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
        break;
        case JP_E:
            pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
            guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
        break;
        default:
        break;
    }
    return SYS_OK;  
}
/*********************************************************************************************************
** Function name:           menuItemParamFmt
** Descriptions:            菜单项显示函数
** input parameters:        pmiiThis        菜单项信息
**                          usFocus         待处理数据长度
**                          pvRsv           待处理数据指针
** output parameters:       none
** Returned value:          SYS_OK          成功
**                          负数            错误,绝对值参考sys_if.h
*********************************************************************************************************/
INT32S __menuItemParamFmt(MENU_ITEM_INFO *pmiiThis, void *pvRsv)
{
    INT32U ucPressureEn;
    pmiiThis = pmiiThis;
   /*  
    *  添加用户代码        
    *  ............
    */
    
    /*
     *  参数过滤
     */
    if (NULL == pmiiThis) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvRsv) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pmiiThis->pvPara) {
        return (-SYS_NOT_OK);
    }        
    ucPressureEn = ((INT32U *)pmiiThis->pvPara)[0];
    sprintf(pvRsv, ":%s", __SscEnStr[ucPressureEn ? 1 : 0]);
    return SYS_OK;
}

/*********************************************************************************************************
  监控主机失能菜单项定义
*********************************************************************************************************/
const MENU_ITEM_INFO_BASE __GmiibServerEn = {                           /*  菜单项信息                  */
    "监控主机     ",
    (MENU_ITEM_FUNC *)&GmifServerEn,
    0x0106,
    (1 << 7) | (PARA_SCOPE_GLOBAL << 4) | PARA_TYPE_VALUE
};


/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
