#include "Admin.h"
#include "TestsAndUsersLists.h"

void Admin::menu()
{
	bool exit = false; string input; string empty;

	while (!exit)
	{
		cout << "�������������: ������ ������" << endl << endl;

		cout << "���������� �������" << endl << endl;
		cout << "/testlist - ���������� ������ ������;" << endl;
		cout << "/create <��������> - ������� ����� ����;" << endl;
		cout << "/edit <����� �����> - ������������� ����;" << endl;
		cout << "/del <����� �����> - ������� ����;" << endl << endl;

		cout << "���������� ��������������" << endl << endl;
		cout << "/userlist - ���������� ������ �������������;" << endl;
		cout << "/changePassword <����� ������������> - �������� ������ ������������;" << endl << endl;

		cout << "/take <����� �����> - ������ ����;" << endl;
		cout << "/exit - ����� � ������� ����." << endl << endl;

		cin >> input; cout << endl;

		if (input == "/testlist")
		{
			system("cls");
			cout << "������ ������" << endl << endl;
			tests.print();
			system("pause"); system("cls");
		}
		else if (input == "/create")
		{
			getline(cin, empty);
			getline(cin, input); cout << endl;
			Test test(input);
			tests.add(test);
			
			cout << "��� ������ ����� ���� - "<<tests[tests.size() - 1].getName() <<". ��� ��� �������������� ������� �������� /edit <index>." << endl << endl;
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
			cout << "���� " << tests[n].getName() << " ��� ������." << endl << endl;
			Sleep(1000); system("cls");
		}
		else if (input == "/userlist")
		{
			system("cls");
			cout << "������ �������������" << endl << endl;
			users.print();
			cout << endl;
			system("pause"); system("cls");
		}
		else if (input == "/changePassword")
		{
			int n; cin >> n;
			cout << "������� ����� ������:" << endl << endl;
			string np; cin >> np; cout << endl;
			users[n]->setPassword(np);
			cout << "������ ������������ " << users[n]->getName() << " ��� �������." << endl << endl;
			Sleep(1000); system("cls");
		}
		else if (input == "/take")
		{
			int n; cin >> n;
			if (n < 0 or n > tests.size() - 1)
			{
				throw runtime_error("������: ����� � ������ ������� �� ����������...");
				abort();
			}
			cout << "����� ������� ���� - " << tests[n].getName() << "." << endl << endl;
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
			cout << "������: ������� ����������� �������..." << endl << endl;
			Sleep(1000); system("cls");
		}
	}
	cout << "����� � ���� �����..." << endl << endl;
	Sleep(1000); system("cls");
}
