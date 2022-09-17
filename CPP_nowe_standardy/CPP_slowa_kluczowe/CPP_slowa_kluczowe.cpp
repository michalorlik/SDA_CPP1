#include <iostream>

class Fish
{
public:
	virtual void swim(int speed) = 0;
};

class GoldFish : public Fish
{
public:
	virtual void swim(int speed) final override
	{
		std::cout << "Rybka ";
		for (int i = 0; i < speed; ++i)
		{
			std::cout << " plynie ";
		}
		std::cout << std::endl;
	}

	void bulbul(float wspolczynnik)
	{
		std::cout << "bul bul " << wspolczynnik << std::endl;
	}

	void bulbul(int wspolczynnik) = delete;
};

class WhiteGoldFish : public GoldFish
{

};

int main()
{
	GoldFish rybka;
	rybka.swim(3);
	rybka.bulbul(2.5f);
	//rybka.bulbul(2);
}

