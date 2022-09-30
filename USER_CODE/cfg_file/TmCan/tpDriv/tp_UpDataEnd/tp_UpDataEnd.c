/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpDataEnd.c
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
#include ".\tp_UpDataEnd_cfg.h"

    /*
     *  �ⲿ����ʹ�ñ���
     */
extern INT32U  __GuiIndex;
extern INT8U   __GucUpgradeBuf[];
extern INT32U  __GuiBackupAddr;

extern void    (*__GpsysSoftParaGet)(INT32U*);
extern INT32S  (*__GpsysUpgradeBegin)(INT8U*, INT32U);
extern INT32S  (*__GpsysUpgradeDataWrite)(unsigned int);
extern INT32S  (*__GpsysUpgradeEnd)(void);   


    /*
     *  �ڲ�ʹ�ñ���
     */
extern INT8U  __GucFlagOnce;     


/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpWrite(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
static INT32S __tpCreate (const TM_PORT_INFO *ptpiThis);
/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TM_PORT_FUNC GtpfUpDataEnd = {
    __tpCreate,
    NULL,
    NULL,
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
    TP_UPDATA_END_INFO *pttiPortCase;                                   /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPDATA_END_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  ����ĳ�ʼ������
     */
   
    
    
    return TM_OK;
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
    TP_UPDATA_END_INFO *pttiPortCase;                               /*  �豸��Ϣ                    */
    INT32S                  siErr;
    MD5_CTX                 md5_check;
    //static __PARAM_STRUCT   __SpsTmp;         
    pttiPortCase = (TP_UPDATA_END_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    
    /*
     *  ʵ�ʵ�д����
     */        
    if ((__GuiIndex >= ((512* 1024)/__UPGRADE_PAGE_SIZE)) || (NULL == __GpsysUpgradeDataWrite) || (__GuiChanle != ucChanle) ||
        (((__GuiIndex + 1) * __UPGRADE_PAGE_SIZE) < __GuiCodeInfo[codeLen]) || (((__GuiIndex - 1) * __UPGRADE_PAGE_SIZE) >= __GuiCodeInfo[codeLen])
        ) {
        return 0;
    }
    if (0 == __GucFlagOnce) {
      	MD5Init(&md5_check);
        MD5Update(&md5_check, (INT8U*)__GuiBackupAddr, __GuiCodeInfo[codeLen] - 16);
        MD5Final(__GucUpgradeBuf, &md5_check);
        
      	memcpy(__GucUpgradeBuf + 16, (INT8U*)(__GuiBackupAddr + __GuiCodeInfo[codeLen] - 16), 16);   
        if (memcmp(__GucUpgradeBuf, __GucUpgradeBuf + 16, 16) != 0) {        	
        	
        	if (__GpsysUpgradeEnd == sysUpgradeEnd) {                   /*  �����������                */
        	    sysIrqDisable(); 
                OSSchedLock();
            	sysSectorPrepare (1, 2);                                /*  ����׼��					*/
                sysSectorErase (1, 2);	                                /*  ��������					*/      
            	OSSchedUnlock();  
                sysIrqEnable(); 
        	} else if (sysUpgradeEndUsr == __GpsysUpgradeEnd) {         /*  ����Ӧ�ó���                */
        	    sysIrqDisable(); 
                OSSchedLock();
                sysWordProgramEx(0x80100018,0x0000);
                sysWordProgramEx(0x8010001A,0x0000);
                sysWordProgramEx(0x80101018,0x0000);
                sysWordProgramEx(0x8010101A,0x0000);
             	OSSchedUnlock();  
                sysIrqEnable(); 
        	} else {                                                    /*  �����������                */
        	    sysIrqDisable(); 
                OSSchedLock();
                sysCodeEraseEx();
             	OSSchedUnlock();  
                sysIrqEnable();    
        	
        	}
        	__GucUpgradeOk = 0x55;
        	GUI_Printf(__GucXPoint, __GucYPoint, 1, "У�������    ");
        	__GuiIndex = 0;    	 
        	return 0x0F;
        } else {
            GUI_Printf(__GucXPoint, __GucYPoint, 1, "У������ȷ��    ");
        }
        __GucUpgradeOk = 0xAA;
        __GucFlagOnce = 1;
    }    
  	if ((OS_TASK_NOT_EXIST != OSTaskDelReq(TASK1_PRIO)) || 
        (OS_TASK_NOT_EXIST != OSTaskDelReq(TASK2_PRIO))
        ) {
        return 0;
    }    
    
    sysIrqDisable();
    OSSchedLock(); 
    siErr = __GpsysUpgradeEnd(); 
    OSSchedUnlock();       
    sysIrqEnable();
    /*
     *  ���������г����ܳ�������������������޷�����
     *  ����취��
     *  1��ֱ���ɹ�����������������������پ���boot��
     *  2�������������д����Ч�ĳ����ܳ���ֵ��
     *     ���ٴν���������������ʱ������boot����������
     */
    if (siErr == -COUNT_ERROR) {      
        if (__GpsysUpgradeEnd == sysUpgradeEnd) {                               /*  �����������                */
    	    if (((__PARAM_STRUCT *)__PARAM_ADDR0)->uiCodeLenRsv != __GuiCodeInfo[codeLen]) {
    	        memcpy(__GucUpgradeBuf, (void *)__PARAM_ADDR0, sizeof(__PARAM_STRUCT));
    	        
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen = __GuiCodeInfo[codeLen];
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLenRsv1 = __GuiCodeInfo[codeLen];

                sysIrqDisable(); 
                OSSchedLock();
                sysSectorPrepare (1, 1);                                        /* ����׼��						*/
                sysSectorErase (1, 1);	                                        /* ��������						*/

                sysSectorPrepare (1, 1);                                        /* ����׼��						*/						
                sysRamToFlash(__PARAM_ADDR0,(INT32U)__GucUpgradeBuf, 512); 
                siErr = sysDataCompare(__PARAM_ADDR0,(INT32U)__GucUpgradeBuf, 512);
                
                OSSchedUnlock();
                sysIrqEnable(); 
                if (0 != siErr) {
                    return 0;
                }
            }
            if (((__PARAM_STRUCT *)__PARAM_ADDR1)->uiCodeLenRsv != __GuiCodeInfo[codeLen]) {
    	        memcpy(__GucUpgradeBuf, (void *)__PARAM_ADDR1, sizeof(__PARAM_STRUCT));
    	        
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen = __GuiCodeInfo[codeLen];
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLenRsv1 = __GuiCodeInfo[codeLen];

                sysIrqDisable(); 
                OSSchedLock();
                sysSectorPrepare (2, 2);                                        /* ����׼��						*/
                sysSectorErase (2, 2);	                                        /* ��������						*/

                sysSectorPrepare (2, 2);                                        /* ����׼��						*/						
                sysRamToFlash(__PARAM_ADDR1,(INT32U)__GucUpgradeBuf, 512); 
                siErr = sysDataCompare(__PARAM_ADDR1,(INT32U)__GucUpgradeBuf, 512);
                OSSchedUnlock();  
                sysIrqEnable();  
                
            }
    	} else if (sysUpgradeEndUsr == __GpsysUpgradeEnd) {         /*  ����Ӧ�ó���                */
    	    if (((__PARAM_STRUCT *)__PARAM_ADDR_EX0)->uiCodeLenRsv1 != __GuiCodeInfo[codeLen]) {
    	        memcpy(__GucUpgradeBuf, (void *)__PARAM_ADDR_EX0, sizeof(__PARAM_STRUCT));
    	        
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen = __GuiCodeInfo[codeLen];
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLenRsv1 = __GuiCodeInfo[codeLen];

                sysIrqDisable(); 
                OSSchedLock();
                
                sysWordProgramEx(__PARAM_ADDR_EX0 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 0,
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 0) & 0xFFFF);
                sysWordProgramEx(__PARAM_ADDR_EX0 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 2, 
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 16) & 0xFFFF);
                
                
                
                OSSchedUnlock();
                sysIrqEnable(); 
                
            }
            if (((__PARAM_STRUCT *)__PARAM_ADDR_EX1)->uiCodeLenRsv1 != __GuiCodeInfo[codeLen]) {
    	        memcpy(__GucUpgradeBuf, (void *)__PARAM_ADDR_EX1, sizeof(__PARAM_STRUCT));
    	        
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen = __GuiCodeInfo[codeLen];
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLenRsv1 = __GuiCodeInfo[codeLen];

                sysIrqDisable(); 
                OSSchedLock();
                sysWordProgramEx(__PARAM_ADDR_EX1 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 0,
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 0) & 0xFFFF);
                sysWordProgramEx(__PARAM_ADDR_EX1 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 2, 
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 16) & 0xFFFF);
                OSSchedUnlock();  
                sysIrqEnable();  
                
            }   
    	} else {                                                    /*  �����������                */
            if (((__PARAM_STRUCT *)__PARAM_ADDR_EX2)->uiCodeLenRsv1 != __GuiCodeInfo[codeLen]) {
    	        memcpy(__GucUpgradeBuf, (void *)__PARAM_ADDR_EX0, sizeof(__PARAM_STRUCT));
    	        
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen = __GuiCodeInfo[codeLen];
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLenRsv1 = __GuiCodeInfo[codeLen];

                sysIrqDisable(); 
                OSSchedLock();
                
                sysWordProgramEx(__PARAM_ADDR_EX2 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 0,
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 0) & 0xFFFF);
                sysWordProgramEx(__PARAM_ADDR_EX2 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 2, 
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 16) & 0xFFFF);
                OSSchedUnlock();
                sysIrqEnable(); 
               
            }
            if (((__PARAM_STRUCT *)__PARAM_ADDR_EX3)->uiCodeLenRsv1 != __GuiCodeInfo[codeLen]) {
    	        memcpy(__GucUpgradeBuf, (void *)__PARAM_ADDR_EX1, sizeof(__PARAM_STRUCT));
    	        
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen = __GuiCodeInfo[codeLen];
    	        ((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLenRsv1 = __GuiCodeInfo[codeLen];

                sysIrqDisable(); 
                OSSchedLock();
                sysWordProgramEx(__PARAM_ADDR_EX3 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 0,
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 0) & 0xFFFF);
                sysWordProgramEx(__PARAM_ADDR_EX3 + (INT32U)(&((__PARAM_STRUCT *)0)->uiCodeLenRsv1) + 2, 
                                (((__PARAM_STRUCT *)__GucUpgradeBuf)->uiCodeLen >> 16) & 0xFFFF);
                OSSchedUnlock();  
                sysIrqEnable(); 
            }   
    	}
    	return 0;  	
    } else if (siErr < 0) {
        usLen  = 0;
    } else {
        GUI_Printf(__GucXPoint, __GucYPoint, 1, "��������:100%%   "); 
        OSTaskDelReq(TASK0_PRIO);            
    } 
    return usLen;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/