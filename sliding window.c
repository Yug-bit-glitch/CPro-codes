int lengthOfLongestSubstring(char* s) {
    if (s == NULL || s[0] == '\0')
        return 0;

    int freq[256] = {0};
    int l = 0, longest = 0;
    int n = strlen(s);

    for (int r = 0; r < n; r++) {
        char c = s[r]; // plain char works fine

        while (freq[c] > 0) {
            freq[s[l]]--;
            l++;
        }

        freq[c]++;
        int window = r - l + 1;
        if (window > longest)
            longest = window;
    }

    return longest;
}
