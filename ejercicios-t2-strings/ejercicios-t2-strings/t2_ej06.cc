// Programación 2
// Tema 2 - Ejercicio 6

#include <iostream>
#include <string>

using namespace std;

// Crea un palíndromo a partir de una cadena
string creaPalindromo(string cadena)
{
  string palindromo=cadena; // Utilizamos una cadena auxiliar
  unsigned tam=palindromo.length();
  
  // Recorremos desde el final de la cadena hasta el principio
  for(unsigned i=tam-1;i>=0;i--)
  {
    // Concatenamos al final de la cadena todos los caracteres en orden inverso
    palindromo+=palindromo[i];
  }

  return palindromo;
}

int main()
{
  string cadena="hola, mundo";
  
  cout << creaPalindromo(cadena) << endl;
}
