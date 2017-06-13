#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
    public:
        int valor;
        Nodo *next;

        Nodo();
        Nodo(int);
        virtual ~Nodo();
};

#endif // NODO_H
