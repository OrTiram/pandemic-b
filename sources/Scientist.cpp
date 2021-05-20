#include "Scientist.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
      Scientist::Scientist(Board& b , City c, int n): Player(b,c){
            this->board = b;
            this->city = c;
            this->num = n;
            this->roleOfPlayer = "Scientist";
      
      } 

      Player& Scientist::discover_cure(Color c) {
         set<City> Tempcards;
         if(board.have_ResearchStations(this->city))
         {
           if(!board.cureDiscoverd(c))
           {
            for(const auto& i :this->cards)
            {
                  if(Board::sameColor(i,c))
                  {
                    Tempcards.insert(i);  
                  } 
                  if(Tempcards.size() == this->num) {break;}
            }

              if(Tempcards.size() == this->num) 
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
