#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

void print(deque<int> a) {
	for (int i = 0; i < a.size(); ++ i)
		cout << a[i] << " ";
	cout << endl;
}
void print(list<int> a) {
	for (auto iter = a.begin(); iter != a.end(); ++ iter)
		cout << *iter << " ";
	cout << endl;
}

int main(void) {
	srand(time(NULL));

	//1
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0; i < n; ++ i) {
		int x;
		cin >> x;
		d.push_back(x);
	}
	int mn = d[0];
	for (int i = 1; i < d.size(); ++ i)
		if (abs(d[i]) < abs(mn))
			mn = d[i];
	int s = 0;
	bool flag = false;
	for (int i = 0; i < d.size(); ++ i) {
		if (d[i] == 0)
			flag = true;
		if (flag)
			s += abs(d[i]);
	}
	print(d);
	cout << "min: " << mn << endl << "sum: " << s << endl;

	deque<int> dnew;
	for (int i = 0; i < d.size(); ++ i) {
		if (i % 2 == 0) {
			dnew.push_front(d[i]);
		}
		else {
			dnew.push_back(d[i]);
		}
	}
	print(dnew);


	//2
	set<int> st;
	list<int> l;
	cin >> n;
	for (int i = 0; i < n; ++ i)
		l.push_back(rand() % 10);
	print(l);
	for (auto iter = l.begin(); iter != l.end(); ++ iter)
		if (count(l.begin(), l.end(), *iter) > 1) st.insert(*iter);
	auto end = l.end();
	for (auto iter = st.begin(); iter != st.end(); ++ iter)
		end = remove(l.begin(), end, *iter);
	l.erase(end, l.end());
	print(l);

	return 0;

}