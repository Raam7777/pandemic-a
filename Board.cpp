#include "Board.hpp"
#include <stdexcept>

using namespace std;

namespace pandemic{
        
        Board::Board(){}

        int Board::operator[](City city) const{
            return 1;
        }
        
        int& Board::operator[](City city){
            return zmani;
        }

        bool Board::is_clean(){
            return true;
        }

        void Board::remove_cures(){

        }

        ostream& operator<<(ostream& os, const Board& board){
            return os;
        }

        Board::~Board(){}
}