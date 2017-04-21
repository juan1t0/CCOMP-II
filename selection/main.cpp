#include <iostream>
#include <stdlib.h>
#include <time.h>
#define LEN 20

using namespace std;

void swap(int *a , int *b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}
void imprimir(int *a,int *b){
    cout<<"[";
    for(;a!=b;a++)
		cout<<*a<<",";
    cout<<*b<<"]"<<endl;
}

void selection(int *p,int *q){
    int *aux,*mini,*im;
    aux=im=mini=p;
    while(aux <= q){
        while(p<=q){
            if(*mini <= *p)
                ;
            else
                mini=p;
            p++;
        }
        swap(mini,aux);
        aux+=1;
        mini=aux;
        p=aux;
    }
    imprimir(im,q);
}

int main()
{
    int a[LEN];

	srand(time(NULL));
	int *p,*q;
	p=a;q=p;
	q+=(sizeof(a)/sizeof(int))-1;
	for(int i=0;i<LEN;i++)
		a[i]=rand()%100;
    imprimir(p,q);
    selection(p,q);
    return 0;
}
