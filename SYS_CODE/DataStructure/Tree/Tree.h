/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               List.h
** Latest modified Date:    2014-12-05
** Latest Version:          1.0.0
** Descriptions:            �������ݽṹ
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2014-12-05
** Version:                 1.0.0
** Descriptions:            The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#ifndef __TREE_H
#define __TREE_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

#include    "..\SYS_CODE\Head\system.h" 


/*
 *  ���ڵ����ݽṹ
 */
typedef struct __tree_node {
    struct __tree_node     *ptnPrev;                                    /*  ��ڵ�                      */
    struct __tree_node     *ptnNext;                                    /*  �ҽڵ�                      */
    struct __tree_node     *ptnParent;                                  /*  ���ڵ�                      */
    struct __tree_node     *ptnChild;                                   /*  �ӽڵ�                      */
    void                   *pvData;                                     /*  �ڵ�����                    */
} TREE_NODE, *PTREE_NODE;


/*********************************************************************************************************
** Function name:           treeInit
** Descriptions:            �˵�������ʼ��
** input parameters:        ptnRoot:            ���ڵ�ָ��
** output parameters:       none
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S treeInit(void *ptnRoot);

/*********************************************************************************************************
** Function name:           treeAddNode
** Descriptions:            ����һ���ڵ�
** input parameters:        ptnParent       ���ڵ�
**                          ptnAdd          �����ӵĽڵ�
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S  treeAddNode(TREE_NODE *ptnParent, TREE_NODE *ptnAdd);

/*********************************************************************************************************
** Function name:           treeDelNode
** Descriptions:            ɾ��һ���ڵ�
** input parameters:        ptnParent       ���ڵ�
**                          ptnDel          ��ɾ�ڵ�
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S  treeDelNode(TREE_NODE *ptnDel);

/*********************************************************************************************************
** Function name:           treeGetIndex
** Descriptions:            ��ȡָ���ڵ���ͬ���ֵܽڵ��е�����
** input parameters:        ptnM            �˵����ڵ�
** output parameters:       puiRtn          ��������ָ��
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S treeGetIndex(TREE_NODE *ptn, INT32U *puiRtn);


/*********************************************************************************************************
** Function name:           treeInsertNodeFront
** Descriptions:            ����һ��ͬ��ǰ�ýڵ�
** input parameters:        ptnBrother      �ֵܽڵ�
**                          ptnAdd          �����ӽڵ�                        
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S  treeInsertNodeFront(TREE_NODE *ptnBrother, TREE_NODE *ptnAdd);

/*********************************************************************************************************
** Function name:           treeInsertNodePost
** Descriptions:            ����һ��ͬ�����ýڵ�
** input parameters:        ptnBrother      �ֵܽڵ�
**                          ptnAdd          �����ӽڵ�                        
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S  treeInsertNodePost(TREE_NODE *ptnBrother, TREE_NODE *ptnAdd);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TREE_H                    */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
