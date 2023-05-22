#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <string>
#include <vector>
#include "Team.hpp"
using namespace std;

namespace ariel{
   class Team2 : public Team {
    public:
        using Team::Team; // inherit constructor
        void attack(Team* enemy_team) override;
        void print() override;
    };
}

#endif // TEAM2_HPP