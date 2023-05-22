#include "Character.hpp"


namespace ariel {


    // Constructor
    Character::Character(const std::string& name, const Point& location, int hit_points)
        : name(name), location(location), hit_points(hit_points) {}

    // Methods

    // Returns true if the character is alive
    bool Character::isAlive() {
        return hit_points > 0;
    }

    // Returns true if the character has a team
    bool Character::getHasTeam() { 
        return hasTeam; 
    }

    // Sets the character's team   
    void Character::setHasTeam(bool hasTeam) {  
       this->hasTeam = hasTeam;
    }

    // Returns the distance between this character and another
    double Character::distance(Character* other) {
        return this->location.distance(other->location);
    }

    // Reduces the character's hit points by the given damage
    void Character::hit(float damage) {
        if (damage < 0) {
            throw std::invalid_argument("Damage cannot be negative");
        }
        this->hit_points -= damage;
    }

    // Returns the character's hit points
    int Character::getHitPoints() {
        return this->hit_points;
    }

    // Returns the character's name
    std::string Character::getName() {
        return this->name;
    }

    // Returns the character's location
    Point Character::getLocation() {
        return this->location;
    }

    // Sets the character's location
    void Character::setLocation(Point location) {
        this->location = location;
    }
    
    // Prints the character's details
    string Character::print() {
        return this->name + " at " + this->location.tostring() + " HP: " + to_string(this->hit_points);
    }


}  // namespace ariel
