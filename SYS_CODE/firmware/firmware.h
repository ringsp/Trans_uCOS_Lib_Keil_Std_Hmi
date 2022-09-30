/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               firmware.h
** Last modified Date:      2010-12-14
** Last Version:            1.0
** Descriptions:
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
********************************************************************************************************/
#ifndef __FIRMWARE_H
#define __FIRMWARE_H
#ifdef __cplusplus
    extern "C" {
#endif

#define __PRJ_BOOT_VER      0x14082510                                  
                                                                        /*                                                                     
                                                                         *  Boot�汾Ϊ V1.0
                                                                         *      1����ʼ�汾
                                                                         */

//extern INT8U  sysSectorPrepare(INT8U ucStart, INT8U ucEnd);
//extern INT32U sysSectorErase(INT8U ucStart, INT8U ucEnd);
/*********************************************************************************************************
** Function name:           sysBootVersionGet
** Descriptions:            ��ȡ�̼��汾��
** input parameters:        none
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
extern INT32U  sysBootVersionGet(void);

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
** Function name:           sysUpgradeBegin
** Descriptions:            ��ʼ����
** input parameters:        pucBuf: �������ݻ����ַ
**                          uiLength�������С(>=512B)
** output parameters:       none
** Returned value:          >=0:    �����ʼ���
**                          ����:   ʧ��
*********************************************************************************************************/
extern INT32S sysUpgradeBegin(INT8U* pucBuf, INT32U uiLength);

/*********************************************************************************************************
** Function name:           sysUpgradeDataWrite
** Descriptions:            �����������
** input parameters:        uiBlockIndex: ���ݿ����������㿪ʼ, ÿ���1KB�����ۼ�
** output parameters:       none
** Returned value:          ����ֵ�ο� "IAP.h"
*********************************************************************************************************/
extern INT32S sysUpgradeDataWrite(unsigned int uiBlockIndex);

/*********************************************************************************************************
** Function name:           sysUpgradeEnd
** Descriptions:            ��������
** input parameters:        none
** output parameters:       none
** Returned value:          ����ֵ�ο� "IAP.h"
*********************************************************************************************************/
extern INT32S sysUpgradeEnd(void);

/*********************************************************************************************************
** Function name:           GetSoftPara
** Descriptions:            ���س���ͷ����
** input parameters:        none
** output parameters:       none
** Returned value:          puiPara[0]: ��ǰ����汾��
**                          puiPara[1]: ��ǰ��������־    
*********************************************************************************************************/
extern void sysSoftParaGet(INT32U* puiPara);

/*********************************************************************************************************
** Function name:           sysUpgradeBeginUsr
** Descriptions:            ��ʼ����
** input parameters:        none
** output parameters:       none
** Returned value:          �ǿ�ָ��:     ����������
*********************************************************************************************************/
extern sysUpgradeBeginUsr(INT8U* pucBuf, INT32U uiLength);

/*********************************************************************************************************
** Function name:           sysUpgradeDataWriteUsr
** Descriptions:            �����������
** input parameters:        uiBlockIndex: ���ݿ����������㿪ʼ, ÿ���1KB�����ۼ�
** output parameters:       none
** Returned value:          ����ֵ�ο� "IAP.h"
*********************************************************************************************************/
extern INT32S sysUpgradeDataWriteUsr(unsigned int uiBlockIndex);

/*********************************************************************************************************
** Function name:           sysUpgradeEndUsr
** Descriptions:            ��������
** input parameters:        none
** output parameters:       none
** Returned value:          ����ֵ�ο� "IAP.h"
*********************************************************************************************************/
extern INT32S sysUpgradeEndUsr(void);

/*********************************************************************************************************
** Function name:           sysSoftParaGetUsr
** Descriptions:            ���س���ͷ����
** input parameters:        none
** output parameters:       none
** Returned value:          puiPara[0]: ��ǰ����汾��
**                          puiPara[1]: ��ǰ��������־  
**                          puiPara[2]: ��ǰ���������ɹ���Ч����   
*********************************************************************************************************/
extern void sysSoftParaGetUsr(INT32U* puiPara);

/*********************************************************************************************************
** Function name:           sysCodeEraseEx
** Descriptions:            ����Ӧ�ó�����Ч��־
** input parameters:        none
** output parameters:       none
** Returned value:          �̼��汾
*********************************************************************************************************/
extern void sysCodeEraseUsr(void);

/*********************************************************************************************************
** Function name:           sysUpgradeBeginEx
** Descriptions:            ��ʼ����
** input parameters:        none
** output parameters:       none
** Returned value:          �ǿ�ָ��:     ����������
*********************************************************************************************************/
extern sysUpgradeBeginEx(INT8U* pucBuf, INT32U uiLength);

/*********************************************************************************************************
** Function name:           sysUpgradeDataWriteEx
** Descriptions:            �����������
** input parameters:        uiBlockIndex: ���ݿ����������㿪ʼ, ÿ���1KB�����ۼ�
** output parameters:       none
** Returned value:          ����ֵ�ο� "IAP.h"
*********************************************************************************************************/
extern INT32S sysUpgradeDataWriteEx(unsigned int uiBlockIndex);

/*********************************************************************************************************
** Function name:           sysUpgradeEndEx
** Descriptions:            ��������
** input parameters:        none
** output parameters:       none
** Returned value:          ����ֵ�ο� "IAP.h"
*********************************************************************************************************/
extern INT32S sysUpgradeEndEx(void);

/*********************************************************************************************************
** Function name:           GetSoltParaEx
** Descriptions:            ���س���ͷ����
** input parameters:        none
** output parameters:       none
** Returned value:          puiPara[0]: ��ǰ����汾��
**                          puiPara[1]: ��ǰ��������־  
**                          puiPara[1]: ��ǰ���������ɹ���Ч����   
*********************************************************************************************************/
extern void sysSoftParaGetEx(INT32U* puiPara);

/*********************************************************************************************************
** Function name:           sysCodeEraseEx
** Descriptions:            ����������Ч��־
** input parameters:        none
** output parameters:       none
** Returned value:          �̼��汾
*********************************************************************************************************/
extern void sysCodeEraseEx(void);

/*********************************************************************************************************
** Function name:       WordProgram
** Descriptions:        �ֱ��
** input parameters:    ��ַ������
** output parameters:   none
** Returned value:      �Ƿ�ɹ�               
*********************************************************************************************************/
extern INT32S sysWordProgramEx(uint32 Addr, uint16 Data);
 
/*********************************************************************************************************
** Function name:       SectorErase
** Descriptions:        ��������
** input parameters:    ������
** output parameters:   none
** Returned value:      �Ƿ�ɹ�               
*********************************************************************************************************/                     
extern INT32S sysSectorEraseEx(uint32 Index); 



/*********************************************************************************************************
** Function name:           sysDataAbortIsrSet
** Descriptions:            ȡ����ֹ����������ַ����
** input parameters:        uiAddr:     ȡ����ֹ����������ַ
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
__inline void sysDataAbortIsrSet(INT32U uiAddr)
{
    extern INT32U uiDataAbortAddr;

    uiDataAbortAddr = uiAddr;
}

/*********************************************************************************************************
** Function name:           sysPrefetchIsrSet
** Descriptions:            Ԥȡ��ֹ����������ַ����
** input parameters:        uiAddr:     Ԥȡ��ֹ����������ַ
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
__inline void sysPrefetchIsrSet(INT32U uiAddr)
{
    extern INT32U uiPrefetchAddr;

    uiPrefetchAddr = uiAddr;
}

/*********************************************************************************************************
** Function name:           sysUndefinedsrSet
** Descriptions:            δ����ָ������������ַ����
** input parameters:        uiAddr:     δ����ָ������������ַ
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
__inline void sysUndefinedsrSet(INT32U uiAddr)
{
    extern INT32U uiUndefinedAddr;

    uiUndefinedAddr = uiAddr;
}

#ifdef __cplusplus
    }
#endif

#endif
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
