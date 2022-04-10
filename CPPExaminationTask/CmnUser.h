#pragma once
#include "User.h"
#include "Statistics.h"
class CmnUser : public User
{
	float gpa = 0;
	vector<Statistics> statistics;

public:
	CmnUser() : User() { }
	CmnUser(string username, string password) : User(username, password) { }

	void menu() override;
	void save(ofstream& write) const override;
	void load(ifstream& read) override;

	friend class Admin;
};

