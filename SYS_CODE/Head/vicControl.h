/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               vicControl.h
** Latest modified Date:    2008-04-21
** Latest Version:          1.0
** Descriptions:            VIC���ƴ���
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Chenmingji
** Created date:            2008-04-21
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

#ifndef _VIC_CONTROL_H_
#define _VIC_CONTROL_H_

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */


/********************************************************************************************************* 
  �����жϲ�����ID�� 
  �û����ɸı�����ID�ĺ궨�� 
*********************************************************************************************************/ 
#define VIC_WDT                      0x00                               /*  ���Ź�                      */ 
#define VIC_TIMER0                   0x04                               /*  ��ʱ��0                     */ 
#define VIC_TIMER1                   0x05                               /*  ��ʱ��1                     */ 
#define VIC_UART0                    0x06                               /*  ����0                       */ 
#define VIC_UART1                    0x07                               /*  ����1                       */ 
#define VIC_PWM0                     0x08                               /*  PWM0                        */ 
#define VIC_I2C0                     0x09                               /*  I2C0                        */ 
#define VIC_SPI0                     0x0a                               /*  SPI0                        */ 
#define VIC_SPI1                     0x0b                               /*  SPI1/ssp                    */ 
#define VIC_PLL                      0x0c                               /*  ���໷                      */ 
#define VIC_RTC                      0x0d                               /*  ʵʱʱ��                    */ 
#define VIC_EINT0                    0x0e                               /*  �ⲿ�ж�0                   */ 
#define VIC_EINT1                    0x0f                               /*  �ⲿ�ж�1                   */ 
#define VIC_EINT2                    0x10                               /*  �ⲿ�ж�2                   */ 
#define VIC_EINT3                    0x11                               /*  �ⲿ�ж�3                   */ 
#define VIC_ADC                      0x12                               /*  AD0������                   */ 
#define VIC_CAN_ERR                  0x13
#define VIC_CAN1_TX                  0x14
#define VIC_CAN2_TX                  0x15
#define VIC_CAN3_TX                  0x16
#define VIC_CAN4_TX                  0x17

#define VIC_CAN1_RX                  0x1a
#define VIC_CAN2_RX                  0x1b
#define VIC_CAN3_RX                  0x1c
#define VIC_CAN4_RX                  0x1d



/*********************************************************************************************************
  ���ݶ��壬�Ժ�Ҫʹ��
*********************************************************************************************************/
#define VIC_Config              VIC_IRQ_CFG
#define pVIC_Config             PVIC_IRQ_CFG

#define SetVICIRQ               vicIrqFuncSet
#define FreeVICIRQ              vicIrqFuncClr
#define ReEnableVICIRQ          vicIrqEnable
#define DisableVICIRQ           vicIrqDisable
#define GetVICIRQState          vicIrqStatusGet
#define SetVICFIQ               vicFiqSet
#define FreeVICFIQ              vicFiqClr
#define SetDefIRQFunction       vicDefIrqFuncSet
#define EnableDefIRQ            vicDefIrqEnable
#define DisableDefIRQ           vicDefIrqDisable
#define EnableSoftInt           vicSoftIntEnable
#define DisableSoftInt          vicSoftIntDisable


/*********************************************************************************************************
  VIC������Ϣ����
*********************************************************************************************************/
struct vic_irq_cfg {
    INT32U      ulChannel;                                              /*  ͨ��                        */
    INT32U      ulPri;                                                  /*  ���ȼ�                      */
    INT32U      ulFunctionAddr;                                         /*  ISR��ַ                     */
    INT32U      ulEnable;                                               /*  ʹ�ܱ�ʶ                    */
};

typedef struct vic_irq_cfg      VIC_IRQ_CFG;
typedef struct vic_irq_cfg     *PVIC_IRQ_CFG;


/*********************************************************************************************************
** Function name:           swiHandle
** Descriptions:            SWI��������
** input parameters:        iHandle: �������ֹ���
**                          ����:    ���ݹ��ܾ���
** output parameters:       ���ݹ��ܾ���
** Returned value:          ���ݹ��ܾ���
*********************************************************************************************************/
__swi(0x01) unsigned int swiHandle (int iHandle, unsigned int, unsigned int, unsigned int);


/*********************************************************************************************************
** Function name:           vicIrqFuncSet
** Descriptions:            ������ѡ������ж����ȼ����жϷ�������ַ����ʹ���ж�
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
**                          uiPri:      �ж����ȼ�
**                          uiFuncAddr: �жϷ�������ַ
** output parameters:       none
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicIrqFuncSet (unsigned int uiChannel,
                                     unsigned int uiPri,
                                     unsigned int uiFuncAddr);
                                     


       
/*********************************************************************************************************
** Function name:           vicIrqFuncClr
** Descriptions:            �����ѡ�����IRQ��Դ
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
** output parameters:       none
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicIrqFuncClr (unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicIrqEnable
** Descriptions:            ʹ����Ӧ������ж�
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
** output parameters:       none
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicIrqEnable (unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicIrqDisable
** Descriptions:            ��ֹ��Ӧ������ж�
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
** output parameters:       none
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicIrqDisable (unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicIrqStatusGet
** Descriptions:            ��ȡ��ѡ������ж�ͨ���š����ȼ����жϷ�������ַ���ж�ʹ��״̬
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
** output parameters:       pvicInfo:   ������Ϣ
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicIrqStatusGet (unsigned int uiChannel, PVIC_IRQ_CFG pvicInfo);

/*********************************************************************************************************
** Function name:           vicFiqSet
** Descriptions:            ���ò�ʹ����ѡ�ж�ͨ����ΪFIQ�ж�
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
** output parameters:       none
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicFiqSet (unsigned int uiChannel);

/*********************************************************************************************************
** Function name:           vicFiqClr
** Descriptions:            �����ѡ�ж�ͨ���ŵ�FIQ�ж�
** input parameters:        uiChannel:  �����Ӧ���ж�ͨ����
** output parameters:       none
** Returned value:          1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicFiqClr (unsigned int uiChannel);

/*********************************************************************************************************
** Function name: DefIrqFuncSet
** Descriptions: ���÷������жϷ�������ַ
** input parameters: uiFuncAddr  :�жϷ��������ͨC���Ժ�����
** output parameters:       none
** Returned value: 1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int vicDefIrqFuncSet(unsigned int uiFuncAddr);

/*********************************************************************************************************
** Function name: DefIrqEnable
** Descriptions: ʹ����ѡ�ж�ͨ���ŵķ������ж�
** input parameters: uiChannel   �������Ӧ���ж�ͨ����
** output parameters:       none
** Returned value: 1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int  vicDefIrqEnable(unsigned int uiChannel);
/*********************************************************************************************************
** Function name: DefIrqDisable
** Descriptions: �ͷ���ѡ�ж�ͨ���ŵķ������ж�
** input parameters: uiChannel     �������Ӧ���ж�ͨ����
** output parameters:       none
** Returned value: 1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int  vicDefIrqDisable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name: SoftIntEnable
** Descriptions: ʹ����ѡ�ж�ͨ���ŵ��������ж�
** input parameters: uiChannel     �������Ӧ���ж�ͨ����
** output parameters:       none
** Returned value: 1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int  vicSoftIntEnable(unsigned int uiChannel);

/*********************************************************************************************************
** Function name: SoftIntDisable
** Descriptions: ��ֹ��ѡ�ж�ͨ���ŵ��������ж�
** input parameters: uiChannel     �������Ӧ���ж�ͨ����
** output parameters:       none
** Returned value: 1:          �ɹ�
**                          0:          ʧ��
*********************************************************************************************************/
extern unsigned int  vicSoftIntDisable(unsigned int uiChannel);




/*********************************************************************************************************
  �����ж�Ƕ�׺궨��
*********************************************************************************************************/
#define     OS_ENABLE_NESTING       OS_EXIT_CRITICAL
#define     OS_DISABLE_NESTING      OS_ENTER_CRITICAL

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TARGET_H                  */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

