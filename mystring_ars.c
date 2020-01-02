/* A string module: C string manipulation functions.

Functions are declared in mystring.h

Array based implementation */

#include <stdio.h>
#include "mystring.h"
#include <assert.h>

/* Description: See mystring.h */
size_t ms_length(char const str[]) {
    size_t str_length;

    assert(str);

    /* copy all characters except null */
    str_length = 0U;
    while (str[str_length]) {
        str_length++;
    }

    return str_length;
}

/* Description: See mystring.h */
char *ms_copy(char dest[], char const src[]) {
    size_t i;

    assert(dest);
    assert(src);

    /* copy all characters except null */
    i = 0U;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }

    /* append terminating null character */
    dest[i] = '\0';

    return dest;
}

/* Description: See mystring.h */
char *ms_ncopy(char dest[], char const src[], size_t num) {
    size_t i; 

    assert(dest);
    assert(src);

    /* copy all characters except null and at most num characters */
    i = 0U;
    while (src[i] && i != num) {   
        dest[i] = src[i];
        i++;
    }

    /* write additional null chars if length of src < num */
    while (i != num) {
        dest[i] = '\0';
        i++;
    }

    return dest;
}

/* Description: See mystring.h */
char *ms_concat(char dest[], char const src[]) {
    size_t i, dest_length;

    assert(dest);
    assert(src);

    /* append all characters except null */
    dest_length = ms_length(dest);
    i = 0U;
    while (src[i]) {
        dest[dest_length + i] = src[i];
        i++;
    }

    /* append null character */
    dest[dest_length + i] = '\0';

    return dest;
}

/* Description: See mystring.h */
char *ms_nconcat(char dest[], char const src[], size_t num) {
    size_t i, dest_length;

    assert(dest);
    assert(src);

    /* append all characters except null and at most num characters */
    dest_length = ms_length(dest);
    i = 0U;
    while (src[i] && i != num) {
        dest[dest_length + i] = src[i];
        i++;
    }

    /* append terminating null character */
    dest[dest_length + i] = '\0';

    return dest;
}

/* Description: See mystring.h */
int ms_compare(char const str1[], char const str2[]) {
    size_t i;

    assert(str1);
    assert(str2);

    /* return the difference of the first two different characters */
    i = 0U;
    while(str1[i] && str2[i]) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

/* Description: See mystring.h */
int ms_ncompare(char const str1[], char const str2[], size_t num) {
    size_t i;

    assert(str1);
    assert(str2);

    /* compare at most num characters & return the difference of the
    first two different characters */
    i = 0U;
    while(str1[i] && str2[i] && i != num) { 
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    /* if num characters have been compared, arrays are equal */
    if (i == num) {
        return 0;
    }

    /* else return the difference of the first two different characters */
    return str1[i] - str2[i];
}

/* Description: See mystring.h */
char *ms_search(char const haystack[], char const needle[]) {
    size_t i, j, haystack_length, needle_length;

    assert(haystack);
    assert(needle);
    
    haystack_length = ms_length(haystack);
    needle_length = ms_length(needle);
    if (haystack_length < needle_length) {
        return NULL;
    }

    /* for positions 0 to (haystack_length - needle_length) in haystack */
    for(i = 0U; i <= haystack_length - needle_length; i++) {

        /* search for needle */
        for (j = 0U; j < needle_length; j++) {
            if (haystack[j+i] != needle[j]) {
                break;
            }
        }

        /* needle found if needle_length characters have been searched */
        if (j == needle_length) {
            return (char *) &haystack[i];
        }
    }
    
    return NULL;
}