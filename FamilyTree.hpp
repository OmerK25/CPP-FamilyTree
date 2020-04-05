#include <string>

using namespace std;

namespace family
{
class Tree
{
private:
    string name;
    Tree *mom;
    Tree *dad;

public:
    Tree(string n)
    {
        name = n;
        mom = nullptr;
        dad = nullptr;
    }

    Tree &addFather(string, string);
    Tree &addMother(string, string);
    string relation(string);
    string find(string);
    void display();
    void remove(string);
    Tree search(Tree *T, string name);
};
} // namespace family