#include <iostream>
using namespace std;

void add(int a,int b)
{
	cout<<a+b<<endl;
}

void add(int a,int b,int c = 100)
{
	cout<<a+b<<endl;
}
int main(int argc, const char *argv[])
{
	add(1,2);
	return 0;
}
