#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    int m = cores.size();
    if (n <= m) return n;
    long long low = 0;
    long long high = (long long)cores[0] * n; 
    long long t = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long total_tasks = 0;

        for (int core : cores) {
            total_tasks += (mid / core) + 1;
        }

        if (total_tasks >= n) {
            t = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }

    long long current_tasks = 0;
    for (int core : cores) {
        current_tasks += ((t - 1) / core) + 1;
    }

    for (int i = 0; i < m; i++) {
        if (t % cores[i] == 0) { 
            current_tasks++;
            if (current_tasks == n) {
                return i + 1; 
            }
        }
    }

    return 0;
}