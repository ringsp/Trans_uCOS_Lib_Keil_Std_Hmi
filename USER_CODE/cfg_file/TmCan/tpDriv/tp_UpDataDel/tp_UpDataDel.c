/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpDataDel.c
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
#include ".\tp_UpDataDel_cfg.h"

    /*
     *  �ⲿ����ʹ�ñ���
     */
   
    /*
     *  �ڲ�ʹ�ñ���
     */
/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpWrite(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TM_PORT_FUNC GtpfUpDataDel = {
    NULL,
    NULL,
    NULL,
    __tpWrite
};
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
    TP_UPDATA_DEL_INFO *pttiPortCase;                               /*  �豸��Ϣ                    */
    INT8U   ucChn;
    INT8U   ucData[4] = {0xaa,0x11,0x55,0x22}; 
    pttiPortCase = (TP_UPDATA_DEL_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    
    /*
     *  ʵ�ʵ�д����
     */        
    
    if (__GucTmDrivChn[(__PORT_DEF_RIGHT >> 3) & 0x07][__PORT_DEF_RIGHT & 0x07] == ucChanle) {                                 /*  ����ת��ͨ��                */                
        ucChn = __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07]; 
    } else {
        ucChn = __GucTmDrivChn[(__PORT_DEF_RIGHT >> 3) & 0x07][__PORT_DEF_RIGHT & 0x07];
    }          
    if (memcmp(ucData, pvData, 4) == 0) {        
        sysCodeEraseUsr();        
        OSTaskDelReq(TASK0_PRIO);  
        return (tmWrite(ucChn, 0x02, 4, ucData, 1));         
    } else {
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
        // ��ʾ"У��ʧ�ܣ�����������"
        __GucUpgradeOk = 0x55;
        GUI_Printf(__GucXPoint, __GucYPoint, 1, "����ʧ��,������!");
        return usLen;
    }
    return usLen;
}

/*********************************************************************************************************
  DEL FILE
*********************************************************************************************************/
