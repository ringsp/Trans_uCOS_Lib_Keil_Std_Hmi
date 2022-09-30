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
#ifndef __LIST_H
#define __LIST_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

#include    "..\SYS_CODE\Head\system.h" 




/*
 *  ������ƿ����ݽṹ
 */
typedef struct __list_cb {
    void                   *pls;                                        /*  ����ָ��                    */
    INT32U                  uiMaxNode;                                  /*  �������ڵ���              */
    void                   *pvFreeNode;                                 /*  ����ǰ���нڵ�            */
    void                   *pvFirstNode;                                /*  ����ռ�õ��׽ڵ�          */
} __LIST_CB, *__PLIST_CB;


/*
 *  ͨ�õ��������ݽṹ
 */
typedef struct __single_list {
    struct __single_list   *pslsNext;                                   /*  ������һ��Ԫ��              */
    void                   *pvData;                                     /*  ���ڵ�����ָ��              */
} __SINGLE_LIST, *__PSINGLE_LIST;


/*
 *  ͨ��˫�������ݽṹ
 */
typedef struct __dual_list {
    struct __dual_list     *pdlsPrev;                                   /*  ����ǰһ���ڵ�              */    
    struct __dual_list     *pdlsNext;                                   /*  ������һ���ڵ�              */

    void                   *pvData;                                     /*  ���ڵ�����ָ��              */
} __DUAL_LIST, *__PDUAL_LIST;



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
extern INT32S  lsInit(__LIST_CB *plcb, INT32U uiMaxNode);

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
extern INT32S  lsNodeAdd(__LIST_CB *plcb, void *pvData);

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
extern INT32S  lsNodeDel(__LIST_CB *plcb, void *pvData);

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
extern INT32S  dlsInit(__LIST_CB *plcb, INT32U uiMaxNode);

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
extern INT32S  dlsNodeAdd(__LIST_CB *plcb, void *pvData);


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
extern INT32S  dlsNodeDel(__LIST_CB *plcb, void *pvData);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __LIST_H                */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
