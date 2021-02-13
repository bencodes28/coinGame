#include "pch.h"
#include "Coin.h"
#include <cstdlib>
#include <ctime>

Coin::Coin()
{
	int x = rand() % 2;

	if (x == 0)
	{
		sideUp = "heads";
	}
	else
	{
		sideUp = "tails";
	}
}


Coin::Coin(int coinValue)
{
	value = coinValue;

	int x = rand() % 2;

	if (x == 0)
	{
		sideUp = "heads";
	}
	else
	{
		sideUp = "tails";
	}
}

	void Coin::toss()
{
	int x = rand() % 2;

	if (x == 0)
	{
		sideUp = "heads";
	}
	else
	{
		sideUp = "tails";
	}
}
std::string Coin::getSideUp()
{
	return sideUp;
}

int Coin::getValue()
{
	return value;
}