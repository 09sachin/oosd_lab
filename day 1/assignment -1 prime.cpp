#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n =77;  // here we declare N upto which we need to find prime numbers.

    int primes = 0; //variable to store count of prime numbers
    bool isprimenumber;  // bool to check that number is prime or not


    //here we loop from 2 to n to find number of primes
    for ( int i = 2; i <= n ; i ++){
        isprimenumber = true; // we declare it to true

        
        // In this loop we will check condition of prime number
        for (int j = 2 ; j <= i/2; j++){
            //this if statement will evaluate the reminder (condition for prime number)
            if ( i % j == 0){
                isprimenumber = false; //number is not prime so we change bool variable to false that number is not prime
                break; //we no need to loop further as we get that number is not prime so we can move to next number
            }
        }
        
        
        //if second loop gives true than number is prime
        if (isprimenumber){
            primes = primes +1;  // we found a prime 
        }
    }
    

    cout << primes; // final output
    return 0;

}