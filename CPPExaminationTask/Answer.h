#pragma once
#include "IncludingsAndUsings.h"

using std::string;

class Answer///����� Answer(�����):
{
	string ansTxt;//���� ansTxt(����. �� answer text, ����� ������);
	bool isRight;//���� isRight, ������������, �������� �� ����� ����������.

public:
	Answer() :ansTxt("Answer"), isRight(false) {}//����������� �� ���������;
	Answer(string ansTxt, bool isRight):ansTxt(ansTxt), isRight(isRight) {}//����������� �������������� ����� string, bool -> Answer.

	string getAnsTxt() const { return ansTxt; }
 	bool answerIsRight() const { return isRight; }
	void setBool(bool isRight) { this->isRight = isRight; }

	void save(ofstream& write) const { write << ansTxt <<' ' << isRight <<endl; }
	void load(ifstream& read) { read >> ansTxt >> isRight; }
};

