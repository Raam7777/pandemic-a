#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic{

   OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city){}

    Player& OperationsExpert::build(){
        return *this;
    }


}
