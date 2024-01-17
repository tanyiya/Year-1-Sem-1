/*
 Tan Yi Ya
 A23CS0187
 3/11/2023
 SET 2
 */

#include <iostream>
using namespace std;

int main() {
    int sum = 0,
            number,
            remainder;

    cout << "Enter an integer number:";
    cin >> number;

    while (number >= 10) {
        remainder = (number % 10);
        sum += remainder;

        cout << remainder << " + ";

        number /= 10;

        if (number < 10)
        {

            remainder = (number % 10);
            sum += remainder;

            cout << remainder << " = " << sum << endl;

            number /= 10;

        }
    }

    if (sum % 2 == 0 && sum % 4 == 0 && sum % 5 == 0)
        cout << sum << " is even number & multiples of 4 and 5.";

    else if (sum % 2 == 0 && sum % 4 == 0)
        cout << sum << " is even number & multiples of 4.";

    else if (sum % 2 == 0 && sum % 5 == 0)
        cout << sum << " is even number & multiples of 5.";

    else if (sum % 2 == 0)
        cout << sum << " is even number.";

    else if (sum % 2 != 0 && sum % 5 == 0)
        cout << sum << " is odd number & multiples of 5.";

    else if (sum % 2 != 0)
        cout << sum << " is odd number.";


    return 0;
}

/*
C:\h\cmake-build-debug\h.exe
Enter an integer number:98762
2 + 6 + 7 + 8 + 9 = 32
32 is even number & multiples of 4.
Process finished with exit code 0
 */