#pragma once
#include "IncludingsAndUsings.h"
class Password
{
	string password;

public:
	Password() : password("user") { }
	Password(string password) : password(password) { }

	string encrypt() const;
	void decrypt();

	string getPassword() const { return password; }
	void setPassword(string password) { this->password = password; }
};

