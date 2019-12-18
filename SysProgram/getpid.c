#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    printf("My parent pid = %d\n", getpid());
    return 0;
}