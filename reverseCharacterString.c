#include <stdio.h>  
#include <string.h>

int main()  
{  
    char str[50];
    printf (" \n Enter character string of maximum 50 characters to be reversed: ");  
    scanf ("%s", str);  

    printf (" \n The output reversed string is: %s ", strrev(str));  
    return 0;  
}  
