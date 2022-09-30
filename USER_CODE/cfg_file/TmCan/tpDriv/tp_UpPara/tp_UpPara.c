/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpPara.c
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


/*********************************************************************************************************
** Function name:           sysUpgradeFlag
** Descriptions:            �������ع�������־���ɹ�����д��0x5a���������д��0xa5
** input parameters:        pucBuf: �������ݻ����ַ
**                          uiLength�������С(>=512B)
** output parameters:       none
** Returned value:          >=0:    �����ʼ���
**                          ����:   ʧ��
*********************************************************************************************************/


#include ".\tp_UpPara_cfg.h"

INT32S sysParaFlag(INT8U ucFlag)
{  
    
    INT32S  siErr;
    memset(__GucUpgradeBuf , 0xFF, __UPGRADE_PAGE_SIZE);
    __GucUpgradeBuf[0] = ucFlag;
    sysSectorPrepare (16, 16);                                          /* ����׼��						*/
    sysSectorErase (16, 16);	                                        /* ��������						*/
    sysSectorPrepare (16, 16);                                          /* ����׼��						*/						
    sysRamToFlash(__PARA_FLAG_ADDR, (INT32U)__GucUpgradeBuf, 512); 
    siErr = sysDataCompare(__PARA_FLAG_ADDR,(INT32U)__GucUpgradeBuf, 512);
    return (-siErr);
}
    /*
     *  �ⲿ����ʹ�ñ���
     */
   
    /*
     *  �ڲ�ʹ�ñ���
     */
/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpCreate (const TM_PORT_INFO *ptpiThis);
static INT32S __tpDel (const TM_PORT_INFO *ptpiThis);
static INT32S __tpRead(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
static INT32S __tpWrite (const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TM_PORT_FUNC GtpfUpPara = {
    __tpCreate,
    __tpDel,
    __tpRead,
    __tpWrite
};


BOOLEAN   __GbParaFlag;


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
    TP_UPPARA_INFO *pttiPortCase;                                       /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPPARA_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  ����ĳ�ʼ������
     */

    __GbParaFlag = FALSE;

        
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
    TP_UPPARA_INFO *pttiPortCase;                                       /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPPARA_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  �����ж�ش���
     */
    __GbParaFlag = FALSE;
    return TM_OK;    
}

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

    TP_UPPARA_INFO *pttiPortCase;                                       /*  �豸��Ϣ                    */
    
//    INT32U  __PARAM_ADDR = __PARAM_ADDR_EX0;
    pttiPortCase = (TP_UPPARA_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase; 
    
    /*
     *  ʵ�ʵ�д����
     */        

     
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
    TP_UPPARA_INFO   *pttiPortCase;                                     /*  �豸��Ϣ                    */
    INT16U              uiTmp;
    SERVICE_PARA_S *pstPara = NULL;
    pttiPortCase = (TP_UPPARA_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase; 
    /*
     *  ������ͨ������
     */
    if (((__GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07] != ucChanle) && 
        (__GucTmDrivChn[(__PORT_DEF_RIGHT >> 3) & 0x07][__PORT_DEF_RIGHT & 0x07] != ucChanle))||
        (__GuiChanle != ucChanle)) {
        return 0;
    }
    /*
     *  �����ж�
     */
    if ((usLen > 0x400) || (usLen < 256)) {                                                
        return 0;
    } 
    /*
     *  �ܺż���
     */
    pstPara = (SERVICE_PARA_S*)pvData;
    if(pstPara->bAddrDir & 0x01) {                                  /*  �������                    */
        if (__GucTmDrivChn[0][__PORT_DEF_LEFT] == ucChanle) {
            pstPara->u8ShldNo -= 1;   
        } else {
            pstPara->u8ShldNo += 1;
        }    
    } else {                                                            /*  �ұ�����                    */
        if (__GucTmDrivChn[0][__PORT_DEF_LEFT] == ucChanle) {
            pstPara->u8ShldNo += 1;    
        } else {
            pstPara->u8ShldNo -= 1;   
        }     
    }

    if (1 == write_eeprom(0x00, pvData, usLen)) {
        if (0xBB != ioInportByte(__PARA_FLAG_ADDR)) {                   /*  ����д��ɹ�                */
            OSSchedLock();
            sysIrqDisable();
            sysParaFlag(0xBB);
            sysIrqEnable();
            OSSchedUnlock();
        }
        GUI_Printf(__GucXPoint, __GucYPoint, 1, "����д��ɹ���  ");
        __GbParaFlag = TRUE;
        return usLen;
    } else {                                                            /*  ����д��ʧ��                */
        GUI_Printf(__GucXPoint, __GucYPoint, 1, "����д��ʧ�ܣ�  ");
        __GbParaFlag = FALSE;
        return usLen;
    } 
}

/*********************************************************************************************************
  DEL FILE
*********************************************************************************************************/
