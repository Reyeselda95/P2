#include <iostream>
#include <fstream>
using namespace std;

const char kNOM []="alumnos.dat";

typedef struct{
	char dni[10];
	char apelidos[40];
	char nombre[20];
	int turno;
}TAlumno;

int main(){
	ifstream fichero;
	fichero.open(kNOM, ios::Init | ios::binary){
	if(fichero.is_open()){
		TAlumno alu;
		
		fichero.read((char *)&alu,sizeof(alu));
		while(!fichero.eof()){
			if(alu.turno==7){
				cout << alu.dni << endl;
			}
			fichero.read((char *)&alu, sizeof(alu));
		}
		fichero.close();
	}
	fichero.close();
	else 
		cout < "ERROR: nose ha podido abrir el fichero"
	
}
	
	
	
}
