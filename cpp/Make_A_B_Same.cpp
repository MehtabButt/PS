#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
    int t, n, temp;
    vector<int> arr_a;
    vector<int> arr_b;

    cin >> t;

    while(t > 0) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> temp;
            arr_a.push_back(temp);
        }
        for(int i=0; i<n; i++) {
            cin >> temp;
            arr_b.push_back(temp);
        }

        if(arr_a[0]==arr_b[0] and arr_a[n-1]==arr_b[n-1]) {
            int i;
            for(i=2; i<n; i++) {
                if(arr_a[i-1]==arr_b[i-1]) continue;
                else if (arr_a[i] | arr_a[i-2] == arr_b[i-1]) continue;
                else {
                    cout << "NO" << endl;
                    break;
                }
            }
            if(i == n) cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        arr_a.clear();
        arr_b.clear();
        t -= 1;
    }
	return 0;
}
