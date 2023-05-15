#include<stdio.h>
#include<string.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
    void *LibHandler;
    void (*func) (const char *);

    char *logo = "\n"
" _______  _______  _______  ___   _  __   __  _______  __   __  ___     \n"
"|       ||       ||       ||   | | ||  | |  ||       ||  |_|  ||   |    \n"
"|  _____||    ___||    ___||   |_| ||  |_|  ||_     _||       ||   |    \n"
"| |_____ |   |___ |   |___ |      _||       |  |   |  |       ||   |    \n"
"|_____  ||    ___||    ___||     |_ |       |  |   |  |       ||   |___ \n"
" _____| ||   |___ |   |___ |    _  ||   _   |  |   |  | ||_|| ||       |\n"
"|_______||_______||_______||___| |_||__| |__|  |___|  |_|   |_||_______|\n";
    puts(logo);

    if(argc != 3)
    {
        printf("Невереное количество аргументов.\n");
        printf("SEEKHTML\n\tПример использования:./seekhtml <плагин> <файл для преобразования>\nПЛАГИНЫ\n\text - удаляет все теги из файла\n\theaders - выводит список заголовков\n\tlinks - выводит список ссылок\n\n");
        return 1;
    }
    if(!(strcmp(argv[1], "text")))
    {
        LibHandler = dlopen("./libhtmlconvert.so", RTLD_LAZY);
        if(!(LibHandler))
        {
            fprintf(stderr, "dlopen() error: %s\n", dlerror());
            return 1;
        }
        func = dlsym(LibHandler, "text");
        if((func))
            func(argv[2]);
        dlclose(LibHandler);

    }else if(!(strcmp(argv[1], "headers")))
    {
        LibHandler = dlopen("./libhtmlconvert.so", RTLD_LAZY);
        if(!(LibHandler))
        {
            fprintf(stderr, "dlopen() error: %s\n", dlerror());
            return 1;
        }
        func = dlsym(LibHandler, "headers");
        if((func))
            func(argv[2]);
        dlclose(LibHandler);
    }else if(!(strcmp(argv[1], "links")))
    {
        LibHandler = dlopen("./libhtmlconvert.so", RTLD_LAZY);
        if(!(LibHandler))
        {
            fprintf(stderr, "dlopen() error: %s\n", dlerror());
            return 1;
        }
        func = dlsym(LibHandler, "links");
        if((func))
            func(argv[2]);
        dlclose(LibHandler);
    }


    return 0;
}