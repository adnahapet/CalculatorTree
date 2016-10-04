//
//  Number_Node.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Number_Node_h
#define Number_Node_h

#include <stdio.h>
#include <string>


#include "Expression_Node.h"


class Expression_Node_Visitor;

class Number_Node: public Expression_Node {
    
public:
    
    Number_Node (int n);
    
    void accept (Expression_Node_Visitor & v);

    int evaluate(void);
    
    
    int n_;
    
    
};

#endif /* Number_Command_h */
