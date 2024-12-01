#include <iostream>
#include <algorithm>
#include <vector>

int binarySearch(const std::vector<int>& arr, int x) {
	int q = 0, r = arr.size();
	while (q < r) {
		int k = q + (r - q) / 2;
		if (arr[k] == x) {
			return 1;
		}
		else if (x < arr[k]) {
			r = k;
		}
		else {
			q = k + 1;
		}
	}
	return 0;
}

int lowerBound(const std::vector<int>& arr, int x) {
	int q = 0, r = arr.size();
	while (q < r) {
		int k = q + (r - q) / 2;
		if (x <= arr[k]) {
			r = k;
		}
		else {
			q = k + 1;
		}
	}
	return q;
}

int upperBound(const std::vector<int>& arr, int x) {
	int q = 0, r = arr.size();
	while (q < r) {
		int k = q + (r - q) / 2;
		if (x < arr[k]) {
			r = k;
		}
		else {
			q = k + 1;
		}
	}
	return q;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int>arr(n, 0);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	int k;
	std::cin >> k;
	std::vector<int>requests(k, 0);
	for (int i = 0; i < k; ++i) {
		std::cin >> requests[i];
	}

	for (auto x : requests) {
		int b = binarySearch(arr, x);
		int l = lowerBound(arr, x);
		int r = upperBound(arr, x);
		std::cout << b << " " << l << " " << r << std::endl;
	}
	return 0;
}