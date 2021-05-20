#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>


namespace pandemic{
 class Scientist:public Player{
    int num;
    public:
       Scientist(Board& b , City c,int n);
       Player& discover_cure(Color c) override;
 };
}
