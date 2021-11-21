#pragma once
#include <string>
#include "publish.h"

using namespace std;

class romans : public publish
{
private:
	string fio;
	string years;
	string books;
	string bio;
public:
	virtual void data() override;
	virtual void set() override;
	virtual void recover(ifstream& in) override;
	virtual void save(ofstream& out) override;
	romans();
	romans(string k, string c, string t, string h);
	romans(const romans& Romans);
	~romans();
	int exception(string line);
};