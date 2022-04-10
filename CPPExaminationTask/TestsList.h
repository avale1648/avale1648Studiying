#pragma once
#include "IncludingsAndUsings.h"
#include "Test.h"

class TestsList
{
	vector<Test> tests;

public:
	TestsList();
	void add(Test& test) { tests.push_back(test); }
	void del(int n) { tests.erase(tests.begin() + n); }
	void print() const;
	void save() const;
	void load();

	int size() { return tests.size(); }
	Test& operator[](int index);
};

