#include <iostream>
#include <string>
using namespace std;

namespace family{
    class Node{

        private:
        string name;
        Node* mother;
        Node* father;
        int rank;

        public:
        Node(string name):name(name), mother(nullptr), father(nullptr), rank(0) {}

    };

    class Tree{

        private:
        Node root;

        public:
        Tree(string name):root(Node(name)){}
        ~Tree();

        Tree& addFather(string child, string father);
        Tree& addMother(string child, string mother);
        string relation(string person);
        string find(string);
        void display();
        void remove(string person);
    };


        

    }


