# C++ Data Structures Practice

Small C++ exercises for learning pointers, linked lists and console output.

## Exercises

| Source | Topics |
| --- | --- |
| [c++.cpp](C%2B%2B/c%2B%2B.cpp) | Doubly linked list: insertion and deletion at the start, end and a specified position |
| [c++11.02.cpp](C%2B%2B/c%2B%2B11.02.cpp) | Console output, newlines and tab characters |

## Build and run

Use a C++ compiler such as GCC. Compile each exercise separately because each has its own `main()`.

```bash
git clone https://github.com/uvinN20/DSA-C-PLUS-PLUS.git
cd DSA-C-PLUS-PLUS
g++ -std=c++17 -Wall -Wextra "C++/c++.cpp" -o linked-list
./linked-list
```

On Windows with MinGW, use `-o linked-list.exe` and run `.\linked-list.exe`.

For the output exercise, replace the source filename with `C++/c++11.02.cpp`.

## Scope and next steps

These are learning exercises, not a general-purpose container library. The linked list uses raw pointers; useful extensions are automatic cleanup, copy/move ownership rules and tests for empty lists and boundary positions.

Build from the source when reviewing the project; the repository also contains previously generated executables.
