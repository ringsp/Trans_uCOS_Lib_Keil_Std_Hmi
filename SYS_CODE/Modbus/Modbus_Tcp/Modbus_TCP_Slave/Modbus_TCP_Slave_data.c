/****************************************Copyright (c)**************************************************
**                               ������������Һ����ϵͳ���޹�˾
**                               �Զ�����      
**
**                                 http://www.tdmacro.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: Modbus_TCP_Slave_data.c
**��   ��   ��: ��ΰ��
**����޸�����: 2010��5��19��
**��        ��: ����Modbus-TCPЭ��ķ�����Slave�˽ӿں���
**              
**              
**              
**             
**              
**              
**              
**             
**--------------��ǰ�汾��Ϣ----------------------------------------------------------------------------
** ������: ��ΰ��
** ��  ��: v1.0
** �ա���: 2010��5��19��
** �衡��: ԭʼ�汾
**
**--------------��ʷ�汾��Ϣ------------------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
**--------------�޸ļ�¼------------------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**			
** �漰����:
**			
**			
**			
**
**------------------------------------------------------------------------------------------------------



********************************************************************************************************/ 

#include "main.h"

// �洢�������ݽṹ
typedef struct tag_MB_TCP_REG_TBL{
	
	uint16	m_nInputStatus;				// ����������״̬�Ĵ���					
	uint16	m_nAdSample1;			    // �����������Ĵ���1
	uint16	m_nAdSample2;				// �����������Ĵ���2
	uint16	m_nFreqSample1;				// ����Ƶ�ʲ����Ĵ���1
	uint16	m_nFreqSample2;				// ����Ƶ�ʲ����Ĵ���2
	uint16	m_nReserved1;
	uint16	m_nReserved2;
	uint16	m_nReserved3;
	uint16	m_nReserved4;
	uint16	m_nReserved5;
	uint16	m_nReserved6;
	uint16	m_nReserved7;
	uint16	m_nReserved8;
	uint16	m_nReserved9;
	uint16	m_nReserved10;
	uint16	m_nReserved11;
	uint16	m_nReserved12;
	uint16	m_nReserved13;

	uint16	m_nReserved14;
	uint16	m_nReserved15;
	uint16	m_nReserved16;
	uint16	m_nReserved17;
	uint16	m_nReserved18;
	uint16	m_nReserved19;
	uint16	m_nReserved20;
	uint16	m_nReserved21;
	uint16	m_nReserved22;
	uint16	m_nReserved23;
	uint16	m_nReserved24;
	uint16	m_nReserved25;
	uint16	m_nReserved26;
	uint16	m_nReserved27;
	}MB_TCP_REG_TBL,*pMB_TCP_REG_TBL;
	
#if 1  
#if MODBUS_SERVER_INSIDE_EN
/*******************************************************************************************************
//
// �û���д�����Ĵ����ӿں���
//
********************************************************************************************************/

#if TCP_READ_DIS_INPUT_EN

static uint8 AppDiscTbl[30] = {0x8a,0x93,0x35};
static uint8 AppKey1;
static uint8 AppKey2;
static uint8 AppKey3;

#define KEY1   (1 << 6)
#define KEY2   (1 << 7)
#define KEY3   (1 << 8)
#define KEY4   (1 << 9)
#define KEY5   (1 << 10)
#define KEY6   (1 << 11)

#define KEY7   (1 << 25)
void keyIni(void)
{
    PINSEL0 &= ~(0xFFF << (6 * 2));
    
    IO0DIR  &= ~(KEY1 | KEY2 | KEY3 | KEY4 | KEY5 | KEY6 | KEY7); 
}

/*********************************************************************************************************
** ��������: MB_TCP_GetDiscrete
** ��������: ��ȡ��ɢֵ�������ú������û���д 
** �䡡��: ch���豸ID  
**         DisInputsV��������ɢ������ֵָ��  
**         Address����Ȧ��ַ
**
** �䡡��: ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
** ȫ�ֱ���: 
** ����ģ��: 
** ������: ��ΰ��
** �ա���: 2010��5��19��
**
**------------------------------------------------------------------------------------------------------
** �޸���:				
** ��  ��:			
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_TCP_GetDiscrete (uint8 ch, uint8 *DisInputsV,uint16 Address)
{
	uint8 err;
	uint8 ix;
	uint8 bit_nbr;
	err = MB_NO_ERR;
	if (Address < 200)//100 * sizeof(uint8))
	{
		ix =(uint8)( Address / 8);
		bit_nbr = (uint8)(Address % 8);
		*DisInputsV =(uint8)((AppDiscTbl[ix] & (1 << bit_nbr))?1:0); 
	}
	else
	{
		switch (Address)
		{
		 
		    case 200:
			    *DisInputsV = (uint8)((IO0PIN & KEY1) ? 1:0);
			    break;
		    case 201:
			    *DisInputsV = (uint8)((IO0PIN & KEY2) ? 1:0);
			    break;
		    case 202:
			    *DisInputsV = (uint8)((IO0PIN & KEY3) ? 1:0);
			    break;
		    case 203:
			    *DisInputsV = (uint8)((IO0PIN & KEY4) ? 1:0);
			    break;
			case 204:
				*DisInputsV = (uint8)(AppKey1?1:0);
				break;
			case 205:
				*DisInputsV = (uint8)(AppKey2?1:0);
				break;
			case 206:
				*DisInputsV = (uint8)(AppKey3?1:0);
				break;
			default:
				err = ILLEGAL_DATA_ADDR;
				break;
		}
	}
	return (err);
}
#endif

#if TCP_READ_COILS_EN

static uint8 AppCoilTbl[100]={0x15,0x52};
static uint8 AppStatus;

/*********************************************************************************************************
** ��������: MB_TCP_GetCoils
** ��������: ��ȡ��Ȧֵ�������ú������û���д 
** �䡡��: ch���豸ID  
**         CoilVPtr��������Ȧֵָ��  
**         Address����Ȧ��ַ
**
** �䡡��: ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
** ȫ�ֱ���: 
** ����ģ��: 
** ������: ��ΰ��
** �ա���: 2010��5��19��
**
**------------------------------------------------------------------------------------------------------
** �޸���:				
** ��  ��:			
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_TCP_GetCoils (uint8 ch, uint8 *CoilVPtr,uint16 Address)
{
	uint8 err;
	uint8 ix;
	uint8 bit_nbr;
	err = MB_NO_ERR;
	
	if (Address < 100 * 8 * sizeof(uint8))
	{
		ix = (uint8)(Address / 8);
		bit_nbr = (uint8)(Address % 8);
		*CoilVPtr =(uint8)((AppCoilTbl[ix] & (1 << bit_nbr))?1:0);
	}
	
	else
	{
		switch (Address) 
		{
			case 99:
				*CoilVPtr = 1;//AppStatus?1:0;
				break;
			case 100:
				*CoilVPtr = 1;//AppRunning?1:0;
				break;
			case 101:
				*CoilVPtr = 1;//AppLED?1:0;
				break;
		    case 102:
		    	*CoilVPtr = 1;//AppLED?1:0;
				break;
			case 103:
				*CoilVPtr = 1;//AppLED?1:0;
				break;
			case 104:
				*CoilVPtr = 1;//AppLED?1:0;
				break;
			case 105:
				*CoilVPtr = 1;//AppLED?1:0;
				break;
			case 106:
				*CoilVPtr = 1;//AppLED?1:0;
				break;		    
			default:
				err = ILLEGAL_DATA_ADDR;
				break;
		}
	}
	return (err);
}
#endif
#if TCP_WRITE_SING_COIL_EN||TCP_WRITE_MULT_COIL_EN
/*********************************************************************************************************
** ��������: MB_TCP_SetCoils
** ��������: ������Ȧֵ�������ú������û���д 
** �䡡��: ch���豸ID  
**         CoilVPtr��������Ȧֵָ��  
**         Address����Ȧ��ַ
**
** �䡡��: ��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
** ȫ�ֱ���: 
** ����ģ��: 
** ������: ��ΰ��
** �ա���: 2010��5��19��
**
**------------------------------------------------------------------------------------------------------
** �޸���:				
** ��  ��:			
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_TCP_SetCoil(uint8 ch, uint16 Address,uint8 CoilValue)
{
	uint8 err;
	uint8 ix;
	uint8 bit_nbr;
	err = MB_NO_ERR;
	if (Address < 100 * sizeof(uint8)) {
		ix = (uint8)(Address / 8);
		bit_nbr = (uint8)(Address % 8);
		if(CoilValue)
			AppCoilTbl[ix] = (uint8)((AppCoilTbl[ix] | (uint8)((1 << bit_nbr))));
		else
			AppCoilTbl[ix] = (uint8)(AppCoilTbl[ix] & (uint8)(~(1 << bit_nbr)));
	} else 	{
	    switch (Address) 
	    {
		    case 199:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                    sysGpioClr(P1_27);
                } else {
                    sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 200:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                     sysGpioClr(P1_27);
                } else {
                     sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 201:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                    sysGpioClr(P1_27);
                } else {
                    sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 202:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                     sysGpioClr(P1_27);
                } else {
                    sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 203:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                     sysGpioClr(P1_27);
                } else {
                     sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 204:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                     sysGpioClr(P1_27);
                } else {
                     sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 205:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                     sysGpioClr(P1_27);
                } else {
                     sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    case 206:
			    AppStatus = (uint8)(CoilValue?1:0);
			    if ( AppStatus ) {
                     sysGpioClr(P1_27);
                } else {
                     sysGpioSet(P1_27); 						// ������Ϩ��
                }
			    break;
		    default:
			    err = ILLEGAL_DATA_ADDR;
			    break;
	    }
	}
	return (err);
}
#endif
#if TCP_READ_INPUT_REG_EN
#define END_INPUT_REG_ADDR 	150
static uint16 InputBuffer[END_INPUT_REG_ADDR] = {0x1234,0x5678,0x9abc};
static uint16 AppAD0;
static uint16 AppAD1;
static uint16 AppAD2;
/*********************************************************************************************************
** ��������:			MB_TCP_GetInputRegValue
**
** ��������:			������Ĵ���ֵ�������ú������û���д
**
** ��    ��:		    ch���豸ID
**						*ValuePtr����������Ĵ���ֵ��ָ��
**						Address���Ĵ�����ַ
** ��    ��:			��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** ��    ��:			��ΰ��
** ��    ��:			2010��5��19��
**-------------------------------------------------------------------------------------------------------
** �޸���:				
** ��  ��:			
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 MB_TCP_GetInputRegValue(uint8 ch, uint16 *ValuePtr,uint16 Address)
{
	uint8 err;
	err = MB_NO_ERR;
	if (Address < END_INPUT_REG_ADDR)
	{
		*ValuePtr = InputBuffer[Address];
	}
	else
	{
		switch (Address) 
		{
			case 300:
				*ValuePtr = AppAD0;
				break;
			case 301:
				*ValuePtr = AppAD1;
				break;
			case 302:
				*ValuePtr = AppAD2;
				break;
			case 303:
				*ValuePtr = AppAD2;
				break;
			case 304:
				*ValuePtr = AppAD2;
				break;
			case 305:
				*ValuePtr = AppAD2;
				break;
			case 306:
				*ValuePtr = AppAD2;
				break;
			case 307:
				*ValuePtr = AppAD2;
				break;
			case 308:
				*ValuePtr = AppAD2;
				break;
			case 309:
				*ValuePtr = AppAD2;
				break;
			case 310:
				*ValuePtr = AppAD2;
				break;
			case 311:
				*ValuePtr = AppAD2;
				break;
			case 312:
				*ValuePtr = AppAD2;
				break;
			case 313:
				*ValuePtr = AppAD2;
				break;
			case 314:
				*ValuePtr = AppAD2;
				break;
			case 315:
				*ValuePtr = AppAD2;
				break;
			default:
				err = ILLEGAL_DATA_ADDR;
				break;
		}
	}
	return (err);
}
#endif


/*********************************************************************************************************
** ����������Э��������޸ĵĲ��֣�����ʵ�ʵ�Ӧ�����е�ͨ��ͨ����дHolding Register��ʵ�֣�������ʼ��ַΪ40001
** ͨ��Э�飺
** �Ĵ�����ַ			
** 40129��0x80��		BIT0 ��ͣ�ź�����λ����
** 40130��0x81��		BIT0~BIT9	����������ֵ1
** 40131��0x82��		BIT0~BIT9	����������ֵ2					
** 40132��0x83��		BIT0~BIT15	Ƶ�ʲ���ֵ1					
** 40133��0x84��		BIT0~BIT15	Ƶ�ʲ���ֵ2
**         
** 40145��0x90��		BIT0~BIT15	���������üĴ���1
** 40146��0x91��		BIT0~BIT15	���������üĴ���2
** 40147��0x92��		BIT0~BIT15	���������üĴ���3
** 40148��0x93��		BIT0~BIT15	���������üĴ���4		
** 	
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if  TCP_READ_HOLD_REG_EN||TCP_WRITE_SING_REG_EN||TCP_WRITE_MULT_REG_EN||TCP_MASK_WRITE_REG_EN||TCP_READ_WRITE_REG_EN


#define MB_TCP_HOLDING_REG_ADDR_OFFSET		0x80
#define MB_TCP_HOLDING_REG_NUM				64
//#define END_HOLDING_REG_ADDR 150

//�洢����64���֣�128���ֽ�
volatile uint16 MB_TCP_RegBuf[MB_TCP_HOLDING_REG_NUM]={0x0000,0x0000,0x0000,0x0000,0x0000,0x1101,0x2202,0x3303,0x4404,0x5505,0x6606,0x7707,0x8808,0x9909,0xaa0a};


						
volatile MB_TCP_REG_TBL * const pMB_TCP_RegTbl = (MB_TCP_REG_TBL *)&MB_TCP_RegBuf[0];  						

#endif
/*********************************************************************************************************
** ��������:			MB_TCP_GetRegValue
**
** ��������:			�����ּĴ���ֵ�������ú������û���д
**
** ��    ��:		    ch���豸ID
**						*ValuePtr�������ȡ�Ĵ�����ֵ��ָ��
**						Address���Ĵ�����ַ
** ��    ��:			��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** ��    ��:			��ΰ��
** ��    ��:			2010��5��19��
**-------------------------------------------------------------------------------------------------------
** �޸���:				
** ��  ��:			
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if  TCP_READ_HOLD_REG_EN||TCP_READ_WRITE_REG_EN
uint8 MB_TCP_GetRegValue(uint8 ch, uint16 *ValuePtr,uint16 Address)
{
	if((Address >= MB_TCP_HOLDING_REG_ADDR_OFFSET)&&(Address < MB_TCP_HOLDING_REG_NUM+MB_TCP_HOLDING_REG_ADDR_OFFSET))
	{
		*ValuePtr = MB_TCP_RegBuf[Address - MB_TCP_HOLDING_REG_ADDR_OFFSET];
		return MB_NO_ERR;
	}
	else
		return ILLEGAL_DATA_ADDR;

}
#endif
/*********************************************************************************************************
** ��������:			MB_TCP_SetRegValue
**
** ��������:			д���ּĴ���ֵ�������ú������û���д
**
** ��    ��:		    ch���豸ID
**						Address���Ĵ�����ַ
**						Value��д���ֵ
** ��    ��:			��������MB_NO_ERR,������ILLEGAL_DATA_ADDR����SLAVE_DEVICE_FAILURE��
**         
** ��    ��:			��ΰ��
** ��    ��:			2010��5��19��
**-------------------------------------------------------------------------------------------------------
** �޸���:				
** ��  ��:			
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#if  TCP_WRITE_SING_REG_EN||TCP_WRITE_MULT_REG_EN||TCP_MASK_WRITE_REG_EN||TCP_READ_WRITE_REG_EN
uint8 MB_TCP_SetRegValue(uint8 ch, uint16 Address,uint16 Value)
{
	if((Address >= MB_TCP_HOLDING_REG_ADDR_OFFSET)&&(Address < MB_TCP_HOLDING_REG_NUM+MB_TCP_HOLDING_REG_ADDR_OFFSET))
	{
		MB_TCP_RegBuf[Address - MB_TCP_HOLDING_REG_ADDR_OFFSET] = Value;
		return MB_NO_ERR;
	}
	else
		return ILLEGAL_DATA_ADDR;
}
#endif
/*********************************************************************************************************
** ��������:           BSP_MB_TmrInit
** ��������:            ��ʱ����ʼ������,�����ṩ�Ĳ����趨��ʱ���жϲ�����Ƶ��
** ��    ��:        time����ʱ��Ƶ�ʣ���СֵΪ25uS
** ��    ��:       none
** 
** ��    ��:           ��ΰ��
** ��    ��:           2010��5��19��
**--------------------------------------------------------------------------------------------------------
** �޸���:             
** ��  ��:           
**--------------------------------------------------------------------------------------------------------
**              
**           
**                          
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/ 
#if 0
void BSP_MB_TmrInit (INT32U time)
{
    char TmrArg[50];
    sprintf(TmrArg, "Time=%uld ActCtrl=3",time);
    sysTimerInit(TIMER1,"Mode=0",NULL);		 	                        /*  ��ʱ��1��ʼ��               */
   /* 
	* ���ö�ʱ��1�Ĺ���ģʽΪ��ʱģʽ��
    * Time=500����ʱʱ��Ϊ500us 
	* ActCtrl=3��ƥ���T1TC��λ,�������ж� 
	*/
	sysTimerSetMode(TIMER1,SET_TIMERMODE,TmrArg);
									 	                           
	if(0 == vicIrqFuncSet(TIMER1_IRQ_CHN,7,(uint32)TIMER1_ISR))    			/*  �����жϣ�һ��Ҫ���жϺ�����
	                                                                        ���MB_TmrUpdate()����      */
    while(1);
    sysTimerStart(TIMER1);                                            /*  ������ʱ��                  */
}
#endif

#endif
#endif
/****************************************************************************************************************/
// File end
/****************************************************************************************************************/
