#include "element.h"

publish* element::get_obj() { return obj; }

element* element::get_prev() { return prev; }

void element::set_obj(publish* Obj) { obj = Obj; }

void element::set_prev(element* Prev) { prev = Prev; }
