#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int c, t;
    cin >> t;
    while(t > 0) {
        cin >> c;
        cout << (c%3 == 0 ? "YES" : "NO") << endl;
        t -= 1;
    }
    return 0;
}
