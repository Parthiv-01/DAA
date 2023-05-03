#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int maxJobs(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compareIntervals);
    int count = 0;
    int end = INT_MIN;
    for (const auto& interval : intervals) {
        if (interval.start >= end) {
            count++;
            end = interval.end;
        }
    }
    return count;
}

int main() {
    vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {5, 7}, {6, 8}, {8, 10}};
    cout << "Max jobs that can be done: " << maxJobs(intervals) << endl;
    return 0;
}
