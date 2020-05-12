#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int user[502];
bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 0; i < stages.size(); ++i) {
    	user[stages[i]]++;
    }

    int size = stages.size();
    vector<pair<double, int>> v;

    for (int i = 1; i <= N; ++i) {
    	if (user[i] == 0) {
    		v.push_back({0, i});
   		} else {
   			v.push_back({(double)user[i]/size, i});
    		size -= user[i];
   		}
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; ++i) {
    	answer.push_back(v[i].second);
    }
    
    return answer;
}