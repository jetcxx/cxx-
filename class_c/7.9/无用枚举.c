#include <stdio.h>
 
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
 
int main()
{
    enum DAY day;
    scanf("%s",&day);

    day = "%s";
    printf("%d",day);
    return 0;
}
