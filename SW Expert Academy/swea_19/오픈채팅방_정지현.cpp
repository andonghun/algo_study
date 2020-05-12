#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;

    stringstream ss;
    string cmd, id, nickname;

    vector<pair<string, string>> info;

    for (int i = 0; i < record.size(); ++i) {
    	ss.str(record[i]);
    	ss >> cmd;
    	if (cmd == "Enter") {
    		ss >> id;
    		ss >> nickname;

    		m[id] = nickname;
    		info.push_back({id, "님이 들어왔습니다."});
    	} else if (cmd == "Leave") {
    		ss >> id;
    		info.push_back({id, "님이 나갔습니다."});
    	} else {
    		ss >> id;
    		ss >> nickname;

    		m[id] = nickname;
    	}
    	ss.clear();
    }

    for (int i = 0; i < info.size(); ++i) {
    	string msg = m[info[i].first] + info[i].second;
    	answer.push_back(msg);
    }
    
    return answer;
}