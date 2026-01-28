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

float haversine(float lat1, float lon1, float lat2, float lon2); // Credit to GeeksforGeeks

Vector3 add(Vector3& v1, Vector3& v2);
Vector3 scalarMultiply(float s, Vector3& v);
Vector3 unitVector(Vector3& v);
Vector fromToVector(Vector3& v1, Vector3& v2);

float magnitude(Vector3& v);

#endif