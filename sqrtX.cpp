#include <iostream>
using namespace std;

int SqrtNUM(int n) {
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    
    int ans = -1;
    while (s <= e) {
        int square = mid * mid;
        
        if (square == n) {
            return mid; // Found exact square root
        } else if (square < n) {
            ans = mid; // Potential answer found, continue searching in upper half
            s = mid + 1;
        } else {
            e = mid - 1; // Square of mid is larger than n, search in lower half
        }
        
        mid = (s + e) / 2; // Update mid
    }
    
    return ans; // Return the floor of the square root
}

int main() {
    int result = SqrtNUM(36);
    cout << "Square root of 36 is: " << result << endl;
    return 0;
}
