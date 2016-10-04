//
//  Expression_Builder.h
//  TreeCalc
//
//  Created by Armen Nahapetian on 4/3/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Expression_Builder_h
#define Expression_Builder_h

#include <stdio.h>
#include "Math_Expression.h"

class Expression_Builder{
    
public:
    
    Expression_Builder(void);
    ~Expression_Builder();
   
    
    virtual void start_expression (void)=0;
    virtual void build_number (int n) = 0;
    virtual void build_add_operand (void) = 0;
    virtual void build_subtract_operand (void) = 0;
    virtual void build_division_operand (void) = 0;
    virtual void build_multiply_operand (void) = 0;
    virtual void build_mod_operand (void) = 0;

    
    // get the current expression
    virtual Math_Expression * get_expression (void) = 0;
  
};
#endif /* Expression_Builder_h */
