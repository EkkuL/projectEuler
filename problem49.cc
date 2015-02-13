#include <QDebug>
#include <QList>
#include <string>
#include <algorithm>

/*
 * Problem 49
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
 * What 12-digit number do you form by concatenating the three terms in this sequence?
*/
struct primeNumber{
    QString asString;
    int asNumber;
};

//Helper function for sorting primeNumber-type by their permutations
bool lessThan(const primeNumber& x, const primeNumber& y) {
    if(x.asString < y.asString){
        return false;
    }
    else if(x.asString == y.asString){
        if(x.asNumber < y.asNumber){
            return false;
        }else{
            return true;
        }
    }else{
        return true;
    }
}
QList <int> fourDigitPrimePermutation(){

    QList<primeNumber>primeNumbers;

    //Solve all prime numbers between 1000 and 10000
    for(int i = 1000; i < 10000; ++i){
         bool isPrime = true;
         if (i % 2 == 0 || i % 3 == 0){
            continue;
         } else {

                int j;
                for (j=5; j*j<=i; j+=6) {
                    if (i % j == 0 || i%(j + 2) == 0){
                        isPrime = false;
                        break;
                    }
                }

         }
         if(isPrime){
             //Sort the string version of the number( "231" = "123")
             QString number = QString::number(i);
             std::sort(number.begin(), number.end());
             primeNumber temp = {number,i};
             primeNumbers.append(temp);
         }
    }

    //Sort them to find permutations
    qSort(primeNumbers.begin(), primeNumbers.end(), lessThan);
    std::vector<int>seq;


  for(int i = 0; i < primeNumbers.size(); ++i){
        QList<int>permutations;
        permutations.append(primeNumbers.at(i).asNumber);

        //If second to the last, break. No sequence found.
        if( i + 1 >= primeNumbers.size()){
            break;
        }
        //Split primenumbers into permutations
        while(primeNumbers.at(i).asString == primeNumbers.at(i+1).asString){
            permutations.push_back(primeNumbers.at(i+1).asNumber);
            ++i;
        }
        //If there is only 2 permtations, sequence not found, continue.
        if(permutations.size() <= 2){
            continue;
        }

        //Check if the permutations have the sequence.
        for(int j = 0; j < permutations.size()-1; ++j){
            int increase = 0;
            for(int m = j+1; m < permutations.size(); ++m){
                increase = permutations.at(m) - permutations.at(j);
                if(permutations.contains(permutations.at(m)+increase)){
                    return permutations;
                }
            }
        }
    }
  QList<int>empty;
  return(empty);
}
