#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int rompecabezas[4][4];
int pos_x;
int pos_y;

bool ordenado(int (*mat)[4]){
	int *row = *mat;
	int cont = 1;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (*row < *(row+1)){
				//cout << *row << " ";
				++cont;
				row++;
			} else {
			    if (cont == 15 && *(*(rompecabezas+3)+3) == 0){
                    *(*(rompecabezas+3)+3) = 16;
                    break;
			    }
				//cout << "NO " << *row << endl;
				return 0;
			}
		}
		//cout << endl;
		mat++;
	}
	cout << "USTED GANA!!\n";
	return 1;
}

///########################################################################################################
void imprimir(){
    system("cls");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << *(*(rompecabezas+i)+j) << " ";
			if(*(*(rompecabezas+i)+j) < 10){
                cout << " ";
			}
		}
		cout << endl;
	}
}
void arriba(){
    if(pos_x != 0){
        *(*(rompecabezas+pos_x)+pos_y) = *(*(rompecabezas+(pos_x-1))+pos_y);
        --pos_x;
        *(*(rompecabezas+pos_x)+pos_y) = 0;
        cout << endl;
    }
}
void abajo(){
    if(pos_x != 3){
        *(*(rompecabezas+pos_x)+pos_y) = *(*(rompecabezas+(pos_x+1)) + pos_y);
        ++pos_x;
        *(*(rompecabezas+pos_x)+pos_y) = 0;
        cout << endl;
    }
}
void izq(){
    if(pos_y != 0){
        *(*(rompecabezas+pos_x)+pos_y) = *(*(rompecabezas+pos_x)+(pos_y-1));
        --pos_y;
        *(*(rompecabezas+pos_x)+pos_y) = 0;
        cout << endl;
    }
}
void der(){
    if(pos_y != 3){
        *(*(rompecabezas+pos_x)+pos_y) = *(*(rompecabezas+pos_x)+(pos_y+1));
        ++pos_y;
        *(*(rompecabezas+pos_x)+pos_y) = 0;
        cout << endl;
        }
}

void llenar_romp(){
	int num = 1;
	for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
                *(*(rompecabezas+i)+j) = num-1;
                num++;
            }
        }
//	*(*(rompecabezas+3)+3)=0;
}
void mezclar(){
    int a;

    for(int i=0;i<2;i++){
        a=rand()%4;
        switch (a){
            case 0: arriba();
            case 1: abajo();
            case 2: izq();
            case 3: der();
        }
    }
}
void buscar_0(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(*(*(rompecabezas+i)+j) == 0){
				pos_x = i;
				pos_y = j;
			}
		}
	}
}
void tecla(){
	char cTecla;
	cout << "Presione una tecla ..." << endl;

	//while(cTecla != 27)
	while(!ordenado(rompecabezas) )
	{
		cTecla = getch();
		if(cTecla == 0)
			cTecla = getch();
		else
			switch(cTecla)
		{
		case 72:
		    ///Arriba
			arriba();
			break;

		case 80:
			///Abajo
			abajo();
			break;

		case 75:
			///Izquierda
			izq();
			break;

		case 77:
			///Derecha
			der();
			break;
		}
		imprimir();
	}
}

int main()
{
    srand(time(NULL));
	llenar_romp();
	mezclar();
	imprimir();
	buscar_0();
	tecla();
}
