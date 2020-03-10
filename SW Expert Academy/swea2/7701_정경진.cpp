#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main()
{
    int T, test_case, numOfNames;
    string name;
    vector <string> names;
	// freopen("input.txt", "r", stdin);
    cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &numOfNames);
        for (int i=0; i<numOfNames; ++i) {
            cin >> name;
            names.push_back(name);
        }
        sort(names.begin(), names.end(), cmp);
        cout << "#" <<test_case << "\n";
        names.erase(unique(names.begin(), names.end()), names.end());
        for (int i=0; i<numOfNames; ++i) {
            cout << names[i] << "\n";
        }
        names.erase(names.begin(), names.end());
	}
	return 0;
}
