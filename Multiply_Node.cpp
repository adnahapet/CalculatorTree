//
//  Multiply_Node.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Multiply_Node.h"

Multiply_Node::Multiply_Node():
    Binary_Operator_Node()
{
   
}

int Multiply_Node::getPrecedence(void){
    return Precedence;
}

void Multiply_Node::accept(Expression_Node_Visitor &v){
    v.Visit_Multiply_Node(*this);
}