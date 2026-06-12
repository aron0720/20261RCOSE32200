#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare_sort(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

struct compare_heap{
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] >= b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), compare_sort);
    int l = size(jobs);
    priority_queue<vector<int>, vector<vector<int>>, compare_heap> heap;
    heap.push(jobs[0]);
    int time = jobs[0][0];
    int idx = 1;
    float answer = 0;

    while (idx < l || !heap.empty()) {
        while (idx < l && jobs[idx][0] <= time) {
            heap.push(jobs[idx]);
            idx++;
        }
        if (heap.empty()) {
            time++;
        } else {
            vector<int> job = heap.top();
            time += job[1];
            answer += time - job[0];
            heap.pop();
        }
    }

    return answer / l;
}