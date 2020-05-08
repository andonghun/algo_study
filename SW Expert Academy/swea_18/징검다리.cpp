/*
2020-05-07 진예진
참고 https://regularmember.tistory.com/193?category=762816
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> visited_rooms;

long long get_empty_room_number(long long cur_room){
    // 0: 비어있음
    if(visited_rooms[cur_room] == 0) return cur_room;
    // visited_room[cur_room]은 모두 비어있는 가장 작은 방의 수로 업데이트 됨
    return visited_rooms[cur_room] = get_empty_room_number(visited_rooms[cur_room]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    // long long empty_room_number;
    
    for(long long cur_room:room_number){
    	long long empty_room_number = get_empty_room_number(cur_room);
        answer.push_back(empty_room_number);
        // 현재 추가된 방도 visited_room에 추가해준다.
        visited_rooms[empty_room_number] = empty_room_number + 1;
    }
    return answer;
}
