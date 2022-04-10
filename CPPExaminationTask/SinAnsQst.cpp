#include "SinAnsQst.h"

SinAnsQst::SinAnsQst()
	:Question()
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			answers.push_back(Answer("Answer", true));
		else
			answers.push_back(Answer("Answer", false));
	}
}

SinAnsQst::SinAnsQst(string qstTxt, vector<string> ansTxts, int rightAns)
	:Question(qstTxt)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == rightAns)
			answers.push_back(Answer(ansTxts[i], true));
		else
			answers.push_back(Answer(ansTxts[i], false));
	}	
}

bool SinAnsQst::answerIsRight() const
{
	int answer; cin >> answer;

	return answers[answer].isAnswerRight() == true;
}

void SinAnsQst::showAnswer() const
{
	for (int i = 0; i < 4; i++)
	{
		if (answers[i].isAnswerRight())
			cout << i << "." << answers[i].getAnsTxt() << '.' << endl;
	}
}

void SinAnsQst::print() const
{
	Question::print(); cout << "?" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
			cout << i << ". " << answers[i].getAnsTxt() << "." << endl;
		else
			cout << i << ". " << answers[i].getAnsTxt() << ";" << endl;
	}
	cout << endl << "¬ведите один вариант:" << endl;
}

void SinAnsQst::save(ofstream& write) const
{
	write << Question::qstTxt <<' ' << answers.size() << endl;
	for (int i = 0; i < answers.size(); i++)
		answers[i].save(write);
}

void SinAnsQst::load(ifstream& read)
{
	read >> Question::qstTxt;
	int n; read >> n;
	for (int i = 0; i < n; i++)
	{
		Answer answer("a", false); answer.load(read);
		answers.push_back(answer);
	}
}
