#include <iostream>
using namespace std;

// Calculates catalan numbers recursively.
int Catalan(int n)
{
    if(n < 0)
    {
        cout << "Error! Integer cannot be negative." << endl;
        return -1;
    }else if(n <= 1)
    {
        return 1;
    }

    int c = 0;

    for(int i = 0; i < n; i++)
    {
        c += Catalan(i) * Catalan(n - i - 1);
    }
    return c;
}

int main(int argc, char* argv[])
{   
    // Converts strings to ints. Utilizes command line arguments. 
    int n = stoi(argv[1]);
    cout << "Catalan{" << n << "} = " << Catalan(n) << endl;
    return 0;
}