/* A string module: C string manipulation functions.

Array based implementation */

#include <stdio.h>
#include "mystring.h"
#include <assert.h>


/* Calculates the length of the character array str, excluding
the terminating null character.

Checks: whether array is NULL at runtime.

Parameters:
str: character array. Must end with null char.

Returns: length of str */
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


/* Copies the character array src to the character array dest. Size of dest
must be large enough to receive the copy or else the behavior is undefined. 

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char.
dest: destination array to copy to.

Returns: pointer to destination array dest */
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


/* Appends the character array src to the character array dest.
It overwrites the terminating null character of src and adds a terminating
null character at the end of dest. Size of dest must be large enough to hold
the contents of both src and dest or else the behavior is undefined.

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char.
dest: destination array to append to. Must end with null char.

Returns: pointer to destination array dest */
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


/* Finds the first occurence of the character array needle
in the character array haystack. The terminating null characters are not
compared.

Checks: whether both arrays are NULL at runtime.

Parameters:
haystack: character array. Must end with null char.
needle: character array. Must end with null char.

Returns: if needle is found a pointer to it, else NULL */
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