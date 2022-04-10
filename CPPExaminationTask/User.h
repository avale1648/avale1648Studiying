#pragma once
#include "IncludingsAndUsings.h"
#include "Password.h"
class User//абстрактный класс User (пользователь):
{
protected:
	string username;
	Password password;

public:
	User() : username("user"), password("user") { }//конструктор по умолчанию;
	User(string username, string password) : username(username), password(password) { }//конструктор преобразования типов.

	virtual void menu() = 0;//чисто виртуальная функция menu(меню).
	virtual bool compare(string username, string password) { return username == this->username and password == this->password.getPassword(); }

	string getName() { return username; }
	void setPassword(string password) { this->password.setPassword(password); }

	virtual void save(ofstream& write) const = 0;
	virtual void load(ifstream& read) = 0;
};

