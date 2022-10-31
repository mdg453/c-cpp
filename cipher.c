#include "cipher.h"
#include <string.h>
#include <stdio.h>

/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.

// See full documentation in header file
void encode (char s[], int k)
{
    int i = 0 ;
    while (s[i] != '\0'){
        int a = s[i];
        if (a < 123 && a > 96){
            a = a + k ;
            while (a > 122){
                a = a -26 ;
            }
            while (a < 97) {
                a = a + 26;
            }
        }
        else if (a < 91 && a > 63) {
            a = a + k;
            while (a > 90) {
                a = a - 26;
            }
            while (a < 64) {
                a = a + 26;
            }
        }
    char b = a;
    s[i] = b ;
    i++ ;
    }
    printf(s);
}

// See full documentation in header file
void decode (char s[], int k)
{
    int i = 0 ;
    while (s[i] != '\0'){
        int a = s[i];
        if (a < 123 && a > 96){
            a = a - k ;
            while (a > 122){
                a = a -26 ;
            }
            while (a < 97) {
                a = a + 26;
            }
        }
        else if (a < 91 && a > 63) {
            a = a - k;
            while (a > 90) {
                a = a - 26;
            }
            while (a < 64) {
                a = a + 26;
            }
        }
        char b = a;
        s[i] = b ;
        i++ ;
    }
    printf(s);
}
