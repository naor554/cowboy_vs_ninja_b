#include "Team2.hpp"
#include <iostream>
#include <limits>

using namespace std;

namespace ariel {
    void Team2::attack(Team* enemy_team) {

        // Check if enemy_team is null.
        if (enemy_team == nullptr) {
            throw std::invalid_argument("enemy_team cannot be null");
        }

        // Check if one of the teams is dead.
        if(enemy_team->stillAlive() == 0 || this->stillAlive() == 0){
            return;
        }

        // Check if the leader is alive. If not, select a new one.
        if (!leader->isAlive()) {
            setNewLeader();
        }

        // Get the victim
        Character* victim = getVictim(enemy_team);


        // All members of the attacking team attack the victim.
        for (Character* member : members) {
            if (member->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
                Ninja* ninja = dynamic_cast<Ninja*>(member);
                if (cowboy) {
                    if (cowboy->hasboolets()) {
                        cowboy->shoot(victim);
                    } else {
                        cowboy->reload();
                    }
                } else if (ninja) {
                    if (ninja->distance(victim) <= 1.0) {
                        ninja->slash(victim);
                    } else {
                        ninja->move(victim);
                    }
                }
                if(!victim->isAlive()){ // Check if the victim is dead during the cowboys attack.
                    victim = getVictim(enemy_team);
                    if(victim == nullptr){
                        return;
                    }
                }
            }
        }
    }

    void Team2::print() {
        cout << "Team2:" << endl;
        for (Character* member : members) {
            member->print();
        }
    }

    
}// namespace ariel
