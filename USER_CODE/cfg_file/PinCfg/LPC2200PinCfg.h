/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               PinCfg.h
** Latest modified Date:    2010-12-13
** Latest Version:          1.0
** Descriptions:            I/O���������ļ� 
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2010-12-13
** Version:                 1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/
#ifndef _LPC2220PINCFG_H_
#define _LPC2220PINCFG_H_

/*********************************************************************************************************
**                                           -------- ���Ź��ܲ�ѯ�� -------                            **          
*********************************************************************************************************/

/****************************** -------- P0 ------- *****************************************************/

#define    P0_00_FUNC        P0_00_SEL              
#define    P0_01_FUNC        P0_01_SEL  
#define    P0_02_FUNC        P0_02_SEL              
#define    P0_03_FUNC        P0_03_SEL  
            
#define    P0_04_FUNC        P0_04_SEL
#define    P0_05_FUNC        P0_05_SEL
#define    P0_06_FUNC        P0_06_SEL
#define    P0_07_FUNC        P0_07_SEL             
#define    P0_08_FUNC        P0_08_SEL
#define    P0_09_FUNC        P0_09_SEL
#define    P0_10_FUNC        P0_10_SEL
#define    P0_11_FUNC        P0_11_SEL
#define    P0_12_FUNC        P0_12_SEL
#define    P0_13_FUNC        P0_13_SEL
#define    P0_14_FUNC        P0_14_SEL
#define    P0_15_FUNC        P0_15_SEL
#define    P0_16_FUNC        P0_16_SEL
#define    P0_17_FUNC        P0_17_SEL
#define    P0_18_FUNC        P0_18_SEL
#define    P0_19_FUNC        P0_19_SEL
#define    P0_20_FUNC        P0_20_SEL
#define    P0_21_FUNC        P0_21_SEL              
#define    P0_22_FUNC        P0_22_SEL
#define    P0_23_FUNC        P0_23_SEL
#define    P0_24_FUNC        P0_24_SEL
#define    P0_25_FUNC        P0_25_SEL
#define    P0_26_FUNC        0
#define    P0_27_FUNC        P0_27_SEL
#define    P0_28_FUNC        P0_28_SEL
#define    P0_29_FUNC        P0_29_SEL
#define    P0_30_FUNC        P0_30_SEL
#define    P0_31_FUNC        0

/****************************** -------- P2 ------- *****************************************************/

#define    P2_16_FUNC        P2_16_SEL
#define    P2_17_FUNC        P2_17_SEL
#define    P2_18_FUNC        P2_18_SEL
#define    P2_19_FUNC        P2_19_SEL
#define    P2_20_FUNC        P2_20_SEL
#define    P2_21_FUNC        P2_21_SEL
#define    P2_22_FUNC        P2_22_SEL
#define    P2_23_FUNC        P2_23_SEL
#define    P2_24_FUNC        P2_24_SEL
#define    P2_25_FUNC        P2_25_SEL
#define    P2_26_FUNC        P2_26_SEL
#define    P2_27_FUNC        P2_27_SEL
#define    P2_28_FUNC        P2_28_SEL
#define    P2_29_FUNC        P2_29_SEL
#define    P2_30_FUNC        P2_30_SEL
#define    P2_31_FUNC        P2_31_SEL

/****************************** -------- P3 ------- *****************************************************/
#define     P3_00_FUNC          P3_00_SEL
    /*
     *  by xuwl
     */
#define     P3_23_FUNC          P3_23_SEL 
#define     P3_24_FUNC          P3_24_SEL             
#define     P3_25_FUNC          P3_25_SEL
#define     P3_26_FUNC          P3_26_SEL             
#define     P3_27_FUNC          P3_27_SEL

#define     P3_28_FUNC        P3_28_SEL
#define     P3_29_FUNC        P3_29_SEL

/*********************************************************************************************************
**                                           -------- ���Ź��������� -------                            **          
*********************************************************************************************************/


/****************************** -------- P0 ------- *****************************************************/
//P0.00
#define    P0_00_GPIO        0x00                                       /* GPIO                         */
#define    P0_00_TxD0        0x01                                       /* UART0���������              */
#define    P0_00_PWM1        0x02                                       /* ������������1              */    
//...      Reserved          0x03                                       /* ����                         */
#define    P0_00_SEL        P0_00_TxD0                                  

//P0.01
#define    P0_01_GPIO        0x00                                       /* GPIO                         */
#define    P0_01_RxD0        0x01                                       /* UART0���������              */
#define    P0_01_PWM3        0x02                                       /* ������������3              */
#define    P0_01_EINT0       0x03                                       /* �ⲿ�ж�0����                */
#define    P0_01_SEL        P0_01_RxD0                                  

//P0.02
#define    P0_02_GPIO        0x00                                       /* GPIO                         */
#define    P0_02_SCL         0x01                                       /* I2Cʱ������/���             */
#define    P0_02_CAP00       0x02                                       /* ��ʱ��0��������ͨ��0         */
//...      Reserved          0x03
#define    P0_02_SEL        P0_02_SCL

//P0.03
#define    P0_03_GPIO        0x00                                       /* GPIO                         */
#define    P0_03_SDA         0x01                                       /* I2C��������/���             */
#define    P0_03_MAT00       0x02                                       /* ��ʱ��0ƥ������ͨ��0         */
#define    P0_03_EINT1       0x03                                       /* �ⲿ�ж�1����                */
#define    P0_03_SEL        P0_03_SDA

//P0.04
#define    P0_04_GPIO        0x00                                       /* GPIO                         */
#define    P0_04_SCK0        0x01                                       /* SPI0�Ĵ���ʱ��               */
#define    P0_04_CAP01       0x02                                       /* ��ʱ��0�Ĳ���ͨ��1           */
//...      Reserved          0x03
#define    P0_04_SEL        P0_04_GPIO

//P0.05
#define    P0_05_GPIO        0x00                                       /* GPIO                         */
#define    P0_05_MISO0       0x01                                       /* SPI0��������ӻ������       */
#define    P0_05_MAT01       0x02                                       /* ��ʱ��0��ƥ������ͨ��1       */
//...      Reserved          0x03
#define    P0_05_SEL        P0_05_GPIO

//P0.06
#define    P0_06_GPIO        0x00                                       /* GPIO                         */
#define    P0_06_MOSI0       0x01                                       /* SPI0��������ӻ������       */
#define    P0_06_CAP02       0x02                                       /* ��ʱ��0�Ĳ�������ͨ��2       */
//...      Reserved          0x03
#define    P0_06_SEL        P0_06_GPIO

//P0.07
#define    P0_07_GPIO        0x00                                       /* GPIO                         */
#define    P0_07_SSEL0       0x01                                       /* SPI0�ӻ�ѡ��                 */
#define    P0_07_PWM2        0x02                                       /* ������������2              */
#define    P0_07_EINT2       0x03                                       /* �ⲿ�ж�2����                */
#define    P0_07_SEL        P0_07_GPIO                                 

//P0.08
#define    P0_08_GPIO        0x00                                       /* GPIO                         */
#define    P0_08_TXD1        0x01                                       /* UART1���������              */
#define    P0_08_PWM4        0x02                                       /* ������������4              */
//...      Reserved          0x03
#define    P0_08_SEL        P0_08_TXD1
    
//P0.09
#define    P0_09_GPIO        0x00                                       /* GPIO                         */
#define    P0_09_RXD1        0x01                                       /* UART1���������              */  
#define    P0_09_PWM6        0x02                                       /* ������������6              */
#define    P0_09_EINT3       0x03                                       /* �ⲿ�ж�3����                */
#define    P0_09_SEL        P0_09_RXD1

//P0.10
#define    P0_10_GPIO        0x00                                       /* GPIO                         */
#define    P0_10_RTS1        0x01                                       /* UART1�����������          */
#define    P0_10_CAP10       0x02                                       /* ��ʱ��1�Ĳ�������ͨ��0       */
//...      Reserved          0x03
#define    P0_10_SEL        P0_10_GPIO

//P0.11
#define    P0_11_GPIO        0x00                                       /* GPIO                         */
#define    P0_11_CTS1        0x01                                       /* UART1������������          */
#define    P0_11_CAP11       0x02                                       /* ��ʱ��1�Ĳ�������ͨ��1       */
//...      Reserved          0x03
#define    P0_11_SEL        P0_11_GPIO

//P0.12
#define    P0_12_GPIO        0x00                                       /* GPIO                         */
#define    P0_12_DSR1        0x01                                       /* UART1�����豸������          */
#define    P0_12_MAT10       0x02                                       /* ��ʱ��1��ƥ������ͨ��0       */
#define    P0_12_RD4         0x03                                       /* CAN4����������               */
#define    P0_12_SEL        P0_12_RD4

//P0.13
#define    P0_13_GPIO        0x00                                       /* GPIO                         */
#define    P0_13_DTR1        0x01                                       /* UART1�����ն˾�����          */
#define    P0_13_MAT11       0x02                                       /* ��ʱ��1��ƥ������ͨ��1       */
#define    P0_13_TD4         0x03                                       /* CAN4���������               */  
#define    P0_13_SEL        P0_13_TD4

//P0.14
#define    P0_14_GPIO        0x00                                       /* GPIO                         */
#define    P0_14_DCD1        0x01                                       /* UART1�����ز���������      */
#define    P0_14_EINT1       0x02                                       /* �ⲿ�ж�1����                */
//...      Reserved          0x03
#define    P0_14_SEL        P0_14_GPIO

//P0.15
#define    P0_15_GPIO        0x00                                       /* GPIO                         */
#define    P0_15_RI1         0x01                                       /* UART1����ָʾ�����          */
#define    P0_15_EINT2       0x02                                       /* �ⲿ�ж�2����                */
//...      Reserved          0x03
#define    P0_15_SEL        P0_15_GPIO

//P0.16
#define    P0_16_GPIO        0x00                                       /* GPIO                         */
#define    P0_16_EINT0       0x01                                       /* �ⲿ�ж�0����                */
#define    P0_16_MAT02       0x02                                       /* ��ʱ��0��ƥ�����ͨ��2       */
#define    P0_16_CAP02       0x03                                       /* ��ʱ��0�Ĳ�������ͨ��2       */
#define    P0_16_SEL        P0_16_GPIO

//P0.17
#define    P0_17_GPIO        0x00                                       /* GPIO                         */
#define    P0_17_CAP12       0x01                                       /* ��ʱ��1�Ĳ�������ͨ��2       */
#define    P0_17_SCK1        0x02                                       /* SPI1����ʱ��                 */
#define    P0_17_MAT12       0x03                                       /* ��ʱ��1��ƥ�����ͨ��2       */
#define    P0_17_SEL        P0_17_SCK1

//P0.18
#define    P0_18_GPIO        0x00                                       /* GPIO                         */
#define    P0_18_CAP13       0x01                                       /* ��ʱ��1�Ĳ�������ͨ��3       */
#define    P0_18_MISO1       0x02                                       /* SPI��������ӻ������        */
#define    P0_18_MAT13       0x03                                       /* ��ʱ��1��ƥ�����ͨ��3       */
#define    P0_18_SEL        P0_18_MISO1

//P0.19
#define    P0_19_GPIO        0x00                                       /* GPIO                         */
#define    P0_19_MAT12       0x01                                       /* ��ʱ��1��ƥ�����ͨ��2       */
#define    P0_19_MOSI1       0x02                                       /* SPI1��������ӻ������       */
#define    P0_19_CAP12       0x03                                       /* ��ʱ��1�Ĳ�������ͨ��2       */
#define    P0_19_SEL        P0_19_MOSI1

//P0.20
#define    P0_20_GPIO        0x00                                       /* GPIO                         */
#define    P0_20_MAT13       0x01                                       /* ��ʱ��1��ƥ�����ͨ��3       */
#define    P0_20_SSEL1       0x02                                       /* SPI1�ӻ�ѡ��                 */
#define    P0_20_EINT3       0x03                                       /* �ⲿ�ж�3����                */
#define    P0_20_SEL        P0_20_EINT3

//P0.21
#define    P0_21_GPIO        0x00                                       /* GPIO                         */
#define    P0_21_PWM5        0x01                                       /* ������������5              */
#define    P0_21_RD3         0x02
#define    P0_21_CAP13       0x03                                       /* ��ʱ��1�Ĳ�������ͨ��3       */
#define    P0_21_SEL        P0_21_RD3                                   

//P0.22
#define    P0_22_GPIO        0x00                                       /* GPIO                         */
#define    P0_22_TD3         0x01
#define    P0_22_CAP00       0x02                                       /* ��ʱ��0��������ͨ��0         */
#define    P0_22_MAT00       0x03                                       /* ��ʱ��0ƥ�����ͨ��0         */
#define    P0_22_SEL        P0_22_TD3

//P0.23
#define    P0_23_GPIO        0x00                                       /* GPIO                         */
#define    P0_23_RD2         0x01                                       /* CAN2����������               */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P0_23_SEL        P0_23_RD2

//P0.24
#define    P0_24_GPIO        0x00                                       /* GPIO                         */
#define    P0_24_TD2         0x01                                       /* CAN2���������               */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P0_24_SEL        P0_24_TD2

//P0.25
#define    P0_25_GPIO        0x00                                       /* GPIO                         */
#define    P0_25_RD1         0x01                                       /* CAN1����������               */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P0_25_SEL        P0_25_RD1

//P0.26
//...      Reserved          0x00
//...      Reserved          0x01
//...      Reserved          0x02
//...      Reserved          0x03
#define    P0_26_SEL        0

//P0.27
#define    P0_27_GPIO        0x00                                       /* GPIO                         */
#define    P0_27_AIN0        0x01                                       /* A/Dת��������0               */
#define    P0_27_CAP01       0x02                                       /* ��ʱ��0�Ĳ�������ͨ��1       */
#define    P0_27_MAT01       0x03                                       /* ��ʱ��0��ƥ�����ͨ��1       */  
#define    P0_27_SEL        P0_27_AIN0

//P0.28
#define    P0_28_GPIO        0x00                                       /* GPIO                         */
#define    P0_28_AIN1        0x01                                       /* A/Dת��������1               */
#define    P0_28_CAP02       0x02                                       /* ��ʱ��0�Ĳ�������ͨ��2       */
#define    P0_28_MAT02       0x03                                       /* ��ʱ��0��ƥ�����ͨ��2       */  
#define    P0_28_SEL        P0_28_AIN1

//P0.29
#define    P0_29_GPIO        0x00                                       /* GPIO                         */
#define    P0_29_AIN2        0x01                                       /* A/Dת��������2               */
#define    P0_29_CAP03       0x02                                       /* ��ʱ��0�Ĳ�������ͨ��3       */
#define    P0_29_MAT03       0x03                                       /* ��ʱ��0��ƥ�����ͨ��3       */
#define    P0_29_SEL        P0_29_AIN2

//P0.30
#define    P0_30_GPIO        0x00                                       /* GPIO                         */
#define    P0_30_AIN3        0x01                                       /* A/Dת��������3               */
#define    P0_30_EINT3       0x02                                       /* �ⲿ�ж�3����                */
#define    P0_30_CAP00       0x03                                       /* ��ʱ��0�Ĳ�������ͨ��0       */
#define    P0_30_SEL        P0_30_AIN3

//P0.31����
//...      Reserved          0x00
//...      Reserved          0x01
//...      Reserved          0x02                 
//...      Reserved          0x03
#define    P0_31_SEL        0

/****************************** -------- P2 ------- *****************************************************/

//P2.16
#define    P2_16_GPIO        0x00                                       /* GPIO                         */
#define    P2_16_D16         0x01                                       /* �ⲿ�洢��������16           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_16_SEL        P2_16_GPIO

//P2.17
#define    P2_17_GPIO        0x00                                       /* GPIO                         */
#define    P2_17_D17         0x01                                       /* �ⲿ�洢��������17           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_17_SEL        P2_17_GPIO

//P2.18
#define    P2_18_GPIO        0x00                                       /* GPIO                         */
#define    P2_18_D18         0x01                                       /* �ⲿ�洢��������18           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_18_SEL        P2_18_GPIO

//P2.19
#define    P2_19_GPIO        0x00                                       /* GPIO                         */
#define    P2_19_D19         0x01                                       /* �ⲿ�洢��������19           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_19_SEL        P2_19_GPIO

//P2.20
#define    P2_20_GPIO        0x00                                       /* GPIO                         */
#define    P2_20_D20         0x01                                       /* �ⲿ�洢��������20           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_20_SEL        P2_20_GPIO

//P2.21
#define    P2_21_GPIO        0x00                                       /* GPIO                         */
#define    P2_21_D21         0x01                                       /* �ⲿ�洢��������21           */
//...      Reserved          0x02                                       /* ����
//...      Reserved          0x03
#define    P2_21_SEL        P2_21_GPIO

//P2.22
#define    P2_22_GPIO        0x00                                       /* GPIO                         */
#define    P2_22_D22         0x01                                       /* �ⲿ�洢��������22           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_22_SEL        P2_22_GPIO

//P2.23
#define    P2_23_GPIO        0x00                                       /* GPIO                         */
#define    P2_23_D23         0x01                                       /* �ⲿ�洢��������23           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_23_SEL        P2_23_GPIO

//P2.24
#define    P2_24_GPIO        0x00                                       /* GPIO                         */
#define    P2_24_D24         0x01                                       /* �ⲿ�洢��������24           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_24_SEL        P2_24_GPIO

//P2.25
#define    P2_25_GPIO        0x00                                       /* GPIO                         */
#define    P2_25_D25         0x01                                       /* �ⲿ�洢��������25           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_25_SEL        P2_25_GPIO

//P2.26
#define    P2_26_GPIO        0x00                                       /* GPIO                         */
#define    P2_26_D26         0x01                                       /* �ⲿ�洢��������26           */
#define    P2_26_BOOT0       0x02                                       /* BOOT0                        */
//...      Reserved          0x03
#define    P2_26_SEL        P2_26_BOOT0

//P2.27
#define    P2_27_GPIO        0x00                                       /* GPIO                         */
#define    P2_27_D27         0x01                                       /* �ⲿ�洢��������27           */
#define    P2_27_BOOT1       0x02                                       /* BOOT1                        */
//...      Reserved          0x03
#define    P2_27_SEL        P2_27_BOOT1

//P2.28
#define    P2_28_GPIO        0x00                                       /* GPIO                         */
#define    P2_28_D28         0x01                                       /* �ⲿ�洢��������28           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_28_SEL        P2_28_GPIO


//P2.29
#define    P2_29_GPIO        0x00                                       /* GPIO                         */
#define    P2_29_D29         0x01                                       /* �ⲿ�洢��������29           */
//...      Reserved          0x02                                       /* ����                         */
//...      Reserved          0x03
#define    P2_29_SEL        P2_29_GPIO

//P2.30
#define    P2_30_GPIO        0x00                                       /* GPIO                         */
#define    P2_30_D30         0x01                                       /* �ⲿ�洢��������30           */
#define    P2_30_AIN4        0x02                                       /* A/Dת��������4               */
//...      Reserved          0x03
#define    P2_30_SEL        P2_30_GPIO

//P2.31
#define    P2_31_GPIO        0x00                                       /* GPIO                         */
#define    P2_31_D31         0x01                                       /* �ⲿ�洢��������31           */
#define    P2_31_AIN5        0x02                                       /* A/Dת��������5               */
//...      Reserved          0x03
#define    P2_31_SEL        P2_31_GPIO

/****************************** -------- P3 ------- *****************************************************/
//P3.00
#define    P3_00_GPIO        0x00                                       /* GPIO                         */
#define    P3_00_A0          0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P3_00_SEL        P3_00_A0


//P3.23
#define    P3_23_GPIO        0x00                                       /* GPIO                         */
#define    P3_23_XCLK        0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P3_23_SEL        P3_23_GPIO


//P3.24
#define    P3_24_GPIO        0x00                                       /* GPIO                         */
#define    P3_24_CS3         0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P3_24_SEL        P3_24_CS3


//P3.25
#define    P3_25_GPIO        0x00                                       /* GPIO                         */
#define    P3_25_CS2         0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P3_25_SEL        P3_25_CS2

//P3.26
#define    P3_26_GPIO        0x00                                       /* GPIO                         */
#define    P3_26_CS1         0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P3_26_SEL        P3_26_CS1


//P3.27
#define    P3_27_GPIO        0x00                                       /* GPIO                         */
#define    P3_27_WE          0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
//...      Reserved          0x02
//...      Reserved          0x03
#define    P3_27_SEL        P3_27_WE

//P3.28
#define    P3_28_GPIO        0x00                                       /* GPIO                         */
#define    P3_28_BLS3        0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
#define    P3_28_AIN7        0x02                                       /* A/Dת��������7               */
//...      Reserved          0x03
#define    P3_28_SEL        P3_28_GPIO

//P3.29
#define    P3_29_GPIO        0x00                                       /* GPIO                         */
#define    P3_29_BLS2        0x01                                       /* �ֽڶ�λѡ���ź�,����Ч      */
#define    P3_29_AIN6        0x02                                       /* A/Dת��������6               */
//...      Reserved          0x03
#define    P3_29_SEL        P3_29_AIN6

/*********************************************************************************************************
** Function name:           pinInit
** Descriptions:            I/O���ܳ�ʼ��
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void pinInit(void);

#endif

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
