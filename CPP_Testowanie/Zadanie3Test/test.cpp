#include "pch.h"

#include "../Zadanie3/Triangle.h"

TEST(TriangleAreaTest, getArea_ValidTriangle_Calculated) {
	Triangle triangle(3, 4, 5);

	EXPECT_DOUBLE_EQ(triangle.getArea(), 6);
}

TEST(TriangleAreaTest, getArea_InvalidTriangle_Calculated) {
	Triangle triangle(1, 2, 3); //1,2,3 zwraca pole 0 dla niew³asciwego trójk¹t nawet nie sprawdzaj¹c tego

	EXPECT_DOUBLE_EQ(triangle.getArea(), 0);
}

TEST(TrianglePerimeterTest, getPerimeter_ValidTriangle_Calculated) {
	Triangle triangle(3, 4, 5);

	EXPECT_DOUBLE_EQ(triangle.getPerimeter(), 12);
}

TEST(TrianglePerimeterTest, getPerimeter_InvalidTriangle_Calculated) {
	Triangle triangle(1, 2, 3);

	EXPECT_DOUBLE_EQ(triangle.getPerimeter(), 0);
}

TEST(TriangleValidityTest, isValid_ValidTriangle_ReturnsTrue) {
	Triangle triangle(3, 4, 5);

	EXPECT_TRUE(triangle.isValid());
}

TEST(TriangleValidityTest, isValid_InvalidTriangle_ReturnsFalse) {
	Triangle triangle(1, 2, 3);

	EXPECT_FALSE(triangle.isValid());
}