/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               sys_if.h
** Latest modified Date:    2009-07-23
** Latest Version:          1.00
** Descriptions:            �����ӿں���,��������Ȩģʽ����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Chenmingji
** Created date:            2009-07-23
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
#ifndef __SYS_IF_H
#define __SYS_IF_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  ����ֵ����
*********************************************************************************************************/
#define SYS_OK                  0                                       /*  �����ɹ�                    */
#define SYS_NOT_OK              1                                       /*  ����ʧ��                    */
#define SYS_PARA_ERR            2                                       /*  ��������                    */
#define SYS_FIND_NO_DEVICE      3                                       /*  û�з����豸                */
#define SYS_NODE_FULL           4                                       /*  �ڵ�����                    */
#define SYS_NO_FIND_FUNCTION    5                                       /*  û�з���ָ������            */
#define SYS_DRIVER_FULL         6                                       /*  �����ڵ�����                */
#define SYS_NODE_EXIST          7                                       /*  �ڵ��Ѵ���                  */
#define SYS_DRIVER_EXIST        7                                       /*  ���������Ѱ�װ              */
#define SYS_FIND_NO_DRIVER      8                                       /*  û�з���ָ������            */
#define SYS_NO_PORT             9                                       /*  û���ҵ��˿�                */
#define SYS_NO_MEMORY           10                                      /*  �ڴ治��                    */
#define SYS_TIME_OUT            11                                      /*  ��ʱ                        */
#define SYS_PACKET_ERR          12                                      /*  ����У�����                */
#define SYS_NO_NODE             13                                      /*  δ�ҵ���Ӧ�ڵ�              */
#define SYS_NO_FIND_OBJECT      16                                      /*  û�з��ֶ���                */
#define SYS_QUEUE_FULL          17
#define SYS_QUEUE_EMPTY         18


/*********************************************************************************************************
  64λ������ض���
*********************************************************************************************************/
typedef long long   INT64S;                                             /*  64λ�з�����                */

#define sysLlAdd(a, b, c) a = (INT64S)(b) + (INT64S)(c)                  /*  64λ�з��żӷ�a=b+c         */
#define sysLlSub(a, b, c) a = (INT64S)(b) - (INT64S)(c)                  /*  64λ�з��ż���a=b-c         */
#define sysLlMul(a, b, c) a = (INT64S)(b) * (INT64S)(c)                  /*  64λ�з��ų˷�a=b*c         */
#define sysLlDiv(a, b, c) a = (INT64S)(b) / (INT64S)(c)                  /*  64λ�з��ų���a=b/c         */
#define sysLlMod(a, b, c) a = (INT64S)(b) % (INT64S)(c)                  /*  64λ�з��ų���a=b/c         */
#define sysLlSet(a, b)    a = (INT64S)(b)                                /*  64λ�з��Ÿ�ֵ              */
#define sysLlIsLess(a, b) ((INT64S)(a) < (INT64S)(b))                    /*  64λ�з���С���ж�          */
#define sysLlSet32(a, b)  a = (INT32U)(b)                                /*  64λ�з��Ÿ�ֵ��32λ�޷�����*/
#define sysLlSet32s(a, b) a = (INT32S)(b)                                /*  64λ�з��Ÿ�ֵ��32λ�з�����*/
/*********************************************************************************************************
  �ֽ�˳��任
*********************************************************************************************************/
#ifndef sys_ntohl
#define sys_ntohl(x) x = (INT32U)(((INT8U *)&x)[0] << 24 | \
                                 ((INT8U *)&x)[1] << 16 | \
                                 ((INT8U *)&x)[2] << 8  | \
                                 ((INT8U *)&x)[3] << 0)
#endif                                                                  /*  aw_ntohl                    */

#ifndef sys_htonl
#define sys_htonl(x) x = (INT32U)(((INT8U *)&x)[0] << 24 | \
                                 ((INT8U *)&x)[1] << 16 | \
                                 ((INT8U *)&x)[2] << 8  | \
                                 ((INT8U *)&x)[3] << 0)
#endif                                                                  /*  aw_htonl                    */

#ifndef sys_ntohs
#define sys_ntohs(x) x = (INT16U)(((INT8U *)&x)[0] << 8  | \
                                 ((INT8U *)&x)[1] << 0)
#endif                                                                  /*  aw_ntohs                    */

#ifndef sys_htons
#define sys_htons(x) x = (INT16U)(((INT8U *)&x)[0] << 8  | \
                                 ((INT8U *)&x)[1] << 0)
#endif                                                                  /*  aw_htons                    */

/*********************************************************************************************************
  ��λģʽ
*********************************************************************************************************/
#define SYS_POWER_RESET      0                                           /*  �ϵ縴λ                    */
#define SYS_HARD_RESET       1                                           /*  Ӳ����λ                    */
#define SYS_SOFT_RESET       2                                           /*  �����λ                    */
/*********************************************************************************************************
** Function name:           sysInit
** Descriptions:            ϵͳ������ʼ��
** input parameters:        uiFosc:     ϵͳ�ⲿʱ��
**                          uiFcclk:    ϵͳ�ں�ʱ��
**                          uiFcco:     ��Ƶʱ��
**                          uiFpclk:    ����ʱ��
**                          uiOsticks:  ϵͳ����
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
extern void sysInit (INT32U uiFosc, INT32U uiFcclk, INT32U uiFcco, INT32U uiFpclk, INT32U uiOsticks);
/*********************************************************************************************************
** Function name:           sysIfInit
** Descriptions:            �ӿڳ�ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIfInit(void);


/*********************************************************************************************************
** Function name:           sysIrqDisable
** Descriptions:            ��ֹ�ж�
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIrqDisable(void);

/*********************************************************************************************************
** Function name:           sysIrqEnable
** Descriptions:            �����ж�
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIrqEnable(void);
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
** Function name:           sysIsrSet
** Descriptions:            �����жϷ������
** input parameters:        uiChannel:  �ж�ͨ����
**                          ulFunction: �жϷ�������ַ
**                          uiPrio:     �ж����ȼ�
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIsrSet(unsigned int uiChannel, unsigned long ulFunction, unsigned int uiPrio);

/*********************************************************************************************************
** Function name:           sysIsrClr
** Descriptions:            ����жϷ������
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIsrClr(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           sysIsrDisable
** Descriptions:            ��ָֹ���ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIsrDisable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           sysIsrEnable
** Descriptions:            ����ָ���ж�
** input parameters:        uiChannel:  �ж�ͨ����
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysIsrEnable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           sysHeapMalloc
** Descriptions:            �ѷ����ڴ�
** input parameters:        ulSize: �ڴ��С
** output parameters:       none
** Returned value:          �ڴ��ַ,NULLΪ���ɹ�
*********************************************************************************************************/
extern void *sysHeapMalloc(INT32U ulSize);

/*********************************************************************************************************
** Function name:           sysHeapMallocAlign
** Descriptions:            �ѷ����ڴ�
** input parameters:        ulSize:         �ڴ��С
**                          uiAlign:        �����ֽ���
** output parameters:       none
** Returned value:          �ڴ��ַ,NULLΪ���ɹ�
** Created by:              Chenmingji
** Created Date:            2009-07-23
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
extern void *sysHeapMallocAlign (INT32U ulSize, INT32U uiAlign);

/*********************************************************************************************************
** Function name:           sysHeapFree
** Descriptions:            ���ͷ��ڴ�
** input parameters:        pvPrt: Ҫ�ͷŵ��ڴ�
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysHeapFree(void *pvPrt);

/*********************************************************************************************************
** Function name:           sysThreadCreate
** Descriptions:            �����߳�
** input parameters:        pvThreedMain: �߳�������
**                          pvArg:        �߳����������
**                          uiPrio:       �߳����ȼ�
**                          ulSize:       ��ջ��С
** output parameters:       none
** Returned value:          �߳�ID,0Ϊ���ɹ�
*********************************************************************************************************/
extern unsigned long sysThreadCreate(void *pvThreedMain, void *pvArg, unsigned int uiPrio, INT32U ulSize);

/*********************************************************************************************************
** Function name:           sysThreadDel
** Descriptions:            ɾ���߳�
** input parameters:        ulThreadId: �߳�ID
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysThreadDel(unsigned long ulThreadId);

/*********************************************************************************************************
** Function name:           sysThreadSuspendSelf
** Descriptions:            �����߳�����
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysThreadSuspendSelf(void);

/*********************************************************************************************************
** Function name:           sysThreadResume
** Descriptions:            �ָ��߳�
** input parameters:        ulThreadId: �߳�ID
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysThreadResume(unsigned long ulThreadId);

/*********************************************************************************************************
** Function name:           sysThreadGetCurId
** Descriptions:            ��õ�ǰ�߳�ID
** input parameters:        none
** output parameters:       none
** Returned value:          �߳�ID
*********************************************************************************************************/
extern unsigned long sysThreadGetCurId(void);

/*********************************************************************************************************
** Function name:           sysThreadSuspendCheck
** Descriptions:            ����߳��Ƿ�ȷʵ������
** input parameters:        ulThreadId: �߳�ID
** output parameters:       none
** Returned value:          SYS_OK:      ����
**                          -SYS_NOT_OK: δ����
**                          ��������:   ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysThreadSuspendCheck(unsigned long ulThreadId);

/*********************************************************************************************************
** Function name:           sysThreadDelay
** Descriptions:            ��ǰ�߳���ʱ
** input parameters:        ulTimes: �Ժ���Ϊ��λ�ȴ�ʱ��
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysThreadDelay(unsigned long ulTimes);

/*********************************************************************************************************
** Function name:           sysSemCreate
** Descriptions:            �����ź���
** input parameters:        ulCnt:  �ź�����ʼֵ
** output parameters:       none
** Returned value:          �ź�����ʶ
**                          0: ���ɹ�
*********************************************************************************************************/
extern unsigned long sysSemCreate(INT32S ulCnt);

/*********************************************************************************************************
** Function name:           sysSemDel
** Descriptions:            ɾ���ź���
** input parameters:        ulSem: sysSemCreate����ֵ
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysSemDel(unsigned long ulSem);

/*********************************************************************************************************
** Function name:           sysSemAccept
** Descriptions:            �޵ȴ�����ź���
** input parameters:        ulSem: sysSemCreate����ֵ
** output parameters:       none
** Returned value:          >=0:   �ź�����ǰֵ
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysSemAccept(unsigned long ulSem);

/*********************************************************************************************************
** Function name:           sysSemPend
** Descriptions:            �ȴ��ź���
** input parameters:        ulSem: sysSemCreate����ֵ
**                          ulDly: ��ȴ�ʱ��,����Ϊ��λ
** output parameters:       none
** Returned value:          >=0:   �ź�����ǰֵ
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysSemPend(unsigned long ulSem, INT32U ulDly);

/*********************************************************************************************************
** Function name:           sysSemPost
** Descriptions:            ����ָ���ж�
** input parameters:        ulSem: sysSemCreate����ֵ
**                          ucMod: ����ģʽ,һ��Ϊ0
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysSemPost(unsigned long ulSem, INT8U ucMod);

/*********************************************************************************************************
** Function name:           sysMsgCreate
** Descriptions:            ������Ϣͨ��
** input parameters:        ulMsgs:    ���Ի�����Ϣ��Ŀ
**                          ulMsgSize: ��Ϣ��С
** output parameters:       none
** Returned value:          ��Ϣͨ����ʶ
**                          0: ���ɹ�
*********************************************************************************************************/
extern unsigned long sysMsgCreate(INT32S ulMsgs, INT32U ulMsgSize);

/*********************************************************************************************************
** Function name:           sysMsgDel
** Descriptions:            ɾ����Ϣͨ��
** input parameters:        ulMsg:  sysMsgCreate����ֵ
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysMsgDel(unsigned long ulMsg);

/*********************************************************************************************************
** Function name:           sysMsgAccept
** Descriptions:            �޵ȴ������Ϣ
** input parameters:        ulMsg:  sysMsgCreate����ֵ
** output parameters:       pucMsg: �����õ���Ϣ
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysMsgAccept(unsigned long ulMsg, INT8U *pucMsgRt);

/*********************************************************************************************************
** Function name:           sysMsgPend
** Descriptions:            �ȴ���Ϣ
** input parameters:        ulMsg:  sysMsgCreate����ֵ
**                          ulDly: ��ȴ�ʱ��,����Ϊ��λ
** output parameters:       pucMsgRt: �����õ���Ϣ
** Returned value:          SYS_OK: �ɹ�
**                          ����:  ����,����ֵ�ο�sys_if.h
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
**                          ����:  ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S sysMsgPost(unsigned long ulMsg, INT8U *pucMsgSend, INT8U ucMod);




extern INT32U __GuiFpclk, __GuiFosc, __GuiFcclk,__GuiFcco;
extern INT32U __GuiOS_TICKS_PER_SEC;

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __SYS_IF_H                   */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
