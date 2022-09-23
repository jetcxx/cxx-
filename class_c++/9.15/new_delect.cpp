#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //int a[4][5];
    int (*a)[5] = new int[4][5]; 
    char (*p)[100] = new char[3][100];
    return 0;
}
