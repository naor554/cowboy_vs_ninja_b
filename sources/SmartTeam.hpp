#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "Team.hpp"
using namespace std;

namespace ariel{
   class SmartTeam : public Team {
        using Team::Team; // inherit constructor
        void attack(Team* enemy_team) override;
        void print() override;
    };
}

#endif // SMARTTEAM_HPP