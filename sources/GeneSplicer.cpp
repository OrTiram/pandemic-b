#include "GeneSplicer.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>
const int NUM_C = 5;
using namespace std;

namespace pandemic{  
      

       GeneSplicer::GeneSplicer(Board& b , City c): Player(b,c){
            this->board = b;
            this->city = c;
            this->roleOfPlayer = "GeneSplicer";
      }


      Player& GeneSplicer::discover_cure(Color c) {
         set<City> Tempcards;
         if(board.have_ResearchStations(this->city))
         {
           if(!board.cureDiscoverd(c))
           {
            for(const auto& i :this->cards)
            {
              Tempcards.insert(i); 
              if(Tempcards.size() == NUM_C) {break;}
            }

              if(Tempcards.size() == NUM_C) 
              {
                  board.insertCures(c);
              }
              else{throw invalid_argument{"You do not have enough cards in the right color "};}

              for(const auto& i : Tempcards)
              {
                this->cards.erase(i);
              }
        }
      }
        
         else{throw invalid_argument{"in this city don't have a research station"};}

          return *this;
      }

}