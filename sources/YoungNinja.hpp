#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include <string>
#include <vector>
#include "Ninja.hpp"
using namespace std;

namespace ariel{
   class YoungNinja : public Ninja {
    public:
        YoungNinja(const std::string& name, const Point& location);
    };
}

#endif // YOUNGNINJA_HPP