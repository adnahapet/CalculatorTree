//
//  Binary_Operator_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Binary_Operator_Node_h
#define Binary_Operator_Node_h

#include <stdio.h>
#include <stdexcept>


#include "Expression_Node.h"
#include "Number_Node.h"

class Binary_Operator_Node : public Expression_Node {
    
public:
    
    Binary_Operator_Node(void);
    
    ~Binary_Operator_Node(void);
    
    virtual void accept(Expression_Node_Visitor & v)= 0;
    
    virtual int getPrecedence(void) = 0;
    
    int precedence;
    
    Expression_Node * left;
    Expression_Node * right;
    
};

#endif /* Binary_Operator_Command_h */
