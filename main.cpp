//
//  main.cpp
//  Handle_Input_part2
//
//  Created by Yifan on 2017-01-09.
//  Copyright © 2017 Yifan. All rights reserved.
//
/*
 --- Day 2: Bathroom Security ---
 --- Part Two ---
 You finally arrive at the bathroom (it's a several minute walk from the lobby so visitors can behold the many fancy conference rooms and water coolers on this floor) and go to punch in the code. Much to your bladder's dismay, the keypad is not at all like you imagined it. Instead, you are confronted with the result of hundreds of man-hours of bathroom-keypad-design meetings:
     1
   2 3 4
 5 6 7 8 9
   A B C
     D
 You still start at "5" and stop when you're at an edge, but given the same instructions as above, the outcome is very different:
 You start at "5" and don't move at all (up and left are both edges), ending at 5.
 Continuing from "5", you move right twice and down three times (through "6", "7", "B", "D", "D"), ending at D.
 Then, from "D", you move five more times (through "D", "B", "C", "C", "B"), ending at B.
 Finally, after five more moves, you end at 3.
 So, given the actual keypad layout, the code would be 5DB3.
 Using the same instructions in your puzzle input, what is the correct bathroom code?
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

const char FILE_NAME[] = "/Users/yifan/Desktop/Instruct_Doc.txt";
/* set const variables for the specific matrix to be defined in main() */
const int row_size = 5;
const int coln_size = 5;

/* function valid_button() checks if we were to execute the next instruction based upon the current button value
 returning true if it's not gonna go to fall at the edge*/

bool valid_button(char keypad[][coln_size],int r,int c,char ch){
    
    if (ch == 'U' && !(keypad[r-1][c] == ' ') && ((r-1)>=0 && (r-1)<=4) &&(c>=0 && c<=4)){
        
        return  true;
    }
    
    
    else if (ch == 'D' && !(keypad[r+1][c] == ' ')&& ((r+1)>=0 && (r+1)<=4) &&(c>=0 && c<=4)){
        
        return  true;
    }
    
    else if (ch == 'L' && !(keypad[r][c-1] == ' ')&& (r>=0 && r<=4) &&((c-1)>=0 && (c-1)<=4)){
        
        return  true;
    }
    
    else if (ch == 'R' && !(keypad[r][c+1] == ' ')&& (r>=0 && r<=4) &&((c+1)>=0 && (c+1)<=4) ){
        
        return  true;
    }
    
    return 0;
    
}

int main() {
    
    FILE *in_file;   /* define input file */
    
    /* character or EOF flag from input */
    char ch;
    
    in_file = fopen(FILE_NAME, "r");
    
    if (in_file == NULL) {
        printf("Cannot open %s\n", FILE_NAME);
        exit(8);
    }
    
    char keypad [row_size][coln_size]; // Put the keypad in a 5x5 matrix
    
    /* Initialize the matrix with ' ' for each entry */
    for (int i=0; i != row_size; ++i){
        
        for (int j=0; j != coln_size; ++j){
            keypad[i][j] = ' ';
        }
    }
    
    /* Define the absolute positions (in the matrix) of those buttons */
    keypad[0][2] = '1';
    keypad[1][1] = '2';
    keypad[1][2] = '3';
    keypad[1][3] = '4';
    keypad[2][0] = '5';
    keypad[2][1] = '6';
    keypad[2][2] = '7';
    keypad[2][3] = '8';
    keypad[2][4] = '9';
    keypad[3][1] = 'A';
    keypad[3][2] = 'B';
    keypad[3][3] = 'C';
    keypad[4][2] = 'D';
    
    
    ch = fgetc(in_file); // Read the first character of the instruction file
    // to kick-start the a-loop-and-a-half pattern.
    int r = 2;
    int c = 0;
    char button = keypad[r][c];
    
    while (ch!=EOF) {
        
        /* search for newline char */
        while (ch != '\n'){
            
                          /* recall that function valid_button() checks if we were to execute the next instruction */
            
            if (ch == 'U' && valid_button(keypad,r,c,ch)==true)
                r -= 1;
            
            else if (ch == 'D' && valid_button(keypad,r,c,ch)==true)
                r += 1;
            
            else if (ch == 'L' && valid_button(keypad,r,c,ch)==true)
                c -= 1;
            
            else if (ch == 'R' && valid_button(keypad,r,c,ch)==true)
                c += 1;
            
            else {};
            
            button = keypad[r][c]; // update the button value.
            ch = fgetc(in_file); // Read the next character/instruction
            
        } // end of inner while
        
        cout<<button<<endl;
        
        ch = fgetc(in_file); // Read the next line.
        
    }
    
    fclose(in_file);
    return 0;
    
}













