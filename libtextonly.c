#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int BUFF_SIZE = 512;

char *removetag(char line[])
{
    char *out = NULL, clrline[BUFF_SIZE];

    int OneCounter = 0, TwoCounter = 0, FirstIndex = 0, SecondIndex = 0;

    for(OneCounter = 0; OneCounter < strlen(line); ++OneCounter)
    {
        if(line[OneCounter] == '<')
            FirstIndex = OneCounter;
        
        if(line[OneCounter] == '>')
            SecondIndex = OneCounter;

        for(TwoCounter = FirstIndex; TwoCounter < SecondIndex + 1; ++TwoCounter)
        {
            line[TwoCounter] = ' ';
        }
    }

    out = line;

    return out;

}

void text(const char *in)
{
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
    printf("Файл для записи результатов преобразования: TextOut.txt\n");

    while((fgets(line, BUFF_SIZE, InputFile)))
    {
        word = removetag(line);

        fprintf(OutputFile, "%s", word);
    }
}