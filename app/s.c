
/**
 * s.c -- разделяет строку с курсором по его позиции
 *
 * Copyright (c) 2017, Sarbaev Artur <sarbaev@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "text/_text.h"
#include "common.h"
#include <string.h>

void s(text txt,char *new_str){

    char line[MAXLINE + 1];
    strncpy(line, new_str, MAXLINE);
    strncat(line, "\n", MAXLINE - strlen(line));
    
    /* Сохраняем позицию курсора */
    int ps = txt->cursor->position;
    node* ln = txt->cursor->line;
    node* next_line = txt->cursor->line->next;
     
    /* Сохраняем последнюю строку */
    node* endd = txt->end;
    
    /* Получаем строку с курсором */
    char *current = txt->cursor->line->contents;
    
    /* Строка */
    char current2[MAXLINE+1];

    memcpy(current2, current + ps, MAXLINE - ps+1);
    
    
    /* Добавление новой строки */
    append_line(txt,current2);
    
    // Ставим эту строку после посде строки с курсором
    if(txt->end->previous != ln){ 
    	next_line->previous = txt->cursor->line;
    	txt->cursor->line->previous = ln;
    	txt->cursor->line->next = next_line;
    	ln->next = txt->cursor->line;
    	endd->next = NULL;
    }
    // Возвращаем курсор на место
    txt->cursor->line = ln;
    txt->cursor->position = ps;
    // Обрезаем строку до курсора
    txt->cursor->line->contents[ps] = '\n';
    txt->cursor->line->contents[ps+1] = 0;
    txt->cursor->line->contents[ps+2] = 0;
    
}
