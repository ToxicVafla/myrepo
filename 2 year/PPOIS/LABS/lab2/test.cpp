#include "pch.h"
#include "..\test_try11\vectors.cpp" 

TEST(tests, constructTEST) {
	Vector f(1, 1, 1, 3, 3, 3);
	Points res = f.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 2);
	EXPECT_EQ(res._y, 2);
	EXPECT_EQ(res._z, 2);
}

TEST(tests, getCords2ndTEST) {
	Vector f(1, 1, 1);
	Points res = f.CordsSecond(2, 3, 4);
	EXPECT_EQ(res._x, 3);
	EXPECT_EQ(res._y, 4);
	EXPECT_EQ(res._z, 5);
}

TEST(tests, getCords1stTEST) {
	Vector f(2, 2, 2);
	Points res = f.CordsFirst(1, 1, 3);
	EXPECT_EQ(res._x, -1);
	EXPECT_EQ(res._y, -1);
	EXPECT_EQ(res._z, 1);
}

TEST(tests, lengthTEST) {
	Vector f(3, 2, 7);
	EXPECT_EQ(f.length(), 7.874);
}

TEST(tests, summCeqFplusGTEST) {
	Vector f(1, 2, 3);
	Vector g(5, 1, 1);
	Vector c = f + g;
	Points res = c.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 6);
	EXPECT_EQ(res._y, 3);
	EXPECT_EQ(res._z, 4);
}

TEST(tests, summFeqFplusGTEST) {
	Vector f(1, 2, 3);
	Vector g(2, 2, 5);
	f += g += g += g;		//at first it counts g += g, then g += g with new values, and then f += g (final g). Same works for "-=", "*=".
	Points res = f.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 9);
	EXPECT_EQ(res._y, 10);
	EXPECT_EQ(res._z, 23);
}


TEST(tests, diffCeqFminusGTEST) {
	Vector f(1, 2, 3);
	Vector g(5, 1, 1);
	Vector c = f - g;
	Points res = c.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, -4);
	EXPECT_EQ(res._y, 1);
	EXPECT_EQ(res._z, 2);
}

TEST(tests, diffFeqFminusGTEST) {
	Vector f(1, 2, 3);
	Vector g(2, 2, 5);
	f -= g;
	Points res = f.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, -1);
	EXPECT_EQ(res._y, 0);
	EXPECT_EQ(res._z, -2);
}

TEST(tests, prodCeqFxNumTEST) {
	Vector f(1, 2, 3);
	double number = 0.5;
	Vector c = f * number;
	Points res = c.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 0.5);
	EXPECT_EQ(res._y, 1);
	EXPECT_EQ(res._z, 1.5);
}

TEST(tests, prodFeqFxNumTEST) {
	Vector f(1, 2, 3);
	double number = 2;
	f *= number;
	Points res = f.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 2);
	EXPECT_EQ(res._y, 4);
	EXPECT_EQ(res._z, 6);
}

TEST(tests, prodCeqFxGTEST) {
	Vector f(1, 2, 3);
	Vector g(3, 1, 5);
	Vector c = f * g;
	Points res = c.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 7);
	EXPECT_EQ(res._y, 4);
	EXPECT_EQ(res._z, -5);
}

TEST(tests, prodFeqFxGTEST) {
	Vector f(3, 2, 2);
	Vector g(4, 1, 3);
	f *= g;
	Points res = f.CordsSecond(0, 0, 0);
	EXPECT_EQ(res._x, 4);
	EXPECT_EQ(res._y, -1);
	EXPECT_EQ(res._z, -5);
}

TEST(tests, divisionNumCeqFdivideGTEST) {
	Vector f(3, 4, 5);
	Vector g(2, 2, 1);
	double c = f / g;
	EXPECT_EQ(c, 2.357);
}

TEST(tests, angleNumCeqFinGTEST) {
	Vector f(1, 2, 3);
	Vector g(4, 4, 4);
	double c = f ^ g;
	EXPECT_EQ(c, 0.9258);
}

TEST(tests, boolGT_TEST) {
	Vector f(11, 22, 33);
	Vector g(1, 2, 3);
	bool c = f > g;
	EXPECT_EQ(c, true);
}

TEST(tests, boolGE1_TEST) {
	Vector f(11, 22, 33);
	Vector g(1, 2, 3);
	bool c = f >= g;
	EXPECT_EQ(c, true);
}

TEST(tests, boolGE2_TEST) {
	Vector f(1, 2, 3);
	Vector g(1, 2, 3);
	bool c = f >= g;
	EXPECT_EQ(c, true);
}

TEST(tests, boolLT_TEST) {
	Vector f(1, 2, 3);
	Vector g(11, 22, 33);
	bool c = f < g;
	EXPECT_EQ(c, true);
}

TEST(tests, boolLE1_TEST) {
	Vector f(1, 2, 3);
	Vector g(11, 22, 33);
	bool c = f <= g;
	EXPECT_EQ(c, true);
}

TEST(tests, boolLE2_TEST) {
	Vector f(1, 2, 3);
	Vector g(1, 2, 3);
	bool c = f <= g;
	EXPECT_EQ(c, true);
}
