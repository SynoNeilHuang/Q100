#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

void delChar(string& s1, string& s2) {
	if (s1.empty() || s1.empty()) {
		return;
	}
	unordered_map<int, bool> del_map;
	for (const auto& idx : s2) {
		del_map[(int)idx] = true;
	}
	size_t ret_idx = 0;
	size_t iter = 0;

	for(; s1[iter] != '\0' ; ++iter) {
		if (!del_map[static_cast<int>(s1[iter])]) {
			if (iter != ret_idx) {
				s1[ret_idx] = s1[iter];
			}
			++ret_idx;
		}
	}
	s1.resize(ret_idx);
}

int main() {
	string s1("They are students");
	string s2("aeiou");

	delChar(s1, s2);
	cout << s1 << endl;
	return 0;
}
