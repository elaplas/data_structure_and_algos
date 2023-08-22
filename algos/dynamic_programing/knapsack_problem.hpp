#include <vector>
#include <iostream>

using namespace std;


struct Item{
    int weight;
    int value;

    Item(int w, int v): weight(w), value(v) {}
};


int knapsackAlgo(const vector<Item>& items, int i, int capacity, int value)
{
    if (capacity <= 0 || i >= items.size())
    {
        return value;
    }

    auto res1 = knapsackAlgo(items, i+1, capacity, value);
    int res2 =0;
    if (items[i].weight <= capacity)
        res2 = knapsackAlgo(items, i+1, capacity-items[i].weight, value+items[i].value);

    return max(res1, res2);
}



int knapsackAlgo_DP(const vector<Item>& items, int maxCapacity)
{

    int lookup[maxCapacity+1];
    for (int i=0; i < maxCapacity+1; ++i)
    {
        lookup[i] = 0;
    }

    for (const auto& item: items)
    {
        for (int capacity=maxCapacity; capacity > 0; --capacity)
        {
            if (item.weight <= capacity)
            {
                lookup[capacity] = max(lookup[capacity], lookup[capacity-item.weight] + item.value);     
            }
        }
    }

    return lookup[maxCapacity];
}




int main()
{

    vector<Item> items = {Item(10, 2), Item(29, 10), Item(5, 7), Item(5, 3), Item(5, 1), Item(24, 12)};
    int maxWeight = 25;
    // correct answer: 14

    auto res = knapsackAlgo(items, 0, maxWeight, 0);
    cout<<res<<"\n";

    res = knapsackAlgo_DP(items, maxWeight);
    cout<<res<<"\n";
    
    return 0;
}