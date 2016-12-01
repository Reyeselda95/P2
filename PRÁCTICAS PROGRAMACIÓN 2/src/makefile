COMPIL=g++ -Wall -g
OBJETOS=Player.o Collection.o Song.o Playlist.o Utils.o

minitunes: $(OBJETOS) minitunes.o
	$(COMPIL) $(OBJETOS) minitunes.o -o minitunes

minitunes.o: minitunes.cc Player.h Song.h Constants.h
	$(COMPIL) -c minitunes.cc

Collection.o:Collection.cc Collection.h Song.h Constants.h
	$(COMPIL) -c Collection.cc

Song.o: Song.cc Song.h Constants.h
	$(COMPIL) -c Song.cc

Playlist.o:Playlist.cc Playlist.h Constants.h Collection.h Song.h Player.h
	$(COMPIL) -c Playlist.cc

Utils.o:Utils.cc Playlist.cc Constants.h Collection.h
	$(COMPIL) -c Utils.cc

Player.o: Player.cc Player.h
	$(COMPIL) -c Player.cc

