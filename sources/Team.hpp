#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <iostream>
#include <limits>

using namespace std;

namespace ariel{
  
    class Team {
    public:
        Team(Character* leader);
        Team(const Team&) = default;            // copy constructor
        Team& operator=(const Team&) = default; // copy assignment operator
        Team(Team&&) noexcept = default;        // move constructor
        Team& operator=(Team&&) noexcept = default; // move assignment operator
        virtual ~Team(); // virtual destructor
        
        void add(Character* character);
        virtual void attack(Team* enemy_team);
        int stillAlive();
        virtual void print();
        
        std::vector<Character*> members;
        std::vector<Cowboy*> cowboys;
        std::vector<Ninja*> ninjas;
        Character* leader;
    
    
    protected:
        Character* getVictim(Team* enemy_team);
        void setNewLeader();

    };

}
#endif // TEAM_HPP