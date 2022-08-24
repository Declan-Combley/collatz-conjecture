# Collatz Conjecture

A simple collatz cojecture calulator written in C.

# Quickstart

```shell
$ ./build.sh
$ ./collatz num
```

# Rules

The collatz conjecture has two rules, if $n$ is even you divide $n$ by two, and if $n$ is odd you times $n$ by three and add one.  Theoretically $n$ will result in 1 after enough itterations.


eg

```
 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
```

## *Warning*

This program can only calculate conjecture with numbers  from 1 to 999999999999999999.
