#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>
#include <string>
#include <set>
const int NUM_C = 5;
using namespace std;


namespace pandemic{

       Player& Player::drive(City c){
         if(this->city == c){throw invalid_argument{"you can't fly to the city you are already in"};}
         if(Board::isConnected(this->city,c)){
           this->city = c;
           return *this;
         }
         throw std::invalid_argument{"The cities are not connected"};
         
       }

       Player& Player::fly_direct(City c){
              if(this->city == c){throw invalid_argument{"you can't fly to the city you are already in"};}
              if (cards.count(c) != 0)
              {
                this->city = c;
                cards.erase(c); 
                return *this; 
              }
             
             throw invalid_argument{"you don't have city card"};

           }

       

       Player& Player::fly_charter(City c){
              if(this->city == c){throw invalid_argument{"you can't fly to the city you are already in"};}
              if (cards.count(this->city) != 0)
              {
                cards.erase(this->city);  
                this->city = c;
                return *this;
   
              }
              
              throw invalid_argument{"you don't have city card"};
              
              }


       Player& Player::fly_shuttle(City c){
            if(city == c){throw invalid_argument{"you can'y fly to the city you are already in"};}
              if(board.have_ResearchStations(this->city) && board.have_ResearchStations(c)){
                 this->city = c;
                 return *this;
              }
              
                throw invalid_argument{"in the cities must have Research Stations"};
  
              }
       

       Player& Player::treat(City c){
           if(this->city != c){throw invalid_argument{"you don't have city card"};}
           if(board[c] == 0) {throw invalid_argument{"no more cubes remain in this city " };}
           if(board.cureDiscoverd(Board::getColor(c)))
           {
              board[c] = 0;
           }
           else {board[c]--;}

         return *this;
         }
       

       Player& Player::take_card(City c){
         cards.insert(c);
         return *this;
         }
       
       Player& Player::build(){
         if(cards.count(this->city) != 0){
         if(!board.have_ResearchStations(this->city)){
         board.bulid_ResearchStations(this->city);
         cards.erase(this->city);
          }
         }
         else{throw invalid_argument{"you don't have city card" };}
         return *this;
       }
       

       Player& Player::discover_cure(Color c){
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
                    if(Tempcards.size() == NUM_C) {break;}
              }

                if(Tempcards.size() == NUM_C) 
                {
                  board.insertCures(c);

                }

                else{throw invalid_argument{"you don't have enough cards"};}

                for(const auto& i : Tempcards)
                {
                  this->cards.erase(i);
                }
            }
          }

         else{throw invalid_argument{"in this city don't have a research station"};}

        return *this;
       }

       string Player::role(){
          return this->roleOfPlayer;
         }
}