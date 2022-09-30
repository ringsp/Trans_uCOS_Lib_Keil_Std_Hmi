/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpgradeBegin.c
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
#include ".\tp_UpgradeBegin_cfg.h"

    /*
     *  �ⲿ����ʹ�ñ���
     */

INT8U   __GucBufTmp[2][__UPGRADE_PAGE_SIZE];                            /*  �������ݻ�����              */
INT8U   __GucUpgradeBuf[__UPGRADE_PAGE_SIZE];                           /*  ����������                  */

INT32U  __GuiIndex;                                                     /*  �����ɹ�������              */
INT32U  __GuiChanle;                                                    /*  ����ͨѶͨ���ż�¼          */

INT8U   __GucXPoint;
INT8U   __GucYPoint;
INT32U  __GuiBackupAddr;

void    (*__GpsysSoftParaGet)(INT32U*);
INT32S  (*__GpsysUpgradeBegin)(INT8U*, INT32U);
INT32S  (*__GpsysUpgradeDataWrite)(unsigned int);
INT32S  (*__GpsysUpgradeEnd)(void);   

INT8U   __GucUpgradeOk;
INT8U   __GucFlagOnce;
volatile INT8U  __GucIsCanBusUpdate;                                    /*  ����������������ʶ          */
/*
 *  ����汾��Ϣȫ�ֱ���
 */
INT32U  __GuiCodeInfo[3];                                
    /*
     *  �ڲ�ʹ�ñ���
     */
static  INT32U      __SuiErr[2];                                        /*  ������ʼ����ֵ              */
__PRO_SEVER_PARA    __SpspTmp[2];
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
const TM_PORT_FUNC GtpfUpgradeBegin = {
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
    TP_UPGRADEBEGIN_INFO *pttiPortCase;                                     /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPGRADEBEGIN_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  ����ĳ�ʼ������
     */    
    
    __GuiIndex      = ~0;
    __GuiChanle     = ~0;
    memset(__SuiErr, 0xFF, sizeof(__SuiErr));
    memset(__SpspTmp, 0x00, 2 * sizeof(__PRO_SEVER_PARA));
    memset(__GuiCodeInfo, 0x00, sizeof(__GuiCodeInfo));
    __GpsysSoftParaGet = NULL;
    __GpsysUpgradeBegin = NULL;
    __GpsysUpgradeDataWrite = NULL;
    __GpsysUpgradeEnd = NULL;
    
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
    TP_UPGRADEBEGIN_INFO *pttiPortCase;                                 /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_UPGRADEBEGIN_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  �����ж�ش���
     */    
    
    __GuiIndex      = ~0;
    __GuiChanle     = ~0;    
    memset(__SuiErr, 0xFF, sizeof(__SuiErr));    
    memset(__SpspTmp, 0x00, 2*sizeof(__PRO_SEVER_PARA));
    memset(__GuiCodeInfo, 0x00, sizeof(__GuiCodeInfo));
    __GpsysSoftParaGet = NULL;
    __GpsysUpgradeBegin = NULL;
    __GpsysUpgradeDataWrite = NULL;
    __GpsysUpgradeEnd = NULL;
    
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
    TP_UPGRADEBEGIN_INFO *pttiPortCase;                                 /*  �豸��Ϣ                    */
    if (usLen > 8) {
        return 0;
    }
    pttiPortCase = (TP_UPGRADEBEGIN_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    
    memcpy(pvData, __SuiErr, usLen);       
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
    TP_UPGRADEBEGIN_INFO   *pttiPortCase;                               /*  �豸��Ϣ                    */
    INT32U                  uiTmp;
    INT32U                  uiCodePar[3];
    INT32U                  uiCodeVer;
    INT8U                   ucNum;
    
    pttiPortCase = (TP_UPGRADEBEGIN_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;    
    
    
    /*
     *  ʵ�ʵ�д����
     */        

    if (__GucIsSrc) {
        __SuiErr[0] = 0x01;
        __SuiErr[1] = __UPGRADE_PRO_BEGIN_ERR;   	                    /*  ��������ʧ��                */
        return usLen;
    }
    uiTmp = ((INT32U*)pvData)[2];
    tm_ntohl(uiTmp);                                                    /*  ��ȡ�³�������            */
    
    
    if((~0 != __GuiChanle)) {                                           /*  ����������                  */
        if ((ucChanle != __GuiChanle)) {                                /*  ����ͨ����ͬ                */
	        __SuiErr[0] = 0x01;
	        __SuiErr[1] = __UPGRADE_PRO_BEING_ERR;   	                /*  �������������              */
	        return usLen;
	    }
	    memcpy(uiCodePar, pvData, 12);
	    tm_ntohl(uiCodePar[codeVer]);
	    tm_ntohl(uiCodePar[codeLen]);
	    tm_ntohl(uiCodePar[codeId]);
	    if ((__GuiCodeInfo[codeVer] != uiCodePar[codeVer]) ||
	        (__GuiCodeInfo[codeLen] != uiCodePar[codeLen]) ||
	        (__GuiCodeInfo[codeId] != uiCodePar[codeId] )) {             /*  ��������ͬ                */   
    		__SuiErr[0] = 0x01;
        	__SuiErr[1] = __UPGRADE_PRO_BEING_ERR; 	                    /*  �������������              */	
    		return usLen;
    	}
    } else {                                                            /*  �����״�����                */
        GUI_ClearSCR();
    }
    if (__DLM_CODE_ID == (uiTmp & 0x800000FF)) {                        /*  ���ع����������            */
        __GpsysSoftParaGet      = sysSoftParaGet;
        __GpsysUpgradeBegin     = sysUpgradeBegin;  
        __GpsysUpgradeDataWrite = sysUpgradeDataWrite; 
        __GpsysUpgradeEnd       = sysUpgradeEnd;   
        __SpspTmp[0].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC0;         /*  ���������������Ԥ���ַ    */
        __SpspTmp[0].pucBufTmp  = __GucBufTmp[0];
        __GuiBackupAddr = __UPGRADE_CODES_SRC0;
        __GucXPoint = 0;
        __GucYPoint = 44; 
        GUI_Printf(0, 4, 1, "���ع����������"); 
        #if 0
        /*
         *  ȥ���ϵ���������
         */
        if ((~0 == __GuiChanle) || (__GucUpgradeOk == 0x55)) {
            sysIrqDisable(); 
            OSSchedLock();
        	sysSectorPrepare (1, 2);                                    /* ����׼��						*/
            sysSectorErase (1, 2);	                                    /* ��������						*/      
        	OSSchedUnlock();  
            sysIrqEnable();
        }
        #endif 
    } else if (__USR_CODE_ID == (uiTmp & 0x800000FF)) {                 /*  ��������������              */
        __GpsysSoftParaGet      = sysSoftParaGetUsr;
        __GpsysUpgradeBegin     = sysUpgradeBeginUsr;        
        __GpsysUpgradeDataWrite = sysUpgradeDataWriteUsr; 
        __GpsysUpgradeEnd       = sysUpgradeEndUsr;
        __SpspTmp[0].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC1;         /*  Ӧ�ó�����������Ԥ���ַ    */
        __SpspTmp[0].pucBufTmp  = __GucBufTmp[0];
        __GuiBackupAddr = __UPGRADE_CODES_SRC1;
        __GucXPoint = 0;
        __GucYPoint = 44; 
        GUI_Printf(0, 4, 1, "  Ӧ�ó�������  "); 
        #if 0
        /*
         *  ȥ���ϵ���������
         */
        if ((~0 == __GuiChanle) || (__GucUpgradeOk == 0x55)) {
            sysIrqDisable(); 
            OSSchedLock();
            sysWordProgramEx(0x80100018,0x0000);
            sysWordProgramEx(0x8010001A,0x0000);
            sysWordProgramEx(0x80101018,0x0000);
            sysWordProgramEx(0x8010101A,0x0000);
         	OSSchedUnlock();  
            sysIrqEnable(); 
        }
        #endif
    } else if (0 != (uiTmp & 0x80000000)) {                             /*  �������ܴ�������            */
        __GpsysSoftParaGet      = sysSoftParaGetEx;
        __GpsysUpgradeBegin     = sysUpgradeBeginEx;        
        __GpsysUpgradeDataWrite = sysUpgradeDataWriteEx; 
        __GpsysUpgradeEnd       = sysUpgradeEndEx;
        
        __SpspTmp[0].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC3;         /*  ���ܴ�����������Ԥ���ַ    */
        __SpspTmp[1].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC3;         /*  ���ܴ�����������Ԥ���ַ    */
        __SpspTmp[0].pucBufTmp  = __GucBufTmp[0];
        __SpspTmp[1].pucBufTmp  = __GucBufTmp[1];

        __GuiBackupAddr = __UPGRADE_CODES_SRC3;
        __GucXPoint = 0;
        __GucYPoint = 16;
        GUI_Printf(0, 0, 1, "���ܴ��г�������");
        #if 0
        /*
         *  ȥ���ϵ���������
         */
        if ((~0 == __GuiChanle) || (__GucUpgradeOk == 0x55)) {
            sysCodeEraseEx();  
        }
        #endif  
    } else {
        __GuiChanle = ~0;
        usLen = 0;        
        ioOutportLong(0x0, __EN_UPGRADE_FLAG0);
        ioOutportLong(0x0, __EN_UPGRADE_FLAG1);  
        OSTaskDelReq(TASK0_PRIO);
        GUI_Printf(0, 24, 1, "�������Ͳ��Ϸ���");     
        return usLen; 
    }
    
    __GpsysSoftParaGet(uiCodePar);                                      /*  ��õ�ǰ�������            */
    
    uiCodePar[codeLen] = ((INT32U*)pvData)[codeLen];                    /*  ��ȡ�³���ĳ���            */
    tm_ntohl(uiCodePar[codeLen]);
    
    uiCodeVer = ((INT32U*)pvData)[codeVer];                             /*  ��ȡ�³���İ汾��Ϣ        */
    tm_ntohl(uiCodeVer); 
   
    if (((uiCodePar[codeLen] > __USR_CODE_LEN) && (__USR_CODE_ID == (uiTmp & 0x800000FF))) ||
        ((uiCodePar[codeLen] > __DLM_CODE_LEN) && (__DLM_CODE_ID == (uiTmp & 0x800000FF))) ||
        (uiCodePar[codeLen] > __MAX_CODE_LEN)) {
        __SuiErr[0] = 0x01;
        __SuiErr[1] = __UPGRADE_PRO_TOOLONG_ERR;                        /*  �³���ĳ���̫��            */
        __GuiChanle = ~0;
        GUI_Printf(0, 24, 1, "���򳤶Ȳ��Ϸ���");
        ioOutportLong(0x0, __EN_UPGRADE_FLAG0);
        ioOutportLong(0x0, __EN_UPGRADE_FLAG1);  
        OSTaskDelReq(TASK0_PRIO);
        return usLen; 
    }
    if (((0 != (uiTmp & 0x80000000))) && ((uiTmp & 0x800000FF) != (uiCodePar[codeId] & 0x800000FF))) {                  
        sysCodeEraseEx();                                               /*  ������������                */            
        uiCodePar[codeVer]  = ~0;
        uiCodePar[codeLen]  = ~0;
        uiCodePar[codeId]   = ~0;
    } 
    
    if((~0 == uiCodePar[codeVer]) || (0 == (uiCodePar[codeVer] & 0xFF))){
        uiCodePar[codeVer] = uiCodeVer - 1;
    }
    if ((~0 == uiCodePar[codeId])) {
        uiCodePar[codeId] = uiTmp;
    }
    if ((~0 == uiCodePar[codeLen])) {
        uiCodePar[codeLen] = ((INT32U*)pvData)[codeLen];                /*  ��ȡ�³���ĳ���            */
        tm_ntohl(uiCodePar[codeLen]);
    }
    
#if 0                                                                   /*  ȥ����Ŀ�汾����            */ 
    if ((uiCodeVer >> 8) != (uiCodePar[codeVer] >> 8)) {
        __SuiErr[0] = 0x01;
        __SuiErr[1] = __UPGRADE_PRO_NOMATCH_ERR;                        /*  �³������Ŀ��ƥ��          */
        __GuiChanle = ~0;
        GUI_Printf(0, 24, 1, "������Ŀ��ƥ�䣡"); 
        ioOutportLong(0x0, __EN_UPGRADE_FLAG0);
        ioOutportLong(0x0, __EN_UPGRADE_FLAG1); 
        OSTaskDelReq(TASK0_PRIO);
        return usLen; 
    } else if ((((((uiCodeVer >> 4) & 0x0F) < (((uiCodePar[codeVer] >> 4) & 0x0F) - 1))&&(0 != (uiCodePar[codeVer] & 0xF0)))) && 
               ((uiTmp & 0x800000FF) == (uiCodePar[codeId] & 0x800000FF))) {
        __SuiErr[0] = 0x01;
        __SuiErr[1] = __UPGRADE_PRO_VERLOW_ERR;                         /*  �³���İ汾̫��            */
        __GuiChanle = ~0;
        GUI_Printf(0, 24, 1, "��������汾�ͣ�");
        ioOutportLong(0x0, __EN_UPGRADE_FLAG0);
        ioOutportLong(0x0, __EN_UPGRADE_FLAG1);  
        OSTaskDelReq(TASK0_PRIO);
        return usLen; 
    }                                                               
#endif
    
    /*  
     *  �³������ϢУ��ͨ��        
     */
    memcpy(__GucUpgradeBuf, pvData, usLen);
    /*
     *  �ܺ���Ϣ��Я��
     */
    ucNum = __GucUpgradeBuf[9]; 
    __GucUpgradeBuf[9] = 0;
    
    
    /*
     *  ��ͬ�汾����ȫ����
     */
    if ((__USR_CODE_ID == (uiTmp & 0x800000FF)) && ((uiCodeVer & 0xFF) == (uiCodePar[codeVer] & 0xFF))) {
    	sysIrqDisable(); 
    	OSSchedLock();
    	sysSectorEraseEx(256);
    	sysSectorEraseEx(257);
    	OSSchedUnlock(); 
    	sysIrqEnable();
    }

    
    sysIrqDisable(); 
    OSSchedLock();
    __SuiErr[1] = __GpsysUpgradeBegin(__GucUpgradeBuf, __UPGRADE_PAGE_SIZE);
    OSSchedUnlock(); 
    sysIrqEnable();
   
    if(__SuiErr[1] > -128) {
        __SuiErr[0] = 0x01;
        __SuiErr[1] = __UPGRADE_PRO_BEGIN_ERR;                          /*  ������������ʧ��            */
        __GuiChanle = ~0;
        return usLen;
    }
    
    __GucUpgradeOk  = 0;
    __GucFlagOnce   = 0;
    
    memcpy(__GuiCodeInfo, pvData, usLen);
    tm_ntohl(__GuiCodeInfo[codeVer]);
    tm_ntohl(__GuiCodeInfo[codeLen]);
    tm_ntohl(__GuiCodeInfo[codeId]);
    __SuiErr[0] = 0x00; 
    
    if (__SuiErr[1] > __GuiCodeInfo[codeLen]) {
        __GuiIndex = (0 == (__GuiCodeInfo[codeLen] % __UPGRADE_PAGE_SIZE))?\
                           (__GuiCodeInfo[codeLen] / __UPGRADE_PAGE_SIZE):\
                           ((__GuiCodeInfo[codeLen] / __UPGRADE_PAGE_SIZE) + 1);
        __SuiErr[1] = __GuiCodeInfo[codeLen];
    } else {       
        __GuiIndex = (__SuiErr[1] / __UPGRADE_PAGE_SIZE);
    }
    

    if ((~0 == __GuiChanle)) { 
        __GuiChanle = ucChanle;
        
        if ((__DLM_CODE_ID == (uiTmp & 0x800000FF)) ||
            (__USR_CODE_ID == (uiTmp & 0x800000FF))) {                  /*  ����������                  */
            if (0 == (uiTmp & (1 << 24))) {
                tpUpDataEndInit();
                tpUpDataInit(); 
                tpUpParaInit();                
                GUI_Printf(0, 24, 0, "  ���������У�  ");
                return usLen; 
            } else if (ucNum == 1) {                                    /*  �յ��                      */
                tpUpDataEndInit();
                tpUpDataInit();
                tpUpParaInit();
                GUI_Printf(0, 24, 0, " ��������ĩ�ܣ� ");
                return usLen;
            } else {
                ;
            }
        } else {
            if (0 == (uiTmp & (1 << 24))) {
                GUI_Printf(0, 16, 0, "  ���������У�  ");
            } else if (ucNum == 1) {                                    /*  �յ��                      */
                GUI_Printf(0, 16, 0, " ��������ĩ�ܣ� ");
            } else {
                ;
            }
        } 
    } else {                                                            /*  �����ظ���������            */
        
        return usLen;
    }       
    if (sysUpgradeBeginEx == __GpsysUpgradeBegin) {
        if (__GuiIndex * __UPGRADE_PAGE_SIZE == uiCodePar[codeLen]) {
            GUI_Printf(0, 16, 1, "��������: 99%%   ");
        } else {
            GUI_Printf(0, 16, 1, "��������:%3d%%   ",
                       (INT8U)(((__SuiErr[1]) * 100) / uiCodePar[codeLen])); 
        }
    } else {
        if (__GuiIndex * __UPGRADE_PAGE_SIZE == uiCodePar[codeLen]) {
            GUI_Printf(0, 44, 1, "��������: 99%%   ");
        } else {
            GUI_Printf(0, 44, 1, "��������:%3d%%   ",
                       (INT8U)(((__SuiErr[1]) * 100) / uiCodePar[codeLen])); 
        }
                    
        
    }
    if ((__DLM_CODE_ID == (uiTmp & 0x800000FF)) ||
        (__USR_CODE_ID == (uiTmp & 0x800000FF))) {                      /*  ����������                  */
        __SpspTmp[0].uiXpoint = 0;
        __SpspTmp[0].uiYpoint = 24;                  
    
    } else {                                                            /*  ���ܴ���������              */
        __SpspTmp[0].uiXpoint = 0;
        __SpspTmp[0].uiYpoint = 0;            
        __SpspTmp[1].uiXpoint = 0;
        __SpspTmp[1].uiYpoint = 32;          
    }
    __SpspTmp[0].ucIsCodePro = 0;                                       /*  ������������������        */
    __SpspTmp[1].ucIsCodePro = 0;                                       /*  ������������������        */
    
    if (__GucTmDrivChn[(__PORT_DEF_RIGHT >> 3)&0x07][__PORT_DEF_RIGHT & 0x07] == ucChanle) {
                                                                        /*  ��������ͨ��                */                
        __SpspTmp[0].uiChn    = __PORT_DEF_LEFT;  
    } else {
        __SpspTmp[0].uiChn    = __PORT_DEF_RIGHT;
    }
    
    if (uiTmp & (1 << 31)) {                                            /*  ���ô�����ת��ͨ��          */
        __SpspTmp[1].uiChn    = (uiTmp >> 25) & 0x3F;    
        tmRemoteDriversAdd((TM_DRIVER_INFO_BASE*)__GpdiTmDrivrers[__GucTmDrivChn[(uiTmp >> 28) & 0x07][(uiTmp >> 25) & 0x07]]);
    }
    if (ucNum == 0) {                                                   /*  ����������                  */
        ;
    } else if (ucNum == 1) {                                            /*  �յ��                      */
        ;   
    } else {                                                            /*  �����ݼ�                    */
        ;   
    }
    
    /*
     *  ���ݼ���
     */
    memcpy((INT8U*)(__SpspTmp[0].uiCodePar), pvData, usLen);
    memcpy((INT8U*)(__SpspTmp[1].uiCodePar), pvData, usLen);
    if (ucNum > 0) {        
        ((INT8U*)__SpspTmp[0].uiCodePar)[9] = ucNum - 1;                /*  ��������                    */
        ((INT8U*)__SpspTmp[1].uiCodePar)[9] = 0;                        /*  ���ܴ�������������          */
    } 
    
        
    /*
     *  ��������Ӧ�ó���DLM����ʱ���ж��Ƿ񴫵���
     */  
    if ((0 == (uiTmp & 0x80000000))) {      
        if ((__USR_CODE_ID == (uiTmp & 0x800000FF)) || 
            (__DLM_CODE_ID == (uiTmp & 0x800000FF))) {}
    } else {
        ;
    }

    OSSchedLock();
    
    tpUpDataEndDel();
    tpUpDataDel();
    tpUpParaDel(); 
    tpApplyUsrDel();                  
    if (((uiTmp & 0x800000FF) == __DLM_CODE_ID || (__USR_CODE_ID == (uiTmp & 0x800000FF)))) {
        OSTaskCreateExt(Pro_SeverTask,
            (void *)&__SpspTmp[0],
            &TASK1_STACK[TASK1_STACK_SIZE-1],
            TASK1_PRIO,
            TASK1_ID,
            &TASK1_STACK[0],
            TASK1_STACK_SIZE,
            (void *)0,
            OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR); 
    } else {
        if (0 != (uiTmp & (1 << 24))) {                                 /*  ����                        */
            OSTaskCreateExt(Pro_SeverTask,
                            (void *)&__SpspTmp[0],
                            &TASK1_STACK[TASK1_STACK_SIZE-1],
                            TASK1_PRIO,
                            TASK1_ID,
                            &TASK1_STACK[0],
                            TASK1_STACK_SIZE,
                            (void *)0,
                            OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR); 
           
        }                                                               /*  ��������ת������            */

        OSTaskCreateExt(Pro_SeverTask,
                        (void *)&__SpspTmp[1],
                        &TASK2_STACK[TASK2_STACK_SIZE-1],
                        TASK2_PRIO,
                        TASK2_ID,
                        &TASK2_STACK[0],
                        TASK2_STACK_SIZE,
                        (void *)0,
                        OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    }       

    tpUpDataEndInit();
    tpUpDataInit();
    tpUpParaInit();
    OSSchedUnlock(); 
     
    return usLen;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
