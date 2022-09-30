/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpHooks.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.0.0
** Descriptions:            ϵͳ�ӿں�����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2014-08-25
** Version:                 1.0.0
** Descriptions:            The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#ifndef __TP_HOOKS_H
#define __TP_HOOKS_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

    /*********************************************************************************************************
** Function name:           tpOSQueueCreate
** Descriptions:            ���д���
** input parameters:        pv                  ��Ϣ�����ڴ�
**                          uiSize              ��Ϣ�������
** output parameters:       none
** Returned value:          ��Ϣָ��            �ɹ�
**                          NULL                ʧ��
*********************************************************************************************************/
extern void *tpOSQueueCreate(void *pv, INT32U uiSize);
    
/*********************************************************************************************************
** Function name:           tpOSQueueDel
** Descriptions:            ����ɾ��
** input parameters:        pv                  ��Ϣ����
**                          
** output parameters:       pucErr              �������
** Returned value:          NULL                �ɹ�
**                          ��Ϣָ��            ʧ��
*********************************************************************************************************/
extern void *tpOSQueueDel(void *pv, INT8U *pucErr);
    
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
extern void *tpOSQueuePend(void *pv, INT32U uiTimeOut, INT8U *pucErr);

/*********************************************************************************************************
** Function name:           tpOSQueuePend
** Descriptions:            ���еȴ�
** input parameters:        pv                  ��Ϣ����
**                          msg                 ��Ϣָ��
**                          
** output parameters:       none
** Returned value:          OS_NO_ERR           �ɹ�
**                          �ο�ucos_ii.h�������
**                          
*********************************************************************************************************/
extern INT8U tpOSQueuePost(void *pv, void *msg);

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
extern void *tpOSSemCreate(INT16U usCnt);

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
extern void *tpOSSemDel(void *pSem, INT8U *pucErr);

/*********************************************************************************************************
** Function name:           tpOSSemPend
** Descriptions:            �ź����ȴ�
** input parameters:        pSem                �ź���ָ��
**                          usTimeOut           �ȴ���ʱ����
**                          
**
**                       
** output parameters:       pucErr              ��������ŵ�ַ
**                          �ο�ucos_ii.h�������
** Returned value:          none
**                          
**                          
*********************************************************************************************************/
extern void tpOSSemPend(void *pSem, INT16U usTimeOut, INT8U *pucErr);

/*********************************************************************************************************
** Function name:           tpOSSemPost
** Descriptions:            �ź�������
** input parameters:        pSem                �ź���ָ��
**                          
** output parameters:       none
** Returned value:          OS_NO_ERR           �ɹ�
**                          �ο�ucos_ii.h�������
**                          
*********************************************************************************************************/
extern INT8U tpOSSemPost(void *pSem);



/*********************************************************************************************************
** Function name:           tpOSTimeDly
** Descriptions:            ϵͳ��ʱ
** input parameters:        usTicks             ��ʱticks
**                          
** output parameters:       none
** Returned value:          none
**                          
**                          
*********************************************************************************************************/
extern void tpOSTimeDly(INT16U usTicks);

/*********************************************************************************************************
** Function name:           tpOSHeapMalloc
** Descriptions:            �ѷ����ڴ�
** input parameters:        ulSize:             �ڴ��С
** output parameters:       none
** Returned value:          �ڴ��ַ,NULLΪ���ɹ�
** Created by:              
** Created Date:            
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
extern void *tpOSHeapMalloc (INT32U ulSize);



/*********************************************************************************************************
** Function name:           tpEnterCritical
** Descriptions:            ��ֹ�ж�
** input parameters:        none
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�tp.h
** Created by:              
** Created Date:            2014-08-25
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
extern INT32S tpEnterCritical(void);

/*********************************************************************************************************
** Function name:           tpExitCritical
** Descriptions:            �����ж�
** input parameters:        none
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�tp.h
** Created by:              
** Created Date:            2014-08-25
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
extern INT32S tpExitCritical(void);


#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TP_HOOKS_H                */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
