/**
 * plb.c -- выводит текст строки с курсором до курсора
 *
 * Copyright (c) 2017, Sarbaev Artur <sarbaev@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/*
* Вывод строки до курсора
*/
void plb(text txt){
    /* Получаем позицию курсора */
    int ps = txt->cursor->position;
    /* Получаем строку с курсором */
    char *current = txt->cursor->line->contents;
    int i = 0;
    /* Просто выводим строку до курсора*/
    for( i = 0 ; i < ps ; i++){
	printf("%c", current[i]);
    }
    printf("\n");
}
