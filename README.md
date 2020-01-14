# Description

C string manipulation functions, similar to those provided in string.h

The following functions are implemented:

* ms_length(string): get the length of string
* ms_copy(string1, string2): copy string2 to string1
* ms_ncopy(string1, string2, N): copy N characters from string2 to string1
* ms_concat(string1, string2): append string2 to string1
* ms_nconcat(string1, string2, N): append N characters from string2 to string1
* ms_compare(string1, string2): compare string1 and string2
* ms_ncompare(string1, string2, N): compare the first N characters of string1 and string2
* ms_search(string, substring): search substring in string

## Compile

The program is written in C.

Two versions are provided: One that treats strings as arrays and one
that treats strings as pointers. Both versions should behave the same.

To compile, use the provided Makefile:

* Pointer version:

```bash
make mystring_ptrs
```

* Array version:

```bash
make mystring_ars
```

## Typical usage

To run the tests in [main.c](main.c), execute either

```bash
./mystring_ars
```

or

```bash
./mystring_ptrs
```

depending on the compiled version.