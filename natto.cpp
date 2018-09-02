/*
// natto.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#define LOG(x) std::cout << x << std::endl

class Player
{
public:
	int x, y;
	int speed;
	
	
	void move(int xa, int ya)
	{
		Player player;
		player.x += xa * player.speed;
		player.y += ya * player.speed;
	}
};

class Destructor
{
public:
	float x, y;
	Destructor()
	{
		x = 0.0f;
		y = 0.0f;
		LOG("ENTITY CREATED!");
	}
	Destructor(float X, float Y)
	{
		x = X;
		y = Y;
	}
	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
	~Destructor()
	{
		LOG("ENTITY DESTROYED!");
	}
};

class Inheritance
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};
class Character: public Inheritance
{
public:
	const char* Name;
	void PrintName()
	{
		LOG(Name);
	}
};

int main()
{
	

	std::cin.get();
    return 0;
}

*/