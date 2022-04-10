#include "Statistics.h"

void Statistics::load(ifstream& read)
{
	getline(read, name, '&');
	string pointString; getline(read, pointString);
	point = stoi(pointString);
}
