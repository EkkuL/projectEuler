#include <QList>

//Return all primenumbers as QList
QList <unsigned long> primeNumbers(unsigned int from, unsigned int to){
    QList <unsigned long> primeNumbers;
    primeNumbers.append(2);
    primeNumbers.append(3);

    if(from < 2){
        from == 2;
    }


    if( to < 2 ){
        QList<unsigned long> empty;
        return empty;
    }

    for(unsigned long  i = from; i < to; ++i){
         bool isPrime = true;
         if (i % 2 == 0 || i % 3 == 0){
            continue;
         } else {
                unsigned long  int j;
                for (j=5; j*j<=i; j+=6) {
                    if (i % j == 0 || i%(j + 2) == 0){
                        isPrime = false;
                        break;
                    }
                }
         }
         if(isPrime){
             primeNumbers.append(i);
         }
    }
    return primeNumbers;
}

