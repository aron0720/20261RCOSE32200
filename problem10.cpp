#include <string>
#include <vector>

using namespace std;

struct Server{
    int n;
    int time;
};

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server_num = 0;
    vector<Server> servers;

    for (int t = 0; t < 24; t++) {
        int idx = 0;
        while (idx < servers.size()) {
            servers[idx].time -= 1;
            if (servers[idx].time == 0) {
                server_num -= servers[idx].n;
                servers.erase(servers.begin() + idx);
                idx--;
            }
            idx++;
        }

        int p = players[t] / m;
        if (p > server_num) {
            Server new_server;
            new_server.n = p - server_num;
            new_server.time = k;
            answer += new_server.n;
            servers.push_back(new_server);
            server_num = p;
        }
    }

    return answer;
}