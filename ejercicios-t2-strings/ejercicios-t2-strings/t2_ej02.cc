// Programación 2
// Tema 2 - Ejercicio 2

#include <iostream>
#include <string>

using namespace std;

// Borra todas las apariciones del caracter "c" en "cadena"
string borraCaracterDeCadena(string cadena,char c)
{
  string auxiliar;
  
  for(unsigned i=0;i<cadena.length();i++)
  {
    // Si el carácter no coincide con el buscado, se añade a "auxiliar". De esta forma se elimina en la nueva cadena el carácter buscado
    if(cadena[i]!=c)
    {
      auxiliar+=cadena[i];
    }
  }
  
  return auxiliar;
}

int main()
{
  string cadena="hola, mundo";
  char c='o';
  
  cout << borraCaracterDeCadena(cadena,c) << endl;    
}
