#include <cmath>
#include "vectors.h"
using namespace std;

Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) : Vector(x2 - x1, y2 - y1, z2 - z1) {}     // Delegating constructor

Vector::Vector(double coordX, double coordY, double coordZ){
    _coordX = coordX;
    _coordY = coordY;
    _coordZ = coordZ;
}

Points Vector::CordsSecond(double x1, double y1, double z1) {   // input -- first point cords, output -- second point cords
    _x2 = x1 + _coordX;                                         // not both coords, but we calculate one point, using another + vector's basis 
    _y2 = y1 + _coordY;
    _z2 = z1 + _coordZ;
    return Points::Points(_x2, _y2, _z2);
}

Points Vector::CordsFirst(double x2, double y2, double z2) {    // input -- second point cords, output -- first point cords
    _x1 = x2 - _coordX;                                         // not both coords, but we calculate one point, using another + vector's basis 
    _y1 = y2 - _coordY;
    _z1 = z2 - _coordZ;
    return Points::Points(_x1, _y1, _z1);
}

double Vector::length() {
    _length = sqrt(pow(_coordX, 2) + pow(_coordY, 2) + pow(_coordZ, 2));
    return RoundUP(_length);                  //using round (here and later) to compare numbers correctly
}

Vector Vector::operator+(const Vector& other) const{
    Vector summ(_coordX + other._coordX, _coordY + other._coordY, _coordZ + other._coordZ);
    return summ;
}

Vector Vector::operator+=(Vector& other) {
    _coordX += other._coordX;
    _coordY += other._coordY;
    _coordZ += other._coordZ;
    return Vector::Vector(_coordX, _coordY, _coordZ);
}

Vector Vector::operator-(const Vector& other) const{
    Vector difference(_coordX - other._coordX, _coordY - other._coordY, _coordZ - other._coordZ);
    return difference;
}

Vector Vector::operator-=(Vector& other) {
    _coordX -= other._coordX;
    _coordY -= other._coordY;
    _coordZ -= other._coordZ;
    return Vector::Vector(_coordX, _coordY, _coordZ);
}

Vector Vector::operator*(const double number) const{
    Vector vectorXnumber(_coordX * number, _coordY * number, _coordZ * number);
    return vectorXnumber;
}

Vector Vector::operator*=(double number) {
    _coordX *= number;
    _coordY *= number;
    _coordZ *= number;
    return Vector::Vector(_coordX, _coordY, _coordZ);
}

Vector Vector::operator*(const Vector& other) const{
    Vector vectorXvector(_coordY * other._coordZ - _coordZ * other._coordY, -(_coordX * other._coordZ - _coordZ * other._coordX), _coordX * other._coordY - _coordY * other._coordX);
    return vectorXvector;
}

Vector Vector::operator*=(Vector& other) {
    double x = _coordX;
    double y = _coordY;
    double z = _coordZ;

    x = _coordY * other._coordZ - _coordZ * other._coordY;
    y = -(_coordX * other._coordZ - _coordZ * other._coordX);
    z = _coordX * other._coordY - _coordY * other._coordX;

    _coordX = x;
    _coordY = y;
    _coordZ = z;
    return Vector::Vector(_coordX, _coordY, _coordZ);
}

double Vector::operator/(Vector& other) {   // in math divide of vecotrs isn't defined operation, so i did in my way
    // output of divide is number, which shows how much the length of one vector is greater than the other

    double current_length = length();
    double other_length = other.length();
    return RoundUP(current_length / other_length);
}

double Vector::operator^(Vector& other) {
    double current_length = length();
    double other_length = other.length();
    _scalar = _coordX * other._coordX + _coordY * other._coordY + _coordZ * other._coordZ;
    return RoundUP(_scalar / (current_length * other_length));
}

bool Vector::operator>(Vector& other) {
    return length() > other.length();
}

bool Vector::operator>=(Vector& other) {
    return RoundUP(length()) >= RoundUP(other.length());
}

bool Vector::operator<(Vector& other) {
    return length() < other.length();
}

bool Vector::operator<=(Vector& other) {
    return RoundUP(length()) <= RoundUP(other.length());
}


double Vector::RoundUP(const double number) const {    //using round to prevent errors in comparing close numbers  7.1111111111... -> 7.1111
    return round(number * 10000) / 10000;
}

Points::Points(double x, double  y, double z) {
    _x = x;
    _y = y;
    _z = z;
}