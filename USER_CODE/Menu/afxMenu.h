/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn  
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               afxMenu.h
** Latest modified Date:    2014-12-05
** Latest Version:          1.0.0
** Descriptions:            
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
#ifndef __AFX_MENU_H
#define __AFX_MENU_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

#include    "..\SYS_CODE\Head\system.h" 


    
#define FONT_XSIZE8         8
#define FONT_YSIZE16        16
#define GUI_LCM_XMAX        128
#define GUI_LCM_YMAX        64
/*********************************************************************************************************
  �˵����������
*********************************************************************************************************/
struct menu_item_info;
struct menu_item_func {
    /*
     *  ���캯��
     */
    INT32S    (*pfuncCreate)(struct menu_item_info *pmiibThis);

    /*
     *  ��������
     */
    INT32S    (*pfuncDel)(struct menu_item_info *pmiibThis);

    /*
     *  �˵������Ӧ����
     */
    INT32S    (*pfuncOnkey)(struct menu_item_info *pmiibThis,
                                  INT32U               uiKeyCode);
    /*
     *  �˵���󶨲�����ʽ���ַ���
     */
    INT32S    (*pfuncParamFmt)(struct menu_item_info *pmiibThis,
                                  void                *pvRsv);                              
};
typedef  struct menu_item_func      MENU_ITEM_FUNC;


/*********************************************************************************************************
  �˵������ݽṹ��Ϣ
*********************************************************************************************************/
typedef enum {
    PARA_TYPE_OPERATE,                                                  /*  ����                        */
    PARA_TYPE_EN_DISABLE,                                               /*  ��ֹ����                    */
    PARA_TYPE_LEFT_RIGHT,                                               /*  ��/����                     */
    PARA_TYPE_ON_OFF,                                                   /*  ��/��                       */
    PARA_TYPE_IN_OUT_NONE,                                              /*  ��/��/��                    */
    PARA_TYPE_FRT_REAR_NONE,                                            /*  ǰ/��/��                    */
    PARA_TYPE_UP_DOWN_NONE,                                             /*  ��/��/��                    */
    PARA_TYPE_LEFT_RIGHT_NONE,                                          /*  ��/��/��                    */
    PARA_TYPE_VALUE,                                                    /*  ����                        */
    PARA_TYPE_SWITCH,                                                   /*  ��/��                       */
    PARA_TYPE_SIGNAL_PRESENT,                                           /*  ��/���ź�                   */
    PARA_TYPE_AIM_REACH,                                                /*  �ﵽ/δ�ﵽ                 */
} __PARA_TYPE;

typedef enum {
    PARA_SCOPE_GLOBAL,                                                  /*  ȫ��                        */
    PARA_SCOPE_LOCAL,                                                   /*  �ֲ�                        */
    PARA_SCOPE_OPTIONAL,                                                /*  ��ѡ                        */
} __PARA_SCOPE;

typedef union {
    INT8U                       ucWord;
    struct {
      __PARA_TYPE               ucType          :5;
      __PARA_SCOPE              ucScope         :2;
        INT8U                   ucIsModifiable  :1;
    } Bits;
} PARA_TYPE;
/*
 *  �˵��������Ϣ
 */
typedef struct menu_item_info_base {
    const char                 *pcTitle;                                /*  �˵������                  */
    MENU_ITEM_FUNC             *pmifFunc;                               /*  �����б�                    */ 
    INT16U                      ulAddrStart;                            /*  �˵�ҳ���                  */
    //INT8U                       ucIsModifiable;                         /*  ���޸Ĳ����˵���ʶ          */
    PARA_TYPE                   ucType;                                 /*  �˵�����
                                                                         *  0 ����
                                                                         *  1 ����
                                                                         * 
                                                                         * 
                                                                         * 
                                                                         * 
                                                                         */  
    // INT8U                       ucIsGlobal;                             /*  ������
    //                                                                      *  1 ȫ��
    //                                                                      *  2 �ֲ�
    //                                                                      *  3 ȫ��/�ֲ���ѡ
    //                                                                      */                                                                                              
} MENU_ITEM_INFO_BASE, *PMENU_ITEM_INFO_BASE;

typedef struct menu_item_info {
    const MENU_ITEM_INFO_BASE  *pmiib;                                  /*  �˵��������Ϣָ��          */
    void                       *pvPara;                                 /*  �˵���󶨲���ָ��          */
    INT8U                       ucX;                                    /*  ������ʾ����X               */
    INT8U                       ucY;                                    /*  ������ʾ����Y               */                        
} MENU_ITEM_INFO, *PMENU_ITEM_INFO;


#if 0
/*
 *  �˵���������ݽṹ
 */
typedef struct __menu_item_node {
    TREE_NODE                   tnMenu;                                 /*  �˵��ڵ�                    */
    MENU_ITEM_INFO             *pmiiData;                               /*  �˵�������                  */
} MENU_ITEM_NODE, *PMENU_ITEM_NODE;
#endif


/*
 *  �˵���غ궨��
 */

#define MAX_MENU_PAGE_NUM           0x10                                /*  �˵�ҳ�����                */                
#define MAX_MENU_ITEM_PER_PAGE      0x02                                /*  ÿҳ�˵��������            */
#define CAPTION_YSPACE              24                                  /*  �˵�ҳ����Yռλ             */
#define CAPTION_XSTART              16                                  /*  �˵�ҳ������ʾX��ʼλ��     */
#define MENU_ITEM_INTERVAL          24                                  /*  �˵�����                  */

#define GUEST_LEVEL                 0x00                                /*  �û�ģʽ                    */
#define ADMIN_LEVEL                 0x01                                /*  ������ģʽ                  */
#define DEVELOPER_LEVEL             0x02                                /*  ������ģʽ                  */


#define MIN_KEY_LAG                 400                                 /*  �˵�����������Сʱ����ms  */             


#define INPUT_UNCOMPLETED           0x00                                /*  ����δ���                  */
#define INPUT_COMPLETED             0x01                                /*  �������                    */
#define INPUT_QUIT                  0x02                                /*  �����˳�                    */
#define INPUT_UNREASONABLE          0x03                                /*  ���벻����                  */
#define INPUT_PARA_ERR              0xff                                /*  �����߲���������            */



/*********************************************************************************************************
** Function name:           miRootInit
** Descriptions:            ���˵��ڵ��ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void miRootInit(void);

/*********************************************************************************************************
** Function name:           mpRootDel
** Descriptions:            ���˵��ڵ�ж��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void miRootDel (void);

/*********************************************************************************************************
** Function name:           miTreeInit
** Descriptions:            �˵�������ʼ��
** input parameters:        pminRoot        �˵�����ڵ�
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miInit(const MENU_ITEM_INFO_BASE *pmiibRoot);

/*********************************************************************************************************
** Function name:           miAdd
** Descriptions:            ���Ӳ˵�ҳ
** input parameters:        pmiParent       ���˵���ڵ�
**                          pmiib           Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miAdd(const MENU_ITEM_INFO_BASE *pmiibParent, const MENU_ITEM_INFO_BASE *pmiib);

/*********************************************************************************************************
** Function name:           miDel
** Descriptions:            ɾ���˵���
** input parameters:        ptnRoot         �˵�����ڵ�
**                          pmiib           ��ɾ���˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miDel(const MENU_ITEM_INFO_BASE *pmiibDel);

/*********************************************************************************************************
** Function name:           miDel
** Descriptions:            ɾ���˵���
** input parameters:        pmiParent       ���˵���ڵ�
**                          pmiib           ��ɾ���˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miFindDel(TREE_NODE *pmiParent, const MENU_ITEM_INFO_BASE *pmiib);


/*********************************************************************************************************
** Function name:           miInsertPrev
** Descriptions:            ����ǰ�ò˵�ҳ
** input parameters:        pmiibBrother    �ֵܲ˵���ڵ�
**                          pmiibAdd        Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miInsertPrev(const MENU_ITEM_INFO_BASE *pmiibBrother, const MENU_ITEM_INFO_BASE *pmiibAdd);


/*********************************************************************************************************
** Function name:           miInsertNext
** Descriptions:            ���Ӻ��ò˵�ҳ
** input parameters:        pmiibBrother    �ֵܲ˵���ڵ�
**                          pmiibAdd        Ҫ���ӵĲ˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miInsertNext(const MENU_ITEM_INFO_BASE *pmiibBrother, const MENU_ITEM_INFO_BASE *pmiibAdd);
    

/*********************************************************************************************************
** Function name:           mpListFlush
** Descriptions:            ������в˵�ҳ
** input parameters:        none
** output parameters:       none
** Returned value:          SYS_OK           �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
extern INT32S miFlush(void);
    
/*********************************************************************************************************
** Function name:           miGetIndex
** Descriptions:            ��ȡָ���˵���������ҳ�е�����
** input parameters:        ptnMenu         �˵����ڵ�
** output parameters:       puiRtn          ��������ָ��
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S miGetIndex(TREE_NODE *ptn, INT32U *puiRtn);

/*********************************************************************************************************
** Function name:           miIsExist
** Descriptions:            ���˵��Ƿ��Ѵ���
** input parameters:        pmiib           �����Ĳ˵���
** output parameters:       none
** Returned value:          TRUE            ����
**                          FALSE           ������
*********************************************************************************************************/
extern BOOLEAN miIsExist(const MENU_ITEM_INFO_BASE *pmiib);


/*********************************************************************************************************
** Function name:           mpHome
** Descriptions:            ��ʾ�˵���ҳ
** input parameters:        none        
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
extern INT32S mpHome(void);

/*********************************************************************************************************
** Function name:           mpOnKey
** Descriptions:            �˵�ҳ������Ӧ����
** input parameters:        pmpiThis        �˵�ҳ��Ϣ      
**                          usLen           ���ݳ���
**                          pvData          ����ָ��
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
extern INT32S  mpOnKey(MENU_ITEM_INFO *pmpiThis, INT16U usLen, void *pvData);
/*********************************************************************************************************
** Function name:           inputFloat
** Descriptions:            ��������ֵ�Ͳ������봦����
** input parameters:        uiKbdCode           ����
**                          pmiiThis            �˵���ָ��
** output parameters:       fpRtn               �����������ֵָ��
** Returned value:          TRUE                ���������
**                          FALSE               δ���������
*********************************************************************************************************/
extern INT8U inputFloat(INT32U uiKbdCode, MENU_ITEM_INFO *pmiiThis, FP32 *pfpRtn);

/*********************************************************************************************************
** Function name:           paraOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :  �ɹ�
**                          ����:    ����,����ֵ�ο�afxMenu.h
** Created by:              
** Created Date:            2014-12-05
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
extern INT32S paraFlotOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, FP32 *pfpRtn);

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
extern INT32S paraIntegerOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT32S *psiRtn);

/*********************************************************************************************************
** Function name:           paraUCharOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :    �ɹ�
**                          ����:       ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S paraUCharOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT8U *pucRtn);

/*********************************************************************************************************
** Function name:           pwdChgOnKey
** Descriptions:            �����޸Ĵ�����
** input parameters:        pmiibThis:  �˵�����Ϣ
**                          pvData:     ����������ָ��
**                          
** output parameters:       pfpRtn:     �������ָ��
** Returned value:          SYS_OK :    �ɹ�
**                          ����:       ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S pwdChgOnKey (MENU_ITEM_INFO *pmiiThis, void *pvData, INT8U *pucRtn);

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
extern INT8U  inputPwd(INT32U uiX, INT32U uiY, INT32U uiKbdCode, INT32U uiMaxLen, INT8U  *pucRtn);

/*********************************************************************************************************
** Function name:           miOnKey
** Descriptions:            �˵������Ӧ����
** input parameters:        pmpiThis        �˵�ҳ��Ϣ      
**                          usLen           ���ݳ���
**                          pvData          ����ָ��
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
extern INT32S  miOnKey(INT32U uiKeyCode);

/*********************************************************************************************************
** Function name:           mpDisplay
** Descriptions:            ��ʾ�˵�ҳ����
** input parameters:        pmpiInfo        �˵�ҳ��Ϣ
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�sys_if.h
*********************************************************************************************************/
extern INT32S mpDisplay(TREE_NODE *ptnParent);

/*********************************************************************************************************
** Function name:           mpDisplayEx
** Descriptions:            �˵�ҳ������ʾ
** input parameters:        pmpiInfo        �˵�ҳ��Ϣ
**                          ucCurIndex      �˵�ҳ��ʼ��ʾ�˵���
** output parameters:       none
** Returned value:          SYS_OK          �ɹ�
**                          ����            ����,����ֵ�ο�afxMenu.h
*********************************************************************************************************/
extern INT32S mpDisplayEx(TREE_NODE *ptnParent, INT8U ucCurIndex);

extern __DUAL_LIST *__GpdlsCurMenuPage;                                 /*  ��ǰ�˵�ҳ�ڵ�ָ��          */



extern INT8U        __GucPara[256];                                     /*  ����������                  */
extern BOOLEAN      __GucEntered;                                       /*  �����޸�״̬��ʶ            */

extern TREE_NODE   *__GptnCurMenu;
extern TREE_NODE   *__GptnRootMenu;
extern const MENU_ITEM_INFO_BASE __GmiibRoot;                           /*  ���˵�����Ϣ                */
#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __AFX_MENU_H                */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
