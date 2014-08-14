/* The number of settings s belongs to {2, 3, 4}. Let's assume the switch is off
If s = 2, then if pull the chain an even number of times n, the fan will be off ie 
if n % 2 = 0. So we want the smallest postive integer p s.t. p % 2 = p % 3 = p % 4 = 0
Thus p = 12. As we have already pulled chain once, the solution is 11 */