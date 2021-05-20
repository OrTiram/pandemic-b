#include "Virologist.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       Virologist::Virologist(Board& b , City c): Player(b,c){
            this->board = b;
            this->city = c;
            this->roleOfPlayer = "Virologist";
       }

       Player& Virologist::treat(City c){
         if(this->cards.count(c)==0 && this->city!= c){throw invalid_argument{"you do not have the card of this city " };}
         if(board[c] == 0) {throw invalid_argument{"no more cubes remain in city " };}
         if(board.cureDiscoverd(Board::getColor(c)))
           {
              board[c] = 0;
           }
         else {board[c]--;}

         return *this;
       }

}