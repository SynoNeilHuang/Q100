#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::min;

// dp.at(i).at(j) : min number of delete in size i of word1 and size j of word2
// Suppose Z is lastest string after delete
// split word1 and word2 to word1 = word1(i-1) + e1 and word2 = word2(j-1) + e2
// if Z include e1 and e2 (it also means e1 == e2)
// dp.at(i).at(j) = dp.at(i-1).at(j-1) if (e1 == e2)
// if Z not include e1 but include e2
// dp.at(i).at(j) = dp.at(i-1).at(j) + 1 if (e1 != e2)
// if Z include e1 but not include e2
// dp.at(i).at(j) = dp.at(i).at(j-1) + 1 if (e1 != e2)
// if Z not include e1 and e2 is be include up two case
//
// dp.at(i).at(j) = dp.at(i-1).at(i-1) if (e1 == e2)
//                = min(dp.at(i-1).at(j) + 1, dp.at(i).at(j-1) + 1) if (e1 != e2)
// if (i = 0 && j == 0) dp.at(i).at(j) = 0;
// else if (i == 0) dp.at(i).at(j) = j
// else if (j == 0) dp.at(i).at(j) = i

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1 ,vector<int>(n+1, 0));

    for (int i = 0 ; i <= m ; ++i) {
	for (int j = 0 ; j <= n ; ++j) {
	    if (i == 0 && j == 0) dp.at(i).at(j) = 0;
	    if (i == 0) {
		dp.at(i).at(j) = j;
	    } else if (j == 0) {
		dp.at(i).at(j) = i;
	    } else {
		if (word1.at(i-1) == word2.at(j-1)) {
		    dp.at(i).at(j) = dp.at(i-1).at(j-1);
		} else {
		    dp.at(i).at(j) = min(dp.at(i-1).at(j) + 1, dp.at(i).at(j-1) + 1);
		}
	    }
	}
    }
    return dp.at(m).at(n);
}

int main() {
    string word1("eat");
    string word2("sea");
    cout << minDistance(word1, word2) << endl;
    return 0;
}
