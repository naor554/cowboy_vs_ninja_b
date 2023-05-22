#include "Point.hpp"


namespace ariel {

    // Constructor
    Point::Point() : x(0), y(0) {}

    // Constructor
    Point::Point(double posx, double posy) : x(posx), y(posy) {}

    // Methods

    // Returns the distance between this point and another
    double Point::distance(const Point& other) const{
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    // Prints the point
    void Point::print() {
        cout << "(" << x << ", " << y << ")";
    }

    // Returns a string representation of the point
    string Point::tostring() const{
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // Returns a point that is distance away from the source point, in a straight line towards the destination point
    Point Point::moveTowards(const Point& source, const Point& destination, double distance) {
        if (distance < 0){
            throw std::invalid_argument("distance must be non-negative");
        }
        double d = source.distance(destination);
        if (d < distance) {
            return destination;
        }
        double ratio = distance / d;
        double x = source.x + (destination.x - source.x) * ratio;
        double y = source.y + (destination.y - source.y) * ratio;
        return Point(x, y);
    }

}  // namespace ariel
