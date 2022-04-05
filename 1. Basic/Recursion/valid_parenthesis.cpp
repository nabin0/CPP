#include<iostream>
#include<vector>

std::vector<std::string> valid;

void generate(std::string &s, int open, int close){
    if(open == 0 && close == 0){ // Base condition
        valid.push_back(s);
    }

    // Insert open parenthesis is the string
    if(open > 0){
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back(); // Backtracking step
    }

    // Insert closing parenthesis in the string
    if(close > 0){
        if(open < close){
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
}

int main(){
    int n;
    std::cin >> n;
    std::string s = "";
    generate(s, n, n);

    for(std::string s : valid)
        std::cout << s << std::endl;
    return 0;
}