/* A string module: C string manipulation functions */

#include <stdio.h>


/* Calculates the length of the character array str, excluding
the terminating null character.

Checks: whether array is NULL at runtime.

Parameters:
str: character array. Must end with null char.

Returns: length of str */
size_t ms_length(const char *str);


/* Copies the character array src to the character array dest. Size of dest
must be large enough to receive the copy or else the behavior is undefined. 

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char.
dest: destination array to copy to.

Returns: pointer to destination array dest */
char *ms_copy(char *dest, const char *src);


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
char *ms_ncopy(char *dest, const char *src, size_t num);


/* Appends the character array src to the character array dest.
It overwrites the terminating null character of src and adds a terminating
null character at the end of dest. Size of dest must be large enough to hold
the contents of both src and dest or else the behavior is undefined.

Checks: whether both arrays are NULL at runtime.

Parameters:
src: source character array to copy from. Must end with null char.
dest: destination array to append to. Must end with null char.

Returns: pointer to destination array dest */
char *ms_concat(char *dest, const char *src);


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
char *ms_nconcat(char *dest, const char *src, size_t num);


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
int ms_compare(const char *str1, const char *str2);


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
int ms_ncompare(const char *str1, const char *str2, size_t num);


/* Finds the first occurence of the character array needle
in the character array haystack. The terminating null characters are not
compared.

Checks: whether both arrays are NULL at runtime.

Parameters:
haystack: character array. Must end with null char.
needle: character array. Must end with null char.

Returns: if needle is found a pointer to it, else NULL */
char *ms_search(const char *haystack, const char *needle);