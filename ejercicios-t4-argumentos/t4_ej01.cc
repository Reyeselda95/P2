// Programación 2
// Tema 4 - Ejercicio 1

#include <iostream>
#include <string.h> // Para 'strcmp'
#include <stdlib.h> // Para 'atoi'

using namespace std;

// Calcula el n-ésimo número primo
int numeroPrimo(int n)
{
  int contador=0; // Almacena la cantidad de números primos encontrados
  int i;
  
  // El bucle continúa hasta que encuentre 'n' números primos
  for(i=1;contador<n;i++)
  {
    bool esPrimo=true; // Indica si el número 'i' es primo o no
    
    // Compruebo si 'i' es divisible por algún número que no sea él mismo o la unidad
    for(int j=2;j<i && esPrimo;j++)
    {
      if(i%j==0)
      {
        esPrimo=false;
      }
    }
    // Si hemos encontrado un número primo, incrementamos el contador
    if(esPrimo)
      contador++;
  }

  // La variable 'i' almacena el último número primo encontrado. Decrementamos en una unidad para contrarrestar el último 'i++' que hace el bucle 'for' antes de terminar
  return i-1;
}

// Comprueba los argumentos de entrada y extrae su valor ('nPrimeros' y 'nuevaLinea') si son correctos
bool ProcesarArgumentos(int argc,char *argv[],int &nPrimeros,bool &nuevaLinea)
{
  bool correcto=true;

  // Comprobamos que el número de argumentos sea como máximo de 4 (Ej: primos -N -L 5)
  if(argc>4)
  {
    correcto=false;
  }
  else
  {
    // Recorremos todos los argumentos, empezando por el '1' (el '0' es el propio nombre del programa)
    for(int i=1;i<argc && correcto;i++)
    {
      // Hemos encontrado '-N'
      if(strcmp(argv[i],"-N")==0)
      {
        // Comprobamos que queden parámetros detrás
        if(i<argc-1)
        {
          // Comprobamos que el valor introducido tras '-N' sea mayor que '0' (usamos 'atoi' para convertir el argumento a entero)
          nPrimeros=atoi(argv[i+1]);
          if(nPrimeros<=0)
          {
            correcto=false;
          }
          i++; // Hemos consultado el entero que sigue a '-N', así que incrementamos 'i' para no volver a consultarlo en la siguiente iteración del bucle 'for'
        }
        // Si no hay un entero siguiendo a '-N' se produce error
        else
        {
          correcto=false;
        }
      }
      // Hemos encontrado '-L'
      else if(strcmp(argv[i],"-L")==0)
      {
        nuevaLinea=true;
      }
      // Si hemos encontrado cualquier otra cosa
      else
      {
        correcto=false;
      }
    }
  }
  
  return correcto;
}

int main(int argc,char *argv[])
{
  // Damos los valores por defecto de '-N' y '-L'
  int nPrimeros=10;
  bool nuevaLinea=false;
  
  // Comprobamos los argumentos de entrada del programa
  if(ProcesarArgumentos(argc,argv,nPrimeros,nuevaLinea))
  {
    for(int i=1;i<=nPrimeros;i++)
    {
      cout << numeroPrimo(i);
      // Si tenemos la opción '-L' se muestra un salto de línea en lugar de un espacio en blanco
      if(nuevaLinea)
      {
        cout << endl;
      }
      else
      {
        cout << " ";
      }
    }

  }
  // Si los parámetros no son correctos, se muestra un error por pantalla
  else
  {
    cout << "ERROR: " << argv[0] << " [-N n] [-L]" << endl;
  }
}
