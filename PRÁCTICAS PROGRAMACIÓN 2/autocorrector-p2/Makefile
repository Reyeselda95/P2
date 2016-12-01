OPTS=-Wall -g
OBJS=player/Player.o minitunes.o
CC=g++

minitunes: $(OBJS)
	$(CC) $(OPTS) $(OBJS) -o minitunes
	rm minitunes.o
	rm player/Player.o

minitunes.o: minitunes.cc player/Player.h
	$(CC) $(OPTS) -c minitunes.cc -Iplayer/

player/Player.o: player/Player.cc player/Player.h
	$(CC) $(OPTS) -c player/Player.cc -Iplayer/ -o player/Player.o

clean:
	rm -rf $(OBJS)
	rm minitunes
