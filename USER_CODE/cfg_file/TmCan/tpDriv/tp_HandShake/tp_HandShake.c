/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpHandShake.c
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
#include ".\tp_HandShake_cfg.h"

    /*
     *  �ⲿ����ʹ�ñ���
     */
   
    /*
     *  �ڲ�ʹ�ñ���
     */
/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpRead(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
static INT32S __tpWrite (const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TM_PORT_FUNC GtpfHandShake = {
    NULL,
    NULL,
    __tpRead,
    __tpWrite
};
/*********************************************************************************************************
** Function name:           __tpRead
** Descriptions:            ���˿ڡ�
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

static INT32S __tpRead (const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData)
{
    TP_HANDSHAKE_INFO *pttiPortCase;                               /*  �豸��Ϣ                    */
    INT32U   uiDlmCodeId[3];
    pttiPortCase = (TP_HANDSHAKE_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    sysSoftParaGet(uiDlmCodeId);
     
    /*
     *  ʵ�ʵ�д����
     */        
    memcpy(pvData, (INT8U*)&uiDlmCodeId, usLen); 
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
    TP_HANDSHAKE_INFO *pttiPortCase;                                    /*  �豸��Ϣ                    */
    INT8U   ucKey[4] = {0xaa,0x11,0x55,0x22};                           /*  ��λ��Կ                    */ 
     
    pttiPortCase = (TP_HANDSHAKE_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    
    /*
     *  ʵ�ʵ�д����
     */ 
    
    if (!memcmp(ucKey, pvData, 4)) {                                    /*  ��λ                        */         
        OSTaskDelReq(TASK0_PRIO);
        return usLen;
    }
     
    if ((usLen <= 8) && (ioInportLong(__EN_UPGRADE_FLAG0) != 0x87654321)) {
        memcpy((void *)__EN_UPGRADE_FLAG0, pvData, usLen);
        tpApplyUsrInit();
    }
    return usLen;
}

/*********************************************************************************************************
  DEL FILE
*********************************************************************************************************/
