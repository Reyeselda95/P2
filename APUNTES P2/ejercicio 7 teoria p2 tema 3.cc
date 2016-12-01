#include <iostream>
#include <fstream>
using namespace std;

const char kSALIDA[]="alumnos.dat"; // Fichero binario
const char kENTRADA[]="alu.txt"; // Aqui está la información que esta en el ejercicio 5 (dni, nombre, apellido, turno)

typedef struct{
	char dni[10];
	char apelidos[40];
	char nombre[20];
	int turno;
}TAlumno;

int main(){
	ifstream fEntrada;
	ofstream fSalida;
	
	fEntrada.open(kENTRADA, ios::in);
	if(fEntrada.is_open()){
		fSalida.open(kSALIDA, ios::out | ios::binary);
		if(fSalida.is_open()){
			string linea;
			getline(fEntrada, linea);
			while(!fEntrada.eof()){
				strncpy(alu.dni, line.c_str(), 9);
				alu.dni[9]='\0';
				
				getline(fEntarda, linea);
				strncpy(alu.apellidos, linea._str(),39);
				alu.apellidos[39]='\0';
				
				getline(fEntrada, linea);
				strncpy(alu.nombre, linea.c_str(),19);
				alu.nombre[19]='\0';
				
				fEntrada >> alu.turno;
				fEntrada.get();
				
				fSalida.write((const char *)&alu, sizeof(alu));
				
				//getline(fEntrada, linea);
				//alu.turno=atoi(linea.c_str());
				
				getline(fEntrada, linea);
			}
			
			fSalida.close();
		}
		else
			cout << "ERROR: no se ha podido abrir el archivo"
	}
	
	
	
	
	
}
