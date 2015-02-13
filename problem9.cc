/* Problem 9
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
*/

//Brute force :)
int specialPythagoreanTriplet(){
    for(int a = 100; a < 1000; ++a){
        for(int b = 100; b < 1000; ++b){
            for(int c = 100; c < 1000; ++c){
                if( a + b + c == 1000 and a*a+b*b==c*c){
                    qDebug() << "a: " << a << "b: " << b << "c:" << c;
                    return a*b*c;
                }
            }
        }
    }
}
