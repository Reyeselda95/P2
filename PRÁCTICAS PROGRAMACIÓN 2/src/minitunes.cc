// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO
 
#include "Player.h"
#include "Constants.h"
#include "Song.h"
#include "Collection.h"
#include "Utils.h"
#include "Playlist.h"
 
using namespace std;

// men� principal
int main(int argc, char *argv[]){
  Collection collection;
  Playlist playlist(&collection);
  char option, borrar;  
  string filename;
  bool a=true;
  a=Utils::manageArguments(argc, argv, collection, playlist);
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
	collection.addSong();
	break;
      case '2':
	collection.editSong();
	break;
      case '3': 
	collection.deleteSong();
	break;
      case '4': 
	collection.show();
	break;
      case '5':
	playlist.manage();
	break;
      case '6':
	cout << "Filename: ";
	getline(cin, filename);
	collection.importJSON(filename);
	break;
      case '7':
	playlist.saveXSPF();
	break;
      case '8':
      	Utils::saveData(collection, playlist);
	break;
      case '9':
	if(collection.size()>0){
	  cout << "Delete previous collection? (Y/N): ";
	  cin >> borrar;
	  if(borrar=='Y'){
	    Utils::loadData(collection, playlist);
	  }
	}
	else{
	  Utils::loadData(collection, playlist);
	}
	break;
      case '0':
	playlist.play();
	break;
      case 'q':
	break;
      default:
	cout << kERROR << endl;
	break;
    }
  }while(option!='q');
  }
  return 0;
}
