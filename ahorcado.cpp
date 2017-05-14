#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
void mostra(int v){
	switch(v){
	case 6:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    O"<<endl;cout<<"|    |"<<endl;cout<<"|   /|\\"<<endl;cout<<"|    |"<<endl;cout<<"|   / \\"<<endl;	cout<<"|_______ "<<endl;
		break;
	case 5:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    O"<<endl;cout<<"|    |"<<endl;cout<<"|   /|\\"<<endl;cout<<"|    |"<<endl;cout<<"|   / "<<endl;	cout<<"|_______ "<<endl;
		break;
	case 4:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    O"<<endl;cout<<"|    |"<<endl;cout<<"|   /|\\"<<endl;cout<<"|    |"<<endl;cout<<"|   "<<endl;	cout<<"|_______ "<<endl;
		break;
	case 3:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    O"<<endl;cout<<"|    |"<<endl;cout<<"|   /|"<<endl;cout<<"|    |"<<endl;cout<<"|   "<<endl;	cout<<"|_______ "<<endl;
		break;
	case 2:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    O"<<endl;cout<<"|    |"<<endl;cout<<"|    |"<<endl ;cout<<"|    |"<<endl;cout<<"|   "<<endl;	cout<<"|_______ "<<endl;
		break;
	case 1:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    O"<<endl;cout<<"|    "<<endl;cout<<"|   "<<endl;cout<<"|    "<<endl;cout<<"|   "<<endl;	cout<<"|_______ "<<endl;
		break;
	case 0:
		cout<<"______"<<endl;cout<<"|    |"<<endl;cout<<"|    "<<endl;cout<<"|    "<<endl;cout<<"|   "<<endl;cout<<"|    "<<endl;cout<<"|   "<<endl;	cout<<"|_______ "<<endl;
		break;

	}
}
bool ver(const char* palabra,char* Pmos,char* letra){
	bool vida =true;
	int pos;
	while(*palabra != '\0'){
		if(*letra == *palabra){
			*Pmos = *letra;
			vida=false;
		}
		Pmos++;
		palabra++;
	}
	return vida; 
}
bool compare(const char *p,char*t){
	while(*p != '\0'){
		if(*p != *t)
			return false;		
		p++;
		t++;		
	}
	return true;
}
int main()
{
	string palabra;
	cin>>palabra;
	const char *p = palabra.c_str();
	for(int i=0;i<100;i++)
		cout<<"#------wait------#"<<endl;;
	
	char p_aux[palabra.size()];
	for(int i=0;i<palabra.size();i++)
		p_aux[i]='-';
	char *aux = p_aux;
	char letra;
	int i=0;
	int vida=0;
	char *a;

	cout<<p_aux<<endl;
	while(vida != 6){
		cin>>letra;
		a = &letra;
		vida += ver(p,aux,a);
		mostra(vida);
		cout<<aux<<endl;
		if(compare(p,aux)){
			cout<<" -- GANASTE --"<<endl;
			return 0;}
	}

cout<<"          $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"       $$$$   $$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"     $$$$      $$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"   $$$$$        $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"  $$$$$          $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<" $$$$$            $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"$$$$$$            $$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"$$$$$$           $$$$$$$$$           $$$$$$"<<endl;
cout<<"$$$$$$$         $$$ $$$ $$$         $$$$$$$$"<<endl;
cout<<"$$$$$$$$      $$$$   $   $$$$      $$$$$$$$$$"; cout<<"      -- Perdiste --"<<endl;
cout<<"$$$$$$$$$$$$$$$$$   $$$   $$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"$$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ o$$$$"<<endl;
cout<<"$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  $$$$$"<<endl;
cout<<" $$$  $'$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  o$$$$"<<endl;
cout<<" '$$o  $$  $$'$$$$$$$$$$$$$$'$$  $$    o$$$"<<endl;
cout<<"   $$o$    $$  '$$'$$'$$'  $$     $   o$$$"<<endl;
cout<<"    $$$o$  $    $$   $$    $$    $$  o$$"<<endl;
cout<<"     '$$$$O$    $$   $$    $$    o4$$$"<<endl;
cout<<"        '$$o$   $$   $$$  $$   o$$$$"<<endl;
cout<<"          '$$$$o$o$o$o$o$o$o$o$$$$"<<endl;
cout<<"             $$$$$$$$$$$$$$$$$$$"<<endl;
	
	return 0;
}


