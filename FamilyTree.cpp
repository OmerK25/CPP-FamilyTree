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
            if (temp->relation == "me")
                temp->dad->relation = "father";
            else if (temp->relation == "father")
                temp->dad->relation = "grandfather";
            else if (temp->relation == "mother")
                temp->dad->relation = "grandfather";
            else if (temp->relation == "grandfather")
                temp->dad->relation = "great-grandfather";
            else if (temp->relation == "grandmother")
                temp->dad->relation = "great-grandfather";
            else
            {
                string t = "great-" + temp->relation;
                for (int j = 0; j < 6; j++)
                    t.pop_back();
                t += "father";
                temp->dad->relation = t;
            }
            return *this;
        }
        else
        {
            throw runtime_error("already have a father");
        }
    }
    else
    {
        throw runtime_error("the child is not in the tree");
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
            if (temp->relation == "me")
                temp->mom->relation = "mother";
            else if (temp->relation == "father")
                temp->mom->relation = "grandmother";
            else if (temp->relation == "mother")
                temp->mom->relation = "grandmother";
            else if (temp->relation == "grandfather")
                temp->mom->relation = "great-grandmother";
            else if (temp->relation == "grandmother")
                temp->mom->relation = "great-grandmother";
            else
            {
                string t = "great-" + temp->relation;
                for (int j = 0; j < 6; j++)
                    t.pop_back();
                t += "mother";
                temp->mom->relation = t;
            }
            return *this;
        }
        else
        {
            throw runtime_error("already have a mother");
        }
    }
    else
    {
        throw runtime_error("the child is not in the tree");
    }
    return *this;
}

string Tree::relation(string relative)
{
    Node *temp = search(this->root, relative);
    if (temp != nullptr)
        return temp->relation;

    return "unrelated";
}

string Tree::find(string relation)
{
    Node *ptr = get_name(relation, this->root);
    if (ptr != nullptr)
        return ptr->name;

    throw runtime_error("This function can't give you the " + relation + "'s name");
}


Node *Tree::get_name(string relation, Node *root)
{
    if (root->relation.compare(relation) == 0)
    {
        return root;
    }

    if (root->mom != nullptr)
    {
        Node *ptr = get_name(relation, root->mom);
        if (ptr != nullptr)
            return ptr;
    }

    if (root->dad != nullptr)
    {
        Node *ptr2 = get_name(relation, root->dad);
        if (ptr2 != nullptr)
            return ptr2;
    }

    return nullptr;
}

void Tree::remove(string relative) //" "
{
    Node *temp = this->root;
    Node *t = search(temp, relative);
    if (t != nullptr)
    {

        if (t->relation == "me")
            throw runtime_error("This function can't give you the " + relative + "'s name");

        t=nullptr;
        delete t;
        // cout << "YOU ARE SEARCHING FOR : " + t->name << endl;
        // leafDelete(t);
        // cout << "YOU DELETED : " + t->name << endl;
    }
    else
    {
        throw runtime_error(relative + " is not one of the family");
    }
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
