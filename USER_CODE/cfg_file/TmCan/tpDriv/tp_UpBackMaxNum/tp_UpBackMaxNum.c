/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpBackMaxNum.c
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            �˿����������ļ�
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
#include ".\tp_UpBackMaxNum_cfg.h"

    /*
     *  �ⲿ����ʹ�ñ���
     */
extern INT32U  __GuiIndex;
extern INT8U   __GucUpgradeBuf[];

extern void    (*__GpsysSoftParaGet)(INT32U*);
extern INT32S  (*__GpsysUpgradeBegin)(INT8U*, INT32U);
extern INT32S  (*__GpsysUpgradeDataWrite)(unsigned int);
extern INT32S  (*__GpsysUpgradeEnd)(void);   

   
    /*
     *  �ڲ�ʹ�ñ���
     */
static  INT8U   __SucUpBackMaxNum[3];
     
/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpCreate(const TM_PORT_INFO *ptpiThis);
static INT32S __tpDel(const TM_PORT_INFO *ptpiThis);
static INT32S __tpRead(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
static INT32S __tpWrite(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TM_PORT_FUNC GtpfUpBackMaxNum = {
    __tpCreate,
    __tpDel,
    __tpRead,
    __tpWrite
};

/*********************************************************************************************************
** Function name:           __tpCreate
** Descriptions:            �����˿�
** input parameters:        ptpiThis: �˿���Ϣ
** output parameters:       none
** Returned value:          TM_OK :  �ɹ�
**                          ����:    ����,����ֵ�ο�tmcan.h
** Created by:              
** Created Date:            2014-08-25
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
static INT32S __tpCreate (const TM_PORT_INFO *ptpiThis)
{
    TP_UPBACK_MAXNUM_INFO *pttiPortCase;                             /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPBACK_MAXNUM_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  ����ĳ�ʼ������
     */
    __SucUpBackMaxNum[0] = 1;
    __SucUpBackMaxNum[1] = 1; 
    __SucUpBackMaxNum[2] = 1;  
    return TM_OK;
}
/*********************************************************************************************************
** Function name:           __tpDel
** Descriptions:            ɾ���˿�
** input parameters:        ptpiThis:  �˿���Ϣ
** output parameters:       none
** Returned value:          TM_OK :  �ɹ�
**                          ����:    ����,����ֵ�ο�tmcan.h
** Created by:              
** Created Date:            2014-08-25
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
static INT32S __tpDel (const TM_PORT_INFO *ptpiThis)
{
    TP_UPBACK_MAXNUM_INFO *pttiPortCase;                             /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPBACK_MAXNUM_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  �����ж�ش���
     */
    __SucUpBackMaxNum[0] = 1;
    __SucUpBackMaxNum[1] = 1; 
    __SucUpBackMaxNum[2] = 1;   
    return TM_OK;    
}

/*********************************************************************************************************
** Function name:           __tpRead
** Descriptions:            ���˿�
** input parameters:        ptpiThis: �˿���Ϣ
**                          usLen:    �����ݸ���
** output parameters:       pvData:   ���ݻ�����
** Returned value:          >=0 :     ������Ŀ
** Created by:              
** Created Date:            2014-08-25
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
static INT32S __tpRead (const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData)
{
    TP_UPBACK_MAXNUM_INFO *pttiPortCase;                             /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPBACK_MAXNUM_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    /*
     *  ʵ�ʵĶ�����
     */ 

    memcpy(pvData, __SucUpBackMaxNum, usLen); 
    return usLen;
}

/*********************************************************************************************************
** Function name:           __tpWrite
** Descriptions:            д�˿ڡ�
** input parameters:        ptpiThis: �˿���Ϣ
**                          usLen:    д���ݸ���
**                          pvData:   ���ݻ�����
** output parameters:       none
** Returned value:          >=0 :     ������Ŀ
** Created by:              
** Created Date:            2014-08-25
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

static INT32S __tpWrite (const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData)
{
    TP_UPBACK_MAXNUM_INFO *pttiPortCase;                             /*  �豸��Ϣ                    */
    INT32S  siErr;
     
    pttiPortCase = (TP_UPBACK_MAXNUM_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    
    /*
     *  ʵ�ʵ�д����
     */        
    if (__GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07] == ucChanle) {
        __SucUpBackMaxNum[0] = ((INT8U*)pvData)[0];
    } else if (__GucTmDrivChn[(__PORT_DEF_RIGHT >> 3) & 0x07][__PORT_DEF_RIGHT & 0x07] == ucChanle) {
        __SucUpBackMaxNum[1] = ((INT8U*)pvData)[0];
    } else if (1 == usLen){
        __SucUpBackMaxNum[2] = ((INT8U*)pvData)[0];
    } else if (usLen < 4){
        memcpy(__SucUpBackMaxNum, pvData, usLen);
    }
    return usLen;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
