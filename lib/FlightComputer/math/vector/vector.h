#ifndef VECTOR_H
#define VECTOR_H
#include "Arduino.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point {
    Vector3 value;
};

struct Vector {
    Vector3 value;
};

double haversine(double lat1, double lon1, double lat2, double lon2); // Credit to GeeksforGeeks

Vector3 add(const Vector3& v1, const Vector3& v2);
Vector3 scalarMultiply(float s, const Vector3& v);
Vector3 unitVector(const Vector3& v);
Vector3 crossProduct(const Vector3& v1, const Vector3& v2);
Vector fromToVector(const Vector3& v1, const Vector3& v2);

float magnitude(const Vector3& v);

#endif