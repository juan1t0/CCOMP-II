#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int mex[13]={0,6,2,2,5,0,3,5,1,4,6,2,4};
string dias[7] ={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
int dias_mes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int bisiesto(int anio){
	int a=(anio % 400);
	int b=(anio % 4);
	int c=(anio & 100);
	if ((a==0))
		return 1;//" es bisiesto";
	if ((b==0) && (c!=0))
		return 1;//" es bisiesto";
	return 0;//" no es bisiesto";
}

int que_dia(int dia,int mes,int anio){
	int A=1,B,C=0,D,E;
	int siglo= anio / 100;

	if (siglo ==20)
		A=0;
	if (siglo < 20)
		for(int i= 1,a=19;siglo != a;i+=2,a--)
			A += i;
	if (siglo > 20)
		for(int i= 0,a=20;siglo != a;i+=2,a++)
			A -= i;

	int an = anio % 100;
	B = an + (an/4);
	
	int bbb=bisiesto(anio);
	if (bbb == 1) 
		if(mes == 1 || mes == 2)
			C=C-1;
	D=mex[mes];
	E = dia;

	return (A+B+C+D+E)%7;//dias[(A+B+C+D+E)%7]; 
}

int queDia(int day, int mon, int yea){
	int d= (dias_mes[mon])%7;
	int di;
	di= (yea -1)*365;
	di+= (yea -1)/4;
	di-= (yea -1)/100;
	di+= (yea-1)/400;

	int bbb=bisiesto(yea);
	if (bbb == 1){
		if(mon == 1 || mon == 2)
			;
		d++;}
	di+= d%7;	
	di+= day;
	return (di % 7); 
}

void calendario(int mes,int anio){
	int uno = que_dia(1,mes,anio),dia=1;
	int k=0;
	if (uno ==0)
		cout<<"| "<<dia<<" |";	
	else 
		while(k!=uno){
			cout<<"|   |";
			k++;
			if (k== uno)
				cout<<"| "<<dia<<" |";	
		}

	for(int i=0;i<6;i++){
		for(;k<7 && dia < 31;k++)
			cout<<"| "<< (dia+=1) <<" |";
		cout<<endl;
		k=0;
		}
}
int main()
{
	/*int a;
	cin >>a;
	cout <<" El año"<< bisiesto(a)<< endl;
*/
	/*string dia,mes,anio;
	cout <<"ingresa una fecha en formato dia/mes/año (solo numeros):"<<endl;
	dia = cin.get();cin.ignore(3,'/');
	mes = cin.get();cin.ignore(3,'/');
	anio= cin.get();
	int dd = atoi(dia.c_str());
	int mm = atoi(mes.c_str());
	int aa = atoi(anio.c_str());
*/	
	cout<<"ingrese el dia: "<<endl;	
	int dd;cin>>dd;
	cout<<"ingrese el mes: "<<endl;
	int mm;cin>>mm;
	cout<<"ingrese el año: "<<endl;
	int aa;cin>>aa;
	
	cout<<"1 el dia es "<< dias[que_dia(dd,mm,aa)]<<endl;	
	cout<<"2 el dia es "<< dias[queDia(dd,mm,aa)]<<endl;	
	
	//calendario(mm,aa);
	return 0;
}


//g++ programa.cpp -o ejecutable
//./ejecutable
