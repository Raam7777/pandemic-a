

#include "Player.hpp"
#include <string>

using namespace std;

namespace pandemic{

    Player::Player(Board& board, City city) : gameToBoard(board), cityLocation(city){}
    Player::Player(Board& board, City city, int number) : gameToBoard(board), cityLocation(city){}

    Player& Player::take_card(City city){
        return *this;
    }

    Player& Player::build(){
        return *this;
    }

    Player& Player::drive(City city){
        return *this;
    }

    Player& Player::fly_direct(City city){
        return *this;
    }

    Player& Player::treat(City city){return *this;}
    
    Player& Player::fly_charter(City city){return *this;}
    
    Player& Player::fly_shuttle(City city){return *this;}

    Player& Player::discover_cure(Color color){return *this;}

    string Player::role(){
        return "city";
    }

    Player::~Player(){}
}

