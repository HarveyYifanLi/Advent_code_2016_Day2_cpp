//
//  main.cpp
//  Handle_Input
//  Created by Yifan on 2017-01-09.
//  Copyright © 2017 Yifan. All rights reserved.
//
/* --- Day 2: Bathroom Security ---
 
 ---part 1---
 
 You arrive at Easter Bunny Headquarters under cover of darkness. However, you left in such a rush that you forgot to use the bathroom! Fancy office buildings like this one usually have keypad locks on their bathrooms, so you search the front desk for the code.
 
 "In order to improve security," the document you find says, "bathroom codes will no longer be written down. Instead, please memorize and follow the procedure below to access the bathrooms."
 
 The document goes on to explain that each button to be pressed can be found by starting on the previous button and moving to adjacent buttons on the keypad: U moves up, D moves down, L moves left, and R moves right. Each line of instructions corresponds to one button, starting at the previous button (or, for the first line, the "5" button); press whatever button you're on at the end of each line. If a move doesn't lead to a button, ignore it.
 
 You can't hold it much longer, so you decide to figure out the code as you walk to the bathroom. You picture a keypad like this:
 
 1 2 3
 4 5 6
 7 8 9
 Suppose your instructions are:
 
 ULL
 RRDDD
 LURDL
 UUUUD
 
 You start at "5" and move up (to "2"), left (to "1"), and left (you can't, and stay on "1"), so the first button is 1.
 Starting from the previous button ("1"), you move right twice (to "3") and then down three times (stopping at "9" after two moves and ignoring the third), ending up with 9.
 Continuing from "9", you move left, up, right, down, and left, ending with 8.
 Finally, you move up four times (stopping at "2"), then down once, ending with 5.
 So, in this example, the bathroom code is 1985.
 
 Your puzzle input is the instructions from the document you found at the front desk. What is the bathroom code? */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/* valid_button_value.cpp is to test whether we should carry out the next new instruction on the current button */
#include "valid_button_value.h"

using std::cout;
using std::endl;

const char FILE_NAME[] = "/Users/yifan/Desktop/Instruct_Doc.txt"; // define a const char array to hold the name of the file

int main() {
    
    FILE *in_file;   /* define input file */ // let in_file be the pointer of the type "to-the-FILE-class"
    
    /* character or EOF flag from input */
    char ch;
    
    in_file = fopen(FILE_NAME, "r");
    
    if (in_file == NULL) {
        printf("Cannot open %s\n", FILE_NAME);
        exit(8);
    }
    
    ch = fgetc(in_file); // Read the first character of the instruction file
                        // to kick-start the a-loop-and-a-half pattern.
    int button = 5; /* Starting button value */
    
    while (ch!=EOF) {
        
        
        /* search for newline char */
        
        while (ch != '\n'){
            
          if(ch == 'U'&& valid_button_value(button,ch)==true) button -= 3;
            
          else if (ch == 'D'&& valid_button_value(button,ch)==true) button += 3;
            
          else if (ch == 'L'&& valid_button_value(button,ch)==true) button -= 1;
            
          else if (ch == 'R'&& valid_button_value(button,ch)==true) button += 1;
           
          else button = button;
            
          ch = fgetc(in_file); // Read the next character/instruction
            
        }
        
        cout<<button<<endl;
        
        ch = fgetc(in_file); // Read the next line.
        
    }
    
    
    fclose(in_file);
    
    return 0;
}

