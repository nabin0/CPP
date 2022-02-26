#include<iostream>
#include<algorithm> // for std algorithms
#include<vector> // For vector dsa
#include<numeric> //For accumulate

int main(){
    int n;
    std::cin >> n;

    std::vector<int> v(n);

    for(int i = 0; i < n; ++i){
        std::cin>>v[i];
    }

/*
    // sort func
    std::sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }

*/

/*
    // is item present in array or not
    auto it = std::find(v.begin(), v.end(), 4);
    if(it != v.end()){
        std::cout << *it << std::endl;
    }else{
        std::cout << "The Item Is Not Found." << std::endl;
    }
*/
/*
    int sum = std::accumulate(v.begin(), v.end(),0); // Results the sum of array
    int count = std::count(v.begin(), v.end(),4); // Result count of given item

    std::cout << count << std::endl;

*/
/*
    std::sort(v.begin(), v.end()); // Necessary to sort other wise time comp will be o(n)

    std::cout << *std::lower_bound(v.begin(), v.end(),4) << std::endl; // REturns the iterator of same item if exist other wise iterator of next greater item
    std::cout << *std::upper_bound(v.begin(), v.end(),4) << std::endl; // Returns the it of greater item
*/

// Using lambda function as comparator 

    std::cout << std::all_of(v.begin(), v.end(),
    [](int a){return a > 0;}); // Returns true if all member satisfies the condition

    std::cout << std::any_of(v.begin(), v.end(),
    [](int item){return item>0;}); // Returns true if any one is true

    std::cout << std::none_of(v.begin(), v.end(),
    [](int item){return item>0;}); // returns true if all returns false

    return 0;
}