
#include <stdio.h>
#include <stdlib.h>

#include "null_pointer_check.h"

void null_pointer_check(void *ptr, char *name, char *file, int line) {
  if (ptr == NULL) {
    fprintf(stderr, "Error: Null pointer for variable '%s' at %s:%d\n", name, file, line);
    exit(EXIT_FAILURE);
  }
}
