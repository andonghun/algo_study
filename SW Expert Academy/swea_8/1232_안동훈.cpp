#include<bits/stdc++.h>

using namespace std;

int N;
string node[2002];
stack<float> s;
string temp = "0";

void cal(string str){
    char op[1];
    strcpy(op, str.c_str());
    
    if(op[0] == '*'){
            float a = s.top();
        	s.pop();
            float b = s.top();
        	s.pop();
			s.push(b*a);        
    }        
    else if(op[0] == '/'){
            float a = s.top();
        	s.pop();
            float b = s.top();
        	s.pop();
            s.push(b/a);
    }
    else if(op[0] == '+'){
            float a = s.top();
        	s.pop();
            float b = s.top();
        	s.pop();
            s.push(b+a);
    }
    else if(op[0] == '-'){
            float a = s.top();
        	s.pop();
            float b = s.top();
        	s.pop();
            s.push(b-a);
    }
}

void order(int num){
    if(node[num] == temp) return;
    order(2*num);
    order(2*num +1);
    if(atoi(node[num].c_str()) == 0) cal(node[num]);
    else s.push((float) atoi(node[num].c_str()));
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
	int test_case;
	int T=10;
    int num, temp1, temp2, temp3;
    string value;
	
	for(test_case = 1; test_case <= T; ++test_case){
        for(int i=0; i<2002; i++){
       		node[i] = temp;
        }
        
        for(int i=1; i<=N; i++){
        	cin >> num >> value;
            if((N%2 == 0 && i < N/2) || (N%2 == 1 && i <= (N-1)/2)){
            cin >> temp1 >> temp2;
            }
        	else if(N%2 == 0 && i == N/2){
            cin >> temp3;
            }
        	node[num] = value;
        }
        
        order(1);
        
        int result = s.top();
        s.pop();

        
        for(int i=1; i<=N; i++){
        cout << node[i] << " ";
        }
        
        cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
