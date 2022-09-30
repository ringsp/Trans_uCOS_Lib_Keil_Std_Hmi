/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               sys_tools.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.00
** Descriptions:            ϵͳ���ߺ���
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
#ifndef __SYS_TOOLS_H
#define __SYS_TOOLS_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  VIC������Ϣ����
*********************************************************************************************************/
struct vic_irq_cfg {
    INT32U      ulChannel;                                              /*  ͨ��                        */
    INT32U      ulPri;                                                  /*  ���ȼ�                      */
    INT32U      ulFunctionAddr;                                         /*  ISR��ַ                     */
    INT32U      ulEnable;                                               /*  ʹ�ܱ�ʶ                    */
};

typedef struct vic_irq_cfg  VIC_IRQ_CFG;
typedef struct vic_irq_cfg* PVIC_IRQ_CFG;

/*********************************************************************************************************
  ����ֵ����
*********************************************************************************************************/
#define SYS_OK                  0                                       /*  �����ɹ�                    */
#define SYS_NOT_OK              1                                       /*  ����ʧ��                    */
#define SYS_PARA_ERR            2                                       /*  ��������                    */
#define SYS_NO_MEMARY           3                                       /*  �ڴ治��                    */
#define SYS_TIME_OUT            4                                       /*  ��ʱ                        */

/*********************************************************************************************************
  64λ������ض���
*********************************************************************************************************/
#define sysLlAdd(a, b, c) a = (INT64S)(b) + (INT64S)(c)                 /*  64λ�з��żӷ�a=b+c         */
#define sysLlSub(a, b, c) a = (INT64S)(b) - (INT64S)(c)                 /*  64λ�з��ż���a=b-c         */
#define sysLlMul(a, b, c) a = (INT64S)(b) * (INT64S)(c)                 /*  64λ�з��ų˷�a=b*c         */
#define sysLlDiv(a, b, c) a = (INT64S)(b) / (INT64S)(c)                 /*  64λ�з��ų���a=b/c         */
#define sysLlMod(a, b, c) a = (INT64S)(b) % (INT64S)(c)                 /*  64λ�з��ų���a=b/c         */
#define sysLlSet(a, b)    a = (INT64S)(b)                               /*  64λ�з��Ÿ�ֵ              */
#define sysLlIsLess(a, b) ((INT64S)(a) < (INT64S)(b))                   /*  64λ�з���С���ж�          */
#define sysLlSet32(a, b)  a = (INT32U)(b)                               /*  64λ�з��Ÿ�ֵ��32λ�޷�����*/
#define sysLlSet32s(a, b) a = (INT32S)(b)                               /*  64λ�з��Ÿ�ֵ��32λ�з�����*/

/*********************************************************************************************************
** Function name:           sysIfInit
** Descriptions:            �ӿڳ�ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIfInit (void);

/*********************************************************************************************************
** Function name:           __sysIfInit
** Descriptions:            �ӿڳ�ʼ��
** input parameters:        pvHeap:        �ѵ�ַ
**                          ulHeapSize:    �Ѵ�С
**                          pvDmaHeap:     DMA�ѵ�ַ
**                          ulDmaHeapSize: DMA�ѵ�ַ��С
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S __sysIfInit(void *pvHeap, INT32U ulHeapSize, void *pvDrivHooks, INT32U ulHooksSize);

/*********************************************************************************************************
** Function name:           sysHeapMalloc
** Descriptions:            �ѷ����ڴ�
** input parameters:        ulSize: �ڴ��С
** output parameters:       none
** Returned value:          �ڴ��ַ,NULLΪ���ɹ�
*********************************************************************************************************/
extern void *sysHeapMalloc (INT32U ulSize);

/*********************************************************************************************************
** Function name:           sysHeapFree
** Descriptions:            ���ͷ��ڴ�
** input parameters:        pvPrt:  Ҫ�ͷŵ��ڴ�
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysHeapFree (void *pvPrt);

/*********************************************************************************************************
** Function name:           sysIrqDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysIrqDisable (void);

/*********************************************************************************************************
** Function name:           sysIrqEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysIrqEnable (void);

/*********************************************************************************************************
** Function name:           sysFiqDisable
** Descriptions:            �ر�ȫ��FIQ�ж�
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysFiqDisable (void);

/*********************************************************************************************************
** Function name:           sysFiqEnable
** Descriptions:            ��ȫ��FIQ�ж�
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysFiqEnable (void);

/*********************************************************************************************************
** Function name:           sysChangeToSysMode
** Descriptions:            �����л���ϵͳģʽ 
** input parameters:        none
**                          
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysChangeToSysMode (void);

/*********************************************************************************************************
** Function name:           sysChangeToUsrMode
** Descriptions:            �����л����û�ģʽ 
** input parameters:        none
**                          
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysChangeToUsrMode (void);

/*********************************************************************************************************
** Function name:           sysMsgCreate
** Descriptions:            ������Ϣͨ��
** input parameters:        ulMsgNum:  ���Ի�����Ϣ��Ŀ
**                          ulMsgSize: ��Ϣ��С
** output parameters:       none
** Returned value:          ��Ϣͨ����ʶ
**                          0: ���ɹ�
*********************************************************************************************************/
extern unsigned long sysMsgCreate (INT32S ulMsgNum, INT32U ulMsgSize);

/*********************************************************************************************************
** Function name:           sysMsgDel
** Descriptions:            ɾ����Ϣͨ��
** input parameters:        ulMsg:  sysMsgCreate����ֵ
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysMsgDel (unsigned long ulMsg);

/*********************************************************************************************************
** Function name:           sysMsgAccept
** Descriptions:            �޵ȴ������Ϣ
** input parameters:        ulMsg:  sysMsgCreate����ֵ
** output parameters:       pucMsg: �����õ���Ϣ
** Returned value:          SYS_OK:  �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysMsgAccept(unsigned long ulMsg, INT8U *pucMsgRt);

/*********************************************************************************************************
** Function name:           sysMsgPend
** Descriptions:            �ȴ���Ϣ
** input parameters:        ulMsg:  sysMsgCreate����ֵ
**                          ulDly: ��ȴ�ʱ��,����Ϊ��λ
** output parameters:       pucMsgRt: �����õ���Ϣ
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysMsgPend(unsigned long ulMsg, INT8U *pucMsgRt, INT32U ulDly);

/*********************************************************************************************************
** Function name:           sysMsgPost
** Descriptions:            ������Ϣ
** input parameters:        ulMsg:      sysMsgCreate����ֵ
**                          pucMsgSend: Ҫ���͵���Ϣ
**                          ucMod:      ����ģʽ,һ��Ϊ0
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S sysMsgPost(unsigned long ulMsg, INT8U *pucMsgSend, INT8U ucMod);

/*********************************************************************************************************
** Function name:           vicIrqFuncSet
** Descriptions:            �����жϷ������
** input parameters:        uiChannel:  �ж�ͨ����
**                          uiPrio:     �ж����ȼ�
**                          ulFunction: �жϷ�������ַ
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicIrqFuncSet(unsigned int uiChannel, unsigned int uiPrio, unsigned long ulFunction);

/*********************************************************************************************************
** Function name:           vicIrqFuncClr
** Descriptions:            ����жϷ������
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicIrqFuncClr(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicIrqEnable
** Descriptions:            ����ָ��ͨ���ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicIrqEnable(unsigned int uiChannel);
/*********************************************************************************************************
** Function name:           vicIrqDisable
** Descriptions:            ��ָֹ��ͨ���ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicIrqDisable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicIrqStatusGet
** Descriptions:            ��ȡ��ѡ������ж�ͨ���š����ȼ����жϷ�������ַ���ж�ʹ��״̬
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       pvicInfo:   ������Ϣ
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicIrqStatusGet (unsigned int uiChannel, PVIC_IRQ_CFG pvicInfo);

/*********************************************************************************************************
** Function name:           vicFiqEnable
** Descriptions:            ����ָ��ͨ�������ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicFiqEnable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicFiqDisable
** Descriptions:            ��ָֹ��ͨ�������ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicFiqDisable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicDefIrqFuncSet
** Descriptions:            ���÷������жϷ������
** input parameters:        ulFunction: �жϷ�������ַ
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicDefIrqFuncSet(unsigned long ulFunction);

/*********************************************************************************************************
** Function name:           vicDefIrqEnable
** Descriptions:            ����ָ��ͨ���������ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicDefIrqEnable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicDefIrqDisable
** Descriptions:            ��ָֹ��ͨ���������ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicDefIrqDisable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicSoftIntEnable
** Descriptions:            ʹ����ѡ�ж�ͨ���ŵ��������ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicSoftIntEnable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicSoftIntDisable
** Descriptions:            ��ֹ��ѡ�ж�ͨ���ŵ��������ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_tools.h
*********************************************************************************************************/
extern INT32S vicSoftIntDisable(unsigned int uiChannel);


#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __SYS_TOOLS_H               */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
