#include "FreeInpQst.h"

bool FreeInpQst::answerIsRight() const
{
	cout << "¬ведите ответ:" << endl << endl;
	string rightAnswer; getline(cin, rightAnswer);

	return rightAnswer == this->rightAnswer;
}

void FreeInpQst::showAnswer() const
{
	cout << rightAnswer << '.' << endl;
}

void FreeInpQst::print() const
{
	Question::print(); cout << endl << endl;
}

void FreeInpQst::load(ifstream& read)
{
	getline(read, qstTxt, '&'); getline(read, rightAnswer, '&');
}
