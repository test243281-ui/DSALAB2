#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{
public:
    double weight;
    double value;
};
// Function to compare two items based on their value-to-weight ratio
bool compare(const Item &a, const Item &b)
{
    double ra = a.value / a.weight; 
    double rb = b.value / b.weight;
    return ra > rb; // Sort in descending order of value-to-weight ratio 
} 
// Function to solve the fractional knapsack problem
double frac_knapsack(vector<Item> items, int cap)
{
    sort(items.begin(), items.end(), compare); // Sort items based on value-to-weight ratio
    double profit = 0.0; // Initialize total profit
    double cap_remaining = cap; // Initialize remaining capacity
    for(Item i: items){
        if(cap_remaining == 0) break; // If capacity is full, break the loop
        if(i.weight <= cap_remaining){ // If the item can be fully added
            profit += i.value; // Add its value to profit
            cap_remaining -= i.weight; // Decrease remaining capacity
        } else { // If the item can only be partially added
            profit += (i.value / i.weight) * cap_remaining; // Add the proportional value
            cap_remaining = 0; // Capacity is now full
            break; // Break the loop as we can't add more items
        }
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