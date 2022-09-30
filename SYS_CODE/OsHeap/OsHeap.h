/****************************************Copyright (c)****************************************************
**                            
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               OsHeap.h
** Last modified Date:      2013-08-22
** Last Version:            1.0.0
** Descriptions:            OS HEAP �ڴ����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2013-08-22
** Version:                 1.0.0
** Descriptions:            OS HEAP �ڴ����
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef __OS_HEAP_H
#define __OS_HEAP_H

#include ".\OsHeapCfg.h"

/*********************************************************************************************************
  �ֶο��ƿ����Ͷ���
*********************************************************************************************************/

typedef struct __os_segment {

    struct __os_segment             *posNeighborLeft;                   /*  ����ھӷֶ�                */
    struct __os_segment             *posNeighborRight;                  /*  �ұ��ھӷֶ�                */
    
    struct __os_segment             *posFreeListNext;                   /*  ��һ�����зֶ�              */
    struct __os_segment             *posFreeListPrev;                   /*  ��һ�����зֶ�              */
    
    void                            *pvDataPtr;                         /*  ��������ָ��                */
    
    INT32U                           ulSegmentByteSize;                 /*  �ֶδ�С                    */
    INT8U                            ulSegmentUsedFlag;                 /*  �ֶ��Ƿ�ʹ��              */

} OS_SEGMENT_CB;

typedef OS_SEGMENT_CB             *POS_SEGMENT_CB;                      /*  �ֶ�ָ��                    */

/*********************************************************************************************************
  �ѿ��ƿ����Ͷ���
*********************************************************************************************************/

typedef struct __os_heap {
    
    struct __os_heap                *pohResrcList;                      /*  ������Դ������ָ��          */
    struct __os_segment             *posFreeSegment;                    /*  ��һ�����зֶ�              */
    
    void                            *pvStartAddress;                    /*  ���ڴ���ʼ��ַ              */
    
    INT32U                           ulTotalByteSize;                   /*  ���ڴ��ܴ�С                */
    INT32U                           ulSegmentCounter;                  /*  �ֶ�����                    */
    
    INT32U                           ulUsedByteSize;                    /*  ʹ�õ��ֽ�����              */
    INT32U                           ulFreeByteSize;                    /*  ���е��ֽ�����              */
    
} OS_HEAP_CB;

typedef OS_HEAP_CB                *POS_HEAP_CB;                         /*  �ѿ��ƿ�ָ��                */

/*********************************************************************************************************
** Function name:           osHeapCreate
** Descriptions:            ����һ���ڴ��
** input parameters:        pvStartAddr     �ڴ����ʼ��ַ
**                          ulByteSize      �ڴ�ѵĴ�С
** output parameters:       NONE
** Returned value:          �ڴ�ѿ��ƿ�ָ��
*********************************************************************************************************/
extern POS_HEAP_CB  osHeapCreate(void  *pvStartAddr, INT32U  ulByteSize);

/*********************************************************************************************************
** Function name:           osHeapDelete
** Descriptions:            ɾ��һ���ڴ��
** input parameters:        ppzhDel         �ڴ�ѿ��ƿ�ָ��ĵ�ַ
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void  osHeapDelete(POS_HEAP_CB  *ppzhDel);

/*********************************************************************************************************
** Function name:           osHeapAllocate
** Descriptions:            ��һ���ڴ���з���ָ����С���ڴ�
** input parameters:        pzhMem          �ڴ�ѿ��ƿ�ָ��
**                          iByteSize       ��Ҫ���ڴ��С
** output parameters:       NONE
** Returned value:          �����ڴ����ʼ��ַ
*********************************************************************************************************/
extern void  *osHeapAllocate(POS_HEAP_CB  pzhMem, int  iByteSize);

/*********************************************************************************************************
** Function name:           osHeapAllocateAlign
** Descriptions:            ��һ���ڴ���з���ָ����С���ڴ�, ͬʱ������������
**                          �˺���������ڴ������ʹ�� OS_HEAP_OP_SAFE ѡ��Ϊ 1 ʱ, �����ͷ�.
** input parameters:        pohMem          �ڴ�ѿ��ƿ�ָ��
**                          uiByteSize      ��Ҫ���ڴ��С
**                          uiAlign         ָ���ڴ��������
** output parameters:       NONE
** Returned value:          �����ڴ����ʼ��ַ
*********************************************************************************************************/
extern void  *osHeapAllocateAlign(POS_HEAP_CB pohMem, unsigned int uiByteSize, unsigned int uiAlign);

/*********************************************************************************************************
** Function name:           osHeapFree
** Descriptions:            ����ǰ��õ��ڴ潻�����ڴ��
** input parameters:        pohMem          �ڴ�ѿ��ƿ�ָ��
**                          pvFree          �����ڴ��С
** output parameters:       NONE
** Returned value:          �ɹ����� NULL ʧ�ܷ��� pvFree
*********************************************************************************************************/
extern void  *osHeapFree(POS_HEAP_CB  pohMem, void * pvFree);

/*********************************************************************************************************
** Function name:           osHeapStatus
** Descriptions:            ���һ���ڴ�ѵ�״̬
** input parameters:        pohMem,             �ڴ�ѿ��ƿ�ָ��        ����Ϊ NULL
**                          pulByteSize,        ����ڴ�Ѵ�С          ����Ϊ NULL
**                          pulSegmentCounter,  ��÷ֶ�����            ����Ϊ NULL
**                          pulUsedByteSize,    ���ʹ�õ��ֽ�����      ����Ϊ NULL
**                          pulFreeByteSize     ��ÿ��е��ֽ�����      ����Ϊ NULL
** output parameters:       NONE
** Returned value:          SYS_OK ���� SYS_NOT_OK ����
*********************************************************************************************************/
extern int osHeapStatus(POS_HEAP_CB  pohMem,
                     INT32U       *pulByteSize,
                     INT32U       *pulSegmentCounter,
                     INT32U       *pulUsedByteSize,
                     INT32U       *pulFreeByteSize);

/*********************************************************************************************************
** Function name:           osHeapStatusEx
** Descriptions:            ���һ���ڴ�ѵ�״̬ (��չ�ӿ�)
** input parameters:        pohMem,             �ڴ�ѿ��ƿ�ָ��        ����Ϊ NULL
**                          pulByteSize,        ����ڴ�Ѵ�С          ����Ϊ NULL
**                          pulSegmentCounter,  ��÷ֶ�����            ����Ϊ NULL
**                          pulUsedByteSize,    ���ʹ�õ��ֽ�����      ����Ϊ NULL
**                          pulFreeByteSize     ��ÿ��е��ֽ�����      ����Ϊ NULL
**                          psegmentList[]      ÿһ���ֶεķֶο��ƿ�ָ���б�
**                          pvReserve1
**                          pvReserve2
**                          pvReserve3
** output parameters:       NONE
** Returned value:          SYS_OK ���� SYS_NOT_OK ����
*********************************************************************************************************/
extern int    osHeapStatusEx(POS_HEAP_CB     pohMem,
                       INT32U           *pulByteSize,
                       INT32U           *pulSegmentCounter,
                       INT32U           *pulUsedByteSize,
                       INT32U           *pulFreeByteSize,
                       POS_SEGMENT_CB   psegmentList[],
                       void             *pvReserve1,
                       void             *pvReserve2,
                       void             *pvReserve3);


#if OS_HEAP_CONFIG_TYPE == 0
/*********************************************************************************************************
** Function name:           _osHeapInit
** Descriptions:            OS HEAP �ڴ�����ʼ��
** input parameters:        NONE
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void   _osHeapInit(void);

#else

/*********************************************************************************************************
** Function name:           _osHeapInit
** Descriptions:            OS HEAP �ڴ�����ʼ��
** input parameters:        iMaxHeapNum     �����Խ����Ķѵĸ���
**                          pohBuffer       ���ƿ��ŵ��׵�ַ
** output parameters:       0:  ��ʾ��ȷ
**                          -1: ��ʾ����
** Returned value:          NONE
*********************************************************************************************************/
extern int    _osHeapInit(int  iMaxHeapNum, void  *pohBuffer);

#endif                                                                  /*  OS_HEAP_CONFIG_TYPE == 0   */

#define osHeapInit         _osHeapInit


#endif                                                                  /*  __OS_HEAP_H                 */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
