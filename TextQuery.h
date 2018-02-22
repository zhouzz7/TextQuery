#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <memory>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> lines;
};

#endif
