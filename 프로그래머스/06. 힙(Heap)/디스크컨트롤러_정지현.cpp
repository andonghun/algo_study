#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0; int time = 0;

    sort(jobs.begin(), jobs.end());
    // 작업시간을 기준으로 오름차순 정렬
    priority_queue<int, vector<vector<int>>, cmp> pq;

    while(1) {
        while (idx < jobs.size()) {
            if (time >= jobs[idx][0]) {
                pq.push(jobs[idx]);
                idx++;
            } else break;
        }

        if (!pq.empty()) {
            vector<int> tmp = pq.top();
            time += tmp[1];
            answer += time - tmp[0];
            pq.pop(); 
        } else time = jobs[idx][0]; 

        if (pq.empty() && idx == jobs.size()) break;
    }

    return answer / jobs.size(); 
}