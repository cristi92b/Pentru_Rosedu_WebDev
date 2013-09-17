#ifndef FUNCTIE_H
#define FUNCTIE_H
#include <iostream>
#include <assert.h>
#include <string.h>

class functie
{
    int (*fptr)(int);
    char* label;
public:
    functie();
    functie(int (*fptr)(int));
    functie(int (*fptr)(int),char*);
    functie(const functie&);
    ~functie();
    int call(int);
    char* getLabel();
    void setLabel(char*);
    void set(int (*fptr)(int));
    void setAll(int (*fptr)(int),char*);
};

#endif // FUNCTIE_H
