#include <iostream>

enum One
{
    ZERO,
    ONE,
    TWO
};

enum Animals
{
    DUCK,
    DOG,
    COW,
    PIG
};

enum class Colour
{
    WHITE, RED, ORANGE, BLUE
};

enum class Fruit
{
    APPLE, BANANA, ORANGE
};

int main()
{
    int x = ZERO + ONE + TWO + PIG + COW;

    bool logic = (COW == TWO);

    std::cout << "Wartosc: " << x;
    std::cout << "Czy krowa to dwa? " << logic;

    int z = static_cast<int>(Colour::WHITE);
}
