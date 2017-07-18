// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO

#include "Song.h"
using namespace std;

Song::Song() {
	id=0;
}

Song::Song(int id, string title, string artist, string album, string genre,
		string url) {
	this->id=id;
	this->title=title;
	this->artist=artist;
	this->album=album;
	this->genre=genre;
	this->url=url;
}

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

Song::Song(string JSONline) {
	title=getField(JSONline, "trackName\":\"");
	album=getField(JSONline, "collectionName\":\"");
	artist=getField(JSONline, "artistName\":\"");
	genre=getField(JSONline, "primaryGenreName\":\"");
	url=getField(JSONline, "previewUrl\":\"");
}

int Song::getId() const {
	return id;
}

string Song::getTitle() const {
	return title;
}

string Song::getArtist() const {
	return artist;
}

string Song::getAlbum() const {
	return album;
}

string Song::getGenre() const {
	return genre;
}

string Song::getUrl() const {
	return url;
}

void Song::setId(int id) {
	this->id = id;
}

void Song::setTitle(string title) {
	this->title=title;
}

void Song::setArtist(string artist) {
	this->artist=artist;
}

void Song::setAlbum(string album) {
	this->album=album;
}

void Song::setGenre(string genre) {
	this->genre=genre;
}

void Song::setUrl(string url) {
	this->url=url;
}

ostream& operator <<(ostream& os, Song &song) {
	os << song.id << " | "
	   << song.title << " | "
	   << song.artist << " | "
	   << song.album << " | "
	   << song.genre;
	return(os);
}

istream& operator >>(istream& is, Song &song) {
	  cout<<"Title: ";
	  getline(is,song.title);
	  cout<<"Artist: ";
	  getline(is,song.artist);
	  cout<<"Album: ";
	  getline(is,song.album);
	  cout<<"Genre: ";
	  getline(is,song.genre);
	  cout<<"Url: ";
	  getline(is,song.url);
	  return(is);
}

Song::Song(const SongBin& songbin) {
	  id=songbin.id;
	  artist=songbin.artist;
	  title=songbin.title;
	  genre=songbin.genre;
	  album=songbin.album;
	  url=songbin.url;
}

bool Song::isEqual(const Song& song) const {
  bool repetida;
  repetida=false;
   if(title == song.title && artist == song.artist){
     repetida=true;
   }
  return(repetida);
}

void Song::printPlaylist() const {
	cout << id << ": " << title << " (" << artist << ")" << endl;
}

void Song::printXSPF(ofstream& f) const {
	  f << "  <track>" << endl
	  << "   <title>" << title << "</title>" << endl
	  << "   <creator>" << artist << "</creator>" << endl
	  << "   <album>" << album << "</album>" << endl
	  << "   <location>" << url << "</location>" << endl
	  << "   <meta rel=\"genre\">" << genre << "</meta>" << endl
	  << "  </track>" << endl;
}

SongBin Song::toBinary() const {
	SongBin songbin;
	  songbin.id=id;
	  strncpy(songbin.title, title.c_str(), kTITLE-1);
	  songbin.title[kTITLE-1]='\0';
	  strncpy(songbin.artist, artist.c_str(),kARTIST-1);
	  songbin.artist[kARTIST-1]='\0';
	  strncpy(songbin.album, album.c_str(),kALBUM-1);
	  songbin.album[kALBUM-1]='\0';
	  strncpy(songbin.genre, genre.c_str(),kGENRE-1);
	  songbin.genre[kGENRE-1]='\0';
	  strncpy(songbin.url, url.c_str(),kURL-1);
	  songbin.url[kURL-1]='\0';
	  return(songbin);
}

