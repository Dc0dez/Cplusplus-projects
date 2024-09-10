#include "TimeSpan.h"
#include <iostream>
using namespace std;

int main()
{
    float hours = 1.0;
    float minutes = 2.0;
    float seconds = 3.0;
    //Tests
    TimeSpan duration1(hours, minutes, seconds);
    TimeSpan duration2(1, 2, 3);
    TimeSpan duration3(7, 3);
    TimeSpan duration4(50.9);
    TimeSpan duration5 = -duration1;
    TimeSpan duration6(1.5, 4, -10);
    TimeSpan duration7(-0.5, -0.5, -0.5);
    TimeSpan duration8(0, 0, 0);
    cout << duration1 + duration2 << endl;
    cout << duration2 - duration1 << endl;
    cout << duration1 - duration7 << endl;
    cout << duration1 + duration7 << endl;
    cout << duration3 << endl;
    cout << duration4 << endl;
    cout << duration5 << endl;
    cout << duration6 << endl;
    cout << "Enter numbers for hours, minutes, seconds: " << endl;
    cin >> duration8;
    cout << duration8 << endl;

    if (duration1 == duration7)
    {   
        cout << "True" << endl;
    }else
    {
        cout << "False" << endl;
    }

    if (duration1 == duration2)
    {   
        cout << "True" << endl;
    }else
    {
        cout << "False" << endl;
    }
    
    if(duration1 != duration6)
    {
        cout << "True" << endl;
    }else
    {
        cout << "False" << endl;
    }

    if(duration1 != duration2)
    {
        cout << "True" << endl;
    }else
    {
        cout << "False" << endl;
    }

    return 0;
}
