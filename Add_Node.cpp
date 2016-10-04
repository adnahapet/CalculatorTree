//
//  Add_Node.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Add_Node.h"

Add_Node::Add_Node():
    Binary_Operator_Node()
{

}

int Add_Node::getPrecedence(void){
    return Precedence;
}

void Add_Node::accept(Expression_Node_Visitor &v){
    v.Visit_Addition_Node(*this);
}



