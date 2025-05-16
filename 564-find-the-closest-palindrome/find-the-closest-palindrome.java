import java.util.HashSet;
import java.util.Set;

class Solution {
    public String nearestPalindromic(String n) {
        long originalNumber = Long.parseLong(n);
        long closestPalindrome = -1;

        int length = n.length();
        Set<Long> candidates = new HashSet<>();

        candidates.add((long) Math.pow(10, length - 1) - 1);
        candidates.add((long) Math.pow(10, length) + 1);

        long leftPart = Long.parseLong(n.substring(0, (length + 1) / 2));
        for (long i = leftPart - 1; i <= leftPart + 1; ++i) {
            StringBuilder candidateBuilder = new StringBuilder();
            candidateBuilder.append(i);
            candidateBuilder.append(new StringBuilder(Long.toString(i)).reverse().substring(length % 2));
            candidates.add(Long.parseLong(candidateBuilder.toString()));
        }

        candidates.remove(Long.parseLong(n));

        for (long candidate : candidates) {
            if (closestPalindrome == -1 ||
                Math.abs(candidate - originalNumber) < Math.abs(closestPalindrome - originalNumber) ||
                (Math.abs(candidate - originalNumber) == Math.abs(closestPalindrome - originalNumber) && candidate < closestPalindrome)) {
                closestPalindrome = candidate;
            }
        }

        return Long.toString(closestPalindrome);
    }
}