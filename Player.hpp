#ifndef PLAYER
#define PLAYER

#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

#include <string>

namespace pandemic{

    class Player{


        Board gameToBoard;
        City cityLocation;

        public:

        

        Player(Board& board, City city);
        Player(Board& board, City city, int number);
        ~Player();

        virtual Player& take_card(City city);
        virtual Player& build();
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& treat(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);

        virtual Player& discover_cure(Color color);

        std::string role();
        

    };

}

#endif