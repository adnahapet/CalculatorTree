//
//  Expression_Node_Visitor.h
//  TreeCalculator
//
//  Created by Armen Nahapetian on 4/2/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Expression_Node_Visitor_h
#define Expression_Node_Visitor_h

#include <stdio.h>

class Add_Node;
class Number_Node;
class Division_Node;
class Mod_Node;
class Multiply_Node;
class Sub_Node;

class Expression_Node_Visitor{
    
public:
    
    virtual ~Expression_Node_Visitor (void);
    
    // Methods for visiting concrete nodes
    
    virtual void Visit_Addition_Node (const Add_Node & node) = 0;
    virtual void Visit_Number_Node (const Number_Node & node) = 0;
    virtual void Visit_Division_Node (const Division_Node & node) =0;
    virtual void Visit_Mod_Node (const Mod_Node & node) = 0;
    virtual void Visit_Sub_Node (const Sub_Node & node) = 0;
    virtual void Visit_Multiply_Node (const Multiply_Node & node) = 0;
    
};



#endif /* Expression_Node_Visitor_h */
