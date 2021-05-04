#ifndef BOARD
#define BOARD

#include <map>
#include <set>
#include <ostream>
#include <stdexcept>

#include "City.hpp"
#include "Color.hpp"


namespace pandemic{


    class Board{
        
        public:
        /*
        std::map<City, int> numberIsCity;
        std::map<City, Color> colorTheCity;
        std::map<City, std::set<City>> mapToCity;
        std::map<City, bool> searchTheCity;
        std::map<Color, bool> discoverCure;
        */
        Board();
        ~Board();

        int zmani;
        int operator[](City city) const;
        int &operator[](City city);

        static bool is_clean();
        void remove_cures();

        friend std::ostream& operator<<(std::ostream& os, const Board& board);

    };
}

#endif