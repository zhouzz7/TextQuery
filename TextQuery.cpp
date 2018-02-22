#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
void trans(string &s)
{
	string word;
	for (auto iter = s.begin(); iter != s.end(); ++iter) {
		if (!ispunct(*iter))
			word += tolower(*iter);
	}
	s = word;
}
TextQuery::TextQuery(ifstream &infile): file(new vector<string>)
{
	string line;
	while (getline(infile, line)) {
		file->push_back(line);
		line_no n = file->size() - 1;
		istringstream in_l(line);
		string word;
		while (in_l >> word) {
			trans(word);
			auto &ret = lines[word];
			if (!ret)
				ret.reset(new set<line_no>);
			ret->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &s) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto ret = lines.find(s);
	if (ret == lines.end())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, ret->second, file);
}
