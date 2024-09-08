// Test definitions. Do NOT edit this file!
#define CATCH_CONFIG_MAIN // defines main() automatically
#include <iostream>
#include "catch.hpp"
#include "main.hpp"
// tests for exercise 1

TEST_CASE("Ex1 rewritesplitwords() ", "[example]")
{

	string filename = "allstates.txt";
	vector<Name> namerecords;
	string state, name;
	char gen;
	int year, cnt;
	ifstream ifs;
	int count = 0;
	char delimiter = ',';

	namerecords = rewritesplitwords(filename, delimiter);
	REQUIRE(namerecords.size() == 4080);
	cout << "--------------------------------------------------\n";

	ifs.open("split.txt");
	REQUIRE(ifs.is_open());
	while (ifs >> state >> gen >> year >> name >> cnt)
		count += 1;
	REQUIRE(count == 4080);
}

TEST_CASE("Ex2 rewritesplitwords() ", "[example]")
{

	ifstream ifs;
	string state, name;
	char gen;
	int year, cnt;
	int maxINcnt = 0, maxDEcnt = 0;

	ifs.open("split.txt");
	if (!ifs)
		cerr << "File Open Error\n";

	while (ifs >> state >> gen >> year >> name >> cnt)
	{
		// cout << state << "\t" << gen << "\t" << year << "\t" << name << "\t" << cnt << endl;
		if (state == "IN" and year == 2011 and gen == 'F')
		{
			cout << state << "\t" << gen << "\t" << year << "\t" << name << "\t" << cnt << endl;
			if (maxINcnt < cnt)
				maxINcnt = cnt;
		}
		if (state == "DE" and year == 2018 and gen == 'M')
		{
			cout << state << "\t" << gen << "\t" << year << "\t" << name << "\t" << cnt << endl;
			if (maxDEcnt < cnt)
				maxDEcnt = cnt;
		}
	}

	REQUIRE(maxINcnt == 453);
	REQUIRE(maxDEcnt == 63);
	cout << "--------------------------------------------------\n";
}

TEST_CASE("Ex3 MFN() ", "[example]")
{

	vector<Result> result;
	vector<Name> namerecords = rewritesplitwords("allstates.txt", ',');

	result = MFN(namerecords, "IN", 2018);
	cout << "Most frequently used male name and count in IN, 2018: " << result[0].name << " " << result[0].count << endl;
	cout << "--------------------------------------------------\n";
	REQUIRE(result[0].name == "Oliver");
	result = MFN(namerecords, "DE", 2018);
	cout << "Most frequently used male name and count in DE, 2018: " << result[0].name << " " << result[0].count << endl;
	cout << "--------------------------------------------------\n";
	REQUIRE(result[0].name == "Liam");
	cout << "--------------------------------------------------\n";
}
