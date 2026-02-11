/* 
 * GovnoLang — кириллический C для настоящих богатырей
 * Copyright © 2026 Богдан <mindyster2009@gmail.ru>
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

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
#define мерило          size_t

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
#define чё              argv
#define дохуя           argc

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
#define двойное_число_из_строки(x)    strtod(x, НОЛЬ)
#define двойное_число_из_строки_полный(x, endptr) strtod(x, endptr)
#define число_из_строки(x)         atoi(x)

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
#define кубический_корень(x)    cbrt(x)
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
#define Главный_Ответ       42
#define Главный_Вопрос      "ПРОИЗВЕДЕНИЕ ШЕСТИ И СЕМИ"

// ========== Директивы препроцессора ==========
#define включить            #include
#define определить          #define
#define если_не_определено  #ifndef
#define конец_если          #endif

// ============================================================================
// Богатырская утилита — полезные макросы с русской душой
// ============================================================================

// ----- 1. Размер массива: «Сколько в стае?» ---------------------------------
#define СКОЛЬКО_В_СТАЕ(arr) (sizeof(arr) / sizeof((arr)[0]))

// ----- 2. Минимум и максимум: «Кто больше?», «Кто меньше?» ------------------
#define КТО_БОЛЬШЕ(a, b)  ((a) > (b) ? (a) : (b))
#define КТО_МЕНЬШЕ(a, b)  ((a) < (b) ? (a) : (b))

// ----- 3. Бесконечный цикл с уважением: «Пока не перестану» ----------------
#define ПОКА_НЕ_ПЕРЕСТАНУ while (1)

// ----- 4. Отладочная печать: «Базарить, если не лень» ----------------------
#ifdef _РЕЖИМ_БОГАТЫРЯ
    #define БАЗАРИТЬ_ЕСЛИ_НЕ_ЛЕНЬ(fmt, ...) \
        базарить("[%s:%s:%d] " fmt, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
    #define БАЗАРИТЬ_ЕСЛИ_НЕ_ЛЕНЬ(fmt, ...) /* тишина в поле */
#endif

// ----- 5. Жёсткая проверка: «Иди отсюда, недостойный!» ---------------------
#define ИДИ_ОТСЮДА(условие, сообщение) \
    do { \
        если (условие) { \
            ошибка("НЕДОПУСТИМО: %s (%s:%d)\n", сообщение, __FILE__, __LINE__); \
            ошибка("Иди отсюда, недостойный!\n"); \
            вернуть -1; \
        } \
    } while (0)

// ----- 6. Экспериментальный код: «Перун, разреши!» -------------------------
#ifdef _ЭКСПЕРИМЕНТЫ_РАЗРЕШЕНЫ
    #define ЭКСПЕРИМЕНТАЛЬНО(блок) блок
#else
    #define ЭКСПЕРИМЕНТАЛЬНО(блок) /* молись, что работает */
#endif

// ----- 7. Богатырский профайлер: «Засечь время» ----------------------------
#include <time.h>  // для clock_t, clock(), CLOCKS_PER_SEC
#define ЗАСЕЧЬ_ВРЕМЯ(блок) \
    do { \
        clock_t старт = clock(); \
        { блок; } \
        clock_t конец = clock(); \
        базарить("Времени ушло: %.2f секунд богатырских\n", \
                 (double)(конец - старт) / CLOCKS_PER_SEC); \
    } while (0)

// ----- 8. Подстраховка: «На всякий случай» --------------------------------
#define НАВСЯКИЙ_СЛУЧАЙ(var, val) var = (val)

// ----- 9. Успешное завершение: «Свершилось!» ------------------------------
#define СВЕРШИЛОСЬ вернуть 0

// ----- 10. Сохранение и восстановление: «Бекап» ---------------------------
#define БЕКАП(var)     сохранённая_##var = (var)
#define ВОССТАНОВИТЬ(var) (var) = сохранённая_##var

// ----- 11. Перебор элементов массива: «Перебрать дружину» -----------------
#define ПЕРЕБРАТЬ(тип, элемент, массив, действие) \
    do { \
        тип* _ptr = (массив); \
        мерило _n = СКОЛЬКО_В_СТАЕ(массив); \
        for (мерило _i = 0; _i < _n; ++_i) { \
            тип элемент = _ptr[_i]; \
            действие; \
        } \
    } while (0)

// ----- 12. Прощальный return: «До свидания» -------------------------------
#define ДО_СВИДАНИЯ(код) \
    do { \
        базарить("Программа завершена. Славься Русь!\n"); \
        вернуть (код); \
    } while (0)

// ----- 13. Маркер недоработанного кода: «Это не баг, а фича» --------------
#ifndef _НИКАКИХ_ОПРАВДАНИЙ
    #define ЭТО_НЕ_БАГ_А_ФИЧА /* гордость разработчика */
#else
    #define ЭТО_НЕ_БАГ_А_ФИЧА /* ладно, баг, но мы это не обсуждаем */
#endif

// ----- 14. Индикатор прогресса: «Сколько осталось?» -----------------------
#define ПРОГРЕСС(текущий, общий, шаг) \
    do { \
        статический число _прошлый_процент = -1; \
        число _процент = (число)(((текущий) * 100) / (общий)); \
        если (_процент / (шаг) != _прошлый_процент / (шаг)) { \
            базарить(" [%d%%] ", _процент); \
            fflush(ВЫВОД); \
            _прошлый_процент = _процент; \
        } \
    } while (0)

// ============================================================================
// Конец богатырской утилиты
// ============================================================================

// ============================================================================
// Опциональные расширения для работы с популярными библиотеками
// Активируются определением соответствующих макросов перед #include "govno.h"
// ============================================================================

// ----------------------------------------------------------------------------
// 1. libcurl — «Позвать_за_море» (сетевые челобитные)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_CURL
    #include <curl/curl.h>

    #define Гонец                CURL
    #define ПОЗВАТЬ_ЗА_МОРЕ     curl_easy_init
    #define БАЗАРИТЬ_ЗА_МОРЕ    curl_easy_setopt
    #define СЛАТЬ_ЧЕЛОБИТНУЮ    curl_easy_perform
    #define ОТВЕТ_БАСУРМАНА     curl_easy_getinfo
    #define ОТПУСТИТЬ_ГОНЦА     curl_easy_cleanup

    #define КОД_ЧЕСТИ           CURLE_OK
    #define ХОРОШО              CURLOPT_URL
    #define ПИСЬМО              CURLOPT_WRITEDATA
#endif

// ----------------------------------------------------------------------------
// 2. SQLite — «Летопись_камней» (каменные скрижали)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_SQLITE
    #include <sqlite3.h>

    #define летопись_камней     sqlite3
    #define открыть_камень      sqlite3_open
    #define высечь_слова        sqlite3_exec
    #define спросить_у_камня    sqlite3_prepare_v2
    #define шагнуть_к_камню     sqlite3_step
    #define прочесть_знак       sqlite3_column_text
    #define закрыть_камень      sqlite3_close
    #define грехи_камня         sqlite3_errmsg
#endif

// ----------------------------------------------------------------------------
// 3. OpenSSL — «Перунов_щит» (богатырская криптография)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_OPENSSL
    #include <openssl/ssl.h>
    #include <openssl/err.h>

    #define перунов_щит         SSL_CTX_new
    #define опоясаться_щитом    SSL_new
    #define рукопожатие_с_Перуном SSL_connect
    #define шептать_молитву     SSL_write
    #define внимать_откровению  SSL_read
    #define сложить_щит         SSL_free
    #define гром_Перуна         ERR_print_errors_fp
#endif

// ----------------------------------------------------------------------------
// 4. libpng / libjpeg — «Иконопись» (святые образы)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_LIBPNG
    #include <png.h>

    #define икона               png_image
    #define прочесть_икону      png_image_begin_read_from_file
    #define явить_икону         png_image_finish_read
    #define помолиться_иконе    png_image_free
#endif

#ifdef GOVNO_USE_LIBJPEG
    #include <jpeglib.h>

    #define лик                 jpeg_decompress_struct
    #define открыть_лик         jpeg_std_error
    #define узреть_лик          jpeg_read_header
    #define явить_лик           jpeg_start_decompress
    #define воздать_почести     jpeg_destroy_decompress
#endif

// ----------------------------------------------------------------------------
// 5. SDL2 — «Скоморошья_потеха» (народные гуляния)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_SDL2
    #include <SDL2/SDL.h>

    #define балаган             SDL_Init
    #define скоморох            SDL_CreateWindow
    #define рисовальщик         SDL_CreateRenderer
    #define намалевать          SDL_RenderCopy
    #define явить_миру          SDL_RenderPresent
    #define разойтись_по_домам  SDL_Quit
    #define весточка           SDL_PollEvent
#endif

// ----------------------------------------------------------------------------
// 6. FFmpeg — «Вещий_баян» (сказитель видео и аудио)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_FFMPEG
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>

    #define вещий_баян          avformat_open_input
    #define найти_сказителя     avformat_find_stream_info
    #define баять_кадрами       av_read_frame
    #define козлик              avcodec_send_packet
    #define плясун              avcodec_receive_frame
    #define отпустить_баяниста  avformat_close_input
#endif

// ----------------------------------------------------------------------------
// 7. json-c — «Челобитная_в_тереме» (боярские грамоты)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_JSONC
    #include <json-c/json.h>

    #define грамота             json_tokener_parse
    #define зачитать_свиток     json_object_get_string
    #define добро_боярское      json_object_new_object
    #define приписать_перстом   json_object_object_add
    #define сжечь_свиток        json_object_put
#endif

// ----------------------------------------------------------------------------
// 8. libgit2 — «Родословная_кода» (вековые летописи)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_LIBGIT2
    #include <git2.h>

    #define родословная         git_repository_open
    #define добавить_в_род      git_index_add_bypath
    #define подписать_кровью    git_commit_create
    #define чернила             git_signature_now
    #define предать_забвению    git_reset
    #define родной_край         git_repository_path
#endif

// ----------------------------------------------------------------------------
// 9. ncurses — «Терем_расписной» (палатные интерфейсы)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_NCURSES
    #include <ncurses.h>

    #define палаты              initscr
    #define наличник            printw
    #define оконце              newwin
    #define весточка            getch
    #define свернуть_ставни     endwin
    #define краска              start_color
    #define узор                init_pair
#endif

// ----------------------------------------------------------------------------
// 10. zlib — «Сундук_с_добром» (берестяное сжатие)
// ----------------------------------------------------------------------------
#ifdef GOVNO_USE_ZLIB
    #include <zlib.h>

    #define сундук              compress
    #define отворить_сундук     uncompress
    #define набить_сундук       deflate
    #define вытряхнуть          inflate
    #define проверить_добро     crc32
#endif

// ============================================================================
// Конец опциональных расширений
// ============================================================================

#endif // GOVNO_H
