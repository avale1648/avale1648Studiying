#include "Question.h"
#pragma once
class SingleAnswerQuestion : public Question
{
	vector<string> answers;
	int rightAnswer = 0;

public:
	SingleAnswerQuestion() : Question() { }
	SingleAnswerQuestion(string question) : Question(question) { }
	
	bool answerIsRight() const override;
	int getType() const override { return 1; }
	void add() override;
	void showAnswer() const override { cout << rightAnswer << ". " << answers[rightAnswer] << "." << endl; }
	void print() const override;

	void save(ofstream& write) const override;
	void load(ifstream& read) override;
};

