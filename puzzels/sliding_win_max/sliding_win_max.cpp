
#include <iostream>
#include <queue>
#include <vector>


/*
* Window position 	Max
———————————- 	————————-
[1  3  -1] -3  5  3  6  7 	3
1 [3  -1  -3] 5  3  6  7 	3
1  3 [-1  -3  5] 3  6  7 	5
1  3  -1 [-3  5  3] 6  7 	5
1  3  -1  -3 [5  3  6] 7 	6
1  3  -1  -3  5 [3  6  7] 	7

input: [1,  3,  -1, -3, 5,  3,  6,  7]
output:  [3, 3, 5, 5, 6, 7]
*/



using namespace std;

vector<int> sliding_win_max_1(vector<int>& arr, int winLen){

    vector<int> res;
    for(int i=0; i< arr.size() - winLen; ++i)
    {
        auto winMax = arr[i];
        for(int j=i; j< i + winLen; ++j )
        {
            if (arr[j] > winMax)
            {
                winMax = arr[j];
            }
        }
        res.push_back(winMax);
    }
    return res;
}

vector<int> sliding_win_max_2(vector<int>& arr, int winLen){

    vector<int> res;
    deque<int> deq;
    int winStart = 0;
    for(int i=0; i< arr.size(); ++i)
    {
        // Push seen the indices of seen element in the deque
        if (deq.empty())
        {
            deq.push_back(i);
        }
        else if (arr[i] > arr[deq.back()])
        {
            while(!deq.empty() && arr[deq.back()] < arr[i] )
            {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        else
        {
            deq.push_back(i);
        }

        // Increment winStart
        if (i >= winLen)
        {
            ++winStart; 
            res.push_back(arr[deq.front()]);
        }

        // Remove elements
        if(!deq.empty())
        {
            if (deq.front() < winStart)
            {
                deq.pop_front();
            }
        }
    }
    return res;
}


int main()
{
    vector<int> A ={1, 3, -1, -3, 5, 3, 6, 7, 3};
    auto res1 = sliding_win_max_1(A, 3);
    for (auto el: res1)
    {
        cout<<el<<"\n";
    }

    cout<<"............................\n";
    auto res2 = sliding_win_max_2(A, 3);
    for (auto el: res2)
    {
        cout<<el<<"\n";
    }
  
}