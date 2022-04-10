#pragma once
#include "IncludingsAndUsings.h"
class Statistics
{
	string name;
	float point;

public:
	Statistics() : name("name"), point(0.0f) { }
	Statistics(string name, float point) :name(name), point(point) { }

	void print() const { cout << name << ' ' << point << endl; }
	void save(ofstream& write) const { write << name << '&' << point <<endl; }
	void load(ifstream& read);
};

