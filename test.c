#include "pipex.h"

int main()
{
    char *tmp;
    tmp = get_next_line(0);
    puts(tmp);
    free(tmp);
    return 0;
}