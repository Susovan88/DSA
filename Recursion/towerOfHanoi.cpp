#include <iostream>
using namespace std;

void towerOfHanoi(int n, char s, char h, char d) {   // (source, helper, destination)
    if (n == 0) return;
    towerOfHanoi(n - 1, s, d, h);
    cout << "Move disk " << n << " from " << s << " to " << d << endl;
    towerOfHanoi(n - 1, h, s, d);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
