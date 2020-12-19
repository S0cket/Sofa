#include <iostream>
#include <vector>
#include <algorithm>
#include <stdarg.h>

using namespace std;

class mnoj {
public:
	vector<int> m;
	unsigned int maxsize;

	mnoj() {
		maxsize = 100;
	}
	mnoj(unsigned int n, ...) {
		va_list args;
		va_start(args, n);
		for (int i = 0; i < n; ++ i) {
			int el = va_arg(args, int);
			if (count(m.begin(), m.end(), el) == 0)
				m.push_back(el);
		}
		va_end(args);
		sort(m.begin(), m.end());
		maxsize = m.size();
	}
	mnoj(vector<int> vect) {
		m = vect;
		sort(m.begin(), m.end());
		m.resize(unique(m.begin(), m.end()) - m.begin());
		maxsize = m.size();
	}

	unsigned int operator()() {
		return maxsize;
	}
	void operator()(unsigned int a) {
		if (a < m.size()) throw 0;
		maxsize = a;
	}

	void operator+(int el) {
		if (m.size() == maxsize) throw 1;
		auto iter = upper_bound(m.begin(), m.end(), el);
		m.insert(iter, el);
	}
	int operator[](unsigned int index) {
		if (index >= m.size()) throw 2;
		return m[index];
	}
	mnoj operator-(mnoj M) {
		vector<int> out = m;
		for (int i = 0; i < out.size(); ++ i) {
			if (binary_search(M.m.begin(), M.m.end(), out[i])) {
				out.erase(out.begin() + i);
				-- i;
			}
		}
		return mnoj(out);
	}
	void operator--() {
		if (m.size() == 0) throw 3;
		m.erase(m.begin());
	}
	void operator--(int) {
		if (m.size() == 0) throw 3;
		m.erase(--m.end());
	}

	void print() {
		for (int i = 0; i < m.size(); ++ i)
			cout << m[i] << " ";
		cout << endl;
	}

	~mnoj() {}

};

int main(void) {
	try {
		mnoj a(5, 3, 2, 1, 2, 5), b(4, 1, 2, 4, 1);
		a.print();
		b.print();
		mnoj c = a - b;
		c.print();
		c + 7; // Ошибка
		c(100);
		c + 7;
		c.print();
		--c;
		c.print();
		c--;
		c.print();

	}
	catch (int) {
		cout << "ERROR!!!!!" << endl;
	}
	return 0;
}