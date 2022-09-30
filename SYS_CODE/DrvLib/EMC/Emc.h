/****************************************Copyright (c)****************************************************
**                              
**
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           emc.h
** Last modified Date:  2013-03-15
** Last Version:        1.01
** Descriptions:        emc�����ⲿͷ�ļ�
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-03-15
** Version:             V1.0
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/

#ifndef  _EMC_H_
#define  _EMC_H_
#ifdef  __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  EMC �������
*********************************************************************************************************/

#define  BANK0          0                                               /*  Bank0 ID ��                 */
#define  BANK1          1                                               /*  Bank1 ID ��                 */
#define  BANK2          2                                               /*  Bank2 ID ��                 */
#define  BANK3          3                                               /*  Bank3 ID ��                 */

#define  DATA_8BIT      8
#define  DATA_16BIT     16
#define  DATA_32BIT     32

/*********************************************************************************************************
  ����ֵ����
*********************************************************************************************************/
#define     ET_OK               0                                       /*  �����ɹ�                    */
#define     ET_PARAMETER_ERR    1                                       /*  ��������                    */

#define     ET_DATA_BUS_LOW     2                                       /*  ������Ϊ�͵�ƽ              */
#define     ET_DATA_BUS_HIGH    3                                       /*  ������Ϊ�ߵ�ƽ              */

#define     ET_DATA_BUS_TGLOW   4                                       /*  ������ճ��Ϊ�͵�ƽ          */
#define     ET_DATA_BUS_TGHIGH  5                                       /*  ������ճ��Ϊ�ߵ�ƽ          */

#define     ET_ADDR_BUS_LOW     6                                       /*  ��ַ��Ϊ�͵�ƽ              */
#define     ET_ADDR_BUS_HIGH    7                                       /*  ��ַ��Ϊ�ߵ�ƽ              */

#define     ET_ADDR_BUS_TGLOW   8                                       /*  ��ַ��ճ��Ϊ�͵�ƽ          */
#define     ET_ADDR_BUS_TGHIGH  9                                       /*  ��ַ��ճ��Ϊ�ߵ�ƽ          */

#define     ET_MEMORY_ERR       10                                      /*  �洢�ռ��л���              */

/*********************************************************************************************************
** Function name:           emcTest
** Descriptions:            EMC���߲���
** input parameters:        uiBANK      : BANK��
**                          uiSizeOfAB  : ��ַ���
**                          Rsv         : ��������
** output parameters:       None
** Returned value:          (((�����߻��ַ����)<<16) | ����״̬��)
*********************************************************************************************************/
INT32S  emcTest(INT32U uiBANK, INT32U uiSizeOfAB, void* pRsv );


/*********************************************************************************************************  
** Function name:           emcInit  
** Descriptions:            EMC��ʼ��
** Input parameters:        uiId            EMC��BANK�ţ���uiId=0,ΪBANK0  
**                          pcArg           ���ò����ַ���ָ��                                                       
**                          pRsv            ��������  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS �����ɹ� 
**                          -OPERATE_FAIL   ����ʧ��
** Example:                 char cEmcArt[]="BusWidth=8 ReadDly=15 WriteDly=15 Idcy=10";  
**                          emcInit( BANK0, cEmcArt, NULL );   
*********************************************************************************************************/ 
extern INT32S emcInit(INT32U ulId, char *pucArg, void *pvRsv);

/*********************************************************************************************************  
** Function name:           emcWrite  
** Descriptions:            EMCд����  
** Input parameters:        uiId            EMC��BANK�ţ���uiId=0,ΪBANK0  
**                          uiBw            �������߿��  
**                          uiAddr          ƫ�Ƶ�ַ0x80000000 ~ 0x83FFFFFF  
**                                          BANK0:  0x80000000 ~ 0x80FFFFFF  
**                                          BANK1:  0x81000000 ~ 0x81FFFFFF  
**                                          BANK2:  0x82000000 ~ 0x82FFFFFF  
**                                          BANK3:  0x83000000 ~ 0x83FFFFFF  
**                          uiNum           д�����ݸ���                                                                        
**                          pvData          ���������׵�ַ  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS �����ɹ� 
**                          -OPERATE_FAIL   ����ʧ��
**                          EXBUSADRROVER   ������ַ��Χ
** Example:                 uint32 uiWriteData[10]={0};  
**                          emcWrite( BANK0, 16, 0x80000000, 10, uiWriteData );  
*********************************************************************************************************/ 
extern INT32S emcWrite(INT32U ulId, INT32U ulBw, INT32U ulAddr, void *pvData, INT32U ulSize);

/*********************************************************************************************************  
** Function name:           emcRead  
** Descriptions:            EMC������  
** Input parameters:        uiId            EMC��BANK�ţ���uiId=0,ΪBANK0  
**                          uiBw            �������߿��  
**                          uiAddr          ƫ�Ƶ�ַ0x80000000 ~ 0x83FFFFFF  
**                                          BANK0:  0x80000000 ~ 0x80FFFFFF  
**                                          BANK1:  0x81000000 ~ 0x81FFFFFF  
**                                          BANK2:  0x82000000 ~ 0x82FFFFFF  
**                                          BANK3:  0x83000000 ~ 0x83FFFFFF  
**                          uiNum           �������ݸ���                                                                        
**                          pvData          �����ݵĴ���׵�ַ  
** Output parameters:       NONE  
** Returned value:          OPERATE_SUCCESS �����ɹ� 
**                          -OPERATE_FAIL   ����ʧ�� 
** Example:                 INT32U uiReadData[10]={0};  
**                          emcRead( BANK0, 16, 0x80000000, 10, uiReadData );  
*********************************************************************************************************/
extern INT32S emcRead(INT32U ulId, INT32U ulBw, INT32U ulAddr, void *pvData, INT32U ulSize);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  _EMC_H_                     */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

