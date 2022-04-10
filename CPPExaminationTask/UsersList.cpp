#include "UsersList.h"

UsersList::UsersList()
{
	User* admin = new Admin;
	users.push_back(admin);
}

void UsersList::add(string username, string password)
{
	User* user = new CmnUser(username, password);
	users.push_back(user);
}

void UsersList::login(string username, string password)
{
	bool found = false;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->compare(username, password))
		{
			system("cls"); users[i]->menu(); found = true;
		}
		found ? cout << " " << endl << endl: cout << "Ошибка: неверный логин или пароль..." << endl << endl;
		Sleep(1000); system("cls");
	}
}

void UsersList::print() const
{
	for (int i = 1; i < users.size(); i++)
		cout << i << ". " <<users[i]->getName() << endl;
}

void UsersList::save() const
{
	ofstream write(".\\save\\users.txt");
	if (!write)
	{
		cout << "Ошибка: не удалось открыть файл users.txt для записи..." << endl << endl;
		return;
	}
	write << users.size() << endl;
	for (int i = 1; i < users.size(); i++)
		users[i]->save(write);
	write.close();
}

void UsersList::load()
{
	ifstream read(".\\save\\users.txt");
	if (!read)
	{
		cout << "Ошибка: не удалось прочитать файл users.txt..." << endl << endl;
		return;
	}
	int n; read >> n;
	string empty; getline(read, empty);
	for (int i = 1; i < n; i++)
	{
		User* u = new CmnUser();
		u->load(read);
		users.push_back(u);
	}
	read.close();
}

User*& UsersList::operator[](int index)
{
	if (index < 0 or index>users.size())
	{
		cout << "Ошибка: пользователя с индексом " << index << " не существует..." << endl << endl;
		abort();
	}
	return users[index];
}
