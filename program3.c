#include <stdio.h>
#include <string.h>
#include <ctype.h>


char *keywords[] = {
    "int", "float", "char", "double", "if", "else",
    "for", "while", "return", "void", "break", "continue"
};


int isKeyword(char *word)
{
    int i;
    for (i = 0; i < 12; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}


int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=' ||
            ch == '<' || ch == '>');
}


int isSpecialSymbol(char ch)
{
    return (ch == ';' || ch == ',' || ch == '(' ||
            ch == ')' || ch == '{' || ch == '}' ||
            ch == '[' || ch == ']' || ch == ':');
}


int main()
{
    char str[500];
    int i = 0;

    printf("Enter C source code:\n");
    fgets(str, sizeof(str), stdin);

    printf("\n--- Lexical Analysis ---\n");

    while (str[i] != '\0')
    {
        
        if (isspace((unsigned char)str[i]))
        {
            i++;
            continue;
        }

        
        if (isalpha((unsigned char)str[i]) || str[i] == '_')
        {
            char word[50];
            int j = 0;
            while (isalnum((unsigned char)str[i]) ||
                   str[i] == '_')
            {
                word[j++] = str[i++];
            }
            word[j] = '\0';
            if (isKeyword(word))
                printf("%s -> Keyword\n", word);
            else
                printf("%s -> Identifier\n", word);
        }

        
        else if (isdigit((unsigned char)str[i]))
        {
            char number[50];
            int j = 0;
            int decimal = 0;

            while (isdigit((unsigned char)str[i]) || str[i] == '.')
            {
                if (str[i] == '.')
                    decimal++;
                number[j++] = str[i++];
            }

            number[j] = '\0';
            if (decimal <= 1)
                printf("%s -> Constant\n", number);
            else
                printf("%s -> Invalid constant\n", number);
        }

      
        else if (isOperator(str[i]) || str[i] == '!' ||
                 str[i] == '&' || str[i] == '|')
        {
            char op[3];
            op[0] = str[i];
            op[1] = '\0';

           
            if ((str[i] == '=' && str[i+1] == '=') ||
                (str[i] == '!' && str[i+1] == '=') ||
                (str[i] == '<' && str[i+1] == '=') ||
                (str[i] == '>' && str[i+1] == '=') ||
                (str[i] == '+' && str[i+1] == '+') ||
                (str[i] == '-' && str[i+1] == '-') ||
                (str[i] == '&' && str[i+1] == '&') ||
                (str[i] == '|' && str[i+1] == '|'))
            {
                op[1] = str[i+1];
                op[2] = '\0';
                i += 2;
            }
            else
            {
                i++;
            }
            printf("%s -> Operator\n", op);
        }

        
        else if (isSpecialSymbol(str[i]))
        {
            printf("%c -> Special symbol\n", str[i]);
            i++;
        }

        
        else
        {
            printf("%c -> Unknown symbol\n", str[i]);
            i++;
        }
    }
    return 0;
}
?
