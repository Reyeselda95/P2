// DNI1 45931406 REYES ALBILLAR, ALEJANDRO
// DNI2 74245842 PASCUAL GOMEZ, ALEJANDRO

#include <iostream>
#include <vector>
#include <fstream> 

using namespace std;

typedef struct {
  int id; // El identificador de una nueva cancion debe ser igual a idNextSong
  string title;
  string artist;
  string album;
  string genre;
  string url;
} Song;

typedef struct {
  vector<Song> songs;
  int idNextSong;  // Cada vez que se anyada una cancion a la coleccion, incrementar idNextSong
} Collection;


// Función para inicializar los valores de la colección
Collection createCollection(){
  Collection collection;
  collection.idNextSong=1;
  return collection;
}

//Este módulo pide los datos de la canción
Song demandSong(Song &song){
  cout<<"Title: ";
  getline(cin,song.title);
  cout<<"Artist: ";
  getline(cin,song.artist);
  cout<<"Album: ";
  getline(cin,song.album);
  cout<<"Genre: ";
  getline(cin,song.genre);
  cout<<"Url: ";
  getline(cin,song.url);
  return(song);
}

//Función que busca si se ha introducido ya una canción
bool isSongInCollection(const Collection &collection, Song song){
  int i;
  bool repetida;
  int tam=collection.songs.size();
  repetida=false;
  for(i=0;i<tam;i++){
    if(song.title == collection.songs[i].title && song.artist == collection.songs[i].artist){
      repetida=true;
    }
  }
  return(repetida);
}


//Opción del menú que añade una cancion a la colección
bool addSong(Collection &collection){
  bool addSong;
  Song song;
  demandSong(song);
  
  if(isSongInCollection(collection, song)==true){
    addSong=false;
    cout<<"The song "<<song.title<<" is already in the collection"<<endl;
  }
  else{
    addSong=true;
    song.id=collection.idNextSong;
    collection.songs.push_back(song);
    collection.idNextSong++;
  }
  return(addSong);
}

//Procedimiento que imprime la lista de canciones
void printSong(Song song){
  cout << song.id << " | " 
  << song.title << " | " 
  << song.artist << " | " 
  << song.album << " | "
  << song.genre;
}

//Opción del menú que muestra las canciones existentes en la colección
bool showCollection(const Collection &collection){
  int i,tam;
  bool showCollection=false;
  tam=collection.songs.size();
  string buscar;
  cout << "Search: ";
  getline(cin,buscar);

  for(i=0;i<tam;i++){
    if (collection.songs[i].title.find(buscar)!=string::npos ||
      collection.songs[i].artist.find(buscar)!=string::npos || 
      collection.songs[i].album.find(buscar)!=string::npos ||
      collection.songs[i].genre.find(buscar)!=string::npos){
      printSong(collection.songs[i]);
    cout << endl;
    showCollection=true;
      }
  }
  if(showCollection==false)
    cout << "No results" << endl;
  return showCollection;
}

//Función que busca el identificador de la canción en collection
int findIdSong(const Collection &collection, int id){
  int tam, n, i;
  n=-1;
  tam= collection.songs.size();
  for(i=0; i<tam; i++){
    if (id==collection.songs[i].id)
      n=i;
  }
  return n;
}

void  editSong(Collection &collection){
  int id, n, option;
  if(showCollection(collection)==true){
    cout << "Select song: ";
    cin >> id;
    cin.get();
    n=findIdSong(collection, id);
    if(n==-1)
      cout << "Error: Unknown song " << id << endl;
    else {
	do{
      cout << "Edit (1-Title, 2-Artist, 3-Album, 4-Genre, 5-Url): ";
	  cin>> option;
	  cin.get();
      switch(option){
	case 1:
	  cout << "Title: ";
	  getline(cin, collection.songs[n].title);
	  break;
	case 2:
	  cout << "Artist: ";
	  getline(cin, collection.songs[n].artist);
	  break;
	case 3:
	  cout << "Album: ";
	  getline(cin, collection.songs[n].album);
	  break;
	case 4:
	  cout << "Genre: ";
	  getline(cin, collection.songs[n].genre);
	  break;
	case 5:
	  cout << "Url: ";
	  getline(cin, collection.songs[n].genre);
	  break;
	default:
	  cout << "Error: Unknown option" <<endl;
	  break;
      }
	  }while(option<1 || option>5);
    }
  }
}

void deleteSong(Collection &collection){
  int id, n;
  char option;
  if(showCollection(collection)==true){
    cout << "Select song: ";
    cin >> id;
    cin.get();
    n=findIdSong(collection, id);
    if(n==-1)
      cout << "Error: Unknown song " << id << endl;
    else{
      cout << "Delete ";
      printSong(collection.songs[n]);
      cout << "? (Y/N): ";
      cin >> option;
      cin.get();
      if(option=='Y')
	collection.songs.erase(collection.songs.begin()+n);
      else
	cout << "Song not deleted" << endl;
    }
  }	
}

// Implementar resto de funciones
int main(){
  Collection collection=createCollection();
  char option;  
  do{
    cout << "----------------------------------------" << endl
    << "------------- Mini Tunes ---------------" << endl
    << "----------------------------------------" << endl
    << "1- Add song" << endl
    << "2- Edit song" << endl
    << "3- Delete song" << endl
    << "4- Show collection" << endl
    << "5- Manage playlist" << endl
    << "6- Import iTunes JSON data" << endl
    << "7- Export playlist to XSPF" << endl
    << "8- Save data" << endl
    << "9- Load data" << endl
    << "0- Play playlist" << endl
    << "q- Quit" << endl
    << "Option: ";
    cin >> option;
    cin.get();
    switch(option){
      case '1':
	addSong(collection);
	break;
      case '2':
	editSong(collection);
	break;
      case '3': 
	deleteSong(collection);
	break;
      case '4': 
	showCollection(collection);
	break;
      case '5':
	break;
      case '6':
	break;
      case '7':
	break;
      case '8':
	break;
      case '9':
	break;
      case '0':
	break;
      case 'q':
	break;
      default:
	cout << "Error: Unknown option" << endl;
	break;
    }
  }while(option!='q');
  return 0;
}
