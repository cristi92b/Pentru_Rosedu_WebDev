#include <iostream>
#include <list>
#include "functie.h"
using namespace std;

int add_one(int val)
{
    return val+1;
}

int multiply_by_five(int val)
{
    return val*5;
}

int substract_three(int val)
{
    return val-3;
}

int add_two(int val)
{
    return val+2;
}

int multiply_by_three(int val)
{
    return val*3;
}



list<int> executare(list<functie> x,int i)
{
    list<int> result;
    for(list<functie>::iterator it=x.begin();it != x.end();++it)
    {
        result.push_back(it->call(i));
        cout<<"Am adaugat in colectia de intregi: "<<it->call(i)<<endl;
    }
    cout<<x.size()<<" elemente addaugate colectiei(listei) de intregi!"<<endl;
    return result;
}

int main()
{
    list<int> rezultat;
    list<functie> lista;
    functie a;

    a.set(add_one);
    lista.push_back(a);

    a.set(multiply_by_five);
    lista.push_back(a);

    a.set(substract_three);
    lista.push_back(a);

    a.set(add_two);
    lista.push_back(a);

    a.set(multiply_by_three);
    lista.push_back(a);

    rezultat=executare(lista,4);

    return 0;
}

