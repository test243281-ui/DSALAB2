#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    double weight;
    double value;
};

int main()
{
    vector<Item> items = {
        {4.0, 20.0},
        {3.0, 9.0},
        {2.0, 12.0},
        {1.0, 7.0}
    };
    int cap=5;
    cout<< endl ;
    return 0;
}