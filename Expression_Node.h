//
//  Expression_Node.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Expression_Node_h
#define Expression_Node_h

#include <string>

//#include "Expression_Node_Visitor.h"

class Expression_Node_Visitor;

class Expression_Node {
public:
    
    //Expression_Node(void);
    
    virtual ~Expression_Node(void);
    
    virtual void accept(Expression_Node_Visitor & v)=0;
    
};

#endif /* Expression_Node_h */
