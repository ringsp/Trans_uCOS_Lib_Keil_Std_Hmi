/****************************************Copyright (c)****************************************************
**                 
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               uCOS_II_add.c
** Latest modified Date:    2013-09-26
** Latest Version:          1.0
** Descriptions:            OS�������ܺ�������
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2013-09-26
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

#ifndef  OS_MASTER_FILE
#include "includes.h"
#endif

extern void (*pOSTaskCreateHook)(OS_TCB *);                             /*  ���������Ӻ���ָ��        */
extern void (*pOSTaskDelHook)(OS_TCB *);                                /*  ɾ�������Ӻ���ָ��        */
extern void (*pOSTaskStatHook)(void);                                   /*  ͳ�������Ӻ���ָ��        */
extern void (*pOSTimeTickHook)(void);                                   /*  ϵͳʱ�ӹ��Ӻ���ָ��        */
extern void (*pOSTaskIdleHook)(void);                                   /*  ���������Ӻ���ָ��        */

/*********************************************************************************************************
** Function name:           OSPrioGet
** Descriptions:            ���ص�ǰ��������ȼ�
** input parameters:        none
** ouput parameters: 		none
** Returned value:          ���ȼ�
*********************************************************************************************************/
INT8U OSPrioGet(void)
{
    return OSPrioCur;
}
/*********************************************************************************************************
** Function name:           OSCPUUsageGet
** Descriptions:            ���ص�ǰCPUռ����
** input parameters:        none
** ouput parameters: 		none
** Returned value:          CPUռ����
*********************************************************************************************************/
INT8S OSCPUUsageGet(void)
{
    return OSCPUUsage;
}

/*********************************************************************************************************
** Function name:           OSIntNestingGet
** Descriptions:            �����ж�Ƕ�ײ��
** input parameters:        none
** ouput parameters: 		none
** Returned value:          OSIntNesting
*********************************************************************************************************/
INT8U OSIntNestingGet(void)
{
    return OSIntNesting;    
}
/*********************************************************************************************************
** Function name:           OSTCBCurGet
** Descriptions:            ���ص�ǰ����Ŀ��ƿ�
** input parameters:        none
** ouput parameters: 		none
** Returned value:          ������ƿ�
*********************************************************************************************************/
OS_TCB *OSTCBCurGet(void)
{
    return OSTCBCur;
}





/*********************************************************************************************************
** Function name:           OSTCBPrioTblGet
** Descriptions:            �����������ȼ��б�
** input parameters:        none
** Returned value:          �������ȼ��б�
*********************************************************************************************************/
OS_TCB **OSTCBPrioTblGet(void)
{
    return OSTCBPrioTbl;
}

/*********************************************************************************************************
** Function name:           OSTaskCreateHookSet
** Descriptions:            �������񴴽����Ӻ���
** input parameters:        pfuncTaskIdleHook: ���񴴽����Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
void OSTaskCreateHookSet(void (* pfuncOSTaskCreateHook)(OS_TCB *ptcb))
{
    /*
     *  ��������
     */
    if (NULL == pfuncOSTaskCreateHook) {
        return;
    }
    pOSTaskCreateHook = pfuncOSTaskCreateHook;
}

/*********************************************************************************************************
** Function name:           OSTaskDelHookSet
** Descriptions:            ��������ɾ�����Ӻ���
** input parameters:        pfuncTaskIdleHook: ����ɾ�����Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
void OSTaskDelHookSet(void (* pfuncOSTaskDelHook)(OS_TCB *ptcb))
{
    /*
     *  ��������
     */
    if (NULL == pfuncOSTaskDelHook) {
        return;
    }
    pOSTaskDelHook = pfuncOSTaskDelHook;
}

/*********************************************************************************************************
** Function name:           OSTaskStatHookSet
** Descriptions:            ��������״̬���Ӻ���
** input parameters:        pfuncTaskIdleHook: ����״̬���Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
void OSTaskStatHookSet(void (* pfuncTaskStatHook)(void))
{
    /*
     *  ��������
     */
    if (NULL == pfuncTaskStatHook) {
        return;
    }
    pOSTaskStatHook = pfuncTaskStatHook;    
}

/*********************************************************************************************************
** Function name:           OSTimeTickHookSet
** Descriptions:            ����ʱ�ӽ��Ĺ��Ӻ���
** input parameters:        pfuncTimeTickHook: ʱ�ӽ��Ĺ��Ӻ���
** Returned value:          none
*********************************************************************************************************/
void OSTimeTickHookSet(void (* pfuncTimeTickHook)(void))
{
    /*
     *  ��������
     */
    if (NULL == pfuncTimeTickHook) {
        return;
    }
    pOSTimeTickHook = pfuncTimeTickHook;    
}

/*********************************************************************************************************
** Function name:           OSTaskIdleHookSet
** Descriptions:            ���ÿ��������Ӻ���
** input parameters:        pfuncTaskIdleHook: ���������Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
void OSTaskIdleHookSet(void (* pfuncTaskIdleHook)(void))
{
    /*
     *  ��������
     */
    if (NULL == pfuncTaskIdleHook) {
        return;
    }
    pOSTaskIdleHook = pfuncTaskIdleHook;  
}

/*********************************************************************************************************
** Function name:           OSTimeLag
** Descriptions:            �ȴ�ʱ����
** input parameters:        usTicks: ���ϴε��ñ�����֮������ʱ�ӽ�����Ŀ
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
void  OSTimeLag(INT16U usTicks)
{
    /*
     *  ��������
     */
    if (0 == usTicks) {
        return;
    }

    OS_ENTER_CRITICAL();                                                /*  ���ж�                      */

    if ((OSTime - OSTCBCur->OSTCBTimeLag) >= usTicks) {
        OSTCBCur->OSTCBTimeLag = OSTime; 
    } else {
        OSTCBCur->OSTCBTimeLag += usTicks;
        if ((OSRdyTbl[OSTCBCur->OSTCBY] &= ~OSTCBCur->OSTCBBitX) == 0) {   
            OSRdyGrp &= ~OSTCBCur->OSTCBBitY;         
        }
        OSTCBCur->OSTCBDly = OSTCBCur->OSTCBTimeLag - OSTime;
        OS_EXIT_CRITICAL();                                             /*  ���ж�                      */
        OS_Sched();
        return;
    } 
    OS_EXIT_CRITICAL();                                                 /*  ���ж�                      */
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
