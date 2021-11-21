#pragma once
#include "publish.h"

class element
{
private:
	publish* obj;
	element* prev;
public:
	publish* get_obj();
	element* get_prev();
	void set_obj(publish* Obj);
	void set_prev(element* Prev);
};