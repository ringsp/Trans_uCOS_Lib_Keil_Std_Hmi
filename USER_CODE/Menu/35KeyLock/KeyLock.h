/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               KeyLock.h
** Latest modified Date:    2021-12-26
** Latest Version:          1.0.0
** Descriptions:            ���������˵�ҳͷ�ļ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2021-12-26
** Version:                 1.0.0
** Descriptions:            The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#ifndef __KEY_LOCK_H
#define __KEY_LOCK_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
** Function name:           miKeyLockInit
** Descriptions:            ���������˵���ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void miKeyLockInit(void);

/*********************************************************************************************************
** Function name:           miKeyLockDel
** Descriptions:            ���������˵�ж��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void miKeyLockDel(void);

extern const MENU_ITEM_INFO_BASE __GmiibKeyLock;                        /*  �˵�����Ϣ                  */
#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __KEY_LOCK_H                */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
