#include "Test.h"

void Test::add(string option)
{
	bool correctOption = true;
	string input, qstTxt, rightAns; 
	if (option == "single")
	{
		cout << "Введите текст вопроса:" << endl << endl;
		getline(cin, input); qstTxt = input;
		questions.push_back(new SingleAnswerQuestion(qstTxt));
	}
	else if (option == "multi")
	{
		cout << "Введите текст вопроса:" << endl << endl;
		getline(cin, input); qstTxt = input;
		questions.push_back(new MultiAnswerQuestion(qstTxt));
	}
	else if (option == "free")
	{
		cout << "Введите текст вопроса:" << endl << endl;
		getline(cin, input); qstTxt = input;
		cout << endl << "Введите правильный ответ:" << endl << endl;
		getline(cin, input); rightAns = input;
		questions.push_back(new FreeInpQst(qstTxt, rightAns));
	}
	else
	{
		cout << "Ошибка: введено неккоректное значение" << endl;
		correctOption = false;
	}
	if (correctOption)
	{
		system("cls");
		questions[questions.size() - 1]->add();
	}	
}

void Test::print(bool admin) const
{
	cout << name << endl << endl;

	for (int i = 0; i < questions.size(); i++)
	{
		questions[i]->print(); cout << endl;
		if (admin)
		{
			cout << "Правильный ответ: ";
			questions[i]->showAnswer(); cout << endl;
		}
	}
}

void Test::menu()
{
	bool exit = false, custom = false; string input, empty;
	while (!exit)
	{
		cout << "РЕДАКТИРОВАНИЕ ТЕСТА: СПИСОК КОМАНД" << endl << endl;
		cout << "/add <тип> - добавить вопрос типа: "<< endl;
		cout << "single - один вариант, multi - несколько вариантов, free - письменный ответ;" << endl;
		cout << "/del <номер вопроса> - удалить вопрос;" << endl;
		cout << "/print - распечатать тест;" << endl;
		cout << "/exit - завершить редактирование теста." << endl << endl;

		cin >> input; cout << endl;

		if (input == "/add")
		{
			string type; cin >> type;
			getline(cin, empty);
			system("cls");
			add(type);
			system("cls");
		}
		else if (input == "/del")
		{
			int n; cin >> n;
			if (n < 0 or n>questions.size() - 1)
			{
				cout << "Ошибка: вопроса №" << n << " не существует..." << endl << endl;
				abort();
			}
			del(n);
			cout << "Вопрос №" << n << "был удален из теста." << endl << endl;
			Sleep(1000); system("cls");
		}
		else if (input == "/print")
		{
			system("cls");
			print(true);
			system("pause"); system("cls");
		}
		else if (input == "/exit")
		{
			exit = true;
		}
		else
		{
			cout << "Ошибка: введена неизвестная команда..." << endl << endl;
			Sleep(1000); system("cls");
		}
	}
	cout << "Завершение редактирования теста..." << endl << endl;
	Sleep(1000); system("cls");
	return;
}

void Test::save(ofstream& write) const
{
	write << name << '&' << questions.size() << endl;

	for (int i = 0; i < questions.size(); i++)
	{
		write << questions[i]->getType() <<endl;
		questions[i]->save(write);
	}
}

void Test::load(ifstream& read)
{
	Question* qst;
	getline(read, name, '&');
	int n; read >> n;
	for (int i = 0; i < n; i++)
	{
		int type; read >> type;
		string empty; getline(read, empty);
		if (type == 1)
		{
			qst = new SingleAnswerQuestion;
			qst->load(read);
			questions.push_back(qst);
		}
		else if (type == 2)
		{
			qst = new MultiAnswerQuestion;
			qst->load(read);
			questions.push_back(qst);
		}
		else if (type == 3)
		{
			qst = new FreeInpQst;
			qst->load(read);
			questions.push_back(qst);
		}
	}
}

float Test::take(bool admin)
{
	string empty;
	float result = 0;
	float point = 100.0f / questions.size();

	cout << name << endl << endl;

	for (int i = 0; i < questions.size(); i++)
	{
		questions[i]->print();
		if (admin)
		{
			cout << "Правильный ответ: ";
			questions[i]->showAnswer(); cout << endl;
		}
		getline(cin, empty);
		if (questions[i]->answerIsRight())
			result += point; cout << endl;
	}
	cout << "Вы набрали " << result << " балл(ов) за этот тест." << endl;
	return result;
}
