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
    // Node *temp = Tree::root;
    // string *ans ;
    // (*ans)="";
    // cout<< "temp is :" + temp->name<< endl;
    // cout<< "relative is :" + relative << endl;
    // if(temp->name.compare(relative)== 0) 
{
    // return "That's me ";
}
    // else if(temp->dad->name.compare(relative)== 0) 
    // {
    //    
        // return "father";
    // }
//    else if(temp->mom->name.compare(relative)== 0) 
    // {
        // return "mother";
    // }
    // else
    // {    
        // if(temp->mom != nullptr)
        // {
        // (*ans) =chick_mom(temp,relative,ans);
                // cout<< " THE REL IS : " + (*ans) <<endl;

        // }
    //    
        // if(temp->dad != nullptr)
        // {   
        // (*ans) = "";
    //    (*ans)=chick_dad(temp,relative,ans);
        // }
    // else 
    // {
        // return "unrelated" ;
    // }
    // }
     return "";
     }
// string Tree::chick_dad(Node *root,string relative,string *ans)
// {
    //   root = root->dad->dad;
//   
    // while(root !=nullptr)
    // {

    //  if( root->name.compare(relative )==0 )
        // {
        //  return (*ans)+ "grandfather ";
        //   }
    //    else 
            // { 
        //    (*ans) += "great-";
        //    
        //  if(root->mom!= nullptr)
        //    {

            // (*ans)= chick_mom(root,relative,ans);
        //    }
            // }
            // root = root->dad;

    // }

    // return (*ans);
// }
// string Tree::chick_mom(Node *root,string relative,string *ans)
// {
    // root=root->mom;
    //   while(root->mom != nullptr )
    // {
    //   if(root->name.compare(relative) == 0)
    //  {
        //  printf("\n1\n");
        // return  (*ans) + "grandmother ";

    //  }
    //    else
        //  {  
            //  (*ans) += "great-";
            // 
    // if (root->dad != nullptr)
        //  {
        //    (*ans)= chick_dad(root,relative,ans);
        //  }
        //  }
            // root= root->mom;
    // }

    // if(root->name.compare(relative) == 0)
//  {
    //  printf("\n2\n");
    // return  "grandmother ";
//  }
    // 
    // return *(ans);
// }

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
