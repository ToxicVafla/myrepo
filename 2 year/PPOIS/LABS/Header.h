#pragma once

class Vector {
private:
    double _coordX = 0;
    double _coordY = 0;
    double _coordZ = 0;
    double _length = 0;
    double _scalar = 0;

public:
    double _x1 = 0, _x2 = 0, _y1 = 0, _y2 = 0, _z1 = 0, _z2 = 0;

    Vector(double x1, double y1, double z1, double x2, double y2, double z2);
    Vector(double coordX, double coordY, double coordZ);

    void getCordsSecond(double x1, double y1, double z1);
    void getCordsFirst(double x2, double y2, double z2);

    double length();

    Vector operator+(Vector& other);
    void operator+=(Vector& other);
    Vector operator-(Vector& other);
    void operator-=(Vector& other);

    Vector operator*(double number);
    void operator*=(double number);
    Vector operator*(Vector& other);
    void operator*=(Vector& other);

    double operator/(Vector& other);

    double operator^(Vector& other);

    bool operator>(Vector& other);
    bool operator>=(Vector& other);
    bool operator<(Vector& other);
    bool operator<=(Vector& other);
};