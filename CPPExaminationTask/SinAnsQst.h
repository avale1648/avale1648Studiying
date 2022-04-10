#pragma once
#include "IncludingsAndUsings.h"
#include "Question.h"
#include "Answer.h"

class SinAnsQst : public Question ///�������� ����� SinAnsQst(����. �� Single Answer Question, ������ � ����� �������) ������ Question:
{
	vector<Answer> answers;

public:
	SinAnsQst();
	SinAnsQst(string qstTxt, vector<string> ansTxts, int rightAns);

	bool answerIsRight() const override;
	int getType() const override { return 1; }
	void showAnswer() const override;
	void print() const override;
	void save(ofstream& write) const override;
	void load(ifstream& read) override;
};

