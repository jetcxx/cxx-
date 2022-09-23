#include <stdio.h>

int main(int argc, const char *argv[])
{
int arr[6] = {10,20,30,40,50,60};
int *p1 = &arr[0];
printf("p1 = %d\n",*p1);
p1++;
printf("p1 = %d\n",*p1);
int *p2 = p1++;
printf("p1 = %d,p2 = %d\n",*p1,*p2);
printf("p1 - p2 = %ld\n",p1 - p2);



return 0;
}
