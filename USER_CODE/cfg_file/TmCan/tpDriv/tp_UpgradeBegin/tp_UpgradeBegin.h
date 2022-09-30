/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpgradeBegin.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            �˿�����ͷ�ļ�
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
#ifndef __TP_UPGRADEBEGIN_H
#define __TP_UPGRADEBEGIN_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  ���¿����һЩ�궨��
*********************************************************************************************************/

/*********************************************************************************************************
  ���ܲ�����Ϣ
*********************************************************************************************************/
struct tp_UpgradeBegin_info {
    TM_PORT_INFO tmPort;                                                /*  ���ܲ���������Ϣ            */
    /*
     *  ��������Ҫ���ӵ���Ϣ
     */        
};

typedef  struct tp_UpgradeBegin_info  TP_UPGRADEBEGIN_INFO;

/*********************************************************************************************************
  �ṩ��ȫ�ֱ���
*********************************************************************************************************/
extern const TM_PORT_FUNC GtpfUpgradeBegin;                             /*  �豸�ӿں�����              */
extern INT32U  __GuiIndex;
extern INT8U   __GucUpgradeBuf[];
extern INT32U  __GuiChanle;


extern INT8U   __GucXPoint;
extern INT8U   __GucYPoint;
extern INT32U  __GuiBackupAddr;
extern void    (*__GpsysSoftParaGet)(INT32U*);
extern INT32S  (*__GpsysUpgradeBegin)(INT8U*, INT32U);
extern INT32S  (*__GpsysUpgradeDataWrite)(unsigned int);
extern INT32S  (*__GpsysUpgradeEnd)(void);   
    
extern INT8U   __GucUpgradeOk;
extern INT8U   __GucFlagOnce;
extern INT32U  __GuiCodeInfo[3]; 
extern volatile INT8U  __GucIsCanBusUpdate;
typedef enum {
    codeVer = 0,
    codeLen,
    codeId
} CODE_INFO;


#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __TP_UPGRADEBEGIN_H         */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
