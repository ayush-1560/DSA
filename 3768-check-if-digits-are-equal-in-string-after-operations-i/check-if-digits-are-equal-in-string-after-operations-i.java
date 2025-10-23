class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        char[] arr = s.toCharArray();

        while (n > 2) {
            for (int i = 0; i < n - 1; i++) {
                int num = (arr[i] - '0' + arr[i + 1] - '0') % 10;
                arr[i] = (char)(num + '0');
            }
            n--;
        }

        return arr[0] == arr[1];
    }
}
