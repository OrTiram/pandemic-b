#include "FieldDoctor.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       FieldDoctor::FieldDoctor(Board& b , City c): Player(b,c){
            this->board = b;
            this->city = c;
            this->roleOfPlayer = "FieldDoctor";
       }
       Player& FieldDoctor::treat(City c){
         if(!Board::isConnected(this->city,c) && this->city != c){throw invalid_argument{"The cities are not connected"};}
         if(board[c] == 0) {throw invalid_argument{"no more cubes remain in this city " };}
         if(board.cureDiscoverd(Board::getColor(c))){
           board[c] = 0;
           }
         else{
           board[c]--;
         }
         return *this;
       }
      

      }

                      
  