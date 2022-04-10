#include "SingleAnswerQuestion.h"

bool SingleAnswerQuestion::answerIsRight() const
{
	cout << "¬ведите номер ответа:" << endl << endl;
	int rightAnswer; cin >> rightAnswer;
	return rightAnswer == this->rightAnswer;
}

void SingleAnswerQuestion::add()
{
	cout << "¬ведите кол-во вариантов ответа:" << endl << endl;
	int n; cin >> n; string s; getline(cin, s); cout << endl;
	cout << "¬ведите варианты ответа:" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		string answer;
		getline(cin, answer);
		answers.push_back(answer);
	}
	cout << endl;
	cout << "¬ведите номер правильного варианта:" << endl << endl;
	bool correctInput = false;
	while (!correctInput)
	{
		cin >> rightAnswer; 
		rightAnswer < answers.size() - 1 ? correctInput = true: correctInput = false;
	}
	cout << endl;
}

void SingleAnswerQuestion::print() const
{
	Question::print(); cout << endl << endl;

	for (int i = 0; i < answers.size(); i++)
	{
		i == answers.size() - 1 ? cout << i << ". " << answers[i] << "." << endl : cout << i << ". " << answers[i] << ";" << endl;
	}
	cout << endl;
}

void SingleAnswerQuestion::save(ofstream& write) const
{
	write << qstTxt << '&' << answers.size() << '&' << rightAnswer << endl;
	for (int i = 0; i < answers.size(); i++)
		write << answers[i] << endl;
}

void SingleAnswerQuestion::load(ifstream& read)
{
	getline(read, qstTxt, '&'); string nString; getline(read, nString, '&'); string rightAnswerString; getline(read, rightAnswerString);
	int n = stoi(nString); rightAnswer = stoi(rightAnswerString);
	for (int i = 0; i < n; i++)
	{
		string answer;
		getline(read, answer);
		answers.push_back(answer);
	}
}
