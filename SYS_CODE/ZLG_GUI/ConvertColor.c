/****************************************************************************************
* 文件名：CONVERTCOLOR.C
* 功能：颜色值转换程序。
* 作者：黄绍斌
* 日期：2004.02.26
* 备注：
****************************************************************************************/
#include  "..\Head\system.h"


#if  CONVERTCOLOR_EN==1
/****************************************************************************
* 名称：GUI_Color2Index_565()
* 功能：将RGB值转换16位索引值。转换后的值适用于64K色彩色液晶。
* 入口参数：ColorRGB		RGB值，d23--d16为R值，d15--d8为G值，d7--d0为B值
* 出口参数：返回转换值(64K色，d15--d11为R值，d10--d5为G值，d4--d0为B值)
* 说明：
****************************************************************************/
uint16  GUI_Color2Index_565(uint32 colorRGB) 
{  uint8  r, g, b;

   b = ( colorRGB>>(0+3) ) & 0x1f;		// 取B色的高5位
   g = ( colorRGB>>(8+2) ) & 0x3f;		// 取G色的高6位
   r = ( colorRGB>>(16+3)) & 0x1f;		// 取R色的高5位
   
   return( (r<<11) + (g<<5) + (b<<0) );		
}


/****************************************************************************
* 名称：GUI_Index2Color_565()
* 功能：将16位索引值转换为RGB值。适用于64K色彩色液晶。
* 入口参数：index		16位索引值(64K色，d15--d11为R值，d10--d5为G值，d4--d0为B值)
* 出口参数：返回值即为RGB值(d23--d16为R值，d15--d8为G值，d7--d0为B值)。
* 说明：
****************************************************************************/
uint32  GUI_Index2Color_565(uint16 index) 
{  uint32  r, g, b;

   b = (index>>0)  & 0x1f;
   g = (index>>5)  & 0x3f;
   r = (index>>11) & 0x1f;
   r = r * 255 / 31;
   g = g * 255 / 63;
   b = b * 255 / 31;
   
   return( (r<<16) + (g<<8) + (b<<0) );
}



/****************************************************************************
* 名称：GUI_Color2Index_555()
* 功能：将RGB值转换15位索引值。转换后的值适用于32K色彩色液晶。
* 入口参数：ColorRGB		RGB值，d23--d16为R值，d15--d8为G值，d7--d0为B值
* 出口参数：返回转换值(32K色，d14--d10为R值，d9--d5为G值，d4--d0为B值)
* 说明：
****************************************************************************/
uint16  GUI_Color2Index_555(uint32 colorRGB) 
{  uint8  r, g, b;

   b = ( colorRGB>>(0+3) ) & 0x1f;
   g = ( colorRGB>>(8+3) ) & 0x1f;
   r = ( colorRGB>>(16+3)) & 0x1f;
  
   return( (r<<10) + (g<<5) + (b<<0) );
}


/****************************************************************************
* 名称：GUI_Index2Color_555()
* 功能：将15位索引值转换为RGB值。适用于32K色彩色液晶。
* 入口参数：index		15位索引值(32K色，d14--d10为R值，d9--d5为G值，d4--d0为B值)
* 出口参数：返回值即为RGB值(d23--d16为R值，d15--d8为G值，d7--d0为B值)。
* 说明：
****************************************************************************/
uint32  GUI_Index2Color_555(uint16 index) 
{  uint32  r, g, b;

   b = (index>>0)  & 0x1f;
   g = (index>>5)  & 0x1f;
   r = (index>>10) & 0x1f;
   r = r * 255 / 31;
   g = g * 255 / 31;
   b = b * 255 / 31;
   
   return( (r<<16) + (g<<8) + (b<<0) );
}


/****************************************************************************
* 名称：GUI_Color2Index_444()
* 功能：将RGB值转换12位索引值。转换后的值适用于4096色伪彩液晶。
* 入口参数：ColorRGB		RGB值，d23--d16为R值，d15--d8为G值，d7--d0为B值
* 出口参数：返回转换值(4096色，RRRRGGGGBBBB)
* 说明：
****************************************************************************/
uint16  GUI_Color2Index_444(uint32 colorRGB) 
{  uint8 r,g,b;

   b = ( colorRGB>>(0+4) ) & 0x0f;
   g = ( colorRGB>>(8+4) ) & 0x0f;
   r = ( colorRGB>>(16+4)) & 0x0f;
   
   return ( (r<<8) + (g << 4) + (b<<0) );
}


/****************************************************************************
* 名称：GUI_Index2Color_444()
* 功能：将12位索引值转换为RGB值。适用于4096色伪彩液晶。
* 入口参数：index		12位索引值(4096色，RRRRGGGGBBBB)
* 出口参数：返回值即为RGB值(d23--d16为R值，d15--d8为G值，d7--d0为B值)。
* 说明：
****************************************************************************/
uint32  GUI_Index2Color_444(uint16 index) 
{  uint8  r,g,b;

   b = (index >> 0) & 0x0f;
   g = (index >> 4) & 0x0f;
   r = (index >> 8) & 0x0f;
  
   r = r * 17;
   g = g * 17;
   b = b * 17;
   
   return ( (r<<16) + (g<<8) + (b<<0) );
}



/****************************************************************************
* 名称：GUI_Color2Index_332()
* 功能：将RGB值转换8位索引值。转换后的值适用于256色伪彩液晶。
* 入口参数：ColorRGB		RGB值，d23--d16为R值，d15--d8为G值，d7--d0为B值
* 出口参数：返回转换值(256色，RRRGGGBB)
* 说明：
****************************************************************************/
uint8  GUI_Color2Index_332(uint32 colorRGB) 
{  uint32  r, g, b;

   b = (colorRGB>>0)  & 0xff;
   g = (colorRGB>>8)  & 0xff;
   r = (colorRGB>>16) & 0xff;
   r = (r * 7 + 127) / 255;
   g = (g * 7 + 127) / 255;
   b = (b + 42) / 85;
   
   return( (r<<5) + (g << 2) + (b<<0) );
}


/****************************************************************************
* 名称：GUI_Index2Color_332()
* 功能：将8位索引值转换为RGB值。适用于256色伪彩液晶。
* 入口参数：index		8位索引值(256色，RRRGGGBB)
* 出口参数：返回值即为RGB值(d23--d16为R值，d15--d8为G值，d7--d0为B值)。
* 说明：
****************************************************************************/
uint32  GUI_Index2Color_233(uint8 index)
{  uint32  r, g, b;

   r = (index >> 5) * 255 / 7;
   g = ((index >> 3) & 7) * 255 / 7;
   b = (index & 3) * 85;
   
   return( (r<<16) + (g << 8) + (b<<0) );
}



/****************************************************************************
* 名称：GUI_Color2Index_222()
* 功能：将RGB值转换8位索引值。转换后的值适用于64色液晶。
* 入口参数：ColorRGB		RGB值，d23--d16为R值，d15--d8为G值，d7--d0为B值
* 出口参数：返回转换值(64色，RRGGBB)
* 说明：
****************************************************************************/
uint8  GUI_Color2Index_222(uint32 colorRGB)
{  uint32  r, g, b;

   b = (((colorRGB>>0) &255)+0x2a)/0x55;
   g = (((colorRGB>>8) &255)+0x2a)/0x55;
   r = (((colorRGB>>16)&255)+0x2a)/0x55;
   
   return( (r<<4) + (g<<2) + (b<<0) );
}


/****************************************************************************
* 名称：GUI_Index2Color_222()
* 功能：将6位索引值转换为RGB值。适用于64色液晶。
* 入口参数：index		6位索引值(64色，RRGGBB)
* 出口参数：返回值即为RGB值(d23--d16为R值，d15--d8为G值，d7--d0为B值)。
* 说明：
****************************************************************************/
uint32  GUI_Index2Color_222(uint8 index) 
{  uint8  r, g, b;

   b = ((index>>0)&3) * 0x55;
   g = ((index>>2)&3) * 0x55;
   r = ((index>>4)&3) * 0x55;
   
   return( (r<<16) + (g<<8) + (b<<0) );
}




/****************************************************************************
* 名称：GUI_Color2Index_111()
* 功能：将RGB值转换3位索引值。转换后的值适用于8色液晶或8级恢度液晶。
* 入口参数：ColorRGB		RGB值，d23--d16为R值，d15--d8为G值，d7--d0为B值
* 出口参数：返回转换值(8色，RGB)
* 说明：
****************************************************************************/
uint8  GUI_Color2Index_111(uint32 colorRGB) 
{  uint8  r, g, b;

   b = (colorRGB>>(0+7))  &1;
   g = (colorRGB>>(8+7))  &1;
   r = (colorRGB>>(16+7)) &1;
   
   return( (r<<2) + (g<<1) + (b<<0) );
}


/****************************************************************************
* 名称： GUI_Index2Color_111()
* 功能：将3位索引值转换为RGB值。适用于8色液晶或8级恢度液晶。
* 入口参数：index		3位索引值(8色，RGB)
* 出口参数：返回值即为RGB值(d23--d16为R值，d15--d8为G值，d7--d0为B值)。
* 说明：
****************************************************************************/
uint32  GUI_Index2Color_111(uint8 Index) 
{  uint8  r, g, b;

   b = ((Index>>0)&1) * 0xff;
   g = ((Index>>1)&1) * 0xff;
   r = ((Index>>2)&1) * 0xff;
   
   return( (r<<16) + (g<<8) + (b<<0) );
}

#endif
