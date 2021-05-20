#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>




namespace pandemic{
 class Medic: public Player{
    public:
       Medic(Board& b , City c);
       Player& treat(City c) override;
       Player& drive(City c) override;
       Player& fly_direct(City c) override;
       Player& fly_charter(City c) override;
       Player& fly_shuttle(City c) override;
 };
}
