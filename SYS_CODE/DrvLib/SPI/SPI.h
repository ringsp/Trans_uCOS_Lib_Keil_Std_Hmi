/****************************************Copyright (c)****************************************************
**                              
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           SPI.h
** Last modified Date:  2013-08-22
** Last Version:        1.0
** Descriptions:        LPC2200 SPI����
**--------------------------------------------------------------------------------------------------------
** Created by:          
** Created date:        2013-08-22
** Version:             V1.0
** Descriptions:        The original version
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
*********************************************************************************************************/

#ifndef __SPI_H
#define __SPI_H
#ifdef  __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  SPI �������
*********************************************************************************************************/
#define   SPI0              0                                           /*  SPI ID ��                   */
#define   SPI1              1                                           /*  SPI ID ��                   */
/*********************************************************************************************************
  SPI�ж�ͨ����
*********************************************************************************************************/
#define   SPI0_IRQ_CHN      10                                          /*  SPI�ж�ͨ����               */
#define   SPI1_IRQ_CHN      11                                          /*  SPI�ж�ͨ����               */

#define   RX_BUF            0                                           /*  ���ջ�������                */
#define   TX_BUF            1                                           /*  ���ͻ�������                */

/*********************************************************************************************************
  SPI ģʽ��������
*********************************************************************************************************/
#define   SET_SPEED         0                                           /*  SPI����                     */
#define   SET_CTRLMODE      1                                           /*  SPI����ģʽ����             */
#define   SET_MSMODE        2                                           /*  SPI�����ӻ�����             */
#define   SET_CSPIN         3                                           /*  SPIƬѡ                     */
#define   SET_RWMODE        4                                           /*  SPI�����ض�ģʽѡ��         */
  
struct spi_hooks {                                                      /*  ���Ӻ�����                  */
                                                                            
    void          (*pReceive)(void *pRsv,INT8U ucRbr);                  /*  ���յ��ַ����õĺ���        */
                                                                        /*  pRsv: ����,�û���Ҫ����     */  
};
typedef struct spi_hooks    SPI_HOOKS;
typedef struct spi_hooks*   PSPI_HOOKS;
/*********************************************************************************************************
** Function name:           spiInit
** Descriptions:            spi��ʼ��
** input parameters:        uiId            spi������
**                          pcArg           ������ʽ���ַ���ָ��
**                          pRsv            ��������
** output parameters:       None
** Returned value:          OPERATE_SUCCESS �����ɹ�
**                          -OPERATE_FAIL   ����ʧ��
*********************************************************************************************************/
extern INT32S spiInit(INT32U ulId, char *pucArg, void *pvRsv);
                         
/*********************************************************************************************************
** Function name:           spiSetMode
** Descriptions:            ����SPI��ģʽ
** input parameters:        uiId            spi������
**                          uiCmd           ����������
**                          pcArg           ���ò����ַ���ָ��
** output parameters:       None
** Returned value:          OPERATE_SUCCESS �����ɹ�
**                          -OPERATE_FAIL   ����ʧ��
*********************************************************************************************************/
extern INT32S spiSetMode(INT32U uiId, INT32U uiCmd, char *pcArg);

/*********************************************************************************************************
** Function name:           spiWrite
** Descriptions:            ��������,������д��spi���Ͷ���
** input parameters:        uiId            spi������
**                          pucBuf          ��������ָ��
**                          uiSize          �����ֽڸ���
** output parameters:       None
** Returned value:          �ɹ������ֽڸ���
*********************************************************************************************************/
extern INT32S spiWrite(INT32U ulId, INT8U *pucBuf, INT32U ulSize); 

/*********************************************************************************************************
** Function name:           spiDirectWrite
** Descriptions:            ��SPI�豸ֱ�ӷ�������
** input parameters:        ulId            spi������
**                          pucBuf          ���ݴ�ŵ�ַ
**                          ulSize          �����ֽڸ���
** output parameters:       None
** Returned value:          �ɹ������ֽڸ���
*********************************************************************************************************/
extern INT32S spiDirectWrite(INT32U ulId, INT8U *pucBuf, INT32U ulSize); 

/*********************************************************************************************************
** Function name:           spiRead
** Descriptions:            ��ȡspi�����е�����
** input parameters:        ulId            spi������
**                          pucBuf          ���ݴ�ŵ�ַ
**                          ulSize          ��ȡ�ֽڸ���
** output parameters:       None
** Returned value:          �ɹ���ȡ�ֽڸ���
*********************************************************************************************************/
extern INT32S spiRead(INT32U ulId, INT8U *pucBuf, INT32U ulSize);

/*********************************************************************************************************
** Function name:           spiFifoState
** Descriptions:            ��ȡQueue���е�״̬
** input parameters:        uiId            spi������
**                          ucFifo          TX_BUF-���Ͷ���
**                                          RX_BUF-���ն���
** output parameters:       None
** Returned value:          ���Ͷ����пɲ����Ŀռ��С������ն����п������ݸ���
*********************************************************************************************************/
extern INT32S spiFifoState(INT32U ulId, INT8U ucFifo);

/*********************************************************************************************************
** Function name:           spiFifoFlush
** Descriptions:            ��շ��ͻ����Queue����
** input parameters:        uiId            spi������
**                          ucFifo          TX_BUF-���Ͷ���;
**                                          RX_BUF-���ն���
** output parameters:       None
** Returned value:          ���Ͷ����пɲ����Ŀռ��С������ն����п������ݸ���
*********************************************************************************************************/
extern INT32S spiFifoFlush(INT32U ulId, INT8U ucFifo);

/*********************************************************************************************************
** Function name:           spiIsr
** Descriptions:            SPI�жϷ������
** input parameters:        uiId            spi������
** output parameters:       None
** Returned value:          ��
*********************************************************************************************************/
extern void spiIsr(INT32U ulId);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */      
#endif                                                                  /*  __SPI_H                     */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
