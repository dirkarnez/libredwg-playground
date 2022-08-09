#include <dwg.h>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    using namespace std;

    Dwg_Data dwg_struct;
    int error = dwg_read_file(argv[1], &dwg_struct);
    
    dwg_free(&dwg_struct);

    cout << (error ? "ERROR" : "SUCCESS") << endl;

    cin.get();
    return error ? 1 : 0;
}
