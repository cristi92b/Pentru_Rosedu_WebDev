#include "functie.h"
functie::functie()
{
    fptr=NULL;
    label=new char[18];
    strcpy(label,"functie fara nume");
}
functie::functie(int (*new_func)(int))
{
    fptr=new_func;
    label=new char[18];
    strcpy(label,"functie fara nume");
}

functie::functie(int (*new_func)(int),char* nume)
{
    fptr=new_func;
    label=new char[strlen(nume)+1];
    strcpy(label,nume);
}

functie::functie(const functie& obj)
{
    label=NULL;
    fptr=NULL;
    fptr=obj.fptr;
    label=new char[strlen(obj.label)+1];
    strcpy(label,obj.label);
}

functie::~functie()
{
    if(label!=NULL)
       delete[] label;
    label=NULL;
    fptr=NULL;
}

int functie::call(int argument)
{
    assert(fptr!=NULL);
    return fptr(argument);
}

char* functie::getLabel()
{
    return label;
}

void functie::setLabel(char* nume)
{
    if(label!=NULL)
       delete[] label;
    label=NULL;
    label=new char[strlen(nume)+1];
    strcpy(label,nume);
}


void functie::set(int (*new_func)(int))
{
    fptr=new_func;
}

void functie::setAll(int (*new_func)(int),char* nume)
{
    fptr=new_func;
    if(label!=NULL)
       delete[] label;
    label=NULL;
    label=new char[strlen(nume)+1];
    strcpy(label,nume);
}
