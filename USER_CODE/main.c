/****************************************Copyright (c)****************************************************
**                          China Coal Beijing Coal Mining Co.,Ltd.
**                                      
**                             https://www.cbmj.chinacoal.com/
**
**--------------File Info---------------------------------------------------------------------------------
**  File name :         main.c
**  Last modified Date :
**  Last Version :      V1.00
**  Descriptions :      �û�������
**
**--------------------------------------------------------------------------------------------------------
** Created by:          ����������
** Created date:        2014-08-25
** Version:             V1.00
** Descriptions :      
**--------------------------------------------------------------------------------------------------------
** Modified by :        sn
** Modified date :      2020-4-29
** Version :            0.2
** Descriptions :       �޸��Զ���ѹǰ��������
*********************************************************************************************************/

#include "main.h"
/*********************************************************************************************************
  TASK0 ����ID�����ȼ�����ջ���ü���������                                
*********************************************************************************************************/
#define TASK0_ID            4                                           /* �����ID                     */
#define TASK0_PRIO          TASK0_ID                                    /* ��������ȼ�                 */
#define TASK0_STACK_SIZE    256                                         /* �����û���ջ����             */
OS_STK  TASK0_STACK[TASK0_STACK_SIZE];                                  /* ��������0 ��ջ               */
void    TASK0(void *pdata);                                             /* ��������0                    */

/*********************************************************************************************************
  TASK21 ����ID�����ȼ�����ջ���ü���������                                
*********************************************************************************************************/
#define TASK1_ID            5                                          /* �����ID                     */
#define TASK1_PRIO          TASK1_ID                                    /* ��������ȼ�                 */
#define TASK1_STACK_SIZE    256                                         /* �����û���ջ����             */
OS_STK  TASK1_STACK[TASK1_STACK_SIZE];                                  /* ��������21��ջ               */
void    TASK1(void *pdata);                                             /* ��������21                   */


#if 0  
/*********************************************************************************************************
  TASK2 ����ID�����ȼ�����ջ���ü���������                                
*********************************************************************************************************/ 
#define TASK2_ID            14                                          /* ��������ȼ�                 */
#define TASK2_PRI           TASK2_ID                                    /* �����ID                     */
#define TASK2_STACK_SIZE    512                                         /* �����û���ջ����             */
OS_STK  TASK2_STACK[TASK2_STACK_SIZE];                                  /* �������� 2��ջ               */
void    TASK2(void *pdata);                                             /* �������� 2                   */ 

/*********************************************************************************************************
  TASK3 ����ID�����ȼ�����ջ���ü���������                                
*********************************************************************************************************/
#define TASK3_ID            15                                          /* �����ID                     */
#define TASK3_PRIO          TASK3_ID                                    /* ��������ȼ�                 */
#define TASK3_STACK_SIZE    512                                         /* �����û���ջ����             */
OS_STK  TASK3_STACK[TASK3_STACK_SIZE];                                  /* �������� 3��ջ               */
void    TASK3(void *pdata);                                             /* �������� 3                   */

/*********************************************************************************************************
  TASK4 ����ID�����ȼ�����ջ���ü���������                                
*********************************************************************************************************/
#define TASK4_ID            16                                          /* �����ID                     */
#define TASK4_PRIO          TASK4_ID                                    /* ��������ȼ�                 */
#define TASK4_STACK_SIZE    512                                         /* �����û���ջ����             */
OS_STK  TASK4_STACK[TASK4_STACK_SIZE];                                  /* �������� 4��ջ               */
void    TASK4(void *pdata);                                             /* �������� 4                   */

/*********************************************************************************************************
  TASK5 ����ID�����ȼ�����ջ���ü���������                                
*********************************************************************************************************/
#define TASK5_ID            17                                          /* �����ID                     */
#define TASK5_PRIO          TASK5_ID                                    /* ��������ȼ�                 */
#define TASK5_STACK_SIZE    512                                         /* �����û���ջ����             */
OS_STK  TASK5_STACK[TASK5_STACK_SIZE];                                  /* �������� 5��ջ               */
void    TASK5(void *pdata);                                             /* �������� 5                   */
#endif


    /*
     *  ȫ�ֱ�������
     */

DEV_PARA        Gdp;
DEV_STATUS      Gds;
unsigned long  GulKeyMsg;
INT32U  GulCanMsg;                                                      /*  ��Ϣͨ��                    */
INT32U  GulRxMsg;                                                       /*  ������Ϣ����                */
INT32U  GulTxMsg;                                                       /*  ������Ϣ����                */

    /*
     *  ���ع��������ر�ʶ
     */
//INT32U  *temp1=(( INT32U*)(0x40003ff0));
//INT32U  *temp2=(( INT32U *)(0x40003ff4));
//INT32U  *temp3=(( INT32U *)(0x40003ff8));
//INT32U  *temp4=(( INT32U *)(0x40003ffC));
//INT32U  *temp5=(( INT32U *)(0x40003fe0));
volatile INT32U *chengxubangflag = ((volatile INT32U *)0x40003ff8);/*????????????*/
//volatile INT32U   *fanweiflag = ((volatile INT32U *)0x40003fe0);/*???????????????*/
//volatile INT32U   *fasongjiangetiaozheng = ((volatile INT32U *)0x4000362C);/*????????????????*/
//volatile INT32U   *fasongyanshitiaozheng = ((volatile INT32U *)0x40003630);/*????????????????*/
volatile INT32U *tongdaoflag = ((volatile INT32U *)0x40003ff8);/*?????????*/

#define M32(adr) (*((volatile unsigned long  *) (adr)))

    /*
     *  ȫ�ֱ�������
     */

void sysDataAbortIsr()
{

}
void sysPrefetchIsr()
{

}
void sysUndefinedsr()
{

}


INT32S __tmUartInit ()
{  
    char  ucUartArg[] = "BaudRate=57600 TxBufSize=128";// Fpclk=11059200";
    UART_HOOKS uartHooks;
   
    memset(&uartHooks, 0x00, sizeof(UART_HOOKS));   
    uartHooks.pReceive =  uartReceiveHook;
    if (uartInit(0, ucUartArg, &uartHooks) < 0) {           /* UART��������ʼ��             */
        while(1);
    }
    vicIrqFuncSet(6, 5, (INT32U)UART0_ISR);	
    return 0;
}

    /*
     *  ���ع�������־���� 
     */             
#define     __EN_UPGRADE_FLAG0      0x40003610                          /*  ʹ�ܳ������ع��ܱ�־0       */
#define     __EN_UPGRADE_FLAG1      0x40003614                          /*  ʹ�ܳ������ع��ܱ�־1       */
#define     __EN_UPGRADE_SRC        0x40003624                          /*  ʹ�ܳ�������ܱ�־          */
#define     __EN_UPGRADE_RANGE      0x40003628                          /*  ���䷶Χ��־                */

extern void reset();
extern void switchDLM2_Handler();
void  __UpGradeBegin(void) 
{
    /*
     *  ����������־
     */
    ioOutportLong(0x55AA55AA, __EN_UPGRADE_FLAG0);
    ioOutportLong(0x55AA55AA, __EN_UPGRADE_FLAG1);

    /*
     *  ������ʼ
     */

    sysIrqDisable();
    sysChangeToSysMode();
    //switchDLM2_Handler();
    sysIrqEnable();
}

void CanFrmProcess(INT8U ucId, CANFRAME cfRbr)
{       
    INT32S      siErr; 
  __CAN_MSG     cmRcv;
    /*
     *  ��ת�����ع������2
     */
    
    if ((0x1f060000 == (cfRbr.ulId & 0xffff0000)) &&
        (ucId == CAN_PORT_RIGHT)) {
        
        /*
         *  �л������ع������2
         */
        __UpGradeBegin(); 
        return;
    }
    cmRcv.cf.ucIsRemote = cfRbr.ucIsRemote;
    cmRcv.cf.ucIsExtend = cfRbr.ucIsExtend;
    cmRcv.cf.ucDataLen  = cfRbr.ucDataLen;
    cmRcv.cf.ulId.ulDWord = cfRbr.ulId;
    memcpy(cmRcv.cf.ucBuf, cfRbr.ucBuf, cfRbr.ucDataLen);
//    if(port_err_cnt[can_num] > 0)       //����������ͨѶ�����������ͨѶ״̬�Ĵ���ά��
//   {
//     port_err_cnt[can_num] -= 1;
//     if((port_err_cnt[can_num] > MIN_PORT_ERR) && (port_err_cnt[can_num] < MAX_PORT_ERR))
//     {
//         can_port_sta[can_num] = 1;
//     }
//     else
//     {
//       if(port_err_cnt[can_num] == 0)
//       {
//         can_port_sta[can_num] = 0;
//       }
//     }
//   }

    if (ucId == CAN_PORT_SELF) {
        siErr = sysMsgPost(GulRxMsg, (INT8U *)&cmRcv, 1);// OSQPostFront(RX_MSG,black_ptr);
    } else {
        siErr = sysMsgPost(GulRxMsg, (INT8U *)&cmRcv, 0);//OSQPost(RX_MSG,black_ptr);
    }
    if (siErr < 0) {
        ;
    }

    if (0xFE != cmRcv.cf.ulId.ulBits.ulDst) {           
        if ((CAN_PORT_RIGHT == ucId)) {                                 /*  ��������������  */             
            cmRcv.ucFromTo = CAN_PORT_BUS;                             
            sysMsgPost(GulTxMsg, (INT8U *)&cmRcv, 1);
        } else if (CAN_PORT_BUS == ucId) {                              /*  �����淢��������*/            
            if ((0xFd == cmRcv.cf.ulId.ulBits.ulDst) || (0x00 == cmRcv.cf.ulId.ulBits.ulDst)) {
				cmRcv.ucFromTo = CAN_PORT_RIGHT; 
	            sysMsgPost(GulCanMsg, (INT8U *)&cmRcv, 0);
			}
        }
    }
}

static void CanDrivReceiveHook (void *pRsv,CANFRAME canFrame)
{
    INT8U   ucChn = ((INT8U*)pRsv)[0];  
    //CanFrmProcess(ucChn + 1, canFrame);
    return;
}
volatile INT32U	GuiPacketSendNum[5];



/*********************************************************************************************************
** Function name:           guiPrintf
** Descriptions:            ָ��λ�ô�ӡ��ʽ���ַ���
** input parameters:        uiXPoint        x����
**                          uiYPoint        y����
**                          ucIsAnti        ����
**                          pcString        ��ʽ���ַ���
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void guiPrintf(INT32U uiXPoint, INT32U uiYPoint, INT8U ucIsAnti, char * pcString,...)
{
    char    cStr[160];
    va_list ap;
    if (NULL == pcString) {
        return;
    }
    va_start(ap,pcString);
    vsprintf(cStr+3,pcString,ap);
    va_end(ap); 
    cStr[0] =  uiXPoint;
    cStr[1] =  uiYPoint; 
    cStr[2] =  ucIsAnti;
    pcString =  cStr; 
    tpWrite(2, __TP_PRINTF, strlen(pcString+3)+4, pcString, 0);
}

/*********************************************************************************************************
** Function name:           guiClrScr
** Descriptions:            ����
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void guiClrScr()
{
    INT8U ucChar = 0x01;
    tpWrite(2, __TP_CLR_SCR, 1, &ucChar, 0);
}

/*********************************************************************************************************
** Function name:           guiClrRectangle
** Descriptions:            ���ָ����Χ
** input parameters:        x0              ��ʼx����
**                          y0              ��ʼy����
**                          x1              ����x����
**                          y1              ����y����
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void  guiClrRectangle(uint32 x0, uint32 y0, uint32 x1, uint32 y1)
{
    char    cStr[4];
    cStr[0] =  x0;
    cStr[1] =  y0; 
    cStr[2] =  x1;
    cStr[3] =  y1;
    tpWrite(2, __TP_CLR_RECT, 4, cStr, 0);
}


/*********************************************************************************************************
** Function name:           ledOn
** Descriptions:            ��������
** input parameters:        uiLedOn             ����ָʾ��λ����
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void ledOn(INT32U uiLedOn)
{
    INT8U ucBuf[3];         
    ucBuf[2] =  ~uiLedOn;
    ucBuf[1] = ~(uiLedOn >> 8);
    ucBuf[0] = ~(uiLedOn >> 16);
    tpWrite(2, __TP_LED_ON, 3, ucBuf, 0); 
}

/*********************************************************************************************************
** Function name:           ledOff
** Descriptions:            ��������
** input parameters:        uiLedOff        ����ָʾ��λ����
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void ledOff(INT32U uiLedOff)
{
    INT8U ucBuf[3];         
    ucBuf[2] =  ~uiLedOff;
    ucBuf[1] = ~(uiLedOff >> 8);
    ucBuf[0] = ~(uiLedOff >> 16);
    tpWrite(2, __TP_LED_OFF, 3, ucBuf, 0);
}

/*********************************************************************************************************
** Function name:           ledBlink
** Descriptions:            �����ƺͷ�����(IO)��˸
** input parameters:        usTimes         ��˸����
**                          usOnTicks       ������ʱ��ms
**                          usOffTicks      �����ʱ��ms
**                          usIoNo          IO 0 �� 1 �� 2 ������ 3 ����ָʾ��
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
void ledBlink(INT16U usTimes, INT16U usOnTicks, INT16U usOffTicks, INT16U usIoNo)
{
    INT16U usBuf[4];  
    usBuf[0] = usTimes;
    usBuf[1] = usOnTicks;
    usBuf[2] = usOffTicks;
    usBuf[3] = usIoNo;
    tpWrite(2, __TP_LED_BLINK, 8, usBuf, 0);
}
   
   
/*********************************************************************************************************
** Function name:           TaskIdlekHook
** Descriptions:            
** input parameters:        none
** output parameters:       none
** Returned value:          none                          
*********************************************************************************************************/
void TaskIdleHook(void)
{
    ;
}

/*********************************************************************************************************
** Function name:           main
** Descriptions:            ������
** input parameters:        none
** output parameters:       none
** Returned value:          none                          
** Created by:              
** Created date:            2017-05-30
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
int main (void)
{
    OSInit(); 
    OSTaskCreateExt(TASK0,
                    (void *)0,
                    &TASK0_STACK[TASK0_STACK_SIZE-1],
                    TASK0_PRIO,
                    TASK0_ID,
                    &TASK0_STACK[0],
                    TASK0_STACK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR); 
    OSStart();    
    return 0;                                   
}

/*********************************************************************************************************
** Function name:           TASK0
** Descriptions:            ��������
** input parameters:        none
** output parameters:       none
** Returned value:          none                          
** Created by:              
** Created date:            
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
void TASK0 (void *pdata)
{  
    extern const unsigned char ucLogo[];
    char               *pscCanArg = "BaudRate=33300 Mode=1 AfMode=0";
    SD2405_TIME       __SExRtcTime;  
    CAN_HOOKS           canReceiveHook;    
    UART_HOOKS          uartHooks;
    INT8U               ucFlag, i;
    INT32S              siErr;
    INT16U              usLsr;
    INT32U              uiIrSendTick;
    INT32U              uiDrvSendTick;
    INT8U               ucBuf[8];
    INT32U              uiMsTics;
    INT32U              __SuiTick;
    

    OSTaskIdleHookSet(TaskIdleHook);
    pinInit();                                                          /*  �ܽų�ʼ��                  */    
    targetInit();                                                       /*  ϵͳ��ʼ��,�汾����֤       */
    
    sysDataAbortIsrSet((INT32U)sysDataAbortIsr);
    sysPrefetchIsrSet((INT32U)sysPrefetchIsr);
    sysUndefinedsrSet((INT32U)sysUndefinedsr);

    GulKeyMsg = sysMsgCreate (5, 4);



    
    
    /*
     *  ��ʼ��uart0, uart1
     */
    //memset(&uartHooks, 0x00, sizeof(UART_HOOKS));
    //uartHooks.pReceive = uartReceiveHook;
    //uartInit(UART1, "BaudRate=9600 TxBufSize=512", &uartHooks); 
    //uartInit(UART0, "BaudRate=57600 TxBufSize=512 FifoLen=8", NULL);

    //vicIrqFuncSet(UART1_IRQ_CHN, 8, (INT32U)UART1_ISR);
    //vicIrqFuncSet(UART0_IRQ_CHN, 7, (INT32U)UART0_ISR);
 
    guiClrScr();
    
    /*
     *  ����ͨѶ���ƣ�������Ϣ����
     */ 
    GulCanMsg = sysMsgCreate(20, sizeof(__CANFRAME));
    if (GulCanMsg == 0) {
        while(1);
    }
    
    GulRxMsg = sysMsgCreate(20, sizeof(__CAN_MSG));
    if (GulRxMsg == 0) {
        while (1);
    }
    
    
    
    __tmUartInit(0);

    memset(&canReceiveHook, 0, sizeof(CAN_HOOKS));
    canReceiveHook.pReceive =  CanDrivReceiveHook;
    //for (i = 0; i < 4; i++) {
        canInit(CAN1, "BaudRate=33300 Mode=1", &canReceiveHook);   
        vicDefIrqEnable(20 + CAN1);										 
        vicDefIrqEnable(26 + CAN1);	
        canInit(CAN2, "BaudRate=33300 Mode=1", &canReceiveHook);   
        vicDefIrqEnable(20 + CAN2);										 
        vicDefIrqEnable(26 + CAN2);	
        canInit(CAN4, "BaudRate=33300 Mode=1", &canReceiveHook);   
        vicDefIrqEnable(20 + CAN4);										 
        vicDefIrqEnable(26 + CAN4);	
    //}
    //vicDefIrqEnable(19);
    //vicDefIrqFuncSet((INT32U)CAN_ISR);                                  /* �����жϷ�����      */ 
    
    
    OSTimeDlyHMSM(0, 0, 2, 0);                   
    /*
     *  ȫ�ֱ�����ʼ��
     */


    
    /*
     *  ������ʼ��
     */
//    if (((INT8U *)0x3c000)[0] != 0xbb) {                                /*  ������Ч                    */   
//        extern unsigned char __SucDispBuf[GUI_LCM_YMAX/8][GUI_LCM_XMAX];
//        eepromWrite(0, (INT8U *)__GucParaDefault, 381);
//        
//        __SucDispBuf[0][0] = 0xbb;
//        sysIrqDisable();
//        iapSectorPrepare(16, 16);
//        iapSectorErase(16, 16);
//        iapSectorPrepare(16, 16);
//        iapRamToFlash(0x3c000, (INT32U)__SucDispBuf, 512);
//        siErr = iapDataCompare(0x3C000, (INT32U)__SucDispBuf, 512);
//        if (siErr != CMD_SUCCESS) {
//            ;
//        }
//        sysIrqEnable();	
//    } else {                                                            /*  ������Ч                    */    
//        ;
//    }
    eepromRead(0, (INT8U *)&Gdp, sizeof(DEV_PARA));
    if (Gdp.usMasterTime < 50) {                                        /*  ������С����ʱ��            */
        Gdp.usMasterTime = 100;
    }
    Gds.ucSlaveNo = Gdp.ucShieldNo;


    //GpuiValveTbl = valveTblGet(Gdp.ucShieldNo);
    GpuiKeyTbl = keyTblGet(Gdp.ucShieldNo);
                                                     


       
    OSTaskCreateExt(TASK1,
                    (void *)0,
                    &TASK1_STACK[TASK1_STACK_SIZE - 1],
                    TASK1_PRIO,
                    TASK1_ID,
                    &TASK1_STACK[0],
                    TASK1_STACK_SIZE,
                    (void *)0,
                    OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
    
#if SD2405_TIME_INIT > 0
    sd2405Init(&__SExRtcTime); 
#endif                                                                  /*  SD2405_TIME_INIT            */
    upSysTime(); 


    
while (1) {       
        if (MS_TIMER - uiMsTics >= 1000) {
            Gds.uiTimeStamp++;
            uiMsTics = MS_TIMER;
            if (!__GptnCurMenu) {                                       /*  ������                      */
                INT32U uiHours, uiMinutes, uiSeconds, uiTemp;
                uiTemp      = Gds.uiTimeStamp / 60;
                uiSeconds   = Gds.uiTimeStamp % 60;
                uiHours     = uiTemp / 60;
                uiMinutes   = uiTemp % 60;
                guiPrintf(0, 48, 0, "����ʱ��%02d:%02d:%02d", uiHours, uiMinutes, uiSeconds);
            }
        }
        

        if (Gds.ucIndicatorFlg.Bits.ucKeyPush) {                        /*  ������ʾ��                  */
            if (Gds.ucIndicatorFlg.Bits.ucKeyPush == 1) {               /*  δ��ʾ                      */                                                                                
                ledBlink(1, 1, 1, 2);                                   /*  ����������                  */
                __SuiTick = MS_TIMER;
                Gds.ucIndicatorFlg.Bits.ucKeyPush = 2;
            } else /*if (Gds.ucIndicatorFlg.Bits.ucKeyPush == 2)*/{     /*  ����ʾ                      */
                if (MS_TIMER - __SuiTick >= 100) {
                    ledBlink(0, 500, 500, 2);                           /*  �رշ�����                  */
                    Gds.ucIndicatorFlg.Bits.ucKeyPush = 0;
                } else {
                    ;
                }
            }
        } else if (Gds.ucIndicatorFlg.Bits.ucSafe) {                    /*  ��ͣ/������ʾ��             */
            static INT8U __SucBeepTimes;
            if (Gds.ucIndicatorFlg.Bits.ucSafe == 1) {                  /*  δ��ʾ                      */
                ledBlink(3, 10, 10, 2);
                __SuiTick = MS_TIMER;
                Gds.ucIndicatorFlg.Bits.ucSafe = 2;
            }
        } else if (Gds.ucIndicatorFlg.Bits.ucWarn) {                        /*  ����Ԥ��                    */
            if (MS_TIMER - __SuiTick >= 500) {                              /*  �������                    */

                __SuiTick = MS_TIMER;
            }
        } else {                                                            /*  �����ⱨ��                  */

            if (Gds.ucIsRemoteReady) {
                ;
            } else {
                ;
            }
        }

        OSTimeLag(OS_TICKS_PER_SEC / 50);                               /*  ����ȷ��ʱ20ms            */       
    }
}

/*********************************************************************************************************
** Function name:           TASK1 
** Descriptions:            ���̴�������
** input parameters:        none
** output parameters:       none
** Returned value:          none                          
** Created by:              
** Created date:            
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
void TASK1(void *pdata) 
{  	
    INT32S          siErr;
    INT32U          uiKeyCode;                                          /*  ��ǰ��ֵ                    */
    INT32U          uiKeyLast;                                          /*  ǰһ�μ�ֵ                  */
    INT32U          uiSafeKey;
//    INT32U          uiMasterTick;                                       /*  ���ؼ�ʱ��                  */
    INT8U           ucBuf[8];

    
    INT8U           ucInvalidCnt;                                       /*  ��Ч����������              */
    INT8U           ucIsInvalidKey;                                     /*  �Ƿ�Ϊ��Ч����              */
    INT32U          uiTimeoutTicks;
    pdata = pdata;                                                      /*  ��ֹ���뾯��                */
    uiSafeKey = 0;
    while (1) {
        if (Gds.ucIsRemoteReady) {
            uiTimeoutTicks = 500;
        } else {
            uiTimeoutTicks = 50;
        }
        siErr = sysMsgPend(GulKeyMsg, ucBuf, uiTimeoutTicks);
//        if ((uiKeyCode & JP_STOP) == (uiSafeKey & JP_STOP) &&
//            (uiSafeKey & JP_STOP)) {
//            continue;
//        } 
        

        if (siErr < 0) {                                                /*  �ް���                      */
            uiKeyCode = 0;
            uiKeyLast = uiKeyCode;                                      /*  ����̧��                    */            
            if (Gds.ucStatus == STA_HOST) {                             /*  ����״̬�ް���Ҳ�������ʾ  */                                                                        
//                if (OS_TASK_RESUME_PRIO != OSTaskResume(TASK3_PRIO)) {  /*  ���Զ��Ƽ��������          */
//                    continue;
//                }


            } else if ((Gds.ucStatus == STA_S_SLAVE) ||
                       (Gds.ucStatus == STA_G_SLAVE)) {                 /*  �ӿ�״̬                    */
                ;
            } else if (Gds.ucStatus == STA_IDLE) {                      /*  ����״̬                    */                                   
                if (MS_TIMER - Gds.uiMasterTimeoutTick > Gdp.usMasterTime * 100) { 
                                                                        /*  �ֶ���������ʱ�䵽          */

                    if (__GptnCurMenu) {                                /*  �˵�״̬                    */                            
                        if (miIsExist(&__GmiibKeyLock)) {
                            ;
                        } else {
                            miFlush();                                      /*  �˳��˵�                    */
                            mainDisplay();                                  /*  ��ʾ������                  */
                        }
                    }
                }
//                if (SEC_TIMER - Gds.uiAuthorizedTimeoutTick >= 10) {
//                    Gds.ucIsAuthorized = FALSE;
//                }   
                continue;
            } else {
                continue;
            }
        } else {                                                        /*  ������Ϣ                    */
            //uiKeyCode = ((INT32U *)ucBuf)[0];                           /*  ȡ��ֵ                      */
            uiKeyCode = (ucBuf[0] << 16) | (ucBuf[1] << 8) | ucBuf[2]; 
            if (uiKeyCode == JP_STOP) {                             /*  ��ͣ                        */
                uiKeyCode |= JP_STOP;
                //uiSafeKey &= ~JP_LOCK;
            } else if (ucBuf[0] == 0x33) {                          /*  ����                        */
                ;
            } else if (uiKeyCode == JP_LOCK) {
                uiKeyCode |= JP_LOCK;
            } else if (ucBuf[0] == 0x44) {
                ;
            }
            if ((uiKeyCode & (JP_LOCK | JP_STOP)) == uiSafeKey &&
                uiSafeKey) {
                continue;
            }
            if ((uiKeyCode == JP_STOP) == (uiSafeKey & JP_STOP) &&
                (uiSafeKey & JP_STOP)) {
                continue;
            } 
            if ((uiKeyCode & JP_STOP) && (!(uiSafeKey & JP_STOP))) {        /*  ��ͣ����                    */
                ucBuf[0] = Gdp.ucShieldNo;
                ucBuf[1] = 1;            
                //tpWrite(TP_DEFAULT_CHNL, __TP_STOP, 2, ucBuf, 0);
                uiSafeKey |= JP_STOP;
            }  else if ((!(uiKeyCode & JP_STOP)) && (uiSafeKey & JP_STOP)) { /*  ��̧ͣ��                    */
                ucBuf[0] = Gdp.ucShieldNo;
                ucBuf[1] = 0;
                //tpWrite(TP_DEFAULT_CHNL, __TP_STOP, 2, ucBuf, 0);
                uiSafeKey &= ~JP_STOP;
            } else if ((uiKeyCode & JP_LOCK) && (!(uiSafeKey & JP_LOCK))) { /*  ��������                    */            
                ucBuf[0] = Gdp.ucShieldNo;
                ucBuf[1] = 1;            
                //tpWrite(TP_DEFAULT_CHNL, __TP_LOCK, 2, ucBuf, 0);
                uiSafeKey |= JP_LOCK;
            } else if ((!(uiKeyCode & JP_LOCK)) && (uiSafeKey & JP_LOCK)) { /*  ����̧��                    */
                ucBuf[0] = Gdp.ucShieldNo;
                ucBuf[1] = 0;            
                //tpWrite(TP_DEFAULT_CHNL, __TP_LOCK, 2, ucBuf, 0);
                uiSafeKey &= ~JP_LOCK;
            } else {
                uiSafeKey = uiKeyCode & (JP_STOP | JP_LOCK);
            }
            
//                if (uiKeyCode & (JP_STOP | JP_LOCK)) {                          /*  ��ͣ/����״̬��������Ӧ     */
//                    //uiSafeKey = uiKeyCode & (JP_STOP | JP_LOCK);
//                    continue;    
//                }
         
            Gds.uiMasterTimeoutTick = MS_TIMER;
        }
        if (uiKeyCode == JP_NOP) {
            continue;
        }
        if (uiKeyCode == uiKeyLast) {                                   /*  �ظ�����                    */
            if ((__GptnCurMenu && Gds.ucStatus != STA_IDLE) &&          /*  ����״̬                    */
                (uiKeyCode != GpuiKeyTbl[KEY_MENU_UP]) &&
                (uiKeyCode != GpuiKeyTbl[KEY_MENU_DOWN]) &&
                (uiKeyCode != GpuiKeyTbl[KEY_MENU_LEFT]) &&
                (uiKeyCode != GpuiKeyTbl[KEY_MENU_RIGHT]) &&
                (uiKeyCode != GpuiKeyTbl[KEY_ABORT])) {            
                ;
            } else {
                continue;
            }
        } else {
            ledBlink(1, 1, 1, 3);
            Gds.ucIndicatorFlg.Bits.ucKeyPush = 1;                      /*  ������������                */
        }
        
                                		   
        if (keyNum(uiKeyCode) >= 2) {                                   /*  �������ͬʱ����            */
            //uiKeyCode = uiKeyLast & uiKeyCode;
        }
        uiKeyLast = uiKeyCode;
        
        if (__GptnCurMenu) {                                            /*  �˵�/��������               */

                miOnKey(uiKeyCode);
            
        } else {                                                        /*  �ڿ���״̬��һ�ΰ��°���    */
            ucIsInvalidKey = FALSE;
            if (uiKeyCode & GpuiKeyTbl[KEY_ABORT]) {                        /*  ֹͣ��                      */                             
                if ((Gds.ucStatus != STA_IDLE) || (__GptnCurMenu == NULL)) {/*  ������                      */   
                    if (Gdp.ucShieldNo >= Gdp.usStopRange) {
                        ucBuf[0] = Gdp.ucShieldNo - Gdp.usStopRange;
                    } else {
                        ucBuf[0] = 0;
                    }
                    if (ucBuf[0] < Gdp.usGblFaceMin) {
                        ucBuf[0] = Gdp.usGblFaceMin;
                    }
                    ucBuf[1] = Gdp.ucShieldNo + Gdp.usStopRange;
                    if (ucBuf[1] > Gdp.usGblFaceMax) {
                        ucBuf[1] = Gdp.usGblFaceMax;
                    }
                    //tpWrite(TP_DEFAULT_CHNL, __TP_ABORT, 2, ucBuf, 0);   
                } 
            } else if ((uiKeyCode & GpuiKeyTbl[KEY_ENTER])) {           /*  ���ϲ˵���ݼ�              */                    
                ;
            } else if (uiKeyCode & GpuiKeyTbl[KEY_WORK_STAT]) {         /*  �����˵���ݼ�              */                    
                ;                   			                      			
            } else if ((uiKeyCode & GpuiKeyTbl[KEY_MENU_LEFT]) || 
                       (uiKeyCode & GpuiKeyTbl[KEY_MENU_RIGHT]) || 
                       (uiKeyCode & GpuiKeyTbl[KEY_MENU_UP]) || 
                       (uiKeyCode & GpuiKeyTbl[KEY_MENU_DOWN])) {       /*  �˵�����                    */
                //miRootInit();

                miBasicCfgInit();
//                miGlobalCfgInit();
//                miAsqCfgInit();
//                miSysInfoInit();
                mpHome();                
            } else if (uiKeyCode & (GpuiKeyTbl[KEY_LEFT] | GpuiKeyTbl[KEY_RIGHT])) {
                                                                        /*  ��/���ڼܵ���               */
                Gds.ucSlaveDir = (uiKeyCode == GpuiKeyTbl[KEY_RIGHT]) ? 1 : 0;
                Gds.ucStatus = STA_HOST;                
                //miNbrInit();                                            /*  �ڼܿ���                    */
                //mpHome();
                
            } else if (uiKeyCode & GpuiKeyTbl[KEY_SELF]) {              /*  �����Կ�                    */
                //miSelfInit();
                //mpHome();                
            } else {                                                    /*  ��Ч����                    */
                ucIsInvalidKey = TRUE;
            }
            if (ucIsInvalidKey) {
                ucInvalidCnt++; 
                if (ucInvalidCnt >= 5) {                                 /*  ����5����Ч����             */
                    ucInvalidCnt = 0;
                    miKeyLockInit();
                    mpHome();
                }
            } else {
                ucInvalidCnt = 0;
            }            								
        }                               
    }
} 

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

