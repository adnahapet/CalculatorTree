//
//  Add_Node.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Add_Node_h
#define Add_Node_h

#include <stdio.h>

#include "Binary_Operator_Node.h"
#include "Expression_Node_Visitor.h"

class Expression_Node_Visitor;

class Add_Node: public Binary_Operator_Node {

public:
    
    Add_Node();
    
    void accept (Expression_Node_Visitor & v);
    
    int getPrecedence(void);
    
    //static vars
    
	int Precedence = 1;
    
};

#endif /* Add_Node_h */
