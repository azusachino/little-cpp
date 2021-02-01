//
// Created by ycpang on 2021-02-01.
//

// 使用 POSIX 编写多线程 C++ 程序。
#include <iostream>
#include <cstdlib>
#include <pthread.h>

// pthread_create (thread, attr, start_routine, arg) 创建线程
// thread	指向线程标识符指针。
// attr	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
// start_routine	线程运行函数起始地址，一旦线程被创建就会执行。
// arg	运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。
// pthread_exit (status) 终止线程
using namespace std;

#define NUM_THREADS 5

// 线程的运行函数
void *say_hello(void *args) {
    cout << "Hello Runoob！" << endl;
    return 0;
}

int main() {
    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0) {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}

void *PrintHello(void *threadid) {
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *) threadid);
    cout << "Hello Runoob! 线程 ID, " << tid << endl;
    pthread_exit(NULL);
    return 0;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];// 用数组来保存i的值
    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() : 创建线程, " << i << endl;
        indexes[i] = i; //先保存i的值
        // 传入的时候必须强制转换为void* 类型，即无类型指针
        rc = pthread_create(&threads[i], NULL,
                            PrintHello, (void *) &(indexes[i]));
        if (rc) {
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

// 向线程传递参数

struct thread_data {
    int thread_id;
    char *message;
};

void *PrintHello(void *threadarg) {
    struct thread_data *my_data;

    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID : " << my_data->thread_id;
    cout << " Message : " << my_data->message << endl;

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *) "This is message";
        rc = pthread_create(&threads[i], NULL,
                            PrintHello, (void *) &td[i]);
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

// 连接和分离线程

void *wait(void *t) {
    int i;
    long tid;

    tid = (long) t;

    sleep(1);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

int main() {
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;

    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, wait, (void *) &i);
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}