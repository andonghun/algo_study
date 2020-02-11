#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
//18min 15sec
using namespace std;
int answer = 987654321;
bool can_Convert(string s1, string s2){
    bool flag = false;
    for(int i=0;i<s1.length();i++){
        if(!flag&&(s1[i]!=s2[i])){
            flag = true;
            continue;
        }
        if(flag&&(s1[i]!=s2[i])){
            return false;
        }
    }
    return flag;
}

int DFS(string &begin, string &target, vector<string> &words,int depth){
    if(begin==target){
        return depth;
    }
    if(words.size()==0)
        return 987654321;
    if(depth>answer)
        return 987654321;
    
    int ret = 987654321;
    bool arr[words.size()];
    memset(arr,false,sizeof(arr));
    for(int i=0;i<words.size();i++){
        arr[i]=can_Convert(begin,words[i]);
    }
    vector<string> next_words;
    for(int i=0;i<words.size();i++){
        if(arr[i]){
            next_words.clear();
            next_words.assign(words.begin(),words.end());
            next_words.erase(next_words.begin()+i);
            ret = min(ret,DFS(words[i],target,next_words,depth+1));
        }
    }
    return ret;
}
int solution(string begin, string target, vector<string> words) {
    answer = DFS(begin,target,words,0);
    if(answer<100)
        return answer;
    else
        return 0;
}
