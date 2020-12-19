#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

template<class T>
class Vector {
private:
	vector<T> elems;
public:
	Vector() {}
	Vector(unsigned size) {
		elems = vector<T>(size);
	}
	Vector(unsigned size, T value) {
		elems = vector<T>(size, value);
	}
	Vector(vector<T> elems) {
		this->elems = elems;
	}

	vector<T> getvector() {
		return elems;
	}
	T& operator[](unsigned index) {
		if (index >= elems.size()) {
			cout << "Index Error!\n";
			exit(1);
		}
		return *(elems.begin() + index);
	}
	unsigned operator()() {
		return elems.size();
	}
	void operator()(unsigned size) {
		elems.resize(size);
	}
	Vector operator*(int n) {
		vector<T> ret = elems;
		for (int i = 0; i < ret.size(); ++ i)
			ret[i] *= n;
		return Vector(ret);
	}

	~Vector() {}
};

class Time {
private:
	int min, sec;
public:
	Time() {
		this->min = 0;
		this->sec = 0;
	}
	Time(int sec) {
		this->min = sec / 60;
		this->sec = sec % 60;
	}
	Time(int min, int sec) {
		this->min = min + sec / 60;
		this->sec = sec % 60;
	}

	int get_min() {
		return this->min;
	}
	int get_sec() {
		return this->sec;
	}
	long long get() {
		return this->min * 60 + this->sec;
	}
	void set() {
		this->min = 0;
		this->sec = 0;
	}
	void set(int sec) {
		this->min = sec / 60;
		this->sec = sec % 60;
	}
	void set(int min, int sec) {
		this->min = min + sec / 60;
		this->sec = sec % 60;
	}
	void print() {
		cout << min << ":" << sec << endl;
	}

	~Time() {}
};

void print(Vector<Time> v) {
	for (int i = 0; i < v(); ++ i)
		v[i].print();
	cout << endl;
}

int main(void) {
	Vector<Time> a(3);
	print(a);
	a[0].set(123);
	print(a);
	return 0;
}