#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Name
{
	string stname;
	string gender;
	int year;
	string name;
	int count;
};
struct Result
{
	string name;
	int count;
};

vector<Name> rewritesplitwords(string filename, char delimiter);
vector<Result> MFN(vector<Name> namerecords, string stname, int thisyear);

vector<Name> rewritesplitwords(string filename, char delimiter)
{
	ifstream ifs;
	ofstream ofs;
	string line;
	int start, found;
	int cnt = 0;
	int fcnt = 0;
	vector<Name> namerecords;
	Name name;
	string buf;

	ifs.open(filename);
	if (!ifs)
		cerr << "File open Error\n";
	ofs.open("split.txt");
	if (!ofs)
		cerr << "File open Error\n";

	while (ifs >> line)
	{
		start = 0;
		fcnt = 0;
		while ((found = line.find(delimiter, start)) != string::npos)
		{
			buf = line.substr(start, found - start);
			switch (fcnt)
			{
			case 0:
				name.stname = buf;
				break;
			case 1:
				name.gender = buf;
				break;
			case 2:
				name.year = stoi(buf);
				break;
			case 3:
				name.name = buf;
				break;
			default:
				break;
			}
			start = found + 1;
			fcnt += 1;
		}
		name.count = stoi(line.substr(start, line.size() - start));
		ofs << name.stname << "\t" << name.gender << "\t" << name.year << "\t" << name.name << "\t" << name.count << endl;
		namerecords.push_back(name);
		cnt += 1;
	}
	ofs.close();
	ifs.close();
	return namerecords;
}

vector<Result> MFN(vector<Name> namerecords, string stname, int thisyear)
{
	vector<Result> MFNames(2);
	char gen;
	int year, cnt;
	int maxcntM = 0, maxcntF = 0;
	Name name;
	for (auto name : namerecords)
	{
		if ((name.stname == stname) and (name.year == thisyear) and (name.gender == "M") and (maxcntM < name.count))
		{
			maxcntM = name.count;
			MFNames[0] = {name.name, name.count};
		}
		if ((name.stname == stname) and (name.year == thisyear) and (name.gender == "F") and (maxcntF < name.count))
		{
			maxcntF = name.count;
			MFNames[1] = {name.name, name.count};
		}
	}
	ifs.close();
	return MFNames;
}