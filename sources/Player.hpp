#pragma once
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <iostream>
#include <string>
#include <set>



namespace pandemic{
 class Player{

    protected:
      Board& board;
      std::set<City> cards;
      City city;
      std::string roleOfPlayer;

    public:
      Player(Board& b , City c): board(b), city(c){}
      Player& take_card(City c);
      void remove_cards(){cards.clear();}
      virtual Player& drive(City c);
      virtual Player& fly_direct(City c);
      virtual Player& fly_charter(City c);
      virtual Player& fly_shuttle(City c);
      virtual Player& treat(City c);
      virtual std::string role();
      virtual Player& discover_cure(Color c);
      virtual Player& build();
 };
}