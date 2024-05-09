#include <iostream>
using namespace std;
void tower(int n, char beg, char mid, char end) {
    if (n <= 0) {
        cout << "Invalid entry" << endl;
    } else if (n == 1) {
        cout << "Move disk from " << beg << " to " << end << endl;
    } else {
        tower(n - 1, beg, end, mid);
        tower(1, beg, mid, end);
        tower(n - 1, mid, beg, end);
    }
}

int main() {
    int n = 3;
    char a = 'A', b = 'B', c = 'C';
    tower(n, a, b, c);
    return 0;
}
