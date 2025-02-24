#include <condition_variable>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>
#include <atomic>

std::queue<int> data_queue;
std::mutex mutex;
std::condition_variable cv;
std::atomic<bool> done{false};

void producer() {
    for (uint64_t i = 0; i < 5; ++i) {
        {
            std::unique_lock<std::mutex> lock(mutex);
            data_queue.push(i);
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {
        done = true;
    }
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, []{ return !data_queue.empty() || done; });
        while (!data_queue.empty()) {
            std::cout << "Consumed: " << data_queue.front() << std::endl;
            data_queue.pop();
        }
        if (done) break;
    }
}

int main() {
    std::thread t1{producer};
    std::thread t2{consumer};

    t1.join();
    t2.join();

    return 0;
}