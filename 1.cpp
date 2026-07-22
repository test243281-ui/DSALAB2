#include<iostream>
#include <vector>
using namespace std;
void change_value(vector<int> vec){
    for (int i=0;i<vec.size();i++){
        vec[i]=vec[i]*vec[i];
    }
}
void display(vector <int> ivac)
{
    for(int i: ivac){
        cout << i <<"";
    }
    cout << endl;
}
int main()
{
    vector<int> ivac={1,2,3,4};
    change_value(ivac);
    display(ivac);
}




