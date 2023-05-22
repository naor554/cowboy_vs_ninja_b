#include "Team.hpp"


using namespace std;

namespace ariel{

    // Constructor
    Team::Team(Character* leader)  {
       if(leader->getHasTeam()) {
            throw std::runtime_error("Character is already in a different team!");
        }
        members.push_back(leader);
        if(dynamic_cast<Cowboy*>(leader)) {
            cowboys.push_back(dynamic_cast<Cowboy*>(leader));
        } else if(dynamic_cast<Ninja*>(leader)) {
            ninjas.push_back(dynamic_cast<Ninja*>(leader));
        }
        leader->setHasTeam(true);
        this->leader = leader; 
    }

    // Methods

    // Adds a character to the team
    void Team::add(Character* character) {
        if(character->getHasTeam()) {
            throw std::runtime_error("Character is already in a different team!");
        }
        if(this->members.size() == 10) {
            throw std::runtime_error("Max amount of members in a team is 10");
        }
        character->setHasTeam(true);
        members.push_back(character);
        if(dynamic_cast<Cowboy*>(character)) {
            cowboys.push_back(dynamic_cast<Cowboy*>(character));
        } else if(dynamic_cast<Ninja*>(character)) {
            ninjas.push_back(dynamic_cast<Ninja*>(character));
        }
    }


    // Sets a new leader for the team
    void Team::setNewLeader() { 

        // Logic to select a new leader.
        // Select the alive character closest to the dead leader.
        Character* newLeader = nullptr;
        double min_distance = std::numeric_limits<double>::max();
        for (Character* member : members) {
            if (member->isAlive()) {
                double distance = leader->getLocation().distance(member->getLocation());
                if (distance < min_distance) {
                    min_distance = distance;
                    newLeader = member;
                }
            }
        }
        leader = newLeader;
    }


    // Returns the victim of the team
    Character* Team::getVictim(Team* enemy_team) {
        
        if(enemy_team->stillAlive() == 0){
            return nullptr;
        }

        // Placeholder for logic to select the victim.
        // Here, we select the enemy character closest to the leader.
        Character* victim = nullptr;
        double min_distance = std::numeric_limits<double>::max();
        for (Character* enemy : enemy_team->members) {
            if (enemy->isAlive()) {
                double distance = leader->distance(enemy);
                if (distance < min_distance) {
                    min_distance = distance;
                    victim = enemy;
                }
            }
        }
        return victim;
    }

    
   void Team::attack(Team* enemy_team) {

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

        // Attack with cowboys first
        for (Cowboy* cowboy : cowboys) {
            if (cowboy->isAlive()) {
                // Choose victim and perform attack
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
    
    
        // Attack with ninjas
        for (Ninja* ninja : ninjas) {
            if (ninja->isAlive()) {
                // check if the ninja is close enough to the victim to slash
                if (ninja->distance(victim) < 1.0) {
                    ninja->slash(victim);
                } else {
                    ninja->move(victim);
                }
            }
            if(!victim->isAlive()){ // Check if the victim is dead during the ninjas attack.
               victim = getVictim(enemy_team);
               if(victim == nullptr){
                   return;
               }
            }
        }
    }


    int Team::stillAlive() {
        int aliveCount = 0;
        for(Character* member : members) {
            if(member->isAlive()) {
                aliveCount++;
            }
        }
        return aliveCount;
    }


    void Team::print() {
        for(Cowboy* cowboy : cowboys) {
            std::cout << cowboy->print() << std::endl;
        }
        for(Ninja* ninja : ninjas) {
            std::cout << ninja->print() << std::endl;
        }
        std::cout << std::endl;
    }

    Team::~Team() {
        for(auto& member : members) {
            delete member;
        }
        members.clear();
        cowboys.clear();
        ninjas.clear();
    }

} // namespace ariel
