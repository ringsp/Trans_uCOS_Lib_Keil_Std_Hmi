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

/*********************************************************************************************************
** Function name:           __osSegmentDelFree
** Descriptions:            ɾ��һ�����ж�
** input parameters:        posc            ��Ҫɾ���Ķ�ָ��
**                          pposcFree       ��ǰ���ж�ָ��ĵ�ַ
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void  __osSegmentDelFree(OS_SEGMENT_CB  *posc, POS_SEGMENT_CB *pposcFree);

/*********************************************************************************************************
** Function name:           __osSegmentAddAheadFree
** Descriptions:            ����һ�����ж�
** input parameters:        posc            ��Ҫ���ӵĶ�ָ��
**                          pposcFree       ��ǰ���ж�ָ��ĵ�ַ
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void  __osSegmentAddAheadFree(OS_SEGMENT_CB  *posc, POS_SEGMENT_CB *pposcFree);
/*********************************************************************************************************
** Function name:           __osSegmentDelNeighbor
** Descriptions:            ɾ��һ�����ڶ�
** input parameters:        posc            ��Ҫɾ���Ķ�ָ��
**                          pposcNeighbor   ��ǰ���ж�ָ��ĵ�ַ
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void  __osSegmentDelNeighbor(OS_SEGMENT_CB  *posc, POS_SEGMENT_CB *pposcNeighbor);

/*********************************************************************************************************
** Function name:           __osSegmentAddTailNeighbor
** Descriptions:            ����һ�����ڶ�
** input parameters:        posc            ��Ҫ���ӵĶ�ָ��
**                          pposcNeighbor   ��ǰ���ж�ָ��ĵ�ַ
** output parameters:       NONE
** Returned value:          NONE
*********************************************************************************************************/
extern void  __osSegmentAddTailNeighbor(OS_SEGMENT_CB  *posc, POS_SEGMENT_CB *pposcNeighbor);




/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
