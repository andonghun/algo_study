#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    int correct[3]={0,};
    int div[3] = {5,8,10};
    vector<vector<int>> solv = {{1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}};
    for(int i=0;i<answers.size();i++)
        for(int j=0;j<3;j++)
            if(answers[i]==solv[j][i%div[j]])
                ++correct[j];
    
    int max_correct = max(correct[0],max(correct[1],correct[2]));
    vector<int> answer;
    for(int i=0;i<3;i++)
        if(correct[i]==max_correct)
            answer.push_back(i+1);
    return answer;
}
