//
// Created by yin on 2018/11/3.
//



#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
            return 1;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return (n % 2 == 0) ? pow(x * x, n / 2) : x * pow(x * x, n / 2);
    }

    //细节：有没有可能是负数的N次方？
    // 0的0次方是多少 1
    //
    // test code
    double Npow(double x, int y) {
        int size = y > 0 ? y : -y;
        double sum = size < 1 ? 1 : x;
        for (int i = 1; i < size; i++) {
            sum *= x;
        }
        return y > 0 ? sum : 1 / sum;
    }


    // test code
    double NRecurPow2(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return n%2==0 ? NRecurPow2(x*x, n/2) : x*NRecurPow2(x*x, n/2);
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            n = -n;
            x = 1/x;
//            return 1 / NRecurPow2(x, -n);
        }
        return n % 2 ? x * NRecurPow2(x*x, n /2) : NRecurPow2(x * x, n / 2);
    }

    // test code
    double NRecurPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n == -1) {
            return 1 / x;
        }
        // 奇数的N次方有bug
        double realX = n < 0 ? 1 / x : x;
        int N = n < 0 ? -N : N;
        return (N % 2 == 0) ? NRecurPow(realX * realX, N / 2) : NRecurPow(realX * realX, N / 2) * realX;
    }

    //https://leetcode.com/problems/majority-element/discuss/51613/O(n)-time-O(1)-space-fastest-solution
    //求众数，大于一半的数
    //{2,2,1,1,1,2,2}
    int majority(int *num, int count) {
        int major = num[0], cnt = 1;
        for (int i = 1; i < count; i++) {
            if (cnt == 0) {
                major = num[i];
                cnt = 1;
            } else if (num[i] == major) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return major;
    }

    //maxProfit https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
    int maxProfit(vector<int> &prices) {
        int totoal = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                totoal += prices[i] - prices[i - 1];
            }
        }
        return totoal;
    }

    int search(vector<int> &nums, int target) {
        int first = 0;
        //size-1
        int last = nums.size() - 1;
        //相等1. 循环退出条件 注意是 low<=high，而不是 lo...
        //
        //极客时间版权所有: https://time.geekbang.org/column/article/42520
        while (first <= last) {
            //相比除法运算，位运算更快
//            int mid = first + (last-first) /2;
            int mid = first + (last - first) >> 1;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return -1;
    }


    int searchFirst(vector<int> &nums, int target) {
        int first = 0;
        //size-1
        int last = nums.size() - 1;
        while (first <= last) {
            int mid = first + (last - first) >> 1;
            if (nums[mid] < target) {
                first = mid + 1;
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else {
                if (nums[mid] == target && nums[mid - 1] != target) {
                    return mid;
                } else {
                    last = mid - 1;
                }
            }
        }
        return -1;
    }

};

int main() {

    Solution s;
    printf("2^10=%f\n", s.NRecurPow2(2, -2147483648));

    int num[7] = {2, 2, 1, 1, 1, 2, 2};
    s.majority(num, 7);

}