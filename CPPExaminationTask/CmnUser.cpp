#include "CmnUser.h"
#include "TestsAndUsersLists.h"

void CmnUser::menu()
{
	bool exit = false; string input;
	while (!exit)
	{
		cout << "������������: ������ ������" << endl << endl;
		cout << "/testlist - ���������� ������ ������;" << endl;
		cout << "/take <����� �����> - ������ ����;" << endl;
		cout << "/stat - ���������� ���������� �� ���������� ������;" << endl;
		cout << "/exit - �����." << endl << endl;

		cin >> input;

		if (input == "/testlist")
		{
			system("cls");
			cout << "������ ������" << endl << endl;
			tests.print();
			system("pause"); system("cls");
		}
		else if (input == "/take")
		{
			int n; cin >> n;
			cout << "����� ������� ���� - " << tests[n].getName() << "." << endl << endl;
			Sleep(1000); system("cls");
			float result = tests[n].take(false);
			gpa == 0 ? gpa += result : gpa = (gpa + result) / 2;
			statistics.push_back(Statistics(tests[n].getName(), result));
			system("pause"); system("cls");
		}
		else if (input == "/stat")
		{
			cout << "��� ������� ���� - " << gpa << endl << endl;
			cout << "���������� �� ������ ���������� ������" << endl << endl;
			for (int i = 0; i < statistics.size(); i++)
			{
				statistics[i].print();
			}
			cout << endl;
			system("pause"); system("cls");
		}
		else if (input == "/exit")
		{
			exit = true;
		}
		else
		{
			cout << "������: ������� ����������� �������..." << endl << endl;
			Sleep(1500); system("cls");
		}
	}
	cout << "����� � ������� ����..." << endl << endl;
	Sleep(1500); system("cls");
}

void CmnUser::save(ofstream& write) const
{
	write << username << '&' << password.encrypt() << '&' << statistics.size() << endl;
	write << gpa << endl;
	for (int i = 0; i < statistics.size(); i++)
		statistics[i].save(write);
	write << endl;
}

void CmnUser::load(ifstream& read)
{
	
	getline(read, username, '&'); string pw; getline(read, pw, '&');
	password.setPassword(pw); password.decrypt();
	string nString; getline(read, nString); int n = stoi(nString);
	string gpaString; getline(read, gpaString); gpa = stoi(gpaString);
	 
	for (int i = 0; i < n; i++)
	{
		Statistics s; s.load(read);
		statistics.push_back(s);
	}
}
