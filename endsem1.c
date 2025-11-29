#include <stdio.h>
#include <stdbool.h>

bool tree(char c)
{
    if (c == '*')
    {
        return true;
    }
    if (c == '.')
    {
        return false;
    }
}

int main()
{

    int n, q;
    scanf("%d %d", &n, &q);

    int s[n+1][n+1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                s[i][j] = 0;
            }
            else
            {
                s[i][j] = (tree(s[i][j]) == true) + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        int ans = s[y2][x2] - s[y1 - 1][x1] - s[y1][x1 - 1] + s[x1][y1];
        printf("%d\n", ans);
    }
    return 0;
}
