#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"
/*
void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string word;
		if (!(cin >> word) || word == "q")
			break;
		print(cout, tq.query(word)) << endl;
	}
}
*/
int main()
{
	ifstream infile("storyDataFile");
	if (!infile) {
		cerr << "couldn't open storyDataFile" << endl;
		return -1;
	}
	TextQuery tq(infile);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q.eval(tq) << endl;
	return 0;
}
