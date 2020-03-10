#include<iostream>
#include<set>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int N, first_num, mid, x, y;
    multiset<int> s;
    multiset<int>:: iterator it;
    
    long long result = 0;

    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> first_num;
			
        	s.insert(first_num);
        	it = s.begin();
        	mid = first_num;
        
        	for(int i=0; i<N; i++){
            	cin >> x >> y;

                s.insert(x);
                s.insert(y);
                
 
                if (mid >= x && mid >= y){
                	it--;
                }
                else if (mid <= x && mid <= y)  {
                    it++; 
                }
                
                mid = *it;
                result += mid;
                result %= 20171109;

            }

        cout << "#" << test_case << " " << result << '\n';
        result = 0;
        s.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}





/* 문제 조건대로 최대 힙, 최소 힙 이용해서 풀었지만 시간 초과, 테스트 케이스 10개는 통과함 
#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	int test_case;
	int T, x, mean;
    long long sum = 0;
    int N, first_num;
	priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;    

	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
    
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> first_num;
        maxheap.push(first_num);
        
        for(int i=0; i<N; i++){
			for(int j=0; j<2; j++){
                cin >> x;

                if(maxheap.size() > minheap.size()){
                    minheap.push(x);
                }
                else{
                    maxheap.push(x);
                }

                if(!minheap.empty() && !maxheap.empty() && minheap.top() < maxheap.top() ) {
                    int a = maxheap.top();
                    int b = minheap.top();
                    maxheap.pop();
                    minheap.pop();
                    maxheap.push(b);
                    minheap.push(a);
                }

            }
                mean = maxheap.top();
                sum += mean;
        }
        cout << "#" << test_case << " " << sum%20171109 << '\n';
        
        sum = 0;
        
        while (!maxheap.empty())
		{
    		maxheap.pop();
		}
        while (!minheap.empty())
		{
    		minheap.pop();
		}
        
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
*/
