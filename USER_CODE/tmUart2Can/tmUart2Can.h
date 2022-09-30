/****************************************Copyright (c)****************************************************
**                            
**                                      
**                                 
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               tmUart2Can.h
** Latest modified Date:    2011-04-17
** Latest Version:          1.0
** Descriptions:            UART ���������ӿ��ļ�
**
**--------------------------------------------------------------------------------------------------------
** Created by:               
** Created date:            2011-04-17
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
#ifndef __TMUART_DRIV_H
#define __TMUART_DRIV_H

#ifdef __cplusplus
extern "C" {
#endif                                                                  /*  __cplusplus                 */

    /*********************************************************************************************************
  �ֽ�˳��任
*********************************************************************************************************/
#ifndef tm_ntohl
#define tm_ntohl(x) x = (INT32U)(((INT8U *)&(x))[0] << 24 | \
                                 ((INT8U *)&(x))[1] << 16 | \
                                 ((INT8U *)&(x))[2] << 8  | \
                                 ((INT8U *)&(x))[3] << 0)
#endif                                                                  /*  tm_ntohl                    */

#ifndef tm_htonl
#define tm_htonl(x) x = (INT32U)(((INT8U *)&(x))[0] << 24 | \
                                 ((INT8U *)&(x))[1] << 16 | \
                                 ((INT8U *)&(x))[2] << 8  | \
                                 ((INT8U *)&(x))[3] << 0)
#endif                                                                  /*  tm_htonl                    */

#ifndef tm_ntohs
#define tm_ntohs(x) x = (INT16U)(((INT8U *)&(x))[0] << 8  | \
                                 ((INT8U *)&(x))[1] << 0)
#endif                                                                  /*  tm_ntohs                    */

#ifndef tm_htons
#define tm_htons(x) x = (INT16U)(((INT8U *)&(x))[0] << 8  | \
                                 ((INT8U *)&(x))[1] << 0)
#endif                                                                  /*  tm_htons                    */

/*********************************************************************************************************
    Э��֡��Ϣ�ṹ�嶨��
*********************************************************************************************************/
struct __frame_packet
{
    union {
        unsigned long    ulDWord;
        struct {                    
            unsigned int ulSrc      :8;                                 /*  Դ��ַλ��                  */
            unsigned int ulDst      :8;                                 /*  Ŀ�ĵ�ַλ��                */
            unsigned int ulRsv      :2;                                 /*  ����λ��                    */
            unsigned int ulDir      :2;                                 /*  ������λ��                  */
            unsigned int ulAck      :2;                                 /*  ��Ӧ��λ��                  */
            unsigned int ulCmd      :4;                                 /*  ������λ��                  */
            unsigned int ulPri      :3;                                 /*  ���ȼ�λ��                  */
            unsigned int ucIsRemote :1;                                 /*  �Ƿ���Զ��֡                */
            unsigned int ucIsExtend :1;                                 /*  �Ƿ�����չ֡                */
        }ulBits;
    }ulId;                                                              /*  ֡ID                        */
    INT8U   ucDataLen;                                                  /*  ���ݳ���                    */
    INT8U   ucBuf[8];                                                   /*  ֡����                      */
};
typedef struct __frame_packet   __FRAME_PACKET;
typedef struct __frame_packet  *__PFRAME_PACKET;

    /*
     *  �ڲ�����ṹ
     */
struct __serial_frame_del {    
    __FRAME_PACKET  *pfrPacket; 
    INT8U            ucXor; 
    INT16U           usLen;
    INT32U           ulId;
    INT8U            ucState;
};
typedef struct __serial_frame_del   __SERIAL_FRAME_DEL;
typedef struct __serial_frame_del  *__PSERIAL_FRAME_DEL;
 

/*********************************************************************************************************
  �ӿں����б�
*********************************************************************************************************/
extern void uartReceiveHook (void *pRsv, INT8U ucRbr, INT8U ucLsr);
extern INT32S uart2CanSend (INT8U  ucChn, struct __frame_packet   *pData);

#ifdef __cplusplus
}
#endif                                                                  /*  __cplusplus                 */

#endif                                                                  /*  __TMUART_DRIV_H              */

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
