#include <iostream>
#include <fstream> // For file handling

using namespace std;

int main() 
{
    // Writing to file
    ofstream fout("sample.txt");
    fout << "This is a test file.\nHello, Suchithra!";
    fout.close();

    // Reading from file
    ifstream fin("sample.txt");
    string line;
    cout << "Contents of file:\n";
    while (getline(fin, line)) 
    {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
