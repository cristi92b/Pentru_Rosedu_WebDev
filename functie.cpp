#include "functie.h"
functie::functie()
{
	fptr=NULL;
}
functie::functie(int (*new_func)(int))
{
    fptr=new_func;
}

int functie::call(int argument)
{
    assert(fptr!=NULL);
    return fptr(argument);
}

void functie::set(int (*new_func)(int))
{
    fptr=new_func;
}
