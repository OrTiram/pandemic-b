#include "Dispatcher.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
       Dispatcher::Dispatcher(Board& b , City c): Player(b,c){
              this->board = b;
              this->city = c;
              this->roleOfPlayer = "Dispatcher";
       }

       Player& Dispatcher::fly_direct(City c) {
              if(this->city == c){throw std::invalid_argument{"you can't fly to the city you are already in"};}
              if(board.have_ResearchStations(this->city))
              {
                this->city = c;
                return *this;
              }
              
              return Player::fly_direct(c);
              
              }

       }      
