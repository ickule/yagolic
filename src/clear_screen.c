#include <stdio.h>

#include "clear_screen.h"

void clear_screen() { puts("\033[2J\033[1;1H"); }
