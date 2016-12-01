#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct{
	string name;
	vector <string> activities;
}Users;


void activities(ostream &f, Users &u){
	string linea;
	int prim=0;
	int j=0
	if (f.is_open()){
		getline(f, linea);
		while (!f.eof()){
			string leido;
			for(int i=0;i<l.length();i++){
				if(l[i]==","){
					prim++;
					if(prim<=1){
						u.name.push_back(leido);
					}
					else{
						u.activities[j].push_back(leido);
						j++;						
					} 					
				}
					
			}
			else{
				
			}
		}
			
	getline(f, linea);
	}

	else
		cout << "El fichero no se ha podido abrir." << endl;		
}

int main(int argc, char *argv[]){
	ostream f;
	Users usuarios;
	if(argc==2){
		f.open(argv[1], ios::in);
		if (f.is_open()){
			activities(f, usuarios);
			f.close();
		}
		else
			cout << "El fichero no se ha podido abrir." << endl;		
	}
	else 
		cout << "No se ha pasado el nombre del fichero." << endl;

}
