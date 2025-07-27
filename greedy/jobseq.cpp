#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;  // Sort descending by profit
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details in format: ID Deadline Profit\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Step 1: Sort by profit
    sort(jobs.begin(), jobs.end(), cmp);

    // Step 2: Find max deadline
    int maxDeadline = 0;
    for (auto job : jobs) {
        if (job.deadline > maxDeadline)
            maxDeadline = job.deadline;
    }

    // Step 3: Create slots, all free initially (using '-')
    vector<char> slot(maxDeadline + 1, '-');

    int totalProfit = 0;

    // Step 4: Assign jobs to the latest free slot before deadline
    for (auto job : jobs) {
        for (int t = job.deadline; t > 0; t--) {
            if (slot[t] == '-') {  // slot free?
                slot[t] = job.id;   // assign job
                totalProfit += job.profit;
                break;
            }
        }
    }

    // Step 5: Print scheduled jobs and total profit
    cout << "Scheduled jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != '-') cout << slot[i] << " ";
    }
    cout << "\nTotal profit: " << totalProfit << endl;

    return 0;
}
