#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char buf[32] = {0};

    int flags;
    if((flags = fcntl(0,F_GETFL)) == -1)
    {
        perror("fcntl");
        exit(1);
    }

    flags |= O_NONBLOCK;

    if(fcntl(0,F_SETFL,flags) == -1)
    {
        perror("fcntl");
        exit(1);
    }
    while(1)
    {
        if(fgets(buf,32,stdin) == NULL)
        {
            perror("fgets");
        }
        sleep(1);

        printf("buf = [%s]\n",buf);
        printf("********************\n");
    }
    return 0;
}
