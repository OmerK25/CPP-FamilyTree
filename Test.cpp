#include "FamilyTree.hpp"
#include <iostream>
#include "doctest.h"

using namespace family;
using namespace std;

TEST_CASE("Check the tree.")
{
    family::Tree T("r");
    T.addFather("r", "rf")
        .addMother("r", "rm")
        .addFather("rf", "rff")
        .addMother("rf", "rfm")
        .addFather("rm", "rmf")
        .addMother("rm", "rmm")
        .addFather("rmm", "rmmf")
        .addFather("rmmf", "rmmff")
        .addFather("rmff", "rmfff")
        .addMother("rmm", "rmmm")
        .addFather("rmmm", "rmmmf")
        .addMother("rmmm", "rmmmm")
        .addFather("rmmmm", "rmmmmf")
        .addMother("rmmmmf", "rmmmmfm")
        .addFather("rmmmmf", "rmmmmff")
        .addMother("rmmmmff", "rmmmmffm")
        .addFather("rmmmmffm", "rmmmmffmf")
        .addMother("rmmmmffmf", "rmmmmffmfm")
        .addFather("rmmmmffmf", "rmmmmffmff")
        .addMother("rmmmm", "rmmmmm")
        .addFather("rmmmmm", "rmmmmmf")
        .addMother("rmmmmm", "rmmmmmm")
        .addFather("rmmmmmm", "rmmmmmmf")
        .addMother("rmmmmmm", "rmmmmmmm")
        .addFather("rff", "rfff")
        .addMother("rff", "rffm")
        .addFather("rfff", "rffff")
        .addMother("rfff", "rfffm")
        .addFather("rffm", "rffmf")
        .addMother("rffm", "rffmm")
        .addFather("rffmm", "rffmmf")
        .addMother("rffmm", "rffmmm")
        .addFather("rmmff", "rmmfff")
        .addMother("rmmff", "rmmffm")
        .addFather("rmmffm", "rmmffmf")
        .addMother("rmmffm", "rmmffmm")
        .addFather("rmmfff", "rmmffff")
        .addMother("rmmfff", "rmmfffm")
        .addFather("rmmffff", "rmmfffff")
        .addMother("rmmffff", "rmmffffm");

    T.display();

    CHECK(T.relation("rm") == "mother");
    CHECK(T.relation("rf") == "father");

    CHECK(T.relation("rff") == "grandfather");
    CHECK(T.relation("rfm") == "grandmother");
    CHECK(T.relation("rmm") == "grandmother");
    CHECK(T.relation("rmf") == "grandfather");

    CHECK(T.relation("rfff") == "great-grandfather");
    CHECK(T.relation("rffm") == "great-grandmother");
    CHECK(T.relation("rmmf") == "great-grandfather");
    CHECK(T.relation("rmmm") == "great-grandmother");

    CHECK(T.relation("rffff") == "great-great-grandfather");
    CHECK(T.relation("rfffm") == "great-great-grandmother");
    CHECK(T.relation("rffmf") == "great-great-grandfather");
    CHECK(T.relation("rffmm") == "great-great-grandmother");
    CHECK(T.relation("rmmff") == "great-great-grandfather");
    CHECK(T.relation("rmmmf") == "great-great-grandfather");
    CHECK(T.relation("rmmmm") == "great-great-grandmother");

    CHECK(T.relation("rffmmf") == "great-great-great-grandfather");
    CHECK(T.relation("rffmmm") == "great-great-great-grandmother");
    CHECK(T.relation("rmmfff") == "great-great-great-grandfather");
    CHECK(T.relation("rmmffm") == "great-great-great-grandmother");
    CHECK(T.relation("rmmmmf") == "great-great-great-grandfather");
    CHECK(T.relation("rmmmmm") == "great-great-great-grandmother");

    CHECK(T.relation("rmmffff") == "great-great-great-great-grandfather");
    CHECK(T.relation("rmmfffm") == "great-great-great-great-grandmother");
    CHECK(T.relation("rmmffmf") == "great-great-great-great-grandfather");
    CHECK(T.relation("rmmffmm") == "great-great-great-great-grandmother");
    CHECK(T.relation("rmmmmff") == "great-great-great-great-grandfather");
    CHECK(T.relation("rmmmmfm") == "great-great-great-great-grandmother");
    CHECK(T.relation("rmmmmmf") == "great-great-great-great-grandfather");
    CHECK(T.relation("rmmmmmm") == "great-great-great-great-grandmother");

    CHECK(T.relation("rmmfffff") == "great-great-great-great-great-grandfather");
    CHECK(T.relation("rmmffffm") == "great-great-great-great-great-grandmother");
    CHECK(T.relation("rmmmmffm") == "great-great-great-great-great-grandmother");
    CHECK(T.relation("rmmmmmmf") == "great-great-great-great-great-grandfather");
    CHECK(T.relation("rmmmmmmm") == "great-great-great-great-great-grandmother");

    CHECK(T.relation("rmmmmffmf") == "great-great-great-great-great-great-grandfather");

    CHECK(T.relation("rmmmmffmff") == "great-great-great-great-great-great-great-grandfather");
    CHECK(T.relation("rmmmmffmfm") == "great-great-great-great-great-great-great-grandmother");

    CHECK(T.find("mr") == "r");

    CHECK(T.find("mother") == "rm");
    CHECK(T.find("father") == "rf");

    CHECK(T.find("grandfather") == "rm");
    CHECK(T.find("grandmother") == "rm");

    CHECK(T.find("great-grandfather") == "rm");
    CHECK(T.find("great-grandmother") == "rm");

    CHECK(T.find("great-great-grandfather") == "rm");
    CHECK(T.find("great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-great-grandfather") == "rm");

    CHECK(T.find("great-great-great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == "rm");

    //s
    CHECK(T.find("grandfather") == "rm");
    CHECK(T.find("grandmother") == "rm");

    CHECK(T.find("great-grandfather") == "rm");
    CHECK(T.find("great-grandmother") == "rm");

    CHECK(T.find("great-great-grandfather") == "rm");
    CHECK(T.find("great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-great-grandfather") == "rm");

    CHECK(T.find("great-great-great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == "rm");

    CHECK(T.find("grandfather") == "rm");
    CHECK(T.find("grandmother") == "rm");

    CHECK(T.find("great-grandfather") == "rm");
    CHECK(T.find("great-grandmother") == "rm");

    CHECK(T.find("great-great-grandfather") == "rm");
    CHECK(T.find("great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-great-grandfather") == "rm");

    CHECK(T.find("great-great-great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == "rm");

    CHECK(T.find("grandfather") == "rm");
    CHECK(T.find("grandmother") == "rm");

    CHECK(T.find("great-grandfather") == "rm");
    CHECK(T.find("great-grandmother") == "rm");

    CHECK(T.find("great-great-grandfather") == "rm");
    CHECK(T.find("great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-grandmother") == "rm");

    CHECK(T.find("great-great-great-great-great-great-grandfather") == "rm");

    CHECK(T.find("great-great-great-great-great-great-great-grandfather") == "rm");
    CHECK(T.find("great-great-great-great-great-great-great-grandmother") == "rm");
}