#include "main.h" 
extern INT32S __sysWordProgramEx(uint32 Addr, uint16 Data); 
extern INT32S __sysSectorEraseEx(uint32 Index); 

/*********************************************************************************************************
** Function name:       WordProgram
** Descriptions:        �ֱ��
** input parameters:    ��ַ������
** output parameters:   none
** Returned value:      �Ƿ�ɹ�               
*********************************************************************************************************/
INT32S sysWordProgramEx(uint32 Addr, uint16 Data) 
{
    return __sysWordProgramEx(Addr, Data);
}  
/*********************************************************************************************************
** Function name:       SectorErase
** Descriptions:        ��������
** input parameters:    ������
** output parameters:   none
** Returned value:      �Ƿ�ɹ�               
*********************************************************************************************************/
                     
INT32S sysSectorEraseEx(uint32 Index) 
{
    return __sysSectorEraseEx(Index); 
}


/*********************************************************************************************************
**                            End Of File
*********************************************************************************************************/
