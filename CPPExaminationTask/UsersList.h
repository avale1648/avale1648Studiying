#pragma once
#include "Admin.h"
#include "CmnUser.h"

class UsersList
{
	vector<User*> users;

public:
	UsersList();

	void add(string username, string password);
	void login(string username, string password);
	void del(int n) { users.erase(users.begin() + n); }
	
	void print() const;
	void save() const;
	void load();
	
	int size() { return users.size(); }
	
	User*& operator[] (int index);
};

