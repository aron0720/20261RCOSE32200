#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    vector<string> cache;
    int answer = 0;
    if (cacheSize == 0) return cities.size() * 5;

    for (string city: cities) {
        for (int i = 0; i < city.length(); i++) city[i] = tolower(city[i]);

        auto t = find(cache.begin(), cache.end(), city);
        if (t != cache.end()) {
            answer += 1;
            cache.erase(t);
            cache.push_back(city);
        } else {
            answer += 5;
            if (cache.size() >= cacheSize) cache.erase(cache.begin());
            cache.push_back(city);
        }
    }

    return answer;
}