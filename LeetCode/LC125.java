import java.util.Scanner;

class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            // skip non-alphanumeric from the right
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }
            // compare lowercased chars
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}

public class LC125 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        Solution sol = new Solution();
        boolean res = sol.isPalindrome(s);
        System.out.println(res);
        sc.close();
    }
}
