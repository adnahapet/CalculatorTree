//
//  Sub_Node.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Sub_Node_h
#define Sub_Node_h

#include <stdio.h>

#include "Binary_Operator_Node.h"
#include "Expression_Node_Visitor.h"

class Expression_Node_Visitor;

class Sub_Node: public Binary_Operator_Node {
    
public:
    
    Sub_Node();
    
    void accept(Expression_Node_Visitor & v);
    
    int getPrecedence(void);
    
    //static vars
    
    int Precedence = 1;
    
    
};


#endif /* Sub_Node_hpp */
