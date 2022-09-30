/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.h
** Latest modified Date:    2017-05-30
** Latest Version:          1.0
** Descriptions:            �û�����������ͷ�ļ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2017-05-30
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/
#ifndef __MAIN_H 
#define __MAIN_H

/*********************************************************************************************************
**  ��һ������Ķ�
*********************************************************************************************************/
#include     ".\cfg_file\config.h"
#include     ".\cfg_file\PinCfg\LPC2200PinCfg.h"

/*********************************************************************************************************
    Э��֡��Ϣ�ṹ�嶨��
*********************************************************************************************************/
struct __can_frame                                                      
{
    BOOLEAN ucIsRemote;                                                 /*  �Ƿ�Զ��֡��־              */
    BOOLEAN ucIsExtend;                                                 /*  �Ƿ���չ֡��־              */
    INT8U   ucDataLen;                                                  /*  ���ݳ���                    */
    union {
        unsigned long   ulDWord;
        struct {                    
            unsigned int ulSrc      :8;                                 /*  Դ��ַλ��                  */
            unsigned int ulDst      :8;                                 /*  Ŀ�ĵ�ַλ��                */
            unsigned int ulRsv      :2;                                 /*  ����λ��                    */
            unsigned int ulDir      :2;                                 /*  ������λ��                  */
            unsigned int ulAck      :2;                                 /*  ��Ӧ��λ��                  */
            unsigned int ulCmd      :4;                                 /*  ������λ��                  */
            unsigned int ulPri      :3;                                 /*  ���ȼ�λ��                  */
        }ulBits;
    }ulId;                                                              /*  ֡ID                        */
    INT8U   ucBuf[8];                                                   /*  ֡����                      */
};
typedef struct __can_frame __CANFRAME;


/*********************************************************************************************************
    CAN����Э��֡��Ϣ�ṹ�嶨��
*********************************************************************************************************/
struct __can_msg 
{
  __CANFRAME    cf;
    INT8U       ucFromTo;
}; 
typedef struct __can_msg __CAN_MSG;

extern void can2ReviceHook (void *pRsv,CANFRAME ucfRbr);
extern void can4ReviceHook (void *pRsv,CANFRAME ucfRbr);
extern void CanInit(void);
extern uint8 CanMsgSend(__CAN_MSG *pcm); 

/*********************************************************************************************************
  Ӧ�ó������� ������Ҫ�Ķ� 
*********************************************************************************************************/ 
#include  ".\eeprom\eeprom.h" 

#include  ".\flash\FlashOS.h"
#include  ".\tmUart2Can\tmUart2Can.h"
#include  ".\key\key.h"
#include  ".\valve\valve.h"

/*����can�˿�*/
#define     COM_PORT_SELF              0x00                                     //�˻�����ͨѶ�߼��˿�ID
#define     COM_PORT_LEFT              0x01                                     //���ڼ�ͨѶ�߼��˿�ID
#define     COM_PORT_RIGHT             0x02                                     //���ڼ�ͨѶ�߼��˿�ID
#define     COM_PORT_BUS               0x03                                     //����ͨѶ�߼��˿�ID

#define     CAN_PORT_LEFT              CAN4                                     //���ڼ�ͨѶ���������ַID
#define     CAN_PORT_RIGHT             CAN2                                     //���ڼ�ͨѶ���������ַID
#define     CAN_PORT_BUS               0x00                                     //����ͨѶ���������ַID 
#define     CAN_PORT_SELF              0x05

#define     OPERATOR_NUMBER 251
#define     COMPUTER_NUMBER 253    //(������ʵ252 û��������ʵ253)
#define     NET_NUMBER 254              //254


typedef struct __dev_para {
    INT8U               usGblFaceMin;                                   /*  ��С�ܺ�                    */
    INT8U               ucGblFaceMinRsv;
    INT8U               usGblFaceMax;                                   /*  ���ܺ�                    */
    INT8U               ucGblFaceMaxRsv;
    INT16U              usMasterTime;                                   /*  ����ʱ��                    */
    INT16U              usPsaP0;                                        /*  ��ѹ����                    */
    INT16U              usPsaP1;                                        /*  ��ѹ����                    */
    INT16U              usPsaP2;                                        /*  ������                      */
    INT8U               ucPsaT0;                                        /*  */
    INT16U              usPsaT1;                                        /*  ��ѹ���                    */
    INT8U               ucAutoInitPara;                                 /*  ������ʼ������              */
    INT8U               ucObliCaliEn;                                   /*  ���У�� bit0:0/1 ��/��     */
    INT8U               ucPsaTimes;                                     /*  ��ѹ����                    */
    INT16U              usStopRange;                                    /*  ֹͣ��Χ                    */
    union  {                                                             /*  ���鶯��ʹ�ܿ���            */
        INT16U          usWord;
        struct {
            INT16U      usRsv0      :1;
            INT16U      usReturnPerch           :1;                     /*  �ظ�λ                      */
            INT16U      usLiftBase              :1;
            INT16U      usRsv3 :1;

            INT16U      usRsv4  :1;
            INT16U      usRsv5  :1;
            INT16U      usSpray                 :1;                     /*  ��������                    */
            INT16U      usRsv7          :1;

            
            INT16U      usNbrPush               :1;                     /*  �ڼ�����                    */
            INT16U      usRsv9  :1;
            INT16U      usRsv10 :1;
            INT16U      usRsv11 :1;

            INT16U      usLinkageFirstEn        :1;                     /*  ��������                    */
            INT16U      usBatchStab             :1;                     /*  ���黤���                  */
            INT16U      usBatchPushConvyerEn    :1;                     /*  ��������                    */
            INT16U      usSelfAsq               :1;                     /*  �����Զ��Ƽ�                */

        }__attribute__((packed)) Bits;
        
    } __attribute__((packed)) usBatchEn;
    //BATCH_EN    usBatchEn;                                                        
    INT8U               ucPullOffset;
    INT8U               ucPushOffset;
    INT8U               ucDir;
    INT16U              usShieldNo;
    INT8U               ucPwrGrpNo;

    /*
     *  ����������
     */

    INT16U              usPsaP3;                                        /*  ������ѹĿ��ѹ��            */
    INT8U               ucAutoStatus;                                   /*  ��������
                                                                         *  0����
                                                                         *  1�쳣
                                                                         *  2�˹�ֹͣ
                                                                         *  3����
                                                                         */
    INT16U              usAutoFirst;                                    /*  �����׼ܱ��                */
    INT16U              usAutoLast;                                     /*  ����ĩ�ܱ��                */
    union {                                                             /*  ��������                    */
        INT8U          ucWord;
        struct {
            INT8U       ucUpPush                :1;                     /*  ���и�������                */
            INT8U       ucDownPush              :1;                     /*  ���и�������                */
            INT8U       ucUpFlipIn              :1;                     /*  ������������                */
            INT8U       ucDownFlipOut           :1;                     /*  ������������                */
            INT8U       ucRsv4                  :1;
            INT8U       ucSpray                 :1;                     /*  ��������                    */
            INT8U       ucRsv6                  :1;
            INT8U       ucRsv7                  :1;
        } __attribute__((packed)) Bits;        
    } __attribute__((packed)) ucAutoEn;                                       



    INT8U               ucAsqDis;                                       /*  [36]�Ƽܾ���                */
    INT8U               ucBpDis;                                        /*  [37]�������                */
    INT8U               ucFlipInDis;                                    /*  [38]������������            */
    INT8U               ucFlipOutDis;                                   /*  [39]������������            */
    INT8U               ucHGSsprayDis;                                  /*  [40]�����������            */
    INT8U               ucHGSsprayRange;                                /*  [41]��������Χ            */
    INT8U               ucUpSnakeMax;                                   /*  [42]�������δ��            */
    INT8U               ucUpSnakeMin;                                   /*  [43]��������С��            */
    INT8U               ucUpCleanMax;                                   /*  [44]�����帡ú���          */
    INT8U               ucUpCleanMin;                                   /*  [45]�����帡úС��          */
    INT8U               ucUpAsqBpTrigger;                               /*  [46]���в��������Ƽܴ�����  */
    INT8U               ucDownSnakeMax;                                 /*  [47]�������δ��            */
    INT8U               ucShearerHopLimit;                              /*  [48]ú������                */
    INT8U               ucDownSnakeMin;                                 /*  [49]��������С��            */
    INT8U               ucDownCleanMax;                                 /*  [50]�����帡ú���          */
    INT8U               ucDownCleanMin;                                 /*  [51]�����帡úС��          */
    INT8U               ucDownAsqBpTrigger;                             /*  [52]���жβ��������Ƽܴ�����*/
    INT8U               ucAutoRunDir;                                   /*  [53]��������1/2-����/����   */
    INT8U               ucAutoPhase;                                    /*  [54]�Զ������׶����ò���    */
    INT8U               ucAutoAsqMax;                                   /*  [55]����2��β˳���Ƽܵ�     */
    INT8U               ucAutoAsqMaxTrigger;                            /*  [56]����3��β˳���Ƽܴ����� */
    INT8U               ucAutoAsqMin;                                   /*  [57]����4��ͷ˳���Ƽܵ�     */
    INT8U               ucAutoAsqMinTrigger;                            /*  [58]����5��ͷ˳���Ƽܴ����� */
    INT8U               ucShearerLength;                                /*  [59]ú����                */

    /*
     *  �����Ƽܲ�����
     */
    INT16U              usAsqStrebSS;//ASQ_STREB_SS           (PARA_LIST[60] | (PARA_LIST[61] << 8))   /*  [60,61]�����Ƽܲ���         */

    INT8U               ucAsqRange;                                     /*  [62]�����Ƽܷ�Χ            */
    INT8U               ucAsqCollection; //ASQ_COLLECTION          PARA_LIST[63]                           /*  [63]�����Ƽܿ��Ʋ���        */
    INT16U              usAsqWarnTime;// ASQ_WARN_T             (PARA_LIST[64] | (PARA_LIST[65] << 8))   /*  [64,65]����Ԥ��ʱ��         */

    INT16U              usAsqP0;//ASQ_P0                 (PARA_LIST[66] | (PARA_LIST[67] << 8))   /*  [66,67]�Ƽ�ѹ��             */

    INT16U              usAsqP1;// ASQ_P1                 (PARA_LIST[68] | (PARA_LIST[69] << 8))   /*  [68,69]�Ƽ�ѹ��             */

    INT16U              usAsqP2;// ASQ_P2                 (PARA_LIST[70] | (PARA_LIST[71] << 8))   /*  [70,71]�Ƽ�ѹ��             */

    INT16U              usAsqP3;// ASQ_P3                 (PARA_LIST[72] | (PARA_LIST[73] << 8))   /*  [72,73]�Ƽ�ѹ��             */
    INT16U              usAsqNbrWaitTime;// ASQ_NB_T               (PARA_LIST[74] | (PARA_LIST[75] << 8))   /*  [74,75]�Ƽܵȴ�ʱ��         */

    INT16U              usAsqEndStrk;// ASQ_END_STRK           (PARA_LIST[76] | (PARA_LIST[77] << 8))   /*  [76,77]Ŀ���г�             */

    INT8U               ucRearBpRange;// REAR_CONV_BATCH_PUSH_SCOPE    PARA_LIST[78]                           /*  [78]�����ƺ��ﶯ����Χ      */
    INT8U               ucRearBpGrp;// REAR_CONV_BATCH_PUSH_GROUP    PARA_LIST[79]                           /*  [79]�����ƺ��ﶯ����        */
    INT8U               ucRearBpTime; //REAR_CONV_BATCH_PUSH_T        PARA_LIST[80]                           /*  [80]�����ƺ��ﶯ��ʱ��      */
    INT8U               ucRearBpInterval;// REAR_CONV_BATCH_PUSH_OFFSET   PARA_LIST[81]                           /*  [81]�����ƺ����������      */
    INT8U               ucAsqPreLowTime; //ASQ_PRELOW_T            PARA_LIST[82]                           /*  [82]Ԥ����ʱ��              */
    INT8U               ucAsqP0LowTime;// ASQ_P0_LOWER_T          PARA_LIST[83]                           /*  [83]������ASQ_P0ʱ��        */
    INT8U               ucAsqLow2Time;// ASQ_LOW2_T              PARA_LIST[84]                           /*  [84]�ٴν���ʱ��            */
    INT8U               ucAsqBaseLiftStartTime;// ASQ_BASE_LIFT_START_T   PARA_LIST[85]                           /*  [85]̧�׿�ʼʱ��            */
    INT8U               ucAsqBaseLiftTime;// ASQ_BASE_LIFT_T         PARA_LIST[86]                           /*  [86]̧��ʱ��                */
    INT16U              usAsqAdvTime;// ASQ_ADV_T              (PARA_LIST[87] | (PARA_LIST[88] << 8))   /*  [87,88]�Ƽ�ʱ��             */

    INT8U               ucAsqRelowTime;// ASQ_RELOW_T             PARA_LIST[89]                           /*  [89]�ٽ���ʱ��              */
    INT8U               ucReadvTime;// ASQ_READV_T             PARA_LIST[90]                           /*  [90]���Ƽ�ʱ��              */
    INT8U               ucAsqRelowTimes;// ASQ_RELOW_C             PARA_LIST[91]                           /*  [91]�ٽ�������              */
    INT8U               ucAsqSetP1Time;// ASQ_SET_P1_T            PARA_LIST[92]                           /*  [92]������P1ʱ��            */
    INT8U               ucAsqSetP2Time;// ASQ_SET_P2_T            PARA_LIST[93]                           /*  [93]������P2ʱ��            */
                                                                        //94
    INT8U               ucAsqInterval;// ASQ_OFFSET              PARA_LIST[95]                           /*  [95]�������                */
    INT16U              ucAsqNbrPushStrk;// ASQ_NB_PUSH_STRK       (PARA_LIST[96] | (PARA_LIST[97] << 8))   /*  [96,97]�ڼ������г�         */

    /*
     *  �������������
     */
    INT8U               ucBpRange;// CONV_BATCH_PUSH_SCOPE   PARA_LIST[98]                           /*  [98]�������ﶯ����Χ        */
    INT8U               ucBpGrp;// CONV_BATCH_PUSH_GROUP   PARA_LIST[99]                           /*  [99]�����������            */
    INT16U              usAsqRearLegP0;// ASQ_REAR_LEG_P0        (PARA_LIST[100]|PARA_LIST[101] << 8)   /*  [100,101]�Ƽ�ѹ����������   */  
    INT16U              usBpTime;// CONV_BATCH_PUSH_T      (PARA_LIST[102]|PARA_LIST[103] << 8)   /*  [102,103]��������ʱ��       */

    INT16U              usBpDelay;// CONV_BATCH_PUSH_DELAY  (PARA_LIST[104]|PARA_LIST[105] << 8)   /*  [104,105]����������ʱ       */
//INT8U      *BP_DELAYH;
//INT8U      *BP_DELAYL;
    INT8U               ucBpInterval;// CONV_BATCH_PUSH_OFFSET PARA_LIST[106]                           /*  [106]���������������       */
                                                                        //107��108
    INT8U               ucBpPresetTime;// CONV_BATCH_PUSH_PRESET_T PARA_LIST[109]                           //109Ԥ��������ʱ��
                                                                        //110
//INT8U      *BP_EXTH;
//INT8U      *BP_EXTL;
    INT16U              usBpEndStrk; //CONV_BATCH_PUSH_END_STRK (PARA_LIST[111]|PARA_LIST[112] << 8)   //111��112
//INT8U      *BP_END_STRKH;
//INT8U      *BP_END_STRKL;
    INT16U              usBpLTime;// BP_L_PUSH_T            (PARA_LIST[113]|PARA_LIST[114] << 8)   //113��114
//INT8U      *BP_L_PUSH_TH;
//INT8U      *BP_L_PUSH_TL;
    INT16U              usBpProtect;// BP_PROTECT             (PARA_LIST[115]|PARA_LIST[116] << 8)   //115��116
//INT8U      *BP_PROTECTH;
//INT8U      *BP_PROTECTL;
    INT8U               ucBpSetAllow;// BP_SET_ALLOW            PARA_LIST[117]                          //[117]��������
    INT16U              usBpPress;// BP_PRESS               (PARA_LIST[118]|PARA_LIST[119] << 8)   //[118��119]����ѹ��
//INT8U      *BP_PRESSH;
//INT8U      *BP_PRESSL;

    /*
     *  ����������������
     */
    INT8U               ucRearConvBatchPullRange;// REAR_CONV_BATCH_PULL_SCOPE PARA_LIST[120]                       /*  [120]���������ﶯ����Χ     */
    INT8U               ucReadConvBatchPullGrp;// REAR_CONV_BATCH_PULL_GROUP PARA_LIST[121]                       /*  [121]���������ﶯ����       */
    INT16U              usRearConvBatchPullTime;// REAR_CONV_BATCH_PULL_T    (PARA_LIST[122] | PARA_LIST[123] << 8)/*  [122,123]����������ʱ��     */
//INT8U      *PULL_BEHIND_TH;
//INT8U      *PULL_BEHIND_TL;
    INT8U               ucReadConvBatchPullDelay;// REAR_CONV_BATCH_PULL_DELAY  PARA_LIST[124]                      /*  [124]��������������ӳ�     */
    INT8U               ucReadConvBatchPullInterval;// REAR_CONV_BATCH_PULL_OFFSET PARA_LIST[125]                      /*  [125]�����������������     */
    INT16U              ucReadConvPullTime;// REAR_CONV_PULL_T           (PARA_LIST[126] | PARA_LIST[127] << 8)/*  [126,127]����������ʱ��     */
//INT8U      *PULL_BEHIND_TSH;
//INT8U      *PULL_BEHIND_TSL;  
    INT8U               ucStabBatchRange;// STAB_BATCH_SCOPE            PARA_LIST[128]                      /*  [128]���黤�ﶯ����Χ       */
    INT8U               ucStabBatchDelay;// STAB_BATCH_DELAY            PARA_LIST[129]                      /*  [129]���黤��ܼ��ӳ�       */
    INT8U               ucFlipBatchInTime;// FLIP_BATCH_IN_T             PARA_LIST[130]                      /*  [130]����������������ʱ��   */
    INT8U               ucFlipBatchOutTime;// FLIP_BATCH_OUT_T            PARA_LIST[131]                      /*  [131]����������������ʱ��   */
    INT8U               ucStabBatchOutTime;// STAB_BATCH_OUT_T            PARA_LIST[132]                      /*  [132]�����커��嶯��ʱ��   */
    INT8U               ucStabBatchInTime;//     STAB_BATCH_IN_T             PARA_LIST[133]                      /*  [133]�����ջ���嶯��ʱ��   */
    INT8U               ucStabInStartTime;// STAB_IN_START_T             PARA_LIST[134]                      /*  [134]�������Զ��Ƽ�һ�������տ�ʼ����ʱ��*/
    INT8U               ucStabInActTime;// STAB_IN_ACT_T               PARA_LIST[135]                      /*  [135]�������Զ��Ƽ�һ�������ն���ʱ��*/
    INT8U               ucFlipInStartTime;// FLIP_IN_START_T             PARA_LIST[136]                      /*  [136]�������Զ��Ƽ��������տ�ʼ����ʱ��*/
    INT8U               ucFlipInActTime;// FLIP_IN_ACT_T               PARA_LIST[137]                      /*  [137]�������Զ��Ƽ��������ն���ʱ��*/
    INT8U               ucStabOutStartTime;// STAB_OUT_START_T            PARA_LIST[138]                      /*  [138]�������Զ��Ƽ�һ�������쿪ʼ����ʱ��*/
    INT8U               ucStabOutActTime;// STAB_OUT_ACT_T              PARA_LIST[139]                      /*  [139]�������Զ��Ƽ�һ�������춯��ʱ��*/
    INT8U               ucFlipOutStartTime;// FLIP_OUT_START_T            PARA_LIST[140]                      /*  [140]�������Զ��Ƽ��������쿪ʼ����ʱ��*/
    INT8U               ucFlipOutActTime;// FLIP_OUT_ACT_T              PARA_LIST[141]                      /*  [141]�������Զ��Ƽ��������춯��ʱ��*/
    INT8U               ucFlipBatchInLowTime;// FLIP_BATCH_LOW_T            PARA_LIST[142]                      /*  [142]����������������ʱ��   */
    INT8U               ucStabBatchInterval;// STAB_BATCH_OFFSET           PARA_LIST[143]                      /*  [143]���黤��������     */

    /*
     *  �������������
     */
    INT8U               ucConvBatchPullRange;// CONV_BATCH_PULL_SCOPE       PARA_LIST[144]                      /*  [144]�������ﷶΧ           */
    INT8U               ucConvBatchPullGrp;// CONV_BATCH_PULL_GROUP       PARA_LIST[145]                      /*  [145]�������ﶯ����         */
    INT16U              usConvBatchPullTime;// CONV_BATCH_PULL_T          (PARA_LIST[146]|PARA_LIST[147] << 8) /*  [146,147]�������ﶯ��ʱ��   */
//INT8U      *CP_IN_TH;
//INT8U      *CP_IN_TL;
    INT16U              usConvBatchPullDelay;// CONV_BATCH_PULL_DELAY      (PARA_LIST[148]|PARA_LIST[149] << 8) /*  [148,149]��������ܼ��ӳ�   */
//INT8U      *CP_DELAYH;
//INT8U      *CP_DELAYL;
    INT8U               ucConvBatchPullSetEn;// CONV_PULL_LEG_SET_ALLOW     PARA_LIST[150]                      /*  [150]��������               */
    INT16U              usConvPullWaitTime;// CONV_PULL_WAIT_T           (PARA_LIST[151]|PARA_LIST[152] << 8) /*  [151,152]�ȴ�ʱ��           */
//INT8U      *CP_WAIT_TH;
//INT8U      *CP_WAIT_TL;
    INT16U              usConvPullEndStrk;// CONV_PULL_END_STRK         (PARA_LIST[153]|PARA_LIST[154] << 8) /*  [153,154]Ŀ���г�           */
//INT8U      *CP_END_STRKH;
//INT8U      *CP_END_STRKL;
    INT8U               ucConvBatchPullInterl;// CONV_BATCH_PULL_OFFSET      PARA_LIST[155]                      /*  [155]�������������       */

    /*
     *  ������ˮ������
     */
    INT8U               ucFrtGirderLinkOutStartTime;// FRT_GIRDER_LINK_OUT_START_T PARA_LIST[156]                      /*  [156]������ǰ����ʼʱ��     */
    INT8U               ucFrtGirderLinkOutTime;// FRT_GIRDER_LINK_OUT_T       PARA_LIST[157]                      /*  [157]������ǰ������ʱ��     */
    INT8U               ucReadConvBatchPushDelay;// REAR_CONV_BATCH_PUSH_DELAY  PARA_LIST[158]                      /*  [158]�����ƺ�������ӳ�     */
    INT8U               ucFrtGirderBatchOutTime;// FRT_GIRDER_BATCH_OUT_T      PARA_LIST[159]                      /*  [159]������ǰ������ʱ��     */
    INT8U               ucFrtGirderBatchInTime;// FRT_GIRDER_BATCH_IN_T       PARA_LIST[160]                      /*  [160]������ǰ������ʱ��     */
    INT8U               ucFrtGirderLinkInStartTime;// FRT_GIRDER_LINK_IN_START_T  PARA_LIST[161]                      /*  [161]������ǰ����ʼʱ��     */
    INT8U               ucFrtGirderLinkInTime;// FRT_GIRDER_LINK_IN_T        PARA_LIST[162]                      /*  [162]������ǰ������ʱ��     */
    INT8U               ucAsqSprayNum;// ASQ_SPRAY_NUM               PARA_LIST[163]                      /*  [163]Asq�����������        */
    INT8U               ucAsqSprayTime;// ASQ_SPRAY_T                 PARA_LIST[164]                      /*  [164,165]��������ʱ��       */
//INT8U      *ASQ_Spray_TH;
//INT8U      *ASQ_Spray_TL;
    INT8U               ucHGAsqRange;// HG_ASQ_SCOPE                PARA_LIST[166]                      /*  [166]����asq��Χ            */
    INT8U               ucHgBpRange;// HG_BP_SCOPE                 PARA_LIST[167]                      /*  [167]�������ﷶΧ           */
    INT8U               ucHgFlipOutRange;// HG_FLIP_OUT_SCOPE           PARA_LIST[168]                      /*  [168]��������������Χ       */
    INT8U               ucHgFlipInRange;// HG_FLIP_IN_SCOPE            PARA_LIST[169]                      /*  [169]��������������Χ       */
          
    /*
     *  ������
     */
    INT8U               ucShearerDataInterval;// SHR_DATA_T                  PARA_LIST[170]                      /*  [170]��ú��λ�����ݱ���ʱ����*/
    INT8U               ucSnrDataInterval;// SNR_DATA_T                  PARA_LIST[171]                      /*  [171]���������ƴ���ʱ����*/
    INT8U               ucSnrFirtNum;// SNR_FIRST_NUM               PARA_LIST[172]                      /*  [172]�׼ܱ��               */
                                                                        //173-δ�� 
                                                                        //174-δ��
    INT8U               ucDownloadInterval;// DOWN_APART_T                PARA_LIST[175]                      /*  [175]���ؼ��               */
    INT8U               ucDownloadDelay;// DOWN_DELAY_T               (PARA_LIST[176]|PARA_LIST[177]<< 8)  /*  [176,177]������ʱ           */
//INT8U      *DOWN_DELAY_TL;                                            
//INT8U      *DOWN_DELAY_TH;
    INT8U               ucParaPwd0;// PARA_PASSWORD_0           ((PARA_LIST[181] >> 4) & 0x0F)            //�޸Ĳ�������1
    INT8U               ucParaPwd1;// PARA_PASSWORD_1           ((PARA_LIST[181] >> 0) & 0x0F)            //�޸Ĳ�������2
    INT8U               ucParaPwd2;// PARA_PASSWORD_2           ((PARA_LIST[180] >> 4) & 0x0F)            //�޸Ĳ�������3
    INT8U               ucParaPwd3;// PARA_PASSWORD_3           ((PARA_LIST[180] >> 0) & 0x0F)            //�޸Ĳ�������4
    INT8U               ucVip;// VIP_PARAMETER               PARA_LIST[182]                      /*  [182]�ؼ����� 0/1-��/��     */
    INT8U               ucAlterSideTime;//            PARA_LIST[183]                      /*  [183]���ܲ໤����ʱ�䣨����ʱ�䣩*/
    INT8U               ucAlterActionTime;// WARN_TIME_COUNT2            PARA_LIST[184]                      /*  [184]���ܵ׵�����ʱ�䣨����ʱ�䣩*/
    INT16U              usSnrSendInterval;// SENSOR_SEND_T              (PARA_LIST[185]|PARA_LIST[186]<<8)   /*  [185,186]����������ʱ��     */
//INT8U      *SENSOR_SEND_TL;                                             //185
//INT8U      *SENSOR_SEND_TH;                                             //186 
    INT8U               ucGrpMin;// GROUP_MIN                   PARA_LIST[187]                      /*  [187]����С��               */
    INT8U               ucGrpMax;// GROUP_MAX                   PARA_LIST[188]                      /*  [188]������               */
    INT8U               ucAsqSprayEnFlag;// ASQ_SPRAY_PERMIT            PARA_LIST[189]                      
                                                                        /*  [189]��ˮ����,0/1-��ֹ/���� 
                                                                         *  .0-�Զ��Ƽܱ����Ƿ�����������
                                                                         *  .1-�Զ��Ƽ�����Ƿ�����������
                                                                         *  .2-�Զ��Ƽ��ұ��Ƿ�����������
                                                                         *  .3-�Զ��Ƽܻ���������ͬ��������
                                                                         *  .4-�Զ��Ƽܷ�ú������ͬ��������
                                                                         *  .5 ������������������
                                                                         *  .6 ���������������Ƿ����� 
                                                                         *  .7 ��������ú�����Ƿ�����
                                                                         */

    INT8U               ucSnrEn;// SNR_FLAG                   (PARA_LIST[190]|PARA_LIST[191]<<8)   /*  [190,191]����������         */
//INT8U      *snr_flagL;                                                  //190
//INT8U      *snr_flagH;                                                  //191
    INT8U           ucAutoStabEn;// AUTO_STAB_CONTROL           PARA_LIST[192]                      /*  [192]��������������ж�������1/2/3����/����/������*/
    INT8U           ucAutoAsqEn;// AUTO_ASQ_CONTROL            PARA_LIST[193]                      /*  [193]�����Զ��Ƽ������ж�������*/  
    INT8U           ucAutoBpEn; //AUTO_BP_CONTROL             PARA_LIST[194]                      /*  [194]�������������ж������� */
    INT8U           ucAutoSsprayEn;// AUTO_SSPRAY_CONTROL         PARA_LIST[195]                      /*  [195]������ˮ�����ж������� */ 
    INT8U           ucAutoAbortMax;// AUTO_FORBID_SUPPLY_1        PARA_LIST[196]                      /*  [196]�����в������ܴ��     */
    INT8U           ucAutoAbortMin;// AUTO_FORBID_SUPPLY_2        PARA_LIST[197]                      /*  [197]�����в�������С��     */
    INT8U           ucLowStrebStartTime;// DOWN_STREB_START            PARA_LIST[200]                      /*  [200]����ʱƽ�⿪ʼ����ʱ�� */
    INT8U           ucLowStrebTime;// DOWN_STREB_TIME             PARA_LIST[201]                      /*  [201]����ʱƽ�⶯��ʱ��     */
    INT8U           ucSetStrebStartTime;// UP_STREB_START              PARA_LIST[202]                      /*  [202]����ʱƽ�⿪ʼ����ʱ�� */
    INT8U           ucSetStrebTime;// UP_STREB_TIME               PARA_LIST[203]                      /*  [203]����ʱƽ�⶯��ʱ��     */
    INT8U           ucBatchSprayRange;// TG_SSPRAY1                  PARA_LIST[204]                      /*  [204]������ˮ��Χ           */
    INT8U           ucBatchSprayTime;// TG_SSPRAY2                  PARA_LIST[205]                      /*  [205]������ˮʱ��           */
    INT8U           ucBatchSprayInterval;// TG_SSPRAY_OFFSET            PARA_LIST[206]                      /*  [206]������ˮ�������       */
    INT8U           ucMiddleNum1;// MIDDLE_NUM_1                PARA_LIST[208]                      /*  [208]�м��С��             */
    INT8U           ucMiddleNum2;// MIDDLE_NUM_2                PARA_LIST[209]                      /*  [209]�м�ܴ��             */
    INT8U           ucFlashBoardInTime1;// IN_FLASHBOARD_T1            PARA_LIST[210]                      /*  [210]�Ŷ�úASQ�ղ�嶯��ʱ��1*/
    INT8U           ucTailInStartTime;// IN_TAIL_START_T1            PARA_LIST[211]                      /*  [211]�Ŷ�úASQ��β����ʼ����ʱ��1*/
    INT8U           ucTailInActTime;// IN_TAIL_ACT_T1              PARA_LIST[212]                      /*  [212]�Ŷ�úASQ��β������ʱ��1*/
    INT8U           ucAsqExpendTime;// ASQ_EXPEND_T1               PARA_LIST[213]                      /*  [213]��úʱ��1              */
    INT8U           ucTailOutActTime;// OUT_TAIL_ACT_T1             PARA_LIST[214]                      /*  [214]�Ŷ�úASQ��β������ʱ��1*/
    INT8U           ucFlashBoardOutStartTime;// OUT_FLASHBOARD_START_T1     PARA_LIST[215]                      /*  [215]�Ŷ�úASQ���忪ʼ����ʱ��1*/
    INT8U           ucFlashBoardOutActTime;// OUT_FLASHBOARD_ACT_T1       PARA_LIST[216]                      /*  [216]�Ŷ�úASQ���嶯��ʱ��1*/
    INT8U           ucExpendUpWaitTime;// EXPEND_UP_T1                PARA_LIST[217]                      /*  [217]�Ŷ�ú�Ϸ��ȴ�ʱ��1    */
    INT8U           ucCycles1;// CIRCULAR_1                  PARA_LIST[218]                      /*  [218]ѭ������1              */
    INT8U           ucFlashBoardInTime2;// IN_FLASHBOARD_T2            PARA_LIST[219]                      /*  [219]�Ŷ�úASQ�ղ�嶯��ʱ��2*/
    INT8U           ucTailInStartTime2;// IN_TAIL_START_T2            PARA_LIST[220]                      /*  [220]�Ŷ�úASQ��β����ʼ����ʱ��2*/
    INT8U           ucTailInActTime2;// IN_TAIL_ACT_T2              PARA_LIST[221]                      /*  [221]�Ŷ�úASQ��β������ʱ��2*/
    INT8U           ucAsqExpendTime2;// ASQ_EXPEND_T2               PARA_LIST[222]                      /*  [222]��úʱ��2              */
    INT8U           ucTailOutActTime2;// OUT_TAIL_ACT_T2             PARA_LIST[223]                      /*  [223]�Ŷ�úASQ��β������ʱ��2*/
    INT8U           ucFlashBoardOutStartTime2;// OUT_FLASHBOARD_START_T2     PARA_LIST[224]                      /*  [224]�Ŷ�úASQ���忪ʼ����ʱ��2*/
    INT8U           ucFlashBoardOutActTime2;// OUT_FLASHBOARD_ACT_T2       PARA_LIST[225]                      /*  [225]�Ŷ�úASQ���嶯��ʱ��2*/
    INT8U           ucExpendUpWaitTime2;// EXPEND_UP_T2                PARA_LIST[226]                      /*  [226]�Ŷ�ú�Ϸ��ȴ�ʱ��2    */
    INT8U           ucCycles2;// CIRCULAR_2                  PARA_LIST[227]                      /*  [227]ѭ������2              */
    INT8U           ucFlashBoardInTime3;// IN_FLASHBOARD_T3            PARA_LIST[228]                      /*  [228]�Ŷ�úASQ�ղ�嶯��ʱ��3*/
    INT8U           ucTailInStartTime3;// IN_TAIL_START_T3            PARA_LIST[229]                      /*  [229]�Ŷ�úASQ��β����ʼ����ʱ��3*/
    INT8U           ucTailInActTime3;// IN_TAIL_ACT_T3              PARA_LIST[230]                      /*  [230]�Ŷ�úASQ��β������ʱ��3*/
    INT8U           ucAsqExpendTime3;// ASQ_EXPEND_T3               PARA_LIST[231]                      /*  [231]��úʱ��3              */
    INT8U           ucTailOutActTime3;// OUT_TAIL_ACT_T3             PARA_LIST[232]                      /*  [232]�Ŷ�úASQ��β������ʱ��3*/
    INT8U           ucFlashBoardOutStartTime3;// OUT_FLASHBOARD_START_T3     PARA_LIST[233]                      /*  [233]�Ŷ�úASQ���忪ʼ����ʱ��3*/
    INT8U           ucFlashBoardOutActTime3;// OUT_FLASHBOARD_ACT_T3       PARA_LIST[234]                      /*  [234]�Ŷ�úASQ���嶯��ʱ��3*/
    INT8U           ucExpendUpWaitTime3;// EXPEND_UP_T3                PARA_LIST[235]                      /*  [235]�Ŷ�ú�Ϸ��ȴ�ʱ��3    */
    INT8U           ucCycles3;// CIRCULAR_3                  PARA_LIST[236]                      /*  [236]ѭ������3              */
    INT8U           ucAsqExpendInterval;// ASQ_EXPEND_DELAY            PARA_LIST[237]                      /*  [237]�Ŷ�ú�ܼ��ӳ�ʱ��     */
    INT8U           ucExpendGrp;// EXPEND_GROUP                PARA_LIST[238]                      /*  [238]��ú������             */
    INT8U           ucExpendType;// EXPEND_OFFSET               PARA_LIST[239]                      /*  [239]�Ŷ�����               */
    INT8U           ucReturnTailOutTime; //RETURN_OUTAIL_T             PARA_LIST[240]                      /*  [240]�ظ�λβ����ʱ��       */
    INT8U           ucReturnFlashBoardOutStartTime;// RETURN_OUTF_START           PARA_LIST[241]                      /*  [241]�ظ�λ����쿪ʼʱ��   */
    INT8U           ucReturnFlashBoardOutActTime;// RETURN_OUTF_T               PARA_LIST[242]                      /*  [242]�ظ�λ����춯��ʱ��   */
    INT8U           ucReturnGrp;// RETURN_GROUP                PARA_LIST[243]                      /*  [243]�ظ�λ����             */
    INT8U           ucReturnInterval;// RETURN_OFFSET               PARA_LIST[244]                      /*  [244]�ظ�λ�������         */
    INT8U           ucExpendSprayEn;// EXPEND_SPRAY_PERMIT         PARA_LIST[245]                      
                                                                        /*  [245]- 
                                                                         *  Bit0-���ܷ�ú�����Ƿ�����
                                                                         *  Bit1-���ڼܷ�ú�����Ƿ�����
                                                                         *  Bit2-���ڼܷ�ú�����Ƿ�����
                                                                         *  bit3-β����嶯��ʱ��ú�����Ƿ�����
                                                                         */
    INT8U           ucExpendSprayTime;// EXPEND_SPRAY_TIME           PARA_LIST[246]                      /*  [246]��ú����ʱ��           */
    INT8U           ucExpendSprayNum;// EXPEND_SPRAY_NUM            PARA_LIST[247]                      /*  [247]��ú�������           */
    INT8U           ucTimingSprayDelay;// TIMING_SPRAY_DELAY          PARA_LIST[248]                      /*  [248]��ʱ�����������       */
    INT8U           ucTimingSprayGrp;// TIMING_SPRAY_GROUP          PARA_LIST[249]                      /*  [249]��ʱ�������ڼ���       */
    INT8U           ucTimingSprayTime;// TIMING_SPRAY_T              PARA_LIST[250]                      //250-��ʱ������ʱ��
    INT8U           ucTimingSprayDir;// TIMING_SPRAY_START          PARA_LIST[251]                      //251-��ʱ����������1-��С����2-�Ӵ�С
    INT8U           ucTimingSprayEn;// TIMING_SPRAY_PERMIT         PARA_LIST[252]                      //252-��ʱ�����Ƿ�����
    INT16U          usSideOutTs;// SIDE_OUT_TS                (PARA_LIST[253]|PARA_LIST[254]<<8)
//INT8U      *SIDE_OUT_TSL;											    //253,254 ������໤����ʱ��
//INT8U      *SIDE_OUT_TSH;											    //253,254 ������໤����ʱ��
    INT8U           ucStab2OutStartTime;// STAB2_OUT_START_T           PARA_LIST[256]                      //256�������Զ��Ƽܶ��������쿪ʼ����ʱ��
    INT8U           ucStab2OutActTime;// STAB2_OUT_ACT_T             PARA_LIST[257]                      //257�������Զ��Ƽܶ��������춯��ʱ��        
    INT8U           ucStab3OutStartTime;// STAB3_OUT_START_T           PARA_LIST[258]                      //258�������Զ��Ƽ����������쿪ʼ����ʱ��
    INT8U           ucStab3OutActTime;// STAB3_OUT_ACT_T             PARA_LIST[259]                      //259�������Զ��Ƽ����������춯��ʱ��
    INT8U           ucStab2InStartTime;// STAB2_IN_START_T            PARA_LIST[260]                      //260�������Զ��Ƽܶ��������տ�ʼ����ʱ��
    INT8U           ucStab2InActTime;// STAB2_IN_ACT_T              PARA_LIST[261]                      //261�������Զ��Ƽܶ��������ն���ʱ��        
    INT8U           ucStab3InStartTime;// STAB3_IN_START_T            PARA_LIST[262]                      //262�������Զ��Ƽ����������տ�ʼ����ʱ��
    INT8U           ucStab3InActTime;// STAB3_IN_ACT_T              PARA_LIST[263]                      //263�������Զ��Ƽ����������ն���ʱ��
    INT8U           ucShakeTime;// SHAKE_TIME                  PARA_LIST[264]                      //264-����ʱ��
    INT8U           ucShakeTimes;// SHAKE_NUM                   PARA_LIST[265]                      //265-��������
    INT16U          usMsgWndTime;// MESSAGE_WIN_TIME           (PARA_LIST[266]|PARA_LIST[267])      //266��267-��Ϣ��ʱ��ms
//INT8U      *MESSAGE_WIN_TIMEL;                                          //266
//INT8U      *MESSAGE_WIN_TIMEH;                                          //267
    INT16U           usEvtWndTime;// EVENT_WIN_TIME             (PARA_LIST[268]|PARA_LIST[269]<<8)   //268��269-�¼���ʱ��ms
//INT8U      *EVENT_WIN_TIMEL;                                            //268
//INT8U      *EVENT_WIN_TIMEH;                                            //269
    INT8U           ucAsqReturnDelay;// ASQ_RETURN_DELAY            PARA_LIST[270]                      //270-�ظ�λ�ܼ��ӳ�ʱ��
    INT16U          usAsqStrebP0;// ASQ_STREB_P0               (PARA_LIST[271]|PARA_LIST[272]<<8)   //271,272 ƽ����ʼѹ��
//INT8U      *ASQ_STREB_P0L;
//INT8U      *ASQ_STREB_P0H;                                                                                                        											
    INT8U           ucAsqStrebEn;// ASQ_STREB_IN_OUT_FLAG       PARA_LIST[273]                      //273  bit0ƽ������:0��ֹ��1����
                                                                        //     bit1-һ�������г̴��������أ�0-����1-��
                                                                        //     bit2-��Ǵ��������أ�0-����1-��
                                                                        //     bit3-һ������ѹ�����������أ�0-����1-��
                                                                        //     bit4-����������λ���������أ�0-����1-��
                                                                        //     bit5�߶ȴ���������
                                                                        //     bit6 ƽ����ѹ������
                                                                        //     bit7 ƽ����ѹ������
    INT16U          usObli1Cal1;// OBLI1_REVISE_D             (PARA_LIST[274]|PARA_LIST[275]<<8)   //274,275У��ֵ1
//INT8U      *OBLI1_REVISE_DL;
//INT8U      *OBLI1_REVISE_DH;
     INT16U          usObli1Cal2;// OBLI2_REVISE_D             (PARA_LIST[276]|PARA_LIST[277]<<8)   //276,277У��ֵ2
//INT8U      *OBLI2_REVISE_DL;
//INT8U      *OBLI2_REVISE_DH;
     INT16U          usObli1Cal3;// OBLI3_REVISE_D             (PARA_LIST[278]|PARA_LIST[279]<<8)   //278,279У��ֵ3
//INT8U      *OBLI3_REVISE_DL;
//INT8U      *OBLI3_REVISE_DH;
    INT16U          usLength1; //LENGTH_1                   (PARA_LIST[280]|PARA_LIST[281]<<8)   //280,281-����1
//INT8U      *LENGTH_1L;
//INT8U      *LENGTH_1H;
    INT16U          usLength2;// LENGTH_2                   (PARA_LIST[282]|PARA_LIST[283]<<8)   //282,283-����2
//INT8U      *LENGTH_2L;
//INT8U      *LENGTH_2H;
    INT16U          usLength3;// LENGTH_3                   (PARA_LIST[284]|PARA_LIST[285]<<8)   //284,285-����3
//INT8U      *LENGTH_3L;
//INT8U      *LENGTH_3H;
    INT16U          usLength4;// LENGTH_4                   (PARA_LIST[286]|PARA_LIST[287]<<8)   //286��287-�����߶�
//INT8U      *LENGTH_4L;
//INT8U      *LENGTH_4H;
    INT8U           ucObliSendInterval;// SEND_DISTIME                PARA_LIST[288]                      //288-��Ǳ��ͼ��
    INT8U           ucObliRelative;// OBLI_RELATE_CONTR           PARA_LIST[289]                      //289-�����ؿ���
                                                                        /*
                                                                         *  Bit0-ƽ��,����������
                                                                         *  Bit1-�����߶����
                                                                         *  Bit2-����������
                                                                         *  Bit3-�����߶����
                                                                         *  Bit4-��׼֧������ 0-��ֹ 1-���� 
                                                                         *  Bit5-�Զ��Ƽ�ʱ�����͸߶����
                                                                         */
    INT8U           ucObliFixNum;// OBLI_FIX_NUM                PARA_LIST[290]                      //290 ������Ǵ�������װ����
    INT8U           ucObli4Fix;// OBLI4_FIT_FLAG              PARA_LIST[291]                      //291������Ǵ�������װ��־
    INT16U          usObliCal4;// OBLI4_REVISE_D             (PARA_LIST[292]|PARA_LIST[293]<<8)   //292,293У��ֵ4
//INT8U      *OBLI4_REVISE_DL;
//INT8U      *OBLI4_REVISE_DH; 
    INT8U           ucHeightShow;// HEIGHT_SHOW_D               PARA_LIST[294]                      //294---��ʾ�߶ȷ�ֵ
    INT8U           ucObliShow;// OBLI_SHOW_D                 PARA_LIST[295]                      //295---��ʾ�Ƕȷ�ֵ
    INT8U           ucObliChkTime;// CHECK_OLI_TIME              PARA_LIST[296]                      //296---�����Ǵ�����ʱ�� 
    INT8U           ucObliAxis;// OBLI_X_Y                    PARA_LIST[297]                      //297-bit0��0-x��1-y��ѡ��
    INT8U           ucStab3BatchOutTime;// STAB3_OUT_T                 PARA_LIST[298]                      //298-�������������ﶯ��ʱ��
    INT8U           ucStab3BatchInTime;// STAB3_IN_T                  PARA_LIST[299]                      //299-�������������ﶯ��ʱ��
    INT16U          usLowHeigth;// DROP_HEIGHT                (PARA_LIST[300]|PARA_LIST[301]<<8)   //300,301-�����߶�����
//INT8U      *DROP_HEIGHTL;                                             
//INT8U      *DROP_HEIGHTH;
    INT8U           ucObliBaseLine;// COM_ABS_ANGLE               PARA_LIST[302]                      //302-�������//*COM_ABS_ANGLE��2---֧�ܻ�׼��3---���Ƕȣ�4---ȡ��֧�ܻ�׼��5-�汾�ţ�6-eeprom״̬
    INT16U          usStab1OutEnd;// STAB1_OUT_AIM              (PARA_LIST[303]|PARA_LIST[304]<<8)   //303,304-��һ������Ŀ���г�
//INT8U      *STAB1_OUT_AIML;
//INT8U      *STAB1_OUT_AIMH;
    INT16U          usStab1InEnd;// STAB1_IN_AIM               (PARA_LIST[305]|PARA_LIST[306]<<8)   //305,306-��һ������Ŀ���г�
//INT8U      *STAB1_IN_AIML;
//INT8U      *STAB1_IN_AIMH;
    INT16U          usStab1OutPEnd;// STAB1_OUT_PRESSURE_AIM     (PARA_LIST[307]|PARA_LIST[308]<<8)   //307,308-��һ������Ŀ��ѹ��
//INT8U      *STAB1_OUT_PRESSURE_AIML;
//INT8U      *STAB1_OUT_PRESSURE_AIMH;
    INT8U           ucRewashEn;// REVERSE_SWASH_PROHIBIT      PARA_LIST[309]                      //309-�Զ���ʱ����ϴ���ܿ���
                                                                        //Bit0-���幦���ܿ��ء�0-��ֹ��1-����
                                                                        //Bit1-�Ϸ��忪�ء�����0-��ֹ��1-����
                                                                        //Bit2-�Ϸ��忪�ء�����0-��ֹ��1-����
                                                                        //bit3-���鷴��ϴ����  0-��ֹ  1-����
    INT8U           ucRewashTime;// REVERSE_SWASH_T             PARA_LIST[310]                      //310-���嶯��ʱ��
    INT8U           ucRewashUpDownInterval;// UP_DOWN_TIMEGAP             PARA_LIST[311]                      //311-���·���ʱ����
    INT8U           ucRewashInterval;// SHIELD_SWASH_TIMEGAP        PARA_LIST[312]                      //312-�ܼ�����ʱ����
    INT8U           ucTimingRewashHour1;// REVERSE_SWASH_TIME1_H       PARA_LIST[313]                      //313-���嶨ʱ1��ʱ
    INT8U           ucTimingRewashMin1;// REVERSE_SWASH_TIME1_M       PARA_LIST[314]                      //314-���嶨ʱ1����
    INT8U           ucTimingRewashHour2;// REVERSE_SWASH_TIME2_H       PARA_LIST[315]                      //315-���嶨ʱ2��ʱ
    INT8U           ucTimingRewashMin2;// REVERSE_SWASH_TIME2_M       PARA_LIST[316]                      //316-���嶨ʱ2����
    INT8U           ucTimingRewashHour3;// REVERSE_SWASH_TIME3_H       PARA_LIST[317]                      //317-���嶨ʱ3��ʱ
    INT8U           ucTimingRewashMin3;// REVERSE_SWASH_TIME3_M       PARA_LIST[318]                      //318-���嶨ʱ3����
    INT8U           ucTimingRewashHour4;// REVERSE_SWASH_TIME4_H       PARA_LIST[319]                      //319-���嶨ʱ4��ʱ
    INT8U           ucTimingRewashMin4;// REVERSE_SWASH_TIME4_M       PARA_LIST[320]                      //320-���嶨ʱ4����
    INT8U           ucStabPsaEn;// STAB_PSA_CONTROL            PARA_LIST[321]                      //321-һ�������Զ���ѹ���
                                                                        //bit0-һ�������Զ���ѹ������ֹ
                                                                        //bit1-������������������,��ֹ
                                                                        //bit2-������һ������ֶ��Ƿ�����
                                                                        //bit3-һ��������λ���������ֹ
    INT16U          usStabPsaP0;// STAB_PSA_P0                (PARA_LIST[322]|PARA_LIST[323]<<8)   //322,323-һ�������Զ���ѹѹ������
//INT8U      *STAB_PSA_P0L;
//INT8U      *STAB_PSA_P0H;
    INT16U          usStabPsaP1;// STAB_PSA_P1                (PARA_LIST[324]|PARA_LIST[325]<<8)   //324,325-һ�������Զ���ѹѹ������
//INT8U      *STAB_PSA_P1L;
//INT8U      *STAB_PSA_P1H;
    INT8U           ucStabPsaTimes;// STAB_PSA_NUM                PARA_LIST[326]                      //326-һ�������Զ���ѹ�������
    INT8U           ucStabPsaTime;// STAB_PSA_T                  PARA_LIST[327]                      //327-һ�������Զ���ѹ����ʱ��
    INT8U           ucStabPsaInterval;// STAB_PSA_SPACET             PARA_LIST[328]                      //328-һ�������Զ���ѹ���ʱ��
    INT16U          usStabPsaP2;// STAB_PSA_P2                (PARA_LIST[329]|PARA_LIST[330]<<8)   //329,330-һ�������Զ���ѹĿ��ѹ��
//INT8U      *STAB_PSA_P2L;
//INT8U      *STAB_PSA_P2H;
    INT8U           ucAsqStabLowDelay;// ASQ_STAB_LOW_DELAY          PARA_LIST[331]                      //331--��ʱ����
    INT8U           ucSprayEn;// PLATEN_FORER_BEHIND         PARA_LIST[332]                      //332-������������ǰ��Ͳ���Ǻ��Ͳ��
                                                                        //bit0-��ǰ����0-��ֹ 1-����
                                                                        //bit1-�Ϻ�����0-��ֹ 1-����
                                                                        //bit2-��ǰ����0-��ֹ 1-����
                                                                        //bit3-�º�����0-��ֹ 1-����
                                                                        //bit5-��������
                                                                        //bit6-�Ƽ�����
                                                                        //bit7-��������
    INT8U           ucAsqSprayEn; //ASQ_SPRAY                   PARA_LIST[333]                      //333-�Զ��Ƽ���ˮ����
    INT8U           ucAsqSprayStartTime;// ASQ_SPRAY_B_T               PARA_LIST[334]                      //334-�Զ��Ƽܿ�ʼ��ˮʱ��0.1s
    INT8U           ucAsqLowSprayTime;// DOWN_SPRAY_T                PARA_LIST[335]                      //335-�����Ƽ���ˮʱ��0.1s
    INT16U          usBaseLiftEnd;// LIFT_SET_AIM               (PARA_LIST[336]|PARA_LIST[337]<<8)   //336,337-�Ƽ�̧�׵�Ŀ���г�
//INT8U      *LIFT_SET_AIML;
//INT8U      *LIFT_SET_AIMH;
    INT8U           ucStabInStartTimeMin;// STAB_IN_S_MIN               PARA_LIST[338]                      //338������ ��һ�����￪ʼ��Сʱ��
    INT8U           ucStabInStartTimeMax;// STAB_IN_S_MAX               PARA_LIST[339]                      //339������ ��һ�����￪ʼ���ʱ��																	
    INT8U           ucHGUpFrtSSprayDis;// HG_SSPRAY3                  PARA_LIST[340]                      //340-����ǰ��Ͳ����
    INT8U           ucHGUpFrtSSprayRange;// HG_SSPRAY4                  PARA_LIST[341]                      //341-����ǰ��Ͳ��Χ
    INT8U           ucHGUpRearSSprayDis;// HG_SSPRAY5                  PARA_LIST[342]                      //342-���к��Ͳ����
    INT8U           ucHGUpRearSSprayRange;// HG_SSPRAY6                  PARA_LIST[343]                      //343-���к��Ͳ��Χ
    INT8U           ucHGDownFrtSSprayDis;// HG_SSPRAY7                  PARA_LIST[344]                      //344-����ǰ��Ͳ����
    INT8U           ucHGDownFrtSSprayRange;// HG_SSPRAY8                  PARA_LIST[345]                      //345-����ǰ��Ͳ��Χ
    INT8U           ucHGDownRearSSprayDis;// HG_SSPRAY9                  PARA_LIST[346]                      //346-���к��Ͳ����
    INT8U           ucHGDownRearSSprayRange;// HG_SSPRAY10                 PARA_LIST[347]                      //347-���к��Ͳ��Χ
    INT8U           ucHGSSprayTime;// HG_SSPRAY_TIME              PARA_LIST[348]                      //348-����������ʱ��
    INT8U           ucStab2InTime;// STAB2_IN_T                  PARA_LIST[349]                      //349-���������ն���ʱ��
    INT8U           ucStab2OutTime;// STAB2_OUT_T                 PARA_LIST[350]                      //350-���������춯��ʱ��
    INT8U           ucStab2OutStartTime2;// STAB2_OUT_START2_T          PARA_LIST[351]                      //351-����ʱ���������쿪ʼʱ�䣨�ڶ��ζ�����
    INT8U           ucStab2OutActTime2;// STAB2_OUT_ACT2_T            PARA_LIST[352]                      //352-����ʱ���������춯��ʱ�䣨�ڶ��ζ�����
    INT8U           ucStab2InStartTime2;// STAB2_IN_START2_T           PARA_LIST[353]                      //353-����ʱ���������տ�ʼʱ�䣨�ڶ��ζ�����
    INT8U           ucStab2InActTime2;// STAB2_IN_ACT2_T             PARA_LIST[354]                      //354-����ʱ���������ն���ʱ�䣨�ڶ��ζ�����
    INT8U           ucStab2ActType;// STAB2_ACT                   PARA_LIST[355]                      //355-��������������������	  1--�� 0--��
                                                                        //Bit3		һ��������ʱ���������2����ʲô������/��
                                                                        //Bit2		һ��������ʱ���������1����ʲô������/��
                                                                        //Bit1		һ��������ʱ���������2����ʲô������/�� 
                                                                        //Bit0		һ��������ʱ���������1����ʲô������/�� 
    INT8U           ucLeftSideOutTime;// LEFT_SIDE_OUT_T             PARA_LIST[356]                      //356-�����춥���໤�嶯��ʱ��
    INT8U           ucRightSideOutTime;// RIGHT_SIDE_OUT_T            PARA_LIST[357]                      //357-�������ڻ����໤�嶯��ʱ��
    INT8U           ucAsqSideEn;// ASQ_FORMER_SIDE             PARA_LIST[358]                      //358-�Զ��Ƽܹ��̲໤�嶯������
    INT8U           ucAsqsetSideOutTime;// ASQ_SIDE_OUT_T              PARA_LIST[359]                      //359-ASQ����������໤����ʱ��
    INT8U           ucAsqPullSideOutTime;// ASQ_SIDE_OUTT_T1            PARA_LIST[360]                      //360-ASQ���Ƽܺ���໤����ʱ��
    INT8U           ucAsqLiftLowTime;// ASQ_LIFT_LOW_T              PARA_LIST[361]                      //361-ASQ����̧��������ʱ��
    INT8U           ucJockeySideLockTime;// JOCKEY_SIDE_LOCK_T          PARA_LIST[362]                      //362-����������໤��������ʱ��
    INT8U           ucAsqSideLockTime;// ASQ_SIDE_LOCK_T             PARA_LIST[363]                      //363-ASQ�������໤��������ʱ��
    INT8U           ucBatchRewashOffset;// FILTRATE_OFFSET             PARA_LIST[364]                      //364-���鷴��ϴ�������
    INT8U           ucBatchRewashRange;// FILTRATE_SCOPE              PARA_LIST[365]                      //365-���鷴��ϴ������Χ
    INT8U           ucYear;// MODIFY_YEAR                 PARA_LIST[366]                      //366-ʱ���޸���
    INT8U           ucMonth;// MODIFY_MONTH                PARA_LIST[367]                      //367-ʱ���޸���
    INT8U           ucDate;// MODIFY_DATE                 PARA_LIST[368]                      //368-ʱ���޸���
    INT8U           ucHour;// MODIFY_HOUR                 PARA_LIST[369]                      //369-ʱ���޸�ʱ
    INT8U           ucMinute;// MODIFY_MINUTE               PARA_LIST[370]                      //370-ʱ���޸ķ�
    INT8U           ucWeek;// MODIFY_WEEK                 PARA_LIST[371]                      //371-ʱ���޸�����
    INT16U          usFixHeight;// FIX_HEIGHT                 (PARA_LIST[372]|PARA_LIST[373]<<8)   //372��373-�������ǰ�װ�߶�
//INT8U      *FIX_HEIGHTL;                                                        
//INT8U      *FIX_HEIGHTH;                                                         
    INT16U          usIrHoldTime;// IR_STAY_TIME               (PARA_LIST[374]|PARA_LIST[375]<<8)   //374��375-�����źű���ʱ��
//INT8U      *IR_STAY_TIMEL;
//INT8U      *IR_STAY_TIMEH;
    INT8U           ucMiddleNum3;// MIDDLE_NUM_3                PARA_LIST[376]                      //376-��ͷС��
    INT8U           ucMiddleNum4;// MIDDLE_NUM_4                PARA_LIST[377]                      //377-��ͷ�ܴ��
    INT8U           ucAngle;// ANGLE_NUM                   PARA_LIST[378]                      //378-�������ڻ����н�
    INT8U           ucAngleUp;// ANGLE_UP_NUM                PARA_LIST[379]                      //379-�����������ƽǶ�  
    INT8U           ucAngeleDown;// ANGLE_DOWN_NUM              PARA_LIST[380]                      //380-�����������ƽǶ�
    INT8U           ucAutoType;// AUTO_TYPE                   PARA_LIST[381]                      //381-�Զ���������  0-�в� 1-ȫ������


    INT8U       ucShieldNo;
    INT8U       ucAsqWarnT;
    INT8U       ucFlipOutStartT;
    INT8U       ucFlipOutActT;
    INT8U       ucPusherOutStartT;
    INT8U       ucPusherOutActT;
    INT8U       ucFlipInStartT;
    INT8U       ucFlipInActT;
    INT8U       ucPusherInStartT;
    INT8U       ucPusherInActT;
    INT8U       ucLiftOutStartT;
    INT8U       ucLiftOutActT;
    INT8U       ucLiftInStartT;
    INT8U       ucLiftInActT;
}__attribute__((packed)) DEV_PARA, *PDEV_PARA;


typedef struct {
    INT8U       ucAsqWarnT;
    INT8U       ucFlipOutStartT;
    INT8U       ucFlipOutActT;
    INT8U       ucPusherOutStartT;
    INT8U       ucPusherOutActT;
    INT8U       ucFlipInStartT;
    INT8U       ucFlipInActT;
    INT8U       ucPusherInStartT;
    INT8U       ucPusherInActT;
    INT8U       ucLiftOutStartT;
    INT8U       ucLiftOutActT;
    INT8U       ucLiftInStartT;
    INT8U       ucLiftInActT;    
} AUTO_PARA, *PAUTO_PARA;

typedef enum {                                                          /*  ֧��״̬����                */
    STA_IDLE,                                                           /*  ����                        */
    STA_HOST,                                                           /*  ����                        */
    STA_S_SLAVE,                                                        /*  �ӿ�                        */
    STA_G_SLAVE,                                                        /*  ����ӿ�                    */
    STA_S_LOCK,                                                         /*  �������                    */
    STA_H_LOCK,                                                         /*  Ӳ������                    */
    //STA_SELF,                                                           /*  �Կ�                        */
    STA_ACT = 0x08,                                                     /*  ������                      */                                    
} SHIELD_STAT;
 

/*����ϵͳʱ��*/
#define     MS_TIMER  							(OSTimeGet()*(1000/OS_TICKS_PER_SEC))
#define     SEC_TIMER							(OSTimeGet()/OS_TICKS_PER_SEC)
typedef struct __dev_status {
    INT16U          usShieldNo;                                         /*  ���ܵ�ַ                    */
    SHIELD_STAT     ucStatus;                                           /*  ����״̬��                  */
    INT8U           ucIsStop;
    INT8U           ucIsLock;
    INT8U           ucIsAuthorized;
    INT32U          uiAuthorizedTimeoutTick;                            /*  ��Ȩ��ʱ��ʱ��              */
    INT32U          uiValveStatus;                                      /*  ���ܷ�����״̬              */
    INT8U           ucIsWarning;                                        /*  Ԥ��״̬                    */
    INT32U          uiWarnStartTick;                                    /*  Ԥ����ʼ��ʱ��              */
    INT32U          uiWarnTimeoutTick;                                  /*  Ԥ����ʱ��ʱ��              */
    INT8U           ucSlaveNo;                                          /*  ���ؼܺ�                    */
    INT8U           ucSlaveDir;                                         /*  ���ؼܷ���
                                                                         *  0   ��
                                                                         *  1   ��         
                                                                         */
    
    INT8U           ucShearerDir;                                       /*  ��ú������                  */
    INT8U           ucShearerPos;                                       /*  ��ú��λ��                  */
    //INT8U           ucIndicatorFlag;
    union {
        INT8U       ucWord;
        struct {
            INT8U   ucKeyPush       :2;
            INT8U   ucSafe          :2;
            INT8U   ucWarn          :2;
            INT8U   ucRsv           :2;
        }Bits;
    } ucIndicatorFlg;                                                   /*  ���ⱨ����ʶ                */
    
    INT32U          uiTimeStamp;                                        /*  ϵͳʱ���                  */
    
    INT8U           ucIsReceiverReady;                                  /*  ���߽�����������ʶ          */
    INT8U           ucIsRemoteReady;                                    /*  ����ң�������ӱ�ʶ          */
    INT32U          uiRemoteCommTimeoutTick;                            /*  ����ң����ͨ�ų�ʱ��ʱ��    */
    INT32U          uiRemoteTimeoutTick;                                /*  ����ң�������ӳ�ʱ��ʱ��    */
    INT32U          uiMasterTimeoutTick;                                /*  ���س�ʱ��ʱ��              */
} DEV_STATUS, *PDEV_STATUS;


/*********************************************************************************************************
  �����жϷ���������
*********************************************************************************************************/
/*********************************************************************************************************
** Function name:       FIQ_Exception
** Descriptions:        FIQ�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void FIQ_Exception (void);

/*********************************************************************************************************
** Function name:       DefIRQ_Exception
** Descriptions:        �������жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void DefIRQ_Exception (void);

/*********************************************************************************************************
** Function name:       PWM0_ISR
** Descriptions:        PWM�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void PWM0_ISR (void);

/*********************************************************************************************************
** Function name:       RTC0_ISR
** Descriptions:        RTC�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void RTC0_ISR (void);

/*********************************************************************************************************
** Function name:       SPI0_ISR
** Descriptions:        SPI0�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void SPI0_ISR (void);

/*********************************************************************************************************
** Function name:       SPI1_ISR
** Descriptions:        SPI1�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void SPI1_ISR (void);

/*********************************************************************************************************
** Function name:       I2C0_ISR
** Descriptions:        I2C0�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void I2C0_ISR (void);

/*********************************************************************************************************
** Function name:       WDT0_ISR
** Descriptions:        WDT�жϷ������
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void WDT0_ISR (void);

/*********************************************************************************************************
** Function name:       EINT0_ISR
** Descriptions:        �ⲿ�ж�0�û���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void EINT0_ISR (void);

/*********************************************************************************************************
** Function name:       EINT1_ISR
** Descriptions:        �ⲿ�ж�1�û���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void EINT1_ISR (void);

/*********************************************************************************************************
** Function name:       EINT2_ISR
** Descriptions:        �ⲿ�ж�2�û���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void EINT2_ISR (void);

/*********************************************************************************************************
** Function name:       EINT3_ISR
** Descriptions:        �ⲿ�ж�3�û���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void EINT3_ISR (void);

/*********************************************************************************************************
** Function name:       UART0_ISR
** Descriptions:        UART0�ж���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void UART0_ISR (void);

/*********************************************************************************************************
** Function name:       UART1_ISR
** Descriptions:        UART1�ж���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void UART1_ISR (void);

/*********************************************************************************************************
** Function name:       TIMER1_ISR
** Descriptions:        TIMER1�ж���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void TIMER1_ISR (void);

/*********************************************************************************************************
** Function name:       CAN_ISR
** Descriptions:        CAN�ж���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void CAN_ISR (void);

/*********************************************************************************************************
** Function name:       ADC0_ISR
** Descriptions:        ADC�ж���Ӧ����
** input parameters:    ��
** output parameters:       none
** Returned value:      ��
*********************************************************************************************************/
extern void ADC0_ISR (void);


extern void guiPrintf(unsigned int uiXPoint, unsigned int uiYPoint, INT8U ucIsAnti, char * pcString,...);

extern void guiClScr();

extern void  guiClrRectangle(uint32 x0, uint32 y0, uint32 x1, uint32 y1);
    
extern unsigned long    GulKeyMsg;                                      /*  ������Ϣ����                */

extern DEV_PARA         Gdp;
extern DEV_STATUS       Gds;

#endif

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
