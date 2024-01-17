/*
 Tan Yi Ya
 A23CS0187
 3/11/2023
 SET 1
 */

#include <iostream>
using namespace std;

int main() {
    int sum = 0,
        number,
        remainder;
    bool repeat = false;

    cout << "Enter an integer number:";
    cin >> number;

    do {
        if (number >= 10)
        {
            repeat = true;

            remainder = (number % 10);
            sum += remainder;

            cout << remainder << " + ";

            number /= 10;
        }

        else if (number < 10)
        {
            repeat = false;

            remainder = (number % 10);
            sum += remainder;

            cout << remainder << " = " << sum << endl;

            number /= 10;
        }

    } while (repeat);

    if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 == 0)
        cout << sum << " is multiples of 3, 4 and 5.";

    else if (sum % 4 == 0 && sum % 5 == 0)
        cout << sum << " is multiples of 4 and 5.";

    else if (sum % 3 == 0 && sum % 5 == 0)
        cout << sum << " is multiples of 3 and 5.";

    else if (sum % 3 == 0 && sum % 4 == 0)
        cout << sum << " is multiples of 3 and 4.";

    else if (sum % 3 == 0)
        cout << sum << " is multiples of 3.";

    else if (sum % 4 == 0)
        cout << sum << " is multiples of 4.";

    else if (sum % 5 == 0)
        cout << sum << " is multiples of 5.";


    return 0;
}

/*
C:\h\cmake-build-debug\h.exe
Enter an integer number:51684
4 + 8 + 6 + 1 + 5 = 24
24 is multiples of 3 and 4.
Process finished with exit code 0
 */