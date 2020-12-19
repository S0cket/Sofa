#include <iostream>
using namespace std;

class koordinat;
class matrix
{
private:
	int n, **m;
public:
	matrix() {
		n = 3;
		m = new int* [n];
		for (int i = 0; i < n; i++) {
			m[i] = new int[n];
			for (int j = 0; j < n; j++)
				m[i][j] = i * n + j + 1;
		}
	}
	matrix(int n) {
		this->n = n;
		m = new int* [n];
		for (int i = 0; i < n; i++) {
			m[i] = new int[n];
			for (int j = 0; j < n; j++)
				m[i][j] = i * n + j + 1;
		}
	}
	~matrix() {
		for (int i = 0; i < n; i++) {
			delete[] m[i];
		}
		delete[] m;
	}
	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	friend void    change(matrix& m, koordinat a, koordinat b);
};

class koordinat 
{
private:
	int x, y;
public:
	koordinat() {
		x = 0, y = 0;
	}
	koordinat(int x_, int y_) {
		x = x_;
		y = y_;
	}
	~koordinat() {}
	friend void    change(matrix& m, koordinat a, koordinat b);
};

void change(matrix& m, koordinat a, koordinat b) {
	if ((a.x < m.n && a.x >= 0) && (a.y < m.n && a.y >= 0)) {
		if ((b.x < m.n && b.x >= 0) && (b.y < m.n && b.y >= 0)) {
			int temp = m.m[a.x][a.y];
			m.m[a.x][a.y] = m.m[b.x][b.y];
			m.m[b.x][b.y] = temp;
		}
	}
};

int main()
{
	matrix a;
	koordinat x(0, 0), y(2, 2);
	a.print();
	change(a, x, y);
	a.print();
	return 0;
}