#include <iostream>
#include <fstream>
using namespace std;

const int MAX_P = 10; // max number of processes
const int MAX_R = 10; // max number of resources

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    ifstream inFile(argv[1]);
    if (!inFile) 
    {
        cout << "Error: could not open input file.\n";
        return 1;
    }

    int n, m; // n = processes, m = resources
    inFile >> n >> m;

    if (!inFile || n > MAX_P || m > MAX_R) 
    {
        cout << "Error: bad n/m or too many processes/resources.\n";
        return 1;
    }

    int available[MAX_R];
    int alloc[MAX_P][MAX_R];
    int maxNeed[MAX_P][MAX_R];
    int need[MAX_P][MAX_R];

    // Read Available
    for (int j = 0; j < m; j++) 
    {
        inFile >> available[j];
    }

    // Read Allocation matrix
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            inFile >> alloc[i][j];
        }
    }

    // Read Max matrix
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            inFile >> maxNeed[i][j];
        }
    }

    inFile.close();
    
    // Compute Need = Max - Allocation
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            need[i][j] = maxNeed[i][j] - alloc[i][j];
        }
    }

    int work[MAX_R];
    bool finish[MAX_P];
    int safeSequence[MAX_P];
    int safeCount = 0;

    // Work starts as Available
    for (int j = 0; j < m; j++) 
    {
        work[j] = available[j];
    }

    // No process is finished at the start
    for (int i = 0; i < n; i++) 
    {
        finish[i] = false;
    }

    for (int count = 0; count < n; count++) 
    {
        bool foundProcess = false;

        for (int i = 0; i < n; i++) 
        {
            if (!finish[i]) 
            {
                bool canRun = true;

                // Checks if enough work resources for need for resource j
                for (int j = 0; j < m; j++) 
                {
                    if (need[i][j] > work[j]) 
                    {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) 
                {
                    // Pretend process i finishes and releases its resources
                    for (int j = 0; j < m; j++) 
                    {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = true;
                    safeSequence[safeCount] = i;
                    safeCount++;
                    foundProcess = true;
                    break; // restart searching from first process
                }
            }
        }

        if (!foundProcess) 
        {
            break; // no suitable process found in this pass
        }
    }

    // Check if all processes finished
    bool isSafe = true;
    for (int i = 0; i < n; i++) 
    {
        if (!finish[i]) 
        {
            isSafe = false;
            break;
        }
    }

    if (isSafe) 
    {
        cout << "System is in a SAFE state.\n";
        cout << "Safe sequence: ";
        for (int i = 0; i < safeCount; i++)
        {
            cout << "P" << safeSequence[i];
            if (i != safeCount - 1)
            {
                cout << " -> ";
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "System is in an UNSAFE state (no safe sequence).\n";
    }

    return 0;
}
