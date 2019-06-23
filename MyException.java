/*
 Create a class named Television that has data members to hold model number
and screen in inches, and the price. If more than four digits are entered
for the model, if screen size is smaller than 12 or greater than 70 inches,
or if price is negative or over $5000 then throw an exception. Write a main
function that instantiates a television objects, allows user to enter data
and display data. If an exception is caught replace all data members values
with zero.
*/



import java.util.Scanner;


class MyException extends Exception{

    String exception_msg;

    MyException(String str) 
    {
    		exception_msg=str;
    }

    public String toString()
    { 
	      return ("EXCEPTION OCCURRED = "+exception_msg) ;
    }
}
