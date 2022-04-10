#pragma once
#include "IncludingsAndUsings.h"


class Question///����������� ������������ ����� Question:
{
protected:
	string qstTxt;//���� qstTxt (����. �� question text, ����� �������).

public:
	Question()
		:qstTxt("question") {}//����������� �� ���������;
	Question(string qstTxt)
		:qstTxt(qstTxt) {}//����������� �������������� ���� string -> Question;
	
	virtual bool answerIsRight() const = 0;//����� ����������� ������� answerIsRight, �������������� � �������� ������� ������ Question;
	virtual int getType() const = 0;
	virtual void add() = 0;
	virtual void showAnswer() const = 0;
	virtual void print() const { cout << qstTxt; }//����������� ����� print, �������������� ��� ������ ���� qstTxt, � ����� ������ ������ ����� � �������� �������;
	virtual void save(ofstream& write) const = 0;
	virtual void load(ifstream& read) = 0;
	
};

