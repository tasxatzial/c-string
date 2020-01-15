# Description

C string manipulation library, similar to string.h

The following functions are implemented:

* ms_length(string): get the length of string
* ms_copy(string1, string2): copy string2 to string1
* ms_ncopy(string1, string2, N): copy N characters from string2 to string1
* ms_concat(string1, string2): append string2 to string1
* ms_nconcat(string1, string2, N): append N characters from string2 to string1
* ms_compare(string1, string2): compare string1 and string2
* ms_ncompare(string1, string2, N): compare the first N characters of string1 and string2
* ms_search(string, substring): search substring in string

## Implementation

Two versions are provided: One that treats strings as arrays and one
that treats strings as pointers. Both versions return the same results but the pointer
version should run faster.

## Compile

Use the provided Makefile:

### Building the library

* Pointer version:

```bash
make mystring_ptrs.o
```

* Array version:

```bash
make mystring_ars.o
```

### Building the test files

Using the library is demonstrated in [main.c](main.c)

* Build the tests for the pointer version:

```bash
make mystring_ptrs
```

and run with:

```bash
./mystring_ptrs
```

* Build the tests for the array version:

```bash
make mystring_ars
```

and run with:

```bash
./mystring_ars
```
