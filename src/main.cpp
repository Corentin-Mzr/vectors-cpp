#include <iostream>

#include <vector2.hpp>
#include <vector3.hpp>
#include <vector4.hpp>

// Some usage examples
int main()
{
    // Constructor
    Vector2f v1(2, 7);
    Vector2f v2(-5, 3);
    Vector3d v6(1, 2, 3);
    Vector3d v7(6, 7, 9);

    // Basic Operations
    Vector2f v3 = v1 + v2;
    Vector2f v4 = 5.0f * v1;
    Vector2f v5 = v2 / 3.0f;
    v7 += 2.0 * v6;
     
    // Basic functions
    double length = v5.norm();
    double dot = v3.dot(v2);
    Vector3d v8 = v6.cross(v7);
    Vector3d v9 = v8.normalize();
    Vector3d v10 = v8.pow(2);

    // Print
    std::cout << "Vector v10 is: " << v10 << std::endl;

    return 0;
}
