/* Problem 10
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
*/

unsigned long long  sumOfPrimes(){
    unsigned long long  sum = 0;
    //Find all primes below 2 000 000
    for(unsigned long  i = 2; i < 2000000; ++i){
         bool isPrime = true;
         if (i % 2 == 0 || i % 3 == 0){
             //Not prime, go next.
            continue;
         } else {
             //Test if it is dividable by other prime numbers.
                unsigned long  int j;
                //Enough to test to half. Every prime number is of form 5+6n(+2)
                for (j=5; j*j<=i; j+=6) {
                    if (i % j == 0 || i%(j + 2) == 0){
                        //Dividable by prime number.
                        isPrime = false;
                        break;
                    }
                }
         }
         if(isPrime){
             sum += i;
         }
    }
    return sum+2+3;
}
