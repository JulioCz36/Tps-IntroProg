#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
	//un funcion que pone en null el tiempo para el rand, y sean diferentes al abrir el programa.
	srand(time(NULL));
	
	//introducimos valor inicial
	int n;
	cout<<"Ingrese Monedas (1 a 10)"<<endl;
	cin>>n;
	
	//aseguramos que sea entre ese rango
	while(n>10 || n<1){
		cout<<"Ingrese Monedas (1 a 10)"<<endl;
		cin>>n;
	}
	
	//Mostramos cuantas tiradas tenemos.(le agregue un detalle).
	if(n==1){
		cout<<endl;
		cout<<"======================"<<endl;
		cout<<"Tenes "<<n<<" tirada"<<endl;
		cout<<"======================"<<endl;
	}else{
		cout<<endl;
		cout<<"======================"<<endl;
		cout<<"Tenes "<<n<<" tiradas"<<endl;
		cout<<"======================"<<endl;
	}
	
	//guardamos cuantas veces gano.
	int vecesGanadas = 0;
	
	//mostramos los valores a medida que aprieta p.
	for(int i=0;i<n;i++){
		bool seApreto = true;
		
		cout<<endl;
		cout<<"Tirada "<<i+1<<endl;
		cout<<"Presione P para tirar"<<endl;
		
		while(seApreto){
			if(kbhit()) { 
				int tecla=getch();
				if(tecla == 'p'){
					int numero1 = rand() % 3 + 1;
					int numero2 = rand() % 3 + 1;
					int numero3 = rand() % 3 + 1;
					if( numero1==numero2 && numero1==numero3){
						vecesGanadas++;
						cout<<endl;
						cout<<"--------------------------"<<endl;
						cout<<"Valores: "<<numero1<<" "<<numero2<<" "<<numero3<<endl;
						cout<<"Son Iguales"<<endl;
						cout<<"--------------------------"<<endl;
						
					}else{
						cout<<endl;
						cout<<"--------------------------"<<endl;
						cout<<"Valores: "<<numero1<<" "<<numero2<<" "<<numero3<<endl;
						cout<<"--------------------------"<<endl;
					}
					seApreto = false;
				}
			}
		}
	}
	//mostramos cuantas veces gano.
	cout<<endl;
	cout<<"********************************"<<endl;
	cout<<"Ganaste "<<vecesGanadas<<" veces "<<endl;
	cout<<"********************************"<<endl;
	
	//un detalle cuando ejecuto el .exe se cierra y no muestra las veces ganadas.
	cout<<endl;
	cout << "Presiona Enter para salir";
	cin.ignore();
	cin.get();
	
	
	return 0;
}

