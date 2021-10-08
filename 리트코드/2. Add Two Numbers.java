// package 리트코드;


// import java.util.*;
// import java.lang.*;
// class Solution {
//     public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    
//         StringBuilder ans = new StringBuilder();
//         ListNode curO = l1;
//         ListNode curT = l2;
//         int carry = 0;
//         while(curO !=null && curT != null){
//             int sum = curO.val + curT.val + carry;
//             String s = String.valueOf(sum);
//             if(s.length() > 1){
                
//                 carry = s.charAt(0) - '0';
//                 ans.append(s.charAt(1));
       
                
//             }
//             else{
//                 carry = 0;
//                 ans.append(s.charAt(0));
//             }
            
//             curO = curO.next;
//             curT = curT.next;
//         }
        
//         while(curO != null){
//          int t = curO.val;
//          int sum = t + carry;
//          String tmp = String.valueOf(sum);
//          if(tmp.length()>1){
//             ans.append(tmp.charAt(1));
//             carry = tmp.charAt(0) - '0';
            
//          }
//           else{
//               ans.append(tmp.charAt(0));
//               carry = 0;
//           }
     
//          curO = curO.next;
            
//         }
//         while(curT != null){
//          int t = curT.val;
//          int sum = t + carry;
//          String tmp = String.valueOf(sum);
//          if(tmp.length()>1){
//              ans.append(tmp.charAt(1));
//              carry = tmp.charAt(0) - '0';
//          }
//           else{
//               ans.append(tmp.charAt(0));
//               carry = 0;
//          }
    
//          curT = curT.next;
//         }
        
//         if(carry != 0){
//              ans.append(String.valueOf(carry));
//         }
        
        
//         ListNode answer = new ListNode();
//         ListNode cur = answer;
//         int i = 0;
//         for(i = 0 ; i < ans.length()-1 ;i++){
//             cur.val = ans.charAt(i) - '0';            
//             cur.next = new ListNode();
            
//             cur = cur.next;
//         }
//         cur.val = ans.charAt(i) - '0';    
//         return answer;
        
//     }
// }