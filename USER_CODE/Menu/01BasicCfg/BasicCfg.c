/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn  
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               BasicCfg.c
** Latest modified Date:    2022-09-17
** Latest Version:          1.0
** Descriptions:            �������ò˵�ҳ  
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2022-09-17
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
#include    ".\01MinNo\MinNo.h"
#include    ".\02MaxNo\MaxNo.h"
#include    ".\03MasterTime\MasterTime.h"
#include    ".\04AddrDir\AddrDir.h"
#include    ".\05ShieldNo\ShieldNo.h"
#include    ".\06ServerEn\ServerEn.h"
#include    ".\07IrUploadEn\IrUploadEn.h"
#include    ".\08IrUploadTime\IrUploadTime.h"
#include    ".\09OpUploadEn\OpUploadEn.h"
#include    ".\10NetChkTime\NetChkTime.h"
#include    ".\11GateWayEn\GateWayEn.h"
#include    ".\12GateWayDir\GatewayDir.h"
#include    ".\13StartNo\StartNo.h"
#include    ".\14ScreenSave\ScreenSave.h"
#include    ".\15SnrUploadTime\SnrUploadTime.h"
#include    ".\16Lightness\Lightness.h"
#include    ".\17SwVer\SwVer.h"
/*********************************************************************************************************
  �ⲿ����
*********************************************************************************************************/


/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __menuItemCreate(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemDel(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemOnKey(MENU_ITEM_INFO *pmiibThis, INT16U usLen, void *pvData);
//static INT32S __menuItemParamFmt(MENU_ITEM_INFO *pmiiThis, void *pvRsv);

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/


/*********************************************************************************************************
  �ڲ�ʹ�ñ���
*********************************************************************************************************/
const MENU_ITEM_FUNC GmifBasic = {
    __menuItemCreate,
    __menuItemDel,
    __menuItemOnKey,
    NULL
};
/*********************************************************************************************************
** Function name:           menuItemCreate
** Descriptions:            �����˵�ҳ
** input parameters:        pmiiThis    �˵�ҳ��Ϣ
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __menuItemCreate (MENU_ITEM_INFO *pmiiThis)
{
    INT32S      siErr = 0;
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
     
    siErr = miAdd(pmiiThis->pmiib, (void *)&__GmiibMinNo);
    siErr+= miAdd(pmiiThis->pmiib, (void *)&__GmiibMaxNo);
    siErr+= miAdd(pmiiThis->pmiib, (void *)&__GmiibMasterTime);
    siErr+= miAdd(pmiiThis->pmiib, (void *)&__GmiibShieldNo);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibServerEn);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibIrUploadEn);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibIrUploadTime);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibOpUploadEn);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibNetChkTime);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibGatewayEn);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibGatewayDir);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibStartNo);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibScreenSave);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibSnrUploadTime);
    siErr+= miAdd(pmiiThis->pmiib, &__GmiibSwVer);
    return siErr;
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
** Function name:           menuItemOnKey
** Descriptions:            �˵�ҳ������Ӧ����
** input parameters:        pmiiThis    �˵�ҳ��Ϣ
**                          usLen       ���������ݳ���
**                          pvData      ����������ָ��
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __menuItemOnKey (MENU_ITEM_INFO *pmiiThis, INT16U usLen, void *pvData)
{
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
    
    return SYS_OK;
}


/*********************************************************************************************************
  ͨ�Ų������ò˵�ҳ����
*********************************************************************************************************/
static const MENU_ITEM_INFO_BASE __GmiibBasic = {                       /*  �˵�ҳ��Ϣ                  */
    "��������",
    (MENU_ITEM_FUNC *)&GmifBasic,
    0x0100
};

/*********************************************************************************************************
** Function name:           miBasicCfgInit
** Descriptions:            �����������ò˵�ҳ��ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void miBasicCfgInit(void)
{ 


    /*
     *  ��Ӳ˵�ҳ
     */
    miAdd(&__GmiibRoot, &__GmiibBasic);
}
/*********************************************************************************************************
** Function name:           miBasicCfgDel
** Descriptions:            �����������ò˵�ҳж��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void miBasicCfgDel (void)
{ 
    /*
     *  ɾ���˵�ҳ
     */
    miDel(&__GmiibBasic);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
