#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>




namespace pandemic{
 class Researcher: public Player{
    public:
       Researcher(Board& b , City c);
       Player& discover_cure(Color c) override;
 };
}
