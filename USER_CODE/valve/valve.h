/****************************************Copyright (c)****************************************************
**                      Beijing Huatai Industrial Equipment Co.,Ltd.
**                                      
**                                 http://www.huatai.com.cn  
**
**--------------File Info---------------------------------------------------------------------------------
**  File name :         valve.h
**  Last modified Date :
**  Last Version :      V1.00
**  Descriptions :      ����ȵ�������������������ͷ�ļ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2014-08-25
** Version:             V1.00
** Descriptions :      
**--------------------------------------------------------------------------------------------------------
** Modified by :        
** Modified date :      
** Version :            
** Descriptions :       
*********************************************************************************************************/
#ifndef __VALVE_H
#define __VALVE_H	

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
    ��������ض���
*********************************************************************************************************/
#define VALVE_MAX                   0x3c                                /*  ���������鳤��              */
#if 1
typedef enum {
            VALVE_INIT,
            LEG_LOW,                                                    /*  ����                        */
            CONV_PULL,                                                  /*  �Ƽ�                        */
            LEG_SET,                                                    /*  ����                        */
            CONV_PUSH,                                                  /*  ����                        */
            BASE_LIFT_SET,                                              /*  ̧��                        */
            STREB_OUT,                                                  /*  ��ƽ��                      */
            STREB_IN,                                                   /*  ��ƽ��                      */
            FLIP_OUT,                                                   /*  ��������                    */
            FLIP_IN,                                                    /*  ��������                    */
            STAB_OUT,                                                   /*  ��һ������                  */
            STAB_IN,                                                    /*  ��һ������                  */
            STAB2_OUT,                                                  /*  ���������                  */
            STAB2_IN,                                                   /*  �ն�������                  */
            SPARY_ON,                                                   /*  ����                        */
            SIDE_IN,                                                    /*  �ղ໤                      */
            SIDE_OUT,                                                   /*  ��໤                      */
            BASE_PUSHER_IN,                                             /*  �յ׵�                      */
            BASE_PUSHER_OUT,                                            /*  ��׵�                      */
            FRT_LEG_LOW,                                                /*  ��ǰ��������              */
            FRT_LEG_SET,                                                /*  ��ǰ��������              */
            REAR_LEG_LOW,                                               /*  �����������ң�              */
            REAR_LEG_SET,                                               /*  �����������ң�              */
            TAIL_GIRDER_OUT,                                            /*  ��β��                      */
            TAIL_GIRDER_IN,                                             /*  ��β��                      */
            FLASHBOARD_OUT,                                             /*  ����                      */
            FLASHBOARD_IN,                                              /*  �ղ��                      */
            REAR_CONV_PUSH,                                             /*  �����                      */
            REAR_CONV_PULL,                                             /*  ������                      */
            FRT_GIRDER_OUT,                                             /*  ��ǰ��                      */
            FRT_GIRDER_IN,                                              /*  ��ǰ��                      */
            FILTRATE_1,                                                 /*  ����ϴ1                     */
            FILTRATE_2,                                                 /*  ����ϴ2                     */
            FLIRT_OUT,                                                  /*  �����                      */
            FLIRT_IN,                                                   /*  �հ���                      */
            STAB3_OUT,                                                  /*  ����������                  */
            STAB3_IN,                                                   /*  ����������                  */
            FILTRATE_3,                                                 /*  ����ϴ3                     */
            FILTRATE_4,                                                 /*  ����ϴ4                     */
            BSPARY_ON,                                                  /*  ��ú����                    */
            ASPARY_ON,                                                  /*  ��������                    */
            ESPARY_ON,                                                  /*  ��������                    */
            TAIL_PILLAR_OUT,                                            /*  ��β��                      */
            TAIL_PILLAR_IN,                                             /*  ��β��                      */
            RSV1,                                                       /*  ����1                       */
            STAB_LINKAGE,                                               /*  �������������              */
            RSV2,                                                       /*  ����2                       */
            RSV3,                                                       /*  ����3                       */
            RSV4,                                                       /*  ����4                       */
            RSV5,                                                       /*  ����5                       */
            RSV6,                                                       /*  ����6                       */
            CEILING_GIRDER_SIDE_OUT,                                    /*  �춥���໤                  */
            CEILING_GIRDER_SIDE_IN,                                     /*  �ն����໤                  */
            COVERING_GIRDER_SIDE_OUT,                                   /*  ���ڻ����໤                */
            COVERING_GIRDER_SIDE_IN,                                    /*  ���ڻ����໤                */
            MID_LEG_LOW,                                                /*  ������                      */
            MID_LEG_SET,                                                /*  ������                      */ 
            HEAD_RIGHT_UP,                                              /*  ��ͷ����                    */
            HEAD_LEFT_UP,                                               /*  ��ͷ����                    */
            HEAD_RIGHT_DOWN,                                            /*  ��ͷ�ҽ�                    */
            HEAD_LEFT_DOWN,                                             /*  ��ͷ��                    */
            TAIL_LEFT_UP,                                               /*  ��β����                    */
            TAIL_RIGHT_UP,                                              /*  ��β����                    */
            TAIL_RIGHT_DOWN,                                            /*  ��β�ҽ�                    */
            LEFT_PUSHER_OUT,                                            /*  ��������                    */
            LEFT_PUSHER_IN,                                             /*  ��������                    */ 
            HEAD_LEFT_MOVE,                                             /*  ͷ����                      */
            HEAD_RIGHT_MOVE,                                            /*  ͷ����                      */
            TAIL_LEFT_MOVE,                                             /*  β����                      */
            TAIL_RIGHT_MOVE,                                            /*  β����                      */
            RIGHT_PUSHER_OUT,                                           /*  ������                      */
            RIGHT_PUSHER_IN,                                            /*  ������                      */            
            TAIL_LEFT_DOWN,                                             /*  β��                      */     
            LEFT_ROLLER_UP,                                             /*  ���й���                    */
            LEFT_ROLLER_DOWN,                                           /*  ���й���                    */
            RIGHT_ROLLER_UP,                                            /*  ���й���                    */
            RIGHT_ROLLER_DOWN,                                          /*  ���й���                    */      
            PUSHER_OUT,                                                 /*  ������                      */
            PUSHER_IN,                                                  /*  ������                      */
            LEFT_FLIP_OUT,                                              /*  ��������                    */
            LEFT_FLIP_IN,                                               /*  ��������                    */
            RIGHT_FLIP_OUT,                                             /*  ��������                    */
            RIGHT_FLIP_IN,                                              /*  ��������                    */
            STRIPE_OUT,                                                 /*  ������                      */
            STRIPE_IN,                                                  /*  ������                      */
            SIDE_1_OUT,                                                 /*  ��һ��                      */
            SIDE_1_IN,                                                  /*  ��һ��                      */
            SIDE_2_OUT,                                                 /*  �����                      */
            SIDE_2_IN,                                                  /*  �����                      */
            SIDE_3_OUT,	                                                /*  ������                      */
            SIDE_3_IN,                                                  /*  ������                      */
            SIDE_4_OUT,	                                                /*  ������                      */
            SIDE_4_IN,                                                  /*  ������                      */
            LIFT_OUT,                                                   /*  ̧����                      */
            LIFT_IN,                                                    /*  ̧����                      */
            BASE_PUSHER_LEFT,                                           /*  �׵���                      */
            BASE_PUSHER_RIGHT,                                          /*  �׵���                      */
            BASE_PUSHER_UP,                                             /*  �׵���                      */
            BASE_PUSHER_DOWN,                                           /*  �׵���                      */
            CEILING_GIRDER_OUT,                                         /*  ������                      */
            CEILING_GIRDER_IN,                                          /*  ������                      */            
            
} VALVE_INDEX; 
#endif

#if 0
typedef enum {                                                          /*  ��ŷ������                */
            VALVE_INIT,                                                 /*  ��ŷ���ʼ��                */
            HEAD_RIGHT_UP,                                              /*  ��ͷ����                    */
            HEAD_LEFT_UP,                                               /*  ��ͷ����                    */
            HEAD_RIGHT_DOWN,                                            /*  ��ͷ�ҽ�                    */
            HEAD_LEFT_DOWN,                                             /*  ��ͷ��                    */
            TAIL_LEFT_UP,                                               /*  ��β����                    */
            TAIL_RIGHT_UP,                                              /*  ��β����                    */
            TAIL_RIGHT_DOWN,                                            /*  ��β�ҽ�                    */
            LEFT_PUSHER_OUT,                                            /*  ��������                    */
            LEFT_PUSHER_IN,                                             /*  ������                      */
            HEAD_LEFT_MOVE,                                             /*  ͷ����                      */
            HEAD_RIGHT_MOVE,                                            /*  ͷ����                      */
            TAIL_LEFT_MOVE,                                             /*  β����                      */
            TAIL_RIGHT_MOVE,                                            /*  β����                      */
            RIGHT_PUSHER_OUT,                                           /*  ������                      */
            RIGHT_PUSHER_IN,                                            /*  ������                      */
            TAIL_LEFT_DOWN,                                             /*  β��                      */
            PUSHER_OUT,                                                 /*  ������                      */
            PUSHER_IN,                                                  /*  ������                      */
            LEFT_FLIP_OUT,                                              /*  ��������                    */
            LEFT_FLIP_IN,                                               /*  ��������                    */
            RIGHT_FLIP_OUT,                                             /*  ��������                    */
            RIGHT_FLIP_IN,                                              /*  ��������                    */
            STRIPE_OUT,                                                 /*  ������                      */
            STRIPE_IN,                                                  /*  ������                      */
            SIDE_1_OUT,                                                 /*  ��һ��                      */
            SIDE_1_IN,                                                  /*  ��һ��                      */
            SIDE_2_OUT,                                                 /*  �����                      */
            SIDE_2_IN,                                                  /*  �����                      */
            SIDE_3_OUT,	                                                /*  ������                      */
            SIDE_3_IN,                                                  /*  ������                      */
            FLIRT_OUT,                                                  /*  �����                      */
            FLIRT_IN,                                                   /*  �հ���                      */
//            STAB3_OUT,                                              /*  ����������                  */
//            STAB3_IN,                                              /*  ����������                  */
            FILTRATE_3,                                                 /*  ����ϴ3                     */
            FILTRATE_4,                                                 /*  ����ϴ4                     */
            BSPARY_ON,                                                  /*  ��ú����                    */
            ASPARY_ON,                                                  /*  ��������                    */
            ESPARY_ON,                                                  /*  ��������                    */
            TAIL_PILLAR_OUT,                                            /*  ��β��                      */
            TAIL_PILLAR_IN,                                             /*  ��β��                      */
            RSV1,                                                       /*  ����1                       */
            STAB_LINKAGE,                                               /*  �������������              */
            RSV2,                                                       /*  ����2                       */
            RSV3,                                                       /*  ����3                       */
            RSV4,                                                       /*  ����4                       */
            RSV5,                                                       /*  ����5                       */
            RSV6,                                                       /*  ����6                       */
            CEILING_GIRDER_SIDE_OUT,                                    /*  �춥���໤                  */
            CEILING_GIRDER_SIDE_IN,                                     /*  �ն����໤                  */
            COVERING_GIRDER_SIDE_OUT,                                   /*  ���ڻ����໤                */
            COVERING_GIRDER_SIDE_IN,                                    /*  ���ڻ����໤                */
            MID_LEG_LOW,                                                /*  ������                      */
            MID_LEG_SET,                                                /*  ������                      */ 
} VALVE_INDEX;
#endif
    /*
     *  ����֧�ܶ�������λ��ͨ��Э��
     */        
#define LEG_SET_PC                  0x00000001                          /*  ����                        */
#define LEG_LOW_PC                  0x00000002                          /*  ����                        */
#define CONV_PUSH_PC                0x00000004                          /*  ����                        */
#define CONV_PULL_PC                0x00000008                          /*  �Ƽ�                        */
#define BASE_LIFT_SET_PC            0x00000010                          /*  ̧��                        */
#define SPARY_ON_PC                 0x00000020                          /*  ����                        */
#define SIDE_OUT_PC                 0x00000040                          /*  ��ǰ�໤��                  */
#define SIDE_IN_PC                  0x00000080                          /*  ��ǰ�໤��                  */
#define STREB_OUT_PC                0x00000100                          /*  ��ƽ��                      */
#define STREB_IN_PC                 0x00000200                          /*  ��ƽ��                      */
#define FLIP_OUT_PC                 0x00000400                          /*  ��������                    */
#define FLIP_IN_PC                  0x00000800                          /*  ��������                    */
#define STAB_OUT_PC                 0x00001000                          /*  ��һ������                  */
#define STAB_IN_PC                  0x00002000                          /*  ��һ������                  */
#define STAB2_OUT_PC                0x00004000                          /*  ���������                  */
#define STAB2_IN_PC                 0x00008000                          /*  �ն�������                  */
#define STAB3_OUT_PC                0x00010000                          /*  ����������                  */
#define STAB3_IN_PC                 0x00020000                          /*  ����������                  */
#define FRT_GIRDER_OUT_PC           0x00040000                          /*  ��ǰ��                      */
#define FRT_GIRDER_IN_PC            0x00080000                          /*  ��ǰ��                      */
#define ACTION_PUSHER_OUTPC         0x00100000                          /*  ��׵�                      */
#define ACTION_PUSHER_INPC          0x00200000                          /*  �յ׵�                      */
#define TAIL_GIRDER_OUT_PC          0x00400000                          /*  ��β��                      */
#define TAIL_GIRDER_IN_PC           0x00800000                          /*  ��β��                      */
#define FLASHBOARD_OUT_PC           0x01000000                          /*  ����                      */
#define FLASHBOARD_IN_PC            0x02000000                          /*  �ղ��                      */
#define BSPARY_ON_PC                0x04000000                          /*  ��ú����                    */
#define ESPARY_ON_PC                0x08000000                          /*  ��������                    */
#define REAR_CONV_PUSH_PC           0x10000000                          /*  �����                      */
#define REAR_CONV_PULL_PC           0x20000000                          /*  ������                      */
#define FRT_LEG_SET_PC              0x40000000                          /*  ��ǰ��������              */
#define REAR_LEG_SET_PC             0x80000000                          /*  �����������ң�              */


#define LEFT_LEG_SET_PC             0x00000001                          /*  ��������                    */
#define RIGHT_LEG_SET_PC            0x00000002                          /*  ��������                    */
#define ASPARY_ON_PC                0x00000004                          /*  ��������                    */

#define TAIL_PILLAR_OUT_PC          0x00000020                          /*  ��β��                      */
#define TAIL_PILLAR_IN_PC           0x00000040                          /*  ��β��                      */
#define FLIRT_OUT_PC                0x00000080                          /*  �����                      */
#define FLIRT_IN_PC                 0x00000100                          /*  �հ���                      */
#define FILTRATE_1_PC               0x00000200                          /*  ����ϴ1                     */
#define FILTRATE_2_PC               0x00000400                          /*  ����ϴ2                     */
#define FILTRATE_3_PC               0x00000800                          /*  ����ϴ3                     */
#define FILTRATE_4_PC               0x00001000                          /*  ����ϴ4                     */
#define FRT_LEG_LOW_PC              0x00002000                          /*  ��ǰ����                    */
#define REAR_LEG_LOW_PC             0x00004000                          /*  ��������                    */

#define LEFT_LEG_LOW_PC             0x00020000                          /*  ��������                    */
#define RIGHT_LEG_LOW_PC            0x00040000                          /*  ��������                    */


extern const INT32U       __SuiValveMiddle[VALVE_MAX];     /*��ŷ�������м䣩���Ժ�ֻ����´˱�*/
extern const INT32U       __SuiValveTransition[VALVE_MAX];     /*��ŷ������(��ͷ)���Ժ�ֻ����´˱�*/
extern const INT32U       __SuiValveEnd[VALVE_MAX];     /*��ŷ������(��ͷ)���Ժ�ֻ����´˱�*/

extern INT32U       GuiValveSnrRelation;		  //��������ز���
extern INT32U       GuiShieldType; 	      //֧�ܹ�������
extern INT32U       GuiPressureSnrNum; 


extern const INT32U *valveTblGet(INT8U ucShieldNum);
extern INT32U       ValveOpposite(INT32U valve_data, const INT32U *puiValveTbl);
extern void         drvPwrDown(void);
extern void         drvPwrUp(void);
extern void         ShieldHandle(INT32U valve_open);

extern const INT32U *GpuiValveTbl;
#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __VALVE_H                   */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

