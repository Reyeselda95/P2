// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO

#include "Playlist.h"
using namespace std;

Playlist::Playlist(Collection *collection) {
	pcollection=collection;
}

int Playlist::size() const {
	return idSong.size();
}

void Playlist::print(int position) const {
	  for(unsigned int i=0; i<idSong.size();i++){
	    int k;
	    k=i;
	    for (int j=0;j<pcollection->size(); j++){
	      if (idSong[i]==pcollection->getSongAt(j).getId()){
		if (k==position) {
		  cout << ">";// la cancion que se esta reproduciendo actualmente (que esta en la posicion position del vector)
			      // se mostrara con un simbolo >. Si el valor de position es -1, no se mostrara el simbolo > delante de ninguna cancion.
		}	      // Se llamará a este módulo por cada cancion
		else{
		  cout << " ";
		}
		pcollection->getSongAt(j).printPlaylist();
	      }
	    }
	  }
}

void Playlist::manage() {
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
		addSongs();
		break;
	      case'2':
		removeSongs();
		break;
	      case'3':
		clearSongs();
		break;
	      case 'q':
		break;
	      default:
		cout << kERROR << endl;
		break;
	    }
	  }while(option!='q');
}

void Playlist::addSongs() {
	string id, select;
	  int n;
	  bool anyadido;
	  if(pcollection->size()<=0){
	    cout << "Empty collection" << endl;
	  }
	  else{
	    pcollection->show();
	    cout << "Select songs (list separated by spaces): ";
	    getline(cin, select); //Usar atoi para transformar char a int
	    for(unsigned int i=0; i<=select.length(); i++){
	      anyadido=false;
	      if (i==select.length() || select[i]== ' '){
		n=atoi(id.c_str());
		for(int j=0;j< pcollection->size(); j++){
		  if(n==pcollection->getSongAt(j).getId()){
		    anyadido=true;
		    idSong.push_back(n);
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

void Playlist::removeSongs() {
	string id, select;
	  bool isInPlaylist=false;
	  int pos=-1;
	  int n;
	  if(size()<=0){
	    cout << "Empty playlist" << endl;
	  }
	  else{
	    print(pos);
	    cout << "Select songs (list separated by spaces): " ;
	    getline(cin, select); //Usar atoi para transformar char a int
	    if(select.size()!=0){
	      for(unsigned int i=0; i<=select.length(); i++){
		if (select[i]== ' ' || i==select.length()){
		  isInPlaylist=false;
		  n=atoi(id.c_str());
		  for(int j=0; j<size(); j++){
		    if(n==idSong[j]){
		      isInPlaylist=true;
		      idSong.erase(idSong.begin()+j);
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

void Playlist::clearSongs() {
	  char opcion;
	  if(idSong.size()<=0){
	    cout<< "Empty playlist" << endl;
	  }
	  else{
	    cout << "Clear playlist? (Y/N):";
	    cin >> opcion;
	    cin.get();
	    if(opcion=='Y'){
	      idSong.clear();
	    }
	  }
}

bool Playlist::saveXSPF() const {
	bool disponible=false;
	  string filename;
	  ofstream fichero;
	  //si playlist esta vacio no hace nada y devuelve false
	  if(size()<=0){
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
	      for(int i=0; i<size();i++){
		int n;
		n=pcollection->findIdSong(idSong[i]);
		pcollection->getSongAt(n).printXSPF(fichero);
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


void Playlist::play() const {
	if (size()<=0){
	    cout << "Empty playlist" << endl;
	  }
	  else{
	    Player player;
	    int pos=0;
	    char command;
	    int i;
	    print(pos);
	    i=pcollection->findIdSong(idSong[pos]);
	    player.playSong(pcollection->getSongAt(i).getUrl());
	    do{
	      cout << "Command: ";
	      cin >> command;
	      cin.get();
	      switch(command){
		case 'p':
		  player.pauseResumeSong();
		  break;
		case 's':
		  if(pos==size()-1){
		    pos=0;
		  }
		  else{
		    pos++;
		  }
		  print(pos);
		  i=pcollection->findIdSong(idSong[pos]);
		  player.playSong(pcollection->getSongAt(i).getUrl());
		  break;
		case 'a':
		  if(pos==0){
		    pos=size()-1;
		  }
		  else{
		    pos--;
		  }
		  print(pos);
		  i=pcollection->findIdSong(idSong[pos]);
		  player.playSong(pcollection->getSongAt(i).getUrl());
		  break;
		case 'q':
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

bool Playlist::read(ifstream& f) {
	  int tam, id;
	  bool abierto=false;
	  idSong.clear();
	  if(f.is_open()){
	    f.read((char *) &tam, sizeof(tam));
	    for(int i=0; i<tam; i++){
	      f.read((char *) &id, sizeof (id));
	      idSong.push_back(id);
	    }
	    abierto=true;
	  }
	  return(abierto);
}

bool Playlist::write(ofstream& f) const {
	  int num;
	  bool abierto=false;
	  if(f.is_open()){
	    abierto=true;
	    num=size();
	    f.write((const char *) &num, sizeof(num));
	    for(int i=0; i<num; i++){
	      f.write((const char *) &idSong[i], sizeof(idSong[i]));
	    }
	  }
	  return(abierto);
}
