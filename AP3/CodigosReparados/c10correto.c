#include <stdlib.h>
#include <stdio.h>

int main(void)
{
        int *p;
        int i = 0;
        while(i < 127)
        {
                free(p);
                p = malloc(128);
                printf("%ld\n", (long)p);
                i++;
        }
        return (0);
}
