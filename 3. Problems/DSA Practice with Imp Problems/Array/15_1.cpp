// Steps for solving this problem
// 1. traverse from the right side and find the element which is violating the descending order(let it is item 'v') of the string i.e abedc here b at 1st index is that item
// 2. now find the greater item then v in the right side of it which must be the nearest greater i.e c is the nearest greater of 'b' then d and e comes greater
// 3. swap v with that nearest greataer item 
// 4. reverse the array/string after the v excluding v


#include<iostream>
using namespace std;

void swap(char * a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(string &s, int start, int end){
    while(start < end){
        swap(s[start++], s[end--]);
    }
}

bool nextPermutation(string &s){
    int n = s.length();

    // Traverse from the right and check which item is violating descending order of string items
    int idx_of_diordered_itm = -1; // store index of this(refer above line ) item index
    for (int i = n-1; i >0; i--)
    {
        if(s[i] > s[i-1]){
            idx_of_diordered_itm = i;
            break;
        }
    }
    // idx_of_diordered_itm-1 gives the index of required item in this case

    if(idx_of_diordered_itm == -1){ // If this condition meets it means the given input does not have any next permutation
        return false;
    }else{
        int nearest_maximum_item = idx_of_diordered_itm; // Now we have to find the nearest larger item than disordered item and have to swap them

        // Traverse form right and find the greater item than idx_disordered_item
        for(int i = n-1; i > idx_of_diordered_itm; i--){
            if(s[i] > s[idx_of_diordered_itm - 1]){ 
                nearest_maximum_item = i;
                break;
            }
        }

        swap(&s[idx_of_diordered_itm-1], &s[nearest_maximum_item]);

        // After swapping now reverse the string after the idx_disorderred_item
        reverse(s,idx_of_diordered_itm,n-1);
        return true;
    }
    
}

int main(){
    string s = "abedc";
    nextPermutation(s);
    cout<<s;

    return 0;
}