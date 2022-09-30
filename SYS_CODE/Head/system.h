/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               system.h
** Latest modified Date:    2010-12-13
** Latest Version:          1.0
** Descriptions:            �����ӿ������ļ�����ȡԭ�ȵ�config.h�ļ��й��� 
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2010-12-13
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/


#ifndef __SYSTEM_H 
#define __SYSTEM_H
#ifdef  __cplusplus
extern "C" {
#endif

#ifndef TRUE
#define TRUE  1
#endif                                                                  /*  TRUE                        */

#ifndef FALSE
#define FALSE 0
#endif                                                                  /*  FALSE                       */

typedef unsigned char  uint8;                                           /*  �޷���8λ���ͱ���           */
typedef signed   char  int8;                                            /*  �з���8λ���ͱ���           */
typedef unsigned short uint16;                                          /*  �޷���16λ���ͱ���          */
typedef signed   short int16;                                           /*  �з���16λ���ͱ���          */
typedef unsigned int   uint32;                                          /*  �޷���32λ���ͱ���          */
typedef signed   int   int32;                                           /*  �з���32λ���ͱ���          */
typedef float          fp32;                                            /*  �����ȸ�������32λ���ȣ�    */
typedef double         fp64;                                            /*  ˫���ȸ�������64λ���ȣ�    */

typedef unsigned char  INT8U;                                           /*  �޷���8λ���ͱ���           */
typedef signed   char  INT8S;                                           /*  �з���8λ���ͱ���           */
typedef unsigned short INT16U;                                          /*  �޷���16λ���ͱ���          */
typedef signed   short INT16S;                                          /*  �з���16λ���ͱ���          */
typedef unsigned int   INT32U;                                          /*  �޷���32λ���ͱ���          */
typedef signed   int   INT32S;                                          /*  �з���32λ���ͱ���          */
typedef long long      INT64S;                                          /*  �з���64λ���ͱ���          */
typedef float          FP32;                                            /*  �����ȸ�������32λ���ȣ�    */
typedef double         FP64;                                            /*  ˫���ȸ�������64λ���ȣ�    */

typedef unsigned long long      INT64U;                                 /*  �޷���64λ���ͱ���          */

/*********************************************************************************************************
  uC/OS-II specital code
  uC/OS-II���������
*********************************************************************************************************/
#include    "..\uCOS-II\Includes.h"


/*********************************************************************************************************
  ARM���������
  ARM specital code
*********************************************************************************************************/
#include    "..\Head\target.h"
#include    "..\Head\LPC2200.h"

#include    "..\firmware\firmware.h"
#include    "..\Head\vicControl.h"


#include    "..\..\SYS_CODE\sysIf\sys_If.h"
#include    "..\DataStructure\List\List.h"
#include    "..\DataStructure\Tree\Tree.h"

#include    "..\uCOS-II\uCOS_II_add.h"
#include    "..\DrvLib\Driver2200.h"
   
#include    "..\SysTools\IO\io.h"
#include    "..\OsHeap\OsHeap.h"

//#include    "..\ZLG_GUI\GUI_CONFIG.H"
#include    "..\ZLG_GUI\GUI.H" 

#include    "..\AnyPort\tpCommon.h"

//#include    "..\Modbus\Modbus_Uart\ModbusUser.h"
//#include    "..\Modbus\Modbus_Uart\RequestFun.h"
//#include    "..\Modbus\Modbus_Uart\MB_USER_Data.h"
/*********************************************************************************************************
  Ӧ�ó�������
  Application Program Configurations
*********************************************************************************************************/
#include    <stdio.h>
#include    <ctype.h>
#include    <stdlib.h>
#include    <stdarg.h>
#include    <setjmp.h>
#include    <rt_sys.h>
#include    <rt_misc.h>

#ifdef __cplusplus
    }
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __SYSTEM_H                  */ 
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
