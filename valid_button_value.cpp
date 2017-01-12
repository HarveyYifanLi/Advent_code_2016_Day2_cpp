//
//  valid_button_value.cpp
//  Handle_Input
//
//  Created by Yifan on 2017-01-09.
//  Copyright © 2017 Yifan. All rights reserved.
//

#include <stdio.h>

bool valid_button_value(int button, char ch){
    
    if (ch == 'U' && ((button-3) >= 1 && (button-3) <= 9)){
        
        return  true;
        
    }
    else if (ch == 'D' && ((button+3) >= 1 && (button+3) <= 9)){
        
        return  true;
        
    }
    else if (ch == 'L' && button !=4 && button !=7 && ((button-1) >= 1 && (button-1) <= 9)){
        
        return  true;
        
    }
    else if (ch == 'R' && button !=3 && button !=6 &&((button+1) >= 1 && (button+1) <= 9)){
        
        return  true;
        
    }
    return 0;
    
}
