#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::string;

int checkPalindrome(const string& s, int start, int end) {
    int cnt(0);
    while (start >= 0 && end < s.size()) {
	if (s.at(start) == s.at(end))
	    ++cnt;
	else
	    break;
	--start;
	++end;
    }
    return cnt;
}

int countSubstrings(string s) {
    if (s.empty()) return 0;
    int ret(0);
    for (int i = 0 ; i < s.size() ; ++i) {
	ret += checkPalindrome(s, i, i);
	ret += checkPalindrome(s, i, i+1);
    }
    return ret;
}

int main() {
    string input("fdsklf");
    cout << countSubstrings(input) << endl;
    return 0;
}
