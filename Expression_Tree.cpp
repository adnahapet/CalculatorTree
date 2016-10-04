#include "Expression_Tree.h"


//basic void constructor that sets the root pointer to nullptr
//the rest of Binary Tree methods are called from Main()
Expression_Tree::Expression_Tree():
    root(nullptr)
{

}

//default destructor uses recursive call to removeNode with root pointer as initial parameter
//created a visitor for this purpose
Expression_Tree::~Expression_Tree()
{
    Delete_Expression_Tree del;
    this->root->accept(del);
	delete root;
}





