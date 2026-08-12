#include<bits/stdc++.h>
using namespace std;
struct activity
{
   int start;
    int finish;
};
bool compare(const activity &a, const activity &b)
{
    return a.finish < b.finish; // Sort in ascending order of finish time
}
int act_selection(vector<activity> &Activities)
{
    sort(Activities.begin(), Activities.end(), compare); // Sort activities based on finish time
    int crr_finishLine=Activities[0].finish; // Initialize current finish line with the first activity's finish time
    int result=1; // Initialize count of selected activities

    for(int i=1; i<Activities.size(); i++)
    {
        if(Activities[i].start >= crr_finishLine)
        {
            result++;
            crr_finishLine = Activities[i].finish;
        }
    }
    return result;
}

int main()
{
    vector<activity> Activities = {
        {5,7},
        {1,3},
        {2, 7},
        {10, 12},
        {2,5},
        {6, 10},
        {4, 8}

    };
  cout<<act_selection(Activities)<<endl; // Output the maximum number of non-overlapping activities

    return 0;
}

    