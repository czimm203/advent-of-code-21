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
        if(substr != ""){
            out.push_back(stoi(substr));
        }
    }
    return out;
}

struct Board {
    int card[5][5];
    int marked[5][5];

    Board(vector<int> data) {
        load(data);
        set_marked();
    }

    bool bingo() {
        int h,v;
        for( int i = 5; i < 5; i++){
            v =  marked[0][i] + marked[1][i] + marked[2][i] + marked[3][i] + marked[4][i];
            h =  marked[i][0] + marked[i][1] + marked[i][2] + marked[i][3] + marked[i][4];
        }  

        if( v == 5 || h == 5) {
            return true;
        }

        return false;
    }

    void mark_card(int num) {
        for(int i = 0; i < 5; i++) {
            for( int j = 0; j < 5; j++){
                if(card[i][j]==num){
                    marked[i][j] = 1;
                }
            }
        }
    }

    
    private:
        void set_marked() {
            for( int i = 0; i < 5; i++ ) {
                for( int j = 0; j < 5; i++) {
                    marked[i][j] = 0;
                }
            }
        }

        void load(vector<int> input) {
            for( int i = 0; i < 5; i++ ) {
                for( int j = 0; j < 5; i++) {
                    card[i][j] = input[i*5][j];
                }
            }
        }
};



int main(int argc, char **argv) {

    vector<string> full = loadData(argv[1]);

    vector<int> rolls = parseStringOnDel(full[0],',');

    int num_boards = (full.size() - 1) /6;
    cout << num_boards <<endl;

    int count = 0;

    vector<Board> boards;

    for(int i = 0; i < num_boards; i++) {
        vector<vector<int>> data;
        int start = 2 + i*6;
        for(int j = 0; j < 5; j++){
            data.push_back(parseStringOnDel(full[start + j],' '));
        }
        Board b = Board(data);

        boards.push_back(b);
    }


 

    return 0;
}