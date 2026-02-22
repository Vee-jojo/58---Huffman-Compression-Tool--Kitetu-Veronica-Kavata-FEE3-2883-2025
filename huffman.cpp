#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ================= NODE STRUCTURE =================
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// ================= MIN HEAP COMPARATOR =================
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// ================= GENERATE HUFFMAN CODES =================
void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right) {
        // Special case: single character
        if (code == "")
            code = "0";
        huffmanCode[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// ================= PRINT TREE =================
void printTree(Node* root, string indent = "", bool last = true) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "     ";
        } else {
            cout << "L----";
            indent += "|    ";
        }

        if (root->data != '\0')
            cout << root->data << "(" << root->freq << ")" << endl;
        else
            cout << "*(" << root->freq << ")" << endl;

        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

// ================= DECODE FUNCTION =================
string decode(Node* root, string encodedStr) {
    string decoded = "";
    Node* current = root;

    for (char bit : encodedStr) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        // If leaf
        if (!current->left && !current->right) {
            decoded += current->data;
            current = root;
        }
    }
    return decoded;
}

// ================= BUILD HUFFMAN TREE =================
Node* buildTree(string text) {
    unordered_map<char, int> freq;

    for (char ch : text)
        freq[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Special case: only one unique character
    if (pq.size() == 1) {
        Node* only = pq.top();
        Node* root = new Node('\0', only->freq);
        root->left = only;
        return root;
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    return pq.top();
}

// ================= MAIN PROGRAM =================
int main() {
    int choice;

    cout << "====== HUFFMAN COMPRESSION TOOL ======\n";

    do {
        cout << "\n1. Compress Text\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {

            string text;
            cout << "\nEnter text to compress:\n";
            getline(cin, text);

            if (text.empty()) {
                cout << "Text cannot be empty!\n";
                continue;
            }

            // Build tree
            Node* root = buildTree(text);

            // Generate codes
            unordered_map<char, string> huffmanCode;
            generateCodes(root, "", huffmanCode);

            // Display Code Table
            cout << "\n----- HUFFMAN CODE TABLE -----\n";
            for (auto pair : huffmanCode)
                cout << pair.first << " : " << pair.second << endl;

            // Encode
            string encoded = "";
            for (char ch : text)
                encoded += huffmanCode[ch];

            cout << "\nCompressed Binary:\n" << encoded << endl;

            // Decode
            string decoded = decode(root, encoded);
            cout << "\nDecompressed Text:\n" << decoded << endl;

            // Sizes
            int originalSize = text.length() * 8;
            int compressedSize = encoded.length();

            cout << "\nOriginal Size (bits): " << originalSize << endl;
            cout << "Compressed Size (bits): " << compressedSize << endl;

            double compressionRatio = compressedSize == 0 ? 0 :
                (double)originalSize / compressedSize;

            cout << fixed << setprecision(2);
            cout << "Compression Ratio: " << compressionRatio << endl;

            // Print Tree
            cout << "\n----- HUFFMAN TREE -----\n";
            printTree(root);
        }

    } while (choice != 2);

    cout << "\nProgram Ended.\n";
    return 0;
}
