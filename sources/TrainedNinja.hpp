#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include <string>
#include <vector>
#include "Ninja.hpp"
using namespace std;

namespace ariel{
   class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const std::string& name, const Point& location);
    };
}

#endif // TRAINEDNINJA_HPP