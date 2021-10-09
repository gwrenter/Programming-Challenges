import java.math.*;
import java.util.*;

class Main
{
    static void CountFibonacci(ArrayList<BigInteger> arr, BigInteger numA, BigInteger numB, long cnt, BigInteger powVal){
        //Adding an element to array
        arr.add(numA);
        
        //Checking if numA variable is greater or smaller than
        //powVal (if true returns 1, 0 otherwise)
        int compA2Pow = numA.compareTo(powVal);
        if(compA2Pow != 1){
            //Calling recursively function CountFibonacci
            //until the compA2Pow becomes equal to 1
            CountFibonacci(arr,numB,numA.add(numB),++cnt,powVal);
        }
    }
    
	public static void main(String[] args) {
	    //Creating Scanner variable to get user input
	    Scanner input = new Scanner(System.in);
	    
	    //Array list that stores all fibonacci values depending on the ranges given
        ArrayList<BigInteger> numArray = new ArrayList<BigInteger>();
	    
	    //Some BigInteger declarations for handling function above
	    BigInteger valA = new BigInteger("1"),
                   valB = new BigInteger("2"),
                   powVal = new BigInteger("10");
                   
        //Raise the BigInteger power value to the power of 100
        //which is the upper end test case
        powVal = powVal.pow(100);
        
        //Counter parameter value for function CountFibonacci
        //and while loop control below
        int numResult = 0;
        
        //Calling function CountFibonacci and passing parameter values
        CountFibonacci(numArray,valA,valB,0,powVal);
	    
	    //Strings that store value to compute
        String strA = input.next(), strB = input.next();

        //While loop control that checks if any of the values are zero
		while(!strA.equals("0") || !strB.equals("0")){
		    //BigInteger declarations
		    BigInteger numA = new BigInteger(strA);
		    BigInteger numB = new BigInteger(strB);
		    
		    //Integer index control for while loop
		    int idx = 0;
		    
		    //Loop compares if value in array index is not greater
		    //than what the BigInteger numA holds, otherwise value is
		    //1 and we keep incrementing index by 1.
		    while(numArray.get(idx).compareTo(numA) == -1)
		        idx++;
		  
		    numResult = 0;
		    //Loop compares if value in array index is greater
		    //than what the BigInteger numB holds, otherwise value is
		    //-1 and we keep incrementing both index and cnt by 1.
		    while(numArray.get(idx).compareTo(numB) != 1){
		        numResult++;
		        idx++;
		    }
		    
		    //Printing counter output with the number of 
		    //fibonacci numbers between the ranges given
		    System.out.println(numResult);
		    
		    //Inserting new data for new test case
		    strA = input.next();
		    strB = input.next();
		}
		
		input.close();
	}
}