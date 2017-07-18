// hola.cc - programa para saludar en varias lenguas
// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO

#include <iostream>
using namespace std;

void MostrarMenu(){
  cout << "1- Castellano" << endl
       << "2- Catalán" << endl
       << "3- Euskera" << endl
       << "4- Inglés"  << endl
       << "5- Francés" << endl
       << "0- Salir" << endl
       << endl;
}

int main(){
  int opcion;

  do{
    MostrarMenu();
    cin >> opcion;
    switch (opcion){
      case 1: cout << "Hola" << endl;
	break;
      case 2: cout << "Hola" << endl;
	break;
      case 3: cout << "Kaixo" << endl;
	break;
      case 4: cout << "Hello" << endl;
	break;
      case 5: cout << "Bonjour" << endl;
	break;
    }
  } while (opcion != 0);
}