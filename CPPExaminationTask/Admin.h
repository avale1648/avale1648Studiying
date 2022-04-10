#pragma once
#include "User.h"

class Admin : public User
{
public:
	Admin():User("admin", "admin") { }
	void menu() override;
	
	void save(ofstream& write) const { return; }
	void load(ifstream& read) { return; }
};

