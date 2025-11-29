int solve(int idx, int n, char *s, int *memo){
    if(idx >= n)
        return 0;

    if(memo[idx] != -1)
        return memo[idx];

    int skip = solve(idx + 1, n, s, memo);

    int take = 0;
    if(s[idx] == '"'){
        take = 1 + solve(idx + 1, n, s, memo);
    }

    // if jump of 3 is allowed
    int jump3 = solve(idx + 3, n, s, memo);

    // if jump of 5 is allowed
    int jump5 = solve(idx + 5, n, s, memo);

    // now choose maximum of skip, take, jump3, jump5
    int ans = skip;

    if(take > ans)
        ans = take;

    if(jump3 > ans)
        ans = jump3;

    if(jump5 > ans)
        ans = jump5;

    memo[idx] = ans;
    return ans;
}
