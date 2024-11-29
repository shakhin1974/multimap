#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include<fstream>
#include <algorithm>
#include<map>
#include <sstream>

using namespace std;
class Car
{
public:
	Car(string, string, string,int, int, int );
	void SetCarColor(string);
	void Vivod();
	~Car();

private:
	string marka;
	string model;
	string color;
	int year;
	int power;
	int speed;
};
