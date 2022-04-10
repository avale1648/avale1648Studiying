#include "Admin.h"
#include "TestsAndUsersLists.h"

void Admin::menu()
{
	bool exit = false; string input; string empty;

	while (!exit)
	{
		cout << "АДМИНИСТРАТОР: СПИСОК КОМАНД" << endl << endl;

		cout << "УПРАВЛЕНИЕ ТЕСТАМИ" << endl << endl;
		cout << "/testlist - посмотреть список тестов;" << endl;
		cout << "/create <название> - создать новый тест;" << endl;
		cout << "/edit <номер теста> - редактировать тест;" << endl;
		cout << "/del <номер теста> - удалить тест;" << endl << endl;

		cout << "УПРАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯМИ" << endl << endl;
		cout << "/userlist - посмотреть список пользователей;" << endl;
		cout << "/changePassword <номер пользователя> - изменить пароль пользователя;" << endl << endl;

		cout << "/take <номер теста> - пройти тест;" << endl;
		cout << "/exit - выход в главное меню." << endl << endl;

		cin >> input; cout << endl;

		if (input == "/testlist")
		{
			system("cls");
			cout << "СПИСОК ТЕСТОВ" << endl << endl;
			tests.print();
			system("pause"); system("cls");
		}
		else if (input == "/create")
		{
			getline(cin, empty);
			getline(cin, input); cout << endl;
			Test test(input);
			tests.add(test);
			
			cout << "Был создан новый тест - "<<tests[tests.size() - 1].getName() <<". Для его редактирования введите комманду /edit <index>." << endl << endl;
			system("pause"); system("cls");
		}
		else if (input == "/edit")
		{
			int n; cin >> n;
			system("cls");
			tests[n].menu();
			system("cls");
		}
		else if (input == "/del")
		{
			int n; cin >> n;
			tests.del(n);
			cout << "Тест " << tests[n].getName() << " был удален." << endl << endl;
			Sleep(1000); system("cls");
		}
		else if (input == "/userlist")
		{
			system("cls");
			cout << "СПИСОК ПОЛЬЗОВАТЕЛЕЙ" << endl << endl;
			users.print();
			cout << endl;
			system("pause"); system("cls");
		}
		else if (input == "/changePassword")
		{
			int n; cin >> n;
			cout << "Введите новый пароль:" << endl << endl;
			string np; cin >> np; cout << endl;
			users[n]->setPassword(np);
			cout << "Пароль пользователя " << users[n]->getName() << " был изменен." << endl << endl;
			Sleep(1000); system("cls");
		}
		else if (input == "/take")
		{
			int n; cin >> n;
			if (n < 0 or n > tests.size() - 1)
			{
				throw runtime_error("Ошибка: теста с данным номером не существует...");
				abort();
			}
			cout << "Будет запущен тест - " << tests[n].getName() << "." << endl << endl;
			Sleep(1000); system("cls");
			tests[n].take(true);
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
	cout << "Выход в меню входа..." << endl << endl;
	Sleep(1000); system("cls");
}
