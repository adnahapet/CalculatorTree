#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>


#include "Expression_Node.h"
#include "Math_Expression.h"
#include "Delete_Expression_Tree.h"

class Expression_Tree:public Math_Expression
{
    public:
    
        //default constructor
        Expression_Tree();
    
        // destructor that works recursively
        ~Expression_Tree();
    
    
    Expression_Node * root;
    
};




#endif // EXPRESSION_TREE_H
