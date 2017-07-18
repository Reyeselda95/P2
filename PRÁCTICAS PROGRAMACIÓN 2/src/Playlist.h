// REYES ALBILLAR, ALEJANDRO
// PASCUAL GOMEZ, ALEJANDRO

#include "Collection.h"
#include "Player.h"
using namespace std;

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

class Playlist {
private:
	vector <int> idSong;
	Collection *pcollection;
public:
	Playlist(Collection *collection);
	int size() const;
	void print(int position) const;
	void manage();
	void addSongs();
	void removeSongs();
	void clearSongs();
	bool saveXSPF() const;
	void play() const;
	bool read(ifstream & f);
	bool write(ofstream & f) const;
};

#endif /* PLAYLIST_H_ */
