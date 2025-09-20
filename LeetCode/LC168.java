import java.util.Scanner;

class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();
        
        while (columnNumber > 0) {
            columnNumber--; // adjust because Excel is 1-based
            int remainder = columnNumber % 26;
            sb.append((char) ('A' + remainder));
            columnNumber /= 26;
        }
        
        return sb.reverse().toString();
    }
}

public class LC168 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Solution sol = new Solution();
        String res = sol.convertToTitle(n);
        System.out.println(res);
        sc.close();
    }
}
