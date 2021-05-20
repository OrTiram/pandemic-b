#include "Medic.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       Medic::Medic(Board& b , City c): Player(b,c){
            this->board = b;
            this->city = c;
            this->roleOfPlayer = "Medic";
       }

       Player& Medic::treat(City c){
         if(this->city != c){throw invalid_argument{"you are not in city "};}
         if(board[c] == 0) {throw invalid_argument{"no more cubes remain in city " };}
           
          board[c] = 0  ;         
          return *this;
       }

      Player& Medic::drive(City c){
      Player::drive(c);
      if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
      return *this;

       }

      Player& Medic::fly_direct(City c) {
          Player::fly_direct(c);
          if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
          return *this;

      }
      Player& Medic::fly_charter(City c){
          Player::fly_charter(c);
          if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
          return *this;
      }
      Player& Medic::fly_shuttle(City c){
          Player::fly_shuttle(c);
          if(board.cureDiscoverd(Board::getColor(c))){board[c]=0;}
          return *this;
      }
}
