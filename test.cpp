#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<int> v(5, 72);

for(auto elem:v){
    cout<<elem<<" ";
}

return 0;
}