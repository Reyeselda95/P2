SongBin songToBinary(const Song &song){
	SongBin songbin;
	strcpy(songbin.id, song.id.c_str());
	strcpy(songbin.title, song.title.c_str());
	strcpy(songbin.artist, artist.title.c_str());
	strcpy(songbin.album, song.album.c_str());
	strcpy(songbin.genre, song.genre.c_str());
	strcpy(songbin.url, song.url.c_str());
	return(songbin);
}

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

bool writePlaylist(const Playlist &playlist, ofstream &f){
	int num;
	bool abierto=false;
	if(f.is_open()){
		abierto=true;
		num=playlist.idSong.size();
		f.write((const char *) &num, sizeof(num));
		for(unsigned int i=0; i<num; i++){
			f.write((const char *) &playlist.idSong[i], sizeor(playlist.idSong[i]));	
		}	
	}
	return(abierto);
}

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


