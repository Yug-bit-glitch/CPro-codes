char* addBinary(char* a, char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int i = len1 - 1;
    int j = len2 - 1;
    int carry = 0;
    
    int maxlen = (len1 > len2 ? len1 : len2) + 2;
    char* ans = (char*)malloc(maxlen);
    ans[maxlen - 1] = '\0';
    int k = maxlen - 2;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        ans[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // shift answer to start
    return ans + k + 1;
}
Line-by-line explanation
char* addBinary(char* a, char* b) {

Start of the function. It takes two C strings a and b (binary numbers comprised of '0' and '1') and returns a newly allocated C string containing their binary sum.

int len1 = strlen(a);

Compute length of string a (number of characters before the null terminator). Requires #include <string.h>.

int len2 = strlen(b);

Compute length of string b.

int i = len1 - 1;

Set i to the index of the last character in a (we process from right to left). If len1 is 0, i becomes -1 and the loop will skip reading a.

int j = len2 - 1;

Same for b.

int carry = 0;

Initialize carry (0 or 1) for binary addition.

int maxlen = (len1 > len2 ? len1 : len2) + 2;

Decide how much space to allocate for the result:

max(len1,len2) for the longer input bits,

+1 in case there is a final carry (e.g., 1 + 1 = 10 needs one extra digit),

+1 more for the null terminator '\0'.

So +2 total. This guarantees the buffer is big enough.

char* ans = (char*)malloc(maxlen);

Allocate maxlen bytes on the heap for the result string. Requires #include <stdlib.h>.

Note: malloc may return NULL if allocation fails — production code should check for NULL.

ans[maxlen - 1] = '\0';

Put the string terminator at the last allocated position. The valid data characters will be written earlier in the buffer (towards lower indices).

int k = maxlen - 2;

k is the index where we will write the next result character (the last possible character slot before '\0'). We fill the answer backwards (right to left).

while (i >= 0 || j >= 0 || carry) {

Loop while there are digits left in either string or there is a carry to write. This ensures we process all bits and any leftover carry.

int sum = carry;

Start this digit’s sum with the existing carry (0 or 1).

if (i >= 0) sum += a[i--] - '0';

If a still has a digit, convert the character digit to its integer value by doing a[i] - '0' (e.g. '1' - '0' == 1).

Add it to sum and then decrement i (postfix i-- returns the old value, then decrements).

if (j >= 0) sum += b[j--] - '0';

Same for b.

ans[k--] = (sum % 2) + '0';

sum % 2 is the resulting bit (0 or 1) for this position.

Adding '0' converts that integer bit back to the corresponding character (0 → '0', 1 → '1').

Store that character at ans[k], then decrement k to move left for the next digit.

carry = sum / 2;

Compute the new carry (either 0 or 1 for binary) for the next iteration. For binary, sum / 2 is 1 only when sum is 2 or 3.

} (end while)

// shift answer to start

Comment: the next line returns a pointer to the first written character, which is inside the allocated buffer.

return ans + k + 1;

After the loop, k points to one position left of the first filled character (because we decremented k after writing). So k + 1 is the index of the first result digit.

Returning ans + k + 1 returns a pointer to the start of the null-terminated result string inside the allocated block.

Quick example walk-through
Inputs: a = "101" (len1=3), b = "11" (len2=2)

maxlen = max(3,2)+2 = 5, buffer indices 0..4, ans[4]='\0', k=3.

Iteration 1: i=2 char '1', j=1 char '1' → sum = 1+1+0 = 2 → ans[3] = (2%2)+'0' = '0', carry = 1, k→2

Iteration 2: i=1 '0', j=0 '1' → sum = 0+1+1 = 2 → ans[2] = '0', carry=1, k→1

Iteration 3: i=0 '1', j=-1 → sum = 1+0+1 = 2 → ans[1] = '0', carry=1, k→0

Iteration 4: i=-1 j=-1 carry=1 → sum = 1 → ans[0] = '1', carry=0, k→-1

Loop ends; return ans + k + 1 → ans + 0 → points at ans[0] which holds "1000".

Important caveats & suggestions
Freeing memory

Returning ans + k + 1 returns a pointer inside the buffer returned by malloc. The pointer you return is not the original pointer returned by malloc, so calling free on that returned pointer is undefined behavior.

Solutions:

Save the original ans pointer somewhere before returning (e.g., return a copy using strdup(ans + k + 1) then free(ans) and return the strdup result). Or:

After finishing, memmove(ans, ans + k + 1, maxlen - (k + 1)) to shift the result to the beginning of ans, then return ans;. Then caller can free(ans) safely.

Or allocate exact-size buffer for the final answer and strcpy into it and free the large temporary.

Check malloc result

Always test if (!ans) return NULL; in robust code.

Off-by-one safety

maxlen = max(len)+2 is correct here. Just ensure you never write before index 0 — the while condition and k initialization prevent that.

Header includes

This code needs #include <string.h> and #include <stdlib.h> (and <stdio.h> if you print).

