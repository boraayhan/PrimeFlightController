#include "vector.h"

double haversine(double lat1, double lon1, double lat2, double lon2) // Credit to GeeksforGeeks
{
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = (lat1)*M_PI / 180.0;
    lat2 = (lat2)*M_PI / 180.0;
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

Vector3 add(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

Vector3 scalarMultiply(float s, const Vector3 &v)
{
    return Vector3{s * v.x, s * v.y, s * v.z};
}

Vector3 unitVector(const Vector3 &v)
{
    float mag = magnitude(v);
    if (mag == 0)
    {
        return {0, 0, 0};
    }
    return scalarMultiply(1 / mag, v);
}

Vector3 crossProduct(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3{
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x};
}

Vector fromToVector(const Vector3& v1, const Vector3& v2) {
    return Vector{v2.x-v1.x, v2.y-v1.y, v2.z-v1.z};
}
float magnitude(const Vector3 &v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}