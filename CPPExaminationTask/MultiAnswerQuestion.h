#pragma once
#include "Question.h"
#include "Answer.h"
class MultiAnswerQuestion : public Question
{
	vector<Answer> answers;

public:
	MultiAnswerQuestion() : Question() { }
	MultiAnswerQuestion(string question) : Question(question) { }
	bool answerIsRight() const override;
	int getType() const override { return 2; }
	void add() override;
	void showAnswer() const override;
	void print() const override;

	void save(ofstream& write) const override;
	void load(ifstream& read) override;
};

