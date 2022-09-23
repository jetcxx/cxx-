#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef int Datatype;

typedef struct contact
{
    int id;
    char name[32];
    char num[32];
}person;

typedef struct List
{
    person data;
    struct List *next;
}linklist;

void InitList();
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
