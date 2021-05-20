#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>




namespace pandemic{
 class Dispatcher: public Player{
    public:
       Dispatcher(Board& b , City c);
       Player& fly_direct(City c) override;
 };
}
