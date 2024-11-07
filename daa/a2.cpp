#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    int freq;

    Node *left;
    Node *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node *temp1, Node *temp2)
    {
        return temp1->freq >= temp2->freq;
    }
};

Node *buildHuffmanTree(map<char, int> charFreqMap)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    cout<<"Frequency of characters: "<<endl;
    for (auto it : charFreqMap)
    {
        cout<<it.first<<" "<<it.second<<endl;
        Node *temp = new Node(it.first, it.second);
        pq.push(temp);
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *temp = new Node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }

    return pq.top();
}

void traverseHuffmanTree(Node *root, string code, map<char, string> &charCodeMap)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        charCodeMap[root->data] = code;
        return;
    }

    traverseHuffmanTree(root->left, code + "0", charCodeMap);
    traverseHuffmanTree(root->right, code + "1", charCodeMap);
}

string generateOutputString(string input, map<char, string> charCodeMap)
{
    string output = "";

    for (auto ch : input)
    {
        output += charCodeMap[ch];
    }

    return output;
}

int main()
{
    string input;
    cin >> input;

    cout << "\nInput String : " << input << endl;
    int n = input.size();

    map<char, int> charFreqMap;
    for (int i = 0; i < n; i++)
    {
        charFreqMap[input[i]]++;
    }

    Node *root = buildHuffmanTree(charFreqMap);

    map<char, string> charCodeMap;
    traverseHuffmanTree(root, "", charCodeMap);

    cout << "\nHuffman Codes for each character : " << endl;
    for (auto it : charCodeMap)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    string output = generateOutputString(input, charCodeMap);

    cout << "\nOutput String : " << output << endl;
    cout << endl;

    return 0;
}
