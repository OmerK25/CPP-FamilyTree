#include <string>
#include <iostream>
#include "FamilyTree.hpp"

namespace family
{

Tree Tree::search(Tree *T, string name)
{

    if (T->name.compare(name) == 0)
        return *T;

    if (T->mom != nullptr)
        search(T->mom, name);

    if (T->dad != nullptr)
        search(T->dad, name);

    throw runtime_error("name isnt on the tree");

    return *this;
}

Tree &Tree::addFather(string child, string dad)
{

    return *this;
}
Tree &Tree::addMother(string child, string mom)
{
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
void Tree::display()
{
}

} // namespace family