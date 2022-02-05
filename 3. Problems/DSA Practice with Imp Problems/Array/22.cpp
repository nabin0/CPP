#include<iostream>
using namespace std;
#define MAX 1000

int multiply(int x, int res[], int res_size);

void factorial(int n){
    int res[MAX]; // Array to store the result
    res[0] = 1; //minfactorial of any number is 1 
    int res_size = 1; //  as 1 is the answer the length of answer is 1

    for (int i = 2; i <= n; i++) // to get factorial of n 1 to n are multiplied i.e n! = n* (n-1) *..*2*1
    {
        res_size = multiply(i,res,res_size);
    }
    
    // Print result 
    for (int i = res_size-1; i >=0; i--)
    {
        cout<<res[i];
    }cout<<endl;
}

int multiply(int x, int res[], int res_size){ // Function to multiply array with x and store result in again 
    int carry = 0;
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] *x+carry; // Product of ith item will be this
        res[i] = prod%10; // Store last item in the array and left items in carry
        carry = prod/10;
    }
    
    while(carry){ // while carry is not zero 
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

int main(){
     factorial(100);
    return 0;
}

//Answer
//93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000