

#pragma once
#include <string>
#include "publish.h"

using namespace std;

class poets : public publish
{
private:
	string fio;
	string years;
	string books;
public:
	virtual void data() override;
	virtual void set() override;
	virtual void recover(ifstream& in) override;
	virtual void save(ofstream& out) override;
	poets();
	poets(string fio, string years, string books);
	poets(const poets& poets);
	int exception(string line);
	~poets();
};