    #include<iostream>
    #include<stack>
    #include<algorithm>
    using namespace std;

    struct Interval{
        int start;
        int end;
    };

    bool compareInterval(Interval i1,Interval i2){ //  compare func to sort interval array
        return i1.start < i2.start;
    }
    
    void mergeInterval(Interval interval[], int n){
        if(n == 0  or n == 1) // if only one or no values given in array
            return;
        
        stack<Interval> s; 
        
        sort(interval , interval +n, compareInterval);
        s.push(interval[0]);

        for (int i = 1; i < n; i++)
        {
            Interval top  = s.top();

            if(top.end < interval[i].start) //if conjugative item are not overlapped
                {s.push(interval[i]);
                continue;}
            else if(top.end <= interval[i].end){ //if conjugative item are overlapped
                top.end  = interval[i].end;
                s.pop();
                s.push(top);
            }
        }
        
        // Printing merged intervals
        while(!s.empty()){
            Interval top  = s.top();
            cout<<"{"<<top.start<< " "<< top.end<<"}"<<" ";
            s.pop();
        }
        
    }
    int main(){
        Interval itv[] = {{1,3}, {2,4},{5,6},{1,5}, {7,9}};
        int s = sizeof(itv)/sizeof(itv[0]);
        mergeInterval(itv,s);
        return 0;
    }