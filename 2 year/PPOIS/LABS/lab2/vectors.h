#pragma once

class Points {
public:
    double _x = 0, _y = 0, _z = 0;
    Points(double x, double y, double z);
};

class Vector {
private:
    double _coordX = 0;
    double _coordY = 0;
    double _coordZ = 0;
    double _length = 0;
    double _scalar = 0;

    double RoundUP(const double number) const ;
    double _x1 = 0, _x2 = 0, _y1 = 0, _y2 = 0, _z1 = 0, _z2 = 0;
public:
    
    Vector(double x1, double y1, double z1, double x2, double y2, double z2);
    Vector(double coordX, double coordY, double coordZ);

    Points CordsSecond(double x1, double y1, double z1);
    Points CordsFirst(double x2, double y2, double z2);

    double length();

    Vector operator+(const Vector& other) const;
    Vector operator+=(Vector& other);
    Vector operator-(const Vector& other) const;
    Vector operator-=(Vector& other);

    Vector operator*(const double number) const;
    Vector operator*=(double number);
    Vector operator*(const Vector& other) const;
    Vector operator*=(Vector& other);

    double operator/(Vector& other);

    double operator^(Vector& other);

    bool operator>(Vector& other);
    bool operator>=(Vector& other);
    bool operator<(Vector& other);
    bool operator<=(Vector& other);
};