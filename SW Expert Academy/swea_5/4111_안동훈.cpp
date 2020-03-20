//왜 50개중에 48개만 맞는지 모르겠네욤

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T, x;
    int N, K;
    vector<int> cam;
    vector<int> dist;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
        for(int i=0; i<N; i++){
        	cin >> x;
            cam.push_back(x);
        }
  
        sort(cam.begin(), cam.end());
 
 
        
        for(int i=0; i<cam.size()-1; i++){
        	dist.push_back(cam[i+1]-cam[i]);
        }
        int size = dist.size();      
        
        sort(dist.begin(), dist.end());
        
        int max_dist = 0;
        for(int i=0; i<size-K+1; i++){
        	max_dist += dist[i];
        }

        cam.clear();
        dist.clear();
        
        cout << "#" << test_case << " " << max_dist << '\n';
	}
	return 0;
}
