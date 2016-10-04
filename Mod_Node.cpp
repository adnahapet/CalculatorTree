//
//  Mod_Node.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Mod_Node.h"

Mod_Node::Mod_Node():
    Binary_Operator_Node()
{
    
}


int Mod_Node::getPrecedence(void){
    return Precedence;
}


void Mod_Node::accept(Expression_Node_Visitor &v){
    v.Visit_Mod_Node(*this);
}