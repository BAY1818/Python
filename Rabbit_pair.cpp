#include <iostream>
using namespace std;

int rabbitPairs(int month);

int main()
{
    int n;

    do
    {
        cout << "Enter number of months (0 to exit): ";
        cin >> n;

        if (n == 0)
        {
            cout << "Program ended." << endl;
            break;
        }

        try
        {
            int result = rabbitPairs(n);
            cout << "Rabbit pairs at month " << n << ": " << result << endl;
        }
        catch (const char *message)
        {
            cout << "Error: " << message << endl;
        }

    } while (true);

    return 0;
}

int rabbitPairs(int month)
{
    if (month < 0) // now only throws for negative
        throw "Month must be positive!";
    if (month == 1 || month == 2)
        return 1;
    return rabbitPairs(month - 1) + rabbitPairs(month - 2);
}
