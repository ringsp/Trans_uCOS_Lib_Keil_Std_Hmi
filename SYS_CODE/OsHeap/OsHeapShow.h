/****************************************Copyright (c)****************************************************
**                            
**
**                                
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               OsHeapShow.h
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
extern INT32S osHeapStatus(POS_HEAP_CB  pohMem,
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
extern INT32S osHeapStatusEx (POS_HEAP_CB     pohMem,
                    INT32U           *pulByteSize,
                    INT32U           *pulSegmentCounter,
                    INT32U           *pulUsedByteSize,
                    INT32U           *pulFreeByteSize,
                    POS_SEGMENT_CB   psegmentList[],
                    void             *pvReserve1,
                    void             *pvReserve2,
                    void             *pvReserve3);
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
