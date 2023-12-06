#include "pch.h"
#include "C:\Users\vasil\source\repos\test_try1\test_try11\test_try11.cpp"

TEST(tests, constructTEST) {
	Vector f(1, 1, 1, 3, 3, 3);
	f.getCordsSecond(0, 0, 0);
	EXPECT_EQ(f._x2, 2);
	EXPECT_EQ(f._y2, 2);
	EXPECT_EQ(f._z2, 2);
	EXPECT_TRUE(true);
}

TEST(tests, getCords2ndTEST) {
	Vector f(1, 1, 1);
	f.getCordsSecond(2, 3, 4);
	EXPECT_EQ(f._x2, 3);
	EXPECT_EQ(f._y2, 4);
	EXPECT_EQ(f._z2, 5);
	EXPECT_TRUE(true);
}

TEST(tests, getCords1stTEST) {
	Vector f(2, 2, 2);
	f.getCordsFirst(1, 1, 3);
	EXPECT_EQ(f._x1, 3);
	EXPECT_EQ(f._y1, 3);
	EXPECT_EQ(f._z1, 5);
	EXPECT_TRUE(true);
}

TEST(tests, lengthTEST) {
	Vector f(3, 2, 7);
	EXPECT_EQ(f.length(), 7.874);
	EXPECT_TRUE(true);
}

TEST(tests, summCeqFplusGTEST) {
	Vector f(1, 2, 3);
	Vector g(5, 1, 1);
	Vector c = f + g;
	c.getCordsSecond(0, 0, 0);
	EXPECT_EQ(c._x2, 6);
	EXPECT_EQ(c._y2, 3);
	EXPECT_EQ(c._z2, 4);
	EXPECT_TRUE(true);
}

TEST(tests, summFeqFplusGTEST) {
	Vector f(1, 2, 3);
	Vector g(2, 2, 5);
	f += g;
	f.getCordsSecond(0, 0, 0);
	EXPECT_EQ(f._x2, 3);
	EXPECT_EQ(f._y2, 4);
	EXPECT_EQ(f._z2, 8);
	EXPECT_TRUE(true);
}

TEST(tests, diffCeqFminusGTEST) {
	Vector f(1, 2, 3);
	Vector g(5, 1, 1);
	Vector c = f - g;
	c.getCordsSecond(0, 0, 0);
	EXPECT_EQ(c._x2, -4);
	EXPECT_EQ(c._y2, 1);
	EXPECT_EQ(c._z2, 2);
	EXPECT_TRUE(true);
}

TEST(tests, diffFeqFminusGTEST) {
	Vector f(1, 2, 3);
	Vector g(2, 2, 5);
	f -= g;
	f.getCordsSecond(0, 0, 0);
	EXPECT_EQ(f._x2, -1);
	EXPECT_EQ(f._y2, 0);
	EXPECT_EQ(f._z2, -2);
	EXPECT_TRUE(true);
}

TEST(tests, prodCeqFxNumTEST) {
	Vector f(1, 2, 3);
	double number = 0.5;
	Vector c = f * number;
	c.getCordsSecond(0, 0, 0);
	EXPECT_EQ(c._x2, 0.5);
	EXPECT_EQ(c._y2, 1);
	EXPECT_EQ(c._z2, 1.5);
	EXPECT_TRUE(true);
}

TEST(tests, prodFeqFxNumTEST) {
	Vector f(1, 2, 3);
	double number = 2;
	f *= number;
	f.getCordsSecond(0, 0, 0);
	EXPECT_EQ(f._x2, 2);
	EXPECT_EQ(f._y2, 4);
	EXPECT_EQ(f._z2, 6);
	EXPECT_TRUE(true);
}

TEST(tests, prodCeqFxGTEST) {
	Vector f(1, 2, 3);
	Vector g(3, 1, 5);
	Vector c = f * g;
	c.getCordsSecond(0, 0, 0);
	EXPECT_EQ(c._x2, 7);
	EXPECT_EQ(c._y2, 4);
	EXPECT_EQ(c._z2, -5);
	EXPECT_TRUE(true);
}

TEST(tests, prodFeqFxGTEST) {
	Vector f(3, 2, 2);
	Vector g(4, 1, 3);
	f *= g;
	f.getCordsSecond(0, 0, 0);
	EXPECT_EQ(f._x2, 4);
	EXPECT_EQ(f._y2, -1);
	EXPECT_EQ(f._z2, -5);
	EXPECT_TRUE(true);
}

TEST(tests, divisionNumCeqFdivideGTEST) {
	Vector f(3, 4, 5);
	Vector g(2, 2, 1);
	double c = f / g;
	EXPECT_EQ(c, 2.357);
	EXPECT_TRUE(true);
}

TEST(tests, angleNumCeqFinGTEST) {
	Vector f(1, 2, 3);
	Vector g(4, 4, 4);
	double c = f ^ g;
	EXPECT_EQ(c, 0.9258);
	EXPECT_TRUE(true);
}

TEST(tests, boolGT_TEST) {
	Vector f(11, 22, 33);
	Vector g(1, 2, 3);
	bool c = f > g;
	EXPECT_EQ(c, true);
	EXPECT_TRUE(true);
}

TEST(tests, boolGE1_TEST) {
	Vector f(11, 22, 33);
	Vector g(1, 2, 3);
	bool c = f >= g;
	EXPECT_EQ(c, true);
	EXPECT_TRUE(true);
}

TEST(tests, boolGE2_TEST) {
	Vector f(1, 2, 3);
	Vector g(1, 2, 3);
	bool c = f >= g;
	EXPECT_EQ(c, true);
	EXPECT_TRUE(true);
}

TEST(tests, boolLT_TEST) {
	Vector f(1, 2, 3);
	Vector g(11, 22, 33);
	bool c = f < g;
	EXPECT_EQ(c, true);
	EXPECT_TRUE(true);
}

TEST(tests, boolLE1_TEST) {
	Vector f(1, 2, 3);
	Vector g(11, 22, 33);
	bool c = f <= g;
	EXPECT_EQ(c, true);
	EXPECT_TRUE(true);
}

TEST(tests, boolLE2_TEST) {
	Vector f(1, 2, 3);
	Vector g(1, 2, 3);
	bool c = f <= g;
	EXPECT_EQ(c, true);
	EXPECT_TRUE(true);
}