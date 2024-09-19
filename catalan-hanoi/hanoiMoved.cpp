#include <iostream>
#include <sys/time.h>

using namespace std;

static int i = 0;// Sets global increment value for number of moves. 
static bool print = true;// Allows for print to be turned on or off globally.

void hanoiMoves(int n, string from, string to, string extra)
{
    i++;
    if(n == 1)
    {
        if(print)
        {
            cout << "Move disk " << n << " from " << from << " to " << extra << endl;
        }
    }else
    {
        hanoiMoves(n-1, from, extra, to);
        if(print)
        {
            cout << "Move disk " << n << " from " << from << " to " << extra << endl;
        }
        hanoiMoves(n-1, to, from, extra);
    } 
}

// Calculates amount of time elapsed. 
struct timeval startTime, endTime;

int elapsed(timeval &startTime, timeval &endTime)
{
    return ((endTime.tv_sec - startTime.tv_sec)*1000000 + endTime.tv_usec - startTime.tv_usec);
}

int main()
{
    // Prints out display of disk movements, number of moves and time elapsed for disk 1.
    print = true;
    int start = gettimeofday(&startTime, 0);
    hanoiMoves(1, "A", "B", "C");
    int end = gettimeofday(&endTime, 0);
    cout << "Number of moves for disk 1" << " = " << i << endl;
    cout << "Time elapsed for disk 1"  << " = " << elapsed(startTime, endTime) << " microseconds"<< endl << endl;
    i = 0;

    // Prints out display of disk movements, number of moves, and time elapsed for disks 1 through 3.
    for (int j = 2; j < 4; j++)
    {
        start = gettimeofday(&startTime, 0);
        hanoiMoves(j, "A", "B", "C");
        end = gettimeofday(&endTime, 0);
        cout << "Number of moves for disks 1 through " << j << " = " << i << endl;
        cout << "Time elapsed for disks 1 through " << j << " = " << elapsed(startTime, endTime) << " microseconds"<< endl << endl;
        i = 0;
    }

    // Prints out number of moves and time elapsed for disks 1 through 15. 
    for(int j = 4; j < 16; j++)
    {
        print = false;
        start = gettimeofday(&startTime, 0);
        hanoiMoves(j, "A", "B", "C");
        end = gettimeofday(&endTime, 0);
        cout << "Number of moves for disks 1 through " << j << " = " << i << endl;
        cout << "Time elapsed for disks 1 through " << j << " = " << elapsed(startTime, endTime) << " microseconds"<< endl << endl;
        i = 0;
    }
    return 0;
}