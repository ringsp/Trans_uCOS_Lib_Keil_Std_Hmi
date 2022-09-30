/****************************************Copyright (c)****************************************************
**                            
**
**                                
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               OsHeapLib.c
** Latest modified Date:    2013-08-22
** Latest Version:          1.0
** Descriptions:            ��ջ�ײ㺯����
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2013-08-22
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


#ifndef __OS_HEAP_LIB_H
#define __OS_HEAP_LIB_H

#if     OS_HEAP_CONFIG_TYPE == 0
/*********************************************************************************************************
** Function name:           _osHeapInit
** Descriptions:            OS HEAP �ڴ�����ʼ��
** input parameters:        NONE
**                          
** output parameters:       NONE
**                          
** Returned value:          NONE
*********************************************************************************************************/
extern void _osHeapInit(void);

#else
/*********************************************************************************************************
** Function name:           _osHeapInit
** Descriptions:            OS HEAP �ڴ�����ʼ��
** input parameters:        uiMaxHeapNum    �����Խ����Ķѵĸ���
**                          phcBuf          ���ƿ��ŵ��׵�ַ
** output parameters:       0:  ��ʾ��ȷ
**                          -1: ��ʾ����
** Returned value:          NONE
*********************************************************************************************************/
extern int _osHeapInit(unsigned int uiMaxHeapNum, void  *phcBuf);
#endif
/*********************************************************************************************************
** Function name:           __osHeapBuild
** Descriptions:            ����һ���ڴ��
** input parameters:        pvStartAddr     �ڴ����ʼ��ַ
**                          uiByteSize      �ڴ�ѵĴ�С
** output parameters:       NONE
** Returned value:          �ڴ�ѿ��ƿ�ָ��
*********************************************************************************************************/
extern POS_HEAP_CB  __osHeapBuild(void  *pvStartAddr, unsigned int uiByteSize);

/*********************************************************************************************************
** Function name:           __osHeapDelete
** Descriptions:            ɾ��һ���ڴ��
** input parameters:        ppzhDel         �ڴ�ѿ��ƿ�ָ��ĵ�ַ
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void  *__osHeapDelete(POS_HEAP_CB  pohcDel);

/*********************************************************************************************************
** Function name:           __osHeapAllocate
** Descriptions:            ��һ���ڴ���з���ָ����С���ڴ�
** input parameters:        pzhMem          �ڴ�ѿ��ƿ�ָ��
**                          uiByteSize      ��Ҫ���ڴ��С
** output parameters:       NONE
** Returned value:          �����ڴ����ʼ��ַ
*********************************************************************************************************/
extern void  *__osHeapAllocate(POS_HEAP_CB  pzhMem, unsigned int uiByteSize);

/*********************************************************************************************************
** Function name:           osHeapAllocateAlign
** Descriptions:            ��һ���ڴ���з���ָ����С���ڴ�, ͬʱ������������
**                          �˺���������ڴ������ʹ�� OS_HEAP_OP_SAFE ѡ��Ϊ 1 ʱ, �����ͷ�.
** input parameters:        pzhMem          �ڴ�ѿ��ƿ�ָ��
**                          iiByteSize      ��Ҫ���ڴ��С
**                          iiAlign         ָ���ڴ��������
** output parameters:       NONE
** Returned value:          �����ڴ����ʼ��ַ
*********************************************************************************************************/
extern void  *__osHeapAllocateAlign(POS_HEAP_CB  pzhMem, unsigned int iByteSize, unsigned int uiAlign);

/*********************************************************************************************************
** Function name:           __osHeapFree
** Descriptions:            ����ǰ��õ��ڴ潻�����ڴ��
** input parameters:        pzhMem          �ڴ�ѿ��ƿ�ָ��
**                          pvFree          �����ڴ��С
** output parameters:       NONE
** Returned value:          �ɹ����� NULL ʧ�ܷ��� pvFree
*********************************************************************************************************/
extern void  *__osHeapFree(POS_HEAP_CB  pohMem, void * pvFree);

typedef struct __heap_cb_list {
    INT32U          uiListUsedFlag;
    OS_HEAP_CB     *pohcHeapCb;
} __HEAP_CB_LIST;

#define roundup(a, b)   ((a / b) + \
                        ((a % b) ? 1 : 0)) * \
                        b

#define OSC_ALIGN_SIZE  roundup(sizeof(OS_SEGMENT_CB), OS_HEAP_PAGESIZE)
extern __HEAP_CB_LIST __GhcFreeList;                                    /*  ���жѿ��ƿ�ָ��            */

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
