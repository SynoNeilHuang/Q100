#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int findExtra(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.empty() || arr2.empty() || abs(arr1.size() - arr2.size()) > 1) return -1
    int start1(0), start2(0), end1(arr1.size()-1), end2(arr2.size()-1);
    while (start1 < end1 && start2 < end2) {
	int mid1 = (start1 + end1+1) / 2;
	int mid2 = (start2 + end2+1) / 2;
	if (mid1 == mid2 && arr1.at(mid1) == arr2.at(mid2)) {
	    start1 = mid1 + 1;
	    start2 = mid2 + 1;
	} else {
	    end1 = mid1 - 1;
	    end2 = mid2 - 1;
	}
    }

    int mid1 = (start1 + end1) / 2;
    int mid2 = (start2 + end2) / 2;
    if (arr1.size() > arr2.size()) {
	if (arr1.at(mid1) == arr2.at(mid2)) {
	    return arr1.at(mid1+1);
	} else {
	    return arr1.at(mid1);
	}
    } else {
	if (arr1.at(mid1) == arr2.at(mid2)) {
	   return arr2.at(mid2+1);
	} else {
	    return arr2.at(mid2);
	}
    }
}

int main() {
    vector<int> input1 = {2, 4, 6, 7, 8, 10, 12};
    vector<int> input2 = {2, 4, 6, 8, 10, 12};
    cout << findExtra(input1, input2) << endl;
    return 0;
}
