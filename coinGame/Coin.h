#pragma once

#include <string>
#include<cstdlib>


#include<ctime>

#ifndef COIN_H
#define COIN_H



//Coin class declaration
class Coin
{
private:
	std::string sideUp;
	int value;

public:
	Coin();
	Coin(int);
	std::string getSideUp();
	int getValue();
	void toss();
};
#endif 
