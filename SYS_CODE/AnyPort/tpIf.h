/****************************************Copyright (c)****************************************************
**                            
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpIf.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            Э������մ����ӿ�ͷ�ļ�
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
#ifndef __TP_IF_H
#define __TP_IF_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  �ӿ���Ϣ
*********************************************************************************************************/
struct tp_if_msg {
    TP_DRV_INFO_BASE    *ptdibDriverInfo;                               /*  ������Ϣ                    */
    TP_PACKET_HEAD      *ptphPacketData;                                /*  ����֡                      */
};
typedef  struct tp_if_msg      TP_IF_MSG;

/*********************************************************************************************************
** Function name:           tpIfInit
** Descriptions:            �ӿڳ�ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�tp.h
*********************************************************************************************************/
extern INT32S tpIfInit(void);

/*********************************************************************************************************
** Function name:           tpRemotePacketReceive
** Descriptions:            Э����յ�����֡
** input parameters:        pdiDriverInfo:  ������Ϣ
**                          ptphPacketData: ����֡   
** output parameters:       none
** Returned value:          TP_OK:          �ɹ�
**                          ����:           ����,����ֵ�ο�tp.h
*********************************************************************************************************/
extern INT32S tpRemotePacketReceive(TP_DRV_INFO_BASE * pdibDriverInfo, TP_PACKET_HEAD *pzphPacketData);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TP_IF_H                   */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/