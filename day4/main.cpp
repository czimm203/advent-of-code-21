#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> loadData(string file) {
    string line;
    vector<string> data;
    ifstream input (file);

    while( getline(input, line)) {
        data.push_back(line);
    }
    return data;
}

vector<int> parseStringOnDel (string str, char del) {
    vector<int> out;
    
    stringstream ss(str);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, del);
        out.push_back(stoi(substr));
    }
    return out;
}



int main(int argc, char **argv) {

    vector<string> full = loadData(argv[1]);
    full.pop_back();

    vector<int> rolls = parseStringOnDel(full[0],',');

    full[0].erase();
    full[1].erase();

    cout << full.size() << endl;



    return 0;
}