//Replace lowercase with uppercase and vice versa in a string  
 
//Method 1: Using ctype.h 
 
#include <stdio.h> 
#include <ctype.h> 
 
int main() { 
    char str[100]; 
    printf("Enter a string: "); 
    gets(str); 
 
    for(int i = 0; str[i] != '\0'; i++) { 
        if(islower(str[i])) 
            str[i] = toupper(str[i]); 
        else if(isupper(str[i])) 
            str[i] = tolower(str[i]); 
    } 
 
    printf("Modified string: %s", str); 
    return 0; 
} 
 
//Method 2: Manual ASCII manipulation 
 
#include <stdio.h> 
 
int main() { 
    char str[100]; 
    printf("Enter a string: "); 
    gets(str); 
 
    for(int i = 0; str[i] != '\0'; i++) { 
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] = str[i] - 32; 
        else if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] = str[i] + 32; 
    } 
 
    printf("Modified string: %s", str); 
    return 0; 
}