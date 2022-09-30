/****************************************Copyright (c)****************************************************
**
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           Driver2200.c
** Last modified Date:  2012-12-31
** Last Version:        1.0
** Descriptions:        ����������Ϣ
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2012-12-31
** Version:             1.0
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:
** Descriptions:        
*********************************************************************************************************/

//#include    "..\USER_CODE\cfg_file\config.h" 
#include    "..\Head\system.h"
/* ���������ڲ����� �û�����ɾ�� */
/*********************************************************************************************************
** Function name:           Dir_Set
** Descriptions:            ����RS-485��������,���û�RS485���Ӻ�������
** input parameters:        Dir  : RS-485�������ű��ֵ
** output parameters:       None
** Returned value:          None
*********************************************************************************************************/
void RS485Dir_Out (INT32U Dir)
{
    gpioSet(Dir);
}
/*********************************************************************************************************
** Function name:           Dir_Clr
** Descriptions:            ����RS-485��������,���û�RS485���Ӻ�������
** input parameters:        Dir  : RS-485�������ű��ֵ
** output parameters:       None
** Returned value:          None
*********************************************************************************************************/
void RS485Dir_In (INT32U Dir)
{
    gpioClr(Dir);
}

/*********************************************************************************************************
** Function name:           UartVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void UartVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           UartVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void UartVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           SpiCS_Enable
** Descriptions:            SPIƬѡʹ��
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void SpiCsEnable(INT32U Dir)
{
    gpioClr(Dir);
}
/*********************************************************************************************************
** Function name:           SpiCS_Disable
** Descriptions:            SPIƬѡ����
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void SpiCsDisable(INT32U Dir)
{
    gpioSet(Dir);
}

/*********************************************************************************************************
** Function name:           SpiVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void SpiVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           SpiVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void SpiVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           I2cVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void I2cVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           I2cVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void I2cVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           WdtVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void WdtVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           WdtVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void WdtVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           CanVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void CanVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           CanVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void CanVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           AdcVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void AdcVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           AdcVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void AdcVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           RtcVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void RtcVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           RtcVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void RtcVicDisable(void)
{
    sysIrqDisable();
}

/*********************************************************************************************************
** Function name:           TimerVicEnable
** Descriptions:            �˳��ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void TimerVicEnable(void)
{
    sysIrqEnable();     
}

/*********************************************************************************************************
** Function name:           RtcVicDisable
** Descriptions:            �����ٽ�״̬
** input parameters:        None
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
void TimerVicDisable(void)
{
    sysIrqDisable();
}

const DRIVER_HOOKS GdhDrvHooksTbl = {
                                    RS485Dir_Out,RS485Dir_In,SpiCsEnable,SpiCsDisable,malloc,free,
                                    UartVicEnable,UartVicDisable,SpiVicEnable,SpiVicDisable,I2cVicEnable,
                                    I2cVicDisable,WdtVicEnable,WdtVicDisable,CanVicEnable,CanVicDisable,
                                    AdcVicEnable,AdcVicDisable,RtcVicEnable,RtcVicDisable,
                                    TimerVicEnable, TimerVicDisable
                                  };

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

