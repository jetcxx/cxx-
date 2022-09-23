#include <ctype.h>
#include <fcntl.h>

#define BSZ 4096

unsigned char buf[BSZ];

unsigned char 
translate(unsigned char c)
{
    if (isalpha(c))
    {
        if(c >= 'n')
        {
            c -= 13;
        }
        else if (c >= 'a')
        {
            c += 13;
        }
        else if(c >= 'N')
        {
            c -= 13;
        }
        else
        {
            c += 13;
        }
        return (c);
    }
}

int main(int argc, char const *argv[])
{
    int ifd,ofd,i,n,nw;
    if(argc != 3)
    {
        err_quit("usage: rot13 infile outfile");
    }
    if((ifd = open(argc[1],O_RDONLY)) < 0)
    {
        err_sys("cant open %s",argv[1]);
    }
    if(())

    return 0;
}
