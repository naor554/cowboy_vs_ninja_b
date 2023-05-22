#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include <string>
#include <vector>
#include "Ninja.hpp"
using namespace std;

namespace ariel{
   class OldNinja : public Ninja {
    public:
        OldNinja(const std::string& name, const Point& location);
    };
}

#endif // OLDNINJA_HPP