# C strings

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

* Build the library that uses pointers:

```bash
make mystring_ptrs.o
```

* Build the library that uses arrays:

```bash
make mystring_ars.o
```

## Tests

Using the library is demonstrated in [main.c](src/main.c)

* Build the tests that use pointer version:

```bash
make mystring_ptrs
```

Run:

```bash
./mystring_ptrs
```

* Build the tests that uses the array version:

```bash
make mystring_ars
```

Run:

```bash
./mystring_ars
```
