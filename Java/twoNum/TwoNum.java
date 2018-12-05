/**
 * 
 * author : cjc
 * time : 2018 12 04
 * leetcode twonum 问题
 *  */

 // 看了 haoel 大神的C++ 实现思路，我用Java自己实现一遍，巩固一下
import java.util.Map;
import java.util.HashMap;

 public class TwoNum {
    public int[] twoNum(int[] number, int target) {
        int[] result = {0,0};
        Map<Integer, Integer> myMap = new HashMap<Integer,Integer>();

        for(int i = 0; i < number.length; i++) {
            if(myMap.get(number[i]) == null) {
                // 不在里面的，添加下标进Map
                myMap.put(target - number[i], i);
            } else {
                result[0] = myMap.get(number[i]) + 1;
                result[1] = i + 1;
                break;
            }
        }
        return result;
    }


     public static void main(String[] args) {
        TwoNum twoNum = new TwoNum();
        int[] number = {2,3,9,7};
        int[] result = twoNum.twoNum(number, 9);
        for(int i : result) {
            System.out.println(i);
        }
     }
 }