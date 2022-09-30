/****************************************Copyright (c)****************************************************
**                  
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               eeprom.h
** Latest modified Date:    2017-05-30
** Latest Version:          1.0
** Descriptions:            eeprom�����ӿ��ļ� 
**
**--------------------------------------------------------------------------------------------------------
** Created by:              
** Created date:            2017-05-30
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
#ifndef __EEPROM_H
#define __EEPROM_H    

/*********************************************************************************************************
** Function name:       write_eeprom
** Descriptions:        дEEPROM
** input parameters:    usSubAddr   : �ӻ��ڲ��ӵ�ַ
**                      ucSubAddrLen: �ӻ��ڲ��ӵ�ַ����
**                      pucRet      : ָ�򷵻����ݴ洢λ�õ�ָ��
**                      ulSize      : ���ݳ���
** output parameters:   None
** Returned value:      None
*********************************************************************************************************/
extern INT8U eepromRead (INT16U usSubAddr, INT8U *pucRet, INT32U ulSize);

/*********************************************************************************************************
** Function name:       read_eeprom
** Descriptions:        ��EEPROM
** input parameters:    usSubAddr   : �ӻ��ڲ��ӵ�ַ
**                      ucSubAddrLen: �ӻ��ڲ��ӵ�ַ����
**                      pucRet      : ָ�򷵻����ݴ洢λ�õ�ָ��
**                      ulSize      : ���ݳ���
** output parameters:   None
** Returned value:      None
*********************************************************************************************************/
extern INT8U eepromWrite (INT16U usSubAddr, INT8U *pucRet, INT32U ulSize);

#endif                                                                  /*  __EEPROM_H                  */

