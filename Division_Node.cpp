//
//  Division_Node.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Division_Node.h"
#include "Expression_Node_Visitor.h"

Division_Node::Division_Node():
    Binary_Operator_Node()
{
    
}

int Division_Node::getPrecedence(void){
    return Precedence;
}

void Division_Node::accept(Expression_Node_Visitor &v){
    v.Visit_Division_Node(*this);
}