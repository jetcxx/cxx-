#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

//#define MAX 1000

typedef int Datatype;

typedef struct contact
{
    int id;
    char name[32];
    char num[32];
}person;

person p1;
person p2;

extern int count;


void Menu();
int Add();
int Search();
int View();
void Del();
void Revise();

#endif