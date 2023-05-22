#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel{
    class Point {

        public:
            Point();
            Point(double posx, double posy);
            double distance(const Point& other) const;
            void print();
            string tostring() const;
            static Point moveTowards(const Point& source, const Point& destination, double distance);
            
        private:
            double x, y;
    };
}

#endif // POINT_HPP