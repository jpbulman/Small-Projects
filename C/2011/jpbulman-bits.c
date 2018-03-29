/* * CS:APP Data Lab
 *
 * JP Bulman jpbulman
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  //Alternating 01010101
  int mask = 0x55;
  //Push it down further each time until it hits the end
  int mask1 = mask << 24;
  int mask2 = mask << 16;
  int mask3 = mask << 8;
  return mask | mask1 | mask2 | mask3;

}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //If the inverse of max is 1000000..000 so it !~max will be 0 and then ~0 will be 1111111...1111
  //That plus the inverse of max xor'ed will only be 0 if x is the max, then the ! will return 1, otherwise 0
  return !(x^(~x+~!~x));

}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //The left side of DeMorgan's law
  int left = ~x & y;
  //Right side
  int right = x & ~y;

  //expand the xor expression (from the slides) and then plug in the law
  return (~(~left & ~right));
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //If x is going to be true 1 if true 0 if false
  int cond = (!!x<<31)>>31;

  //return y if x is true, and if cond is false, then return z
  return (cond&y)|(~cond&z);
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) {

  //If the number is negative
  int isNeg = x>>31;

  int nonNeg;

  //Convert the number so bits to the right of the greatest bit are 1
  x = x | x>>1;
  x = x | x>>2;
  x = x | x>>4;
  x = x | x>>8;
  x = x | x>>16;

  //the solution for positive numbers, isolates the greatest bit by itself
  nonNeg = x^(x>>1);

  //If the number is negative, return t min, otherwise return the positive solution
  return (isNeg&(1<<31))|(~isNeg&nonNeg);
}

/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  //If x is negative
  int isNeg = x >> 31;

  //All positive numbers can be solved this way
  int a = (x>>n);
  //If x is the minimum
  int xIsMin = ((!(x<<1))<<31)>>31;

  //If it is negative and the min, do the normal, else take the complement, shift, and then complement back, or if it is positive, then just shift n amount (the normal)
  return (isNeg& (((xIsMin&a)|(~xIsMin& ((~((~x+1)>>n))+1) ))) )|(~isNeg&a);
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {

  //Shifts the number all the way to the right
  int y = x>>31;

  //If the number is negative, then y will be 111...11, and !y will return 0
  //If the number is positive, then y will be 000...00, and !y will return 1
  return !y;

}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
  //The sum of 3 x's
  int sum = x+x+x;

  //The original sign of x
  int originalSign = x>>31;
  //The sign of the sum (if the sum is negative then it will be all 1's, but that's fine, as long as it's not 0)
  int newSign = ((sum)>>31);

  //The sign when you add x and x together
  int oNewS = ((x+x)>>31);

  //If there was a sign change when you do x+x or x+x+x then there was a change, otherwise there will not have been a sign change
  int wasChange = (((originalSign^newSign)<<31)>>31)|(((originalSign^oNewS)<<31)>>31);

  //If x was originally negative
  int wasOrgNeg = (originalSign<<31)>>31;

  int min = 1<<31;

  //If there was a sign change at any point in the addition, then there was an overflow
  //So, if there was a change, then return min if the original was negative, max if positive, and then if there was no overflow at all, just return the sum
  return (wasChange & ((wasOrgNeg&min)|(~wasOrgNeg&(~(min)))) ) | (~wasChange&(sum));

}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //Sign of x (negative will be 1111...11)
  int xNeg = x>>31;
  //Same for y
  int yNeg = y>>31;

  //If x and y have the same sign
  int sameSign = !(xNeg^yNeg);

  //If x is bigger than -y-1
  int xIsBigger = ((~y+x)>>31);

  //If they are equal
  int areEqual = (xIsBigger&sameSign);

  //If they have different signs
  int diffSign = (xNeg&(!yNeg));

  //If they are equal or have different signs, then 0, otherwise x must be greater
  return ((areEqual|diffSign)&0)|((!(areEqual|diffSign))&1);
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  //Subtracts 48 to make the number 0-9
  int z = x+((~0x30)+1);
  //If its 0-7
  int k = !(z>>3);
  //If its 8 or 9
  int a = !(z+(~9)+1)|!(z+~8+1);
  //Return if it's 0-7 or 8 or 9, 0-9
  return k|a;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
  //Does not work :(
  //4/8  + 1/8
  //4/8=1/2
  int twoX = (x>>1);
  //4/8 + 1/8
  int val = (twoX+(x>>3));

  //using the formula from the slides for dividing with negatives
  int negSum = ( ((x+(1<<1)+(~0))>>1) + ((x+(1<<3)+(~0))>>3) );

  //if the number is negative
  int isNeg = x>>31;

  //If the number is negative, return the negative sum, otherwise, return the standard value
  return (isNeg&negSum)|(~isNeg&val);
}

/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

  //Brute force!
  //Pros: Pretty straightforward to understand and works effectively
  //Cons: Looks gross and uses too many operators

  //Essentially makes a variable for each of the bits and then on return, checks each conditional from the leftmost bit to the right most bit and
  //returns with whichever is true first

  int thirty = (x<<1)>>31;
  int twnn = (x<<2)>>31;
  int twei = (x<<3)>>31;
  int twsv = (x<<4)>>31;
  int twsi = (x<<5)>>31;
  int twfi = (x<<6)>>31;
  int twfo = (x<<7)>>31;
  int twth = (x<<8)>>31;
  int twtw = (x<<9)>>31;
  int twon = (x<<10)>>31;
  int twty = (x<<11)>>31;
  int nint = (x<<12)>>31;
  int eitn = (x<<13)>>31;
  int svnt = (x<<14)>>31;
  int sixt = (x<<15)>>31;
  int fift = (x<<16)>>31;
  int frtn = (x<<17)>>31;
  int thrt = (x<<18)>>31;
  int twlv = (x<<19)>>31;
  int elvn = (x<<20)>>31;
  int ten = (x<<21)>>31;
  int nine = (x<<22)>>31;
  int eght = (x<<23)>>31;
  int svn = (x<<24)>>31;
  int six = (x<<25)>>31;
  int five = (x<<26)>>31;
  int four = (x<<27)>>31;
  int three = (x<<28)>>31;
  int two = (x<<29)>>31;
  int one = (x<<30)>>31;
  int zero = (x<<31)>>31;

  return (thirty&30)|(~thirty&((twnn&29)|(~twnn&((twei&28)|(~twei&((twsv&27)|(~twsv&((twsi&26)|(~twsi&((twfi&25)|(~twfi&((twfo&24)|(~twfo&((twth&23)|(~twth&((twtw&22)
  |(~twtw&((twon&21)|(~twon&((twty&20)|(~twty&((nint&19)|(~nint&((eitn&18)|(~eitn&((svnt&17)|(~svnt&((sixt&16)|(~sixt&((fift&15)|(~fift&((frtn&14)|(~frtn&((thrt&13)
  |(~thrt&((twlv&12)|(~twlv&((elvn&11)|(~elvn&((ten&10)|(~ten&((nine&9)|(~nine&((eght&8)|(~eght&((svn&7)|(~svn&((six&6)|(~six&((five&5)|(~five&(
  (four&4)|(~four&((three&3)|(~three&((two&2)|(~two&((one&1)|(~one&((zero&0)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
                                                                              //Looks like Racket...
}

/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  //The exponent portion of x
  int exp = uf>>23&0xff;
  //The mantissa
  int mant = uf&0x7fffff;

  //If the exponent is the largest it can be and the mantissa is not 0, then return itself
  if(exp==0xff&&mant!=0){
    return uf;
  }
  else{
    //Otherwise return the number with the signe removed
    return uf^(1<<31);
  }
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {

  //Sign for the number
  unsigned s = x<0;
  //Mantissa
  unsigned m = s ? -x:x;
  //Exponent
  unsigned e = 127+31;
  //Rounding
  unsigned r;
  //Temporary mask
  unsigned mask;

  //If the mantissa is 0, then the exponent should be 0
  if(m==0){
    e = 0;
  }
  //Otherwise
  else{
    //Makes the mask the minimum
    mask = 0x80000000;
    //While the mask and the mantissa are 0
    while(!(m&mask)){
      //Keep shifting the mantissa
      m = m<<1;
      //Subtract one from the exponent
      e--;
    }

    //Round
    r = m & 0xff;
    //Shifts mantissa and ands it cut off the endings
    m = (m>>8) & 0x7fffff;

    //If the round is greater than 128 or if the round is exactly 128 and the mantissa is odd
    if(r > 0x80 || (r== 0x80 && (m & 0x1))){
      //Make the mantissa even
      m++;
      //
      if(m > 0x7fffff){
        //Get rid of the end of the mantissa and shift one
        m = (m&0x7fffff) >> 1;
        //Increase the exponent
        e++;
      }

    }

  }

  //Put the signn back on the left, put the exponent in the correct bit positions and add the mantissa
  return s<<31|e<<23|m;

}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //Does not work :(
  return 2;
}
