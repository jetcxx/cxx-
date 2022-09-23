#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct contact
{
    int id;
    char name[32];
    char num[32];
}person;

void Welcome();
void Menu();
void Add();
void sort();
void View();
void Search();
void Del();
void Revise();

int mystrcmp();
int mystrlen();
