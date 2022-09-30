/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_ApplyUsr.h
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
#include ".\tp_ApplyUsr_cfg.h"

    /*
     *  �ⲿ��������
     */
extern  INT8U   __GucBufTmp[2][__UPGRADE_PAGE_SIZE];
extern __PRO_SEVER_PARA    __SpspTmp[2];
    /*
     *  �ⲿ����ʹ�ñ���
     */

INT8U   __GucIsSrc;                                                     /*  ����Դ��ʶ                  */

    /*
     *  �ڲ�ʹ�ñ���
     */
//static __PRO_SEVER_PARA     __SpspApplyUsr[2]; 

//static INT32U               __SuiErr[TM_MAX_DRIVER][1];                 /*  ������������
//                                                                         *  [0] �������
//                                                                         */


static void    (*__SpsysParaGet)(INT32U*);


/*
 *  ����汾��Ϣȫ�ֱ���
 */
extern INT32U		__SuiTmp[3];

/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpCreate(const TM_PORT_INFO *ptpiThis);
static INT32S __tpDel(const TM_PORT_INFO *ptpiThis);
static INT32S __tpRead(const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
static INT32S __tpWrite (const TM_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TM_PORT_FUNC GtpfApplyUsr = {
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
    TP_APPLYUSR_INFO *pttiPortCase;                                     /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_APPLYUSR_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  ����ĳ�ʼ������
     */
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
    TP_APPLYUSR_INFO *pttiPortCase;                                     /*  �豸��Ϣ                    */
    
    pttiPortCase = (TP_APPLYUSR_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase;
    /*
     *  �����ж�ش���
     */
    
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
    
    INT32U uiTmp[3];
    TP_APPLYUSR_INFO *pttiPortCase;                                     /*  �豸��Ϣ                    */
    pttiPortCase = (TP_APPLYUSR_INFO *)ptpiThis;
    /*
     *  ʵ��д�Ĵ���
     */    
    uiTmp[2] = ((INT32U *)pvData)[0];
    if (0xff == ucChanle) {                                             /*  ������˿�                  */
        ucChanle = __GucTmDrivChn[(uiTmp[2] >> 28) & 0x07][(uiTmp[2] >> 25) & 0x07];    
    }
    if ((ucChanle != __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07]) && 
        (ucChanle != __GucTmDrivChn[(__PORT_DEF_RIGHT >> 3)& 0x07][__PORT_DEF_RIGHT& 0x07])) {
                                                                        /*  ������ֻ�������ڼ�          */
        return 0;
    }
    if (usLen < 4) {                                                    /*  ��������                    */
        return 0;
    }
    sysSoftParaGetUsr(uiTmp);                                           /*  ��ȡӦ�ó���汾            */
	memcpy(pvData, uiTmp, usLen);                                       /*	��������뷵��				*/
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
    TP_APPLYUSR_INFO   *pttiPortCase;                                   /*  �豸��Ϣ                    */
    INT32U              uiTmp;
    INT32U              uiCodePar[3];
    INT8U               ucTaskOn = 0;
    //__PRO_SEVER_PARA    pspTmp;
    void    (*pfSoftParaGet)(INT32U*);
    
    pttiPortCase = (TP_APPLYUSR_INFO *)ptpiThis;
    pttiPortCase = pttiPortCase; 
    
    /*
     *  ʵ��д�Ĵ���
     */
    uiTmp = ((INT32U *)pvData)[0];
    tm_ntohl(uiTmp);
    
    if (0xff == ucChanle) {                                             /*  �������������              */
        ucChanle = __GucTmDrivChn[(uiTmp >> 28) & 0x07][(uiTmp >> 25) & 0x07]; 
    }
    if ((ucChanle != __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07]) && 
        (ucChanle != __GucTmDrivChn[(__PORT_DEF_RIGHT>> 3) & 0x07][__PORT_DEF_RIGHT& 0x07])) {
                                                                        /*  ������ֻ�������ڼ�          */
        return usLen;
    }
    
    

    if (OS_TASK_RESUME_PRIO != OSTaskResume(TASK1_PRIO)) {
        ucTaskOn |= (1 << 0);
    }
    if (OS_TASK_RESUME_PRIO != OSTaskResume(TASK2_PRIO)) {
        ucTaskOn |= (1 << 1);
    }
    
    if (((ucTaskOn & (1 << 0)) && (ucChanle == __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07])) ||
        ((ucTaskOn & (1 << 1)) && (ucChanle == __GucTmDrivChn[(__PORT_DEF_RIGHT>> 3) & 0x07][__PORT_DEF_RIGHT& 0x07]))){
        return usLen;    
    }
    if (__DLM_CODE_ID == (uiTmp & 0x800000FF)) {                        /*  �������ع������            */
        pfSoftParaGet     = sysSoftParaGet;            
    } else if (__USR_CODE_ID == (uiTmp & 0x800000FF)){                  /*  �������������              */
        pfSoftParaGet     = sysSoftParaGetUsr;
    } else if (0 != (uiTmp & 0x80000000)) {                             /*  �����������ܴ���            */
        pfSoftParaGet     = sysSoftParaGetEx;
    } else {     
        GUI_ClearSCR();
        GUI_Printf(0, 44, 1, "������򲻺Ϸ���");     
        return usLen; 
    }
    pfSoftParaGet(uiCodePar);                                           /*  ��ȡ����Ӧ�ó�����Ϣ        */
    
    uiCodePar[2] &= ~(1 << 24);                                         /*  Ĭ�ϴ�����                  */
    
    if (((uiCodePar[2] & 0x800000ff) != (uiTmp & 0x800000ff)) &&        /*  �������δ����              */
        (uiTmp & 0xff != __USR_CODE_ID)) {                              /*  Ӧ�ó������                */                               
        GUI_ClearSCR();
        GUI_Printf(0, 44, 1, "  ���������Ч��");     
        return usLen;
    }
    if (ioInportLong(__EN_UPGRADE_FLAG0) == 0x12345678) {               /*  ������������������          */                                                                               
        return usLen;
    }
    if ((~0 == uiCodePar[0]) || (~0 == uiCodePar[1]) || (0 == (uiCodePar[0] & 0xFF))) { 
                                                                        /*  ԭ�г�����Ч                */
        if ((__GuiCodeInfo[codeId] & 0x800000FF) != (uiTmp & 0x800000FF)) {/*  ��������δ����              */         
            return usLen;
        }         
        memcpy (uiCodePar, __GuiCodeInfo, 12);
        tm_htonl(uiCodePar[codeVer]);
        tm_htonl(uiCodePar[codeLen]);
        tm_htonl(uiCodePar[codeId]);
        
        //uiCodePar[2] &=  
        
        if (__GuiChanle == ucChanle) {                                  /*  ������ͨ��������ͨ������    */  	        
            return usLen;
        }
        
        if (OS_TASK_RESUME_PRIO != OSTaskResume(TASK1_PRIO)) {          /*  �������������������        */	           
            return usLen;
        }
        
        if (__DLM_CODE_ID == (uiTmp & 0x800000FF)) {                    /*  �������ع������            */            
            __SpspTmp[0].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC0;     /*  ���������������Ԥ���ַ    */                
        } else if (__USR_CODE_ID == (uiTmp & 0x800000FF)){              /*  �������������              */            
            __SpspTmp[0].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC1;     /*  Ӧ�ó�����������Ԥ���ַ    */                
        } else {                                                        /*  �����������ܴ���            */
            __SpspTmp[0].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC3;     /*  ������������������Ԥ���ַ  */
        } 
        __SpspTmp[0].pucBufTmp  = __GucBufTmp[0];                       /*  �������ݻ���                */
        __SpspTmp[0].uiChn      = ucChanle;                             /*  ����ͨ��                    */    
        __SpspTmp[0].uiXpoint   = 0;
        __SpspTmp[0].uiYpoint   = 24;
                  
                
        __SpspTmp[0].uiCodePar[0] = uiCodePar[0];
        __SpspTmp[0].uiCodePar[1] = uiCodePar[1];
        __SpspTmp[0].uiCodePar[2] = uiCodePar[2]; 
        __SpspTmp[0].ucIsCodePro  = 0; 
           
        GUI_RectangleFill(0, 24, 127, 63, 0);
        if (ucChanle == __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07]) {
            if (__DLM_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 24, 0, "���ڼ����������");
            } else if (__USR_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 24, 0, "���ڼ���Ӧ�ó���");
            }
        } else if (ucChanle == __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_RIGHT & 0x07]) {
            if (__DLM_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 24, 0, "���ڼ����������");
            } else if (__USR_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 24, 0, "���ڼ���Ӧ�ó���");
            }
        } else {
            GUI_Printf(0, 24, 0, "��������ʼ������");
        }
        OSSchedLock();
        OSTaskCreateExt(Pro_SeverTask,
                        (void *)&__SpspTmp[0],
                        &TASK1_STACK[TASK1_STACK_SIZE-1],
                        TASK1_PRIO,
                        TASK1_ID,
                        &TASK1_STACK[0],
                        TASK1_STACK_SIZE,
                        (void *)0,
                        OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
         OSSchedUnlock();
    } else if ((__GuiCodeInfo[0] != 0x00000000) && 
               (__GuiCodeInfo[0] != 0xFFFFFFFF)) {                    /*  ����������                  */
        GUI_Printf(0, 24, 0, "�����������Եȣ�");     
        return usLen;         
    } else {                                                            /*  ����Ӧ�ó�����Ч            */
        INT8U ucId = (ucChanle == __GucTmDrivChn[(__PORT_DEF_LEFT >> 3) & 0x07][__PORT_DEF_LEFT & 0x07]) ? 0 : 1;
       
        tm_htonl(uiCodePar[0]);
        tm_htonl(uiCodePar[1]);
        tm_htonl(uiCodePar[2]);
        if (__USR_CODE_ID == (uiTmp & 0x800000FF)) {
            __SpspTmp[ucId].ucIsCodePro = 3;
            __GbParaFlag = TRUE;
        } else {
            __SpspTmp[ucId].ucIsCodePro = 2;
        }
        if (ucTaskOn & 0x03) {
            ;
        } else {
            GUI_ClearSCR();
        }
        if (0 == ucId) {                                                /*  ���ڼܳ��������            */                                                                                    
            if (__DLM_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 00, 0, "���ڼ����������");
            } else if (__USR_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 00, 0, "���ڼ���Ӧ�ó���");
            }
        } else {                                                        /*  ���ڼܳ��������            */
            if (__DLM_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 32, 0, "���ڼ����������");
            } else if (__USR_CODE_ID == (uiTmp & 0xFF)) {
                GUI_Printf(0, 32, 0, "���ڼ���Ӧ�ó���");
            }
        }
        __SpspTmp[ucId].pucBufTmp  = __GucBufTmp[ucId];                 /*  Ӧ�ó�����������Ԥ���ַ    */    
        __SpspTmp[ucId].uiChn      = ucChanle;   
        __SpspTmp[ucId].uiXpoint   = 0;
        __SpspTmp[ucId].uiYpoint   = 32 * ucId;
        
        __SpspTmp[ucId].uiCodePar[0] = uiCodePar[0];
        __SpspTmp[ucId].uiCodePar[1] = uiCodePar[1];
        __SpspTmp[ucId].uiCodePar[2] = uiCodePar[2];           
        
        if (__DLM_CODE_ID == (uiTmp & 0x800000FF)) {                    /*  �������ع������            */
            __SpspTmp[ucId].pucSrcAddr = (INT8U*)__DLM_CODES_SRC;       /*  ���������������Ԥ���ַ    */                
        } else if (__USR_CODE_ID == (uiTmp & 0x800000FF)) {             /*  �������������              */
            __SpspTmp[ucId].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC2;  /*  Ӧ�ó�����������Ԥ���ַ    */                
        } else {                                                        /*  �����������ܴ���            */
            __SpspTmp[ucId].pucSrcAddr = (INT8U*)__UPGRADE_CODES_SRC3;  /*  ������������������Ԥ���ַ  */            
        }    
        __GucIsSrc = TRUE;
        /*
         *	�������������
         */
        OSSchedLock();
        
        //tpUpgradeBeginDel();
        __GucUpgradeOk = 0xAA;                                
        if (0 == ucId) {
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
        OSSchedUnlock();
    }
    return usLen;
}
/*********************************************************************************************************
  DEL FILE
*********************************************************************************************************/
