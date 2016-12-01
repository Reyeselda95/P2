// Programación 2
// Tema 2 - Ejercicio 1

#include <iostream>
#include <string>

using namespace std;

// Extrae una subcadena de longitud 'n' en la posición 'p'
string subCadena(string cadena,int n,int p)
{
  string subcadena;

  int tam=cadena.length();
  
  // Extraemos a partir de la posición 'p'. Comprobamos que no se supere el tamaño de la cadena
  for(int i=p;i<tam && i<p+n; i++)
  {
    subcadena+=cadena[i];
  }

  return subcadena;
}

int main()
{
  string cadena="hoooola";
  
  cout << subCadena(cadena,2,5) << endl;
}
