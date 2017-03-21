#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int monedas[7]={200,100,50,20,10,5,1};
string cents[3]={"0.50","0.20","0.10"};
int centavos[3]={50,20,10};

void ent(float cant){
    int d = cant;
    int c = (cant -d)*100 +1;
    cout<<c<<endl;
    for(int i=0;i<7;i++){
        int res = d%(monedas[i]);
        int cc = d/(monedas[i]);
        cout<<"necesitara "<< cc<<" de "<< monedas[i]<<endl;
        d=res;
    }
    for(int i=0;i<3;i++){
        int res = c%(centavos[i]);
        int cc = c/(centavos[i]);
        cout<<"necesitara "<< cc<<" de "<< cents[i]<<endl;
        c=res;
    }
}

int main()
{
    ent(6516.80);
    return 0;
}
