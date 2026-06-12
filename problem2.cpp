#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Metadata {
    string h;
    int n;
};

bool compare(string a, string b) {
    vector<Metadata> metadata(2);
    string strs[2] = {a, b};

    for (int idx = 0; idx < 2; idx++) {
        string s = strs[idx];
        int l = s.size();
        
        int num_start = -1;
        int num_end = -1;

        for (int i = 0; i < l; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (num_start == -1) num_start = i;
                num_end = i;
            } else {
                if (num_start != -1) break;
            }
        }

        string head = s.substr(0, num_start);
        transform(head.begin(), head.end(), head.begin(), ::toupper);
        metadata[idx].h = head;
        metadata[idx].n = stoi(s.substr(num_start, num_end - num_start + 1));
    }

    if (metadata[0].h != metadata[1].h) return metadata[0].h < metadata[1].h;
    if (metadata[0].n != metadata[1].n) return metadata[0].n < metadata[1].n;
    return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}