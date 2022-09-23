#include <stdio.h>
enum week{
    MON = 1,
    TUS,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};
int main()
{
    int day = TUS;
    printf("day = %d\n",day);

    enum week day1;
    printf("sizeof(day1) = %ld\n",sizeof(enum week));
    day1 = SAT;
    printf("day1 = %d\n",day1);
    return 0;
}
