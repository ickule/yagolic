#ifndef NULL_POINTER_CHECK_H_INCLUDED
#define NULL_POINTER_CHECK_H_INCLUDED

/* Checks if pointer is null and print a message and exit accordingly */
void null_pointer_check(void *ptr, char *name, char *file, int line);

/* Macro to wrap the null_pointer_function and provide variable name, file name and line number */
#define NULL_POINTER_CHECK(ptr)                                                                    \
  do {                                                                                             \
    null_pointer_check(ptr, #ptr, __FILE__, __LINE__);                                             \
  } while (0)

#endif /* NULL_POINTER_CHECK_H_INCLUDED */
