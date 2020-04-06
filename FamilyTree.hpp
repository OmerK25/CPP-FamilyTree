#include <string>
#include <string.h>

using namespace std;

namespace family
{
class Node
{
public:
    string name;
    Node *mom;
    Node *dad;

    Node(string n)
    {
        name = n;
        mom = nullptr;
        dad = nullptr;
    }
};

class Tree
{
public:
    Node *root;

    Tree(string n)
    {
        root = new Node(n);
    }

    Tree &addFather(string, string);
    Tree &addMother(string, string);
    string relation(string);
    string find(string);
    void display();
    void remove(string);
    Node *search(Node *root, string name);
};
} // namespace family