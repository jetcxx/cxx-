#include "contact.h"

int main(int argc, char const *argv[])
{
    printf("--------------------------------------------------------------------------------\n");
    printf("                                    欢迎使用                               \n");
    printf("---------------------------------------------------------------------------------\n");
    char input;
    int count = 0;
    Menu();
    //scanf("%c",&input);
    while(1)
    {
        //getchar();
        scanf("%c",&input);
        switch (input)
        {
        case 'a':
            Add();
            break;
        case 'b':
            View();
            break;
        case 'c':
            Search();
            break;
        case 'd':
            Del();
            break;
        case 'e':
            Revise();
            break;
        case 'f':
            exit(0);
            break;
        default:
            printf("无效输入\n");
            break;
        }
        getchar();
        //scanf("%c",&input);
    }
    return 0;
}
