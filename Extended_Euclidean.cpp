#include <bits/stdc++.h>
using namespace std;

// s*a + t*b = gcd(a,b)
pair<int, int> gcd(int a, int b) {
    int x = a, y = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    
    while (b > 0) {
        int q = a / b;
        int r = a - q * b;
        a = b;
        b = r;
        
        int s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;  
    }

    cout << "Value of s is " << s1 << endl;
    cout << "Value of t is " << t1 << endl;
    
    int val = (s1 * x) + (t1 * y);
    cout << val << " = " << a << endl;  // This will print the equation gcd(a, b) = s*a + t*b
    
    return {a, s1};  // Return gcd and s1 (the inverse if gcd is 1)
}

int main() {
    int a, b;
    cout << "Enter the value of a and b respectively" << endl;
    cin >> a >> b;
    
    auto result = gcd(a, b);
    int gcd_val = result.first;
    int inverse = result.second;
    
    cout << "Value of GCD is " << gcd_val << endl;

    if (gcd_val == 1) {
        // Modular inverse exists only when gcd(a, b) is 1
        int mod_inverse = (inverse % b + b) % b;  // Ensure positive result
        cout << "Inverse of a mod b is " << mod_inverse << endl;
    } else {
        cout << "Inverse doesn't exist as gcd(a, b) != 1" << endl;
    }

    return 0;
}
