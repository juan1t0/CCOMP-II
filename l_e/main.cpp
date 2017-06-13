#include <iostream>
#include "Nodo.h"

using namespace std;

void print_list(Nodo *a){
    cout<<"["<<a->valor<<" , ";
    while(a->next!=0){
        a=a->next;
        cout<<a->valor<<" , ";
    }
    cout<<"]"<<endl;
}
void print_Memo(Nodo *a){
    cout<<"["<<a<<" | ";
    while(a->next!=0){
        a=a->next;
        cout<<a<<" | ";
    }
    cout<<"]"<<endl;
}

void insert(Nodo *z,Nodo *x){
    while(z->next!=0)
        z=z->next;
    z->next = x;
}
void insort(Nodo *z,Nodo *x){
    if(z->valor <= x->valor)
        insert(z,x);
    else
        insert(x,z);
}
Nodo* crearLe(int intervalo,int len){
    Nodo* a= new Nodo(1);
    Nodo *aux=a;
    for(int i=1;i<len;i++){
        a->next=new Nodo(i*intervalo);
        a=a->next;
    }
    return aux;
}
void concatenar(Nodo* oA,Nodo* oB){
    Nodo *aux;
    Nodo *inicio;
    if(oA->valor <= oB->valor){
        inicio=oA;
        oA=oA->next;}
    else{
        inicio=oB;
        oB=oB->next;}
    aux=inicio;
    while(oA !=NULL && oB != NULL){
        if(oA->valor <= oB->valor){
            aux->next = oA;
            oA = oA->next;
            aux = aux->next;
        }
        else if(oB->valor <= oA->valor){
            aux->next = oB;
            oB = oB->next;
            aux = aux->next;
        }
    }
    if(oA == NULL)
        aux->next=oB;
    if(oB == NULL)
        aux->next=oA;
    oA=inicio;
}
void borrar_lista(Nodo* d){
    while(d != 0){
        Nodo *temp = d;
        d=d->next;
        delete temp;
    }
//    delete d;
}

int main()
{
    Nodo *t = crearLe(17,13);
    Nodo *r = crearLe(13,17);
    print_list(t); //print_Memo(t);
    print_list(r); //print_Memo(r);
    concatenar(t,r);
    print_list(t); //print_Memo(t);
    borrar_lista(t);
    borrar_lista(r);
    return 0;
}
