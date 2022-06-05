#include<stdio.h>
#include<stdlib.h>

char* inputString() {

    char ch;
    int i = 0;
    char *str = NULL;

    while(1) {

        ch = getc(stdin);

        if (ch == '\n') 
            break;

        str = realloc(str, i + 1);
        *(str + i) = ch;
        i++;

    } // end of while loop

    str = realloc(str, i + 1);
    *(str + i) = '\0';

    return str;
} // end of inputString()

void displayString(char *str) {
    
    int i = 0;
    char ch = *(str + i);

    while (ch != '\0') {
        printf("%c", ch);
        ch = *(str + ++i);
    } // end of while loop

} // end of displayString(char*)


int main() {

    printf("Enter string: ");
    char *s = inputString();

    printf("Entered string is: ");
    displayString(s);
    printf("\n");

    return 0;
} // end of main()
