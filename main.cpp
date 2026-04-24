
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an interval
struct Interval {
    int l, r;
    Interval(int l, int r) : l(l), r(r) {}
    
    // For set ordering - sort by left endpoint
    bool operator<(const Interval& other) const {
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<Interval> intervals;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            
            // Find all intervals that overlap with [l, r]
            // An interval [a, b] overlaps with [l, r] if max(a, l) <= min(b, r)
            vector<Interval> toRemove;
            
            // Find first interval with left endpoint >= l - (r-l) 
            // This is a conservative estimate to catch all possible overlaps
            auto it = intervals.lower_bound(Interval(l - 100000, 0));
            
            while (it != intervals.end()) {
                int a = it->l, b = it->r;
                // Check if [a,b] overlaps with [l,r]
                if (max(a, l) <= min(b, r)) {
                    toRemove.push_back(*it);
                }
                // If the current interval's left endpoint is already greater than r, 
                // no more intervals can overlap
                if (a > r) break;
                ++it;
            }
            
            // Remove all overlapping intervals
            int count = 0;
            for (const auto& interval : toRemove) {
                intervals.erase(interval);
                count++;
            }
            
            // Add the new interval [l, r]
            intervals.insert(Interval(l, r));
            
            cout << count << '\n';
        } else if (op == 'B') {
            cout << intervals.size() << '\n';
        }
    }
    
    return 0;
}
