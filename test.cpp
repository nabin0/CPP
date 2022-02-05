#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<pair<int, int> > s;
    s.insert({2,5});
    s.insert({4,5});
    s.insert({4,5});
    s.insert({2,4});



    for(auto it: s){
        cout << (it).first <<" " << it.second << endl;
    }cout <<endl;

    multiset<pair<int, int> >::iterator it = ++s.begin();

    auto itr = s.find((*it));

    if(itr != s.end()){
        cout << (*itr).first << ' ' << itr->second<< " found!!!" << endl;
    }else{
        cout << "end ptr" << endl;
    }
    


    
    
    return 0;
}