import java.util.*;
class Spreadsheet {
     private int[][] grid;

    public Spreadsheet(int rows) {
        
       
      grid=new int[rows][26];
        
    }
    
    public void setCell(String cell, int value) {
        int col=cell.charAt(0)-'A';
        int row=Integer.parseInt(cell.substring(1))-1;
        grid[row][col]=value;

        
    }
    
    public void resetCell(String cell) {
        int col=cell.charAt(0)-'A';
        int row=Integer.parseInt(cell.substring(1))-1;
        grid[row][col]=0;
        
    }
    public int solve(String s){
        if(Character.isDigit(s.charAt(0))){
            return Integer.parseInt(s);
        }
        int col=s.charAt(0)-'A';
        int row=Integer.parseInt(s.substring(1))-1;
        return grid[row][col];
    }
    
    public int getValue(String formula) {
        String s=formula.substring(1);
        int idx=s.indexOf('+');
        String left=s.substring(0,idx);
        String right=s.substring(idx+1);
        return solve(left)+solve(right);
        
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */