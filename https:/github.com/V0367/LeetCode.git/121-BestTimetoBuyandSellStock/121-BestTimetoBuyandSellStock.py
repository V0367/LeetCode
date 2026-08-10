# Last updated: 10/08/2026, 12:50:28
1class Solution(object):
2    def maxProfit(self, prices):
3        min_price = prices[0]
4        max_profit = 0
5
6        for i in range(len(prices)):
7            if prices[i]<min_price:
8                min_price=prices[i]
9            profit = prices[i] - min_price
10            max_profit = max(profit,max_profit)
11
12        return max_profit