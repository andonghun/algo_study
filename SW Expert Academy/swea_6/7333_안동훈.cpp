#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> weight;
int a1[4] = {25, 17, 13, 10};
int a2[4] = {49, 24, 16, 12};
int arr1[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int arr2[9] = {6, 7, 8, 9, 10, 13, 17, 25, 50};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T, x;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        for(int i=0; i<N; i++){
        	cin >> x;
			weight.push_back(x);
    	}
        
        sort(weight.begin(), weight.end());

        int count = 0;
        while(1){
        	if(weight.empty()) break;
         	int top_box = weight.back();
            
            if(top_box >= 50){
            	count++;
                weight.pop_back();
                continue;
            }
            
            //top_box가 10~49일때
            for(int so_long = 2; so_long<6; so_long++){
                if(top_box >= a1[so_long-2] && top_box <= a2[so_long-2]){
                    if(weight.size() >= so_long) {
                        count++;
                        weight.pop_back();
                        for(int v=0; v<so_long-1; v++) weight.erase(weight.begin());
                    }
                    else weight.pop_back();
                    continue;
                }
            }

            
            //top_box 1~9일 때
			for(int so_long = 0; so_long<9; so_long++){            
                if(top_box == arr1[so_long]){
                    if(weight.size() >= arr2[so_long]) {
                        count++;
                        weight.pop_back();
                        for(int v=0; v<arr2[so_long]-1; v++) weight.erase(weight.begin());
                    }
                    else weight.pop_back();
                    continue;
                }
            }            
        }
        
        cout << "#" << test_case << " " << count << '\n';
	}
	return 0;
}