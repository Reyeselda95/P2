// Programación 2
// Tema 2 - Ejercicio 4

#include <iostream>
#include <string>

using namespace std;

const int numLetras='Z'-'A'+1; // Almacena cuantas letras hay en el alfabeto

// Indica si un carácter es mayúscula
bool esMayuscula(char c)
{
  return(c>='A' && c<='Z');
}

// Indica si un carácter es minúscula
bool esMinuscula(char c)
{
  return(c>='a' && c<='z');
}

// Comprueba si el carácter es una letra (mayúscula o minúscula)
bool esLetra(char c)
{
  return(esMayuscula(c) || esMinuscula(c));
}

// Codifica un carácter en otro a partir de un código entero
string codifica(string cadena,int codigo)
{
  string modificada;
  
  codigo=codigo%numLetras; // Nos aseguramos que el código no es mayor que el número de letras
  
  for(unsigned i=0;i<cadena.length();i++)
  {
    // Si el carácter es una letra
    if(esLetra(cadena[i]))
    {
      char codificado;
      
      // Comprobamos si es mayúscula y al sumar el código al carácter superamos la letra 'Z', o si es minúscula y al sumar el código al carácter superamos la letra 'z'
      if((esMayuscula(cadena[i]) && (cadena[i]+codigo)>'Z') || (esMinuscula(cadena[i]) && (cadena[i]+codigo)>'z'))
      {
        codificado=(cadena[i]+codigo)-numLetras;
      }
      // Si no, sumamos el código sin más
      else
      {
        codificado=(cadena[i]+codigo);
      }
      // Añadimos el carácter codificado a la cadena
      modificada+=codificado;
    }
    // Si no es letra, no se codifica, se añade tal cual
    else
    {
      modificada+=cadena[i];
    }
  }

  return modificada;
}

int main()
{
  string cadena="hola, mundo";
  int codigo=3;
  
  cout << codifica(cadena,codigo) << endl;  
}
