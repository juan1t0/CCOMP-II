#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void swap(int *a , int *b){
	int *aux;
	*aux=*a;
	*a=*b;
	*b=*aux;
}
int* crearL(int len){
	srand(time(NULL));
	int *a,*g;
	g=a;
	for(int i=0;i<len;i++,a++)
		*a=rand()%50;
	return g;
}
void imprimir(int *w,int len){
	for(int i=0;i<len;i++,w++)
		cout<<*w<<",";
}
int main (int argc, char *argv[]) {
	int* ar = crearL(10);
	imprimir(ar,10);
	return 0;
}

