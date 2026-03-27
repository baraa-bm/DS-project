#ifndef ADS_PROJECT_TASK_H
#define ADS_PROJECT_TASK_H


class task {
public:
    int id;
    int priority;
    int excution_duration;
    int arrival_time;

    int waiting_time;

    task();
    task(int,int,int,int);
};


#endif //ADS_PROJECT_TASK_H
