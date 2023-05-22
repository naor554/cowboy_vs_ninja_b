#include "SmartTeam.hpp"


using namespace std;

namespace ariel{

    
    void SmartTeam::attack(Team* enemy_team) {

        // Check if enemy_team is null.
        if (enemy_team == nullptr) {
            throw std::invalid_argument("enemy_team cannot be null");
        }

        // Check if one of the teams is dead.
        if(enemy_team->stillAlive() == 0 || this->stillAlive() == 0){
            throw std::runtime_error("Cannot attack a dead team.");
        }
        
        // Check if the leader is alive. If not, select a new one.
        if (!leader->isAlive()) {
            setNewLeader();
        }

       
        // Get the victim
        Character* victim = getVictim(enemy_team);



        // Sorting ninjas by distance to the victim
        std::sort(ninjas.begin(), ninjas.end(), [victim](Ninja* a, Ninja* b) {
            return a->distance(victim) < b->distance(victim);
        });

        
        vector<Ninja*> close_ninjas;
        vector<Ninja*> far_ninjas;

        // Splitting the ninjas to two groups: close and far
        for (Ninja* ninja : ninjas) {
            if (ninja->distance(victim) < 1.0) {
                close_ninjas.push_back(ninja);
            } else {
                far_ninjas.push_back(ninja);
            }
        }

        // Ninjas who are close enough attack first
        for (Ninja* ninja : close_ninjas) {
            if (ninja->isAlive()) {
                ninja->slash(victim);
            }
            if(!victim->isAlive()){ // Check if the victim is dead during the cowboys attack.
                victim = getVictim(enemy_team);
                if(victim == nullptr){
                    return;
                }
            }
        }

        // Cowboys attack second
        for (Cowboy* cowboy : cowboys) {
            if (cowboy->isAlive()) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(victim);
                } else {
                    cowboy->reload();
                }
            }
            if(!victim->isAlive()){ // Check if the victim is dead during the cowboys attack.
                victim = getVictim(enemy_team);
                if(victim == nullptr){
                    return;
                }
            }
        }


        // Ninjas who are not close enough move towards the victim
        for (Ninja* ninja : far_ninjas) {
            if (ninja->isAlive()) {
                ninja->move(victim);
            }
        }

    }

    // print the team
    void SmartTeam::print() {
        cout << "SmartTeam:" << endl;
        cout << "Leader: ";
        leader->print();
        cout << "Cowboys:" << endl;
        for (Cowboy* cowboy : cowboys) {
            cowboy->print();
        }
        cout << "Ninjas:" << endl;
        for (Ninja* ninja : ninjas) {
            ninja->print();
        }
    }
} // namespace ariel
