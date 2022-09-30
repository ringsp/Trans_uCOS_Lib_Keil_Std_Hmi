/***********************************************Copyright (c)********************************************* 
**                                 
**                                      
**                                       
** 
**--------------File Info--------------------------------------------------------------------------------- 
** File name:               CmdStr.h 
** Last modified Date:      2013-12-31 
** Last Version:            1.0 
** Descriptions:            �ַ�����������ͷ�ļ� 
** 
**-------------------------------------------------------------------------------------------------------- 
** Created by:               
** Created date:            2013-12-31 
** Version:                 1.0 
** Descriptions:             
** 
**-------------------------------------------------------------------------------------------------------- 
** Modified by:              
** Modified Date:            
** Version:                  
** Descriptions:             
** 
*********************************************************************************************************/ 
#ifndef __CMDSTR_H 
#define __CMDSTR_H 
 
#define __ARG_CMD_FORMAT    0 
/********************************************************************************************************* 
** Function name:           ImpCmd 
** Descriptions:            �û��ַ�����ת��Ϊϵͳ�����õ����ֲ��� 
** input parameters:        ID     : ������:Tab_UART,Tab_I2C,�������μ�Deviceconfig.h 
**                          arg    : �û�������ַ���ָ�� 
**                          para_data  : ת��������ֲ�����ַ 
** Returned value:          >0  :��ʾ�����ɹ����ַ������� 
*********************************************************************************************************/ 
int ImpCmd(unsigned int ID, char *arg, unsigned int *para_data ); 
 
/********************************************************************************************************* 
** Function name:           ExpCmd 
** Descriptions:            ϵͳ���õ����ֲ���ת��Ϊ�ַ������ 
** input parameters:        ID     : ������:Tab_UART,Tab_I2C,�������μ�Deviceconfig.h 
**                          arg    : ������û����û������ַ���ָ�� 
**                          para_data  : ϵͳ�����ֲ�����ַ 
**                          para_num   : ĳ����Ĳ������� 
** Returned value:          OPERATE_SUCCESS--�����ɹ� 
********************************************************************************************************/ 
int ExpCmd(unsigned int ID, char *arg, unsigned int *para_data ); 
 
 
 
#endif                                                                  /* __CMDSTR_H                   */ 
/********************************************************************************************************* 
   END FILE 
*********************************************************************************************************/ 
