#include <stdio.h>

int y;
int ans[500005];
int temp[500005];
int dp[500005];
int min = 100;

void dfs(int x, int len)
{

	if (len > 19)
		return;

	if (len >= min)
		return;

	if (x > y)
		return;

	if (x == y)
	{
		if (min > len)
		{
			min = len;
			for (int a = 1; a <= min; a++)
				ans[a] = temp[a];
		}
		return;
	}


	for (int b = len; b >= 1; b--)
		for (int c = b; c >= 1; c--)
		{
			// case 1 len <=10 is critical
			if (len <= 14)
			{
				if (dp[temp[b] + temp[c]] >= len + 1)
				{
					dp[temp[b] + temp[c]] = len + 1;
					temp[len + 1] = temp[b] + temp[c];
					dfs(temp[b] + temp[c], len + 1);
				}
			}
			else if (dp[temp[b] + temp[c]] > len + 1)
			{
				dp[temp[b] + temp[c]] = len + 1;
				temp[len + 1] = temp[b] + temp[c];
				dfs(temp[b] + temp[c], len + 1);
			}
		}
	return;
}

int main()
{
	for (int a = 1; a <= 10000; a++)
		dp[a] = 100;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	temp[1] = 1;
	temp[2] = 2;
	temp[3] = 3;

	scanf("%d", &y);

	dfs(3, 3);

	//printf("len is %d\n", min);
	for (int c = 1; c <= min; c++)
		printf("%d ", ans[c]);
}