#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>

#define f first
#define s second
#define sint short int

using namespace std;

class Node {
public:
    Node* left, * right;
    sint value;
    Node(sint v) : left(nullptr), right(nullptr), value(v) {}
    Node(Node* a, Node* b) : left(a), right(b), value(-1) {}
};

void dfs(Node* x, map<char, string>& MP, string st) {
    if (x->value > -1)
        MP[x->value] = st;
    else {
        dfs(x->left, MP, st + '1');
        dfs(x->right, MP, st + '0');
    }
}

class Tree {
public:
    Node* Root = new Node(-1);
    map<char, string> MP;
    Tree(int data[256]) {  
        priority_queue < pair<int, Node*>> PQ;
        for(sint i = 0; i < 256; i++)
            if (data[i] != 0) {
                PQ.push(make_pair(-data[i], new Node(i)));
            }
        while (PQ.size() > 1) {
            auto A = PQ.top();
            PQ.pop();
            auto B = PQ.top();
            PQ.pop();
            PQ.push(make_pair(A.first + B.first, new Node(B.second, A.second)));
        }
        Root = PQ.top().second;
        dfs(Root, MP, "");
    }

};

Tree encode(string &filename) {
    ifstream fin(filename);
    string s;
    int data[256] = { 0, };
    char c;
    while (fin.get(c)) data[c]++;
    Tree Tr(data);
    fin.close();
    map<char, string> MP;
    fin.open(filename);
    
    string Res = "";
    while (fin.get(c)) {
        Res += Tr.MP[c];
    }
    ofstream fout(filename.substr(0, filename.length() - 4) + "_encode.txt");
    fout << Res;
    return Tr;
}

void decode(Tree& Tr, string& filename) {
    ifstream fin(filename);
    ofstream fout(filename.substr(0, filename.length() - 4) + "_decode.txt");
    char c;
    Node* curr = Tr.Root;
    while (fin.get(c)) {
        if (c == '1')
            curr = curr->left;
        else curr = curr->right;
        if (curr->value > -1) {
            fout << (char)(curr->value);
            curr = Tr.Root;
        }
            
    }
}

int main()
{
   string path = "input.txt";
  Tree Tr = encode(path);
   path = "input_encode.txt";
   decode(Tr, path);
   return 0;
}
