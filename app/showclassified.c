/**
 * Showclassified.C -- Реализует команду вывода текста, где буквенные символы заменяны на звезды
 *
 * Copyright (c) 2017, Sarbaev Artur <sarbaev@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <ctype.h>
static void showclassified_line(int index, char *contents);

/**
 * Выводит вместо букв звездочки
 */

void showclassified(text txt)
{
    /* Вставляет курсор в текст */
    print_cursor(txt);
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showclassified_line);
    /* Удаляет курсор из текста */
    remove_cursor(txt);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void showclassified_line(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    /* Переменная счетчика */
    int i;
    /* Массив для строк */
    char arr[MAXLINE];
    /* Проверка каждого символа и замена на звезду */
    for( i = 0 ; i < MAXLINE ; i++ ){
	/* Присваеваем нашему массиву символ и проверяем на буквенность */
	arr[i]=contents[i];
    	if(isalpha(contents[i])){
		arr[i] = '*';
	}
    }
    /* Декларируем неиспользуемый параметр */
    UNUSED(index);
    /* Выводим строку на экран */
    printf("%s", arr);
}

