#ifndef __OLED_H__
#define __OLED_H__
#include "main.h"
#include "font.h"

// OLED屏幕坐标系 (128x64像素)
// ┌──────────────────────────────┐ y=0
// │ (0,0)                        │
// │                              │
// │                              │
// │                              │
// │                              │
// │                      (127,63)│
// └──────────────────────────────┘ y=63
// x=0                        x=127

/* OLED颜色模式枚举：NORMAL正常模式，REVERSED反色模式 */
typedef enum {
  OLED_COLOR_NORMAL = 0, // 正常模式
  OLED_COLOR_REVERSED    // 反色模式
} OLED_ColorMode;

/* OLED初始化，配置SSD1306显示参数 */
void OLED_Init(void);
/* 开启OLED显示，使能电荷泵并点亮屏幕 */
void OLED_DisPlay_On(void);
/* 关闭OLED显示，关闭电荷泵并熄灭屏幕 */
void OLED_DisPlay_Off(void);
/* 创建新帧，清空显存 */
void OLED_NewFrame(void);
/* 显示帧，刷新屏幕 */
void OLED_ShowFrame(void);
/* 设置单个像素点 */
void OLED_SetPixel(uint8_t x, uint8_t y, OLED_ColorMode color);

// ========================== 文字绘制函数 ==========================
/* 绘制单个ASCII字符 */
void OLED_PrintASCIIChar(uint8_t x, uint8_t y, char ch, const ASCIIFont *font, OLED_ColorMode color);
/* 绘制ASCII字符串 */
void OLED_PrintASCIIString(uint8_t x, uint8_t y, char *str, const ASCIIFont *font, OLED_ColorMode color);
/* 绘制UTF-8编码字符串，支持中英文混合 */
void OLED_PrintString(uint8_t x, uint8_t y, char *str, const Font *font, OLED_ColorMode color);
/* OLED测试函数，测试I2C通信 */
void OLED_Test(void);

// ========================== 图形绘制函数 ==========================
/* 绘制线段 */
void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_ColorMode color);
/* 绘制矩形框 */
void OLED_DrawRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);
/* 绘制填充矩形 */
void OLED_DrawFilledRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);
/* 绘制三角形框 */
void OLED_DrawTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, OLED_ColorMode color);
/* 绘制填充三角形 */
void OLED_DrawFilledTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, OLED_ColorMode color);
/* 绘制圆形框 */
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);
/* 绘制填充圆形 */
void OLED_DrawFilledCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);
/* 绘制椭圆 */
void OLED_DrawEllipse(uint8_t x, uint8_t y, uint8_t a, uint8_t b, OLED_ColorMode color);
/* 绘制图片 */
void OLED_DrawImage(uint8_t x, uint8_t y, const Image *img, OLED_ColorMode color);

#endif

