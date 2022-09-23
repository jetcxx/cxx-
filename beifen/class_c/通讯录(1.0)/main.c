#include "contact.h"

int count = 0;
person *ct[MAX] = {0};
//int id_init = 1;

int main()
{
Welcome();
char choice;
Menu();
scanf("%c",&choice);
while(1)
{
    switch (choice)
    {
        case 'a':
            Add();
            break;
        case 'b':
            sort();
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
    Menu();
    getchar();
    scanf("%c",&choice);
}
    Add();
    return 0;
}

