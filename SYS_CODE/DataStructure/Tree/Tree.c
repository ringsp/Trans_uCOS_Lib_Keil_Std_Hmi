/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               Tree.c
** Latest modified Date:    2021-09-29
** Latest Version:          1.1
** Descriptions:            �����ݽṹʵ��
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2017-02-04
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             ����������
** Modified date:           2021-09-29
** Version:                 1.1
** Descriptions:            ʵ����ͬ���ڵ�Ľڵ�֮���˫������ṹ��ǰ��ָ�룻
**
*********************************************************************************************************/

#include    ".\Tree.h"   

/*********************************************************************************************************
  �ⲿ����
*********************************************************************************************************/


/*********************************************************************************************************
  ��������
*********************************************************************************************************/


/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/


/*********************************************************************************************************
  �ڲ�ʹ�ñ���
*********************************************************************************************************/


/*********************************************************************************************************
** Function name:           treeInit
** Descriptions:            �˵�������ʼ��
** input parameters:        ptnRoot:            ���ڵ�ָ��
** output parameters:       none
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S treeInit(void *ptnRoot)
{
    if (!ptnRoot){
        return (-SYS_PARA_ERR);
    }
    memset(ptnRoot, 0x00, sizeof(TREE_NODE));
    
    return SYS_OK;

}

/*********************************************************************************************************
** Function name:           treeAddNode
** Descriptions:            ����һ���ڵ�
** input parameters:        ptnParent       ���ڵ�
**                          ptnAdd          �����ӽڵ�                        
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S  treeAddNode(TREE_NODE *ptnParent, TREE_NODE *ptnAdd)
{
    TREE_NODE  **pptnTail;
    /*
     *  ��������
     */
    if ((NULL == ptnParent) || (NULL == ptnAdd)) {
        return (-SYS_PARA_ERR);
    }

    /*
     *  ��������β�ڵ�
     */
    pptnTail = &ptnParent->ptnChild;
    do {
        if (NULL == *pptnTail) {                                        /*  ���ӽڵ�                    */
            ptnAdd->ptnPrev = NULL;
            *pptnTail = ptnAdd;
            break;
        } else if ((*pptnTail)->ptnNext == NULL) {                      /*  β�ڵ�                      */
            (*pptnTail)->ptnNext = ptnAdd;
            ptnAdd->ptnPrev = *pptnTail;
            break;
        }
        pptnTail = &(*pptnTail)->ptnNext;        
    } while(1);     
    ptnAdd->ptnParent   = ptnParent;
    ptnAdd->ptnNext     = NULL;
    ptnAdd->ptnChild    = NULL;
    return SYS_OK;
}


/*********************************************************************************************************
** Function name:           treeDelNode
** Descriptions:            ɾ��һ���ڵ�
** input parameters:        ptnParent       ���ڵ�
**                          ptnDel          ��ɾ�ڵ�                         
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S  treeDelNode_(TREE_NODE *ptnParent, void *pvDel)
{
    TREE_NODE **pptnWalker;
    TREE_NODE  *ptnPrev;
    /*
     *  ��������
     */
    if ((NULL == ptnParent) || (NULL == pvDel)){
        return (-SYS_PARA_ERR);
    }
    /*
     *  ����������ͬ����ָ��
     */
    pptnWalker = &ptnParent->ptnChild;
    ptnPrev = ptnParent;
    
    do {
        if (NULL == (*pptnWalker)) {
            return (-SYS_NO_NODE);
        }
        if ((*pptnWalker)->pvData == pvDel) {                           /*  ��ɾ�ڵ�                    */
            break;
        } else {
            ptnPrev = *pptnWalker;
            pptnWalker = &(*pptnWalker)->ptnNext;
        }
    } while(1);
    
    ptnPrev->ptnNext = (*pptnWalker)->ptnNext;                           /*  ɾ���ڵ�                    */   
    sysHeapFree(*pptnWalker);
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           treeDelNode
** Descriptions:            ɾ��һ���ڵ�
** input parameters:        ptnDel          ��ɾ�ڵ�
**                          
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S  treeDelNode(TREE_NODE *ptnDel)
{
    TREE_NODE **pptnWalker;
    TREE_NODE  *ptnPrev;
    TREE_NODE  *ptnParent;
    /*
     *  ��������
     */
    if (NULL == ptnDel) {
        return (-SYS_PARA_ERR);
    }
    //if (ptnDel->ptnChild) {                                             /*  ��Ҷ�ڵ�                    */
    //    return (-SYS_PARA_ERR);
    //}
    ptnParent = ptnDel->ptnParent;
    if (NULL == ptnParent) {                                            /*  ���ڵ�                      */
        return SYS_OK;
    }
    /*
     *  ������ڵ�
     */
    pptnWalker = &ptnParent->ptnChild;
    ptnPrev = ptnParent;
    do {
        if (NULL == (*pptnWalker)) {
            return (-SYS_NO_NODE);
        }
        if (*pptnWalker == ptnDel) {                                    /*  ��ɾ�ڵ�                    */
            break;
        } else {
            ptnPrev = *pptnWalker;
            pptnWalker = &(*pptnWalker)->ptnNext;
        }
    } while(1);
    if (ptnPrev == ptnParent) {                                         /*  �׽ڵ�                      */        
        if ((*pptnWalker)->ptnNext) {                                   /*  ���ֵܽڵ�                  */
            (*pptnWalker)->ptnNext->ptnPrev = NULL;
        } else {                                                        /*  ���ֵܽڵ�                  */
            ;
        }
        ptnPrev->ptnChild = (*pptnWalker)->ptnNext;
    } else {                                                            /*  ���ֵܽڵ�                  */   
        ptnPrev->ptnNext = (*pptnWalker)->ptnNext;
        (*pptnWalker)->ptnNext->ptnPrev = ptnPrev;
    }        
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           treeGetIndex
** Descriptions:            ��ȡָ���ڵ���ͬ���ֵܽڵ��е�����
** input parameters:        ptnM            �˵����ڵ�
** output parameters:       puiRtn          ��������ָ��
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S treeGetIndex(TREE_NODE *ptn, INT32U *puiRtn)
{
    INT32U      uiIndex;
    TREE_NODE  *ptnWalker;
    if ((ptn == NULL) || (puiRtn == NULL)) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == ptn->ptnParent) {
        return (-SYS_NO_NODE);
    }
    /*
     *  ���ֲ˵�����ɾ��������
     */
    ptnWalker = ptn->ptnParent->ptnChild;                               /*  �׸��ӽڵ�                  */
    uiIndex = 0;
    do {
        if (ptnWalker == ptn) {
            *puiRtn = uiIndex;
            break;
        }
        ptnWalker = ptnWalker->ptnNext;
        if (ptnWalker == NULL) {
            return (-SYS_NO_NODE);
        }
        uiIndex++;
    } while (1);
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           treeInsertNodeFront
** Descriptions:            ����һ��ͬ��ǰ�ýڵ�
** input parameters:        ptnBrother      �ֵܽڵ�
**                          ptnAdd          �����ӽڵ�                        
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S  treeInsertNodeFront(TREE_NODE *ptnBrother, TREE_NODE *ptnAdd)
{
    /*
     *  ��������
     */
    if ((NULL == ptnBrother) || (NULL == ptnAdd)) {
        return (-SYS_PARA_ERR);
    }  
    ptnAdd->ptnParent   = ptnBrother->ptnParent;
    ptnAdd->ptnNext     = ptnBrother;
    ptnAdd->ptnPrev     = ptnBrother->ptnPrev;
    ptnAdd->ptnChild    = NULL;
    if (ptnBrother->ptnPrev) {                                          /*  �ֵܽڵ�ԭǰ�ýڵ���Ч      */
        ptnBrother->ptnPrev->ptnNext = ptnAdd;
    }
    
    ptnBrother->ptnPrev = ptnAdd;
    
    if (ptnAdd->ptnPrev == NULL) {                                      /*  ͬ���׽ڵ�                  */
        if (ptnAdd->ptnParent) {
            ptnAdd->ptnParent->ptnChild = ptnAdd;
        }
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           treeInsertNodePost
** Descriptions:            ����һ��ͬ�����ýڵ�
** input parameters:        ptnBrother      �ֵܽڵ�
**                          ptnAdd          �����ӽڵ�                        
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S  treeInsertNodePost(TREE_NODE *ptnBrother, TREE_NODE *ptnAdd)
{
    /*
     *  ��������
     */
    if ((NULL == ptnBrother) || (NULL == ptnAdd)) {
        return (-SYS_PARA_ERR);
    }  
    ptnAdd->ptnParent   = ptnBrother->ptnParent;
    ptnAdd->ptnNext     = ptnBrother->ptnNext;
    ptnAdd->ptnPrev     = ptnBrother;
    ptnAdd->ptnChild    = NULL;
    if (ptnBrother->ptnNext) {                                          /*  �ֵܽڵ�ԭ���ýڵ���Ч      */
        ptnBrother->ptnNext->ptnPrev = ptnAdd;
    }
    
    ptnBrother->ptnNext = ptnAdd;
    return SYS_OK;
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
