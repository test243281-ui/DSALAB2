#include<iostream>
#include <vector>
using namespace std;
int merge_(vector<int> &v, int low, int high, int mid)
{
    int leftsum=INT_MIN;
    int currentsum=0;
    for(int i=mid;i>=low;i--){
        currentsum+=v[i];
        if(currentsum>leftsum)
        leftsum=currentsum;
    }
    int rightsum=INT_MIN;
    currentsum=0;
    for (int i=mid+1;i<=high;i++){
        currentsum+=v[i];
        if(currentsum>rightsum)
        rightsum=currentsum;
    }
    return leftsum+rightsum;

}
int mss(vector<int> &v,int low,int high) 
{
    if (low >= high)
        return v[low];
    int mid=(low+high)/2;
    mss(v,low,mid);
    mss(v,mid+1,high);
    merge_(v,low,high,mid);
return max(merge_(v,low,high,mid),max(mss(v,low,mid),mss(v,mid+1,high)));
}
void display(vector <int> &ivac)
{
    for(int i: ivac){
        cout << i <<"";
    }
    cout << endl;
}
int main()
{
vector<int> ivac={-16,-23,18,20,-7,12,-5};
int sum=mss(ivac,0,ivac.size()-1);
cout<<sum<<endl;
}