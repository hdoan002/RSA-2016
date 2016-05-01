#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    int isprime = 1;
    for(int i = 3; i <= num; i++) {
        isprime = 1;
        for(int n = 2; n <= i - 1; n++) {
            if((i % n) == 0) {
                isprime = 0;
            }
        }
    }
    return isprime;
}

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    if(a < b) {
        return gcd(b, a);
    }
    return gcd(a - b, b);
}

int encrypt(int M, int e, int n) {
    int c = static_cast<int>(pow(M, e)) % n;
    return c;
}

int decrypt(int C, int d, int n) {
    int M = static_cast<int>(pow(C, d)) % n;
    cout << "the test:" << static_cast<int>(pow(C, d)) << endl;
    return M;
}

int main() {
    int p;
    int q;
    //Input
    cout << "Please enter a prime integer: ";
    cin >> p;
    
    //Checking Input
    while(!(isPrime(p))) {
        cout << "The number you have enter was not prime." << endl;
        cout << "Please enter a prime integer: ";
        cin >> p;
    }
    
    //Second Input
    cout << "Please enter another prime integer: ";
    cin >> q;
    
    //Checking Second Input
    while(q == p) {
        cout << "This number is the same as the previous number." << endl;
        cout << "Please enter a prime integer: ";
        cin >> q;
        while(!(isPrime(q))) {
            cout << "The number you have enter was not prime." << endl;
            cout << "Please enter a prime integer: ";
            cin >> q;
        }
    }
    
    //n
    int n = p * q;
    //Euler's Totient
    int totient = (p - 1) * (q - 1); 
    
    //Finding e that is relatively prime
    int e = 2;
    while(!((gcd(e, totient)) == 1)) {
        e++;
    }
    
    //Public Key
    cout << "Your e is: " << e << endl;
    cout << "Your PUBLIC KEY is (" << e << ", " << totient << ")." << endl;
    
    //Secret Key
    int d = 1;
    while(((d * e) % totient) != 1) {
        d++;
    }
    cout << "Your SECRET KEY is " << d << "." << endl;
    
    
    //Encrypt (TEST IMPLEMENTATION)
    int c = encrypt(3, e, n);
    cout << "Test encryption is " << c << endl;
    
    //Decrypt (TEST IMPLEMENTATION)
    int m = decrypt(c, d, n);
    cout << "Test decryption is " << m << endl;
}