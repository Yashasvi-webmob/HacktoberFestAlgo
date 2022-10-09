#include <stdio.h>  
#include <string.h>

int main()  
{  
    char str[50];
    printf (" \n Enter string to be reversed: ");  
    scanf ("%s", str);  
      
    printf (" \n Reversed string is: %s ", strrev(str));  
    return 0;  
}  
