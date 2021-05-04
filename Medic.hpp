#include "Player.hpp"

namespace pandemic{

    class Medic : public Player{
        public:
        Medic(Board& board, City city): Player(board, city){}
        Player& treat(City city){
            return *this;
        }
    };
}