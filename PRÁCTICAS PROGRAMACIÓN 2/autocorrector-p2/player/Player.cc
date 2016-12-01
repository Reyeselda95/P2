#include "Player.h"

// Funcion para reproducir una cancion. Necesita una URL como parámetro.
void playSong(string url, Player &player)
{
  if (url!="")
  {
  	player.playing = true;
    cout << "Reproduciendo " << url << endl;
  }
  else cout << "No URL for this song" << endl;
}

// Funcion para pausar o quitar la pausa a una cancion
void pauseResumeSong(Player &player)
{
  player.playing = !player.playing;
  if (player.playing)
    cout << "Se ha reanudado la reproduccion" << endl;
  else
    cout << "Se ha pausado la reproduccion" << endl;
}

// Importante: Llamar a esta funcion una vez se ha terminado de usar el reproductor
void endPlayer(Player &player)
{
  player.playing = false;
  cout << "Se ha detenido el reproductor" << endl;
}
