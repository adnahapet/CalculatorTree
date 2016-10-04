//
//  Number_Node.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Number_Node.h"
#include "Expression_Node_Visitor.h"


Number_Node::Number_Node(int value):
    n_(value)
{
    
}


void Number_Node::accept(Expression_Node_Visitor &v){
    
        v.Visit_Number_Node (*this);
}