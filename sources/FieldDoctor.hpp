#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>




namespace pandemic{
 class FieldDoctor: public Player{
    public:
       FieldDoctor(Board& b , City c);
       Player& treat(City c) override;
 };
}
