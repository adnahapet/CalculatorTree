//
//  Evaluate_Expression_Tree.cpp
//  TreeCalculator
//
//  Created by Armen Nahapetian on 4/2/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Evaluate_Expression_Tree.h"

Evaluate_Expression_Tree::Evaluate_Expression_Tree(){
    
}

Evaluate_Expression_Tree::~Evaluate_Expression_Tree(){
    
}

//pushes value contained in node onto a stack
void Evaluate_Expression_Tree::Visit_Number_Node(const Number_Node &node){
    calculator.push(node.n_);
}


//nodes use the same recursive call and pop 2 and push method
void Evaluate_Expression_Tree::Visit_Addition_Node(const Add_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    int n2 = calculator.pop();
    int n1 = calculator.pop();
    int result = n1+n2;
    
    calculator.push(result);
}

//nodes use the same recursive call and pop 2 and push method
void Evaluate_Expression_Tree::Visit_Mod_Node(const Mod_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    int n2 = calculator.pop();
    if (n2 == 0)
        throw divide_by_zero_exception();
    int n1 = calculator.pop();
    int result = n1%n2;
    
    calculator.push(result);
}

//nodes use the same recursive call and pop 2 and push method
void Evaluate_Expression_Tree::Visit_Sub_Node(const Sub_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    int n2 = calculator.pop();
    int n1 = calculator.pop();
    int result = n1 - n2;
    
    calculator.push(result);
}

//nodes use the same recursive call and pop 2 and push method
void Evaluate_Expression_Tree::Visit_Division_Node(const Division_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    int n2 = calculator.pop();
    if (n2 == 0)
        throw divide_by_zero_exception();
    int n1 = calculator.pop();
    int result = n1/n2;
    
    calculator.push(result);
}

//nodes use the same recursive call and pop 2 and push method
void Evaluate_Expression_Tree::Visit_Multiply_Node(const Multiply_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    int n2 = calculator.pop();
    int n1 = calculator.pop();
    int result = n1*n2;
    
    calculator.push(result);
}


int Evaluate_Expression_Tree::result(void){
    
    return calculator.pop();
    
}