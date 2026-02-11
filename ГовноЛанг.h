// GovnoLang: кириллический C для настоящих богатырей
#ifndef GOVNO_H
#define GOVNO_H

// ========== Базовые переопределения ==========
#define символ          char
#define число           int
#define длинное_число   long
#define очень_длинное   long long
#define число_с         float
#define двойное_число   double
#define буква           char
#define строка          char*
#define ничего          void
#define структура       struct
#define перечисление    enum
#define объединение     union
#define не_меняется     const
#define статический     static

// ========== Управление ==========
#define главная         main
#define если            if
#define иначе           else
#define иначе_если      else if
#define перебор         for
#define повторять       while
#define делай           do
#define выбор           switch
#define вариант         case
#define по_умолчанию    default
#define вернуть         return
#define идтидо          goto
#define продолжить      continue
#define иди_нахуй       break

// ========== Ввод-вывод (printf/scanf семья) ==========
#include <stdio.h>
#define базарить(fmt, ...)    printf(fmt, ##__VA_ARGS__)
#define спросить(fmt, ...)    scanf(fmt, ##__VA_ARGS__)
#define ошибка(fmt, ...)      fprintf(stderr, fmt, ##__VA_ARGS__)
#define символ_взять()        getchar()
#define символ_дать(ch)       putchar(ch)
#define строка_взять(s, n)    fgets(s, n, stdin)
#define строка_дать(s)        fputs(s, stdout)

// ========== Файловые операции ==========
#define файл            FILE
#define открыть_файл    fopen
#define закрыть_файл    fclose
#define читать_файл     fread
#define писать_файл     fwrite
#define строка_из_файла fgets
#define строка_в_файл   fputs
#define символ_из_файла fgetc
#define символ_в_файл   fputc
#define формат_в_файл   fprintf
#define формат_из_файла fscanf
#define конец_файла     feof
#define ошибка_файла    ferror

// ========== Память ==========
#include <stdlib.h>
#define выделить(sz)            malloc(sz)
#define выделить_массив(n, sz)  calloc(n, sz)
#define перевыделить(ptr, sz)   realloc(ptr, sz)
#define освободить(ptr)         free(ptr)

// ========== Строки ==========
#include <string.h>
#define длина_строки(s)         strlen(s)
#define скопировать_строку(dst, src) strcpy(dst, src)
#define скопировать_часть(dst, src, n) strncpy(dst, src, n)
#define соединить_строки(dst, src) strcat(dst, src)
#define сравнить_строки(a, b)   strcmp(a, b)
#define найти_символ(s, c)      strchr(s, c)
#define найти_строку(s, sub)    strstr(s, sub)
#define разбить_строку(s, sep)  strtok(s, sep)
#define перевернуть_строку(s)   strrev(s)  // нестандарт, но многие любят

// ========== Математика ==========
#include <math.h>
#define модуль(x)               ((x) < 0 ? -(x) : (x))
#define корень(x)               sqrt(x)
#define синус(x)                sin(x)
#define косинус(x)              cos(x)
#define тангенс(x)              tan(x)
#define арксинус(x)             asin(x)
#define арккосинус(x)           acos(x)
#define арктангенс(x)           atan(x)
#define степень(x, y)           pow(x, y)
#define экспонента(x)           exp(x)
#define логарифм(x)             log(x)
#define логарифм10(x)           log10(x)
#define округлить_вниз(x)       floor(x)
#define округлить_вверх(x)      ceil(x)
#define случайное()            rand()
#define посев_случайного(s)    srand(s)

// ========== Преобразования ==========
#define текст_в_число(s)       atoi(s)
#define текст_в_длинное(s)     atol(s)
#define текст_в_дробное(s)     atof(s)
#define число_в_текст(n, buf)  sprintf(buf, "%d", n)
#define дробное_в_текст(f, buf) sprintf(buf, "%f", f)

// ========== Константы ==========
#define ИСТИНА              1
#define ЛОЖЬ                0
#define НОЛЬ                NULL
#define КОНЕЦ_ФАЙЛА         EOF
#define ВВОД                stdin
#define ВЫВОД               stdout
#define ОШИБКА              stderr

// ========== Директивы препроцессора ==========
#define включить            #include
#define определить          #define
#define если_не_определено  #ifndef
#define конец_если          #endif

#endif // GOVNO_H