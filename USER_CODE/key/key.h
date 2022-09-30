/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn  
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               key.h
** Latest modified Date:    2020-02-20
** Latest Version:          1.00
** Descriptions:            ��������
**
**--------------------------------------------------------------------------------------------------------
** Created by:              ����������
** Created date:            2020-02-20
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
#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
    ����������
*********************************************************************************************************/
#define MENU_LIST_MAX               0x13                                /*  �˵�ҳ                      */
#define KEY_ROM_MAX                 0x1E                                /*  �˵����ַ�������            */
#define KEY_ROM_DEFINE              0x09                                /*  ����ȡֵ���Ƴ���            */
//#define KEY_MAX                     0x5a                                /*  ��ֵ���鳤��                */    
    

/********************************************************************************************************* 
    ��ֵ����
*********************************************************************************************************/
#define JP_0                        0x00000001 
#define JP_1                        0x00000002 
#define JP_2                        0x00000004 
#define JP_3                        0x00000008
#define JP_4                        0x00000010
#define JP_5                        0x00000020 
#define JP_6                        0x00000040 
#define JP_7                        0x00000080 
#define JP_8                        0x00000100
#define JP_9                        0x00000200
#define JP_L                        0x00000400 
#define JP_R                        0x00000800 
#define JP_E                        0x00001000 
#define JP_B                        0x00002000 
#define JP_P                        0x00004000
#define JP_N                        0x00008000
#define JP_U                        0x00010000 
#define JP_D                        0x00020000
#define JP_K                        0x00040000
#define JP_M                        0x00080000
#define JP_A                        0x00100000

#define JP_LOCK                     0x00200000
#define JP_STOP                     0x00400000
#define JP_NOP                      0x00000000



/********************************************************************************************************* 
    ����led����
*********************************************************************************************************/
#define NAVI_M              ~0x00000001
#define NAVI_D              ~0x00000002	
#define NAVI_B              ~0x00000004	
#define NAVI_E              ~0x00000008	
#define NAVI_L              ~0x00000010	
#define NAVI_R      	    ~0x00000020	
#define NAVI_RX      	    ~0x00000040	
#define NAVI_TX             ~0x00000080	
#define NAVI_N              ~0x00000100	
#define NAVI_9              ~0x00000200	
#define NAVI_0              ~0x00000400	
#define NAVI_S              ~0x00000800	
#define NAVI_T              ~0x00001000	
#define NAVI_U              ~0x00002000	
#define NAVI_K              ~0x00004000	
#define NAVI_Q              ~0x00008000	
#define NAVI_4              ~0x00010000	
#define NAVI_I              ~0x00020000	
#define NAVI_J              ~0x00040000	
#define NAVI_5              ~0x00080000	
#define NAVI_6              ~0x00100000	
#define NAVI_7              ~0x00200000	
#define NAVI_8              ~0x00400000	
#define NAVI_P              ~0x00800000	
#define NAVI_A              ~0x01000000
#define NAVI_C              ~0x02000000	
#define NAVI_F              ~0x04000000	
#define NAVI_G              ~0x08000000	
#define NAVI_H              ~0x10000000
#define NAVI_1              ~0x20000000
#define NAVI_2              ~0x40000000	
#define NAVI_3              ~0x80000000

typedef enum {
        KEY_LEG_LOW,                                                    /*  ����                        */
        KEY_CONV_PULL,                                                  /*  �Ƽ�                        */
        KEY_LEG_SET,                                                    /*  ����                        */
        KEY_CONV_PUSH,                                                  /*  ����                        */
        KEY_BASE_LIFT_SET,                                              /*  ̧��                        */
        KEY_STREB_OUT,                                                  /*  ��ƽ��                      */
        KEY_STREB_IN,                                                   /*  ��ƽ��                      */
        KEY_FLIP_OUT,                                                   /*  ��������                    */
        KEY_FLIP_IN,                                                    /*  ��������                    */
        KEY_STAB_OUT,                                                   /*  ��һ������                  */
        KEY_STAB_IN,                                                    /*  ��һ������                  */
        KEY_STAB2_OUT,                                                  /*  ���������                  */
        KEY_STAB2_IN,                                                   /*  �ն�������                  */
        KEY_STAB3_OUT,                                                  /*  ����������                  */
        KEY_STAB3_IN,                                                   /*  ����������                  */        
        KEY_SPARY_ON,                                                   /*  ����                        */
        KEY_REMOTE,                                                     /*  Զ��                        */
        KEY_LEFT,                                                       /*  ���ڼ�                      */
        KEY_RIGHT,                                                      /*  ���ڼ�                      */
        KEY_START,                                                      /*  ����                        */
        KEY_ABORT,                                                      /*  ֹͣ                        */
        KEY_LEFT_BATCH,                                                 /*  �����                      */
        KEY_RIGHT_BATCH,                                                /*  �ҳ���                      */        
        KEY_SIDE_IN,                                                    /*  �ղ໤                      */
        KEY_SIDE_OUT,                                                   /*  ��໤                      */
        KEY_BASE_PUSHER_IN,                                             /*  �յ׵�                      */
        KEY_MENU_LEFT,                                                  /*  ��ҳ                      */
        KEY_BASE_PUSHER_OUT,                                            /*  ��׵�                      */
        KEY_MENU_RIGHT,                                                 /*  �ҷ�ҳ                      */
        KEY_MENU_UP,                                                    /*  �Ϸ��˵�                    */
        KEY_MENU_DOWN,                                                  /*  �·��˵�                    */
        KEY_INC,                                                        /*  ��1����                     */
        KEY_DEC,                                                        /*  ��1����                     */
        KEY_ENTER,                                                      /*  ȷ��                        */
        KEY_AUX_LEFT,                                                   /*  ����                      */
        KEY_AUX_RIGHT,                                                  /*  �Ҹ���                      */
        KEY_FRT_LEG_LOW,                                                /*  ��ǰ��������              */
        KEY_FRT_LEG_SET,                                                /*  ��ǰ��������              */
        KEY_MID_LEG_LOW,                                                /*  ��������                    */
        KEY_MID_LEG_SET,                                                /*  ��������                    */        
        KEY_REAR_LEG_LOW,                                               /*  �����������ң�              */
        KEY_REAR_LEG_SET,                                               /*  �����������ң�              */
        KEY_TAIL_GIRDER_OUT,                                            /*  ��β��                      */
        KEY_TAIL_GIRDER_IN,                                             /*  ��β��                      */
        KEY_FLASHBOARD_OUT,                                             /*  ����                      */
        KEY_FLASHBOARD_IN,                                              /*  �ղ��                      */
        KEY_REAR_CONV_PUSH,                                             /*  �����                      */
        KEY_REAR_CONV_PULL,                                             /*  ������                      */
        KEY_FRT_GIRDER_OUT,                                             /*  ��ǰ��                      */
        KEY_FRT_GIRDER_IN,                                              /*  ��ǰ��                      */
        KEY_FILTRATE_1,                                                 /*  ����ϴ1                     */
        KEY_FILTRATE_2,                                                 /*  ����ϴ2                     */        
        KEY_FLIRT_OUT,                                                  /*  �����                      */
        KEY_FLIRT_IN,                                                   /*  �հ���                      */
        KEY_CONV_BATCH_PUSH,                                            /*  ��������                    */
        KEY_CONV_BATCH_PULL,                                            /*  ��������                    */
        KEY_STAB1_BATCH_OUT,                                            /*  ������һ�������            */
        KEY_STAB1_BATCH_IN,                                             /*  ������һ�������            */
        KEY_STAB2_BATCH_OUT,                                            /*  ��������������            */
        KEY_STAB2_BATCH_IN,                                             /*  �����ն��������            */
        KEY_FRT_GIRDER_BATCH_OUT,                                       /*  ������ǰ��                  */
        KEY_FRT_GIRDER_BATCH_IN,                                        /*  ������ǰ��                  */
        KEY_REAR_CONV_BATCH_PULL,                                       /*  ����������                  */
        KEY_FLIP_BATCH_OUT,                                             /*  ������������                */
        KEY_FLIP_BATCH_IN,                                              /*  ������������                */
        KEY_STAB3_BATCH_OUT,                                            /*  ����������                  */
        KEY_STAB3_BATCH_IN,                                             /*  ����������                  */        
        KEY_REAR_CONV_SELF_PULL,                                        /*  ����������                  */
        KEY_CONV_SELF_PUSH,                                             /*  ��������                    */        
        KEY_SIDE_SELF_OUT,                                              /*  ������໤                  */
        KEY_BSPRAY_ON,                                                  /*  ��ú����                    */
        KEY_ASPRAY_ON,                                                  /*  ��������                    */
        KEY_ESPRAY_ON,                                                  /*  ��������                    */       
        KEY_FILTRATE_3,                                                 /*  ����ϴ3                     */
        KEY_FILTRATE_4,                                                 /*  ����ϴ4                     */  
        KEY_TAIL_PILLAR_OUT,                                            /*  ��β��                      */
        KEY_TAIL_PILLAR_IN,                                             /*  ��β��                      */
        KEY_BSPRAY_BATCH,                                               /*  �����ú����                */
        KEY_ASPRAY_BATCH,                                               /*  ���鶥������                */
        KEY_ESPRAY_BATCH,                                               /*  �����������                */
        KEY_SPRAY_BATCH,                                                /*  ��������                    */
        KEY_WORK_STAT,                                                  /*  ����                        */
        KEY_STAB_LINKAGE,                                               /*  �������������              */
        KEY_FILTRATE_BATCH,                                             /*  ���鷴��ϴ����              */
        KEY_RTC,                                                        /*  ʱ����ʾ��ݰ���            */
        KEY_PSA_PARA,                                                   /*  ������ѹ������ݼ�����������*/
        KEY_PSA,                                                        /*  ������ѹ���ܿ�ݼ�          */
        KEY_PSA_2,                                                      /*  ������ѹ���ܿ�ݼ�-��ϼ�2  */
        KEY_SELF,                                                       /*  �����Կ�                    */
        KEY_HEAD_RIGHT_UP,                                              /*  ͷ����                      */
        KEY_HEAD_LEFT_UP,                                               /*  ͷ����                      */
        KEY_HEAD_RIGHT_DOWN,                                            /*  ͷ�ҽ�                      */
        KEY_HEAD_LEFT_DOWN,                                             /*  ͷ��                      */
        KEY_TAIL_LEFT_UP,                                               /*  β����                      */
        KEY_TAIL_RIGHT_UP,                                              /*  β����                      */
        KEY_TAIL_RIGHT_DOWN,                                            /*  β�ҽ�                      */
        KEY_LEFT_PUSHER_OUT,                                            /*  ������                      */
        KEY_LEFT_PUSHER_IN,                                             /*  ������                      */
        KEY_HEAD_LEFT_MOVE,                                             /*  ͷ����                      */
        KEY_HEAD_RIGHT_MOVE,                                            /*  ͷ����                      */
        KEY_TAIL_LEFT_MOVE,                                             /*  β����                      */
        KEY_TAIL_RIGHT_MOVE,                                            /*  β����                      */
        KEY_RIGHT_PUSHER_OUT,                                           /*  ������                      */
        KEY_RIGHT_PUSHER_IN,                                            /*  ������                      */
        KEY_TAIL_LEFT_DOWN,                                             /*  β��                      */
        KEY_PUSHER_OUT,                                                 /*  ������                      */
        KEY_PUSHER_IN,                                                  /*  ������                      */
        KEY_LEFT_FLIP_OUT,                                              /*  ��������                    */
        KEY_LEFT_FLIP_IN,                                               /*  ��������                    */
        KEY_RIGHT_FLIP_OUT,                                             /*  ��������                    */
        KEY_RIGHT_FLIP_IN,                                              /*  ��������                    */
        KEY_STRIPE_OUT,                                                 /*  ������                      */
        KEY_STRIPE_IN,                                                  /*  ������                      */
        KEY_SIDE_1_OUT,                                                 /*  ��һ��                      */
        KEY_SIDE_1_IN,                                                  /*  ��һ��                      */
        KEY_SIDE_2_OUT,                                                 /*  �����                      */
        KEY_SIDE_2_IN,                                                  /*  �����                      */
        KEY_SIDE_3_OUT,	                                                /*  ������                      */
        KEY_SIDE_3_IN,                                                  /*  ������                      */
        KEY_SIDE_4_OUT,	                                                /*  ������                      */
        KEY_SIDE_4_IN,                                                  /*  ������                      */
        KEY_LIFT_OUT,                                                   /*  ̧����                      */
        KEY_LIFT_IN,                                                    /*  ̧����                      */
        KEY_BASE_PUSHER_LEFT,                                           /*  �׵���                      */
        KEY_BASE_PUSHER_RIGHT,                                          /*  �׵���                      */
        KEY_BASE_PUSHER_UP,                                             /*  �׵���                      */
        KEY_BASE_PUSHER_DOWN,                                           /*  �׵���                      */
        KEY_CEILING_GIRDER_OUT,                                         /*  ������                      */
        KEY_CEILING_GIRDER_IN,                                          /*  ������                      */   
} KEY_INDEX; 



extern const INT32U GuiUnlockPwd[3];
extern const INT32U *GpuiKeyTbl;

/*********************************************************************************************************
** Function name:       keyTblGet
** Descriptions:        �����ϰ���������ʼ��
** input parameters:    ucNo                    �ܺ�
** output parameters:   None
** Returned value:      None
*********************************************************************************************************/
extern const INT32U *keyTblGet(INT8U ucNo);

/*********************************************************************************************************
** Function name:       keyToAction
** Descriptions:        ������ת������Ӧ��ŷ�������
** input parameters:    uiKeyValue              ���µļ�ֵ
**                      puiKeyTbl               ����������
**                      puiValveTbl             ��ŷ��ڶ�����
**                      
** output parameters:   None
** Returned value:      ��������ʶ
*********************************************************************************************************/
extern INT32U keyToAction(INT32U uiKeyValue, const INT32U *puiKeyTbl, const INT32U *puiValveTbl);

/*********************************************************************************************************
** Function name:       keyAuxToValve
** Descriptions:        �����������˵��Ķ�Ӧ����ת���ɵ�ŷ���
** input parameters:    ucRow:          �����˵�����һ����
**                      ucRowFocus��    ���Ե��ǵ�һ�л��ǵڶ���
**                      ucIsAuxRight:   0/1 ����/�Ҹ���
** output parameters:   None
** Returned value:      ��ŷ���
*********************************************************************************************************/
extern INT32U keyAuxToValve(INT8U ucRow, const INT32U *puiValveTbl, INT8U ucIsAuxRight);


/*********************************************************************************************************
** Function name:       keyToNum
** Descriptions:        ����ת����
** input parameters:    uiKeyCode               ��ֵ
** output parameters:   None  
** Returned value:      ���� ����Ч�򷵻�0x0f,��1������0x0a����1������0x0b
*********************************************************************************************************/
extern INT8U keyToNum(INT32U uiKeyCode);

/*********************************************************************************************************
** Function name:       keyNum
** Descriptions:        ���¼������ж�
** input parameters:    uiKeyCode               ��ֵ
** output parameters:   None  
** Returned value:      ��������
*********************************************************************************************************/
extern INT8U keyNum(INT32U uiKeyCode);

/*********************************************************************************************************
** Function name:       keyShow
** Descriptions:        ���̱���ʱ�ļ�ֵ��ʾ
** input parameters:    uiKeyCode               ����ֵ
** output parameters:   None
** Returned value:      None
*********************************************************************************************************/
extern void keyShow(INT32U uiKeyCode);

/*********************************************************************************************************
** Function name:       ledNavi
** Descriptions:        ��������
** input parameters:    uiLedNavi               ����ָʾ�Ƶ�λ����ȡ��
** Returned value:      void
*********************************************************************************************************/
extern void ledNavi(INT32U uiLedNavi);

/*********************************************************************************************************
** Function name:       ledComm
** Descriptions:        ͨ�ŵ�������˸
** input parameters:    ucLedNo                 ָʾ�Ʊ��
** Returned value:      void
*********************************************************************************************************/
extern void ledComm(INT8U ucLedNo);		


#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __KEY_H                     */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/


