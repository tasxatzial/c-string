/* A string module: C string manipulation functions.

Functions are declared in mystring.h

Pointer based implementation */

#include <stdio.h>
#include "mystring.h"
#include <assert.h>

/* Description: See mystring.h */
size_t ms_length(char const *str) {
    char const *str_ptr;
    
    assert(str);

    /* copy all characters except null */
    str_ptr = str;
    while (*str_ptr) {
        str_ptr++;
    }

    return str_ptr - str;
}

/* Description: See mystring.h */
char *ms_copy(char *dest, char const *src) {
    char const *src_ptr;
    char *dest_ptr;

    assert(dest);
    assert(src);

    /* copy all characters except null */
    src_ptr = src;
    dest_ptr = dest;
    while (*src_ptr) {
        *dest_ptr++ = *src_ptr++;
    }

    /* append terminating null character */
    *dest_ptr = '\0';

    return dest;
}

/* Description: See mystring.h */
char *ms_ncopy(char *dest, char const *src, size_t num) {
    char const *src_ptr;
    char *dest_ptr;

    assert(dest);
    assert(src);

    src_ptr = src;
    dest_ptr = dest;
    
    /* copy all characters except null and at most num characters */
    while (*src_ptr && (src_ptr - src) != num) {
        *dest_ptr++ = *src_ptr++;
    }

    /* write additional null chars if length of src < num */
    while (src_ptr - src != num) {
        *dest_ptr++ = '\0';
        src_ptr++;
    }

    return dest;
}

/* Description: See mystring.h */
char *ms_concat(char *dest, char const *src) {
    char const *src_ptr;
    char *dest_ptr;
    
    assert(dest);
    assert(src);

    /* append all characters except null */
    dest_ptr = &dest[ms_length(dest)];
    src_ptr = src;
    while (*src_ptr) {
        *dest_ptr++ = *src_ptr++;
    }

    /* append terminating null character */
    *dest_ptr = '\0';

    return dest;
}

/* Description: See mystring.h */
char *ms_nconcat(char *dest, char const *src, size_t num) {
    char const *src_ptr;
    char *dest_ptr;

    assert(dest);
    assert(src);

    /* append all characters except null and at most num characters */
    src_ptr = src;
    dest_ptr = &dest[ms_length(dest)];
    while (*src_ptr && (src_ptr - src) != num) {
        *dest_ptr++ = *src_ptr++;
    }

    /* append terminating null character */
    *dest_ptr = '\0';

    return dest;
}

/* Description: See mystring.h */
int ms_compare(char const *str1, char const *str2) {
    char const *ptr1, *ptr2;
    
    assert(str1);
    assert(str2);

    /* return the difference of the first two different characters */
    ptr1 = str1;
    ptr2 = str2;
    while(*ptr1 && *ptr2) {
        if (*ptr1 != *ptr2) {
            return *ptr1 - *ptr2;
        }
        ptr1++;
        ptr2++;
    }

    return *ptr1 - *ptr2;
}


/* Description: See mystring.h */
int ms_ncompare(char const *str1, char const *str2, size_t num)
{
    char const *ptr1, *ptr2;
    
    assert(str1);
    assert(str2);
    ptr1 = str1;
    ptr2 = str2;

    /* compare at most num characters & return the difference of the
    first two different characters */
    while(*ptr1 && *ptr2 && (ptr1 - str1) != num) { 
        if (*ptr1 != *ptr2) {
            return *ptr1 - *ptr2;
        }
        ptr1++;
        ptr2++;
    }

    /* else if num characters have been compared, arrays are equal */
    if (ptr1 - str1 == num) {
        return 0;
    }

    /* else return the difference of the first two different characters */
    return *ptr1 - *ptr2;
}

/* Description: See mystring.h */
char *ms_search(char const *haystack, char const *needle) {
    size_t haystack_length, needle_length;
    char const *haystack_ptr;

    assert(haystack);
    assert(needle);

    needle_length = ms_length(needle);
    haystack_length = ms_length(haystack);
    if (haystack_length < needle_length) {
        return NULL;
    }

    /* for every position in haystack */
    haystack_ptr = haystack;
    while(*haystack_ptr) {

        /* compare needle to haystack that begins from haystack_ptr
           and has length = needle_length */
        if (!ms_ncompare(haystack_ptr, needle, needle_length)) {
            return (char *) haystack_ptr;
        }
        haystack_ptr++;
    }

    return NULL;
}