prefix[r] = 2 * prefix[r - 1];

prefix[r + 1] >= prefix[r] >= 2 * prefix[r - 1];

doi k < r;

--> prefix[r] - k == 2 * prefix[r - 1];

1, 2, 3, ... , v, ..., k - 1, k
sum(1 --> k - 1) == k;