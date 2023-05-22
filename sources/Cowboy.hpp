#ifndef COWBOY_HPP
#define COWBOY_HPP


#include <string>
#include <vector>
#include "Character.hpp"
using namespace std;

namespace ariel{
   class Cowboy : public Character {
    public:
        Cowboy(const std::string& name, const Point& location);
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();
        string print() override;
    private:
        int boolets;
    };
}

#endif // COWBOY_HPP