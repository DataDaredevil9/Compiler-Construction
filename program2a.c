#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];
    printf("Enter a line of code : ");
    fgets(line, sizeof(line), stdin);

    if (strncmp(line, "#define", 7) == 0)
    {
        printf("Macro definition Identified.\n");
    }
    else
    {
        printf("Macro definition not found.\n");
    }
    return 0;
}
