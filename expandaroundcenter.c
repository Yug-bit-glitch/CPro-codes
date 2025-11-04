char* longestPalindrome(char* s) {
 // expand around center idea is used
 // (2n-1 )centers
 int n=strlen(s);
 int maxlen=0;
 int start=0;
for(int i=0;i<2*n-1;i++){
int left=i/2;
int right=left+(i%2);
while((left>=0)&&(right<n)&&(s[left]==s[right])){
int curr=right-left+1;
if(curr>maxlen){
    start=left;
    maxlen=curr;
}
left--;
right++;
}
}
char*ans=malloc((maxlen+1)*sizeof(char));
strncpy(ans,s+start,maxlen);
ans[maxlen]='\0';
return ans;
}
