#pragma once
#include"personal.h"
Car::Car(string _marka, string _model,
	string _color, int _year, int _power,
	int _speed) 
{ 
	if (_year > 1980 && _year < 2025)
	{ year = _year; }
	else { year = 0; }
	if (_power > 60 && _power < 800)
	{ power = _power; }
	else { power = 0; }
	if (_speed > 90 && _speed < 250)
	{ speed = _speed; }
	else { speed = 0; }
	
	string color_lst[] = { "Чёрный", "Белый", "Красный", "Синий", "Зелёный", 
		"Жёлтый", "Серый", "Оранжевый"};
	for (size_t i = 0; i < size(color_lst); i++)
	{
		if (_color == color_lst[i])
		{ color = _color; break; }
		else 
		{ color = "(New)" + _color; }
	}
	ifstream fin; 
	vector<string> marka_lst; 
	
	fin.open("data.txt"); 
	string key, value;
	while (fin>>key>>value)
	{ 
		marka_lst.push_back(key); }
	
	fin.close(); 
	
	for (size_t i = 0; i < size(marka_lst); i++)
	{ if (_marka == marka_lst[i])
		{ marka = _marka; break; }
		else { marka = "(New)" + _marka; }
	}
	multimap<string, string> model_list;
	ifstream fin1;
	fin1.open("data.txt");
	string key1, value1;
	while (fin1 >> key1 >> value1) 
	{
		model_list.insert({ key1, value1 });
	}

	
	for (auto& it:model_list)
	{
		if (it.first == _marka and it.second==_model)
		{
			model = _model; 
			marka = _marka;
			break;
		}
		else
		{
			marka = "(New)" + _marka;
			model = "(New)" + _model;

		}
	}
		
	/*
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
			model = _model + " такой модели нету в файле ";
		}

	}
	else
	{
		marka = _marka + " такой марки  нету в файле";

	}

	
	
	
	
	*/
}
