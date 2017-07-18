// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO

#include "Utils.h"
#include "Constants.h"
using namespace std;

bool Utils::saveData(const Collection& collection, const Playlist& playlist) {
	ofstream fichero;
	  bool abierto=false;
	  if(collection.size()<=0){
	    cout << "Empty collection" << endl;
	  }
	  else{
	    fichero.open("minitunes.dat",ios::out|ios::binary);
	    if(fichero.is_open()){
	      abierto=true;
	      playlist.write(fichero);
	      collection.write(fichero);
	      fichero.close();
	    }
	    else{
	      cout<<"Error opening file minitunes.dat"<<endl;
	    }
	  }
	  return(abierto);
}


bool Utils::loadData(Collection& collection, Playlist& playlist) {
	 ifstream fichero;
	  bool abierto=false;
	  fichero.open("minitunes.dat", ios::in | ios::binary);
	  if(fichero.is_open()){
	    abierto=true;
	    playlist.read(fichero);
	    collection.read(fichero);
	    fichero.close();
	  }
	  else{
	    cout << "Error opening file minitunes.dat" << endl;
	  }
	  return(abierto);
}



bool Utils::manageArguments(int argc, char* argv[], Collection& collection,
		Playlist& playlist) {
	bool argumento=true;
	  string filename;
	  if(argc==2){
	    if(!strcmp(argv[1],"-d")){
	      loadData(collection, playlist);
	    }
	    else{
	      argumento=false;
	    }
	  }
	  else if(argc==3){
	    if(!strcmp(argv[1],"-i")){
	      filename=argv[2];
	      collection.importJSON(filename);
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




