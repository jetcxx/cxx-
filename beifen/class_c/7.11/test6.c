#include <stdio.h>
#define SIZE 50
int main(void)
{
    int counter,evens[SIZE];
    for(counter = 0;counter < SIZE;counter++)
	evens[counter] = 2 * counter;
    printf("%d",evens[50]);
    return 0;
}
