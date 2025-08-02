import java.util.Scanner;

class Solution {
    public String reverseWords(String s) {
        String[] arr = s.trim().split("\\s+");
        StringBuilder res = new StringBuilder();

        for (int i = arr.length - 1; i >= 0; i--) {
            res.append(arr[i]);
            if (i != 0) {
                res.append(" ");
            }
        }
        return res.toString();
    }
}


public class LC151{
    public static void main(String[] arg){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Solution sol = new Solution();
        System.out.println(sol.reverseWords(str));
        sc.close();
    }
}