#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

string abc("{abcdefghijklmnopqrstuvwxyz ");


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
string encrip(string fr,int kl_public){
    string aux;
    int t ;
    for(int i=0;i<fr.size();i++){
        t= abc.find(fr[i]);
        t*=kl_public;
        ostringstream ss;
        ss << t;
        aux +=ss.str();
        aux += ' ';
        }
        aux += '|';
    return aux;
}
int* for_des(string num){
    int a[999];
    string w;
    int j=0;
    for(int i=0;num[i]!='|';i++){
        if(num[i] == ' '){
            istringstream ( w ) >> a[j];
            j++;
            w="";}
        else
            w+=num[i];
        }
    int *aa = a;
    return aa;
}
string descrip(int rf[] ,int kl_private){
    string aux;
    int r;
    for(int i=0;rf[i]!='\0';i++){
        r= mode(rf[i] * kl_private, abc.size());
        aux+=abc[r];
        }
    return aux;
}
int main()
{
    ///---------------------------------------MENU
    int klave_publica , klave_privada;
    string respuesta;
    cout<<"...... ENCRIPTA ........."<<endl;

    cout<<"ingrese su clave publica : "<<endl;
    cin>>klave_publica;
    cout<<"ingrese su clave privada : "<<endl;
    cin>>klave_privada;

    ifstream fichero;
    ofstream ficero;

    string frase,fresa;

    fichero.open("hm.txt");
    getline(fichero,frase);
    fichero.close();
    cout<<"Desea modificar el texto de hm.txt (S/n)"<<endl;
    cin>>respuesta;
    if(respuesta == "s"){
        cout<<"Ingrese su texto :"<<endl;
        cin.ignore();
        getline(cin, frase);
        }
    else if(respuesta != "n" && respuesta != "s")
        return 0;

    ///---------------------------------------

    ficero.open("hmcrp.txt");
    ficero << encrip(frase,klave_publica);
    frase="";
    ficero.close();

    fichero.open("hmcrp.txt");
    getline(fichero,frase);
    fichero.close();
    int *let =(for_des(frase));
    cout<<"Desea ver el archivo encriptado hmcrp.txt (S/n) :"<<endl;
    cin>>respuesta;
    if(respuesta == "s")
        cout<<frase<<endl;
    cout<<"Mostrar el texto original (S/n) :"<<endl;
    cin>>respuesta;
    if(respuesta == "s")
        cout<<descrip(let,klave_privada)<<endl;

    return 0;
}
// a= 28 b = 17 | x = -3  y = 5
/*  letra * y = crip
    crip * b = plain
    plain mod 27 = letra*/
