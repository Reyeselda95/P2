// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO

#include "Constants.h"
using namespace std;

#ifndef SONG_H_
#define SONG_H_

typedef struct{
  int id;
  char title[kTITLE];
  char artist[kARTIST];
  char album[kALBUM];
  char genre[kGENRE];
  char url[kURL];
}SongBin;

class Song {
	friend ostream& operator << (ostream &os, Song &song);
	friend istream& operator >> (istream &is, Song &song);
private:
	int id;
	string title;
	string artist;
	string album;
	string genre;
	string url;
public:
	Song();
	Song(int id, string title, string artist, string album, string genre, string url);
	Song(string JSONline);
	Song(const SongBin & songbin);
	int getId() const;
	string getTitle() const;
	string getArtist() const;
	string getAlbum() const;
	string getGenre() const;
	string getUrl() const;
	void setId(int id);
	void setTitle(string title);
	void setArtist(string artist);
	void setAlbum(string album);
	void setGenre(string genre);
	void setUrl(string url);
	bool isEqual(const Song & song) const;
	void printPlaylist() const;
	void printXSPF(ofstream& f) const;
	SongBin toBinary() const;

};

#endif /* SONG_H_ */
