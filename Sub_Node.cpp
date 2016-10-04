//
//  Sub_Node.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Sub_Node.h"


Sub_Node::Sub_Node():
    Binary_Operator_Node()
{
   
}

void Sub_Node::accept(Expression_Node_Visitor &v){
    v.Visit_Sub_Node(*this);
}

int Sub_Node::getPrecedence(void){
    return Precedence;
}


