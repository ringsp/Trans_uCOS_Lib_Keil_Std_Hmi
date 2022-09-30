/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn   
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               afxMenu.c
** Latest modified Date:    2014-12-05
** Latest Version:          1.0
** Descriptions:            
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

#include "..\main.h"


/*********************************************************************************************************
  �ⲿ����
*********************************************************************************************************/


/*********************************************************************************************************
  ��������
*********************************************************************************************************/
static INT32S __menuItemCreate(MENU_ITEM_INFO *pmiibThis);
static INT32S __menuItemDel(MENU_ITEM_INFO *pmiibThis);


/*********************************************************************************************************
  ȫ�ֱ�������
*********************************************************************************************************/
BOOLEAN         __GucEntered;                                           /*  �����޸�״̬��ʶ            */
TREE_NODE      *__GptnRootMenu;                                         /*  �˵����ڵ�                  */
TREE_NODE      *__GptnCurMenu;                                          /*  ��ǰ�˵��ڵ�                */


/*********************************************************************************************************
  �ڲ�ʹ�ñ���
*********************************************************************************************************/
const MENU_ITEM_FUNC GmifRoot = {
    __menuItemCreate,
    __menuItemDel,
    NULL,
    NULL
};

static const  char *const __SscStr[4] = {   "  ������������  ",
                                            "���ٴ�����������",    
                                            " ���������óɹ� ",
                                            " ����������ʧ�� "};

INT8U    __SucIndex;  
static char   __SscParamFmt[32];                                            
/*********************************************************************************************************
** Function name:           menuItemCreate
** Descriptions:            �����˵���
** input parameters:        pmiiThis    �˵�����Ϣ
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
static INT32S __menuItemCreate (MENU_ITEM_INFO *pmiiThis)
{
    INT32S      siErr = 0;
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
    
    return siErr;
}

/*********************************************************************************************************
** Function name:           menuItemDel
** Descriptions:            ɾ���˵���
** input parameters:        pmiiThis    �˵�����Ϣ
** output parameters:       none
** Returned value:          SYS_OK      �ɹ�
**                          ����        ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
static INT32S __menuItemDel (MENU_ITEM_INFO *pmiiThis)
{
    INT32S      siErr = 0;
    pmiiThis = pmiiThis;
   /*  
    *  ����û�����        
    *  ............
    */
    mainDisplay();
    Gds.ucIsAuthorized = FALSE;
    return siErr;    
}
/*********************************************************************************************************
  ���ڵ�˵����
*********************************************************************************************************/
const MENU_ITEM_INFO_BASE __GmiibRoot = {                               /*  �˵�����Ϣ                  */
    "����",
    (MENU_ITEM_FUNC *)&GmifRoot,
    0x0000
};
#if 0
/*********************************************************************************************************
** Function name:           miRootInit
** Descriptions:            ���˵��ڵ��ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void miRootInit(void)
{ 
    /*
     *  ��Ӳ˵�
     */
    miAdd(NULL, &__GmiibRoot);
}
/*********************************************************************************************************
** Function name:           mpRootDel
** Descriptions:            ���˵��ڵ�ж��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void miRootDel (void)
{ 
    /*
     *  ɾ���˵�ҳ
     */
    miDel(&__GmiibRoot);
}
#endif

/*********************************************************************************************************
** Function name:           kbd2Ascii
** Descriptions:            ����ת��Ϊascii��
** input parameters:        uiKbdCode           ����
**                          
** output parameters:       none
** Returned value:          ascii��
**                          
*********************************************************************************************************/
INT8U kbd2Ascii(INT32U  uiKbdCode)
{
    switch (uiKbdCode) {
        case JP_0:
            return '0';
        
        case JP_1:
            return '1';
        
        case JP_2:
            return '2';
        
        case JP_3:
            return '3';
        
        case JP_4:
            return '4';
        
        case JP_5:
            return '5';
        
        case JP_6:
            return '6';
        
        case JP_7:
            return '7';
        
        case JP_8:
            return '8';
        
        case JP_9:
            return '9';
        
        default:
            return 0;        
    }
}
/*********************************************************************************************************
** Function name:           miIsExist
** Descriptions:            ���˵��Ƿ��Ѵ���
** input parameters:        ptnParent       ���ڵ�
**                          pmiib           �����Ĳ˵���
** output parameters:       none
** Returned value:          !NULL           ����
**                          NULL            ������
*********************************************************************************************************/
static TREE_NODE* __miIsExist(TREE_NODE *ptnParent, const MENU_ITEM_INFO_BASE *pmiib)
{
    TREE_NODE      *ptnRtn = NULL;
    TREE_NODE     **pptnWalker;
    MENU_ITEM_INFO *pmii;
    /*
     *  ��������
     */
    if ((NULL == pmiib) ||
        (NULL == ptnParent)) {
        return NULL;
    }
    
    pptnWalker = &ptnParent;//->ptnChild;
    while (*pptnWalker) {
        pmii = (*pptnWalker)->pvData;                             
        if (pmii->pmiib == pmiib) {                                     /*  �ڵ��Ѿ�����                */
            ptnRtn = *pptnWalker;
            break;
        } else if ((*pptnWalker)->ptnChild) {
            ptnRtn = __miIsExist((*pptnWalker)->ptnChild, pmiib);
            if (ptnRtn) {
                break;
            } else {
                pptnWalker = &(*pptnWalker)->ptnNext;
            }
        } else {
            pptnWalker = &(*pptnWalker)->ptnNext;
        }
    }
    return ptnRtn;
}

/*********************************************************************************************************
** Function name:           __miAdd
** Descriptions:            ���Ӳ˵�ҳ
** input parameters:        pmiParent       ���˵���ڵ�
**                          pmiib           Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __miAdd(TREE_NODE *ptnRoot, const MENU_ITEM_INFO_BASE *pmiibParent, const MENU_ITEM_INFO_BASE *pmiibAdd)
{
    TREE_NODE      *ptnParent;
    TREE_NODE      *ptnAdd;
    INT32S          siErr;   
    /*
     *  ��������
     */        
    if ((NULL == pmiibAdd) ||
        (NULL == ptnRoot)) {                                               
        return (-SYS_PARA_ERR);
    }
    if (NULL == pmiibAdd->pmifFunc) {                                   /*  �˿ں����б���Ч            */
        return (-SYS_PARA_ERR);
    }
    
    /*
     *  Ѱ�Ҹ��ڵ�
     */
    //ptnRoot = __GptnRootMenu;
    ptnParent = __miIsExist(ptnRoot, pmiibParent);
    if (NULL == ptnParent) {                                            /*  ���ڵ㲻����                */
        return (-SYS_NO_NODE);
    }
    
    /*
     *  �����ظ��ڵ�
     */
    if (__miIsExist(ptnRoot, pmiibAdd)) {                                 /*  ������ڵ��Ѵ���            */
        return (-SYS_NODE_EXIST);
    }

    /*
     *  ��ӽڵ�
     */
    
    ptnAdd = sysHeapMalloc(sizeof(TREE_NODE));
    if (NULL == ptnAdd) {
        return (-SYS_NO_MEMORY);
    }
    memset(ptnAdd, 0x00, sizeof(TREE_NODE));
    
    (ptnAdd)->pvData = sysHeapMalloc(sizeof(MENU_ITEM_INFO));
    if (NULL == ptnAdd->pvData) {
        sysHeapFree(ptnAdd);
        return (-SYS_NO_MEMORY);
    }
    memset(ptnAdd->pvData, 0x00, sizeof(MENU_ITEM_INFO));

    ((MENU_ITEM_INFO *)ptnAdd->pvData)->pmiib = pmiibAdd; 

    if (ptnParent) {
        sysIrqDisable();
        siErr = treeAddNode(ptnParent, ptnAdd);
        sysIrqEnable();

        if (siErr < 0) {
            sysHeapFree((ptnAdd)->pvData);
            sysHeapFree(ptnAdd);
            return siErr;
        }
    } else {
        ;
    }
    if (pmiibAdd->pmifFunc->pfuncCreate) {
        return pmiibAdd->pmifFunc->pfuncCreate(ptnAdd->pvData);
    }    
    return SYS_OK;
}


/*********************************************************************************************************
** Function name:           __miInsertPrev
** Descriptions:            ͬ����ָ���˵����ǰ�����˵�
** input parameters:        pmiBrother      ͬ���˵���ڵ�
**                          pmiib           Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __miInsertPrev(TREE_NODE *ptnRoot, const MENU_ITEM_INFO_BASE *pmiibBrother, const MENU_ITEM_INFO_BASE *pmiibAdd)
{
    TREE_NODE      *ptnBrother;
    TREE_NODE      *ptnAdd;
    INT32S          siErr;   
    /*
     *  ��������
     */        
    if ((NULL == pmiibAdd) ||
        (NULL == pmiibBrother) ||
        (NULL == ptnRoot)) {                                               
        return (-SYS_PARA_ERR);
    }
    if (NULL == pmiibAdd->pmifFunc) {                                   /*  �˿ں����б���Ч            */
        return (-SYS_PARA_ERR);
    }
    
    /*
     *  Ѱ�Ҹ��ڵ�
     */
    ptnBrother = __miIsExist(ptnRoot, pmiibBrother);
    if (NULL == ptnBrother) {                                           /*  �ֵܽڵ㲻����              */
        return (-SYS_NO_NODE);
    }
    
    /*
     *  �����ظ��ڵ�
     */
    if (__miIsExist(ptnRoot, pmiibAdd)) {                               /*  ������ڵ��Ѵ���            */
        return (-SYS_NODE_EXIST);
    }

    /*
     *  ��ӽڵ�
     */
    
    ptnAdd = sysHeapMalloc(sizeof(TREE_NODE));
    if (NULL == ptnAdd) {
        return (-SYS_NO_MEMORY);
    }
    memset(ptnAdd, 0x00, sizeof(TREE_NODE));
    
    (ptnAdd)->pvData = sysHeapMalloc(sizeof(MENU_ITEM_INFO));
    if (NULL == ptnAdd->pvData) {
        sysHeapFree(ptnAdd);
        return (-SYS_NO_MEMORY);
    }
    memset(ptnAdd->pvData, 0x00, sizeof(MENU_ITEM_INFO));

    ((MENU_ITEM_INFO *)ptnAdd->pvData)->pmiib = pmiibAdd; 


    sysIrqDisable();
    siErr = treeInsertNodeFront(ptnBrother, ptnAdd);
    sysIrqEnable();

    if (siErr < 0) {
        sysHeapFree((ptnAdd)->pvData);
        sysHeapFree(ptnAdd);
        return siErr;
    }

    if (pmiibAdd->pmifFunc->pfuncCreate) {
        return pmiibAdd->pmifFunc->pfuncCreate(ptnAdd->pvData);
    }    
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           __miInsertNext
** Descriptions:            ͬ����ָ���˵���ĺ������˵�
** input parameters:        pmiBrother      ͬ���˵���ڵ�
**                          pmiib           Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __miInsertNext(TREE_NODE *ptnRoot, const MENU_ITEM_INFO_BASE *pmiibBrother, const MENU_ITEM_INFO_BASE *pmiibAdd)
{
    TREE_NODE      *ptnBrother;
    TREE_NODE      *ptnAdd;
    INT32S          siErr;   
    /*
     *  ��������
     */        
    if ((NULL == pmiibAdd) ||
        (NULL == pmiibBrother) ||
        (NULL == ptnRoot)) {                                               
        return (-SYS_PARA_ERR);
    }
    if (NULL == pmiibAdd->pmifFunc) {                                   /*  �˿ں����б���Ч            */
        return (-SYS_PARA_ERR);
    }
    
    /*
     *  Ѱ�Ҹ��ڵ�
     */
    ptnBrother = __miIsExist(ptnRoot, pmiibBrother);
    if (NULL == ptnBrother) {                                           /*  �ֵܽڵ㲻����              */
        return (-SYS_NO_NODE);
    }
    
    /*
     *  �����ظ��ڵ�
     */
    if (__miIsExist(ptnRoot, pmiibAdd)) {                               /*  ������ڵ��Ѵ���            */
        return (-SYS_NODE_EXIST);
    }

    /*
     *  ��ӽڵ�
     */
    
    ptnAdd = sysHeapMalloc(sizeof(TREE_NODE));
    if (NULL == ptnAdd) {
        return (-SYS_NO_MEMORY);
    }
    memset(ptnAdd, 0x00, sizeof(TREE_NODE));
    
    (ptnAdd)->pvData = sysHeapMalloc(sizeof(MENU_ITEM_INFO));
    if (NULL == ptnAdd->pvData) {
        sysHeapFree(ptnAdd);
        return (-SYS_NO_MEMORY);
    }
    memset(ptnAdd->pvData, 0x00, sizeof(MENU_ITEM_INFO));

    ((MENU_ITEM_INFO *)ptnAdd->pvData)->pmiib = pmiibAdd; 


    sysIrqDisable();
    siErr = treeInsertNodePost(ptnBrother, ptnAdd);
    sysIrqEnable();

    if (siErr < 0) {
        sysHeapFree((ptnAdd)->pvData);
        sysHeapFree(ptnAdd);
        return siErr;
    }

    if (pmiibAdd->pmifFunc->pfuncCreate) {
        return pmiibAdd->pmifFunc->pfuncCreate(ptnAdd->pvData);
    }    
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           miAdd
** Descriptions:            ���Ӳ˵�ҳ
** input parameters:        pmiParent       ���˵���ڵ�
**                          pmiib           Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miAdd(const MENU_ITEM_INFO_BASE *pmiibParent, const MENU_ITEM_INFO_BASE *pmiibAdd)
{
    if (!__GptnRootMenu) {                                                 /*  ���ڵ�                      */
        TREE_NODE *ptnRoot;
        if (__GptnRootMenu) {                                           /*  ���ڵ����                  */
            return (-SYS_NODE_EXIST);
        }
        ptnRoot = sysHeapMalloc(sizeof(TREE_NODE));
        if (NULL == ptnRoot) {
            return (-SYS_NO_MEMORY);
        }
        memset(ptnRoot, 0x00, sizeof(TREE_NODE));
        
        ptnRoot->pvData = sysHeapMalloc(sizeof(MENU_ITEM_INFO));
        if (NULL == ptnRoot->pvData) {
            sysHeapFree(ptnRoot);
            return (-SYS_NO_MEMORY);
        }
        memset(ptnRoot->pvData, 0x00, sizeof(MENU_ITEM_INFO));
        ((MENU_ITEM_INFO *)ptnRoot->pvData)->pmiib = &__GmiibRoot;//pmiibAdd; 
        __GptnRootMenu = ptnRoot;
        if (__GmiibRoot.pmifFunc->pfuncCreate) {
            __GmiibRoot.pmifFunc->pfuncCreate(ptnRoot->pvData);
        }        
    }
    return __miAdd(__GptnRootMenu, pmiibParent, pmiibAdd);
}    

/*********************************************************************************************************
** Function name:           __miDel
** Descriptions:            ɾ���Ա��˵���Ϊ���ڵ�Ĳ˵���
** input parameters:        ptnDel         ��ɾ���˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __miDel(TREE_NODE *ptnDel)
{
    MENU_ITEM_INFO *pmiiDel;
    
    TREE_NODE     **pptnWalker;

    INT32S          siErr = 0;
    /*
     *  ��������
     */        
    if (NULL == ptnDel) {
        return (-SYS_PARA_ERR);
    }
    
    pptnWalker = &ptnDel; 
    
    //while (*pptnWalker) {
        while ((*pptnWalker)->ptnChild) {                                  /*  �����ӽڵ�                  */
            __miDel((*pptnWalker)->ptnChild);
        }
    //}
    //    ptnDel = *pptnWalker;
        pmiiDel = (MENU_ITEM_INFO *)ptnDel->pvData;
        
        if (pmiiDel->pmiib->pmifFunc->pfuncDel) {                       /*  �˿�ж�غ�����Ч            */
            pmiiDel->pmiib->pmifFunc->pfuncDel(pmiiDel);
        }
        sysHeapFree(pmiiDel);
        //ptnDel->pvData = NULL;
        sysIrqDisable();                                                /*  �����ٽ�δ���              */
        siErr = treeDelNode(ptnDel);
        sysIrqEnable();                                                 /*  �˳��ٽ�δ���              */       
        if (siErr < 0)
    //        break;
        while (1);
        sysHeapFree(ptnDel);
    //    pptnWalker = &(*pptnWalker)->ptnNext;
    //}
    
    return siErr;
}
/*********************************************************************************************************
** Function name:           miDel
** Descriptions:            ɾ���˵���
** input parameters:        ptnRoot         �˵�����ڵ�
**                          pmiib           ��ɾ���˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miDel(const MENU_ITEM_INFO_BASE *pmiibDel)
{
    TREE_NODE      *ptnDel;
    MENU_ITEM_INFO *pmiiRoot;
    INT32S          siErr;
    INT8U           ucIsRoot = 0;
    /*
     *  ��������
     */
    if (NULL == pmiibDel) {
        return (-SYS_PARA_ERR);
    }
    
    if (NULL == __GptnRootMenu) {                                       /*  �˵���������                */          
        return (-SYS_NO_NODE);
    }
    pmiiRoot = (MENU_ITEM_INFO *)__GptnRootMenu->pvData;
    //ucIsRoot = pmiiRoot->pmiib == pmiibDel;
    
    ptnDel = __miIsExist(__GptnRootMenu, pmiibDel);
    if (NULL == ptnDel) {
        return (-SYS_NO_NODE);
    }
    if (((ptnDel->ptnNext == NULL) && (ptnDel->ptnPrev == NULL) &&
        (ptnDel->ptnParent == __GptnRootMenu)) ||
        (ptnDel == __GptnRootMenu)) {
        ucIsRoot = TRUE;
    }
    siErr = __miDel(ptnDel);
    if (siErr < 0) {
        return siErr;
    }
    
    if  (ucIsRoot) {                                                    /*  ɾ�����ڵ�                  */
        if (ptnDel == __GptnRootMenu) {                                 /*  ���ڵ���ɾ��                */
            ;
        } else {
            __miDel(__GptnRootMenu);
        }
        __GptnRootMenu = NULL;
        __GptnCurMenu = NULL;
    }
    return siErr;
}
/*********************************************************************************************************
** Function name:           __miDelTail
** Descriptions:            ɾ���Ա��˵���Ϊ���ڵ�Ĳ˵����ֵܽڵ��β����ʼɾ
** input parameters:        ptnDel         ��ɾ���˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
static INT32S __miDelTail(TREE_NODE *ptnDel)
{
    MENU_ITEM_INFO *pmiiDel;
    
    TREE_NODE     **pptnWalker;

    INT32S          siErr = 0;
    /*
     *  ��������
     */        
    if (NULL == ptnDel) {
        return (-SYS_PARA_ERR);
    }
    
    
    /*
     *  ɾ���ӽڵ�
     */
    while (ptnDel->ptnChild) {
        TREE_NODE *ptnDelTemp;
        pptnWalker = &ptnDel->ptnChild;
        /*
         *  �����ֵ��е�β���ڵ�
         */
        while ((*pptnWalker)->ptnNext) {
            pptnWalker = &(*pptnWalker)->ptnNext;
        }
        if ((*pptnWalker)->ptnChild) {                                  /*  �����ӽڵ�                  */
            __miDelTail((*pptnWalker));
        }
        ptnDelTemp = *pptnWalker;
        pmiiDel = (MENU_ITEM_INFO *)(*pptnWalker)->pvData;
        
        if (pmiiDel->pmiib->pmifFunc->pfuncDel) {                       /*  �˿�ж�غ�����Ч            */
            pmiiDel->pmiib->pmifFunc->pfuncDel(pmiiDel);
        }
        sysHeapFree(pmiiDel);
        sysIrqDisable();                                                /*  �����ٽ�δ���              */
        siErr = treeDelNode(ptnDelTemp);
        sysIrqEnable();                                                 /*  �˳��ٽ�δ���              */       
        if (siErr < 0)
            return siErr;
        sysHeapFree(ptnDelTemp);
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           miDel
** Descriptions:            ɾ���˵���
** input parameters:        ptnRoot         �˵�����ڵ�
**                          pmiib           ��ɾ���˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miDelTail(const MENU_ITEM_INFO_BASE *pmiibDel)
{
    TREE_NODE      *ptnDel;
    MENU_ITEM_INFO *pmiiRoot;
    INT32S          siErr;
    INT8U           ucIsRoot;
    /*
     *  ��������
     */
    if (NULL == pmiibDel) {
        return (-SYS_PARA_ERR);
    }
    
    if (NULL == __GptnRootMenu) {                                       /*  �˵���������                */          
        return (-SYS_NO_NODE);
    }
    pmiiRoot = (MENU_ITEM_INFO *)__GptnRootMenu->pvData;
    ucIsRoot = pmiiRoot->pmiib == pmiibDel;
    
    ptnDel = __miIsExist(__GptnRootMenu, pmiibDel);
    if (NULL == ptnDel) {
        return (-SYS_NO_NODE);
    }
    siErr = __miDelTail(ptnDel);
    if (siErr < 0) {
        return siErr;
    }

    /*
     *  ɾ������ڵ�
     */
    pmiiRoot = (MENU_ITEM_INFO *)ptnDel->pvData;
    
    if (pmiiRoot->pmiib->pmifFunc->pfuncDel) {                       /*  �˿�ж�غ�����Ч            */
        pmiiRoot->pmiib->pmifFunc->pfuncDel(pmiiRoot);
    }
    sysHeapFree(pmiiRoot);
    sysIrqDisable();                                                /*  �����ٽ�δ���              */
    siErr = treeDelNode(ptnDel);
    sysIrqEnable();                                                 /*  �˳��ٽ�δ���              */       
    if (siErr < 0)
        return siErr;
    sysHeapFree(ptnDel);

    if  (ucIsRoot) {                                                    /*  ɾ�����ڵ�                  */
        __GptnRootMenu = NULL;
    }
    return siErr;
}

/*********************************************************************************************************
** Function name:           miInsertPrev
** Descriptions:            ����ǰ�ò˵�ҳ
** input parameters:        pmiibBrother    �ֵܲ˵���ڵ�
**                          pmiibAdd        Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miInsertPrev(const MENU_ITEM_INFO_BASE *pmiibBrother, const MENU_ITEM_INFO_BASE *pmiibAdd)
{
        /*
     *  ��������
     */        
    if ((NULL == pmiibAdd) ||
        (NULL == pmiibBrother)) {                                               
        return (-SYS_PARA_ERR);
    }
    if (NULL == pmiibAdd->pmifFunc) {                                   /*  �˿ں����б���Ч            */
        return (-SYS_PARA_ERR);
    }
    if (__GptnRootMenu == NULL) {
        return (-SYS_NO_NODE);
    }
    return __miInsertPrev(__GptnRootMenu, pmiibBrother, pmiibAdd);
}
    

/*********************************************************************************************************
** Function name:           miInsertNext
** Descriptions:            ���Ӻ��ò˵�ҳ
** input parameters:        pmiibBrother    �ֵܲ˵���ڵ�
**                          pmiibAdd        Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miInsertNext(const MENU_ITEM_INFO_BASE *pmiibBrother, const MENU_ITEM_INFO_BASE *pmiibAdd)
{
        /*
     *  ��������
     */        
    if ((NULL == pmiibAdd) ||
        (NULL == pmiibBrother)) {                                               
        return (-SYS_PARA_ERR);
    }
    if (NULL == pmiibAdd->pmifFunc) {                                   /*  �˿ں����б���Ч            */
        return (-SYS_PARA_ERR);
    }
    if (__GptnRootMenu == NULL) {
        return (-SYS_NO_NODE);
    }
    return __miInsertNext(__GptnRootMenu, pmiibBrother, pmiibAdd);
}


/*********************************************************************************************************
** Function name:           miFlush
** Descriptions:            ������в˵���
** input parameters:        ptnRoot         �˵����ڵ�
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miFlush(void)
{
    if (NULL == __GptnRootMenu) {
        return (-SYS_NO_NODE);
    }
    /*
     *  ���ֲ˵�����ɾ��������
     */
    //if (miDelTail(((MENU_ITEM_INFO *)__GptnRootMenu->pvData)->pmiib) < 0) {
    //    while (1);
    //}
    if (miDel(((MENU_ITEM_INFO *)__GptnRootMenu->pvData)->pmiib) < 0) {
        while (1);
    }
    __GucEntered = FALSE;
    __SucIndex = 0;
    __GptnCurMenu = NULL;
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           miGetIndex
** Descriptions:            ��ȡָ���˵���������ҳ�е�����
** input parameters:        ptnMenu         �˵����ڵ�
** output parameters:       puiRtn          ��������ָ��
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S miGetIndex(TREE_NODE *ptn, INT32U *puiRtn)
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
    return treeGetIndex(ptn, puiRtn);
}


/*********************************************************************************************************
** Function name:           miIsExist
** Descriptions:            ���˵��Ƿ��Ѵ���
** input parameters:        ptnParent       ���ڵ�
**                          pmiib           �����Ĳ˵���
** output parameters:       none
** Returned value:          TRUE            ����
**                          FALSE           ������
*********************************************************************************************************/
BOOLEAN miIsExist(const MENU_ITEM_INFO_BASE *pmiib)
{
    if (__miIsExist(__GptnRootMenu, pmiib)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
/*********************************************************************************************************
** Function name:           mpDisplay
** Descriptions:            ��ʾ�˵�ҳ����
** input parameters:        pmpiInfo        �˵�ҳ��Ϣ
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S mpDisplay(TREE_NODE *ptnParent)
{
    int i;
    TREE_NODE                  *ptnWalker;
    MENU_ITEM_INFO             *pmii;
    /*
     *  ��������
     */
    if (NULL == ptnParent) {
        return (-SYS_PARA_ERR);
    }
    pmii = (MENU_ITEM_INFO *)ptnParent->pvData;
    guiClrScr();
    guiPrintf((128 - 8 * strlen(pmii->pmiib->pcTitle)) / 2, 0, 0, (char *)pmii->pmiib->pcTitle);                  /*  ��ʾ�˵�ҳ����              */
    /*
     *  ��ʾ�˵���,2��/ҳ
     */
    ptnWalker = ptnParent->ptnChild;

    for (i = 0; i < MAX_MENU_ITEM_PER_PAGE; i++) {
        char scParamFmt[32] = { 0 };
        char scStr[64] = {0};
        if (NULL == ptnWalker) {
            break;
        }
        pmii = ptnWalker->pvData;
        strcpy(scStr, pmii->pmiib->pcTitle);
        if (NULL != pmii->pmiib->pmifFunc->pfuncParamFmt) {
            pmii->pmiib->pmifFunc->pfuncParamFmt(pmii, scParamFmt);
        }
        strcat(scStr, scParamFmt);
        /*
         *  ��ʾ�˵������              
         */

        guiPrintf(0, CAPTION_YSPACE + MENU_ITEM_INTERVAL * i, __GptnCurMenu == ptnWalker, scStr);

        

        pmii->ucX = 0;
        pmii->ucY = CAPTION_YSPACE + MENU_ITEM_INTERVAL * i;

        ptnWalker = ptnWalker->ptnNext;
    }
    
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           mpDisplayEx
** Descriptions:            �˵�ҳ������ʾ
** input parameters:        pmpiInfo        �˵�ҳ��Ϣ
**                          ucCurIndex      �˵�ҳ��ʼ��ʾ�˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S mpDisplayEx(TREE_NODE *ptnParent, INT8U ucCurIndex)
{
    int i;
    MENU_ITEM_INFO             *pmii;
    TREE_NODE                  *ptnWalker;
    /*
     *  ��������
     */
    if (NULL == ptnParent) {
        return (-SYS_PARA_ERR);
    }
    pmii = (MENU_ITEM_INFO *)ptnParent->pvData;
    
    guiClrScr();
    
    guiPrintf((128 - 8 * strlen(pmii->pmiib->pcTitle)) / 2, 0, 0, (char *)pmii->pmiib->pcTitle);                  /*  ��ʾ�˵�ҳ����              */    
    
    ptnWalker = ptnParent->ptnChild;
    for (i = 0; i < ucCurIndex; i++) {
        if (NULL == ptnWalker) {
            return (-SYS_NOT_OK);
        }
        ptnWalker = ptnWalker->ptnNext;
    }
    /*
     *  ��ʾ�˵���
     */
    pmii = (MENU_ITEM_INFO *)ptnWalker->pvData; 
    for (i = 0; i < MAX_MENU_ITEM_PER_PAGE; i++) {                      /*  ��ʾ�˵���                  */
        char scParamFmt[32] = { 0 };
        char scStr[64] = {0};
        if (NULL == ptnWalker) {
            break;
        }
        pmii = (MENU_ITEM_INFO *)ptnWalker->pvData;
        strcpy(scStr, pmii->pmiib->pcTitle);
        if (NULL != pmii->pmiib->pmifFunc->pfuncParamFmt) {
            pmii->pmiib->pmifFunc->pfuncParamFmt(pmii, scParamFmt);
        }
        strcat(scStr, scParamFmt);
        if (__GptnCurMenu == ptnWalker) {                               /*  ��ǰ�˵���                  */
            guiPrintf(0, CAPTION_YSPACE + MENU_ITEM_INTERVAL * i, 1, scStr);                       /*  ��ʾ�˵������              */
        } else {
            guiPrintf(0, CAPTION_YSPACE + MENU_ITEM_INTERVAL * i, 0, scStr);                       /*  ��ʾ�˵������              */
        }
        pmii->ucX = 0;
        pmii->ucY = CAPTION_YSPACE + MENU_ITEM_INTERVAL * i;
        ptnWalker = ptnWalker->ptnNext;
        
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           mpHome
** Descriptions:            ��ʾ�˵���ҳ
** input parameters:        none        
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S mpHome(void)
{   
    INT32S      siErr;
    /*
     *  ��������
     */
    if (NULL == __GptnRootMenu) {
        return (-SYS_NO_NODE);
    }
    
    if (NULL != __GptnRootMenu->ptnChild) {
        if (__GptnRootMenu->ptnChild->ptnChild) {
            __GptnCurMenu = __GptnRootMenu->ptnChild->ptnChild;
        } else {
            __GptnCurMenu = __GptnRootMenu->ptnChild;
        }
        siErr = mpDisplay(__GptnRootMenu->ptnChild); 
    } else {
        __GptnCurMenu = __GptnRootMenu;
        siErr = mpDisplay(__GptnRootMenu);
    }
    return siErr;
}

/*********************************************************************************************************
** Function name:           miOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmpiThis        �˵�ҳ��Ϣ      
**                          usLen           ���ݳ���
**                          pvData          ����ָ��
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
INT32S  miOnKey(INT32U uiKeyCode)
{
    TREE_NODE         **pptnWalker;
    MENU_ITEM_INFO     *pmii;
    
    INT8U               ucMenuIndex = 0;
    INT32U              uiTmp;
    /*
     *  ��������
     */
    
    pmii      = (MENU_ITEM_INFO *)__GptnCurMenu->pvData;
    
    if (__GptnCurMenu->ptnParent == __GptnRootMenu) {                   /*  ֻ�и��ڵ�˵�              */
        //return pmii->pmiib->pmifFunc->pfuncOnkey(pmii, uiKeyCode);
        if (pmii->pmiib->pmifFunc->pfuncOnkey) {
            pmii->pmiib->pmifFunc->pfuncOnkey(pmii, uiKeyCode);
        }
        return;
    }
    // if (__GucEntered) {                                                 
    //     return pmii->pmiib->pmifFunc->pfuncOnkey(pmii, uiKeyCode);
    // }
    /*
     *  ���ݲ�ͬ����Ԥ��pptnWalker
     */
    if  ((uiKeyCode == GpuiKeyTbl[KEY_MENU_LEFT]) ||
         (uiKeyCode == GpuiKeyTbl[KEY_MENU_RIGHT])) {                   /*  ���Ҽ�                      */
        if (__GptnCurMenu->ptnParent == __GptnRootMenu) {               /*  ���Ӳ˵�                    */
            pptnWalker = &__GptnCurMenu;
        } else {                                                        /*  ���Ӳ˵�                    */
            pptnWalker = &__GptnCurMenu->ptnParent;                     /*  �˵�ҳ                      */
        }
    } else {                                                            /*  ��������                    */
        if (__GptnCurMenu->ptnParent == __GptnRootMenu) {               /*  ���Ӳ˵�                    */
            //*pptnWalker = NULL;                                       /*  ����߼�������              */
            if (pmii->pmiib->pmifFunc->pfuncOnkey) {
                return pmii->pmiib->pmifFunc->pfuncOnkey(pmii, uiKeyCode);
            }
        } else {                                                        /*  ���Ӳ˵�                    */
            pptnWalker = &__GptnCurMenu->ptnParent->ptnChild;           /*  �˵���                      */
        }
    }

    /*
     *  ������������
     */
    if (uiKeyCode == GpuiKeyTbl[KEY_MENU_UP]) {                         /*  ��һ���˵���                */ 
        if (*pptnWalker == NULL) {
            ;
        } else if (__GptnCurMenu == (*pptnWalker)) {                    /*  �Ϸ�����                    */
            sysIrqDisable();
            do {                    
                if ((*pptnWalker)->ptnNext == NULL) {
                    __GptnCurMenu = *pptnWalker;
                    break;
                } else {
                    pptnWalker = &(*pptnWalker)->ptnNext;  
                    ucMenuIndex++;
                }
            } while (1);
            sysIrqEnable();
        } else {
            sysIrqDisable();
            do {                    
                if ((*pptnWalker)->ptnNext == __GptnCurMenu) {
                    __GptnCurMenu = *pptnWalker;
                    break;
                } else {
                    pptnWalker = &(*pptnWalker)->ptnNext;  
                    ucMenuIndex++;
                }
            } while (1);
            sysIrqEnable(); 
        }
        mpDisplayEx(__GptnCurMenu->ptnParent, (ucMenuIndex / MAX_MENU_ITEM_PER_PAGE) * MAX_MENU_ITEM_PER_PAGE);
    } else if (uiKeyCode == GpuiKeyTbl[KEY_MENU_DOWN]) {                /*  ��һ���˵���                */  
        if (*pptnWalker == NULL) {
            ;
        } else if (NULL == __GptnCurMenu->ptnNext) {                    /*  �·�����                    */
            __GptnCurMenu = *pptnWalker;
        } else {                
            sysIrqDisable();
            do {                    
                if (*pptnWalker == __GptnCurMenu) {
                    if ((*pptnWalker)->ptnNext) {                        
                        __GptnCurMenu = (*pptnWalker)->ptnNext;
                        ucMenuIndex++;
                    } 
                    break;
                } else {
                    pptnWalker = &(*pptnWalker)->ptnNext;  
                    ucMenuIndex++;
                }
            } while (1);
            sysIrqEnable();
        } 
        mpDisplayEx(__GptnCurMenu->ptnParent, (ucMenuIndex / MAX_MENU_ITEM_PER_PAGE) * MAX_MENU_ITEM_PER_PAGE);                
    } else if (uiKeyCode == GpuiKeyTbl[KEY_MENU_LEFT]) {                /*  ��ҳ                      */
        if (*pptnWalker == NULL) {
            ;
        } else if ((*pptnWalker)->ptnPrev == NULL) {                    /*  ��ҳ                        */            
            do {                                                        /*  ����ĩҳ                    */
                if ((*pptnWalker)->ptnNext == NULL) {
                    break;
                }
                pptnWalker = &(*pptnWalker)->ptnNext;
            } while (1);            
        } else {                                                        /*  ǰһҳ                      */
            pptnWalker = &(*pptnWalker)->ptnPrev;
        }
        if ((*pptnWalker)->ptnChild) {                                  /*  ���Ӳ˵���                  */
            __GptnCurMenu = (*pptnWalker)->ptnChild;
        } else {                                                        /*  ���Ӳ˵���                  */
            __GptnCurMenu = (*pptnWalker);
        }
        mpDisplay(*pptnWalker);
    } else if (uiKeyCode == GpuiKeyTbl[KEY_MENU_RIGHT]) {               /*  �ҷ�ҳ                      */
        if (*pptnWalker == NULL) {
            ;
        } else if ((*pptnWalker)->ptnNext == NULL) {                    /*  βҳ                        */
            pptnWalker = &__GptnRootMenu->ptnChild;                     /*  �ص���ҳ                    */
        } else {
            pptnWalker = &(*pptnWalker)->ptnNext;
        }
        if ((*pptnWalker)->ptnChild) {                                  /*  ���Ӳ˵���                  */
            __GptnCurMenu = (*pptnWalker)->ptnChild;
        } else {                                                        /*  ���Ӳ˵���                  */
            __GptnCurMenu = (*pptnWalker);
        }
        mpDisplay(*pptnWalker);
    } else if (uiKeyCode == GpuiKeyTbl[KEY_ENTER]) {                    /*  ȷ��                        */
        if (__GptnCurMenu->ptnChild) {                                  /*  �����¼��˵�                */
            __GptnCurMenu = __GptnCurMenu->ptnChild;
            mpDisplay(__GptnCurMenu->ptnParent);
        } else if (__GucEntered) {
            if (pmii->pmiib->pmifFunc->pfuncOnkey) {
                pmii->pmiib->pmifFunc->pfuncOnkey(pmii, uiKeyCode);
            }
        } else if (pmii->pmiib->ucType.Bits.ucIsModifiable) {
            if (Gds.ucIsAuthorized) {
                uiTmp = strlen(pmii->pmiib->pcTitle);
                guiPrintf(pmii->ucX + uiTmp * FONT_XSIZE8, pmii->ucY, 1, "?");
                if (pmii->pvPara) {                                     /*  �������˵�                  */
                    __GucEntered = TRUE;
                }    
                Gds.uiAuthorizedTimeoutTick = SEC_TIMER;
            } else {
                miAdd(pmii->pmiib, &__GmiibPwdInput);
                __GptnCurMenu = __GptnCurMenu->ptnChild;
                mpDisplay(__GptnCurMenu);
                __GucEntered = TRUE;
            }
        }
    } else if ((uiKeyCode == GpuiKeyTbl[KEY_ABORT]) &&                   /*  ֹͣ��                      */
               (!__GucEntered)) {                                       /*  δ�����޸�״̬              */
        // if ((__GptnCurMenu->ptnParent) &&
        //     ((*pptnWalker)->ptnParent != __GptnRootMenu) &&
        //     (__GptnCurMenu->ptnParent->ptnParent)) {                    /*  �����ϼ��˵�                */
        //     __GptnCurMenu = __GptnCurMenu->ptnParent->ptnParent->ptnChild;
        //     mpDisplay(__GptnCurMenu->ptnParent);                        /*  ������һ���˵�              */
        // } else {                                                        /*  ���ڵ�״̬                  */
            miFlush();                                                  /*  ���ؿ��н���                */
        //    mainDisplay();
        //    __GucEntered = FALSE;
        // }

    } else {                                                            /*  ��������                    */
        if (pmii->pmiib->pmifFunc->pfuncOnkey) {
            pmii->pmiib->pmifFunc->pfuncOnkey(pmii, uiKeyCode);
        }
    }
    
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           inputPwd
** Descriptions:            �������봦����
** input parameters:        uiKbdCode           ����
**                          uiX                 ���������X����
**                          uiY                 ���������Y����
**                          uiMaxLen            ��������ַ���                         
**                          
** output parameters:       pucRtn              ������������
** Returned value:          TRUE                ���������
**                          FALSE               δ���������
*********************************************************************************************************/
INT8U  inputPwd(INT32U uiX, INT32U uiY, INT32U uiKbdCode, INT32U uiMaxLen, INT8U  *pucRtn)	  
{
    //static INT8U    __SucIndex;
    switch(uiKbdCode) {
        case JP_0:
        case JP_1:
        case JP_2:
        case JP_3:
        case JP_4:
        case JP_5:
        case JP_6:
        case JP_7:
        case JP_8:
        case JP_9:
            if (0 == __SucIndex) {
                guiClrRectangle(uiX + FONT_XSIZE8, uiY, uiX + (uiMaxLen + 1) * FONT_XSIZE8 - 1, uiY + FONT_YSIZE16 - 1);
            }
            if (__SucIndex >= uiMaxLen) {                                       /*  ���������Զ��������        */
                return INPUT_UNCOMPLETED;
            }
            pucRtn[__SucIndex] = kbd2Ascii(uiKbdCode);
            guiPrintf(uiX + __SucIndex * FONT_XSIZE8, uiY, 0, "*");
            __SucIndex++;
            break;
        
        
            
        default:
            if (GpuiKeyTbl[KEY_ENTER] == uiKbdCode) {
            //if (__SucIndex < uiMaxLen) {
            //    return INPUT_UNCOMPLETED;
            //} else {
                __SucIndex = 0;
                return INPUT_COMPLETED;
            //}
            } else if (GpuiKeyTbl[KEY_ABORT] == uiKbdCode) {
                __SucIndex = 0;
                return INPUT_QUIT;
            } 
            break;
    }
    return INPUT_UNCOMPLETED;
} 

/*********************************************************************************************************
** Function name:           inputInt
** Descriptions:            ������ֵ�Ͳ������봦����
** input parameters:        uiKbdCode           ����
**                          pmiiThis            �˵���ָ��
**                          psiRtn              ������ֵ
** output parameters:       fpRtn               �����������ֵָ��
** Returned value:          �ο�afxMenu.h
*********************************************************************************************************/
INT8U inputInt(INT32U uiKbdCode, MENU_ITEM_INFO *pmiiThis, INT32S *psiRtn)
{
    //static INT8U  __SucIndex;
    INT8U           ucErr = INPUT_UNCOMPLETED;
    static INT32U __SuiMaxLen;
    INT32U          uiX, uiY;
    uiX = pmiiThis->ucX + (strlen(pmiiThis->pmiib->pcTitle) + 1) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
   
    switch(uiKbdCode) {
        case JP_0:
        case JP_1:
        case JP_2:
        case JP_3:
        case JP_4:
        case JP_5:
        case JP_6:
        case JP_7:
        case JP_8:
        case JP_9:
            if (0 == __SucIndex) {                                      /*  �״�����                    */
                guiClrRectangle(uiX, uiY, 127, uiY + FONT_YSIZE16 - 1);
                //pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, __SscParamFmt);
                //__SuiMaxLen = strlen(__SscParamFmt) - 1;
                memset(&__SscParamFmt[0], 0x00, sizeof(__SscParamFmt));
            }
            __SscParamFmt[__SucIndex] = kbd2Ascii(uiKbdCode);
            __SucIndex++;
            //GUI_RectangleFill(uiX, uiY, uiX + (__SuiMaxLen + 1) * FONT_XSIZE8 - 1, uiY + FONT_YSIZE16 - 1, 0);            
            guiPrintf(uiX + FONT_XSIZE8, uiY, 0, "%s", __SscParamFmt);
            ucErr = INPUT_UNCOMPLETED;
        break;
        
        default:
            if (uiKbdCode == GpuiKeyTbl[KEY_ENTER]) {
                if (sscanf(__SscParamFmt, "%d", psiRtn)) {                  /*  ��ֵ�����ɹ�                */            
                    ucErr = INPUT_COMPLETED;
                } else {                                                    /*  ��ֵ����ʧ��                */                                                
                    ucErr = INPUT_UNREASONABLE;
                }
                __SucIndex = 0; 
            } else if (uiKbdCode == GpuiKeyTbl[KEY_ABORT]) {
                __SucIndex = 0;
                ucErr = INPUT_QUIT;
            }
        break;
    }
    return ucErr;
}


#if 0

/*********************************************************************************************************
** Function name:           inputInt
** Descriptions:            ������ֵ�Ͳ������봦����
** input parameters:        uiKbdCode           ����
**                          pmiiThis            �˵���ָ��
**                          psiRtn              ������ֵ
** output parameters:       fpRtn               �����������ֵָ��
** Returned value:          �ο�afxMenu.h
*********************************************************************************************************/
INT8U inputInt(INT32U uiKbdCode, MENU_ITEM_INFO *pmiiThis, INT32S *psiRtn)
{

    //static INT8U  __SucIndex;
    INT8U           ucErr = INPUT_UNCOMPLETED;
    static INT32U __SuiMaxLen;
    INT32U          uiX, uiY;
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
   
    switch(uiKbdCode) {
        case KEY_ENTER:
            if (sscanf(__SscParamFmt, "%d", psiRtn)) {                  /*  ��ֵ�����ɹ�                */            
                ucErr = INPUT_COMPLETED;
            } else {                                                    /*  ��ֵ����ʧ��                */                                                
                ucErr = INPUT_UNREASONABLE;
            }
            __SucIndex = 0;  
        break;
        
        case KEY_ESC:
            __SucIndex = 0;
            ucErr = INPUT_QUIT;
        break;
        
        case KEY_0:
        case KEY_1:
        case KEY_2:
        case KEY_3:
        case KEY_4:
        case KEY_5:
        case KEY_6:
        case KEY_7:
        case KEY_8:
        case KEY_9:
        case KEY_MINUS: 
            if (0 == __SucIndex) {                                      /*  �״�����                    */
                pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, __SscParamFmt);
                __SuiMaxLen = strlen(__SscParamFmt) - 1;
                memset(&__SscParamFmt[1], 0x00, sizeof(__SscParamFmt));
            }
            __SscParamFmt[__SucIndex + 1] = kbd2Ascii(uiKbdCode);
            __SucIndex++;
            guiRectangleFill(uiX, uiY, uiX + (__SuiMaxLen + 1) * FONT_XSIZE8 - 1, uiY + FONT_YSIZE16 - 1, 0);
            guiPrintf(uiX + FONT_XSIZE8, uiY, 0, "%s", __SscParamFmt);
            ucErr = INPUT_UNCOMPLETED;
        break;
        
        default:
            
        break;
    }
    return ucErr;
}

/*********************************************************************************************************
** Function name:           inputFloat
** Descriptions:            ��������ֵ�Ͳ������봦����
** input parameters:        uiKbdCode           ����
**                          pmiiThis            �˵���ָ��
**                          pfpRtn              ������ֵ
** output parameters:       fpRtn               �����������ֵָ��
** Returned value:          �ο�afxMenu.h
*********************************************************************************************************/
INT8U inputFloat(INT32U uiKbdCode, MENU_ITEM_INFO *pmiiThis, FP32 *pfpRtn)
{
    //static char   __SscParamFmt[32];
    //static INT8U  __SucIndex;
    INT8U           ucErr = INPUT_UNCOMPLETED;
    static INT32U __SuiMaxLen;
    INT32U          uiX, uiY;
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    
    /*
     *  ��ɽ��������������
     */
    if ((!__GucEntered) && (uiKbdCode != KEY_ENTER)) {
        return ucErr;
    }
    //==================================================================================================    
    switch(uiKbdCode) {
        case KEY_ENTER:
            if (!__GucEntered) {
                guiPrintf(uiX, uiY, 1, "?");
            } else if (sscanf(__SscParamFmt, "%f", pfpRtn)) {           /*  ��ֵ�����ɹ�                */            
                ucErr = INPUT_COMPLETED;
            } else {                                                    /*  ��ֵ����ʧ��                */                                                
                ucErr = INPUT_UNREASONABLE;
            }
            __SucIndex = 0;  
        break;
        
        case KEY_ESC:
            __SucIndex = 0;
            ucErr = INPUT_QUIT;
        break;
        
        case KEY_0:
        case KEY_1:
        case KEY_2:
        case KEY_3:
        case KEY_4:
        case KEY_5:
        case KEY_6:
        case KEY_7:
        case KEY_8:
        case KEY_9:
        case KEY_MINUS:
        case KEY_DOT:  
            if (0 == __SucIndex) {                                      /*  �״�����                    */
                pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, __SscParamFmt);
                __SuiMaxLen = strlen(__SscParamFmt) - 1;
                memset(__SscParamFmt, 0x00, sizeof(__SscParamFmt));
            }
            ucErr = INPUT_UNCOMPLETED;
            if (__SucIndex >= __SuiMaxLen) {
                break;
            }
            __SscParamFmt[__SucIndex] = kbd2Ascii(uiKbdCode);
            __SucIndex++;
            guiRectangleFill(uiX + FONT_XSIZE8, uiY, uiX + (__SuiMaxLen + 1) * FONT_XSIZE8 - 1, uiY + FONT_YSIZE16 - 1, 0);
            guiPrintf(uiX + FONT_XSIZE8, uiY, 0, "%s", __SscParamFmt);
            
        break;
        
        case KEY_DEL:
            ucErr = INPUT_UNCOMPLETED;
            memset(__SscParamFmt, 0x00, sizeof(__SscParamFmt));
            __SucIndex = 0;
            guiRectangleFill(uiX + FONT_XSIZE8, uiY, uiX + (__SuiMaxLen + 1) * FONT_XSIZE8 - 1, uiY + FONT_YSIZE16 - 1, 1);
            
        break;
        default:
            
        break;
    } 
    return ucErr;
}

/*********************************************************************************************************
** Function name:           paraFloatOnKey
** Descriptions:            �����Ͳ����˵������Ӧ����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :  �ɹ�
**                          ����:    ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S paraFloatOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, FP32 *pfpRtn)
{
    INT32U         *puiKeyCode;    
    FP32            fpRtn;
    char            scParamFmt[32];
    INT32U          uiX, uiY;
    INT8U           ucErr;
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    /*
     *  ��������
     */
    if (NULL == pmiiThis) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    puiKeyCode = pvData;
    ucErr = inputFloat(puiKeyCode[0], pmiiThis, &fpRtn);
    if (INPUT_UNCOMPLETED == ucErr) {                                   /*  δ�������                  */
        return SYS_OK;
    }
    if (INPUT_COMPLETED == ucErr) {                                     /*  �����������                */
        pfpRtn[0] = fpRtn;
        if (dsSaveParam(&GdiDevInfo) < 0) {                             /*  ��������ʧ��                */
            dsRecoverParam(&GdiDevInfo);
        } else {
            ;
        }         
    } else if (INPUT_QUIT == ucErr) {                                   /*  �˳�����                    */                              
        ;
    } else if (INPUT_UNREASONABLE == ucErr) {                           /*  ����Ƿ�                    */
        ;
    } else {                                                            /*  ����δ�������              */
        ;
    }
    pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
    guiRectangleFill(uiX, uiY, GUI_LCM_XMAX, uiY + FONT_YSIZE16, 0);
    guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
    __GucEntered = !__GucEntered;
    //mpDisplay(__GpdlsCurMenuPage->pvData);
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           paraIntegerOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :    �ɹ�
**                          ����:       ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S paraIntegerOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT32S *psiRtn)
{
    INT32U     *puiKeyCode;    
    FP32            fpRtn;
    char            scParamFmt[32];
    INT32U          uiX, uiY;
    INT8U           ucErr;
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    /*
     *  ��������
     */
    if (NULL == pmiiThis) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    puiKeyCode = pvData;
    ucErr = inputFloat(puiKeyCode[0], pmiiThis, &fpRtn);
    if (INPUT_COMPLETED == ucErr) {                                     /*  �����������                */
        psiRtn[0] = (INT32S)fpRtn;
        if (dsSaveParam(&GdiDevInfo) < 0) {                         /*  ��������ʧ��                */
            dsRecoverParam(&GdiDevInfo);
        } else {
            ;
        } 
        pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
        guiRectangleFill(uiX, uiY, GUI_LCM_XMAX, uiY + FONT_YSIZE16, 0);
        guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
        __GucEntered = !__GucEntered;
        //mpDisplay(__GpdlsCurMenuPage->pvData);
    } else if (INPUT_QUIT == ucErr) {                                   /*  �˳�����                    */                              
        ;
    } else if (INPUT_UNREASONABLE == ucErr) {                           /*  ����Ƿ�                    */
        ;
    } else {                                                            /*  ����δ�������              */
        ;
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           paraUCharOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :    �ɹ�
**                          ����:       ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S paraUCharOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT8U *pucRtn)
{
  __IFSF_MSG        imMsg;
    INT32U         *puiKeyCode;    
    FP32            fpRtn;
    char            scParamFmt[32];
    INT32U          uiX, uiY;
    INT8U           ucErr;
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    /*
     *  ��������
     */
    if (NULL == pmiiThis) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    puiKeyCode = pvData;
    ucErr = inputFloat(puiKeyCode[0], pmiiThis, &fpRtn);
    if (INPUT_UNCOMPLETED == ucErr) {
        return SYS_OK;
    }
    if ((INPUT_COMPLETED == ucErr) &&                                   /*  �����������                */
        ((fpRtn > 0.0f) &&
        (fpRtn <= 255.0f))) {                                           /*  ������ֵ                    */
        pucRtn[0] = (INT8U)fpRtn;
        if (dsSaveParam(&GdiDevInfo) < 0) {                             /*  ��������ʧ��                */
            dsRecoverParam(&GdiDevInfo);
        } else {
            ;
        };       

    } else if (INPUT_QUIT == ucErr) {                                   /*  �˳�����                    */                              
        ;
    } else if (INPUT_UNREASONABLE == ucErr) {                           /*  ����Ƿ�                    */
        ;
    } else {                                                            /*  ����δ�������              */
        ;
    }
    pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
    guiRectangleFill(uiX, uiY, GUI_LCM_XMAX, uiY + FONT_YSIZE16, 0);
    guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
    return SYS_OK; 
}

/*********************************************************************************************************
** Function name:           paraEnDateOnKey
** Descriptions:            �������ò˵������Ӧ����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :    �ɹ�
**                          ����:       ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S paraEnDateOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT8U *pucRtn)
{
    INT32U     *puiKeyCode;    
    FP32            fpRtn;
    char            scParamFmt[32] = {0};
    INT32U          uiX, uiY;
    INT8U           ucErr;
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    /*
     *  ��������
     */
    if (NULL == pmiiThis) {
        return (-SYS_PARA_ERR);
    }
    if (NULL == pvData) {
        return (-SYS_PARA_ERR);
    }
    puiKeyCode = pvData;
    ucErr = inputFloat(puiKeyCode[0], pmiiThis, &fpRtn);
    if (INPUT_COMPLETED == ucErr) {                                     /*  �����������                */
        pucRtn[0] = (INT8U)fpRtn;
        if (dsSaveParam(&GdiDevInfo) < 0) {                         /*  ��������ʧ��                */
            dsRecoverParam(&GdiDevInfo);
        } else {
            ;
        } 
        pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
        guiRectangleFill(uiX, uiY, GUI_LCM_XMAX, uiY + FONT_YSIZE16, 0);
        guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
        __GucEntered = !__GucEntered;
        //mpDisplay(__GpdlsCurMenuPage->pvData);
    } else if (INPUT_QUIT == ucErr) {                                   /*  �˳�����                    */                              
        ;
    } else if (INPUT_UNREASONABLE == ucErr) {                           /*  ����Ƿ�                    */
        ;
    } else {                                                            /*  ����δ�������              */
        ;
    }
    return SYS_OK;
}

/*********************************************************************************************************
** Function name:           pwdChgOnKey
** Descriptions:            �����޸Ĵ�����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :    �ɹ�
**                          ����:       ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
INT32S pwdChgOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT8U *pucRtn)
{
    INT32U         *puiKeyCode;
    static INT8U  __SucPassword[2][6];
    static INT8U  __SucTimes;
    static INT32U   uiX, uiY;
    INT8U           ucErr;
    char scParamFmt[16];
    puiKeyCode = pvData;
    if ((!__GucEntered) && puiKeyCode[0] == KEY_ESC) {
        __SucTimes = 0;
        return SYS_OK;
    }
    uiX = pmiiThis->ucX + strlen(pmiiThis->pmiib->pcTitle) * FONT_XSIZE8;
    uiY = pmiiThis->ucY;
    if (!__GucEntered && puiKeyCode[0] == KEY_ENTER) {
        guiPrintf(uiX, uiY, 0, "?");
        guiPrintf(0, 0, 0, "%s", __SscStr[__SucTimes]);
        return SYS_OK;
    }
    
    ucErr = inputPwd(uiX + FONT_XSIZE8, uiY, puiKeyCode[0], 6, __SucPassword[__SucTimes]);
    if (INPUT_COMPLETED == ucErr) {
        
        __SucTimes++;
        guiPrintf(0, 0, 0, "%s", __SscStr[__SucTimes]);
        pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
        guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
        
        if (__SucTimes > 1) {                                           /*  ���2������                 */
            if (memcmp(__SucPassword[0], __SucPassword[1], 6)) {
                __SucTimes++;
            } else {
                memcpy(pucRtn, __SucPassword[0], 6);
                if (dsSaveParam(&GdiDevInfo) < 0) {                         /*  ��������ʧ��                */
                    //��ʾ�����������
                    dsRecoverParam(&GdiDevInfo);
                } else {
                    ;
                }
            }
            guiPrintf(0, 0, 0, "%s", __SscStr[__SucTimes]);
            guiPrintf(uiX, uiY, 1, ":");
            __SucTimes = 0;
        } else {
            guiPrintf(uiX, uiY, 1, "?");
            __GucEntered = !__GucEntered;
        }
    } else if (INPUT_QUIT == ucErr) {
        guiPrintf(0, 0, 0, "%s", __SscStr[__SucTimes]);
        pmiiThis->pmiib->pmifFunc->pfuncParamFmt(pmiiThis, scParamFmt);
        guiPrintf(uiX, uiY, 1, "%s", scParamFmt);
    }
    return SYS_OK;
}
#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
