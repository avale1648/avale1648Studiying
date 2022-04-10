#include "TestsAndUsersLists.h"

void main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	bool exit = false; string input;

	users.load(); 
	tests.load();

	while (!exit)
	{
		cout << "ВХОД: СПИСОК КОМАНД" << endl << endl;
		cout << "/login <имя пользователя> <пароль>  - вход в существующую запись;" << endl;
		cout << "/signin <имя пользователя> <пароль> - создание новой учетной записи;" << endl;
		cout << "/exit - выход из программы." << endl << endl;

		cin >> input; cout << endl;

		if (input == "/login")
		{
			string name, password;
			cin >> name >> password;
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i]->compare(name, password))
				{
					system("cls"); 
					users[i]->menu();
				}
				else
					cout << "Ошибка: неверный логин или пароль..." << endl << endl;
			}
			Sleep(1000); system("cls");
		}
		else if (input == "/signin")
		{
			string name, password;
			cin >> name >> password;
			users.add(name, password);
			cout << "Зарегистрирован новый пользователь - " << name << "." << endl << endl;
			Sleep(1000); system("cls");
		}
		else if (input == "/exit")
		{
			exit = true;
		}
		else
		{
			cout << "Ошибка: введена неизвестная команда..." << endl << endl;
			Sleep(1500); system("cls");
		}
	}

	cout << "Выход из программы..." << endl << endl;

	users.save(); tests.save();

	 system("pause");
}