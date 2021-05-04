#include "Player.hpp"

namespace pandemic{

    class Scientist : public Player{
        public:
        Scientist(Board& board, City city, int num) : Player(board, city, num){}
        Player& discover_cure(Color color){
            return *this;
        }
    };
}