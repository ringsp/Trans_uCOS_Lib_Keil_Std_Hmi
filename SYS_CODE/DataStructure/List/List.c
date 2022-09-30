/****************************************Copyright (c)****************************************************
**                            
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               List.c
** Latest modified Date:    2014-12-05
** Latest Version:          1.0
** Descriptions:            �������ݽṹʵ��
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2014-12-05
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

#include    ".\List.h"   

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


#if 0
/*********************************************************************************************************
** Function name:           lsInit
** Descriptions:            ��һ�ڴ���ϳ�ʼ��������
** input parameters:        plcb            �������ŵ�ַ
**                          uiMaxNode       �������������
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  lsInit(__LIST_CB *plcb, INT32U uiMaxNode)
{
    int i;
    __SINGLE_LIST  *psls;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (0 == uiMaxNode) {
        return (-SYS_PARA_ERR);
    }
    /*
     *  ������ƿ����ݳ�ʼ��
     */
    memset(plcb, 0x00, sizeof(__LIST_CB) + uiMaxNode * sizeof(__SINGLE_LIST));
    plcb->pvFirstNode   = NULL;    
    plcb->pvFreeNode    = (void *)((INT32U)plcb + sizeof(__LIST_CB));
    plcb->uiMaxNode     = uiMaxNode;
    plcb->pls = plcb->pvFreeNode;
    psls = plcb->pls;
    /*  
     *  ��������                    
     */
    for (i = 0; i < uiMaxNode - 1; i++) {                              
        psls[i].pslsNext = &psls[i + 1];
        
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           lsNodeAdd
** Descriptions:            ����������һ���ڵ�
** input parameters:        plcb            �������ŵ�ַ
**                          pvData          �ڵ������ָ��
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  lsNodeAdd(__LIST_CB *plcb, void *pvData)
{
    int i;
    __SINGLE_LIST  *psls;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    /*
     *  ����������ͬ����ָ��
     */
    psls = plcb->pvFirstNode;
    sysIrqDisable();
    do {
        if (NULL == psls) {
            break;
        }
        if (psls->pvData == pvData) {                                   /*  �ظ��ڵ�                    */
            sysIrqEnable();
            return (-SYS_NODE_EXIST);
        } else {
            psls = psls->pslsNext;
        }
    } while(1);
    psls = plcb->pvFreeNode;
    if (NULL == psls) {                                                 /*  �����޿��нڵ�              */
        return (-SYS_NODE_FULL);
    }
    psls->pvData = pvData;
    plcb->pvFreeNode = psls->pslsNext;
    psls->pslsNext = NULL;
        
    if (NULL == plcb->pvFirstNode) {                                    /*  ����ڵ�δ��ռ��            */
        plcb->pvFirstNode = psls;
    }
    
    sysIrqEnable();
    return SYS_OK;
}


/*********************************************************************************************************
** Function name:           lsNodeDel
** Descriptions:            ������ɾ��һ���ڵ�
** input parameters:        plcb            �������ŵ�ַ
**                          pvData          �ڵ������ָ��
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  lsNodeDel(__LIST_CB *plcb, void *pvData)
{
    int i;
    __SINGLE_LIST  *psls, *pslsPrev = NULL;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    /*
     *  ����������ͬ����ָ��
     */
    psls = plcb->pvFirstNode;
    sysIrqDisable();
    do {
        if (NULL == psls) {
            sysIrqEnable();
            return (-SYS_NO_NODE);
        }
        if (psls->pvData == pvData) {                                   /*  �ظ��ڵ�                    */
            break;
        } else {
            pslsPrev= psls;
            psls    = psls->pslsNext;
        }
    } while(1);
    
    
    if (NULL == pslsPrev) {                                             /*  ɾ���׽ڵ�                  */
        plcb->pvFirstNode = psls->pslsNext;    
    } else {                                                            /*  ɾ���м�ڵ�                */
        pslsPrev->pslsNext = psls->pslsNext;
    }
    psls->pslsNext = plcb->pvFreeNode;
    plcb->pvFreeNode = psls;
    
    sysIrqEnable();
    return SYS_OK;
}
#endif
/*********************************************************************************************************
** Function name:           dlsInit
** Descriptions:            ��һ�ڴ���ϳ�ʼ��˫����
** input parameters:        plcb            ˫�����ŵ�ַ
**                          uiMaxNode       ˫�����������
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  dlsInit(__LIST_CB *plcb, INT32U uiMaxNode)
{
    int i;
    __DUAL_LIST  *pdls;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (0 == uiMaxNode) {
        return (-SYS_PARA_ERR);
    }
    /*
     *  ������ƿ����ݳ�ʼ��
     */
    memset(plcb, 0x00, sizeof(__LIST_CB) + uiMaxNode * sizeof(__DUAL_LIST));
    plcb->pvFirstNode   = NULL;    
    plcb->pvFreeNode    = (void *)((INT32U)plcb + sizeof(__LIST_CB));
    plcb->uiMaxNode     = uiMaxNode;
    plcb->pls = plcb->pvFreeNode;
    pdls = plcb->pls;
    /*  
     *  ��������                    
     */
    for (i = 0; i < uiMaxNode - 1; i++) {                              
        pdls[i].pdlsNext = &pdls[i + 1];
        
    }
    for (i = uiMaxNode - 1; i > 0; i--) {
        pdls[i].pdlsPrev = &pdls[i - 1];
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           dlsNodeAdd
** Descriptions:            ˫��������һ���ڵ�
** input parameters:        plcb            ˫������ƿ�ָ��
**                          pvData          �ڵ������ָ��
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  dlsNodeAdd(__LIST_CB *plcb, void *pvData)
{
    __DUAL_LIST  *pdls, *pdlsPrev;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    /*
     *  ����������ͬ����ָ��
     */
    pdls        = plcb->pvFirstNode;
    pdlsPrev    = pdls;
    sysIrqDisable();
    do {
        if (NULL == pdls) {                                             /*  ����ڵ�δ��ռ��            */
            break;
        }
        if (pdls->pvData == pvData) {                                   /*  �ظ��ڵ�                    */
            sysIrqEnable();
            return (-SYS_NODE_EXIST);
        } else {
            pdlsPrev= pdls;
            pdls    = pdls->pdlsNext;
        }
    } while(1);
    
    if (NULL == plcb->pvFreeNode) {                                     /*  �����޿��нڵ�              */
        return (-SYS_NODE_FULL);
    }
    /*
     *  ����ڵ�
     */    
    
    pdls = plcb->pvFreeNode;
    
    
    plcb->pvFreeNode = pdls->pdlsNext;
    pdls->pvData = pvData;      
    if (NULL != pdls->pdlsNext) {                                       /*  ��������׽ڵ�              */
        pdls->pdlsNext->pdlsPrev = NULL;
    }
    pdls->pdlsNext = NULL;
  
    if (NULL == plcb->pvFirstNode) {                                    /*  ����ڵ�δ��ռ��            */
        plcb->pvFirstNode = pdls;
    } else {                                                            /*  β������                    */
        pdls->pdlsPrev      = pdlsPrev;
        pdlsPrev->pdlsNext  = pdls;
    }
    sysIrqEnable();
    return SYS_OK;
}


/*********************************************************************************************************
** Function name:           dlsNodeDel
** Descriptions:            ˫����ɾ��һ���ڵ�
** input parameters:        plcb            ˫������ƿ�ָ��
**                          pvData          �ڵ������ָ��
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  dlsNodeDel(__LIST_CB *plcb, void *pvData)
{
    __DUAL_LIST  *pdls, *pdlsPrev = NULL;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    /*
     *  ����������ͬ����ָ��
     */
    pdls = plcb->pvFirstNode;
    sysIrqDisable();
    do {
        if (NULL == pdls) {                                             /*  ����ȫ���ǿ��нڵ�          */
            sysIrqEnable();
            return (-SYS_NO_NODE);
        }
        if (pdls->pvData == pvData) {                                   /*  �ҵ���ɾ���ڵ�              */
            break;
        } else {                                                        /*  ������һ���ڵ�              */
            pdlsPrev= pdls;
            pdls    = pdls->pdlsNext;
        }
    } while(1);
    
    
    if (NULL == pdlsPrev) {                                             /*  ɾ���׽ڵ�                  */
        plcb->pvFirstNode = pdls->pdlsNext;    
        if (pdls->pdlsNext) {                                           /*  �µ��׽ڵ�ǰ��ָ��NULL      */
        	pdls->pdlsNext->pdlsPrev = NULL;
        }
    } else {                                                            /*  ɾ���м�ڵ�                */
        pdlsPrev->pdlsNext = pdls->pdlsNext;
        if (pdls->pdlsNext) {
            pdls->pdlsNext->pdlsPrev = pdlsPrev;
        }
        pdls->pdlsPrev = NULL;
    }
    pdls->pdlsNext = plcb->pvFreeNode;
    
    //pdls->pdlsNext->pdlsPrev = pdls;
    if (plcb->pvFreeNode) {
        ((__DUAL_LIST *)plcb->pvFreeNode)->pdlsPrev = pdls;
    }
    plcb->pvFreeNode = pdls;
    
    sysIrqEnable();
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           dlsNodeInsert
** Descriptions:            ˫�������һ���ڵ�
** input parameters:        plcb            ˫������ƿ�ָ��
**                          pvDataTail      ����β��λ��
**                          pvData          ������ڵ������ָ��
**                         
**                          
** output parameters:       SYS_OK
** Returned value:          >=0             �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  dlsNodeInsert(__LIST_CB *plcb, void *pvDataTail, void *pvData)
{
    __DUAL_LIST  *pdlsTail, *pdls;
    /*
     *  ��������
     */
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvDataTail) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    
    if (NULL == plcb->pvFirstNode) {
        return (-SYS_NO_NODE);
    }
    
    /*
     *  ���Ҳ���λ��
     */
    pdlsTail    = plcb->pvFirstNode;
    sysIrqDisable();
    do {
        if (NULL == pdlsTail) {                                         /*  ����ڵ㲻����              */
            sysIrqEnable();
            return (-SYS_NO_NODE);
        }
        if (pdlsTail->pvData == pvDataTail) {                           /*  �ҵ�����λ��                */
            break;
        } else {
            pdlsTail    = pdlsTail->pdlsNext;
        }
    } while(1);
    /*
     *  ���Ҵ�����ڵ�
     */
    pdls        = plcb->pvFreeNode;
    do {
        if (NULL == pdls) {                                             /*  ����ڵ����                */
            sysIrqEnable();
            return (-SYS_NODE_EXIST);
        }
        if (pdls->pvData == pvData) {                                   /*  �ҵ�����λ��                */
            break;
        } else {
            pdls    = pdls->pdlsNext;
        }
    } while(1);
    
    /*
     *  ����ڵ�
     */    
    
    pdlsTail->pdlsNext  = pdls;
    pdls->pdlsPrev      = pdlsTail;
     
    if (NULL != pdls->pdlsPrev) {                                       /*  ��������׽ڵ�              */
        pdls->pdlsPrev->pdlsNext = pdls->pdlsNext;
    } 
    if (NULL != pdls->pdlsNext) {
        pdls->pdlsNext->pdlsPrev = pdls->pdlsPrev;
    }
    sysIrqEnable();
    return SYS_OK;
}
/*********************************************************************************************************
** Function name:           dlsNodeAdd
** Descriptions:            ˫��������һ���ڵ�
** input parameters:        plcb            ˫������ƿ�ָ��
**                          pvData          �ڵ������ָ��
**                         
**                          
** output parameters:       pdlsRtn         �ڵ�ָ��
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S  dlsNodeFind(__DUAL_LIST *pdlsRtn, __LIST_CB *plcb, void *pvData)
{
    __DUAL_LIST            *pdls;
    /*
     *  ��������
     */
    if (NULL == pdlsRtn) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == plcb) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    pdls = plcb->pvFirstNode;
    sysIrqDisable();
    do {
        if (NULL == pdls) {                                             /*  ��Ѱ���                    */
            sysIrqEnable();
            return (-SYS_NO_NODE);
        }
        if (pdls->pvData == pvData) {
            break;
        }
        pdls = pdls->pdlsNext;
    } while(1);
    
    sysIrqEnable();
    pdlsRtn = pdls;
    return SYS_OK;
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
