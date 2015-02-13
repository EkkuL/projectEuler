/* Problem 7
 * What is the 10 001st prime number?
*/

int the10001stPrime(){

    int st = 2; //Start at 2, because 2 and 3 are prime

    //Find every prime but 2 and 3
    for(unsigned long  i = 2; i < 2000000; ++i){
         bool isPrime = true;
         if (i % 2 == 0 || i % 3 == 0){
            continue;
         } else {

                unsigned long  int j;
                //Enough to test to half. Every prime number is of form 5+6n(+2)
                for (j=5; j*j<=i; j+=6) {
                    if (i % j == 0 || i%(j + 2) == 0){
                        isPrime = false;
                        break;
                    }
                }

         }
         if(isPrime){
             ++st;
             if(st == 10001){
                 return i;
             }

         }
    }
    return 0;
}
