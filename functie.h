#ifndef FUNCTIE_H
#define FUNCTIE_H
#include <iostream>
#include <assert.h>

class functie
{
    int (*fptr)(int);
public:
    functie();
    functie(int (*fptr)(int));
    int call(int);
    void set(int (*fptr)(int));
};

#endif // FUNCTIE_H
