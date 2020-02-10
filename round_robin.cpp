#include<iostream>
#include<queue>
#include<numeric>

using namespace std;

float avg_waiting_time(int arr[], int bur[], int size) {
    int time_quantum = 2;
    float avgwt = 0;
    int rem_bur[size] ;
    int waiting_time[size] = {0};
    copy(bur,bur+size,rem_bur);
    // for(int i : rem_bur)
    //     cout<<i<<endl;
    queue<int> processes;
    int time = 0;
    int total_time = 0;
    int index = 0;
    for(int i = index; arr[i]<=time; i++) {
            processes.push(i);
            index++;
        }
    total_time = accumulate(bur,bur+size, total_time);
    // cout<<"Total time : "<<total_time<<endl;
    // for(queue<int> demo = processes; !demo.empty(); demo.pop())
    //     cout<<demo.front()<<" ";
    // cout<<endl;
    // cout<<"Index : "<<index<<"  Time : "<<time<<endl;
    while (time < total_time)
    {
        int curr_process = processes.front();
        processes.pop();
        if(rem_bur[curr_process] > time_quantum) {
            time += time_quantum;
            rem_bur[curr_process]-=time_quantum;
            for(int i = index; arr[i]<=time && i < size; i++) {
                processes.push(i);
                index++;
            }
            processes.push(curr_process);
        }
        else {
            time += rem_bur[curr_process];
            rem_bur[curr_process] = 0;
            waiting_time[curr_process] = time - arr[curr_process] - bur[curr_process];
            for(int i = index; arr[i]<=time && i < size; i++) {
                processes.push(i);
                index++;
            }
        }
        // for(queue<int> demo = processes; !demo.empty(); demo.pop())
        // cout<<demo.front()<<" ";
        // cout<<endl;
        // cout<<"Index : "<<index<<"  Time : "<<time<<endl;
    }
    // for(int i : waiting_time)
    //     cout<<i<<" ";
    // cout<<endl;
    avgwt = accumulate(waiting_time, waiting_time+size, avgwt)/size;
    // cout<<"Average waiting time : "<<avgwt<<endl;
    return avgwt;
}

int main() {
    int arrival_time[5] = {0,2,3,5,6};
    int burst_time[5] = {4,3,1,3,1};
    int size = sizeof(arrival_time)/sizeof(arrival_time[0]);
    cout<<"Average waiting time : "<<avg_waiting_time(arrival_time, burst_time, size)<<endl;
    return 0;
}