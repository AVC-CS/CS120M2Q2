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
    vector<Name> namerecords;
    // Code your function here
    /*
     * This function reads a file and splits the words into a vector of Name structs.
     * The function returns the vector of Name structs.
     */
    return namerecords;
}

vector<Result> MFN(vector<Name> namerecords, string stname, int thisyear)
{
    vector<Result> MFNames(2);
    // Code your function here
    /*
     * This function finds the most frequently used male name and count in a given state and year.
     * The function returns the vector of Result structs.
     */
    return MFNames;
}