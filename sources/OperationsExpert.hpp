#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>




namespace pandemic{
 class OperationsExpert:public Player{
    public:
       OperationsExpert(Board& b , City c);
       Player& build() override;
 };
}
