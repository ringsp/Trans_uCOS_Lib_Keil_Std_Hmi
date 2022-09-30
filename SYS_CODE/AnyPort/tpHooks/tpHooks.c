/****************************************Copyright (c)****************************************************
**                            
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpHooks.c
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            ϵͳ�ӿڲ㺯����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2014-08-25
** Version:                 1.0
** Descriptions:            ��ʼ�汾
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#include    "..\tpCommon.h"

    /*
     *  �ⲿ����ʹ�ñ���
     */


    /*
     *  �ڲ�ʹ�ñ���
     */


    /*
     *  ��������
     */

/*********************************************************************************************************
** Function name:           tpOSQueueCreate
** Descriptions:            ���д���
** input parameters:        pv                  ��Ϣ�����ڴ�
**                          uiSize              ��Ϣ�������
** output parameters:       none
** Returned value:          ��Ϣָ��            �ɹ�
**                          NULL                ʧ��
*********************************************************************************************************/
void *tpOSQueueCreate(void *pv, INT32U uiSize)
{
    
    return OSQCreate(pv, uiSize);                                       /*  ������Ϣ����                */
}


/*********************************************************************************************************
** Function name:           tpOSQueueDel
** Descriptions:            ����ɾ��
** input parameters:        pv                  ��Ϣ����
**                          
** output parameters:       pucErr              �������
** Returned value:          NULL                �ɹ�
**                          ��Ϣָ��            ʧ��
*********************************************************************************************************/
void *tpOSQueueDel(void *pv, INT8U *pucErr)
{
    
    return OSQDel(pv, OS_DEL_ALWAYS, pucErr);                           /*  ɾ����Ϣ����                */
}


/*********************************************************************************************************
** Function name:           tpOSQueuePend
** Descriptions:            ���еȴ�
** input parameters:        pv                  ��Ϣ����
**                          uiTimeOut           �ȴ���ʱ����
**                          
** output parameters:       pucErr              ���ش������
** Returned value:          ��Ϣָ��            �ɹ�
**                          
*********************************************************************************************************/
void *tpOSQueuePend(void *pv, INT32U uiTimeOut, INT8U *pucErr)
{
    
    return OSQPend(pv, uiTimeOut, pucErr);
}

/*********************************************************************************************************
** Function name:           OSQueuePost
** Descriptions:            ���еȴ�
** input parameters:        pv                  ��Ϣ����
**                          msg                 ��Ϣָ��
**                          
** output parameters:       none
** Returned value:          OS_NO_ERR       �ɹ�
**                          �ο�ucos_ii.h�������
**                          
*********************************************************************************************************/
INT8U tpOSQueuePost(void *pv, void *msg)
{
    return OSQPost(pv, msg);
}

/*********************************************************************************************************
** Function name:           tpOSSemCreate
** Descriptions:            �ź�������
** input parameters:        usCnt               �ź�����ʼֵ
**                          
**                          
**
**                       
** output parameters:       none
** Returned value:          �ź���ָ��          �ɹ�
**                          NULL                ʧ��
*********************************************************************************************************/
void *tpOSSemCreate(INT16U usCnt)
{
    return OSSemCreate(usCnt);
}

/*********************************************************************************************************
** Function name:           tpOSSemDel
** Descriptions:            �ź���ɾ��
** input parameters:        pSem                �ź���ָ��
**                          
**                          
**                       
** output parameters:       pucErr              ��������ŵ�ַ
**                          �ο�ucos_ii.h�������
** Returned value:          �ź���ָ��          ʧ��
**                          NULL                �ɹ�
*********************************************************************************************************/
void *tpOSSemDel(void *pSem, INT8U *pucErr)
{
    return OSSemDel(pSem, OS_DEL_ALWAYS, pucErr);
}

/*********************************************************************************************************
** Function name:           tpOSSemPend
** Descriptions:            �ź����ȴ�
** input parameters:        pSem            �ź���ָ��
**                          usTimeOut       �ȴ���ʱ����
**                          
**
**                       
** output parameters:       pucErr          ��������ŵ�ַ
**                          �ο�ucos_ii.h�������
** Returned value:          none
**                          
**                          
*********************************************************************************************************/
void tpOSSemPend(void *pSem, INT16U usTimeOut, INT8U *pucErr)
{
    OSSemPend(pSem, usTimeOut, pucErr);
}

/*********************************************************************************************************
** Function name:           tpOSSemPost
** Descriptions:            �ź�������
** input parameters:        pSem            �ź���ָ��
**                          
** output parameters:       none
** Returned value:          OS_NO_ERR       �ɹ�
**                          �ο�ucos_ii.h�������
**                          
*********************************************************************************************************/
INT8U tpOSSemPost(void *pSem)
{
    return OSSemPost(pSem);    
}

/*********************************************************************************************************
** Function name:           tpOSTimeDly
** Descriptions:            ϵͳ��ʱ
** input parameters:        usMsTicks           ��ʱms
**                          
** output parameters:       none
** Returned value:          none                         
*********************************************************************************************************/
void tpOSTimeDly(INT16U usMsTicks)
{
    INT16U usTicks;
    usTicks = (usTicks * __GuiOS_TICKS_PER_SEC + 999) / 1000;
        
    OSTimeDly(usTicks);
}

/*********************************************************************************************************
** Function name:           tpOSHeapMalloc
** Descriptions:            �ѷ����ڴ�
** input parameters:        ulSize:             �ڴ��С
** output parameters:       none
** Returned value:          �ڴ��ַ,NULLΪ���ɹ�
*********************************************************************************************************/
void *tpOSHeapMalloc (INT32U ulSize)
{
    return sysHeapMalloc(ulSize);
}

/*********************************************************************************************************
** Function name:           tpEnterCritical
** Descriptions:            ��ֹ�ж�
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK:             �ɹ�
**                          ����:               ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S tpEnterCritical(void)
{
    OS_ENTER_CRITICAL();
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           tpExitCritical
** Descriptions:            �����ж�
** input parameters:        none
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S tpExitCritical(void)
{
    OS_EXIT_CRITICAL();
    return SYS_OK;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

