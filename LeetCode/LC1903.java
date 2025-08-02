import java.util.Scanner;

class Solution {
    public String largestOddNumber(String num) {
        int i = num.length() - 1;

        while (i >= 0 && (num.charAt(i) - '0') % 2 == 0) {
            i--;
        }

        if (i < 0) {
            return "";
        }

        return num.substring(0, i + 1);
    }
}


public class LC1903{
    public static void main(String[] a){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Solution sol = new Solution();
        System.out.println(sol.largestOddNumber(str));
        sc.close();
    }
}