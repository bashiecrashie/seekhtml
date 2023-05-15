#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char findheader(char line[], int strings)
{
    int OneCounter = 0, TwoCounter = 0, ThreeCouter = 0, FirstIndex = 0, SecondIndex = 0;

    char numbers[6] = {'1', '2', '3', '4', '5', '6'};

    for(OneCounter = 0; OneCounter < strlen(line); ++OneCounter)
    {
        if(line[OneCounter] == '<' && line[OneCounter + 1] == 'h')
        {
            for(TwoCounter = 0; TwoCounter < 5; ++TwoCounter)
                if(line[OneCounter + 2] == numbers[TwoCounter] && line[OneCounter + 3] == '>')
                    printf("Строка: %d Найден тег заголовка: %c%c%c%c\n", strings, line[OneCounter], line[OneCounter + 1], line[OneCounter + 2],  line[OneCounter + 3]);
        }

    }

}

void headers(const char *in)
{
    FILE *InputFile;

    int counter = 0, strings = 0;

    const int BUFF_SIZE = 512;

    char line[BUFF_SIZE], *word;

    char headers[10][5] = {"<h1>", "</h1>", "<h2>", "</h2>", "<h3>", "</h3>", "<h4>", "</h5>", "<h6>", "</h6>"};

    if(!(InputFile = fopen(in, "r")))
    {
        printf("Не удалось открыть файл %s\n", in);
        exit(1);
    }
    printf("Входящий файл: %s\n", in);

    while((fgets(line, BUFF_SIZE, InputFile)))
    {
            ++strings;
            findheader(line, strings);
    }

}