//
//  Calculator.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <memory>

#include "Stack.h"
#include "Array.h"
#include "Array_Iterator.h"
#include "Expression_Builder.h"
#include "Expression_Tree_Builder.h"
#include "Evaluate_Expression_Tree.h"

class Calculator{
    
public:
    
    //constructors and methods
    Calculator();
    
    //destructor
    ~Calculator();
    
    //gets string input from user
    void getExpression();
    
    //validates expression balance and checks for invalid arguments
    bool validator(std::string input);
    
    //takes user input and converts it to postfix
    int evaluate_expression(const std::string & infix);
    
    bool parse_expression(const std::string & infix, Expression_Builder &b);
    

    
    
    //member variables
    
    std::string input;
    
};


#endif /* Calculator_h */
