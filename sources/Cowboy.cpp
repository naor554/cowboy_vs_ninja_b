#include "Cowboy.hpp"

namespace ariel {

// Constructor
Cowboy::Cowboy(const std::string& name, const Point& location)
    : Character(name, location, 110), boolets(6) {}  // Cowboy starts with 6 bullets and 110 hit points

// Methods

// Shoots the given enemy
void Cowboy::shoot(Character* enemy) {
    if (!this->isAlive() || !enemy->isAlive()) {
        throw std::runtime_error("Dead characters cannot attack or be attacked");
    }

    if (this == enemy) {
        throw std::runtime_error("Cannot harm self.");
    }
    
    if(this->isAlive() && boolets > 0) {
        boolets--;
        enemy->hit(10);
    }
}

// check if cowboy has bullets
bool Cowboy::hasboolets() {
    return boolets > 0;
}

// reload cowboy's gun
void Cowboy::reload() {
    if (!this->isAlive()) {
        throw std::runtime_error("Dead cowboy cannot reload.");
    }
    boolets = 6;
}

// Returns a string representation of the character
std::string Cowboy::print() {
    if(this->isAlive()) {
        return "C " + this->getName() + " " + this->getLocation().tostring() + " " + std::to_string(this->getHitPoints()) + " " + std::to_string(this->boolets);
    }else {
        return "C ("  + this->getName() + ") " + this->getLocation().tostring() + " DEAD";
    }
}

}  // namespace ariel
