#include "TestsList.h"

TestsList::TestsList()
{
	Test test;

	tests.push_back(test);
}

void TestsList::print() const
{
		for (int i = 1; i < tests.size(); i++)
			cout << i << ". " << tests[i].getName() << endl;
}

void TestsList::save() const
{
	ofstream testlist(".\\save\\tests\\testList.txt");
	if (!testlist)
	{
		cout << "Ошибка: не удалось открыть testlist.txt для записи..." << endl << endl;
	}
	testlist << tests.size() << endl;
	
	for (int i = 1; i < tests.size(); i++)//начиная с 1, потому что в tests[0] записан экспериментальный тест.
	{
		testlist << i << ".txt" << endl;
		ofstream write(".\\save\\tests\\" + to_string(i) + ".txt");
		if (!write)
		{
			cout << "Ошибка: не удалось открыть "<<i<<".txt для записи..." << endl << endl;
		}
		tests[i].save(write);
		write.close();
	}
	testlist.close();
}

void TestsList::load()
{
	ifstream testlist(".\\save\\tests\\testList.txt");
	if(!testlist)
		cout << "Ошибка: не удалось прочитать testList.txt..." << endl << endl;
	
	int n; testlist >> n;
	testlist.close();
	string empty; getline(testlist, empty);
	for (int i = 1; i < n; i++)
	{
		ifstream read(".\\save\\tests\\" + to_string(i) + ".txt");
		if (!read)
		{
			cout << "Ошибка: не удалось прочитать " << i << ".txt..." << endl << endl;
		}
		Test test("Тест"); test.load(read);
		tests.push_back(test);
		read.close();
	}
}

Test& TestsList::operator[](int index)
{
	if (index < 0 or index>tests.size())
	{
		cout << "Ошибка: теста с индексом " << index << " не существует..." << endl << endl;
		abort();
	}
	return tests[index];
}
