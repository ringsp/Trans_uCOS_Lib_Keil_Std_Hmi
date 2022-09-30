/****************************************Copyright (c)****************************************************
**                              
**
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           target.c
** Last modified Date:  2012-12-31
** Last Version:        1.0
** Descriptions:        lpc22xx�������ֵ�ARM��Ŀ�������Ĵ��룬�����쳣��������Ŀ����ʼ������
**                      ÿ������Ӧ����������ļ��Ŀ������û����ݳ������Ҫ�޸ı��ļ���
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2012-12-31
** Version:             V1.0
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/
#define IN_TARGET
#include    "..\..\USER_CODE\main.h"

#define     __SD2405    0x64

/*
 *  ����ת��
 */
#define    BCD_TO_HEC(b)    ((((b) >> 4) * 10) + ((b) & 0x0f))
#define    HEC_TO_BCD(h)    ((((h) / 10) << 4) | ((h) % 10))

/*********************************************************************************************************
** Function name:           upSysTime
** Descriptions:            Update the system time 
** input parameters:        None
** output parameters:       None
** Returned value:          None
** Created by:              LinEnqiang
** Created Date:            2011-01-18
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
void upSysTime (void)
{    
    INT8U ucTimeBuff[7];
    INT8U ucAddr;
    INT8U ucAck;
    INT8S scArg[64] = {0};
    /*
     *  ��ʱ��
     */
    ucAddr = 0;
    memset(ucTimeBuff,0,sizeof(ucTimeBuff));
    i2cRead(I2C0, __SD2405, &ucAddr, 0, ucTimeBuff, 7,NULL);            /* ������                        */
    do {
        OSTimeDly(1);
        ucAck = i2cGetFlag(I2C0);
        if (((I2C_NOT_GET_BUS | I2C_ACK_ERR) & ucAck) != 0) {
            break;
        }
    } while((I2C_READ_END & ucAck) == 0);
    ucTimeBuff[0] = (INT8U)BCD_TO_HEC((ucTimeBuff[0]&0x7f));                  /* ��                           */
    ucTimeBuff[1] = (INT8U)BCD_TO_HEC((ucTimeBuff[1]&0x7f));                  /* ��                           */
    ucTimeBuff[2] = (INT8U)BCD_TO_HEC((ucTimeBuff[2]&0x3f));                  /* Сʱ                         */
    ucTimeBuff[3] = (INT8U)BCD_TO_HEC((ucTimeBuff[3]&0x07));                  /* ����                         */
    ucTimeBuff[4] = (INT8U)BCD_TO_HEC((ucTimeBuff[4]&0x3f));                  /* ��                           */
    ucTimeBuff[5] = (INT8U)BCD_TO_HEC((ucTimeBuff[5]&0x1f));                  /* ��                           */
    ucTimeBuff[6] = (INT8U)(BCD_TO_HEC(ucTimeBuff[6]));                 /* ��Ϊ20XX                     */
    
     snprintf(scArg, 64, "Year=%4d Month=%d Day=%d Week=%d Hour=%d Min=%d Sec=%d", ucTimeBuff[6] +2000, ucTimeBuff[5], ucTimeBuff[4], ucTimeBuff[3], ucTimeBuff[2], ucTimeBuff[1], ucTimeBuff[0]);
     rtcInit(RTC0, scArg, NULL);
    
}

/*********************************************************************************************************
** Function name:           sd2405Init
** Descriptions:            Initialize the system time
** input parameters:        The system time
** output parameters:       None
** Returned value:          None
** Created by:              LinEnqiang
** Created Date:            2011-01-18
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
void sd2405Init (SD2405_TIME *pTime)
{
    INT8U ucTimeBuff[7];
    INT8U ucAddr;
    INT8U ucAck;
    
    /*
     *  ����д����
     */
    ucAddr = 0x10;
    ucTimeBuff[0] = 0x80;    
    i2cWrite(I2C0, __SD2405, &ucAddr, 1, ucTimeBuff, 1,NULL); 
    do {
        OSTimeDly(1);
        ucAck = i2cGetFlag(I2C0);
        if (((I2C_NOT_GET_BUS | I2C_ACK_ERR) & ucAck) != 0) {
            break;
        }
    } while((I2C_WRITE_END & ucAck) == 0);  
  
    ucAddr = 0x0F;
    ucTimeBuff[0] = 0x84;    
    i2cWrite(I2C0, __SD2405, &ucAddr, 1, ucTimeBuff, 1,NULL); 
    do {
        OSTimeDly(1);
        ucAck = i2cGetFlag(I2C0);
        if (((I2C_NOT_GET_BUS | I2C_ACK_ERR) & ucAck) != 0) {
            break;
        }
    } while((I2C_WRITE_END & ucAck) == 0);
    
    /*
     *  ת��ΪBCD��
     */
    ucTimeBuff[0] = (INT8U)HEC_TO_BCD(pTime->ucSecond);                 /* ת����                       */
    ucTimeBuff[1] = (INT8U)HEC_TO_BCD(pTime->ucMinute);                 /* ת����                       */
    ucTimeBuff[2] = (INT8U)HEC_TO_BCD(pTime->ucHour);                   /* ת��Сʱ                     */
    ucTimeBuff[2] =  ucTimeBuff[2] | 0x80;                              /* 24Сʱ��                     */
    
    ucTimeBuff[3] = (INT8U)HEC_TO_BCD(pTime->ucWeek);                   /* ת������                     */
    ucTimeBuff[4] = (INT8U)HEC_TO_BCD(pTime->ucDay);                    /* ת����                       */
    ucTimeBuff[5] = (INT8U)HEC_TO_BCD(pTime->ucMonth);                  /* ת����                       */
    ucTimeBuff[6] = (INT8U)HEC_TO_BCD(pTime->usYear - 2000);            /* ת����                       */

    ucAddr = 0x00;  
    i2cWrite(I2C0, __SD2405, &ucAddr, 1, ucTimeBuff, 7,NULL); 
    do {
        OSTimeDly(1);
        ucAck = i2cGetFlag(I2C0);
        if (((I2C_NOT_GET_BUS | I2C_ACK_ERR) & ucAck) != 0) {
            break;
        }
    } while((I2C_WRITE_END & ucAck) == 0);
    
    /*
     *  ��ֹд����
     */
    ucAddr = 0x0F;
    ucTimeBuff[0] = 0x00; 
    ucTimeBuff[1] = 0x00;    
    i2cWrite(I2C0, __SD2405, &ucAddr, 1, ucTimeBuff, 2,NULL); 
    do {
        OSTimeDly(1);
        ucAck = i2cGetFlag(I2C0);
        if (((I2C_NOT_GET_BUS | I2C_ACK_ERR) & ucAck) != 0) {
            break;
        }
    } while((I2C_WRITE_END & ucAck) == 0);
    upSysTime();
    return;
}

/*********************************************************************************************************
** Function name:           sd2405Read
** Descriptions:            read the system time
** input parameters:        The system time point
** output parameters:       The system time
** Returned value:          �ɹ��� OPERATE_SUCCESS
**                          ʧ�ܣ� -OPERATE_FAIL
** Created by:              LinEnqiang
** Created Date:            2011-01-18
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
INT32S sd2405Read (SD2405_TIME *pTime)
{
    INT8U ucTimeBuff[7];
    INT8U ucAddr;
    INT8U ucAck;
    /*
     *  ��ʱ��
     */
    ucAddr = 0;
    memset(ucTimeBuff,0,sizeof(ucTimeBuff));
    i2cRead(I2C0, __SD2405, &ucAddr, 0, ucTimeBuff, 7,NULL);           /* ������                       */
    do {
        OSTimeDly(1);
        ucAck = i2cGetFlag(I2C0);
        if (((I2C_NOT_GET_BUS | I2C_ACK_ERR) & ucAck) != 0) {
            break;
        }
    } while((I2C_READ_END & ucAck) == 0);
    if (I2C_READ_END != ucAck) {
        return -OPERATE_FAIL;
    }
    pTime->ucSecond = (INT8U)BCD_TO_HEC((ucTimeBuff[0]&0x7f));          /* ��                           */
    pTime->ucMinute = (INT8U)BCD_TO_HEC((ucTimeBuff[1]&0x7f));          /* ��                           */
    pTime->ucHour   = (INT8U)BCD_TO_HEC((ucTimeBuff[2]&0x3f));          /* Сʱ                         */
    pTime->ucWeek   = (INT8U)BCD_TO_HEC((ucTimeBuff[3]&0x07));          /* ����                         */
    pTime->ucDay    = (INT8U)BCD_TO_HEC((ucTimeBuff[4]&0x3f));          /* ��                           */
    pTime->ucMonth  = (INT8U)BCD_TO_HEC((ucTimeBuff[5]&0x1f));          /* ��                           */
    pTime->usYear   = (INT32U)(BCD_TO_HEC(ucTimeBuff[6])+2000);         /* ��Ϊ20XX                     */
    return OPERATE_SUCCESS;
}

/*********************************************************************************************************
** ��������: Timer0_Exception
** ��������: ��ʱ��0�жϷ������
** �䡡��: ��
**
** �䡡��: ��
**         
** ȫ�ֱ���: ��
** ����ģ��: OSTimeTick
**
** ������: ������
** �ա���: 2004��2��2��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

 static void __osTimerIsr (void)
{
    T0IR = 0x01;
    VICVectAddr = 0;                                                    /*  ֪ͨ�жϿ������жϽ���      */
    OSTimeTick();
  
}
/*********************************************************************************************************
** ��������: Timer0Init
** ��������: ��ʱ��0��ʼ��
** �䡡��: ��
**
** �䡡��: ��
**         
** ȫ�ֱ���: ��
** ����ģ��: ��
**
** ������: ������
** �ա���: 2002��4��4��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void __osTimerInit(void)
{
    T0IR  = 0xffffffff;
    T0TCR = 0x03;
    T0TC  = 0;
    T0MCR = 0x03;
    T0MR0 = (FPCLK / OS_TICKS_PER_SEC);
    T0TCR = 0x01;
    vicIrqFuncSet(TIMER0_IRQ_CHN, 0, (INT32U)__osTimerIsr);
 }

/*********************************************************************************************************
** ��������: TargetInit
** ��������: Ŀ����ʼ�����룬����Ҫ�ĵط����ã�������Ҫ�ı�
** �䡡��: ��
**
** �䡡��: ��
**         
** ȫ�ֱ���: ��
** ����ģ��: ��
**
** ������: ������
** �ա���: 2004��2��2��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void targetInit(void)
{
    /*
     *  ϵͳ������ʼ��
     */    
    if (SYS_OK != sysIfInit()) {
        while (1) {
            ;
        }
    }
    
    sysInit(FOSC, FCCLK, FCCO, FPCLK, OS_TICKS_PER_SEC);                                                 
    __osTimerInit();                                                    /*  ϵͳʱ�ӳ�ʼ��              */
    
    //srand((uint32) targetInit);

    //i2cInit(I2C0, "Speed=400000", NULL);                             /*  I2C��ʼ��                   */
    //vicIrqFuncSet(I2C0_IRQ_CHN, 6, (INT32U)I2C0_ISR);
      
    //eintInit(EINT2, SET_INTMODE, "Mode=0");                          /*  �½��ش����ж�              */        
    //vicIrqFuncSet(EINT2_IRQ_CHN, 5, (INT32U)EINT2_ISR);
    
    //gpioSet(P0_10);                                                     /*  ���̽��빤��                */
    //gpioSet(P1_25);                                                     /*  �������ִ�������Դ          */     
    //gpioSet(P2_21);                                                     /*  ������ŷ�&ģ�⴫������Դ   */
    //adcInit(ADC0, "Mode=1 Channel=0x3F Preci=10 Speed=100000", NULL);
    //vicIrqFuncSet(ADC0_IRQ_CHN,13,(INT32U)ADC0_ISR);
    //adcStart(ADC0);
    /*
     *  �豸��ʼ��
     */ 
    tpInit();
    tpUsrInit();
    

}


/*********************************************************************************************************
  ����ΪһЩ��ϵͳ��صĿ⺯����ʵ��
  ����������ads�Ĳο���������⺯���ֲ�
  �û����Ը����Լ���Ҫ���޸�
*********************************************************************************************************/
/*********************************************************************************************************
  The implementations for some library functions
  For more details, please refer to the ADS compiler handbook and The library
  function manual
  User could change it as needed
*********************************************************************************************************/
#pragma import(__use_no_semihosting_swi)
#pragma import(__use_two_region_memory)

void _ttywrch (int ch)
{
    ch = ch;
}

/*********************************************************************************************************
  End File
*********************************************************************************************************/
