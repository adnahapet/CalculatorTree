//
//  Mod_Node.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Mod_Node_h
#define Mod_Node_h

#include <stdio.h>
#include <iostream>

#include "Binary_Operator_Node.h"
#include "Expression_Node_Visitor.h"

class Expression_Node_Visitor;

class Mod_Node: public Binary_Operator_Node{
    
public:
    
    Mod_Node();
    
    void accept (Expression_Node_Visitor & v);
    
    int getPrecedence(void);
    
    //static vars
    
    int Precedence = 2;
    
    
};


#endif /* Mod_Command_hpp */
