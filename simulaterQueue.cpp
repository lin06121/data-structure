//
// Created by 玉林 on 25-3-18.
//
#include <iostream>
#include <cstdlib>
#include "Queue.h"

using namespace std;

int vanTime = 0;
int busTime = 0;
int currentTime = 0;
int busWaitTime = 0;
int vanWaitTime = 0;
int buscount=0;
int vancount=0;
Queue<int> busQueue, vanQueue;

void simulateQueue(int busHigh, int busLow, int vanHigh, int vanLow, int m, int n) {
    int i = 0, j = 0;

    for (currentTime = 0;; currentTime += 10) {
        busTime += rand() % (busHigh - busLow + 1) + busLow;
        busQueue.enQueue(busTime);
        i++;

        vanTime += rand() % (vanHigh - vanLow + 1) + vanLow;
        vanQueue.enQueue(vanTime);
        j++;

        if (i > m || j > n) break;

        int ship;
        for (ship = 0; ship < 8 && !busQueue.isEmpty() && busQueue.getHead() <=currentTime ; ship++) {
            busWaitTime +=  currentTime-busQueue.deQueue();
            buscount+=1;
        }

        for (; ship < 10 && !vanQueue.isEmpty() && vanQueue.getHead() <= currentTime ; ship++) {
            vanWaitTime += -vanQueue.deQueue() + currentTime;
            vancount+=1;
        }

        for (; ship < 10 && !busQueue.isEmpty() && busQueue.getHead() <= currentTime ; ship++) {
            busWaitTime += -busQueue.deQueue() + currentTime;
            buscount+=1;
        }
    }
}

int main() {
    int busHigh, busLow, vanHigh, vanLow, m, n;

    cout << "Please input bus and van time range (busHigh busLow vanHigh vanLow): ";
    cin >> busHigh >> busLow >> vanHigh >> vanLow;

    cout << "Please input bus and van queue sizes (m n): ";
    cin >> m >> n;

    simulateQueue(busHigh, busLow, vanHigh, vanLow, m, n);

    cout << "Average bus wait time: " << (m ? (busWaitTime / m) : 0) << " minutes" << endl;
    cout << "Average van wait time: " << (n ? (vanWaitTime / n) : 0) << " minutes" << endl;
    cout<<"left bus van number "<< (m-buscount )<<" "<<(n-vancount );
    return 0;
}

