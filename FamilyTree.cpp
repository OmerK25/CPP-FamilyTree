/*
 *AUTHOR: Omer Katz & Raafat Marzuq
 *
 * Date: 2020-04
 *
 */

#include <string>
#include <iostream>
#include "FamilyTree.hpp"

using namespace family;

Node *Tree::search(Node *root, string name)
{
    if (root->name.compare(name) == 0)
    {
        return root;
    }

    if (root->mom != nullptr)
    {
        Node *ans = search(root->mom, name);
        if (ans != nullptr)
            return ans;
    }

    if (root->dad != nullptr)
    {
        Node *ans = search(root->dad, name);
        if (ans != nullptr)
            return ans;
    }

    return nullptr;
}

Tree &Tree::addFather(string child, string dad)
{
    Node *ptr = search(this->root, child);
    if (ptr != nullptr)
    {
        if (ptr->dad == nullptr)
        {
            ptr->dad = new Node(dad);

            return *this;
        }
        else
        {
            //cout << "got dad" << endl;
        }
    }
    return *this;
}

Tree &Tree::addMother(string child, string mom)
{
    Node *ptr = search(this->root, child);
    if (ptr != nullptr)
    {
        if (ptr->mom == nullptr)
        {
            ptr->mom = new Node(mom);

            return *this;
        }
        else
        {
            //cout << "got mom" << endl;
        }
    }
    return *this;
}

string Tree::relation(string)
{
    return "";
}
string Tree::find(string)
{
    return "";
}
void Tree::remove(string)
{
}

void print2D(Node *root, int space)
{
    if (root == NULL)
        return;  //Base case
    space += 10; // Increase distance between levels

    print2D(root->dad, space); // Process father node
    cout << endl;              // Print current node after space
    for (int i = 10; i < space; i++)
    {
        cout << " ";
    }
    cout << root->name << "\n";
    print2D(root->mom, space); // Process mother node
}
//
void Tree::display()
{ // Done !
    cout << "Display Tree:\n--------------------------------------------------------------";
    print2D(this->root, 0);
    cout << "--------------------------------------------------------------" << endl;
}
