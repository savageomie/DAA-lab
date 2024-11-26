#include <bits/stdc++.h>
using namespace std;

class SalaryCalculator {
private:
    float basicSalary;
    float HRA;
    float DA;
    float PF;
    float other;
    float taxes;
    float gross;
    float net;

public:
    SalaryCalculator(float basic) {
        basicSalary = basic;
        HRA = 0.2 * basic;
        DA = 0.1 * basic;
        PF = 0.12 * basic;
        other = 0.15 * basic;
        taxes = 0.2 * basic;
        gross = basicSalary + HRA + DA + other;
        net = gross - PF - taxes;
    }

    float getNetSalary(){
        return net;
    }
};

float Findmin(vector<float>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }
    if (right == left + 1) {
        return min(arr[left], arr[right]);
    }

    int mid = left + (right - left) / 2;
    float minleft = Findmin(arr, left, mid);
    float minright = Findmin(arr, mid + 1, right);

    return min(minleft, minright);
}

float findMax(const vector<float>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    if (right == left + 1) {
        return max(arr[left], arr[right]);
    }

    int mid = left + (right - left) / 2;
    float leftMax = findMax(arr, left, mid);
    float rightMax = findMax(arr, mid + 1, right);

    return max(leftMax, rightMax);
}

int main() {
    // Sample data: array of basic salaries
    float basicSalaries[10] = {12000,22000,73000,47000,53000,67000,89000,7000,48000,9000};
    vector<float> netSalaries(10);

    // Calculate net salaries using SalaryCalculator
    for (int i = 0; i < 10; i++) {
        SalaryCalculator sc(basicSalaries[i]);
        netSalaries[i] = sc.getNetSalary();
    }

    // Find the minimum and maximum salary using divide and conquer
    float minSalary = Findmin(netSalaries, 0, netSalaries.size() - 1);
    float maxSalary = findMax(netSalaries, 0, netSalaries.size() - 1);

    // Output results
    cout << "Employee with minimum salary has: " << minSalary << endl;
    cout << "Employee with maximum salary has: " << maxSalary << endl;

    return 0;
}
