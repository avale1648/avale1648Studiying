#pragma once
#include "IncludingsAndUsings.h"
#include "Question.h"
#include "Answer.h"

class MltAnsQst : public Question
{
	vector<Answer> answers;

public:
	MltAnsQst();
	MltAnsQst(string qstTxt, vector<string> ansTxts, int rightAns1, int rightAns2);

	bool answerIsRight() const override;
	int getType() const override { return 2; }
	void showAnswer() const override;
	void print() const override;
	void save(ofstream& write) const override;
	void load(ifstream& read) override;
};

