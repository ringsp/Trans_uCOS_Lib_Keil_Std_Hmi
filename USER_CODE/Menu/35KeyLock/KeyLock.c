/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               KeyLock.c
** Latest modified Date:    2021-12-26
** Latest Version:          1.0
** Descriptions:            ���̱����˵�ҳ  
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2021-12-26
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

#include    "..\..\main.h"   

/*********************************************************************************************************
  �ⲿ����
*********************************************************************************************************/
extern TREE_NODE      *__GptnCurMenu;                                   /*  ��ǰ�˵��ڵ�                */
extern TREE_NODE      *__GptnRootMenu;                                  /*  �˵����ڵ�                  */

/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __menuItemCreate(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemDel(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemOnKey(MENU_ITEM_INFO *pmiibThis, INT32U uiKeyCode);
//static INT32S __menuItemParamFmt(MENU_ITEM_INFO *pmiiThis, void *pvRsv);

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/


/*********************************************************************************************************
  �ڲ�ʹ�ñ���
*********************************************************************************************************/
const MENU_ITEM_FUNC GmifKeyLock = {
    __menuItemCreate,
    __menuItemDel,
    __menuItemOnKey,
    NULL
};
                                 
/*********************************************************************************************************
** Function name:           menuItemCreate
** Descriptions:            �����˵���
** input parameters:        pmiiThis    �˵�ҳ��Ϣ
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
    guiClrScr();
    guiPrintf(0, 16, 0, "%s", __GmiibLock.pcTitle); 
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           menuItemDel
** Descriptions:            ɾ���˵�ҳ
** input parameters:        pmiiThis    �˵�ҳ��Ϣ
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
** Function name:       keyShow
** Descriptions:        ���̱���ʱ�ļ�ֵ��ʾ
** input parameters:    uiKeyCode               ����ֵ
** output parameters:   None
** Returned value:      None
*********************************************************************************************************/
void keyShow(INT32U uiKeyCode)
{
    if (!uiKeyCode) {
        return;
    }
    guiClrScr();
    guiPrintf(0, 16, 0,"    ���̱���  ");
    if (uiKeyCode == JP_A) {             
        guiPrintf(0, 16 * 2, 0,"    A�ż�����  ");            
    } else if (uiKeyCode == JP_D) {
        guiPrintf(0, 16 * 2, 0,"    D�ż�����  "); 
    } else if (uiKeyCode == JP_1) {
        guiPrintf(0, 16 * 2, 0,"    1�ż�����  "); 
    } else if (uiKeyCode == JP_2) {
        guiPrintf(0, 16 * 2, 0,"    2�ż�����  "); 
    } else if (uiKeyCode == JP_3) {
        guiPrintf(0, 16 * 2, 0,"    3�ż�����  "); 
    } else if (uiKeyCode == JP_4) {
        guiPrintf(0, 16 * 2, 0,"    4�ż�����  "); 
    } else if (uiKeyCode == JP_5) {
        guiPrintf(0, 16 * 2, 0,"    5�ż�����  "); 
    } else if (uiKeyCode == JP_6) {
        guiPrintf(0, 16 * 2, 0,"    6�ż�����  "); 
    } else if (uiKeyCode == JP_7) {
        guiPrintf(0, 16 * 2, 0,"    7�ż�����  "); 
    } else if (uiKeyCode == JP_8) {
        guiPrintf(0, 16 * 2, 0,"    8�ż�����  "); 
    } else if (uiKeyCode == JP_P) {
        guiPrintf(0, 16 * 2, 0,"    P�ż�����  "); 
    } else if (uiKeyCode == JP_N) {
        guiPrintf(0, 16 * 2, 0,"    N�ż�����  "); 
    } else if (uiKeyCode == JP_9) {
        guiPrintf(0, 16 * 2, 0,"    9�ż�����  "); 
    } else if (uiKeyCode == JP_0) {
        guiPrintf(0, 16 * 2, 0,"    0�ż�����  "); 
    } else if (uiKeyCode == JP_U) {
        guiPrintf(0, 16 * 2, 0,"    U�ż�����  "); 
    } else if (uiKeyCode == JP_K) {
        guiPrintf(0, 16 * 2, 0,"    K�ż�����  "); 
    } else if (uiKeyCode == JP_M) {
        guiPrintf(0, 16 * 2, 0,"    M�ż�����  "); 
    } else if (uiKeyCode == JP_D) {
        guiPrintf(0, 16 * 2, 0,"    D�ż�����  "); 
    } else if (uiKeyCode == JP_B) {
        guiPrintf(0, 16 * 2, 0,"    B�ż�����  "); 
    } else if (uiKeyCode == JP_E) {
        guiPrintf(0, 16 * 2, 0,"    E�ż�����  "); 
    } else if (uiKeyCode == JP_L) {
        guiPrintf(0, 16 * 2, 0,"    L�ż�����  "); 
    } else if (uiKeyCode == JP_R) {
        guiPrintf(0, 16 * 2, 0,"    R�ż�����  "); 
    } else {
        //guiPrintf(0, 16 * 2, 0,"   δ֪������  "); 
    }
}

/*********************************************************************************************************
** Function name:           menuItemOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmiiThis    �˵�ҳ��Ϣ
**                          usLen       ���������ݳ���
**                          pvData      ����������ָ��
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __menuItemOnKey (MENU_ITEM_INFO *pmiiThis, INT32U uiKeyCode)
{
    static INT8U   __SucPwdIndex;
    INT32U  uiValveDat;
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
    if (uiKeyCode == JP_A) {             
        guiPrintf(0, 24, 0,"    A�ż�����  ");            
    } else if (uiKeyCode == JP_D) {
        guiPrintf(0, 24, 0,"    D�ż�����  "); 
    } else if (uiKeyCode == JP_1) {
        guiPrintf(0, 24, 0,"    1�ż�����  "); 
    } else if (uiKeyCode == JP_2) {
        guiPrintf(0, 24, 0,"    2�ż�����  "); 
    } else if (uiKeyCode == JP_3) {
        guiPrintf(0, 24, 0,"    3�ż�����  "); 
    } else if (uiKeyCode == JP_4) {
        guiPrintf(0, 24, 0,"    4�ż�����  "); 
    } else if (uiKeyCode == JP_5) {
        guiPrintf(0, 24, 0,"    5�ż�����  "); 
    } else if (uiKeyCode == JP_6) {
        guiPrintf(0, 24, 0,"    6�ż�����  "); 
    } else if (uiKeyCode == JP_7) {
        guiPrintf(0, 24, 0,"    7�ż�����  "); 
    } else if (uiKeyCode == JP_8) {
        guiPrintf(0, 24, 0,"    8�ż�����  "); 
    } else if (uiKeyCode == JP_P) {
        guiPrintf(0, 24, 0,"    P�ż�����  "); 
    } else if (uiKeyCode == JP_N) {
        guiPrintf(0, 24, 0,"    N�ż�����  "); 
    } else if (uiKeyCode == JP_9) {
        guiPrintf(0, 24, 0,"    9�ż�����  "); 
    } else if (uiKeyCode == JP_0) {
        guiPrintf(0, 24, 0,"    0�ż�����  "); 
    } else if (uiKeyCode == JP_U) {
        guiPrintf(0, 24, 0,"    U�ż�����  "); 
    } else if (uiKeyCode == JP_K) {
        guiPrintf(0, 24, 0,"    K�ż�����  "); 
    } else if (uiKeyCode == JP_M) {
        guiPrintf(0, 24, 0,"    M�ż�����  "); 
    } else if (uiKeyCode == JP_D) {
        guiPrintf(0, 24, 0,"    D�ż�����  "); 
    } else if (uiKeyCode == JP_B) {
        guiPrintf(0, 24, 0,"    B�ż�����  "); 
    } else if (uiKeyCode == JP_E) {
        guiPrintf(0, 24, 0,"    E�ż�����  "); 
    } else if (uiKeyCode == JP_L) {
        guiPrintf(0, 24, 0,"    L�ż�����  "); 
    } else if (uiKeyCode == JP_R) {
        guiPrintf(0, 24, 0,"    R�ż�����  "); 
    } else {
        ;guiPrintf(0, 24, 0,"   δ֪������  "); 
    }
    switch(__SucPwdIndex) {
        case 0:
            if (uiKeyCode == JP_R) {
                __SucPwdIndex++;
            }
        break;

        case 1:
            if (uiKeyCode == JP_E) {
                __SucPwdIndex++;
            } else if (uiKeyCode == JP_R) {
                __SucPwdIndex = 1;
            } else {
                __SucPwdIndex = 0;
            }
        break;

        case 2:
            if (uiKeyCode == JP_L) {
                //__SucPwdIndex++;
                miFlush(); 
                mainDisplay();
            } else if (uiKeyCode == JP_R) {
                __SucPwdIndex = 1;
            } else {
                __SucPwdIndex = 0;
            }
        break;

        default:
            __SucPwdIndex = 0;
        break;
    }
    return SYS_OK;
}


/*********************************************************************************************************
  ���������˵�ҳ����
*********************************************************************************************************/
const MENU_ITEM_INFO_BASE __GmiibKeyLock = {                            /*  �˵�����Ϣ                  */
    "    ���̱���    ",
    (MENU_ITEM_FUNC *)&GmifKeyLock,
    0x3500
};

/*********************************************************************************************************
** Function name:           miKeyLockInit
** Descriptions:            ���̱����˵���ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void miKeyLockInit(void)
{ 
    /*
     *  ��Ӳ˵�ҳ
     */
    miAdd(&__GmiibRoot, &__GmiibKeyLock);                                          /*  �ײ˵��ڵ�                  */
}
/*********************************************************************************************************
** Function name:           miKeyLockDel
** Descriptions:            ���������˵�ж��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void miKeyLockDel(void)
{ 
    /*
     *  ɾ���˵�ҳ
     */
    miDel(&__GmiibKeyLock);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
