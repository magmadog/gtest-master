#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text/text.h"
#include "text/_text.h"
#include "common.h"

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;

    /* Создаем объект для представления текста */
    text txt = create_text();
    /* Цикл обработки команд */
    while (1) {
        printf("ed> ");

        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }
        /* Загружаем содержимое файла, заданного параметром */
	
          if (strcmp(cmd, "load") == 0) {
                   if ((arg = strtok(NULL, " \n")) == NULL) {
                       fprintf(stderr, "Usage: load filename\n");
                   } else {
                       load(txt, arg);
                   }
                   continue;
               }
               /* Завершаем работу редактора */
                      if (strcmp(cmd, "quit") == 0) {
                          fprintf(stderr, "Bye!\n");
                          break;
                      }
	       /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
	    if(tracer(txt, 0) != NULL)
		show(txt);
	    else
		fprintf(stderr, "No file\n");
            continue;
        }
        /* Выводим строку до  курсора*/
        if (strcmp(cmd, "plb") == 0) {
                        if(tracer(txt, 0) != NULL)
                                plb(txt);
                        else
                                fprintf(stderr, "No file\n");

                    continue;
                }

        /* Разделяет строку с курсором */
        if (strcmp(cmd, "s") == 0) {
            if(tracer(txt, 0) != NULL)
                s(txt);
            else
                fprintf(stderr, "No file\n");

            continue;
        }

        /* Разделяет строку с курсором */
        if (strcmp(cmd, "s") == 0) {
            if(tracer(txt, 0) != NULL)
                s(txt);
            else
                fprintf(stderr, "No file\n");

            continue;
        }


    }
    return 0;

}

