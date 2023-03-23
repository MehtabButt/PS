#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	// your code goes here
    int t, n, count, temp, min;
    vector<int> arr;

    cin >> t;
    while(t > 0) {
        count = 0;
        cin >> n;


        for(int i=0; i<n; i++) {
            cin >> temp;
            arr.push_back(temp);
            if(i == 0) {
                min = temp;
            }
            else {
                if(temp < min) min = temp;
            }
        }

        for(int i : arr) {
            if(i > min) count += 1;
        }

        cout << count << endl;
        arr.clear();
        t -= 1;
    }
	return 0;
}
