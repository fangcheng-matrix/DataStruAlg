#include <iostream>
#include <string>
using namespace std;

int match(string& S, string& T) {
	int i = 0, j = 0;
	while (i < S.size() && j < T.size()) {
		if (S[i] == T[j]) {
			++i, ++j;
		}
		else {
			i -= j - 1;
			j = 0;
		}
	}
	if (j >= T.size())
		return i - T.size() + 1;
	else
		return 0;
}

int main() {
	string S, T;
	char chars1[] = "abcabcaccacbab";
	char chars2[] = "abcac";
	S.assign(chars1);
	T.assign(chars2);
	int pos = match(S, T);
	cout << "主串S=" << chars1 << endl;
	cout << "子串T=" << chars2 << endl;
	if (pos) {
		cout << "在第" << pos << "个位置开始匹配！\n";
	}
	else {
		cout << "匹配不成功...\n";
	}
}