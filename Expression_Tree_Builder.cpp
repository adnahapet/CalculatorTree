//
//  Expression_Tree_Builder.cpp
//  TreeCalc
//
//  Created by Armen Nahapetian on 4/3/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Expression_Tree_Builder.h"

Expression_Tree_Builder::Expression_Tree_Builder(void){
    
}

Expression_Tree_Builder::~Expression_Tree_Builder(void){
	delete this->tree_;
}

// initializes new expression tree, deletion of individual nodes on tree will be handled by a recursive call in tree destructor
void Expression_Tree_Builder::start_expression (void){
    
    this->tree_ =  new Expression_Tree;
    
}

//builds new number node and pushes to postfix stack
void Expression_Tree_Builder::build_number (int n){
    
    Number_Node * newNode = new Number_Node(n);
    childStack.push(newNode);
}


//creates new node and handles placement
void Expression_Tree_Builder::build_add_operand (void){
    
    Add_Node * newNode = new Add_Node();
    handle_operand(newNode);
   
}


//creates new node and handles placement
void Expression_Tree_Builder::build_subtract_operand (void){
    
    Sub_Node * newNode = new Sub_Node();
    handle_operand(newNode);
    
}

//creates new node and handles placement
void Expression_Tree_Builder::build_division_operand(void){
    
    Division_Node * newNode = new Division_Node();
    handle_operand(newNode);
    
}

//creates new node and handles placement
void Expression_Tree_Builder::build_multiply_operand(void){
    
    Multiply_Node * newNode = new Multiply_Node();
    handle_operand(newNode);
    
}

//creates new node and handles placement
void Expression_Tree_Builder::build_mod_operand(void){
    
    Mod_Node * newNode = new Mod_Node();
    handle_operand(newNode);
    
}


//handles placement of node
//assigns left and right children for parents and then pushes them into the child stack if necessary
void Expression_Tree_Builder::handle_operand(Binary_Operator_Node * newNode){
    
    if(parentStack.is_empty() == true){
        parentStack.push(newNode);
    }
    else if (parentStack.top()->getPrecedence() < newNode->getPrecedence()){
        parentStack.push(newNode);
    }
    else {
        while(parentStack.is_empty() == false && parentStack.top()->getPrecedence() >= newNode->getPrecedence()){
            Binary_Operator_Node * currentNode = parentStack.pop();
            currentNode->right = childStack.pop();
            currentNode->left = childStack.pop();
            childStack.push(currentNode);

        }
        parentStack.push(newNode);
    }
    
}


//finalizes build of tree and returns pointer to it
//clears nodeStack of low precedence operators if necessary
Expression_Tree* Expression_Tree_Builder::get_expression(void){
    
    Binary_Operator_Node * currentNode;
    
    while(parentStack.is_empty()==false){
        
        currentNode = parentStack.pop();
        tree_->root = currentNode;
        currentNode->right = childStack.pop();
        currentNode->left = childStack.pop();
        childStack.push(currentNode);
        
    }
    
    //catches case where the entire input is contained within parenthesis and was parsed exclusively as a subexpression
    if(tree_->root == nullptr){
        tree_->root = childStack.top();
    }
    
    return tree_;
}
