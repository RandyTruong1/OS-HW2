# OS-HW2
Topic: Banker’s Algorithm

The purpose of this program is to determine whether a system is in a safe or unsafe state based on the current allocation of resources to processes. The program implements the Banker’s Algorithm. It reads the current resource allocation, maximum resource, and available resources. Using these values, it computes how many more resources each process needs and repeatedly checks whether a process can safely run with the currently available resources. If all processes can finish without entering a deadlock, a safe sequence is printed. Otherwise, the system is declared unsafe.


USAGE GUIDE:

I downloaded the WSL (Windows Subsystem for Linux) program and used it to run (you will need to use "cd" and move to the folder of the files).

1. Download all files
2. Make sure all files are there by typing "ls"
3. Type "make" to make banker
4. Type "./banker input.txt" to run the program



I ran the example problem from the assignment doc in my program, and this is what I got. 

EXAMPLE OUTPUT SCREENSHOT:

<img width="582" height="39" alt="image" src="https://github.com/user-attachments/assets/883c4038-53c0-4dde-9d8d-384537060b1e" />


