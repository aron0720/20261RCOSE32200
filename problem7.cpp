#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> v(n, -1);
    sort(costs.begin(), costs.end(), compare);

    for (vector<int> cost: costs) {
        int s = cost[0], e = cost[1], c = cost[2];
        if (v[s] == -1 && v[e] == -1) {
            answer += c;
            v[s] = s;
            v[e] = s;
            continue;
        } 
        if (v[s] == -1) {
            answer += c;
            v[s] = v[e];
            continue;
        }
        if (v[e] == -1) {
            answer += c;
            v[e] = v[s];
            continue;
        }
        if (v[s] == v[e]) continue;
        int t = v[e];
        for (int i = 0; i < n; i++) {
            if (v[i] == t) v[i] = v[s];
        }
        answer += c;
    }

    return answer;
}