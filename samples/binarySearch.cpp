int binarySearch(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (dp[mid] < target) { 
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return right;
}