import java.util.Scanner;

class Solution {
    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;
        return (s + s).contains(goal);
    }
}

public class LC796{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s, goal;
        s = sc.nextLine();
        goal = sc.nextLine();

        Solution sol = new Solution();
        if(sol.rotateString(s,goal)){
            System.out.println("Is rotated");
        } else {
            System.out.println("NOT rotated");
        }
        sc.close();
    }
}