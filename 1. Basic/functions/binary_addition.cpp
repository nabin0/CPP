#include<iostream>
using namespace std;

int reverse(int n){
    int num = 0;
    while(n > 0){
        int lstDigit = n %10;
        num = num*10 + lstDigit;
        n/=10;
    }
    return num;
}

int addBinary(int a, int b){
    int r = 0; //reminder
    int sum = 1; // Initializing it with 1 willhwlp to store 0 values too other wise it will ignore zeros in some conditions

// Adding binary digits from end
while(a > 0 && b>0){

    if (a %2 == 0 && b%2==0){

        // ---------We can write this as-----------

        /*
        if(r == 1){
            sum = sum * 10 + 1;
            r = 0;
        }
        else{
            sum = sum *10 + 0;
            r = 0;
        }
        */

        // ---------In place of above-----------
        sum = sum * 10 + 1;
            r = 0;
    }
    else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0)){
        if(r ==1){
            sum = sum*10 + 0;
            r = 1;
        }
        else{
            sum = sum * 10 + 1;
            r = 0;
        }
    }
    else{
        if(r ==1){
            sum = sum *10 + 1;
            r = 1;
        }
        else{
            sum = sum * 10 +0;
            r = 1;
        }
    }

    a/=10;
    b/=10;
}

// Attending leftover digits in a
while(a >0){
    if(r ==1){
        if(a%2==1){
        sum = sum *10 + 0;
        r = 1;
        }
        else{
            sum = sum*10 + 1;
            r = 0;
        }
    }
    else{
        sum = sum *10 + (a%2);
        r = 0;
    }
    a/=10;
}


// Attending leftover digits in b
while(b >0){
    if(r ==1){
        if(b%2==1){
        sum = sum *10 + 0;
        r = 1;
        }
        else{
            sum = sum*10 + 1;
            r = 0;
        }
    }
    else{
        sum = sum *10 + (b%2);
        r = 0;
    }
    b/=10;
}

// Checking left reminder
if(r == 1){
    sum = sum*10 + 1;
}

// Since we have added numbers from last to first we need to reverse answer
sum = reverse(sum);
// Removing excess 1 from answer that we have initialized it with
sum = sum /10;
return sum;
}

int main(){
int b1,b2;
cin>>b1>>b2;

cout<<"The sum of entered binary numbers is: "<<addBinary(b1, b2)<<endl;
return 0;
}