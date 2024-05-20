#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;
using std::make_pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    // Min-heap to store the next available time and worker index
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;

    // Initialize the heap with all workers being available at time 0
    for (int i = 0; i < num_workers_; ++i) {
      pq.push(make_pair(0, i));
    }

    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      auto next_worker = pq.top();
      pq.pop();

      assigned_workers_[i] = next_worker.second;
      start_times_[i] = next_worker.first;

      pq.push(make_pair(next_worker.first + duration, next_worker.second));
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
