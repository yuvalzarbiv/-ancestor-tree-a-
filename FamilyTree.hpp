#include <iostream>
#include <string>
using namespace std;

namespace family{
    struct Node{

        string name;
        Node* mother;
        Node* father;
        int rank;
        string relation;
        int gender;

        Node(string name){//:name(name), mother(nullptr), father(nullptr), rank(0), relation("") {}
        this->name = name;
        mother = nullptr;
        father = nullptr;
        rank = 0;
        relation = "me";
        gender = 0;
        }
    };

    class Tree{
        
        public:
        Node* root;

    public:
        Tree(string name){
            if (name == ""){
                throw("invalid input");
            }
            root = new Node(name);
        } 

        ~Tree();

        Tree& addFather(string child, string father);
        Tree& addMother(string child, string mother);
        string relation(string person);
        string find(string);
        void display();
        void remove(string person);
        Node* searchNode (Node* root, string name);
        Node* searchNodeByRelation (Node* root, string re);
        void destroyTree(Node* root);
    };


        

    }


