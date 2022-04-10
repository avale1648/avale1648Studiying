#include "MltAnsQst.h"

MltAnsQst::MltAnsQst()
	:Question()
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 0 or i == 1)
			answers.push_back(Answer("Answer", true));
		else
			answers.push_back(Answer("Answer", false));
	}
}

MltAnsQst::MltAnsQst(string qstTxt, vector<string> ansTxts, int rightAns1, int rightAns2)
	:Question(qstTxt)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == rightAns1 or i == rightAns2)
			answers.push_back(Answer(ansTxts[i], true));
		else
			answers.push_back(Answer(ansTxts[i], false));
	}
}

bool MltAnsQst::answerIsRight() const
{
	int answer1, answer2;
	cin >> answer1 >> answer2;
	return answers[answer1].isAnswerRight() == true and answers[answer2].isAnswerRight() == true;
}

void MltAnsQst::showAnswer() const
{
	for (int i = 0; i < 4; i++)
	{
		if (answers[i].isAnswerRight())
			cout << i << "." << answers[i].getAnsTxt() << ' ';
	}
	cout << '.' << endl;
}

void MltAnsQst::print() const
{
	Question::print(); cout << "?" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 3)
			cout << i << ". " << answers[i].getAnsTxt() << "." << endl;
		else
			cout << i << ". " << answers[i].getAnsTxt() << ";" << endl;
	}
	cout << endl << "¬ведите два варианта:" << endl;
}

void MltAnsQst::save(ofstream& write) const
{
	write << Question::qstTxt << ' ' << answers.size() << endl;
	for (int i = 0; i < answers.size(); i++)
		answers[i].save(write);
}

void MltAnsQst::load(ifstream& read)
{
	read >> Question::qstTxt;
	int n; read >> n;
	for (int i = 0; i < n; i++)
	{
		Answer answer; answer.load(read);
		answers.push_back(answer);
	}
}
