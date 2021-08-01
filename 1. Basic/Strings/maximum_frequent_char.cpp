#include <iostream>
#include <algorithm>
using namespace std;

void maxFreqChar(string st)
{
    int frequencyArr[26] = {0};

    for (int i = 0; i < st.length(); i++)
    {
        frequencyArr[st[i] - 'a']++;
    }
    int mx = -1;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (frequencyArr[i] > mx)
        {
            mx = max(mx, frequencyArr[i]);
            ch = i + 'a';
        }
    }

    cout << "The Character with max. frequency is : " << ch << endl;
    cout << "The maximum frequency is : " << mx << endl;
}

int main()
{
    //String declaration and initialisation
    string str = "fakjskflkjddd";

    // invoking function
    maxFreqChar(str);
    return 0;
}