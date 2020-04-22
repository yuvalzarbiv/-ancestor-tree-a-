#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace family;
using namespace std;

TEST_CASE("test creat a family tree"){
    Tree root("shir");  

    CHECK_NOTHROW(root.addFather("shir", "haim"));
    CHECK_NOTHROW(root.addMother("shir", "roti"));
    CHECK_NOTHROW(root.addFather("haim", "yaakov"));
    CHECK_NOTHROW(root.addMother("haim", "naomi"));
    CHECK_NOTHROW(root.addFather("roti", "eyal"));
    CHECK_NOTHROW(root.addMother("roti", "shoshi"));
    CHECK_NOTHROW(root.addFather("yaakov", "yosi"));
    CHECK_NOTHROW(root.addMother("yaakov", "keren"));
    CHECK_NOTHROW(root.addFather("naomi", "kobi"));
    CHECK_NOTHROW(root.addMother("naomi", "orna"));
    CHECK_NOTHROW(root.addFather("eyal", "albert"));
    CHECK_NOTHROW(root.addMother("eyal", "orit"));
    CHECK_NOTHROW(root.addFather("shoshi", "asaf"));
    CHECK_NOTHROW(root.addMother("shoshi", "michal"));
    
	CHECK_THROWS(Tree T(""));
    

}

TEST_CASE("test relations"){
     Tree root("shir");
    CHECK_NOTHROW(root.addFather("shir", "haim"));
    CHECK_NOTHROW(root.addMother("shir", "roti"));
    CHECK_NOTHROW(root.addFather("haim", "yaakov"));
    CHECK_NOTHROW(root.addMother("haim", "naomi"));
    CHECK_NOTHROW(root.addFather("roti", "eyal"));
    CHECK_NOTHROW(root.addMother("roti", "shoshi"));
    CHECK_NOTHROW(root.addFather("yaakov", "yosi"));
    CHECK_NOTHROW(root.addMother("yaakov", "keren"));
    CHECK_NOTHROW(root.addFather("naomi", "kobi"));
    CHECK_NOTHROW(root.addMother("naomi", "orna"));
    CHECK_NOTHROW(root.addFather("eyal", "albert"));
    CHECK_NOTHROW(root.addMother("eyal", "orit"));
    CHECK_NOTHROW(root.addFather("shoshi", "asaf"));
    CHECK_NOTHROW(root.addMother("shoshi", "michal"));
    CHECK(root.relation("haim") == "father");
    CHECK(root.relation("roti") == "mother");
    CHECK(root.relation("yaakov") == "grandfather");
    CHECK(root.relation("naomi") == "grandmother");
    CHECK(root.relation("eyal") == "grandfather");
    CHECK(root.relation("shoshi") == "grandmother");
    CHECK(root.relation("yosi") == "great-grandfather");
    CHECK(root.relation("keren") == "great-grandmother");
    CHECK(root.relation("kobi") == "great-grandfather");
    CHECK(root.relation("orna") == "great-grandmother");
    CHECK(root.relation("albert") == "great-grandfather");
    CHECK(root.relation("orit") == "great-grandmother");
    CHECK(root.relation("asaf") == "great-grandfather");
    CHECK(root.relation("michal") == "great-grandmother");

    CHECK(root.relation("moshe") == "unrelated");
    CHECK(root.relation("shani") == "unrelated");
    
}

TEST_CASE("test find"){
     Tree root("shir");
   CHECK_NOTHROW(root.addFather("shir", "haim"));
    CHECK_NOTHROW(root.addMother("shir", "roti"));
    CHECK_NOTHROW(root.addFather("haim", "yaakov"));
    CHECK_NOTHROW(root.addMother("haim", "naomi"));
    CHECK_NOTHROW(root.addFather("roti", "eyal"));
    CHECK_NOTHROW(root.addMother("roti", "shoshi"));
    CHECK_NOTHROW(root.addFather("yaakov", "yosi"));
    CHECK_NOTHROW(root.addMother("yaakov", "keren"));
    CHECK_NOTHROW(root.addFather("naomi", "kobi"));
    CHECK_NOTHROW(root.addMother("naomi", "orna"));
    CHECK_NOTHROW(root.addFather("eyal", "albert"));
    CHECK_NOTHROW(root.addMother("eyal", "orit"));
    CHECK_NOTHROW(root.addFather("shoshi", "asaf"));
    CHECK_NOTHROW(root.addMother("shoshi", "michal"));

    CHECK(root.find("mother") == "roti");
    CHECK(root.find("father") == "haim");
    CHECK(root.find("grandmother") == "naomi");
    CHECK(root.find("grandmother") == "shoshi");
    CHECK(root.find("grandfather") == "yaakov");
    CHECK(root.find("grandfather") == "eyal");
    CHECK(root.find("great-grandfather") == "kobi");
    CHECK(root.find("great-grandmother") == "orna");
    CHECK(root.find("great-great-grandfather") == "asaf");
    CHECK(root.find("great-great-grandmother") == "michal");
    CHECK(root.find("great-grandfather") == "yosi");
    CHECK(root.find("great-grandmother") == "keren");
    CHECK(root.find("great-grandfather") == "albert");
    CHECK(root.find("great-grandmother") == "orit");
    CHECK(root.find("great-great-grandfather") == "asaf");
    CHECK(root.find("great-great-grandmother") == "michal");

    CHECK(root.find("great-great-great-grandmother") == "notfound");
    CHECK(root.find("great-great-great-grandfather") == "notfound");



}

TEST_CASE("remove than relation"){
     Tree root("shir");
   CHECK_NOTHROW(root.addFather("shir", "haim"));
    CHECK_NOTHROW(root.addMother("shir", "roti"));
    CHECK_NOTHROW(root.addFather("haim", "yaakov"));
    CHECK_NOTHROW(root.addMother("haim", "naomi"));
    CHECK_NOTHROW(root.addFather("roti", "eyal"));
    CHECK_NOTHROW(root.addMother("roti", "shoshi"));
    CHECK_NOTHROW(root.addFather("yaakov", "yosi"));
    CHECK_NOTHROW(root.addMother("yaakov", "keren"));
    CHECK_NOTHROW(root.addFather("naomi", "kobi"));
    CHECK_NOTHROW(root.addMother("naomi", "orna"));
    CHECK_NOTHROW(root.addFather("eyal", "albert"));
    CHECK_NOTHROW(root.addMother("eyal", "orit"));
    CHECK_NOTHROW(root.addFather("shoshi", "asaf"));
    CHECK_NOTHROW(root.addMother("shoshi", "michal"));
    root.remove("albert");
    root.remove("kobi");
    root.remove("orna");
    root.remove("keren");
    root.remove("yosi");
    root.remove("shoshi");
    root.remove("eyal");
    root.remove("naomi");
    root.remove("yaakov");
    root.remove("roti");
    root.remove("haim");
    CHECK(root.relation("albert") == "unrelated");
    CHECK(root.relation("kobi") == "unrelated");
    CHECK(root.relation("orna") == "unrelated");
    CHECK(root.relation("keren") == "unrelated");
    CHECK(root.relation("yosi") == "unrelated");
    CHECK(root.relation("shoshi") == "unrelated");
    CHECK(root.relation("eyal") == "unrelated");
    CHECK(root.relation("naomi") == "unrelated");
    CHECK(root.relation("yaakov") == "unrelated");
    CHECK(root.relation("roti") == "unrelated");
    CHECK(root.relation("haim") == "unrelated");
}   



