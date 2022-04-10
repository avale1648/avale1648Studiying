#pragma once
#include "IncludingsAndUsings.h"
//#include "SinAnsQst.h"
//#include "MltAnsQst.h"
#include "SingleAnswerQuestion.h"
#include "MultiAnswerQuestion.h"
#include "FreeInpQst.h"

class Test
{
	string name;
	vector<Question*> questions;

public:
	Test() : name("Test") { }
	Test(string name):name(name) { }
	void add(string option);
	void del(int n) { questions.erase(questions.begin() + n); }
	void print(bool admin) const;
	void menu();

	void save(ofstream& write) const;
	void load(ifstream& read);

	string getName() const { return name; }

	float take(bool admin);
};

