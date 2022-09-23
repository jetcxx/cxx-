#include "contact.h"


int main()
{ 
    InitList();
    Welcome();
    char choice;
    int count;
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
            //sort();
            View();
            break;
        case 'c':
            Search();
            break;
        case 'd':
            Del();
            //count--;
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

