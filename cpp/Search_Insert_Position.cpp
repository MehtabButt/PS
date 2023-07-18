#include <iostream>
#include <cmath>
using namespace std;

double logOfBase(int n, double b) {
    return log2(n)/log2(b);
}

int NthRoot(int n, int m) {
    double s = 2, e = m;
    double mid;
    double logRes;

    while((e-s) > 1e-6) {
        mid = (s+e)/2.0;
        logRes = logOfBase(m, mid);
        if(logRes > n) s = mid + 1e-6;
        else e = mid - 1e-6;
    }

    if((int)logOfBase(m, round(s)) == n) return round(s);
    return -1;
}
int main() {
    int n, m;
    cin >>n >>m;
    cout <<NthRoot(n, m) <<endl;
    return 0;
}
