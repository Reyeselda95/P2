#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef struct 
{
  int id; // El identificador de una nueva cancion debe ser igual a idNextSong
  string title;
  string artist;
  string album;
  string genre;
  string url;
} Song;

typedef struct
{
  vector<Song> songs;
  int idNextSong;  // Cada vez que se anyada una cancion a la coleccion, incrementar idNextSong
} Collection;


// Función para inicializar los valores de la colección
Collection createCollection()
{
  Collection collection;
  collection.idNextSong=1;

  return collection;
}

// Implementar resto de funciones

int main()
{
  Collection collection=createCollection();
  
  // Implementar menu principal
  return 0;
}
