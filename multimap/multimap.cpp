#include"personal.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

Car::Car(string _marka, string _model,
string _color, int _year, int _power, int _speed)
{
	ifstream fin; vector<string> marka_lst; fin.open("marka_lst.txt");
	string br;
	while (!fin.eof())
	{ fin >> br;  marka_lst.push_back(br); }
	fin.close();
	for (size_t i = 0; i < size(marka_lst); i++)
	{ if (_marka == marka_lst[i])
		{ marka = _marka; break; }
		else { marka = "(New)" + _marka; } 
	}
	map<string, vector<string>> CarMap;
	ifstream marka_File("marka_lst.txt");
	ifstream model_File("model_lst.txt");
	string marka_;
	while (getline(marka_File, marka_)) {
		string model_txt;
		if (getline(model_File, model_txt)) {
			istringstream iss(model_txt); 
			string model_;
			vector<string> models;
		while (iss >> model_) {
				models.push_back(model_);
			}
	CarMap[marka_] = models;
		}
	}

	marka_File.close();
	model_File.close();
	auto marka_find = CarMap.find(_marka);
	if (marka_find != CarMap.end())
	{
		marka = _marka;
		auto vect_model = marka_find->second;
		auto model_find = find(vect_model.begin(), vect_model.end(), _model);
		if (model_find != vect_model.end())
		{
			model = _model;
		}
		else
		{
			model = _model + " такой модели нету в файле ";		}

	}
	else
	{
		marka = _marka + " такой марки  нету в файле";
		model = _model + "(Íó ðàç íåòó ìàðêè, òî òî÷íî íåòó ìîäåëè)";

	}


	string color_lst[] = { "Чёрный", "Белый", "Красный", "Синий", "Зелёный", "Жёлтый", "Серый" };	
	for (size_t i = 0; i < size(color_lst); i++)
	for (size_t i = 0; i < size(color_lst); i++)
	{
		if (_color == color_lst[i])
		{
			color = _color;
			break;
		}
		else
		{
			color = "(New)" + _color;
		}
	}
	if (_year > 1980 && _year < 2025)
	{
		year = _year;
	}
	else { year = 0; }
	if (_power > 60 && _power < 800)
	{
		power = _power;
	}
	else { power = 0; }
	if (_speed > 90 && _speed < 250)
	{
		speed = _speed;
	}
	else { speed = 0; }
}
void Car::SetCarColor(string col)
{
	color = col;
}
void Car::Vivod()
{
	ofstream fout;
	fout.open("car.txt");
	
		cout << marka << " " << model << " " << color << " " << year << " " << power << " " << speed << endl;
	
}
Car::~Car()
{
}

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
	multimap<string, string> m;
	m.emplace("AlfaRomeo", "Brera");
	m.emplace("AlfaRomeo", "MiTo");
	m.emplace("AlfaRomeo", "Giulietta");
	m.emplace("Audi", "A1");
	m.emplace("Audi", "A3");
	m.emplace("Audi", "A4");
	m.insert({ "BMW", "M3" });
	m.insert({ "BMW", "M4" });
	m.insert({ "BMW", "M5" });
	 
	for (auto& it : m) {
		if (it.first == "BMW" && it.second == "M3")
		{
			cout << "Ok ";
		}
	}
	*/
	Car Audi("Audi", "A1", "Серый", 2020, 150, 200);
	Audi.Vivod();
}
 
