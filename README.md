# libcmdparser
This is a simple library for splitting command into arguments.

Example:
```c
#include <stdio.h>
#include <stddef.h>

#include "cmdparser.h"

int main(int argc, char** argv) {
    const char* command = "ls abcdef      test_dir hello123  tratata";

    command_parser_t parser = {};
    command_parser_new(&parser, command);

    for(size_t i = 0; i < parser.argc; i++){
        printf("Argument number: %zu -> `%s`\n", i, parser.argv[i]);
    }

    command_parser_destroy(&parser);
}
```

Output:
```
Argument number: 0 -> `ls`
Argument number: 1 -> `abcdef`
Argument number: 2 -> `test_dir`
Argument number: 3 -> `hello123`
Argument number: 4 -> `tratata`
```