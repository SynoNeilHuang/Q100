#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::min;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<int> costs(n, INT_MAX);
    for (const auto& flight : flights) {
	if (flight.at(0) == src) {
	    costs.at(flight.at(1)) = flight.at(2);
	}
    }
    for (int i = 0 ; i < K ; ++i) {
	vector<int> localCosts(costs);
	for (const auto& flight : flights) {
	    if (localCosts.at(flight.at(0)) != INT_MAX) {
		costs.at(flight.at(1)) = min(costs.at(flight.at(1)), localCosts.at(flight.at(0)) + flight.at(2));
	    }
	}
    }
    return costs.at(dst) == INT_MAX ? -1 : costs.at(dst);
}

int main() {
    return 0;
}
