#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
class edge{
public:
    int from;
    int to;
    int value;
    edge(int f, int t, int v) : from(f) , to(t), value(v){}
};
class cmp{
public:
    bool operator()(edge e1, edge e2){
        return e1.value>e2.value;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int map[101][101];
    bool visit[101];
    int min_from;
    int min_to;
    int min_value = 987654321;
    for (int i = 0; i < costs.size(); i++) {
        map[costs[i][0]][costs[i][1]] = costs[i][2];
        map[costs[i][1]][costs[i][0]] = costs[i][2];
        if (min_value > costs[i][2]) {
            min_value = costs[i][2];
            min_from = costs[i][0];
            min_to = costs[i][1];
        }
    }
    priority_queue<edge, vector<edge>, cmp> pq;
    for(int i=0;i<n;i++){
        if(map[min_from][i]!=0){
            pq.push(edge(min_from,i,map[min_from][i]));
        }
        if(map[min_to][i]!=0){
            pq.push(edge(min_to,i,map[min_to][i]));
        }
    }
    visit[min_from] = true;
    visit[min_to] = true;
    answer += min_value;
    int cnt = 2;
    while (!pq.empty()) {
        int f = pq.top().from;
        int t = pq.top().to;
        int v = pq.top().value;
        pq.pop();
        if (visit[t] && visit[f])
            continue;
        answer += v;
        if (!visit[t]) {
            for (int i = 0; i < n; i++) {
                if (map[t][i] != 0&&!visit[i]) {
                    pq.push(edge(t, i, map[t][i]));
                }
            }
            visit[t] = true;
            cnt++;
        }
        if (!visit[f]) {
            for (int i = 0; i < n; i++) {
                if (map[f][i] != 0&&!visit[i]) {
                    pq.push(edge(f, i, map[f][i]));
                }
            }
            visit[f] = true;
            cnt++;
        }
        if(cnt==n)
            break;
    }
    return answer;
}
