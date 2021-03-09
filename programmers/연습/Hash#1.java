import java.util.*;

class Solution {
    public static String solution(String[] participant, String[] completion) {
       String answer = "";
       int a;
       HashMap<String, Integer> map = new HashMap<>();
       for(String person : participant) {
           if(map.get(person) == null) {
               a = 0;
               map.put(person, a);
           } else {
               a = map.get(person);
               map.put(person, a + 1);
           }
       }
       for(String person : completion) {
           a = map.get(person) - 1;
           map.put(person, a);
       }
       for(String person : participant) {
           if(map.get(person) == 0) answer = person;
       }
       return answer;
    }

    public static void main(String[] args) {
        String[] a = {"mislav", "stanko", "mislav", "ana"};
        String[] b = {"stanko", "ana", "mislav"};
        System.out.println(solution(a,b));
    }
}