/****************************************Copyright (c)**************************************************
**                               
**                                      
**                                 
**
**--------------File Info-------------------------------------------------------------------------------
** File name:           MB_USER_Data.c
** Last modified Date:  2013-11-30
** Last Version:        2.0
** Descriptions:        
**
**------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        
** Version:             
** Descriptions:        
**
**------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Descriptions:
**
********************************************************************************************************/
#include "..\..\..\USER_CODE\main.h"

#if 1
/*******************************************************************************************************
//
// �û���д�����Ĵ����ӿں���
//
********************************************************************************************************/


uint8 AppDiscTbl[30];
uint8 AppKey1;
uint8 AppKey2;
uint8 AppKey3;


//#define KEY1   (1 << 20)
//#define KEY2   (1 << 22)

#define     BUZZER                  P0_21               // P0.21���Ʒ��������͵�ƽ����

#define     BUZZER_Set()            gpioSet(BUZZER)     // ��������
#define     BUZZER_Clr()            gpioClr(BUZZER) 


/*********************************************************************************************************
** Function name:           MB_GetDiscrete
**
** Descriptions:            ��ȡ��ɢֵ�������ú������û���д
**
** input parameters:        ch,Modbus�ܵ���
**                          DisInputsV��������ɢ������ֵָ��
**                          Address����Ȧ��ַ
** Returned value:          ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_GetDiscrete (uint8 ch,uint8 *DisInputsV,uint16 Address)
{
    uint8 err;
    err = MB_NO_ERR;
    
    switch (Address) {
    case 200:
        *DisInputsV = (IO0PIN & KEY1) ? 1:0;            // ��ȡ����ֵ   
        break;
    case 201:
        *DisInputsV = (IO0PIN & KEY2) ? 1:0;            // ��ȡ����ֵ   
        break;
    default:
        err = ILLEGAL_DATA_ADDR;
        break;
    }
    return (err);

}

uint8 AppCoilTbl[100];
uint8 AppStatus;
uint8 AppRunning;
uint8 AppLED;
/*********************************************************************************************************
** Function name:           MB_GetCoils
**
** Descriptions:            ��ȡ��Ȧֵ�������ú������û���д
**
** input parameters:        ch,Modbus�ܵ���
**                          CoilVPtr��������Ȧֵָ��
**                          Address����Ȧ��ַ
** Returned value:          ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_GetCoils (uint8 ch,uint8 *DisInputsV,uint16 Address)
{
    uint8 err;
    uint8 ix;
    uint8 bit_nbr;
    err = MB_NO_ERR;
    
    if (Address < 100 * sizeof(uint8)) {
        ix = (uint8)(Address / 8);
        bit_nbr = (uint8)(Address % 8);
        *DisInputsV =(uint8)((AppCoilTbl[ix] & (1 << bit_nbr))?1:0); 
        
    } else  {
        switch (Address) {
        case 200:
            *DisInputsV = (uint8)(AppStatus?1:0);
            break;
        case 201:
            *DisInputsV = (uint8)(AppRunning?1:0);
            break;
        case 202:
            *DisInputsV = (uint8)(AppLED?1:0);
            break;
        default:
            err = ILLEGAL_DATA_ADDR;
            break;
        }
    }
    return (err);
}


/*********************************************************************************************************
** Function name:           MB_SetCoil
**
** Descriptions:            ������Ȧֵ�������ú������û���д
**
** input parameters:        ch,Modbus�ܵ���
**                          Address����Ȧ��ַ
**                          CoilValue,��Ȧֵ��0\1��
** Returned value:          ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_SetCoil(uint8 ch,uint16 Address,uint8 CoilValue)
{
    uint8 err;
    uint8 ix;
    uint8 bit_nbr;
    err = MB_NO_ERR;
    if (Address < 100 * sizeof(uint8)) {
        ix = (uint8)(Address / 8);
        bit_nbr = (uint8)(Address % 8);
        if(CoilValue)
            AppCoilTbl[ix] |= (1 << bit_nbr);
        else
            AppCoilTbl[ix] &= ~(1 << bit_nbr);
    } else  {
        switch (Address) {
        case 200:
            if ( CoilValue ) {
                BUZZER_Set(); 
              
            } else {
                BUZZER_Clr(); 
            }

            break;
        case 201:
            AppRunning = (uint8)(CoilValue?1:0);
            break;
        case 202:
            AppLED = (uint8)(CoilValue?1:0);
            break;
        default:
            err = ILLEGAL_DATA_ADDR;
            break;
        }
    }
    return (err);
}

#define END_INPUT_REG_ADDR  150
uint16 InputBuffer[END_INPUT_REG_ADDR];
uint16 AppAD0;
uint16 AppAD1;
uint16 AppAD2;
/*********************************************************************************************************
** Function name:           MB_GetInputRegValue
**
** Descriptions:            ������Ĵ���ֵ�������ú������û���д
**
** input parameters:        ch,Modbus�ܵ���
**                          *ValuePtr����������Ĵ���ֵ��ָ��
**                          Address���Ĵ�����ַ
** Returned value:          ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_GetInputRegValue(uint8 ch,uint16 *ValuePtr,uint16 Address)
{
    uint8 err;
    err = MB_NO_ERR;
    if (Address < END_INPUT_REG_ADDR) {
        *ValuePtr = InputBuffer[Address];
    } else  {
        switch (Address) {
        case 3000:
            *ValuePtr = AppAD0;
            break;
        case 3001:
            *ValuePtr = AppAD1;
            break;
        case 3002:
            *ValuePtr = AppAD2;
            break;
        default:
            err = ILLEGAL_DATA_ADDR;
            break;
        }
    }
    return (err);
}


#define END_HOLDING_REG_ADDR 150
uint16 RegValueBuffer[END_HOLDING_REG_ADDR];
/*********************************************************************************************************
** Function name:           MB_GetRegValue
**
** Descriptions:            �����ּĴ���ֵ�������ú������û���д
**
** input parameters:        ch,Modbus�ܵ���
**                          *ValuePtr�������ȡ�Ĵ�����ֵ��ָ��
**                          Address���Ĵ�����ַ
** Returned value:          ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_GetRegValue(uint8 ch,uint16 *ValuePtr,uint16 Address)
{
    if(Address < END_HOLDING_REG_ADDR) {
        *ValuePtr = RegValueBuffer[Address] ;
        return MB_NO_ERR;
    } else {
        return ILLEGAL_DATA_ADDR;
    }
}


/*********************************************************************************************************
** Function name:           MB_SetRegValue
**
** Descriptions:            д���ּĴ���ֵ�������ú������û���д
**
** input parameters:        ch,Modbus�ܵ���
**                          Address���Ĵ�����ַ
**                          Value��д���ֵ
** Returned value:          ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** Created by:              
** Created Date:            2013/11/30
**-------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_SetRegValue(uint8 ch,uint16 Address,uint16 Value)
{
    if (Address < END_HOLDING_REG_ADDR) {
        RegValueBuffer[Address] = Value;
        return MB_NO_ERR;
    } else {
        return ILLEGAL_DATA_ADDR;
    }
}

#endif
/****************************************************************************************************************/
// File end
/****************************************************************************************************************/
