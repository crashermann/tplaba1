
#pragma once
#include <string>
#include "publish.h"

using namespace std;

class fantasts : public publish
{
private:
    string fio;
    string books;
    string films;
public:
    virtual void data() override;
    virtual void set() override;
    virtual void recover(ifstream& in) override;
    virtual void save(ofstream& out) override;
    fantasts();
    fantasts(string t, string d, string c);
    fantasts(const fantasts& fur);
    ~fantasts();
    int exception(string line);
};