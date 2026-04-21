#include<iostream>
#include "punteros.h"

using namespace std;
using TP = int;

void Print(TP n){
    cout << n << endl;
}

// Paso por valor
void f1(TP n){     ++n;    }

// Paso por referencia
void f2(TP &n){    ++n;    }

// Paso por referencia constante
void f3(const TP &n){}

// Paso de puntero por valor
void f4(TP *pi){   ++*pi; pi=nullptr;  }

// Paso de referencia a un puntero
void f5(TP *&rp){  ++*rp; rp=nullptr;}

// Paso de puntero a puntero
void f6(TP **ppx){ ++**ppx;    ppx=nullptr;      }

// Paso de puntero a puntero
void f7(TP **&rpp){ ++**rpp; rpp=nullptr;   }

void DemoPunteros1 (){
    TP x=10, y=20, &r=x;
    TP *p,*q,**pp;

    p=&x;
    q=&y;
    pp=&p;

    cout << "Primera parte void f1(TP n)" << endl;
    f1(x);      Print(x);
    f1(*p);     Print(x);
    f1(**pp);   Print(x);
    f1(10);     Print(10);
    f1(r);      Print(x);

    r=20; //x=20

    f1(x+5);    Print(x);
    f1(x+y);    Print(x);

    cout << "Segunda parte void f2(TP &n)" << endl;
    x=10; y=20;

    f2(x);      Print(x);// 11
    f2(r);      Print(x);// 12
    f2(*p);     Print(x);// 13
    f2(**pp);   Print(x);// 14
    // f2(15);  // Error
    // f2(x+3); // Error

    cout << "Tercera parte void f3(const TP &n)" << endl;
    x=10; y=20;

    f3(x);      Print(x);
    f3(25);     Print(x);
    f3(r);      Print(x);
    f3(*p);     Print(x);
    f3(**pp);   Print(x);

    cout << "Cuarta parte void f4(TP *pi)" << endl;
    x=10; y=20;

    f4(&x);     Print(x);
    f4(p);      Print(x);
    f4(*pp);    Print(x);
    f4(&r);     Print(x);

    cout << "Quinta parte void f5(TP *&rp)" << endl;
    x=10; y=20;

    // f5(&x); // Error
    f5(p);      Print(x);
    cout << "p=" << p << endl;
    p=&x;
    f5(*pp);    Print(x);
    p=&x; // *pp = &x;
    f5(q);      Print(y);

    cout << "Sexta parte void f6(TP **ppx)" << endl;
    x=10; y=20;
    f6(pp);     Print(x);
    cout << "pp=" << pp << endl;
    
    cout << "Septima parte void f7(TP **&rpp)" << endl;
    x=10; y=20;

    f7(pp);     Print(x);
    cout << "pp=" << pp << endl;
}