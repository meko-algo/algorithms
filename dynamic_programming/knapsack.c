#include<stdio.h>

int max(int a, int b) { return (a > b) ? a : b;}

int cache[100][100];

int knapsack_naive(int W, int wt[], int val[], int n)
{
	if (cache[n][W] != -1)
		return cache[n][W];
	if (n == 0 || W == 0)
		ans = 0;
	else if (wt[n-1] > W)
		ans = knapsack(W, wt, val, n-1);
	else
		ans = max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
	cache[n][W] = ans
	return ans
}

int knapsack_bottom_up(int W, int wt[], int val[], int n)
{
	int i, w;
	int dp[n+1][W+1];
	for (i = 0; i <= n; i++) dp[i][0] = 0;
	for (w = 0; w <= W; w++) dp[0][w] = 0;
	for (i = 1; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (wt[i-1] <= w)
				dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
			else
				dp[i][w] = dp[i-1][w];
		}
	}
	return dp[n][W];
}

int	main()
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	int i, j;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= W; j++)
			cache[i][j] = -1;
	printf("%d", knapsack(W, wt, val, n));
	return 0;
}
