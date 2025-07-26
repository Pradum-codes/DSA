// import java.util.HashMap;
import java.util.Scanner;

class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return mid;

            if(nums[mid] == nums[mid-1]){
                if((mid-1)%2 == 0){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        
        return -1;
    }
}

// class Solution {
//     public int singleNonDuplicate(int[] nums) {
//         HashMap<Integer, Integer> hm = new HashMap<>();
        
//         for(int num : nums) {
//             hm.put(num, hm.getOrDefault(num, 0) + 1);
//         }
        
//         for(int key : hm.keySet()) {
//             if(hm.get(key) == 1) {
//                 return key;
//             }
//         }
        
//         return -1;
//     }
// }

public class LC540 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        Solution sol = new Solution();
        int res = sol.singleNonDuplicate(arr);
        System.out.println(res);
        sc.close();
    }    
}