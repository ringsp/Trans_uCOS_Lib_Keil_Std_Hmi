/****************************************Copyright (c)****************************************************
**                                  Tongxin Microelectronics Co.,Ltd.
**                                      
**                                   http://www.tsinghuaic.com  
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpIf.c
** Latest modified Date:    2019-01-25
** Latest Version:          2.0
** Descriptions:            AnyPortЭ������մ���ӿ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2014-08-25
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             ����������
** Modified date:           2019-01-25
** Version:                 2.0
** Descriptions:            ������ݽ����̷߳�Ϊ���������̺߳ʹӻ������߳�
**                          ʹ�ڹ��ܶ˿��п��Է�����������
*********************************************************************************************************/
#include    ".\tpCommon.h"   
#include    "main.h"

/*********************************************************************************************************
  ������Ϊ��Э����������ӵı����ͺ�������
*********************************************************************************************************/
static INT32U   __GulTpIfHostMsg;                                       /*  ����������Ϣ����            */
static INT32U   __GulTpIfDeviceMsg;                                     /*  �ӻ�������Ϣ����            */
static void     __tpRemoteHostThread(void *pvData);                     /*  ����������������            */
static void     __tpRemoteDeviceThread(void *pvData);                   /*  �����ӻ���������            */
static OS_STK   TP_HOST_STACK[TP_IF_HOST_THREAD_SIZE];                  /*  �����������������ջ        */
static OS_STK   TP_DEVICE_STACK[TP_IF_THREAD_SIZE];                     /*  ����ӻ����������ջ        */
static OS_STK   TASK_HOST_STACK[TP_POLL_THREAD_SIZE];                   /* ��������host ��ջ            */


extern void __tpHostPollTask(void *pdata);

/*********************************************************************************************************
** Function name:           tpHostInit
** Descriptions:            Э��������ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_if.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
INT32S tpHostInit (void)
{
    INT32S siErr;
    siErr = __tpHostInitEx();
    if (siErr != SYS_OK) {
        return (siErr);
    }
    /*
     *  ����������ѯ����
     */
    if (OSTaskCreate(__tpHostPollTask,
                     (void *)0,
                     &TASK_HOST_STACK[TP_POLL_THREAD_SIZE - 1],
                     TP_POLL_THREAD_PRIO) != OS_NO_ERR) {
        
        return (-SYS_NOT_OK);
    }    
    return SYS_OK;
}


/*********************************************************************************************************
** Function name:           tpIfInit
** Descriptions:            Э�鴦��ӿڳ�ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S tpIfInit (void)
{
    __GulTpIfHostMsg    = sysMsgCreate(TP_IF_Q_SIZE, sizeof(TP_IF_MSG));
    __GulTpIfDeviceMsg  = sysMsgCreate(TP_IF_Q_SIZE, sizeof(TP_IF_MSG));
    if ((__GulTpIfHostMsg == 0)||(__GulTpIfDeviceMsg == 0)) {
        return (-SYS_NO_MEMORY);
    }
    
    if (OSTaskCreate(__tpRemoteHostThread,
                     (void *)0,
                     &TP_HOST_STACK[TP_IF_HOST_THREAD_SIZE - 1],
                     TP_IF_HOST_THREAD_PRIO) != OS_NO_ERR) {
        sysMsgDel(__GulTpIfHostMsg);
        __GulTpIfHostMsg = 0;
        sysMsgDel(__GulTpIfDeviceMsg);
        __GulTpIfDeviceMsg = 0;
        return (-SYS_PARA_ERR);
    }   
    if (OSTaskCreate(__tpRemoteDeviceThread,
                     (void*)0,
                     &TP_DEVICE_STACK[TP_IF_THREAD_SIZE - 1],
                     TP_IF_THREAD_PRIO) != OS_NO_ERR)
    {
        sysMsgDel(__GulTpIfHostMsg);
        __GulTpIfHostMsg = 0;
        sysMsgDel(__GulTpIfDeviceMsg);
        __GulTpIfDeviceMsg = 0;
        return (-SYS_PARA_ERR);
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           __tpRemoteHostThread
** Descriptions:            ����Э����մ��������߳�
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
static void __tpRemoteHostThread (void *pvData)
{
    TP_IF_MSG imMsg;                                                    /*  ��Ϣ                        */

    pvData = pvData;
    while (1) {        
        if (sysMsgPend(__GulTpIfHostMsg, (INT8U *)&imMsg, 0) < 0) {
            continue;
        } 

        /*
         *  ֡У��
         */
        if (tpPacketCheck(imMsg.ptdibDriverInfo, imMsg.ptphPacketData) == 0) {
            tpHostReceive(imMsg.ptdibDriverInfo, imMsg.ptphPacketData);
			//ADD_COMM_ONCE();
        }
        sysHeapFree(imMsg.ptphPacketData);
    }
}
/*********************************************************************************************************
** Function name:           __tpRemoteHostThread
** Descriptions:            �ӻ�Э����մ��������߳�
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
static void __tpRemoteDeviceThread(void * pvData)
{
    TP_IF_MSG imMsg;                                                    /*  ��Ϣ                        */

    pvData = pvData;
    while (1) {        
        if (sysMsgPend(__GulTpIfDeviceMsg, (INT8U *)&imMsg, 0) < 0) {
            continue;
        }
        /*
         *  ֡У��
         */
        if (tpPacketCheck(imMsg.ptdibDriverInfo, imMsg.ptphPacketData) == 0) {
            tpDeviceReceive(imMsg.ptdibDriverInfo, imMsg.ptphPacketData);
        }
        sysHeapFree(imMsg.ptphPacketData);
    }

}
/*********************************************************************************************************
** Function name:           tpRemotePacketReceive
** Descriptions:            Э����յ�����֡
** input parameters:        pdiDriverInfo:      ������Ϣ
**                          ptphPacketData:     ����֡   
** output parameters:       none
** Returned value:          SYS_OK:             �ɹ�
**                          ����:               ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S tpRemotePacketReceive(TP_DRV_INFO_BASE * ptdibDriverInfo, TP_PACKET_HEAD *ptphPacketData)
{
    TP_IF_MSG imMsg;                                                    /*  ��Ϣ                        */
    imMsg.ptdibDriverInfo   = ptdibDriverInfo;
    imMsg.ptphPacketData    = ptphPacketData;
    
    if ((ptphPacketData->tpHeadBits.Bits.uiRF < TP_RREAD_FLG) ||
        (ptphPacketData->tpHeadBits.Bits.uiRsv == 1)) {
        if (sysMsgPost(__GulTpIfDeviceMsg, (INT8U *)&imMsg, 0) < 0) {
            sysHeapFree(ptphPacketData);
            return (-SYS_PARA_ERR);
        }        
    } else {
        if (sysMsgPost(__GulTpIfHostMsg, (INT8U *)&imMsg, 0) < 0) {
            sysHeapFree(ptphPacketData);
            return (-SYS_PARA_ERR);
        }
    }    
    return SYS_OK;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

