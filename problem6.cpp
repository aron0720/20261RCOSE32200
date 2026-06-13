#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    for (vector<int> l: edge) {
        graph[l[0]].push_back(l[1]);
        graph[l[1]].push_back(l[0]);
    }
    vector<int> dis(n + 1, -1);
    deque<int> q;
    q.push_back(1);
    dis[1] = 0;

    while (!q.empty()) {
        int c = q.front();
        q.pop_front();
        for (int i: graph[c]) {
            if (dis[i] == -1) {
                dis[i] = dis[c] + 1;
                q.push_back(i);
            }
        }
    }
    
    int max_dis = *max_element(dis.begin(), dis.end());
    return count(dis.begin(), dis.end(), max_dis);
}