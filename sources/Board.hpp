#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>



namespace pandemic{
 class Board{
    
      static std::map<City,std::set<City>> connectionCities;
      //static std::map<City, Color> colorsOfCities;
      std::map<City,int> levelOfDisease;
      std::set<City> researchStations;
      std::set<Color> medicane;
     
     public: 
      Board();
      int& operator[](City city);
      friend std::ostream& operator<<(std::ostream& output,const Board& board);
      bool is_clean();
      void remove_cures(){medicane.clear();};
      void remove_stations(){researchStations.clear();};

    //Help
      static bool isConnected(City& c1, City& c2);
      bool have_ResearchStations(City c);
      void bulid_ResearchStations(City c);
      static bool sameColor(City c1, Color c2);
      static Color getColor(City c);
      void insertCures(Color c);
      bool cureDiscoverd(Color c);


 };
}