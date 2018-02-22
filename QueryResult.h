#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include "TextQuery.h"
class QueryResult {
	friend ostream &print(ostream &, const QueryResult &);
	friend ostream &operator<<(ostream &, const QueryResult &);
public:
	typedef vector<string>::size_type line_no;
	QueryResult(const string &s, 
		shared_ptr<set<line_no>> l,
		shared_ptr<vector<string>> f):
		sought(s), lines(l), file(f)  { }
	set<line_no>::const_iterator begin() const
	{
		return lines->cbegin();
	}
	set<line_no>::const_iterator end() const
	{
		return lines->cend();
	}
	shared_ptr<vector<string>> get_file() const
	{
		return file;
	}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

#endif
#pragma once
