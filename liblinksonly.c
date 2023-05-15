#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char findlink(char line[])
{
    int OneCounter = 0, TwoCounter = 0, MatchesCount = 0;

    char href[6] = {'h', 'r', 'e', 'f', '=', '"'};

    for(OneCounter = 0; OneCounter < strlen(line); ++OneCounter)
    {
        //:-(
    }
    printf("\n");
}

void links(const char *in)
{
    const int BUFF_SIZE = 512;

    FILE *InputFile, *OutputFile;

    int counter = 0;

    char line[BUFF_SIZE], *word = NULL;

    if(!(InputFile = fopen(in, "r")))
    {
        printf("Не удалось открыть файл %s\n", in);
        exit(1);
    }
    printf("Файл для преобразования: %s\n", in);

    if(!(OutputFile = fopen("TextOut.txt", "w")))
    {
        printf("Не удалось создать файл: TextOut.txt\n");
        exit(1);
    }

    while((fgets(line, BUFF_SIZE, InputFile)))
    {
        findlink(line);
    }
}