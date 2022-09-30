/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               uCOS_II_add.h
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
#ifndef __uCOS_II_ADD_H 
#define __uCOS_II_ADD_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
** Function name:           OSPrioGet
** Descriptions:            ���ص�ǰ��������ȼ�
** input parameters:        none
** ouput parameters: 		none
** Returned value:          ���ȼ�
*********************************************************************************************************/
extern INT8U OSPrioGet(void);

/*********************************************************************************************************
** Function name:           OSTCBCurGet
** Descriptions:            ���ص�ǰ����Ŀ��ƿ�
** input parameters:        none
** ouput parameters: 		none
** Returned value:          ������ƿ�
*********************************************************************************************************/
extern OS_TCB *OSTCBCurGet(void);

/*********************************************************************************************************
** Function name:           OSCPUUsageGet
** Descriptions:            ���ص�ǰCPUռ����
** input parameters:        none
** ouput parameters: 		none
** Returned value:          CPUռ����
*********************************************************************************************************/
extern INT8S OSCPUUsageGet(void);

/*********************************************************************************************************
** Function name:           OSIntNestingGet
** Descriptions:            �����ж�Ƕ�ײ��
** input parameters:        none
** ouput parameters: 		none
** Returned value:          OSIntNesting
*********************************************************************************************************/
extern INT8U OSIntNestingGet(void);

/*********************************************************************************************************
** Function name:           OSTCBPrioTblGet
** Descriptions:            �����������ȼ��б�
** input parameters:        none
** Returned value:          �������ȼ��б�
*********************************************************************************************************/
extern OS_TCB **OSTCBPrioTblGet(void);

/*********************************************************************************************************
** Function name:           OSTaskCreateHookSet
** Descriptions:            �������񴴽����Ӻ���
** input parameters:        pfucTaskIdleHook: ���񴴽����Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
extern void OSTaskCreateHookSet(void (* pfucOSTaskCreateHook)(OS_TCB *ptcb));

/*********************************************************************************************************
** Function name:           OSTaskDelHookSet
** Descriptions:            ��������ɾ�����Ӻ���
** input parameters:        pfucTaskIdleHook: ����ɾ�����Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
extern void OSTaskDelHookSet(void (* pfucOSTaskDelHook)(OS_TCB *ptcb));

/*********************************************************************************************************
** Function name:           OSTaskStatHookSet
** Descriptions:            ��������״̬���Ӻ���
** input parameters:        pfucTaskIdleHook: ����״̬���Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
extern void OSTaskStatHookSet(void (* pfucTaskStatHook)(void));

/*********************************************************************************************************
** Function name:           OSTimeTickHookSet
** Descriptions:            ����ʱ�ӽ��Ĺ��Ӻ���
** input parameters:        pfucTimeTickHook: ʱ�ӽ��Ĺ��Ӻ���
** Returned value:          none
*********************************************************************************************************/
extern void OSTimeTickHookSet(void (* pfucTimeTickHook)(void));

/*********************************************************************************************************
** Function name:           OSTaskIdleHookSet
** Descriptions:            ���ÿ��������Ӻ���
** input parameters:        pfucTaskIdleHook: ���������Ӻ���
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
extern void OSTaskIdleHookSet(void (* pfucTaskIdleHook)(void));

/*********************************************************************************************************
** Function name:           OSTimeLag
** Descriptions:            �ȴ�ʱ����
** input parameters:        usTicks: ���ϴε��ñ�����֮������ʱ�ӽ�����Ŀ
** ouput parameters: 		none
** Returned value:          none
*********************************************************************************************************/
extern void  OSTimeLag(INT16U usTicks);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __uCOS_II_ADD_H             */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
