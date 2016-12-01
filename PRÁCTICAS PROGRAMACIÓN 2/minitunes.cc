// DNI1 45931406 REYES ALBILLAR, ALEJANDRO
// DNI2 74245842 PASCUAL GOMEZ, ALEJANDRO
 
#include <iostream>
#include <vector>
#include <fstream> 
#include <cstdlib>
#include <cstring>
#include "Player.h"
 
using namespace std;
 
const int kTITLE=30;
const int kARTIST=60;
const int kALBUM=60;
const int kGENRE=30;
const int kURL=255;

typedef struct{
  int id;
  char title[kTITLE];
  char artist[kARTIST];
  char album[kALBUM];
  char genre[kGENRE];
  char url[kURL];
}SongBin;
 
 
 
typedef struct {
  int id; // El identificador de una nueva cancion debe ser igual a idNextSong
  string title;
  string artist;
  string album;
  string genre;
  string url;
}Song;
 
typedef struct {
  vector<Song> songs;
  int idNextSong;  // Cada vez que se anyada una cancion a la coleccion, incrementar idNextSong
}Collection;
 
typedef struct{
  vector<int> idSong;  // Este vector contendrá los id de las canciones seleccionadas
}Playlist;
 
// Función para inicializar los valores de la colección
Collection createCollection(){
  Collection collection;
  collection.idNextSong=1;
  return collection;
}
 
//Este módulo pide los datos de la canción
Song demandSong(){
  Song song;
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
  Song song=demandSong();
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
  if(showCollection==false){
    cout << "No results" << endl;
  }
  return showCollection;
}
 
//Función que busca el identificador de la canción en collection
int findIdSong(const Collection &collection, int id){
  int tam, n, i;
  n=-1;
  tam= collection.songs.size();
  for(i=0; i<tam; i++){
    if (id==collection.songs[i].id){
      n=i;
    }
  }
  return n;
}

// Procedimiento que edita los valores de una cancion
void  editSong(Collection &collection){
  int id, n, option;
  if(showCollection(collection)==true){
    cout << "Select song: ";
    cin >> id;
    cin.get();
    n=findIdSong(collection, id);
    if(n==-1){
      cout << "Error: Unknown song " << id << endl;
    }
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

// Procedimiento que borra una cancion de la coleccion
void deleteSong(Collection &collection){
  int id, n;
  char option;
  if(showCollection(collection)==true){
    cout << "Select song: ";
    cin >> id;
    cin.get();
    n=findIdSong(collection, id);
    if(n==-1){
      cout << "Error: Unknown song " << id << endl;
    }
    else{
      cout << "Delete ";
      printSong(collection.songs[n]);
      cout << "? (Y/N): ";
      cin >> option;
      cin.get();
      if(option=='Y'){
	collection.songs.erase(collection.songs.begin()+n);
      }
      else{
	cout << "Song not deleted" << endl;
      }
    }
  }
}

//Procedimiento que imprime una cancion de playlist en formato id: title(artist)
void printPlaylistSong(Song song){
  cout << song.id << ": " << song.title << " (" << song.artist << ")" << endl;
}
 
// Procedimiento que imprime cada cancion del procedimiento removeSongsPlaylist
void printPlaylist(const Playlist &playlist, const Collection &collection, int position){
  for(unsigned int i=0; i<playlist.idSong.size();i++){
    int k;
    k=i;
    for (unsigned int j=0;j<collection.songs.size(); j++){
      if (playlist.idSong[i]==collection.songs[j].id){
	if (k==position) {
	  cout << ">";// la cancion que se esta reproduciendo actualmente (que esta en la posicion position del vector)
		      // se mostrara con un simbolo >. Si el valor de position es -1, no se mostrara el simbolo > delante de ninguna cancion.
	}	      // Se llamará a este módulo por cada cancion
	else{
	  cout << " ";
	}
	printPlaylistSong(collection.songs[j]);
      }
    }
  }
}
 
// Procedimiento que añade una cancion a la playlist
void addSongsPlaylist(Playlist &playlist, const Collection &collection){
  string id, select;
  int n;
  bool anyadido;
  if(collection.songs.size()<=0){
    cout << "Empty collection" << endl;
  }
  else{
    showCollection(collection);
    cout << "Select songs (list separated by spaces): ";
    getline(cin, select); //Usar atoi para transformar char a int
    for(unsigned int i=0; i<=select.length(); i++){
      anyadido=false;
      if (select[i]== ' ' || i==select.length()){
	n=atoi(id.c_str());
	for(unsigned int j=0;j<collection.songs.size(); j++){
	  if(n==collection.songs[j].id){
	    anyadido=true;
	    playlist.idSong.push_back(n);
	  }
	}
	if(anyadido==false){
	  cout << "Error: Unknown song " << n << endl;
	}
	id="";
      }
      else {
	id+=select[i];
      }
    }
  }
}
 
// Procedimiento que quita una cancion a la playlist
void removeSongsPlaylist(Playlist &playlist, const Collection &collection){
  string id, select;
  bool isInPlaylist=false;
  int pos=-1;
  int n;
  if(playlist.idSong.size()<=0){
    cout << "Empty playlist" << endl;
  }
  else{
    printPlaylist(playlist, collection, pos);		
    cout << "Select songs (list separated by spaces): " ;
    getline(cin, select); //Usar atoi para transformar char a int
    if(select.size()!=0){
      for(unsigned int i=0; i<=select.length(); i++){
	if (select[i]== ' ' || i==select.length()){
	  isInPlaylist=false;
	  n=atoi(id.c_str());
	  for(unsigned int j=0; j<playlist.idSong.size(); j++){
	    if(n==playlist.idSong[j]){
	      isInPlaylist=true;
	      playlist.idSong.erase(playlist.idSong.begin()+j);
	      j--;
	    }
	  }
	  if(isInPlaylist==false){
	    cout << "Error: Song " << n << " not in playlist" << endl;
	  }
	  id="";
	}
	else {
	  id+=select[i];
	}	 
      }
    }
  }
}

// Procedimiento que borra todas las canciones de la playlist
void clearSongsPlaylist(Playlist &playlist){
  char opcion;
  if(playlist.idSong.size()<=0){
    cout<< "Empty playlist" << endl;
  }
  else{
    cout << "Clear playlist? (Y/N):";
    cin >> opcion;
    cin.get();
    if(opcion=='Y'){
      playlist.idSong.clear();
    }
  }
}

// Procedimiento para administrar la playlist
void managePlaylist(Playlist &playlist, const Collection &collection){
  char option;
  do{
    cout << "1- Add songs" << endl
    << "2- Remove songs" << endl
    << "3- Clear" << endl
    << "q- Back to main menu" << endl
    << "Option: ";
    cin >> option;
    cin.get();
    switch(option){
      case '1':
	addSongsPlaylist(playlist, collection);
	break;
      case'2':
	removeSongsPlaylist(playlist, collection);
	break;
      case'3':
	clearSongsPlaylist(playlist);
	break;
      case 'q':
	break;
      default:
	cout << "Error: Unknown option" << endl;
	break;
    }
  }while(option!='q');
}

// procedimiento que extrae un dato de una linea a partir de un campo específico
string getField(string line, string field){
  int tam=line.length();
  int encontrado, i;
  bool end=false;
  string lectura;
  if(line.find(field)!=string::npos){
    encontrado=line.find(field);
    for(i=encontrado+field.length();i<tam && end==false;i++){
      if(line[i]!='\"'){
	lectura.push_back(line[i]);
      }	
      else{
	end=true;
      }
    }
  }
  return(lectura);
}

// procedimiento que extrae una canción de una línea del archivo especificado en importJSON
Song getSongFromJSONline(string JSONline){
  Song song;
  song.title=getField(JSONline, "trackName\":\"");
  song.album=getField(JSONline, "collectionName\":\"");
  song.artist=getField(JSONline, "artistName\":\"");
  song.genre=getField(JSONline, "primaryGenreName\":\"");
  song.url=getField(JSONline, "previewUrl\":\"");
  return(song);
}

// procedimiento que importa una lista de canciones según el diseño obtenible a partir de la instrucción 
// wget itunes.apple.com/search?term="Beatles" -q -O beatles.txt
bool importJSON(Collection &collection, string filename){
  ifstream fichero;
  Song song;
  bool ficheroAbierto=false;
  fichero.open(filename.c_str(),ios::in);
  if(fichero.is_open()){
    string linea;
    ficheroAbierto=true;
    getline(fichero, linea);
    while(!fichero.eof()){
      if(linea.find("kind\":\"song")!=string::npos){
	song=getSongFromJSONline(linea);
	if(isSongInCollection(collection,song)==false){ //devuelve true si está en la colección
	  song.id=collection.idNextSong;
	  collection.songs.push_back(song);
	  collection.idNextSong++;
	}
	else{
	  cout << "The song " << song.title << " is already in the collection" << endl;
	}
      }
      getline(fichero, linea);
    }
    fichero.close();
  }
  else{
    cout << "Error opening file " << filename << endl;
  }
  return(ficheroAbierto);	
}


// Es llamado para cada cancion e imprime en un fichero la informacion de la playlist
void printXSPFSong(Song song, ofstream &f){
  f << "  <track>" << endl
  << "   <title>" << song.title << "</title>" << endl
  << "   <creator>" << song.artist << "</creator>" << endl
  << "   <album>" << song.album << "</album>" << endl
  << "   <location>" << song.url << "</location>" << endl
  << "   <meta rel=\"genre\">" << song.genre << "</meta>" << endl
  << "  </track>" << endl;
}
  
  
//guarda el playlist en un archivo XSPF
bool saveXSPFPlaylist(const Playlist &playlist, const Collection &collection){
  bool disponible=false;
  string filename;
  ofstream fichero;
  //si playlist esta vacio no hace nada y devuelve false
  if(playlist.idSong.size()<=0){
    cout << "Empty playlist" << endl;
  }
  //si playlist no esta vacio pide un nombre donde guardarlo
  else{
    cout<<"Filename: ";
    getline(cin, filename);
    fichero.open(filename.c_str());
    if(fichero.is_open()){
      fichero << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl
      << "<playlist version=\"1\" xmlns=\"http://xspf.org/ns/0/\">" << endl
      << " <title>MiniTunes playlist</title>" << endl
      << " <trackList>" << endl;
      for(unsigned int i=0; i<playlist.idSong.size();i++){
	int n;
	n=findIdSong(collection, playlist.idSong[i]);
	printXSPFSong(collection.songs[n], fichero);
      }
      fichero << " </trackList>" << endl<< "</playlist>";
      fichero.close();
    }
    else{
      cout << "Error opening file " << filename << endl;
    }
    disponible=true;
  }
  return(disponible);
}



//lee del fichero binario los datos de la playlist y los guarda en ella, borrando playlist si exxistía anteriormente
bool readPlaylist(Playlist &playlist, ifstream &f){
  int tam, id;
  bool abierto=false;
  playlist.idSong.clear();
  if(f.is_open()){
    f.read((char *) &tam, sizeof(tam));
    for(int i=0; i<tam; i++){
      f.read((char *) &id, sizeof (id));
      playlist.idSong.push_back(id);
    }
    abierto=true;
  }
  return(abierto);
}

// Transforma los datos de una canción a binario
SongBin songToBinary(const Song &song){
  SongBin songbin;
  songbin.id=song.id;
  strncpy(songbin.title, song.title.c_str(), kTITLE);//errores
  strncpy(songbin.artist, song.artist.c_str(),kARTIST);//errores
  strncpy(songbin.album, song.album.c_str(),KALBUM);//errores
  strncpy(songbin.genre, song.genre.c_str(),kGENRE);//errores
  strncpy(songbin.url, song.url.c_str(),kURL);//errores
  return(songbin);
}

// escribe los datos de la colección en el archivo binario
bool writeCollection(const Collection &collection, ofstream &f){
  SongBin songbin;
  int idNextSong;
  bool abierto=false;
  if(f.is_open()){
    abierto=true;
    idNextSong=collection.idNextSong;
    f.write((const char *) &idNextSong, sizeof(idNextSong));
    for(unsigned int i=0;i<collection.songs.size();i++){
      songbin=songToBinary(collection.songs[i]);
      f.write((const char *) &songbin, sizeof(songbin));
    }
  }
  return(abierto);
}

// escribe los datos de la playlist en el archivo binario
bool writePlaylist(const Playlist &playlist, ofstream &f){
  int num;
  bool abierto=false;
  if(f.is_open()){
    abierto=true;
    num=playlist.idSong.size();
    f.write((const char *) &num, sizeof(num));
    for(int i=0; i<num; i++){
      f.write((const char *) &playlist.idSong[i], sizeof(playlist.idSong[i]));	 
    }
  }
  return(abierto);
}

// procedimiento que guarda los datos de collection y playist en un archivo binario
bool saveData(const Collection &collection, const Playlist &playlist){
  ofstream fichero;
  bool abierto=false;
  if(collection.songs.size()<=0){
    cout << "Empty collection" << endl;
  }
  else{
    fichero.open("minitunes.dat",ios::out|ios::binary);
    if(fichero.is_open()){
      abierto=true;
      writePlaylist(playlist, fichero);
      writeCollection(collection, fichero);
      fichero.close();      
    }
    else{
      cout<<"Error opening file minitunes.dat"<<endl;
    }
  }
  return(abierto);
}


// pasa una cancion de SongBin a Song
Song binaryToSong(const SongBin &songbin){
  Song song;
  song.id=songbin.id;
  song.artist=songbin.artist;
  song.title=songbin.title;
  song.genre=songbin.genre;
  song.album=songbin.album;
  song.url=songbin.url;
  return(song);
}

// lee del fichero binario los datos dela colección y los almacena borrando la colección si existia previamente
bool readCollection(Collection &collection, ifstream &f){
  SongBin songbin;
  Song song;
  int idNextSong;
  bool abierto=false;
  collection.songs.clear();
  if(f.is_open()){
    abierto=true;
    f.read((char *) &idNextSong, sizeof(idNextSong));
    collection.idNextSong=idNextSong;
    f.read((char *) &songbin, sizeof(songbin));
    while(!f.eof()){
      song=binaryToSong(songbin);
      if(isSongInCollection(collection, song)==false ){
	collection.songs.push_back(song);
      }
      f.read((char *) &songbin, sizeof(songbin));
    }
  }
  return(abierto);
}

// lee los datos de un fichero binario y los introduce en la colección y la playlist
bool loadData(Collection &collection, Playlist &playlist){
  ifstream fichero;
  bool abierto=false;
  fichero.open("minitunes.dat", ios::in | ios::binary);
  if(fichero.is_open()){
    abierto=true;
    readPlaylist(playlist, fichero);
    readCollection(collection, fichero);
    fichero.close();
  }
  else{
    cout << "Error opening file minitunes.dat" << endl;
  }
  return(abierto);
}

// modulo que reproduce el contenido de la playlist 
void playPlaylist(const Playlist &playlist, const Collection &collection){
  if (playlist.idSong.size()<=0){
    cout << "Empty playlist" << endl;
  }
  else{
    Player player;
    unsigned int pos=0;
    char command;
    int i;
    printPlaylist(playlist, collection, pos);
    i=findIdSong(collection, playlist.idSong[pos]);
    playSong(collection.songs[i].url, player);
    do{
      cout << "Command: ";
      cin >> command;
      cin.get();
      switch(command){
	case 'p':
	  pauseResumeSong(player);
	  break;
	case 's':
	  if(pos==playlist.idSong.size()-1){
	    pos=0;
	  }
	  else{
	    pos++;
	  }
	  printPlaylist(playlist, collection, pos);
	  i=findIdSong(collection, playlist.idSong[pos]);
	  playSong(collection.songs[i].url, player);
	  break;
	case 'a':
	  if(pos==0){
	    pos=playlist.idSong.size()-1;
	  }
	  else{
	    pos--;
	  }
	  printPlaylist(playlist, collection, pos);
	  i=findIdSong(collection, playlist.idSong[pos]);
	  playSong(collection.songs[i].url, player);
	  break;
	case 'q':
	  endPlayer(player);
	  break;
	default:
	  cout << "Options:" << endl
	  << "p: Pause/resume" << endl
	  << "s: Next song" << endl
	  << "a: Previous song" << endl
	  << "q: Quit" << endl;
	  break;
      }
    }while(command!='q');
  }
}

// procediento que administra los argumentos
bool manageArguments(int argc, char *argv[], Collection &collection, Playlist &playlist){
  bool argumento=true;
  string filename;
  if(argc==2){
    if(!strcmp(argv[1],"-d")){
      loadData(collection, playlist);
    }
    else if(!strcmp(argv[1],"-i")){
    }
    else{
      argumento=false;
    }
  }
  else if(argc==3){
    if(!strcmp(argv[1],"-i")){
      filename=argv[2];
      importJSON(collection, filename);
    }
    else if(!strcmp(argv[1],"-d")){
      argumento=false;
    }
    else{
      argumento=false;
    }
  }
  else if(argc>3){
    argumento=false;
  }
  return(argumento);
}

// menú principal
int main(int argc, char *argv[]){
  Collection collection=createCollection();
  Playlist playlist;
  char option, borrar;  
  string filename;
  bool a=true;
  a=manageArguments(argc, argv, collection, playlist);
  if(a==false){
    cout<<"Syntax: ./minitunes [-d] [-i jsonfilename]" << endl;
  }
  else{
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
	managePlaylist (playlist, collection);
	break;
      case '6':
	cout << "Filename: ";
	getline(cin, filename);
	importJSON(collection, filename);
	break;
      case '7':
	saveXSPFPlaylist(playlist, collection);
	break;
      case '8':
      	saveData(collection, playlist);
	break;
      case '9':
	if(collection.songs.size()>0){
	  cout << "Delete previous collection? (Y/N): ";
	  cin >> borrar;
	  if(borrar=='Y'){
	    loadData(collection, playlist);
	  }
	}
	else{
	  loadData(collection, playlist);
	}
	break;
      case '0':
	playPlaylist(playlist, collection);
	break;
      case 'q':
	break;
      default:
	cout << "Error: Unknown option" << endl;
	break;
    }
  }while(option!='q');
  }
  return 0;
}