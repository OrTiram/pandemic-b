#include "Researcher.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>
const int NUM_C = 5;
using namespace std;

namespace pandemic{  
      
       Researcher::Researcher(Board& b , City c): Player(b,c){
            this->board = b;
            this->city = c;
            this->roleOfPlayer = "Researcher";
      
      } 

      Player& Researcher::discover_cure(Color c) {
              set<City> Tempcards;
              if(!board.cureDiscoverd(c))
              {
              for(const auto& i : this->cards)
              {
                     if(Board::sameColor(i,c))
                     {
                     Tempcards.insert(i);  
                     } 
                     if(Tempcards.size() == NUM_C) {break;}
              }

              if(Tempcards.size() == NUM_C)
              {
                     board.insertCures(c);

              }
              else{throw invalid_argument{"you don't have enough cards "};}

              for(const auto& i : Tempcards)
              {
                     this->cards.erase(i);
              }
              }

              return *this;
       }
       
}