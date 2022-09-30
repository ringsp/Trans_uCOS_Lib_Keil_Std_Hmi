/****************************************Copyright (c)****************************************************
**                            Guangzhou ZHIYUAN electronics Co.,LTD.
**                                      
**                                 http://www.embedtools.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               zlgHeapCfg.h
** Last modified Date:      2008-07-17
** Last Version:            1.0.0
** Descriptions:            ZLG HEAP 内存管理配置
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Hanhui
** Created date:            2008-07-17
** Version:                 1.0.0
** Descriptions:            ZLG HEAP 内存管理配置
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef __OS_HEAP_CFG_H
#define __OS_HEAP_CFG_H


/*********************************************************************************************************
  配置类型
*********************************************************************************************************/

#define OS_HEAP_CONFIG_TYPE        0                                    /*  0 为静态配置模式            */
                                                                        /*  1 为动态配置模式            */

/*********************************************************************************************************
  互斥操作配置
*********************************************************************************************************/

#define OS_HEAP_INIT_LOCK()                                             /*  初始化堆锁，可以使用信号量  */
                                                                        /*  或关闭调度器                */
#define OS_HEAP_LOCK()             OSSchedLock()                        /*  内存堆上锁                  */
#define OS_HEAP_UNLOCK()           OSSchedUnlock()                      /*  内存堆解锁                  */

/*********************************************************************************************************
  内部操作配置
*********************************************************************************************************/

#define OS_HEAP_PAGESIZE           16                                   /*  段内分页大小(字节)4的整数倍 */
                                                                        /*  更大的页, 可以有效降低内存  */
                                                                        /*  碎片的产生                  */
                                                                        /*  同时更大的页, 将会使部分的  */
                                                                        /*  内存产生浪费                */

#define OS_HEAP_NUMBER             10                                   /*  可供使用的分堆数            */
                                                                        /*  使用动态配置时, 此宏没有意义*/

#define OS_HEAP_OP_SAFE            1                                    /*  是否需要，安全操作控制      */



/*********************************************************************************************************
  配置检查 (用户不需要修改)
*********************************************************************************************************/

#if     OS_HEAP_PAGESIZE == 0                                           /*  使用默认分页大小            */
#undef  OS_HEAP_PAGESIZE
#define OS_HEAP_PAGESIZE           8
#endif                                                                  /*  OS_HEAP_PAGESIZE == 0       */

#if    (OS_HEAP_PAGESIZE & 0x03) != 0x00
#error  "设置的页大小没有对齐内存，必须是 4 的整数倍"                   /*  内存对齐检查                */
#endif

#if     OS_HEAP_CONFIG_TYPE == 0
#if     OS_HEAP_NUMBER <= 0                                             /*  至少定义一个堆              */
#undef  OS_HEAP_NUMBER
#define OS_HEAP_NUMBER             1
#endif                                                                  /*  OS_HEAP_NUMBER <= 0         */
#endif                                                                  /*  OS_HEAP_CONFIG_TYPE == 0    */

#endif                                                                  /*  __OS_HEAP_CFG_H             */
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
