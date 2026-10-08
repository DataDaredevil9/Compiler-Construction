#include <stdio.h>
#include <string.h>

int main()
{
    char *program[] = {
        "START MACRO",
        "MOV A, B",
        "ADD A, C",
        "MEND",
        "DISPLAY MACRO",
        "MOV R1, R2",
        "MEND",
        "END"
    };
    int i;

    printf("Macro definition Identified \n");
    printf("-------------------------\n");
    for (i = 0; strcmp(program[i], "END") != 0; i++)
    {
        if (strstr(program[i], "MACRO") != NULL)
        {
            printf("%s\n", program[i]);
        }
    }
    return 0;
}
?
