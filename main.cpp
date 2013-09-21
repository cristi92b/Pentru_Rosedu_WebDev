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
    for(list<functie>::iterator it=x.begin(); it != x.end(); ++it)
    {
        result.push_back(it->call(i));
        //cout<<"Am adaugat in colectia de intregi: "<<it->call(i)<<endl;
    }
    //cout<<x.size()<<" elemente addaugate colectiei(listei) de intregi!"<<endl;
    return result;
}

void afiseaza_lista_de_intregi(list<int> x)
{
    int p=0;
    cout<<"Colectia de intregi:\n";
    for(list<int>::iterator it=x.begin(); it != x.end(); ++it)
    {
        cout<<p<<" -> "<<*it<<endl;
        p++;
    }
    cout<<endl;
}

void afiseaza_lista_de_functii(list<functie> x)
{
    int p=0;
    cout<<"Colectia de functii:\n";
    for(list<functie>::iterator it=x.begin(); it != x.end(); ++it)
    {
        cout<<p<<" -> "<<it->getLabel()<<endl;
        p++;
    }
    cout<<endl;
}

void elimina(list<functie> &x,int pozitie)
{
    list<functie>::iterator it=x.begin();
    for(int i=0; i<pozitie; i++)
        it++;
    x.erase(it);
}


void program()
{
    functie a(add_one,"add_one"),b(multiply_by_five,"multiply_by_five"),c(substract_three,"substract_three"),d(add_two,"add_two"),e(multiply_by_three,"multiply_by_three");
    int i,t=0,g,id,t1,t2,poz;
    list<int> rezultat;
    list<functie> lista;
    cout<<"i=";
    cin>>i;
    do
    {
        cout<<"1 - Adauga o functie in colectie\n2 - Afiseaza colectia de functii\n3 - Elimina o functie din colectie\n4 - Afiseaza biblioteca de functii\n5 - Executa programul\n";
        cin>>g;
        switch(g)
        {
        case 1 :
            t1=0;
            do
            {
                cout<<"ID (0-4) =";
                cin>>id;
                if(id>=0&&id<=4)
                {
                    t1=1;
                    switch(id)
                    {
                    case 0 :
                        lista.push_back(a);
                        break;
                    case 1 :
                        lista.push_back(b);
                        break;
                    case 2 :
                        lista.push_back(c);
                        break;
                    case 3 :
                        lista.push_back(d);
                        break;
                    case 4 :
                        lista.push_back(e);
                        break;
                    default :
                        lista.push_back(a);
                        break;
                    }

                }
                else
                    cout<<"functia nu exista!\n";
            }
            while(t1==0);
            cout<<"Functia cu ID-ul "<<id<<" a fost adaugata cu succes in colectie!\n";
            break;
        case 2 :
            afiseaza_lista_de_functii(lista);
            break;
        case 3 :
            t2=0;
            do
            {
                cout<<"pozitie (0-"<<lista.size()-1<<") =";
                cin>>poz;
                if(poz>=0&&poz<lista.size())
                {
                    elimina(lista,poz);
                    t2=1;
                    cout<<"elementul numarul "<<poz<<" din lista de functii a fost eliminat cu succes!\n";
                }
                else
                {
                    cout<<"elementul nu exista!\n>";
                }
            }
            while(t2==0);
            break;
        case 4 :
            cout<<"Biblioteca de functii:\nID=0 add_one()\nID=1 multiply_by_five()\nID=2 substract_three()\nID=3 add_two()\nID=4 multiply_by_three()\n";
            break;
        case 5 :
            t=1;
            break;
        default :
            cout<<"Comanda nerecunoscuta!\n";
            break;
        }
    }
    while(t==0);

    rezultat=executare(lista,i);
    afiseaza_lista_de_functii(lista);
    afiseaza_lista_de_intregi(rezultat);
    lista.clear();
    rezultat.clear();
}



int main()
{

    program();
    return 0;

}

