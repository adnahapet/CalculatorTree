//
//  Multiply_Node.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Multiply_Node_h
#define Multiply_Node_h

#include <stdio.h>

#include "Binary_Operator_Node.h"
#include "Expression_Node_Visitor.h"

class Expression_Node_Visitor;

class Multiply_Node: public Binary_Operator_Node {
    
public:
    
    Multiply_Node();
    
    void accept (Expression_Node_Visitor & v);
 
    int getPrecedence(void);
    
 
    
    //static vars
    
    int Precedence = 2;
    

};


#endif /* Multiply_Node_h */
