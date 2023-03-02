import java.util.*;
public class Main { 
    public static int positiveNumber(int array[]){
            int sumPositiveNumber = 0;
            int i = 0;
            while (i < array.length) {
                if (array[i] > 0) {
                    sumPositiveNumber += array[i];
                } 
                i++;
            } 
            return sumPositiveNumber;
        }
    public static int negativeNumber(int array[]){
            int sumNegativeNumber = 0;
            int i = 0;
            while (i < array.length) {
                if (array[i] < 0) { 
                        sumNegativeNumber += array[i]; 
                } 
                i++;
            } 
            return sumNegativeNumber;
        }
    public static void positiveOddNumbers(int array[]){
            System.out.print("Every positive odd numbers in the array: "); 
            int i = 0;
            while (i < array.length) { 
                if (array[i] > 0 && array[i] % 2 != 0)
                System.out.print (array[i] + " "); 
                i++; 
                    
            } 
            System.out.println(); 
    }
    public static void negativeEvenNumbers(int array[]){
            System.out.print ("Every negative even numbers in the array: ");
            int i = 0; 
            while (i < array.length) {
                if (array[i] < 0 && array[i] % 2 == 0) 
                System.out.print (array[i] + " ");
                i++; 
                
            }
            System.out.println();
    }
    public static void positiveReverseOrder(int array[]){
            System.out.print("Every positive numbers in the array in reverse order: ");
            int i = array.length - 1; 
            while (i >= 0) { 
                if (array[i] > 0) 
                System.out.print (array[i] + " ");
                i--; 
            } 
            System.out.println();     
    }
    public static void negativeNumbers(int array[]){
            System.out.print("Every negative numbers in the array: "); 
            int i = 0; 
            while (i < array.length) { 
                if (array[i] < 0) 
                System.out.print (array[i] + " ");
                i++;
            } 
            System.out.println();   
    }
    public static void everyNumbers(int array[]){
            System.out.print ("Every numbers in the array: "); 
            int i = 0;
            while (i < array.length) {
                System.out.print (array[i] + " ");
                i++; 
            } 
            System.out.println();
    }
    public static int countNegative(int array[]){
            int countNegativeNumber = 0;
            int i = 0;
            while (i < array.length) {
                if (array[i] < 0) { 
                    countNegativeNumber += 1; 
                } 
                i++;
            } 
            return countNegativeNumber;        
    }
    public static int countPositiveNumbers(int array[]){
            int countPositiveNumber = 0;
            int i = 0;
            while (i < array.length) {
                if (array[i] > 0) { 
                    countPositiveNumber += 1; 
                } 
                i++;
            } 
            return countPositiveNumber;        
    }
    public static void main (String[]args) { 
    Scanner pack = new Scanner (System.in); 
    int size = 20; 
    int[] array = new int[size]; 
    int i = 0;
    while (i < size) {
        array[i] = pack.nextInt (); 
        i++;
    }
    while (true) { 
        System.out.println ("1.Sum of every positive numbers"); 
        System.out.println ("2.Sum of every negative numbers"); 
        System.out.println ("3.Positive odd numbers"); 
        System.out.println ("4.Negative even numbers");
        System.out.println ("5.Every positive numbers in reverse order");
        System.out.println ("6.Every negative numbers in array"); 
        System.out.println ("7.Every numbers in array"); 
        System.out.println ("8.Count of negative numbers"); 
        System.out.println ("9.Count of positive numbers"); 
        System.out.print ("Enter your choice (1-9): "); 
        int yes = pack.nextInt (); 
        while (true) { 
            if(yes==1) {
                System.out.println("Sum of every positive numbers in the array: "+positiveNumber(array)); 
                break;
            }
            if(yes==2) { 
                System.out.println("Sum of every negative numbers in the array: "+negativeNumber(array));
                break; 
            } 
            if(yes==3) { 
                positiveOddNumbers(array);
                break;
            } 
            if(yes==4) { 
                negativeEvenNumbers(array);
                break; 
            } 
            if(yes==5) { 
                positiveReverseOrder(array);
                break; 
            } 
            if(yes==6) { 
                negativeNumbers(array);
                break; 
            } 
            if(yes==7) { 
                everyNumbers(array);
                break;
            }
            if(yes==8){ 
                System.out.println ("Count of Negative number: "+countNegative(array)); 
                break; 
            } 
            if(yes==9){ 
                System.out.println ("Count of Positive number: " +countPositiveNumbers(array)); 
                break; 
            }
        } 
        System.out.println ("Continue(y/n):");
        char bravo = pack.next().charAt(0);
        if (bravo == 'n') 
            break; 
        }
    }
}