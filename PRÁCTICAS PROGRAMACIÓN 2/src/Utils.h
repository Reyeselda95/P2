// DNI1 45931406 REYES ALBILLAR, ALEJANDRO
// DNI2 74245842 PASCUAL GOMEZ, ALEJANDRO

#include "Collection.h"
#include "Playlist.h"
#ifndef UTILS_H_
#define UTILS_H_

class Utils {
public:
	static bool saveData(const Collection & collection, const Playlist & playlist);
	static bool loadData(Collection & collection, Playlist & playlist);
	static bool manageArguments(int argc, char *argv[], Collection & collection, Playlist & playlist);
};

#endif /* UTILS_H_ */
