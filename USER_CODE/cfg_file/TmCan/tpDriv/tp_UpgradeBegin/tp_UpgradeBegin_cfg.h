/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tp_UpgradeBegin_cfg.h
** Latest modified Date:    2014-08-25
** Latest Version:          1.0
** Descriptions:            �˿����������ļ�
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
#ifndef __TP_UPGRADEBEGIN_CFG_H
#define __TP_UPGRADEBEGIN_CFG_H

/*********************************************************************************************************
  �����ͷ�ļ�
*********************************************************************************************************/
#include    "..\..\..\config.h"
#include    ".\tp_UpgradeBegin.h"


#ifndef __UPGRADE_PAGE_SIZE
#define __UPGRADE_PAGE_SIZE     (1 * 512)
#endif

#if     __UPGRADE_PAGE_SIZE % 512 != 0
	#error  "__UPGRADE_PAGE_SIZE is must multiple of 512"
#endif

#if     __UPGRADE_PAGE_SIZE > 4096
	#error  "__UPGRADE_PAGE_SIZE is must less than 4096"
#endif

#define __UPGRADE_OK                0x00                                /*  ��������У��ͨ��            */
#define __UPGRADE_PRO_NOMATCH_ERR   0x01                                /*  ����������Ŀ��ƥ��          */
#define __UPGRADE_PRO_VERLOW_ERR    0x02                                /*  ��������汾̫��            */
#define __UPGRADE_PRO_TOOLONG_ERR   0x03                                /*  �������򳤶ȳ���            */
#define __UPGRADE_PRO_BEGIN_ERR     0x04                                /*  ������������ʧ��            */
#define __UPGRADE_PRO_BEING_ERR     0x05                                /*  �������������              */


#define __UPGRADE_PRO_TYPE_ERR      0x06                                /*  �����������ʹ���            */
    /*
     *  ������Ϣ���ã�ͬʱ��Ҫ��Startup.s������Ӧ�޸�
     */
#ifdef __EN_PRO                                                  
    #define __DLM_CODE_ID   0x10                                        /*  ��������ع����������      */
    #define __USR_CODE_ID   0xFF                                        
#endif

#ifdef __EN_CTRL                                                      
    #define __DLM_CODE_ID   0x11                                        /*  ���������ع����������      */
    #define __USR_CODE_ID   0x12                                        /*  ������Ӧ�ó�������          */
#endif

#ifdef __EN_SRV
    #define __DLM_CODE_ID   0x13                                        /*  ���������ع����������      */
    #define __USR_CODE_ID   0x14                                        /*  ������Ӧ�ó�������          */
#endif
    #define __DLM_CODE_LEN  0x1A000 
    #define __USR_CODE_LEN  0x80000
    #define __MAX_CODE_LEN  0x80000 
#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  ����Լ���������Ϣ
*********************************************************************************************************/

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __TP_UPGRADEBEGIN_CFG_H     */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
