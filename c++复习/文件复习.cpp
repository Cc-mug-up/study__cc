#include <bits/stdc++.h>
using namespace std;
int main()
{
    string data;
    ofstream outfile;
    outfile.open("test.dat", ios::app);
    while (getline(cin, data))
        outfile << data << endl;
    outfile.close();
    ifstream infile;
    infile.open("test.dat");
    while (getline(infile, data))
        cout << data << endl;
    return 0;
}