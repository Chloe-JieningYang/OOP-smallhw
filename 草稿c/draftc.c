#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(int argc, char* argv[])
{
    FILE* fout, * fin;

    fout = fopen("out.txt", "w");
    fprintf(fout, "ABC\x1\x2\xff\t\v\b\175()-=def\n");
    fclose(fout);

    fin = fopen("out.txt", "r");
    int c = 0;
    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        c++;
    }
    printf("%d\n", c);
    fclose(fin);

    return 0;
}
