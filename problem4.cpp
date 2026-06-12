#include <string>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> computers, int n, vector<bool>& visited, int x) {
    if (visited[x]) return 1;
    visited[x] = 1;
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (!computers[x][i]) continue;
        res |= dfs(computers, n, visited, i);
    }

    return res;
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, 0);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        answer += dfs(computers, n, visited, i);
    }
    return answer;
}