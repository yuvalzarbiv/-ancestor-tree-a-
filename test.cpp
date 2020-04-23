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

// TEST_CASE("test find"){
//      Tree root("shir");
//    CHECK_NOTHROW(root.addFather("shir", "haim"));
//     CHECK_NOTHROW(root.addMother("shir", "roti"));
//     CHECK_NOTHROW(root.addFather("haim", "yaakov"));
//     CHECK_NOTHROW(root.addMother("haim", "naomi"));
//     CHECK_NOTHROW(root.addFather("roti", "eyal"));
//     CHECK_NOTHROW(root.addMother("roti", "shoshi"));
//     CHECK_NOTHROW(root.addFather("yaakov", "yosi"));
//     CHECK_NOTHROW(root.addMother("yaakov", "keren"));
//     CHECK_NOTHROW(root.addFather("naomi", "kobi"));
//     CHECK_NOTHROW(root.addMother("naomi", "orna"));
//     CHECK_NOTHROW(root.addFather("eyal", "albert"));
//     CHECK_NOTHROW(root.addMother("eyal", "orit"));
//     CHECK_NOTHROW(root.addFather("shoshi", "asaf"));
//     CHECK_NOTHROW(root.addMother("shoshi", "michal"));

//     CHECK(root.find("mother") == "roti");
//     CHECK(root.find("father") == "haim");
//     CHECK(root.find("grandmother") == "naomi");
//     CHECK(root.find("grandmother") == "shoshi");
//     CHECK(root.find("grandfather") == "yaakov");
//     CHECK(root.find("grandfather") == "eyal");
//     CHECK(root.find("great-grandfather") == "kobi");
//     CHECK(root.find("great-grandmother") == "orna");
//     CHECK(root.find("great-great-grandfather") == "asaf");
//     CHECK(root.find("great-great-grandmother") == "michal");
//     CHECK(root.find("great-grandfather") == "yosi");
//     CHECK(root.find("great-grandmother") == "keren");
//     CHECK(root.find("great-grandfather") == "albert");
//     CHECK(root.find("great-grandmother") == "orit");
//     CHECK(root.find("great-great-grandfather") == "asaf");
//     CHECK(root.find("great-great-grandmother") == "michal");

//     CHECK(root.find("great-great-great-grandmother") == "notfound");
//     CHECK(root.find("great-great-great-grandfather") == "notfound");



// }

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

////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Test 1 remove") {

    Tree T ("Maya");
    T.addMother("Maya", "Anat").addFather("Maya", "Rami")
     .addMother("Anat", "Rivka").addFather("Anat", "Yoni")
     .addMother("Yoni", "Vered").addFather("Yoni", "Shlomi")
     .addFather("Rami", "David");

    //CHECK_THROWS(T.remove("Maya")); //try to remove the root --> exception

    CHECK((T.find("grandfather") == string("David") || T.find("grandfather") == string("Yoni")));

    CHECK(T.find("father") == string("Rami"));
    T.remove("Rami"); 
    CHECK_THROWS(T.find("father")); // removed the father
    CHECK(T.find("grandfather") == string("Yoni")); //because David has removed from the tree while removing Rami

    CHECK(T.find("great-grandmother") == string("Vered")); 
    CHECK(T.find("great-grandfather") == string("Shlomi")); 
    T.remove("Vered");
    CHECK_THROWS(T.find("great-grandmother"));
    T.remove("Yoni");
    CHECK_THROWS(T.find("great-grandfather"));
    CHECK_THROWS(T.find(T.find("grandfather")));

    T.addFather("Anat", "Nir"); //we've removed Yoni, sowe can add new father to Anat now
    CHECK(T.find("grandfather") == string("Nir")); 
    CHECK(T.find("grandmother") == string("Rivka"));
    T.remove("Rivka"); 
    CHECK_THROWS(T.find("grandmother")); 
    T.remove("Anat"); 
    CHECK_THROWS(T.find("grandfather")); 
    CHECK_THROWS(T.find("mother"));
}

TEST_CASE("Test 2 remove"){
    Tree T ("Omri");
    T.addMother("Omri", "Hanna").addFather("Omri", "Omer")
     .addMother("Hanna", "Rachel").addFather("Hanna", "Loren")
     .addMother("Loren", "Calanit").addFather("Loren", "Moky")
     .addFather("Omer", "Nadav");

    CHECK_THROWS(T.remove("Omri")); //try to remove the root --> exception

    CHECK((T.find("grandfather") == string("Nadav") || T.find("grandfather") == string("Loren")));

    CHECK(T.find("father") == string("Omer"));
    T.remove("Omer"); 
    CHECK_THROWS(T.find("father"));
    CHECK(T.find("grandfather") == string("Loren")); // Nadav has removed from the tree while removing Omer

    CHECK(T.find("great-grandmother") == string("Calanit")); 
    CHECK(T.find("great-grandfather") == string("Moky")); 
    T.remove("Calanit");
    CHECK_THROWS(T.find("great-grandmother"));
    T.remove("Loren");
    CHECK_THROWS(T.find("great-grandfather"));
    CHECK_THROWS(T.find(T.find("grandfather")));

    T.addFather("Hanna", "Nissan"); //removed Loren, sowe can add new father to Hanna now
    CHECK(T.find("grandfather") == string("Nissan")); 
    CHECK(T.find("grandmother") == string("Rachel"));
}
