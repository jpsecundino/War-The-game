// Taken from LuisEduardoR/CPP-GrandStrategy, one of the contributors of the project.

#ifndef MAPDATA_HPP
#define MAPDATA_HPP

#include <set>
#include <map>
#include <utility>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>

// Paths to the map data files, relative to where the executable is.
#define PROVINCES_BMP_PATH "map/provinces.bmp"
#define PROVINCES_TXT_PATH "map/provinces.txt"
#define ADJACENCIES_TXT_PATH "map/adjacencies.txt"

namespace mdata {

unsigned generateIdFromColor(sf::Color color);
sf::Color generateColorFromId(unsigned id);

// Contain variables and methods related to provinces, both in game and during their generation.
class Province {

    public:

        unsigned id;

        sf::Vector2u center;

        unsigned min_x, max_x, min_y, max_y;

        Province(void) {

            min_x = min_y = 0x3f3f3f3f;
            max_x = max_y = 0;

        }

        void generateCenter() {

            center.x = (min_x + max_x) / 2;
            center.y = (min_y + max_y) / 2;

        }

        void generateCenter(unsigned x, unsigned y) {

            center.x = x;
            center.y = y;

        }

};

// Contain all the map data that will be used for the game. EMPTY FOR NOW.
class MapData {

    public:

        std::map <unsigned, Province> provinces;
        std::set <std::pair<unsigned, unsigned>> adjacencies;

        MapData(void);
        bool isAvaliable() { return mDataAvaliable; }
   
    private:

        bool loadMapData();
        bool mDataAvaliable;


};

class MapGenerator {

    private:

        sf::Image provinceMap;

        std::map <unsigned, Province> provincesInGeneration;
        std::set <std::pair<unsigned, unsigned>> provinceAdjacencies;

        bool loadNecessaryFiles();

    public:

        bool generateMapData();
        std::map <unsigned, mdata::Province>::iterator createProvince(unsigned x, unsigned y);
        void updateEdgeCoordinates(unsigned x, unsigned y, std::map<unsigned,Province>::iterator it);

};

}

#endif
