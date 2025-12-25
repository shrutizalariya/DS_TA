// Vowel Anxiety Problem 
// Utkarsh has recently started taking English-language classes to improve his 
// reading and writing skills. However, he is still struggling to learn English. His 
// teacher gave him the following problem to improve his vowel-identification 
// skills: 
// There is a string S of length N consisting of lowercase English letters only. 
// Utkarsh has to start from the first letter of the string. 
// Each time he encounters a vowel; he has to reverse the entire substring that 
// came before the vowel. 
// Utkarsh needs help verifying his answer. Can you print the final string after 
// performing all the operations for him? 
 
// Input Format: 
// • First line will contain T, number of test cases. Then T test cases follow. 
// • The first line of each test case contains N, the length of the string. 
// • The second line contains S, the string itself. 
 
// Output Format: 
// For each test case, output in a single line the final string after traversing S from 
// Left to right and performing the necessary reversals. 
 
// Sample Example: 
// Input: 
// 2 
// 10 
// abcdefghij 
// 7 
// bcadage 
 
// Output: 
// hgfeabcdij 
// gacbade 
 
 
#include <stdio.h> 
#include <string.h> 
 
#define MAX 1000 
 
int isVowel(char ch) { 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
} 
void reversePrefix(char str[], int index) { 
    int start = 0; 
    int end = index - 1; 
    char temp; 
 
    while (start < end) { 
        temp = str[start]; 
        str[start] = str[end]; 
        str[end] = temp; 
        start++; 
        end--; 
    } 
} 
 
int main() { 
    int T, j=1; 
    printf("Enter number of test cases: "); 
    scanf("%d", &T); 
 
    while (j<=T) { 
        int N; 
        char S[MAX]; 
 
        printf("Enter length of string: "); 
        scanf("%d", &N); 
        printf("Enter the string: "); 
        scanf("%s", S); 
 
        for (int i = 0; i < N; i++) { 
            if (isVowel(S[i])) { 
                reversePrefix(S, i); 
            } 
        } 
 
        printf("Final String: %s\n", S); 
        j++; 
    } 
 
    return 0; 
}