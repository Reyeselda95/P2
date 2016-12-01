// Programación 2
// Tema 2 - Ejercicio 5

#include <iostream>
#include <string>

using namespace std;

// Indica si la cadena pasada como parámetro es palíndromo (es decir, se lee igual al derecho que al revés)
bool esPalindromo(string cadena)
{
  bool esPalindromo=true;
  unsigned tam=cadena.length();
  
  // Comparamos la primera mitad de la cadena con la otra mitad
  for(unsigned i=0;i<tam/2 && esPalindromo;i++)
  {
    // Comparamos cada carácter del inicio de la cadena con su opuesto del final de la cadena
    if(cadena[i]!=cadena[tam-1-i])
    {
      esPalindromo=false;
    }
  }
  
  return esPalindromo;
}

int main()
{
  string cadena="hola,aloh";
  string cadena2="hola, aloh";
  
  cout << esPalindromo(cadena) << endl;
  cout << esPalindromo(cadena2) << endl;
}
