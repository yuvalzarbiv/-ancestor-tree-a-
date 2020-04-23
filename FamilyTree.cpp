#include "FamilyTree.hpp"

using namespace std;
using namespace family;



    Tree& Tree::addFather(string child, string father)
    {
        Node* nchild = this->searchNode(this->root, child);
        if (nchild == nullptr){
            throw("the child "+child+ " does not exist");
        }
        else if (this->searchNode(this->root,father) != nullptr){
            throw("name is already exist");
        }
        else if (nchild->father != nullptr){
            throw("this child alresdy has a father");
        }
        else {
            nchild->father = new Node(father);
            nchild->father->gender=1;
            int r = nchild->rank;
            nchild->father->rank = r+1;
            if(nchild->father->rank == 1){
                nchild->father->relation = "father";
            }
            else if(nchild->father->rank == 2){
                nchild->father->relation = "grandfather";
            }
            else {
                 nchild->father->relation = "grandfather";
                for (int i = 2; i < nchild->father->rank; i++){
                    nchild->father->relation = "great-"+nchild->father->relation;         
                }
            }

        }
        return *this;
    }
    Tree& Tree::addMother(string child, string mother)
    {
        Node* nchild = this->searchNode(this->root,child);
        if (nchild == nullptr){
            throw("the child "+child+" does not exist");
        }
        else if (this->searchNode(this->root,mother) != nullptr){
            throw("name is already exist");
        }
        else if (nchild->mother != nullptr){
            throw("this child alresdy has a mother");
        }
        else {
            nchild->mother = new Node(mother);
            nchild->mother->gender=2;
            nchild->mother->rank = nchild->rank+1;
            if(nchild->mother->rank == 1){
                nchild->mother->relation = "mother";
            }
            else if(nchild->mother->rank == 2){
                nchild->mother->relation = "grandmother";
            }
            else {
                nchild->mother->relation = "grandmother";
                for (int i = 2; i < nchild->mother->rank; i++ ){
                    nchild->mother->relation = "great-"+nchild->mother->relation;         
                }
            }
        }
        return *this;   
    }

    string Tree::relation(string person)
    {
        Node* temp = this->searchNode(this->root,person);
        if (temp == nullptr){
            return "unrelated";
        }
        else return temp->relation;
    }

    string Tree::find(string relation)
    {
      Node* temp = this->searchNodeByRelation(this->root,relation);
      if (temp == nullptr){
            throw("this relation does not exist");
        }
      else return temp->name;
    }
    

    void printtree(Node* root){

        if (!root) return;

        printtree(root->mother);

        for (int i = 0; i < root->rank; i++){
             cout << "        ";
        }

        cout << root->name << "\n\n";

        printtree(root->father);

    }

    void Tree::display()
    {
        printtree(this->root);
    }
    

    void Tree::remove(string person)
    {   
        if (this->root->name == person){
            throw("you can not delet the root");
        }
        Node* temp = this->searchNode(this->root,person);
        if (temp == nullptr){
            throw("this person does not exist");
        }
        else{
            
            destroyTree(temp);
        }

    }
    Tree::~Tree()
    {
        destroyTree(this->root);
    }

    void Tree::destroyTree(Node* root){
	if (root != nullptr){
		destroyTree(root->father);
		destroyTree(root->mother);
		delete root;
	}
}

    Node* Tree::searchNode(Node* root, string name) {

        Node* temp=new Node("");
        if (root==NULL){
            return root;
        }
        if (root->name == name){
            return root;
        }
        else{
            temp=searchNode(root->father,name);
        
            if(temp==NULL){
            
             temp=searchNode(root->mother,name);
            }
        }
        return temp;
        
    }
    
    Node* Tree::searchNodeByRelation(Node* root, string re) {

         Node* temp=new Node("");
        if (root==NULL){
            return root;
        }
        if (root->relation == re){
            return root;
        }
        else{
            temp=searchNodeByRelation(root->father,re);
        
            if(temp==NULL){
            
             temp=searchNodeByRelation(root->mother,re);
            }
        }
        return temp;
    }
    
   
