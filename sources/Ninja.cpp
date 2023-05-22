#include "Ninja.hpp"

namespace ariel {

// Constructor
Ninja::Ninja(const std::string& name, const Point& location, int hit_points, int speed)
    : Character(name, location, hit_points), speed(speed) {}

// Methods

// Moves the ninja towards the given enemy
void Ninja::move(Character* enemy) {
    if (enemy != nullptr) {
        Point new_location = Point::moveTowards(this->getLocation(), enemy->getLocation(), speed);
        this->setLocation(new_location);
    }
}

// Slashes the given enemy
void Ninja::slash(Character* enemy) {
    if (!this->isAlive() || !enemy->isAlive()) {
        throw std::runtime_error("Dead characters cannot attack or be attacked");
    }

    if (this == enemy) {
        throw std::runtime_error("Cannot harm self.");
    }
    
    if (enemy != nullptr) {
        double distance_to_enemy = distance(enemy);
        if (distance_to_enemy < 1.0) { // assuming slash range is 1.0
            enemy->hit(40);
        }
    }
}

// Returns a string representation of the character
std::string Ninja::print() {
    if(this->isAlive()) {
        return "N " + this->getName() + " " + this->getLocation().tostring() + " " + std::to_string(this->getHitPoints()) + " " + std::to_string(this->speed);
    }else {
        return "N ("  + this->getName() + ") " + this->getLocation().tostring() + " DEAD";
    }
}

}  // namespace ariel
