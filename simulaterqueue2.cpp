//
// Created by 玉林 on 25-3-19.
//
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <random>

using namespace std;

// 事件结构
struct Event {
    double time;  // 事件发生时间
    int customer_id;  // 客户编号
    string type;  // "arrival" or "finish"

    // 让 priority_queue 以时间升序排序
    bool operator<(const Event &other) const {
        return time > other.time;
    }
};

// 事件驱动模拟类
class QueueSimulation {
private:
    double A_min, A_max, S_min, S_max;
    int total_customers;
    priority_queue<Event> event_queue;  // 事件队列
    queue<int> waiting_queue;  // 客户等待队列
    bool server_busy = false;
    int customer_id = 0;
    double current_time = 0.0;
    map<int, double> arrival_time;  // 记录客户到达时间
    double total_wait_time = 0.0;   // 总等待时间
    random_device rd;
    mt19937 gen;
    uniform_real_distribution<double> arrival_dist;
    uniform_real_distribution<double> service_dist;

public:
    QueueSimulation(double A_min, double A_max, double S_min, double S_max, int total_customers)
        : A_min(A_min), A_max(A_max), S_min(S_min), S_max(S_max), total_customers(total_customers),
          gen(rd()), arrival_dist(A_min, A_max), service_dist(S_min, S_max) {}

    // 添加事件
    void schedule_event(double time, const string &type, int customer_id) {
        event_queue.push({time, customer_id, type});
    }

    // 运行仿真
    void run() {
        double first_arrival_time = arrival_dist(gen);
        schedule_event(first_arrival_time, "arrival", customer_id);

        while (!event_queue.empty()) {
            Event event = event_queue.top();
            event_queue.pop();
            current_time = event.time;

            if (event.type == "arrival") {
                handle_arrival(event);
            } else if (event.type == "finish") {
                handle_finish(event);
            }
        }

        // 计算平均等待时间
        double avg_wait_time = total_wait_time / total_customers;
        cout << "平均等待时间: " << avg_wait_time << " 秒\n";
    }

    // 处理客户到达
    void handle_arrival(const Event &event) {
        cout << "[" << current_time << "] 客户 " << event.customer_id << " 到达\n";
        arrival_time[event.customer_id] = current_time;  // 记录到达时间

        if (!server_busy) {
            server_busy = true;
            double service_time = service_dist(gen);
            double finish_time = current_time + service_time;
            schedule_event(finish_time, "finish", event.customer_id);
        } else {
            waiting_queue.push(event.customer_id);
        }

        if (customer_id < total_customers - 1) {
            customer_id++;
            double next_arrival_time = current_time + arrival_dist(gen);
            schedule_event(next_arrival_time, "arrival", customer_id);
        }
    }

    // 处理客户完成服务
    void handle_finish(const Event &event) {
        cout << "[" << current_time << "] 客户 " << event.customer_id << " 完成服务\n";

        if (!waiting_queue.empty()) {
            int next_customer = waiting_queue.front();
            waiting_queue.pop();
            double wait_time = current_time - arrival_time[next_customer];  // 计算等待时间
            total_wait_time += wait_time;

            double service_time = service_dist(gen);
            double finish_time = current_time + service_time;
            schedule_event(finish_time, "finish", next_customer);
        } else {
            server_busy = false;
        }
    }
};

// 主函数
int main() {
    double A_min = 1.0, A_max = 3.0;
    double S_min = 2.0, S_max = 5.0;
    int total_customers = 10;

    QueueSimulation simulator(A_min, A_max, S_min, S_max, total_customers);
    simulator.run();

    return 0;
}
