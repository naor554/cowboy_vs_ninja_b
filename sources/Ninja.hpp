#ifndef NINJA_HPP
#define NINJA_HPP

#include <string>
#include <vector>
#include "Character.hpp"
using namespace std;

namespace ariel{
   class Ninja : public Character {
    public:
        Ninja(const std::string& name, const Point& location, int hit_points, int speed);
        void move(Character* enemy);
        void slash(Character* enemy);
        string print() override;
        int getSpeed() const { return speed; }
    private:
        int speed;
    };
}

#endif // NINJA_HPP