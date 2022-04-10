#pragma once
#include "IncludingsAndUsings.h"


class Question///абстрактный родительский класс Question:
{
protected:
	string qstTxt;//поле qstTxt (сокр. от question text, текст вопроса).

public:
	Question()
		:qstTxt("question") {}//конструктор по умолчанию;
	Question(string qstTxt)
		:qstTxt(qstTxt) {}//конструктор преобразования типа string -> Question;
	
	virtual bool answerIsRight() const = 0;//чисто виртуальная функция answerIsRight, использующаяся в дочерних классах класса Question;
	virtual int getType() const = 0;
	virtual void add() = 0;
	virtual void showAnswer() const = 0;
	virtual void print() const { cout << qstTxt; }//виртуальный метод print, использующийся для вывода поля qstTxt, а также вывода других полей в дочерних классах;
	virtual void save(ofstream& write) const = 0;
	virtual void load(ifstream& read) = 0;
	
};

