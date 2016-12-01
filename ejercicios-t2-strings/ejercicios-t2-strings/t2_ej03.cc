// Programación 2
// Tema 2 - Ejercicio 3

#include <iostream>
#include <string>

using namespace std;

// Localiza la cadena "a" en "b" y devuelve su posición
int buscarSubCadena(string a,string b)
{
  int pos=-1;
  bool encontrado=false;
  unsigned i;
  unsigned tamA=a.length(),tamB=b.length();
  
  for(i=0;i<tamB && !encontrado;i++)
  {
    // Comprobamos si coincide la primera letra de la subcadena "a" en la cadena "b"
    if(b[i]==a[0])
    {
      bool iguales=true;
      unsigned j;
      // Iteramos mientras que no superemos la longitud de "b" y la de "a", y mientras los caracteres sean iguales
      for(j=1; i+j<tamB && j<tamA && iguales; j++)
      {
        if(b[i+j]!=a[j])
        {
          iguales=false;
        }
      }
      // Si no he encontrado ningún carácter distinto y he encontrado toda la cadena "a" en "b"
      if(iguales && j==tamA)
      {
        encontrado=true;
      }
    }
  }
  if(encontrado)
  {
    pos=i-1; // Descontamos el último incremento que hace el bucle "for" antes de terminar
  }

  return pos;  
}

int main()
{
  string cadena="hoooola";
  string subcadena="oool";
  
  cout << buscarSubCadena(subcadena,cadena) << endl;  
}
