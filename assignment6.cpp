#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

// Partition using last element as deterministic pivot
int partitionDeterministic(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Partition using random pivot
int partitionRandomized(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partitionDeterministic(arr, low, high);
}

// Deterministic Quick Sort
void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionDeterministic(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arrOriginal(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arrOriginal[i];

    // Copy for each variant
    vector<int> arrDet = arrOriginal;
    vector<int> arrRand = arrOriginal;

    // deterministic version
    quickSortDeterministic(arrDet, 0, n - 1);

    // randomized version
    quickSortRandomized(arrRand, 0, n - 1);

    cout << "Sorted array (Deterministic):\n";
    printArray(arrDet);
    cout << "Sorted array (Randomized):\n";
    printArray(arrRand);

    return 0;
}
