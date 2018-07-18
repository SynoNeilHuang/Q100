#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::pair;

void open(int curLock, int curStep, vector<int>& flag, queue<pair<int, int>>& que) {
    for (int i = 0 ; i < 4 ; ++i) {
	int unit = pow(10, i);
	int mod = pow(10, i+1);
	int plus = (((curLock % mod) + unit) % mod) + ((curLock / mod) * mod);
	int minus = (((curLock % mod) + unit * 9) % mod) + ((curLock / mod) * mod);
	if (flag.at(plus) == 0) {
	    que.emplace(plus, curStep+1);
	    flag.at(plus) = 1;
	}
	if (flag.at(minus) == 0) {
	    que.emplace(minus, curStep+1);
	    flag.at(minus) = 1;
	}
    }
}

int openLock(vector<string>& deadends, string target) {
    vector<int> flag(10000, 0);
    for (const auto& deadend : deadends) {
	flag.at(stoi(deadend)) = -1;
    }

    queue<pair<int, int>> que;
    que.emplace(stoi(target), 0);
    while (!que.empty()) {
	int curLock = que.front().first;
	int curStep = que.front().second;
	que.pop();
	if (0 == curLock) {
	    return curStep;
	} else {
	    open(curLock, curStep, flag, que);
	}
    }
    return -1;

}

int main() {
    vector<string> deadend = {"0201","0101","0102","1212","2002"};
    cout << openLock(deadend, "0202") << endl;
}
