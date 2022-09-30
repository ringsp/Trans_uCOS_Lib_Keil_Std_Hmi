/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               io.h
** Latest modified Date:    2010-12-14
** Latest Version:          1.0
** Descriptions:            ����I/O������
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2010-12-14
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
#ifndef __IO_H
#define __IO_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

/*********************************************************************************************************
  ����Ϊ��������
*********************************************************************************************************/

/*********************************************************************************************************
** Function name:           ioInportByte
** Descriptions:            ��I/O�˿�����һ���ֽ�(8λ)
** input parameters:        ulPort: �˿ڵ�ַ
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
__inline INT8U ioInportByte(unsigned long ulPort)
{
    volatile INT8U *pucAddr;

    pucAddr = (INT8U *)ulPort;
    return *pucAddr;
}

/*********************************************************************************************************
** Function name:           ioInportWord
** Descriptions:            ��I/O�˿�����һ������(16λ)
** input parameters:        ulPort: �˿ڵ�ַ
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
__inline INT16U ioInportWord(unsigned long ulPort)
{
    volatile INT16U *pusAddr;

    pusAddr = (INT16U *)ulPort;
    return *pusAddr;
}

/*********************************************************************************************************
** Function name:           ioInportLong
** Descriptions:            ��I/O�˿�����һ����(32λ)
** input parameters:        ulPort: �˿ڵ�ַ
** output parameters:       none
** Returned value:          ����������
*********************************************************************************************************/
__inline INT32U ioInportLong(unsigned long ulPort)
{
    volatile INT32U *pulAddr;

    pulAddr = (INT32U *)ulPort;
    return *pulAddr;
}

/*********************************************************************************************************
** Function name:           ioOutportByte
** Descriptions:            ��һ���ֽ�(8λ)�����I/O�˿�
** input parameters:        ucData: Ҫ���������
**                          ulPort: �˿ڵ�ַ
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
__inline void ioOutportByte(INT8U ucData, unsigned long ulPort)
{
    volatile INT8U *pucAddr;

    pucAddr  = (INT8U *)ulPort;
    *pucAddr = ucData;
}

/*********************************************************************************************************
** Function name:           ioOutportWord
** Descriptions:            ��һ�����ֽ�(16λ)�����I/O�˿�
** input parameters:        usData: Ҫ���������
**                          ulPort: �˿ڵ�ַ
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
__inline void ioOutportWord(INT16U usData, unsigned long ulPort)
{
    volatile INT16U *pusAddr;

    pusAddr  = (INT16U *)ulPort;
    *pusAddr = usData;
}

/*********************************************************************************************************
** Function name:           ioOutportLong
** Descriptions:            ��һ����(32λ)�����I/O�˿�
** input parameters:        ulData: Ҫ���������
**                          ulPort: �˿ڵ�ַ
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
__inline void ioOutportLong(INT32U ulData, unsigned long ulPort)
{
    volatile INT32U *pulAddr;

    pulAddr  = (INT32U *)ulPort;
    *pulAddr = ulData;
}


/*********************************************************************************************************
** Function name:           ioInportMultiByte
** Descriptions:            ��I/O�˿�����ָ����Ŀ���ֽ�(8λ)
** input parameters:        ulPort:  �˿ڵ�ַ
**                          ulCount: ��Ҫ�����������Ŀ
** output parameters:       pvData:  ���ݱ������ʼλ��
** Returned value:          none
*********************************************************************************************************/
extern void ioInportMultiByte(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioCmpByte
** Descriptions:            �Ƚϴ�I/O�����������(8λ�ֽ���)���ڴ��е������Ƿ�һ��
** input parameters:        ulPort:  �˿ڵ�ַ
**                          pvData:  ���Ƚ����ݵ���ʼλ�� 
**                          ulCount: ��Ҫ�Ƚϵ�������Ŀ
** output parameters:       none
** Returned value:          0:       ����һ��
**                          ����:    �����в��    
*********************************************************************************************************/
extern int ioCmpByte(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioInportMultiWord
** Descriptions:            ��I/O�˿�����ָ����Ŀ�İ���(16λ)
** input parameters:        ulPort:  �˿ڵ�ַ
**                          ulCount: ��Ҫ�����������Ŀ
** output parameters:       pvData:  ���ݱ������ʼλ��
** Returned value:          none
*********************************************************************************************************/
extern void ioInportMultiWord(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioCmpWord
** Descriptions:            �Ƚϴ�I/O�����������(16λ������)���ڴ��е������Ƿ�һ��
** input parameters:        ulPort:  �˿ڵ�ַ
**                          pvData:  ���Ƚ����ݵ���ʼλ�� 
**                          ulCount: ��Ҫ�Ƚϵ�������Ŀ
** output parameters:       none
** Returned value:          0:       ����һ��
**                          ����:    �����в��    
*********************************************************************************************************/
extern int ioCmpWord(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioInportMultiLong
** Descriptions:            ��I/O�˿�����ָ����Ŀ����(32λ)
** input parameters:        ulPort:  �˿ڵ�ַ
**                          ulCount: ��Ҫ�����������Ŀ
** output parameters:       pvData:  ���ݱ������ʼλ��
** Returned value:          none
*********************************************************************************************************/
extern void ioInportMultiLong(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioCmpLong
** Descriptions:            �Ƚϴ�I/O�����������(32λ����)���ڴ��е������Ƿ�һ��
** input parameters:        ulPort:  �˿ڵ�ַ
**                          pvData:  ���Ƚ����ݵ���ʼλ�� 
**                          ulCount: ��Ҫ�Ƚϵ�������Ŀ
** output parameters:       none
** Returned value:          0:       ����һ��
**                          ����:    �����в��    
*********************************************************************************************************/
extern int ioCmpLong(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioOutportMultiByte
** Descriptions:            ��ָ����Ŀ���ֽ�(8λ)���I/O�˿�
** input parameters:        ulPort:  �˿ڵ�ַ
**                          pvData:  ���ݱ������ʼλ��
**                          ulCount: ��Ҫ�����������Ŀ
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void ioOutportMultiByte(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioOutportMultiWord
** Descriptions:            ��I/O�˿�����ָ����Ŀ�İ���(16λ)
** input parameters:        ulPort:  �˿ڵ�ַ
**                          pvData:  ���ݱ������ʼλ��
**                          ulCount: ��Ҫ�����������Ŀ
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void ioOutportMultiWord(unsigned long ulPort, void *pvData, unsigned long ulCount);

/*********************************************************************************************************
** Function name:           ioOutportMultiLong
** Descriptions:            ��I/O�˿�����ָ����Ŀ����(32λ)
** input parameters:        ulPort:  �˿ڵ�ַ
**                          pvData:  ���ݱ������ʼλ��
**                          ulCount: ��Ҫ�����������Ŀ
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/
extern void ioOutportMultiLong(unsigned long ulPort, void *pvData, unsigned long ulCount);


#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __IO_H                      */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
