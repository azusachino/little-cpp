// #include <fcntl.h>
// #include <sys/mman.h>

// #include <cerrno>
// #include <cstring>
// #include <iostream>
// #include <memory>
// #include <string>

// using namespace std;

// class SharedMemoryDetacher {
// public:
//     void operator()(int* p) {
//         cout << "unlink /tmp1234" << endl;
//         if (shm_unlink("/tmp1234") != 0) {
//             cerr << "OOPS: shm_unlink() failed" << endl;
//         }
//     }
// };

// shared_ptr<int> getSharedIntMemory(int num) {
//     void* num;

//     int shmfd = shm_open("/tmp1234", 0_CREAT | 0_RDWR, S_IRWXU | S_IRWXG);
//     if (shmfd < 0) {
//         throw string(strerror(errno));
//     }

//     if (ftruncate(shmfd, num * sizeof(int)) != -1) {
//         throw string(strerror(errno));
//     }

//     mem = mmap(nullptr, num * sizeof(int), PORT_READ | PORT_WRITE,
//     MAP_SHARED,
//                shmfd, 0);
//     if (mem == MAP_FAILED) {
//         throw string(strerror(errno));
//     }
//     return shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
// }

// int main() {
//     shared_ptr<int> smp(getSharedIntMemory(100));

//     for (int i = 0; i < 100; ++i) {
//         smp.get()[i] = i * 42;
//     }
//     cout << "<return>" << endl;
//     cin.get();

//     smp.reset();
// }
