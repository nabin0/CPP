#include<iostream>
#include<limits>
using namespace std;

void ignoreLine(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getDouble(){
    while(true){
        cout << "Enter a Double number: ";
        double x{};

        cin>>x;
        if(cin.fail()){
            cin.clear();
            ignoreLine();
            cerr << "Bad Input. Please Try again." << endl;
        }else{
            ignoreLine();
            return x;
        }
    }
}

char getOperator(){
    while(true){
        cout << "Enter any of the following: '+', '-', '*', '/' : ";
        char symbol{};
        cin>>symbol;

        switch(symbol){
            case '+':
            case '-':
            case '*':
            case '/':
                return symbol;
            default:
                cout << "Invalid Operation!!! Enter Again.\n";
        }
    }
}

void printResult(double n1, double n2, char operation){
    switch(operation){
        case '+':
            cout << "The sum of "<<n1 << " and " << n2 << " is: "<< n1+n2 << endl;
            break;
        case '-':
            cout << "The difference of "<<n1 << " and " << n2 << " is: "<< n1-n2 << endl;
            break;
        case '*':
            cout << "The product of "<<n1 << " and " << n2 << " is: "<< n1*n2 << endl;
            break;
        case '/':
            cout << "The division of "<<n1 << " and " << n2 << " is: "<< n1/n2 << endl;
            break;
        default:
            cout << "Invalid operation!!" << endl;
    }
}

int main(){
    double n1 = getDouble();
    char operation = getOperator();
    double n2 = getDouble();

    printResult(n1, n2, operation);

    return 0;
}