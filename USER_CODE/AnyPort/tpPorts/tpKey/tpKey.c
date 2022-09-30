/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tpKey.c
** Latest modified Date:    2022-09-17
** Latest Version:          1.0
** Descriptions:            �������ܶ˿�ʵ��
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2022-09-17
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
#include ".\main.h"

/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __tpCreate(const TP_PORT_INFO *ptpiThis);
static INT32S __tpDel(const TP_PORT_INFO *ptpiThis);
static INT32S __tpRead(const TP_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);
static INT32S __tpWrite(const TP_PORT_INFO *ptpiThis, INT8U ucChanle, INT16U usLen, void *pvData);

/*********************************************************************************************************
  ���ܲ�����Ϣ
*********************************************************************************************************/
struct tp_key_info {
    TP_PORT_INFO tp;                                                    /*  ���ܲ���������Ϣ            */
    /*
     *  ��������Ҫ���ӵ���Ϣ
     */        
};

typedef  struct tp_key_info  TP_KEY_INFO;

/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
const TP_PORT_FUNC __GtpfKey = {
    __tpCreate,
    __tpDel,
    __tpRead,
    __tpWrite
};

/*********************************************************************************************************
  �˿ڶ���
*********************************************************************************************************/
static const TP_KEY_INFO __GtpiKey = {                                  /*  �˿���Ϣ                    */
    {
        (TP_PORT_FUNC *)&__GtpfKey,
      __TP_KEY,
        TRUE
    }
};

extern unsigned long  GulKeyMsg;
/*********************************************************************************************************
** Function name:           tpKeyInit
** Descriptions:            �˿ڼ���
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void tpKeyInit(void)
{ 
    /*
     *  ��Ӷ˿�
     */
    tpDevicePortAdd((TP_PORT_INFO *)&__GtpiKey);
}
/*********************************************************************************************************
** Function name:           tpKeyDel
** Descriptions:            �˿�ж��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void tpKeyDel(void)
{ 
    /*
     *  ��Ӷ˿�
     */
    tpDevicePortDel((TP_PORT_INFO *)&__GtpiKey);
}

/*********************************************************************************************************
** Function name:           __tpCreate
** Descriptions:            �����˿�
** input parameters:        ptpiThis: �˿���Ϣ
** output parameters:       none
** Returned value:          SYS_OK:  �ɹ�
**                          ����:    ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __tpCreate(const TP_PORT_INFO *ptpiThis)
{    
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           __tpDel
** Descriptions:            ɾ���˿�
** input parameters:        ptpiThis:  �˿���Ϣ
** output parameters:       none
** Returned value:          SYS_OK:  �ɹ�
**                          ����:    ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __tpDel(const TP_PORT_INFO *ptpiThis)
{
    return SYS_OK;    
}

/*********************************************************************************************************
** Function name:           __tpRead
** Descriptions:            ���˿�
** input parameters:        ptpiThis: �˿���Ϣ
**                          usLen:    �����ݸ���
** output parameters:       pvData:   ���ݻ�����
** Returned value:          >=0 :     ������Ŀ
*********************************************************************************************************/
static INT32S __tpRead (const TP_PORT_INFO *ptpiThis, INT8U ucChnl, INT16U usLen, void *pvDat)
{
    TP_KEY_INFO        *ptti;                                           /*  �豸��Ϣ                    */
    INT32S              siErr;
    INT8U              *pucDat = pvDat;


    ptti = (TP_KEY_INFO *)ptpiThis;
    ptti = ptti;   
    

    /*
     *  ʵ�ʵ�д����
     */
   
    return usLen;
}

/*********************************************************************************************************
** Function name:           __tpWrite
** Descriptions:            д�˿ڡ�
** input parameters:        ptpiThis: �˿���Ϣ
**                          usLen:    д���ݸ���
**                          pvData:   ���ݻ�����
** output parameters:       none
** Returned value:          >=0 :     ������Ŀ
*********************************************************************************************************/
static INT32S __tpWrite (const TP_PORT_INFO *ptpiThis, INT8U ucChnl, INT16U usLen, void *pvDat)
{
    TP_KEY_INFO        *ptti;                                           /*  �豸��Ϣ                    */
    INT32S              siErr;
    INT32U              uiValue;
    const INT32U       *puiValveTbl;

    INT8U               ucBuf[8];
    ptti = (TP_KEY_INFO *)ptpiThis;
    ptti = ptti;    
    /*
     *  ʵ�ʵ�д����
     */        
    if (3 == usLen) {
//        if (0 == memcmp(ucKeyData, pvData, 3))
        sysMsgPost(GulKeyMsg, pvDat, 0);
    }
    return usLen;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
