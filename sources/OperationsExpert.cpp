#include "OperationsExpert.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
      OperationsExpert::OperationsExpert(Board& b , City c): Player(b,c){
            this->board = b;
            this->city = c;
            this->roleOfPlayer = "OperationsExpert";
      }

      Player& OperationsExpert::build(){
         if(!board.have_ResearchStations(this->city)){
         board.bulid_ResearchStations(this->city);
          }
          return *this;
      }

}

