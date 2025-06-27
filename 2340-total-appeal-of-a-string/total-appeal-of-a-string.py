class Solution:
    def appealSum(self, s):  # Added 'self' parameter
        n = len(s)
        # last_pos[c] stores the last position where character c appeared
        last_pos = {}
        
        # dp[i] represents the sum of appeals of all substrings ending at position i
        dp = 0
        total_appeal = 0
        
        for i in range(n):
            char = s[i]
            
            # Calculate the new dp value
            # For each previous substring ending before position i,
            # we either add 1 to its appeal (if char is new) or keep it same
            if char in last_pos:
                # Character appeared before at position last_pos[char]
                # Substrings starting after last_pos[char] will get +1 appeal
                # Substrings starting before or at last_pos[char] won't change
                dp = dp + (i - last_pos[char])
            else:
                # Character is new, all substrings ending at i get +1 appeal
                dp = dp + (i + 1)
            
            last_pos[char] = i
            total_appeal += dp
        
        return total_appeal
