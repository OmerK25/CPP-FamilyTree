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
    Node *temp = this->root;
    string *ans ;
    (*ans)="";
    if(temp->name.compare(relative)== 0) 
{
    return "That's me ";
}
    else if(temp->dad->name.compare(relative)== 0) 
    {
       
        return "father";
    }
   else if(temp->mom->name.compare(relative)== 0) 
    {
        return "mother";
    }
    else
    {           
        if(temp->dad != nullptr)
        {   
        (*ans) = "";
       (*ans)=findDad(temp,relative,ans);
        }
    }
     return (*ans);
      }
string Tree::findDad(Node *root,string relative,string *ans)
{
      Node *temp = root->dad;
  
    while(temp !=nullptr)
    {

     if( temp->name.compare(relative )==0 )
        {
         return (*ans)+ "grandfather ";
          }
     else if(temp->mom != nullptr)
        {
            if(temp->mom->name.compare(relative) == 0)
            {
                return (*ans) + "grandmother";
            }
        }
       else 
            { 
           (*ans) += "great-";
            }
             
            temp = temp->dad;

    }

        
    return "unrelated";
}
string Tree::findMom(Node *root,string relative,string *ans)
{
          Node *temp = root->mom;
  
    while(temp !=nullptr)
    {

     if( temp->name.compare(relative )==0 )
        {
         return (*ans)+ "grandfather ";
          }
     else if(temp->mom != nullptr)
        {
            if(temp->mom->name.compare(relative) == 0)
            {
                return (*ans) + "grandmother";
            }
        }
       else 
            { 
           (*ans) += "great-";
            }
             
            temp = temp->dad;

    }
        
    return "unrelated";
}

string Tree::find(string relation)
{   
    if(relation.compare("me")== 0)
    {
        return this->root->name;
    }
    else if(relation.compare("father") == 0)
    {
        return this->root->dad->name ;
    }
   else if( relation.compare("mother") == 0) 
    {
        return this->root->mom->name;
    }
    else 
    {   
        try
        {   
          
              string _Rel = relation;
    return get_name(_Rel,this->root );
        }
        catch(const std::exception& e)
        {
           throw runtime_error( "This function can't give you the "+ relation +"'s name")  ;
        }
    }
    
    return "";
}
string  Tree::get_name(string relation,Node *node)
{   

    if(relation.compare("grandfather") ==0)
    {
        return node->dad->dad->name;
    }
    else if(relation.compare("grandmother") == 0)
    {
        if(node->dad->mom != nullptr)
        {
            return node->dad->mom->name;
        }
        if(node->mom->mom != nullptr)
        {
            return node->mom->mom->name;
        }
    }
    else
    {   

        string temp ;
        temp.append(relation.begin()+6,relation.end());
        return get_name(temp,node->dad);
    }
    return "";
}
void Tree::remove(string relative)
{   
    Node *temp = this->root;
    bool flag =ifNodeExists(temp,relative);
    if(flag){
        Node* _node = search(root,relative);
           cout<< "YOU ARE SEARCHING FOR : " + _node->name << endl;
        Node* deleted_node=leafDelete(_node);
           cout<< "YOU DELETED : " + deleted_node->name << endl;
    }
    else
    {
       throw runtime_error(relative + " is not one of the family");
    }
    

}
 Node*  Tree::leafDelete( Node* root) 
{ 
    if (root == NULL) 
        return NULL; 
    if (root->mom == NULL && root->dad == NULL) { 
        free(root); 
        return NULL; 
    }  
    // Else recursively delete in left and right 
    // subtrees. 
    root->mom = leafDelete(root->mom); 
    root->dad = leafDelete(root->dad); 
  
    return root; 
} 
bool Tree::ifNodeExists( Node* node, string key) 
{ 
    if (node == NULL) 
        return false; 
  
    if (node->name == key) 
        return true; 
  
    /* then recur on left sutree */
    bool res1 = ifNodeExists(node->mom, key); 
  
    if(res1) return true; // node found, no need to look further 
  
    /* node is not found in left, so recur on right subtree */
    bool res2 = ifNodeExists(node->dad, key); 
  
    return res2; 
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
