/* A string module: C string manipulation functions.

Pointer based implementation */

#include <stdio.h>
#include "mystring.h"
#include <assert.h>


/* Calculates the length of the character array str, excluding
the terminating null character.

Checks: whether array is NULL at runtime.

Parameters:
str: character array. Must end with null char.

Returns: length of str */
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


/* Copies the character array src to the character array dest. Size of dest
must be large enough to receive the copy or else the behavior is undefined. 

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char.
dest: destination array to copy to.

Returns: pointer to destination array dest */
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


/* Copies at most num chars from the character array src to the character
array dest. If there is no
null character among the first num characters of src, dest will not be
null-terminated. If length of src is less than num, the function writes
additional null characters to dest to ensure that a total of num characters
are written. Size of dest must be large enough to receive the copy or else
the behavior is undefined.

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char if its
length <= num.
dest: destination character array to copy to.
num: number of characters.

Returns: pointer to destination array dest */
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


/* Appends the character array src to the character array dest.
It overwrites the terminating null character of src and adds a terminating
null character at the end of dest. Size of dest must be large enough to hold
the contents of both src and dest or else the behavior is undefined.

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char.
dest: destination array to append to. Must end with null char.

Returns: pointer to destination array dest */
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


/* Appends at most num characters from the character array src
string to the character array dest. It overwrites the terminating null
character of src and adds a terminating null character at the end of dest.
Size of dest must be large enough to hold the contents of both src and
dest or else the behavior is undefined.

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char if its
length <= num.
dest: destination character array to append to. Must end with null char.
num: number of characters.

Returns: pointer to destination array dest */
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


/* Compares character arrays str1 and str2.

Checks: whether both arrays are NULL at runtime.

Parameters:
str1: character array. Must end with null char.
str2: character array. Must end with null char if
      (length of str2 < length of str1)

Returns:
- An integer < 0 if str1 < str2
- 0 if str1 = str2
- An integer > 0 if str1 > str2 */
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


/* Compares the first num characters of character arrays str1 and str2.

Checks: whether both arrays are NULL at runtime.

Parameters:
str1: character array. Must end with null char if
      (length of str1 <= num)
str2: character array. Must end with null char if
      (length of str2 < length of str1 && length of str2 <= num)

Returns:
- An integer < 0 if str1 < str2
- 0 if str1 = str2
- An integer > 0 if str1 > str2 */
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


/* Finds the first occurence of the character array needle
in the character array haystack. The terminating null characters are not
compared.

Checks: whether both arrays are NULL at runtime.

Parameters:
haystack: character array. Must end with null char.
needle: character array. Must end with null char.

Returns: if needle is found a pointer to it, else NULL */
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