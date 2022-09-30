#define __NOR_FLASH

#include "main.h"
/*
 *  定义IAP返回状态字
 */
#define     CMD_SUCCESS                                0
#define     INVALID_COMMAND                            1
#define     SRC_ADDR_ERROR                             2 
#define     DST_ADDR_ERROR                             3
#define     SRC_ADDR_NOT_MAPPED                        4
#define     DST_ADDR_NOT_MAPPED                        5
#define     COUNT_ERROR                                6
#define     INVALID_SECTOR                             7
#define     SECTOR_NOT_BLANK                           8
#define     SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION    9
#define     COMPARE_ERROR                              10
#define     BUSY                                       11
#define     SRC_BUF_NOT_MAPPED                         128

/*********************************************************************************************************
** Function name:       GetAddr
** Descriptions:        转换地址
** input parameters:    地址
** output parameters:   none
** Returned value:      转换后的地址                    
*********************************************************************************************************/
volatile uint16 *GetAddr(uint32 addr)
{
    uint32 temp;
    
    temp = 0x80000000;
    temp += (addr << 1);
    return (volatile uint16 *)temp;
}

/*********************************************************************************************************
** Function name:       WordProgram
** Descriptions:        字编程
** input parameters:    地址，数据
** output parameters:   none
** Returned value:      是否成功               
*********************************************************************************************************/
INT32S __sysWordProgramEx(uint32 Addr, uint16 Data) 
{
    volatile uint16 *ip;
    uint16 temp1,temp2;

    ip = GetAddr(0x5555);
    ip[0] = 0xaaaa;
    ip = GetAddr(0x2aaa);
    ip[0] = 0x5555;
    ip = GetAddr(0x5555);
    ip[0] = 0xa0a0;
    
    ip = ((volatile uint16 *)(Addr));
    *ip = Data;
    while (1) {
        temp1 = *ip;
        temp2 = *ip;
        if (temp1 == temp2) {
            if (temp1 != Data) {
                return -BUSY;
            } else {
                return CMD_SUCCESS;
            }
        }
    }
}  
/*********************************************************************************************************
** Function name:       SectorErase
** Descriptions:        扇区擦除
** input parameters:    扇区号
** output parameters:   none
** Returned value:      是否成功               
*********************************************************************************************************/
                     
INT32S __sysSectorEraseEx(uint32 Index) 
{
    volatile uint16 *ip;
    uint16 temp1,temp2;

    ip = GetAddr(0x5555);
    ip[0] = 0xaaaa;
    ip = GetAddr(0x2aaa);
    ip[0] = 0x5555;
    ip = GetAddr(0x5555);
    ip[0] = 0x8080;
    ip = GetAddr(0x5555);
    ip[0] = 0xaaaa;
    ip = GetAddr(0x2aaa);
    ip[0] = 0x5555;
    ip = GetAddr(Index << 11);
    ip[0] = 0x3030; 
    while (1) {
        temp1 = *ip;
        temp2 = *ip;
        if (temp1 == temp2) {
            if (temp1 != 0xffff) {
                return -BUSY;
            } else {
                return CMD_SUCCESS;
            }
        }
    }
}


/*********************************************************************************************************
**                            End Of File
*********************************************************************************************************/
