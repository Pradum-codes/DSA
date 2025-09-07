import java.util.Scanner;

class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxArea = -1;
        int maxDiagSq = -1; // store squared diagonal
        
        for (int i = 0; i < dimensions.length; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            
            int diagSq = l * l + w * w; // squared diagonal
            int area = l * w;
            
            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }
        
        return maxArea;
    }
}


public class LC3000 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][2];
        for (int i = 0; i<n; i++) {
            int l = sc.nextInt();
            int w = sc.nextInt();
            arr[i][0] = l;
            arr[i][1] = w;
        }

        Solution sol = new Solution();
        System.out.println(sol.areaOfMaxDiagonal(arr));
        
        sc.close();
    }
}