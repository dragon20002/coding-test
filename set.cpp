#include <iostream>
#include <set>
#include <string>
using namespace std;

struct compare {
	bool operator() (const string& a, const string& b) const {
		int alen = a.length(), blen = b.length();
		if (alen != blen) return alen < blen;
		return a < b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	set<string, compare> words;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words.insert(word);
	}

	set<string, compare>::iterator iter;
	for (iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << '\n';
}
