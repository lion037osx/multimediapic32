/* 
 * File:   DrawText.h
 * Author: optimus
 *
 * Created on 4 de agosto de 2017, 00:10
 */

#ifndef DRAWTEXT_H
#define	DRAWTEXT_H

#ifdef	__cplusplus
extern "C" {
#endif
    

    
void draw_clock(MCP79401 rtcc);

void drawText(void);

WORD func_draw_txt(WORD start_x , WORD start_y , BYTE ascii ,WORD color_font);

WORD str_draw_txt(WORD x,WORD y,char* str,WORD color_font);

#ifdef	__cplusplus
}
#endif

#endif	/* DRAWTEXT_H */

