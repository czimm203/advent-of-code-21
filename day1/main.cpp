#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line;

    vector<int> depths;
    int prev;
    int count;
    ifstream infile("data.txt");
    if(infile.is_open()) {
        while (getline(infile, line)){
            depths.push_back(stoi(line));
        }

        infile.close();
    }

    for(int i = 1; i < depths.size() - 1; i ++){
        int sum = depths[i-1] + depths[i] + depths[i+1];
        if(prev && sum > prev){
            count ++;
        }
        prev = sum;
    }
    cout << "Number of increases: " << count << endl;

    return 0;
}