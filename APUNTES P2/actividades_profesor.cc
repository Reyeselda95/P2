#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef struct{
	string  nombre;	
	vector <string> socios;
}Actividad;

string obtenerCampo(string linea, int &i){
	string campo;
	while(i<linea.length() && linea[i]!=','){
		campo+=linea[i];
		i++;
	}
	i++;
	return campo;
}

void procesarLinea(string linea, vector<Actividad> &actividades){
	int i=0;
	string nombreSocio=obtenerCampo(linea, i);
	
	while(i<linea.length()){
		string nombreActividad=obtenerCampo(linea, i);
		bool encontrado=false;
		for (int j=0; j<actividades.size() && !encontrado; j++){
			
			if(nombreActividad==actividades[j].nombre){
				actividades[j].socios.push_back(nombreSocio);
				encontrado=true;
			}
		}
		if (!encontrado){
			Actividad nueva;
			nueva.nombre=nombreActividad;
			nueva.socios.push_back(nombreSocio);
			actividades.push_back(nueva);			
		}
	}	
}

void imprimirActividades(vector<Actividad> &actividades){
	for(int i=0; i<actividades.size(); i++){
		cout << actividades[i].nombre << ": ";
		for (int j=0; j< actividades[i].socios.size();j++){
			if(j!=0)
				cout << ",";
			else 
				cout << actividades[i].socios[j]; 
		}
		cout << endl;
	}	
}

int main(int argc, char *argv[]){
	vector <Actividad> actividades;
	if(argc==2){
		ifstream ficheroEntrada;
		
		ficheroEntrada.open(argv[1], ios::in);
		if(ficheroEntrada.is_open()){
			
			string linea;
			
			getline(ficheroEntrada, linea);
			while(!ficheroEntrada.eof() || linea.length()!=0){
				procesarLinea(linea, actividades);
				linea="";
				getline(ficheroEntrada, linea);
				
			}
			ficheroEntrada.close();
			imprimirActividades(actividades);
		}	
	}
	else
		cerr<< "USO: " << argv[0] << " <nombre fichero>" << endl;
}

