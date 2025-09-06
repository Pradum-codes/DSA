import java.util.Scanner;

class Solution {
    int findClosest(int x, int y, int z) {
        int dist_1 = Math.abs(x-z);
        int dist_2 = Math.abs(y-z);    
        if(dist_1 == dist_2) return 0;
        else if (dist_1 < dist_2) return 1;
        return 2;
    }
};

public class LC3516{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        Solution sol = new Solution();

        System.out.println(sol.findClosest(x, y, z));

        sc.close();
    }
}