// DNI1 45931406 REYES ALBILLAR, ALEJANDRO
// DNI2 74245842 PASCUAL GOMEZ, ALEJANDRO

#include "Collection.h"
using namespace std;

Collection::Collection() {
	  idNextSong=1;
}

Song Collection::getSongAt(int index) const {
	return songs[index];
}


int Collection::findIdSong(int id) const {
	int n;
	  n=-1;
	  for(int i=0; i<size(); i++){
	    if(id==getSongAt(i).getId()){
	      n=i;
	    }
	  }
	  return n;
}


bool Collection::isSongInCollection(Song song) const {
	  int i;
	  bool repetida;
	  int tam=size();
	  repetida=false;
	  for(i=0;i<tam;i++){
	   if(song.isEqual(getSongAt(i))==true){
	     repetida=true;
	   }
	  }
	  return(repetida);
}


bool Collection::show() const {
	  bool showCollection=false;
	  string buscar;
	  cout << "Search: ";
	  getline(cin,buscar);
	  for(int i=0;i<size();i++){
	   if (getSongAt(i).getTitle().find(buscar)!=string::npos ||
			   getSongAt(i).getArtist().find(buscar)!=string::npos ||
			   getSongAt(i).getAlbum().find(buscar)!=string::npos ||
			   getSongAt(i).getGenre().find(buscar)!=string::npos){
		   Song s=getSongAt(i);
		   cout << s << endl;
	     showCollection=true;
	    }
	  }
	  if(showCollection==false){
	    cout << "No results" << endl;
	  }
	  return showCollection;
}


bool Collection::addSong() {
	bool addSong1;
	Song song;
	cin >> song;//error no devuelve la song;
	if(isSongInCollection(song)==true){
	  addSong1=false;
	  cout<<"The song "<<song.getTitle()<<" is already in the collection"<<endl;
	}
	else{
	  addSong1=true;
	  song.setId(idNextSong);
	  songs.push_back(song);
	  idNextSong++;
	}
	return(addSong1);
}


void Collection::editSong() {
	int id, n, option;
	  if(show()==true){
	    cout << "Select song: ";
	    cin >> id;
	    cin.get();
	    n=findIdSong(id);
	    if(n==-1){
	      cout << "Error: Unknown song " << id << endl;
	    }
	    else {
	      do{
		cout << "Edit (1-Title, 2-Artist, 3-Album, 4-Genre, 5-Url): ";
		cin>> option;
		cin.get();
	    string title;
	    string artist;
	    string album;
	    string genre;
	    string url;

		switch(option){
		  case 1:
		    cout << "Title: ";
		    getline(cin,title);
		    songs[n].setTitle(title);
		    break;
		  case 2:
		    cout << "Artist: ";
		    getline(cin, artist);
		    songs[n].setArtist(artist);
		    break;
		  case 3:
		    cout << "Album: ";
		    getline(cin,album);
		    songs[n].setAlbum(album);
		    break;
		  case 4:
		    cout << "Genre: ";
		    getline(cin, genre);
		    songs[n].setGenre(genre);
		    break;
		  case 5:
		    cout << "Url: ";
		    getline(cin,url);
		    songs[n].setUrl(url);
		    break;
		  default:
		    cout << kERROR <<endl;
		    break;
		}
	      }while(option<1 || option>5);
	    }
	  }
}


void Collection::deleteSong() {
	int id, n;
	  char option;
	  if(show()==true){
	    cout << "Select song: ";
	    cin >> id;
	    cin.get();
	    n=findIdSong(id);
	    if(n==-1){
	      cout << "Error: Unknown song " << id << endl;
	    }
	    else{
	      cout << "Delete ";
	      Song s=getSongAt(n);
	      cout << s << endl;
	      cout << "? (Y/N): ";
	      cin >> option;
	      cin.get();
	      if(option=='Y'){
		songs.erase(songs.begin()+n);
	      }
	      else{
		cout << "Song not deleted" << endl;
	      }
	    }
	  }
}


bool Collection::importJSON(string filename) {
	ifstream fichero;
	  bool ficheroAbierto=false;
	  fichero.open(filename.c_str(),ios::in);
	  if(fichero.is_open()){
	    string linea;
	    ficheroAbierto=true;
	    getline(fichero, linea);
	    while(!fichero.eof()){
	      if(linea.find("kind\":\"song")!=string::npos){
		Song song(linea);
		if(isSongInCollection(song)==false){ //devuelve true si est� en la colecci�n
		  song.setId(idNextSong);
		  songs.push_back(song);
		  idNextSong++;
		}
		else{
		  cout << "The song " << song.getTitle() << " is already in the collection" << endl;
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


bool Collection::read(ifstream& f) {
	SongBin songbin;
	  int idNextSong;
	  bool abierto=false;
	  clear();
	  if(f.is_open()){
	    abierto=true;
	    f.read((char *) &idNextSong, sizeof(idNextSong));
	    this->idNextSong=idNextSong;
	    f.read((char *) &songbin, sizeof(songbin));
	    while(!f.eof()){
	      Song song(songbin);
	      if(isSongInCollection(song)==false ){
		songs.push_back(song);
	      }
	      f.read((char *) &songbin, sizeof(songbin));
	    }
	  }
	  return(abierto);
}


bool Collection::write(ofstream& f) const {
	SongBin songbin;
	  int idNextSong1;
	  bool abierto=false;
	  if(f.is_open()){
	    abierto=true;
	    idNextSong1=idNextSong;
	    f.write((const char *) &idNextSong1, sizeof(idNextSong1));
	    for(int i=0;i<size();i++){
	      songbin=getSongAt(i).toBinary();
	      f.write((const char *) &songbin, sizeof(songbin));
	    }
	  }
	  return(abierto);
}


int Collection::size() const {
	int tam;
	tam= songs.size();
	return tam;
}


void Collection::clear() {
	songs.clear();
	idNextSong=1;
}


