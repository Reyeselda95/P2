/*
 * Collection.h
 *
 *  Created on: 13/05/2014
 *      Author: apg124
 */
#include "Constants.h"
#include "Song.h"
using namespace std;

#ifndef COLLECTION_H_
#define COLLECTION_H_


class Collection {
private:
	int idNextSong;
	vector<Song> songs;
public:
	Collection();
	Song getSongAt(int index) const;
	int findIdSong (int id) const;
	bool isSongInCollection(Song song) const;
	bool show() const;
	bool addSong();
	void editSong();
	void deleteSong();
	bool importJSON(string filename);
	bool read(ifstream& f);
	bool write(ofstream& f) const;
	int size() const;
	void clear();
};

#endif /* COLLECTION_H_ */
