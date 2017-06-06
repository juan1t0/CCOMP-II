#include <iostream>
#include "Nodo.h"

using namespace std;
Nodo* jossephus(int a){
    Nodo *ne = new Nodo();
    Nodo *aux = ne;
    for(int i=1;i<a;i++){
        ne->next=new Nodo(i);
        ne=ne->next;
    }
    ne->next=aux;
    return aux;
}
void imprimir(Nodo *a){
    Nodo*aux=a;
    while(a->next != aux){
        cout<<a->valor<<" , ";
        a=a->next;
    }
    cout<<a->valor<<endl;
}
void Matar(Nodo *ptr,int a,int sizz){
    Nodo* p = ptr;
    for(;sizz>2;sizz--){
        for(int j=1;j<a-1;j++){
            p=p->next;
        }
        Nodo* aux = p->next;
        p->next=p->next->next;
        cout<<aux->valor<<" ";
        delete aux;
        p=p->next;
    }
    cout<<endl;
    cout<<"vive"<<p->valor<<" y "<<p->next->valor<<endl;
}
int main()
{
    Nodo *jose = jossephus(30);
  //  imprimir(jose);
    Matar(jose,3,30);
    return 0;
}
