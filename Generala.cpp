#include <iostream>
#include <conio2.h>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int tirarDado(){
	int valor = rand() % 6 + 1;
	return valor;
}
	
int todoAl(vector<int>v, int nro ){
	int c = 0;
	
	for(size_t i = 0;i < v.size();i++){
		if(v[i] == nro){
			c++;
		}
	}
	return nro * c;
}

int full(vector<int>v){
	int iguales3 = 0, iguales2 = 0;
		
	for(size_t i=0;i < v.size();i++){
		int c = 0;
		for(size_t j = 0;j < v.size();j++){
			if(v[i] == v[j]){
				c++;
			}
		}
		if(c == 2 && iguales2 !=v[i]){
			iguales2 = v[i];
		}
		if(c == 3 && iguales3 !=v[i]){
			iguales3= v[i];
		}
	}
	
	if(iguales2 != 0 && iguales3!=0){
		return 30;
	}
	return 0;
}
	
int poker(vector<int>v){
	
	for(size_t i=0;i < v.size();i++){
		int c = 0;
		for(size_t j = 0;j < v.size();j++){
			if(v[i] == v[j]){
				c++;
			}
		}
		if(c == 4){
			return 40;
		}
	}
	return 0;
}

int escalera(vector<int>v){
	sort(v.begin(), v.end());
	
	bool es_escalera = (v == vector<int>{1, 2, 3, 4, 5} || v == vector<int>{2, 3, 4, 5, 6});
	
	if(es_escalera){
		return 50;
	}
	return 0;
}
	
int generala(vector<int>v){
	int c = 0, valor = v[0];
	
	for(size_t i = 1;i < v.size();i++){
		if(v[i] == valor){
			c++;
		}
	}
	if(c == 4){
		return 60;
	}
	
	return 0;
}

	
int obtenerPuntajeMaximo(vector<int> v){
	vector<int> valores;
	
	for(int i = 0;i<6;i++){
		valores.push_back(todoAl(v,i+1));
	}
	
	valores.push_back(full(v));
	valores.push_back(poker(v));
	valores.push_back(escalera(v));
	valores.push_back(generala(v));
	
	
	return *max_element(valores.begin(),valores.end());
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	char opcion;
	
	do{
	vector<int>tiradas;
	
	cout<<"======================"<<endl;
	cout<<"      GENERALA"<<endl;
	cout<<"======================"<<endl;
	
	
	//TIRA JUGADOR 1 
	
	bool seApreto = true;
	cout<<endl<<"Presione T para tirar jugador 1"<<endl;
	while(seApreto){
		if(kbhit()) { 
			int tecla=getch();
			if(tecla == 't'){
				for(int i=0;i<5;i++){
					tiradas.push_back(tirarDado());
				}
				seApreto = false;
			}
		}
	}
	
	cout<<endl<<"Tirada jugador 1: ";
	for(int i=0;i<5;i++){
		cout<< tiradas[i]<<" "; 
	}
	
	cout<<endl<<endl<<"----------------------------"<<endl;
	for(int i = 0;i<6;i++){
		cout<<"Todo al "<< i + 1<<": " <<todoAl(tiradas,i+1)<<endl;
	}
	
	cout<<"Full: "<<full(tiradas)<<endl;
	cout<<"Poker: "<<poker(tiradas)<<endl;
	cout<<"Escalera: "<<escalera(tiradas)<<endl;
	cout<<"Generala: "<<generala(tiradas)<<endl;
	cout<<"----------------------------"<<endl;
	
	int puntaje_jugador1 = obtenerPuntajeMaximo(tiradas);
	cout << "Puntaje del jugador 1: " <<puntaje_jugador1<<endl;
	
	
	//TIRA JUGADOR 2

	
	seApreto = true;
	cout<<endl<<"Presione T para tirar jugador 2"<<endl;
	while(seApreto){
		if(kbhit()) { 
			int tecla=getch();
			if(tecla == 't'){
				for(int i=0;i<5;i++){
					tiradas[i]=tirarDado();
				}
				seApreto = false;
			}
		}
	}
	cout<<endl<<"Tirada jugador 2: ";
	for(int i=0;i<5;i++){
		cout<< tiradas[i]<<" "; 
	}
	
	cout<<endl<<endl<<"----------------------------"<<endl;
	for(int i = 0;i<6;i++){
		cout<<"Todo al "<< i + 1<<": " <<todoAl(tiradas,i+1)<<endl;
	}
	
	cout<<"Full: "<<full(tiradas)<<endl;
	cout<<"Poker: "<<poker(tiradas)<<endl;
	cout<<"Escalera: "<<escalera(tiradas)<<endl;
	cout<<"Generala: "<<generala(tiradas)<<endl;
	cout<<"----------------------------"<<endl;
	
	int puntaje_jugador2 = obtenerPuntajeMaximo(tiradas);
	cout << "Puntaje del jugador 2: " <<puntaje_jugador2<<endl<<endl;
	
	// Determinar el ganador
	if (puntaje_jugador1 > puntaje_jugador2) {
		cout<<"********************************"<<endl;
		cout<<"  El ganador es el jugador 1!"<<endl;
		cout<<"********************************"<<endl;
	} else if (puntaje_jugador2 > puntaje_jugador1) {
		cout<<"********************************"<<endl;
		cout<<"  El ganador es el jugador 2!"<<endl;
		cout<<"********************************"<<endl;
	} else {
		cout<<"********************************"<<endl;
		cout<<"         Es un empate!"<<endl;
		cout<<"********************************"<<endl;
	}
	
	// Preguntar al usuario si quiere reiniciar o salir
	cout <<endl<< "Presione 'R' para reiniciar o 'S' para salir" <<endl<<endl;
	while (true) {
		if (kbhit()) {
			int tecla = getch();
			if (tecla == 'r' || tecla == 'R') {
				opcion = 'r';
				break;
			} else if (tecla == 's' || tecla == 'S') {
				opcion = 's';
				break;
			}
		}
	}
	}while (opcion == 'r');
	
	return 0;
}

