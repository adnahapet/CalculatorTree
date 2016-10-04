//
//  Expression_Tree_Builder.h
//  TreeCalc
//
//  Created by Armen Nahapetian on 4/3/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Expression_Tree_Builder_h
#define Expression_Tree_Builder_h

#include <stdio.h>
#include <iostream>

#include "Expression_Builder.h"
#include "Expression_Tree.h"
#include "Expression_Node.h"

#include "Binary_Operator_Node.h"
#include "Add_Node.h"
#include "Number_Node.h"
#include "Division_Node.h"
#include "Multiply_Node.h"
#include "Sub_Node.h"
#include "Mod_Node.h"

#include "Stack.h"

class Expression_Tree_Builder: public Expression_Builder{
    
public:
    // ...
    Expression_Tree_Builder(void);
    
    void start_expression (void);
    
    
    void build_number (int n);
    void build_add_operand (void);
    void build_subtract_operand (void);
    void build_division_operand (void);
    void build_multiply_operand (void);
    void build_mod_operand (void);

    void handle_operand(Binary_Operator_Node * newNode);
    
    // get the current expression
    Expression_Tree * get_expression (void);
    
private:
   
    Expression_Tree  * tree_;
    
    
    Stack <Binary_Operator_Node *> parentStack;
    Stack <Expression_Node *> childStack;
    

    
};

#endif /* Expression_Tree_Builder_hpp */
