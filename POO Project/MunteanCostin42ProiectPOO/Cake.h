#define _WIN32 1
#ifdef _WIN32
#define NOMINMAX
#include <windows.h>

inline void delay(unsigned long ms)
{
	Sleep(ms);
}
#else
#include <unistd.h>

inline void delay(unsigned long ms)
{
	usleep(ms * 1000);
}
#endif 
#pragma once
#include<string>
#include<iostream>
using namespace std;
class Cake
{
private:
	string name;
public:
	Cake() { name = "n\a"; }
	Cake(string _name)
	{
		name = _name;
	}
	string getName()
	{
		return name;
	}
};