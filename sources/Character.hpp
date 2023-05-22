#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel{
    class Character {

    public:
        Character(const std::string& name, const Point& location, int hit_points);
        Character(const Character&) = default; // Copy constructor
        Character& operator=(const Character&) = default; // Copy assignment operator
        Character(Character&&) = default; // Move constructor
        Character& operator=(Character&&) = default; // Move assignment operator
        virtual ~Character() = default; // Virtual destructor

        
        bool isAlive(); 
        double distance(Character* other);
        void hit(float damage);
        std::string getName();
        Point getLocation();
        void setLocation(Point location);
        int getHitPoints();
        bool getHasTeam();
        void setHasTeam(bool hasTeam);
        virtual string print();
        
    private:
        std::string name;
        Point location;
        int hit_points;
        bool hasTeam = false;
    };
}

#endif // CHARACTER_HPP