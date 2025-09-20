class Spreadsheet {
public:
    vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid.assign(rows,vector<int>(26,0));
        
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        grid[row][col]=value;
        
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        grid[row][col]=0;
        
    }
    int solve(string s){
        if(isdigit(s[0])){
            return stoi(s);
        }
        int col=s[0]-'A';
        int row=stoi(s.substr(1))-1;
        return grid[row][col];

    }
    
    int getValue(string formula) {
        string s=formula.substr(1);
        int idx=s.find('+');
        string left=s.substr(0,idx);
        string right=s.substr(idx+1);
        return solve(left)+solve(right);
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */