#include "Vector.h"
Vector::Vector(void){
	beg = 0;
	size = 0;
	CurrentPos = 0;
}
Vector::Vector(int N) {
	beg = new Object * [N];
	size = N;
	CurrentPos = 0;
}
Vector::~Vector(void) {
	if (beg != 0) { delete[]beg; }
	beg = 0;
}
void Vector::Add(Object* p) {
	if (CurrentPos < size) {
		beg[CurrentPos] = p;
		CurrentPos++;
	}
}
ostream& operator<<(ostream& out, const Vector& temp)
{
	if (temp.size == 0) { out << "\nÏףסעמ\n"; }
	Object** p = temp.beg;
	for (int i = 0; i < temp.CurrentPos; i++) {
		(*p)->Show();
		p++;
	}
	return out;
}
