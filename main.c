/* Test file for the string module.

Functions are declared in mystring.h */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"


void test_ms_copy() {
    char s1[] = "this";
    char s2[] = "this";
    char s3[] = "that";

    char *a, *b;

    a = ms_copy(s1, s3);
    b = strcpy(s2, s3); /* string.h */
    if (strcmp(a, b)) {
        printf("%s %s\n", a, b);
    }
}

void test_ms_length() {
    char s1[] = "this";

    int s1_len1 = ms_length(s1);
    int s1_len2 = strlen(s1); /* string.h */

    if (s1_len1 != s1_len2) {
        printf("%d %d\n", s1_len1, s1_len2);
    }
}

void test_ms_compare() {
    char s1[] = "this";
    char s2[] = "that";

    int a = ms_compare(s1, s2);
    int b = strcmp(s1, s2); /* string.h */

    if (a != b) {
        printf("%d %d\n", a, b);
    }
}

void test_ms_concat() {
    char s1[] = "this";
    char s2[9] = "that";
    char s3[9] = "that";

    char *a = ms_concat(s2, s1);
    char *b = strcat(s3, s1); /* string.h */

    if (strcmp(a, b)) {
        printf("%s %s\n", a, b);
    }
}

void test_ms_search() {
    char s1[] = "Hello there";
    char s2[] = "there";

    char *a = ms_search(s1, s2);
    char *b = strstr(s1, s2); /* string.h */

    if (strcmp(a, b)) {
        printf("%s %s\n",a, b);
    }
}

void test_ms_ncopy() {
    char s1[] = "this";
    char s2[] = "that";
    char s3[] = "that";

    char *a = ms_ncopy(s2, s1, 2);
    char *b = strncpy(s3, s1, 2); /* string.h */

    if (strcmp(a, b)) {
        printf("%s %s\n", a, b);
    }
}

void test_ms_ncompare() {
    char s1[] = "this";
    char s2[] = "that";

    int a = ms_ncompare(s1, s2, 3);
    int b = strncmp(s1, s2, 3); /* string.h */

    if (a != b) {
        printf("%d %d\n", a, b);
    }
}

void test_ms_nconcat() {
    char s1[] = "this";
    char s2[9] = "that";
    char s3[9] = "that";

    char *a = ms_nconcat(s2, s1, 4);
    char *b = strncat(s3, s1, 4); /* string.h */

    if (strcmp(a, b)) {
        printf("%s %s\n", a, b);
    }
}

int main() {
    test_ms_copy();
    test_ms_length();
    test_ms_compare();
    test_ms_concat();
    test_ms_search();
    test_ms_ncopy();
    test_ms_ncompare();
    test_ms_nconcat();

    return 0;
}