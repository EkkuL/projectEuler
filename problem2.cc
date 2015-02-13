/* Problem 2
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms. */

//A simple recursion to solve Project Euler's problem two.
void sumOfEvenFibonacci( int first,  int second,  int &sum){
    if(first%2 == 0){
        sum += first;
    }
    if(first > 4000000){
        return;
    }
    sumOfEvenFibonacci(second,first+second,sum);
}
