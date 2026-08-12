#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Item
{
public:
    double weight;
    double value;
};
bool compare(const Item &a, const Item &b)
{
    double ra = a.value / a.weight; 
    double rb = b.value / b.weight;
    return ra > rb; // Sort in descending order of value-to-weight ratio 
}
double frac_knapsack(vector<Item> items, int cap)
{
   sort(items.begin(), items.end(), compare); // Sort items based on value-to-weight ratio// Sort items based on value-to-weight ratio
    double profit = 0.0; // Initialize total profit
    double cap_remaining = cap; // Initialize remaining capacity
  for(Item i: items){
    double percentage=min(1.0, cap_remaining/i.weight);
    profit += percentage * i.value; // Add the proportional value
    cap_remaining -= percentage * i.weight; // Decrease remaining capacity
  }
    return profit; // Return the total profit
}
int main()
{
    vector<Item> items = {
        {4.0, 20.0},
        {3.0, 9.0},
        {2.0, 12.0},
        {1.0, 7.0}
    };
    int cap=5;
    cout<< frac_knapsack(items, cap) << endl ;
    return 0;
}