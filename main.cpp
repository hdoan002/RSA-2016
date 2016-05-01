#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    int isNotprime = 0;
    for(int i = 3; i <= num; i++) {
        isNotprime = 0;
        for(int n = 2; n <= i - 1; n++) {
            if((i % n) == 0) {              //checks if not prime
                isNotprime = 1;
            }
        }
    }
    return isNotprime;
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
//Checking Input
void check_first(int p) {
    while(p > 7) {
        cout << "The number you have entered is not allowed." << endl;
        cout << "Please enter a prime integer (0 - 7): ";
        cin >> p;
    }
    while(isPrime(p)) {
        cout << "The number you have entered was not prime." << endl;
        cout << "Please enter a prime integer (0 - 7): ";
        cin >> p;
    }
}

//Checking Second Input
void check_second(int q, int p) {
    while(q > 7) {
        cout << "The number you have entered is not allowed." << endl;
        cout << "Please enter another prime integer (0 - 7): ";
        cin >> q;
    }
    while(isPrime(q)) {
        cout << "The number you have entered was not prime." << endl;
        cout << "Please enter another prime integer (0 - 7): ";
        cin >> q;
        while (q == p) {
            cout << "This number is the same as the previous number." << endl;
            cout << "Please enter another prime integer (0 - 7): ";
            cin >> q;
        }
    }
}

//Finding e
int acquire_E(int totient) {
    int e = 2;
    while(!((gcd(e, totient)) == 1)) {
        e++;
    }
    return e;
}

//Finding secret key
int acquire_Secret(int e, int totient) {
    int d = 1;
    while(((d * e) % totient) != 1) {
        d++;
    }
    return d;
}

//outputs public key
void outputPublic(int e, int totient) {
    cout << "Your e is: " << e << endl;
    cout << "Your PUBLIC KEY is (" << e << ", " << totient << ")." << endl; 
}

//outputs secret key
void outputSecret(int d) {
    cout << "Your SECRET KEY is " << d << "." << endl;
}

////////////////////////////////////////////////////////////////////
int main() {
    int p;
    int q;
    string username;
    string password;
    
    cout << "Please enter your username: ";
    cin >> username;
    
    cout << "Please enter your password: ";
    cin >> password;
    
    //First Input
    cout << "Please enter a prime integer (0 - 7): ";
    cin >> p;
    
    //check first input
    check_first(p);
    
    //Second Input
    cout << "Please enter another prime integer (0 - 7): ";
    cin >> q;
    
    //check second input
    check_second(q, p);
    
    //n
    int n = p * q;
    //Euler's Totient
    int totient = (p - 1) * (q - 1); 
    
    //Finding e that is relatively prime
    int e = acquire_E(totient);
    
    
    
    

    
    // //Encrypt (TEST IMPLEMENTATION)
    // int c = encrypt(9, e, n);
    // cout << "Test encryption is " << c << endl;
    
    // //Decrypt (TEST IMPLEMENTATION)
    // int m = decrypt(c, d, n);
    // cout << "Test decryption is " << m << endl;
}

//NOTE: (5-1-16)

/*
There is a limitation to the RSA where in order for the algorithm to
be effective, you must allow for the computation of really big 
numbers by finding a way to represent large numbers. This could be 
solved through the usage of long long ints, but for now I will just 
limit the computation of exponental numbers by limiting the inputs 
to numbers lower than 7. This should limit the possibilities of the
totient. I will experiment with unsigned long long ints later on 
down the road.
*/