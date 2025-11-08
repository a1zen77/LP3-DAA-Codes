#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
    double ratio;
};

// Comparator to sort items by decreasing profit-to-weight ratio
bool cmp(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

// Greedy fractional knapsack function
double fractionalKnapsack(int capacity, const vector<Item> &items) {
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), cmp);

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (const auto &item : sortedItems) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalProfit += item.profit;
        } else {
            int remaining = capacity - currentWeight;
            totalProfit += item.ratio * remaining;
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    double maxProfit = fractionalKnapsack(capacity, items);
    cout << "Maximum profit in fractional knapsack = " << maxProfit << endl;

    return 0;
}
