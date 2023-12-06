#include <cmath>
#include "Header.h"
using namespace std;

Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) {
    _coordX = x2 - x1;
    _coordY = y2 - y1;
    _coordZ = z2 - z1;
}

Vector::Vector(double coordX, double coordY, double coordZ) {
    _coordX = coordX;
    _coordY = coordY;
    _coordZ = coordZ;
}

void Vector::getCordsSecond(double x1, double y1, double z1) {      // input -- first point cords, output -- second point cords
    _x2 = x1 + _coordX;                                     // not both coords, but we calculate one point, using another + vector's basis 
    _y2 = y1 + _coordY;
    _z2 = z1 + _coordZ;
}

void Vector::getCordsFirst(double x2, double y2, double z2) {       // input -- sec
    _x1 = x2 + _coordX;
    _y1 = y2 + _coordY;
    _z1 = z2 + _coordZ;
}

double Vector::length() {
    _length = sqrt(pow(_coordX, 2) + pow(_coordY, 2) + pow(_coordZ, 2));
    return round(_length * 10000) / 10000;                  //using round (here and later) to compare numbers correctly
}

Vector Vector::operator+(Vector& other) {
    Vector summ(_coordX + other._coordX, _coordY + other._coordY, _coordZ + other._coordZ);
    return summ;
}

void Vector::operator+=(Vector& other) {
    _coordX += other._coordX;
    _coordY += other._coordY;
    _coordZ += other._coordZ;
}

Vector Vector::operator-(Vector& other) {
    Vector difference(_coordX - other._coordX, _coordY - other._coordY, _coordZ - other._coordZ);
    return difference;
}

void Vector::operator-=(Vector& other) {
    _coordX -= other._coordX;
    _coordY -= other._coordY;
    _coordZ -= other._coordZ;
}

Vector Vector::operator*(double number) {
    Vector vectorXnumber(_coordX * number, _coordY * number, _coordZ * number);
    return vectorXnumber;
}

void Vector::operator*=(double number) {
    _coordX *= number;
    _coordY *= number;
    _coordZ *= number;
}

Vector Vector::operator*(Vector& other) {
    Vector vectorXvector(_coordY * other._coordZ - _coordZ * other._coordY, -(_coordX * other._coordZ - _coordZ * other._coordX), _coordX * other._coordY - _coordY * other._coordX);
    return vectorXvector;
}

void Vector::operator*=(Vector& other) {
    double x = _coordX;
    double y = _coordY;
    double z = _coordZ;

    x = _coordY * other._coordZ - _coordZ * other._coordY;
    y = -(_coordX * other._coordZ - _coordZ * other._coordX);
    z = _coordX * other._coordY - _coordY * other._coordX;

    _coordX = x;
    _coordY = y;
    _coordZ = z;
}

double Vector::operator/(Vector& other) {   // in math divide of vecotrs isn't defined operation, so i did i tin my way
    // output of divide is number, which shows how much the length of one vector is greater than the other

    double current_length = length();
    double other_length = other.length();
    return round(current_length / other_length * 10000) / 10000;
}

double Vector::operator^(Vector& other) {
    double current_length = length();
    double other_length = other.length();
    _scalar = _coordX * other._coordX + _coordY * other._coordY + _coordZ * other._coordZ;
    return round(_scalar / (current_length * other_length) * 10000) / 10000;
}

bool Vector::operator>(Vector& other) {
    return (round(length() * 10000) / 10000) > (round(other.length() * 10000) / 10000);
}

bool Vector::operator>=(Vector& other) {
    return (round(length() * 10000) / 10000) >= (round(other.length() * 10000) / 10000);
}

bool Vector::operator<(Vector& other) {
    return (round(length() * 10000) / 10000) < (round(other.length() * 10000) / 10000);
}

bool Vector::operator<=(Vector& other) {
    return (round(length() * 10000) / 10000) <= (round(other.length() * 10000) / 10000);
}