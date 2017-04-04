#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int mode(int a , int b){
	int q,r;
	q=a/b;
	r = a - (q*b);
	if (r<0){
		q= q-1;
		r=r+b;
	}
	return r;
}

int mcd(int a,int b){
	int r = mode(a,b);
	while(r!=0){
		a=b;
		b=r;
		r=mode(a,b);
	}
	return b;
}

int inversomod(int a,int b,char o){
    if(mcd(a,b) != 1){
        cout<<"no tiene inverso modular"<<endl;
        return 0;}

    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;

    int q , r , s , t;
    while(r2>0){
        q = r1/r2;
        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        s = s1 -q*s2;
        s1 = s2;
        s2 = s;

        t = t1 - q*t2;
        t1 = t2;
        t2 = t;
    }

    if(o == 'x')
        return s1;
    return t1;

}
int main()
{
    ///---------------------------------------MENU
    int k1 , k2,mo;
    string respuesta;
    cout<<"...... CALCULADORA DE MODULO........."<<endl;

    cout<<"Que operacion va a realizar? (+/-/*/i)"<<endl;
    cin>>respuesta;
    if(respuesta=="+" or respuesta == "-" or respuesta == "*"){
        cout<<"Ingrese su primer numero :  ";
        cin>>k1;
        cout<<endl;
        cout<<"Ingrese su segundo numero :  ";
        cin>>k2;
        cout<<endl;
        }
    else if (respuesta == "i"){
        cout<<"Ingrese su numero para invertir :  ";
        cin>>k1;
        cout<<endl;
        }
    else
      cout<<"Operacion invalida"<<endl;
    
    cout<<"Ingresa la base del modulo: \n";
    cin>>mo;
    switch ( respuesta ) {
    case "+":
      return mode((k1 + k2) , mo);
      break;
    case "-":
      return mode((k1 - k2) , mo);
      break;
    case "*":
       return mode((k1 * k2) , mo);
        break;
    case "i":
      return mode(k1 , mo);
      break;
    }
    
    ///---------------------------------------


 //  return 0;
}
