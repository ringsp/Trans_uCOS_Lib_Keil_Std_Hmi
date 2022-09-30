/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn  
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               SeverEn.c
** Latest modified Date:    2022-09-18
** Latest Version:          1.0
** Descriptions:            �������ʹ�����ò˵���
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
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
  �ⲿ����
*********************************************************************************************************/


/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __menuItemCreate(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemDel(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemOnKey(MENU_ITEM_INFO *pmiibThis, INT32U uiKeyCode);
static INT32S __menuItemParamFmt(MENU_ITEM_INFO *pmiiThis, void *pvRsv);

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/


/*********************************************************************************************************
  �ڲ�ʹ�ñ���
*********************************************************************************************************/
const MENU_ITEM_FUNC GmifServerEn = {
    __menuItemCreate,
    __menuItemDel,
    __menuItemOnKey,
    __menuItemParamFmt
};

static char * __SscEnStr[2] = {"��", "��"};
/*********************************************************************************************************
** Function name:           menuItemCreate
** Descriptions:            �����˵���
** input parameters:        pmiiThis    �˵�����Ϣ
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __menuItemCreate (MENU_ITEM_INFO *pmiiThis)
{
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
    pmiiThis->pvPara = (void *)&Gdp.ucDir;
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           menuItemDel
** Descriptions:            ɾ���˵���
** input parameters:        pmpiThis    �˵�����Ϣ
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __menuItemDel (MENU_ITEM_INFO *pmiiThis)
{
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
    return SYS_OK;    
}

/*********************************************************************************************************
** Function name:           menuItemOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmiiThis    �˵�����Ϣ
**                          usLen       ���������ݳ���
**                          pvData      ����������ָ��
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�sys_if.h
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
    *  ����û�����        
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
            if (1) {                         /*  ��������ʧ��                */
                //��ʾ�����������
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
** Descriptions:            �˵�����ʾ����
** input parameters:        pmiiThis        �˵�����Ϣ
**                          usFocus         ���������ݳ���
**                          pvRsv           ����������ָ��
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S __menuItemParamFmt(MENU_ITEM_INFO *pmiiThis, void *pvRsv)
{
    INT32U ucPressureEn;
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
    
    /*
     *  ��������
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
  �������ʧ�ܲ˵����
*********************************************************************************************************/
const MENU_ITEM_INFO_BASE __GmiibServerEn = {                           /*  �˵�����Ϣ                  */
    "�������     ",
    (MENU_ITEM_FUNC *)&GmifServerEn,
    0x0106,
    (1 << 7) | (PARA_SCOPE_GLOBAL << 4) | PARA_TYPE_VALUE
};


/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
