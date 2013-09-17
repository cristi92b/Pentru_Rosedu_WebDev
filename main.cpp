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

void afiseaza_lista_de_intregi(list<int> x)
{
	cout<<"root";
	for(list<int>::iterator it=x.begin();it != x.end();++it)
	{
		cout<<"->"<<*it;
	}
	cout<<endl;
}

void afiseaza_lista_de_functii(list<functie> x)
{
	cout<<"root";
	for(list<functie>::iterator it=x.begin();it != x.end();++it)
	{
		cout<<"->"<<it->getLabel();
	}
	cout<<endl;
}

int main()
{
    int i;
    list<int> rezultat;
    list<functie> lista;
    /*
    functie a;

    a.setAll(add_one,"add_one");
    lista.push_back(a);

    a.setAll(multiply_by_five,"multiply_by_five");
    lista.push_back(a);

    a.setAll(substract_three,"substract_three");
    lista.push_back(a);

    a.setAll(add_two,"add_two");
    lista.push_back(a);

    a.setAll(multiply_by_three,"multiply_by_three");
    lista.push_back(a);
    */

    functie a(add_one,"add_one"),b(multiply_by_five,"multiply_by_five"),c(substract_three,"substract_three"),d(add_two,"add_two"),e(multiply_by_three,"multiply_by_three");

    lista.push_back(a);
    lista.push_back(b);
    lista.push_back(c);
    lista.push_back(d);
    lista.push_back(e);
    cout<<"i="; cin>>i;
    rezultat=executare(lista,i);
    afiseaza_lista_de_functii(lista);
    afiseaza_lista_de_intregi(rezultat);
    lista.clear();
    rezultat.clear();
    return 0;
}

