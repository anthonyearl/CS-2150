//Brandon Feng yf2km testPostfixCalc.cpp 2/7/2017

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <cstdlib>

#include "postfixCalculator.h"
using namespace std;

int main() {
      postfixCalculator p;
 
      cout<< "Enter line: " << endl;
  
      while (true) {
 

	string s;
        cin >> s;

	if(!cin.good())
	  {
	    break;
	  }

	if(s == "+")
	  {
	    p.add();
	  }
	else if(s == "-")
	  {
	    p.minus();
	  }
	else if(s == "*")
	  {
	    p.multiply();
	  }
	else if(s == "/")
	  {
	    p.divide();
	  }
	else if(s == "~")
	  {
	    p.uNegate();
	  }
	else
	  {
	    p.pushNum(atoi(s.c_str()));
	  }
      }
      cout <<"Result: " <<  p.getTopValue() << endl;

}
