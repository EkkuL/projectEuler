/* Problem 6
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int sumSquareDifference(){
    int sumOfSquares = 0;
    int squareOfSums = 0;
    for(int i = 1; i <= 100; ++i){
        squareOfSums += i;
        sumOfSquares += i*i;
    }
    squareOfSums = squareOfSums*squareOfSums;
    return squareOfSums-sumOfSquares;
}
