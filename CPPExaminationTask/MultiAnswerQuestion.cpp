#include "MultiAnswerQuestion.h"

bool MultiAnswerQuestion::answerIsRight() const
{
	vector<bool> areRight;
	cout << "ќбозначьте истинность вариантов (1 - истина, 0 - ложь):" << endl << endl;
	for (int i = 0; i < answers.size(); i++)
	{
		bool isRight; cin >> isRight;
		areRight.push_back(isRight);

		if (areRight[i] != answers[i].answerIsRight())
			return false;
	}
	return true;
}

void MultiAnswerQuestion::add()
{
	cout << "¬ведите количество вариантов ответа: " << endl << endl;
	int n; cin >> n; cout << endl;
	cout << "¬ведите варианты ответа:" << endl << endl;
	string empty; getline(cin, empty); cout << endl;
	for (int i = 0; i < n; i++)
	{
		string answer; getline(cin, answer); 
		answers.push_back(Answer(answer, 0));
	}
	cout << endl;
	cout << "ќбозначьте истинность вариантов (1 - истина, 0 - ложь):" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		bool isRight; cin >> isRight;
		answers[i].setBool(isRight);
	}
	cout << endl;
}

void MultiAnswerQuestion::showAnswer() const
{
	for (int i = 0; i < answers.size(); i++)
	{
		i == answers.size() - 1 ? (answers[i].answerIsRight() ? cout << i << ". - истина." : cout << i << ". - ложь.") :
			(answers[i].answerIsRight() ? cout << i << ". - истина, " : cout << i << ". - ложь, ");
	}
	cout << endl;
}

void MultiAnswerQuestion::print() const
{
	Question::print(); cout << endl << endl;

	for (int i = 0; i < answers.size(); i++)
	{
		i == answers.size() - 1 ? cout << i << ". " << answers[i].getAnsTxt() << "." << endl : cout << i << ". " << answers[i].getAnsTxt() << ";" << endl;
	}
	cout << endl;
}

void MultiAnswerQuestion::save(ofstream& write) const
{
	write << qstTxt << '&' << answers.size() << endl;
	for (int i = 0; i < answers.size(); i++)
		write << answers[i].getAnsTxt() << '&' << answers[i].answerIsRight() << endl;
}

void MultiAnswerQuestion::load(ifstream& read)
{
	getline(read, qstTxt, '&'); int n; read >> n;
	string empty; getline(read, empty);
	for (int i = 0; i < n; i++)
	{
		string answer; getline(read, answer, '&');
		bool isRight; read >> isRight;
		getline(read, empty);
		answers.push_back(Answer(answer, isRight));
	}
}
