#pragma once
#include "IncludingsAndUsings.h"
#include "Question.h"

class FreeInpQst : public Question
{
	string rightAnswer;

public:
	FreeInpQst() : Question(), rightAnswer("Answer") { }
	FreeInpQst(string qstText, string rightAnswer) : Question(qstText), rightAnswer(rightAnswer) { }

	bool answerIsRight() const override;
	int getType() const override { return 3; }
	void add() override { return; }
	void showAnswer() const override;
	void print() const override;
	void save(ofstream& write) const { write << qstTxt << '&' << rightAnswer << '&' << endl; }
	void load(ifstream& read) override;
};

