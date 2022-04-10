#pragma once
#include "IncludingsAndUsings.h"

using std::string;

class Answer///класс Answer(ответ):
{
	string ansTxt;//поле ansTxt(сокр. от answer text, текст ответа);
	bool isRight;//поле isRight, определяющее, является ли ответ правильным.

public:
	Answer() :ansTxt("Answer"), isRight(false) {}//конструктор по умолчанию;
	Answer(string ansTxt, bool isRight):ansTxt(ansTxt), isRight(isRight) {}//конструктор преобразования типов string, bool -> Answer.

	string getAnsTxt() const { return ansTxt; }
 	bool answerIsRight() const { return isRight; }
	void setBool(bool isRight) { this->isRight = isRight; }

	void save(ofstream& write) const { write << ansTxt <<' ' << isRight <<endl; }
	void load(ifstream& read) { read >> ansTxt >> isRight; }
};

