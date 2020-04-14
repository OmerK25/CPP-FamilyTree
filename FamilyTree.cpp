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
    Node *temp = search(this->root, child);
    if (temp != nullptr)
    {
        if (temp->dad == nullptr)
        {
            temp->dad = new Node(dad);

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
    Node *temp = search(this->root, child);
    if (temp != nullptr)
    {
        if (temp->mom == nullptr)
        {
            temp->mom = new Node(mom);

            return *this;
        }
        else
        {
            //cout << "got mom" << endl;
        }
    }
    return *this;
}

string Tree::relation(string relative)
{
    Node *temp = Tree::root;
    string ans="";
    if(temp->mom != nullptr)
        ans= chick_mom(temp,relative);
    else if((temp->dad != nullptr) && (ans.compare("")==1))
        return chick_dad(temp,relative);
    else
    {
        return "unrelated" ;
    }
    
    }
string Tree::chick_dad(Node *root,string relative)
{
      root = root->dad;

    while(root !=nullptr)
    {
        if( root->name.compare(relative )==0 )
            return "grand";
        else if(root->mom!= nullptr)
            return chick_mom(root,relative);
        else
            root = root->dad;
    }
    return "father";
}
string Tree::chick_mom(Node *root,string relative)
{
    root=root->mom;
    
      while(root!=NULL)
    {
        if(root->name.compare(relative) == 0)
            return "grand";
        else if (root)
            return chick_dad(root,relative);
        else
            root= root->mom;
    }
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
