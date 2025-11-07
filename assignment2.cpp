#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Custom Comparator 
struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

// Recursive function to print Huffman codes
void printCodes(HuffmanNode* root, string str) {
    if (!root)
        return;
    if (!root->left && !root->right)
        cout << root->ch << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build Huffman tree and print codes
void huffmanEncoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (size_t i = 0; i < chars.size(); i++) {
        pq.push(new HuffmanNode(chars[i], freq[i]));
    }

    while (pq.size() > 1) {
        HuffmanNode *left = pq.top(); pq.pop();
        HuffmanNode *right = pq.top(); pq.pop();

        HuffmanNode *top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i] >> freq[i];
    }

    cout << "Huffman Codes:\n";
    huffmanEncoding(chars, freq);

    return 0;
}
