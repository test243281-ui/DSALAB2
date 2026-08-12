#include<iostream>
#include<vector>
using namespace std;
void merge_(vector<int> &v, int low, int high, int mid)
{
    vector<int> left, right;

    for (int i = low; i <= mid; i++)
        left.push_back(v[i]);

    for (int i = mid + 1; i <= high; i++)
        right.push_back(v[i]);

    int i = 0, j = 0;
    int k = low;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        v[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size())
    {
        v[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &v,int low,int high)
{
    if (low >= high)
        return;
int mid=(low+high)/2;
mergesort(v,low,mid);
mergesort(v,mid+1,high);
merge_(v,low,high,mid);
}
void display(vector <int> &ivac)
{
    for(int i: ivac){
        cout << i <<"";
    }
    cout << endl;
}
int main(){
    vector<int> v={2,1,7,9,3,50,-2};
    mergesort(v,0,v.size()-1);
    display(v);





}