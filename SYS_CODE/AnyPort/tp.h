/****************************************Copyright (c)****************************************************
**                          Beijing Hengfengli Technology CO.,LTD.
**                                      
**                                 http://www.hengfengli.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            AnyPortЭ��ջͷ�ļ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
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
#ifndef __TP_H
#define __TP_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  �汾����
*********************************************************************************************************/
#define     TP_VER           0x14082510                                 /*  V1.0                        */

/*********************************************************************************************************
  ����ֵ����
*********************************************************************************************************/
//#define     TP_OK                   0                                   /*  �����ɹ�                    */
//#define     TP_NOT_OK               1                                   /*  ����ʧ��                    */
//#define     TP_PARA_ERR             2                                   /*  ��������                    */
//#define     TP_NO_FIND_DEVICE       3                                   /*  û�з����豸                */
//#define     TP_NODE_FULL            4                                   /*  �ڵ�����                    */
//#define     TP_NO_FIND_FUNCTION     5                                   /*  û�з���ָ������            */
//#define     TP_DRIVER_FULL          6                                   /*  ����������                  */
//#define     TP_DRIVER_EXIST         7                                   /*  ���������Ѱ�װ              */
//#define     TP_FIND_NO_DRIVER       8                                   /*  û�з�����������            */
//#define     TP_NO_PORT              9                                   /*  �����ڵĶ˿�                */
//#define     TP_NO_MEMORY            10                                  /*  �ڴ治��                    */
//#define     TP_TIME_OUT             11                                  /*  ��ʱ                        */
//#define     TP_PACKET_ERR           12                                  /*  ֡����                      */

/*********************************************************************************************************
  ����ͨ���Ŷ���
*********************************************************************************************************/
#define     TP_DEFAULT_CHNL         0xff                                /*  Ĭ��ͨ����                  */

/*********************************************************************************************************
  �˿ڲ�������
*********************************************************************************************************/
struct tp_port_info;
struct tp_port_func {
    /*
     *  ���캯��
     */
    INT32S    (*pfuncCreate)(const struct tp_port_info *ptpiThis);

    /*
     *  ��������
     */
    INT32S    (*pfuncDel)(const struct tp_port_info *ptpiThis);

    /*
     *  ���˿�����
     */
    INT32S    (*pfuncRead)(const struct tp_port_info *ptpiThis,
                                 INT8U                ucChnl,
                                 INT16U               usLen,
                                 void                *pvData);

    /*
     *  д�˿�����
     */
    INT32S    (*pfuncWrite)(const struct tp_port_info *ptpiThis,
                                  INT8U                ucChnl,
                                  INT16U               usLen,
                                  void                *pvData);

    /*
     *  д���˿�����
     */
    
};
typedef  struct tp_port_func      TP_PORT_FUNC;

/*********************************************************************************************************
  �˿���Ϣ
*********************************************************************************************************/
struct tp_port_info {
    TP_PORT_FUNC *pdfFunc;                                              /*  �����б�                    */ 
    INT32U        ulAddrStart;                                          /*  ��ʼ�˿ڵ�ַ                */
    INT8U         ucRemoteEn;                                           /*  Զ�̷������                */
};

typedef  struct tp_port_info      TP_PORT_INFO;

/*********************************************************************************************************
  ͨѶ��������
*********************************************************************************************************/
struct tp_drv_info_base;
struct tp_drv_func_base {
   
    /*
     *  ���캯��
     */
    INT32S    (*pfuncCreate)(struct tp_drv_info_base *ptpiThis);

    /*
     *  ��������
     */
    INT32S    (*pfuncDel)(struct tp_drv_info_base *ptpiThis);
    
    /*
     *  д�˿�����
     */
    INT32S    (*pfuncWrite)(struct tp_drv_info_base    *ptpiThis,
                                    INT8U               ucDst,
                                    INT8U               ucSrc,
                                    INT8U               ucAddr,
                                    INT16U              usLen,
                                    void               *pvData,
                                    INT8U               ucAck,
                                    INT8U               ucFType);
    /*
     *  ���˿�����
     */
    INT32S    (*pfuncRead)(struct tp_drv_info_base     *ptpiThis,
                                    INT8U               ucDst,
                                    INT8U               ucSrc,
                                    INT8U               ucAddr,
                                    INT16U              usLen,
                                    void               *pvData,
                                    INT8U               ucFType);
                                      
};

typedef  struct tp_drv_func_base      TP_DRV_FUNC_BASE;
 
/*********************************************************************************************************
  ͨѶ������Ϣ
*********************************************************************************************************/
struct tp_drv_info_base {
    TP_DRV_FUNC_BASE    *pdfFunc;                                       /*  ����������Ϣ                */    
  
    INT32U               uiChnl;                                        /*  ����ͨ����                  */
    INT32U               uiReceiveDelay;                                /*  �ȴ������ӳ�ʱ��            */
    INT32U              *pulHostTable;                                  /*  �����豸ת�����            */
    INT32U              *pulSlaveTable;                                 /*  �����豸ת�����            */
    
};

typedef  struct tp_drv_info_base      TP_DRV_INFO_BASE;

/*********************************************************************************************************
** Function name:           tpRead
** Descriptions:            �˿ڶ�
** input parameters:        uiChnl          ����ͨ����
**                          ucDstAddr       Ŀ�ĵ�ַ
**                          ucAddr          �˿ڵ�ַ
**                          usLen           ������Ŀ
**                          pvData          ���ݱ����ַ
**                          
** output parameters:       pvData          ����������
** Returned value:          >=0             ��ɵ�������Ŀ
**                          ����            ����,����ֵ�ο�tp.h         
*********************************************************************************************************/
extern INT32S tpRead(INT32U uiChnl, INT8U ucAddr, INT16U usLen, void *pvData);
extern INT32S tpReadBus(INT32U uiChnl, INT8U ucDst, INT8U ucSrc, INT8U ucAddr, INT16U usLen, void *pvData);

/*********************************************************************************************************
** Function name:           tpWrite
** Descriptions:            �˿�д
** input parameters:        uiChnl          ����ͨ����
**                          ucDstAddr       Ŀ�ĵ�ַ
**                          ucAddr          �˿ڵ�ַ
**                          usLen           ������Ŀ
**                          pvData          ���ݱ����ַ
**                          ucAck           0--�޻ظ� 1--�лظ�
** output parameters:       none
** Returned value:          >=0             ��ɵ�������Ŀ
**                          ����            ����,����ֵ�ο�tp.h         
*********************************************************************************************************/
extern INT32S tpWrite(INT32U uiChnl, INT8U ucAddr, INT16U usLen, void *pvData, INT8U ucAck);
extern INT32S tpWriteBus(INT32U uiChnl, INT8U ucDst, INT8U ucSrc, INT8U ucAddr, INT16U usLen, void *pvData, INT8U ucAck);
/*********************************************************************************************************
** Function name:           tpWriteRead
** Descriptions:            �˿�д��
** input parameters:        uiChnl          ����ͨ����
**                          ucAddr          �˿ڵ�ַ
**                          usLen           ������Ŀ
**                          pvData          ���ݱ����ַ
**                          ucAck           0--�޻ظ� 1--�лظ�
** output parameters:       none
** Returned value:          >=0             ��ɵ�������Ŀ
**                          ����            ����,����ֵ�ο�tp.h          
*********************************************************************************************************/

/*********************************************************************************************************
  ����Ϊ�ڲ�ʹ�õĺ�����ṹ�嶨�壬�û��������
*********************************************************************************************************/

/*********************************************************************************************************
  ��������
*********************************************************************************************************/
struct __tp_list {
    struct __tp_list     *plNext;                                       /*  ��һ���˿�                  */
    const TP_PORT_INFO   *ptpiData;                                     /*  �˿�����                    */
};

typedef  struct __tp_list           __TP_LIST;



/*********************************************************************************************************
  �궨��
*********************************************************************************************************/
#define TP_BUS_FLAG_CHAR    0x00                                        /*  ����Э���ʶ                */
#define TP_NBR_FLAG_CHAR    0x02                                        /*  ��Ե�Э���ʶ              */

#define __TP_REMOTE_FUNC   \
    {                      \
        tpDrvCreate,      \
        tpDrvDel,         \
        tpDrvWrite,       \
        tpDrvRead         \
    }

#define __TP_REMOTE_FUNC_EX \
    {                      \
        tpDrvCreate,      \
        tpDrvDel,         \
        tpDrvWriteEx,     \
        tpDrvReadEx       \
    }    
/*********************************************************************************************************
  ֡���붨��
*********************************************************************************************************/
#define TP_READ_FLG       0x00                                           /*  �˿ڶ�                     */
#define TP_WRITE_FLG      0x01                                           /*  �˿�д                     */
#define TP_NREAD_FLG      0x02                                           /*  ����                       */
#define TP_NWRITE_FLG     0x03                                           /*  �˿�д,����Ҫ�ظ�          */

#define TP_RREAD_FLG      0x04                                           /*  �˿ڶ��ɹ��ظ�             */
#define TP_RWRITE_FLG     0x05                                           /*  �˿�д�ɹ��ظ�             */
#define TP_RFREAD_FLG     0x06                                           /*  �˿ڶ�ʧ�ܻظ�             */
#define TP_RFWRITE_FLG    0x07                                           /*  �˿�дʧ�ܻظ�             */

/*********************************************************************************************************
  �ֽ�˳��任
*********************************************************************************************************/
#ifndef tp_ntohl
#define tp_ntohl(x) x = (INT32U)(((INT8U *)&(x))[0] << 24 | \
                                 ((INT8U *)&(x))[1] << 16 | \
                                 ((INT8U *)&(x))[2] << 8  | \
                                 ((INT8U *)&(x))[3] << 0)
#endif                                                                  /*  tp_ntohl                    */

#ifndef tp_htonl
#define tp_htonl(x) x = (INT32U)(((INT8U *)&(x))[0] << 24 | \
                                 ((INT8U *)&(x))[1] << 16 | \
                                 ((INT8U *)&(x))[2] << 8  | \
                                 ((INT8U *)&(x))[3] << 0)
#endif                                                                  /*  tp_htonl                    */

#ifndef tp_ntohs
#define tp_ntohs(x) x = (INT16U)(((INT8U *)&(x))[0] << 8  | \
                                 ((INT8U *)&(x))[1] << 0)
#endif                                                                  /*  tp_ntohs                    */

#ifndef tp_htons
#define tp_htons(x) x = (INT16U)(((INT8U *)&(x))[0] << 8  | \
                                 ((INT8U *)&(x))[1] << 0)
#endif                                                                  /*  tp_htons                    */

/*********************************************************************************************************
  Ĭ��Э��������Ϣ
*********************************************************************************************************/
struct tp_drv_info;
struct tp_packet_head;
struct tp_drv_func {                                                 /*  ���������б�                */
    TP_DRV_FUNC_BASE dfFunc;                                         /*  �������������б�            */

    /*
     *  ���캯��
     */
    INT32S    (*pfuncCreate)(struct tp_drv_info *ptpiThis);

    /*
     *  ��������
     */
    INT32S    (*pfuncDel)(struct tp_drv_info *ptpiThis);

    /*
     *  �������ݰ�
     */
    INT32S    (*pfuncSend)(struct tp_drv_info  *ptpiThis,                                  
                           struct tp_packet_head  *pData);
                          
};

typedef  struct tp_drv_func     TP_DRV_FUNC;


struct tp_drv_info {
    TP_DRV_INFO_BASE    dibInfo;                                        /*  ������Ϣ                    */
    INT8U               ucId;                                           /*  �豸ID��                    */
};

typedef  struct tp_drv_info     TP_DRV_INFO;
/*********************************************************************************************************

*********************************************************************************************************/


/*********************************************************************************************************
  Э����ṹ
*********************************************************************************************************/
#if 0

typedef union __headbits
{
    unsigned int	uiWord;
    struct 
    {
        unsigned int uiFtype    :2;                                     /*  ֡����                      */
        union {
            struct {
        unsigned int uiSegNum   :14;                                    /*  ��֡����                    */
        unsigned int uiSegPolo  :2;                                     /*  ��֡��־                    */  
            } NbrHeadBits;
            struct {
                unsigned int uiDstAddr  :8;
                unsigned int uiSrcAddr  :8;
            } BusHeadBits;
        }SegBits;
        unsigned int uiPortAddr :8;                                     /*  ���ܶ˿ڵ�ַ                */
        unsigned int uiRF       :3;                                     /*  ���б�־                    */
        unsigned int uiRsv      :3;    
    }Bits;
}__HEADBITS, *__PHEADBITS;
#endif

/*********************************************************************************************************
  ����֡ID�ṹ
*********************************************************************************************************/
typedef union __headbits
{
    unsigned int	uiWord;
    struct {
        unsigned int uiFtype    :2;                                     /*  ֡����                      */        
        unsigned int uiSegNum   :14;                                    /*  ��֡����                    */
        unsigned int uiSegPolo  :2;                                     /*  ��֡��־                    */  
        unsigned int uiPortAddr :8;                                     /*  ���ܶ˿ڵ�ַ                */
        unsigned int uiRF       :3;                                     /*  ���б�־                    */
        unsigned int uiRsv      :3;    
    } Bits;
    struct {
        unsigned int uiFtype    :2;                                     /*  ֡����                      */
        unsigned int uiDstAddr  :8;                                     /*  Ŀ�ĵ�ַ                    */
        unsigned int uiSrcAddr  :8;                                     /*  Դ��ַ                      */
        unsigned int uiPortAddr :8;                                     /*  ���ܶ˿ڵ�ַ                */
        unsigned int uiRF       :3;                                     /*  ���б�־                    */
        unsigned int uiRsv      :3;    
    } BusHeadBits;
}__HEADBITS, *__PHEADBITS;


/*********************************************************************************************************
  ����CAN֡Э���֡��ʶ���ṹ
*********************************************************************************************************/
typedef union __seg_flag
{
    unsigned short usSegFlag;
    struct
    {
        unsigned int uiSegNum   :14;                                    /*  ��֡����                    */
        unsigned int uiSegPolo  :2;                                     /*  ��֡��־                    */    
    } Bits;

}__SEG_FLAG, *__PSEG_FLAG;
struct tp_packet_head {                                                 /*  ֡ͷ�ṹ                    */
  __HEADBITS        tpHeadBits;                                         /*  ����֡ͷ                    */
    INT8U           ucDatLen;                                           /*  ֡���ݳ���                  */
};


typedef  struct tp_packet_head      TP_PACKET_HEAD;


struct tp_packet {                                                      /*  ��ͨ֡�ṹ                  */
    TP_PACKET_HEAD    tpHead;                                           /*  ֡ͷ                        */
    INT16U            usDatLen;                                         /*  ��Ч���ݳ���                */
    INT8U            *pucDat;                                           /*  ���ݻ���ָ��                */
    INT8U             ucChnl;                                           /*  �����豸��                  */
};

typedef  struct tp_packet    TP_PACKET;

/*********************************************************************************************************
  tp���ݽṹ
*********************************************************************************************************/
struct tp_drv {
    TP_DRV_INFO        *ptdi;
    INT32U              uiTimeOut;
    unsigned long       pSemSend;
    unsigned long       pSemRcv;
    TP_PACKET           tp;
    INT8U              *pucRtn;                                         /*  дӦ��Я������              */
    INT32U              uiErr;
    INT32U              uiFlg;
};
typedef struct tp_drv TP_DRV, *PTP_DRV;



/*********************************************************************************************************
** Function name:           tpInit
** Descriptions:            Tp��ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK: �ɹ�
**                          ����:   ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S tpInit(void);

/*********************************************************************************************************
** Function name:           tpTick
** Descriptions:            ʱ�ӽ��Ĵ���
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void tpTick(void);

/*********************************************************************************************************
** Function name:           tpDevicePortInit
** Descriptions:            �˿����ʼ��
** input parameters:        ptpListSpace:       �˿�������
**                          uiMaxDevices:
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�tp.h
*********************************************************************************************************/
extern INT32S tpDevicePortInit(__TP_LIST *ptpListSpace, unsigned int uiMaxDevices);    

/*********************************************************************************************************
** Function name:           tpRemoteInit
** Descriptions:            �������������ʼ��
** input parameters:        ppdiDriversSpace:   ��������������Ϣ��ָ��Ĵ洢�ռ�
**                          uiMaxDrivers:       �������������Ŀ
**                          pRsv:               ��������
** output parameters:       none
** Returned value:          SYS_OK:             �ɹ�
**                          ����:               ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S tpRemoteDriversInit(TP_DRV_INFO_BASE   **ppdibDriversSpace,
                          unsigned int          uiMaxDrivers,
                          void                 *pRsv);

/*********************************************************************************************************
** Function name:           tpDrivCreate
** Descriptions:            �������������ʼ��
** input parameters:        ptdibThis:          �����ʶ
** output parameters:       none
** Returned value:          SYS_OK:             �ɹ�
**                          ����:               ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S tpDrvCreate (TP_DRV_INFO_BASE *ptdibThis);

/*********************************************************************************************************
** Function name:           tpDrivDel
** Descriptions:            ɾ��������������
** input parameters:        ptdibThis:          �����ʶ
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�tp.h
*********************************************************************************************************/
extern INT32S tpDrvDel (TP_DRV_INFO_BASE *ptdibThis);

/*********************************************************************************************************
** Function name:           tpDrivWrite
** Descriptions:            ��������д����
** input parameters:        ptdibThis:          �����ʶ
**                          ucDst:              Ŀ�ĵ�ַ
**                          ucSrc:              Դ��ַ
**                          ucAddr:             �˿ڵ�ַ
**                          usLen:              ������Ŀ
**                          pvData:             ���ݱ����ַ
** output parameters:       none
** Returned value:          >=0:                ��ɵ�������Ŀ
**                          ����:               ����,����ֵ�ο�tp.h
*********************************************************************************************************/
extern INT32S tpDrvWrite(TP_DRV_INFO_BASE      *ptdibThis,
                          INT8U                 ucAddr,
                          INT16U                usLen,
                          void                 *pvData,
                          INT8U                 ucAck); 
extern INT32S tpDrvWriteEx(TP_DRV_INFO_BASE      *ptdibThis,
                          INT8U                 ucDst,
                          INT8U                 ucSrc,
                          INT8U                 ucAddr,
                          INT16U                usLen,
                          void                 *pvData,
                          INT8U                 ucAck,
                          INT8U                 ucFType); 
/*********************************************************************************************************
** Function name:           tpDrvRead
** Descriptions:            ��������������
** input parameters:        ptdibThis:          �����ʶ
**                          ucDst:              Ŀ�ĵ�ַ
**                          ucSrc:              Դ��ַ
**                          ucAddr:             �˿ڵ�ַ
**                          usLen:              ������Ŀ
** output parameters:       pvData:             ����
** Returned value:          >=0:                ��ɵ�������Ŀ
**                          ����:               ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S tpDrvRead (TP_DRV_INFO_BASE      *ptdibThis,
                         INT8U                  ucAddr,
                         INT16U                 usLen,
                         void                  *pvDat);

extern INT32S tpDrvReadEx(TP_DRV_INFO_BASE      *ptdibThis,
                         INT8U                  ucDst,
                         INT8U                  ucSrc,
                         INT8U                  ucAddr,
                         INT16U                 usLen,
                         void                  *pvDat,
                         INT8U                  ucFType);
/*********************************************************************************************************
** Function name:           tpReceive
** Descriptions:            ����֡����
** input parameters:        ptdibThis:          ����������ʶ
**                          ptphPacket:         ����֡
** output parameters:       none
** Returned value:          TP_OK:              �ɹ�
**                          ����:               ����,����ֵ�ο�tp.h
*********************************************************************************************************/
extern INT32S tpReceive(TP_DRV_INFO_BASE *ptdibThis, TP_PACKET_HEAD *ptphPacket);

/*********************************************************************************************************
** Function name:           tpDrvsInit
** Descriptions:            ����AnyPortЭ���ʼ������
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/

extern TP_DRV_INFO  *const __GptdiDrvs[TP_MAX_DRIVER];  
#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TP_H                      */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
