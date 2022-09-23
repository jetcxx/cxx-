#include <stdio.h>
int main()
{
/*    int a;
    char b;
    scanf("%d %c",&a,&b);
    printf("%d %c",a,b);
    return 0;

    char c;
    scanf("%c", &c);
    printf("%d\n", c);
  
    scanf("%c", &c);
    printf("%d\n", c);
*/
    int a = 0, b =0;
   char d = 'a', e ='a';
   scanf("%d",&a);        //输入字符a到缓存，跳过接受，a=0
   scanf("%d",&b);        //输入字符a到缓存，跳过接受，b=0
   scanf("%c",&d);        //输入字符a到缓存，接受，d=b
   scanf("%c",&e);        //e接受换行符，ASCII为10
   printf("%d,%d,%c,%d\n",a,b,d,e);
    return 0;

}
