#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string dig1[10]={"cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
string dig2[5]={"once","doce","trece","catorce","quince"};
string dig3[10]={"","diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
string dig4[4]={"cien","ciento","cientos","entos"};
string dig5[8]={"do","tre","cuatro","quini","seis","sete","ocho","nove"};
string dig6[3]={"mil","millon","millones"};

string escribe_0to99(int numero){

    if (numero < 10)
        return dig1[numero];
    else if(numero%10 == 0)
        return dig3[(numero / 10)];
    else if(numero<=15)
        return dig2[(numero -11)];
    else if(numero >15 && numero < 100)
        return dig3[(numero / 10)] +" y "+dig1[(numero % 10)];
}
string escribe_100to999(int numero){
    if(numero ==0)
        return "";
    if (numero <100)
        return escribe_0to99(numero);
    if((numero % 100) == 0){
        if(numero == 100)
            return dig4[0];
        else if(numero != 500)
            return dig5[(numero / 100)-2]+ dig4[2];
        else if(numero == 500)
            return dig5[3]+ dig4[3];}
    else if(numero>100 && numero <200)
        return dig4[1] +" "+( escribe_0to99(numero % 100));
    else if(numero >=200 && numero <500)
        return dig5[(numero / 100)-2]+ dig4[2] +" "+( escribe_0to99(numero % 100));
    else if(numero >=500 && numero <600)
        return dig5[(numero / 100)-2]+ dig4[3] +" "+( escribe_0to99(numero % 100));
    else if(numero >=600 && numero <1000)
        return dig5[(numero / 100)-2]+ dig4[2] +" "+( escribe_0to99(numero % 100));
}

string escribe_mil(int numero){
    if(numero==0)
        return "";
    if(numero<1000)
        return escribe_100to999(numero);
    if ((numero % 10000)==1)
        return escribe_100to999(numero / 10000)+" y un "+dig6[0]+" "+escribe_100to999(numero %1000);
    else if(numero < 1000000)
        return escribe_100to999(numero /1000)+" "+dig6[0]+" "+escribe_100to999(numero %1000);

}
string escribe_millones(int numero){
    //if(numero < 100000000)
      //  return escribe_0to99(numero / 1000000)+" "+dig6[2]+" "+escribe_mil(numero %1000000);
    if(numero < 1000000000)
        return escribe_100to999(numero/10000000)+" "+dig6[2]+" "+escribe_mil(numero %1000000);
    else if(numero < 1000000000000)//999000-999000
        return escribe_mil(numero/1000000)+" "+dig6[2]+" "+escribe_mil(numero%1000000);
}
string escribe( int numero){
    if (numero<100)
        return escribe_0to99(numero);
    else if(numero < 1000)
        return escribe_100to999(numero);
    else if(numero < 100000)
        return escribe_mil(numero);
    else if(numero < 100000000)
        return escribe_0to99(numero / 1000000)+" "+dig6[2]+" "+escribe_100to999(numero %1000)+" "+dig6[0]+" "+escribe_100to999(numero %1000);
    else if(numero < 10000000000)//999 19999999
        return escribe_100to999(numero/10000000)+" "+dig6[2]+" "+escribe_100to999(numero %1000)+" "+dig6[0]+" "+escribe_100to999(numero %1000);
}
int main()
{
    cout<<"ingrese un numero : "<<endl;
    int num;
  //  cin>>num;
    cout<<escribe_mil(21000)<<endl;;
    return 0;
}
