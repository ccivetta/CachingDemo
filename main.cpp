
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {

    vector<int> myvec;
    vector<int> myvec2;
    clock_t clock_time;

    clock_time = clock();
    for (int i = 0; i < 9999999; i++) {
        myvec.push_back(999);
    }
    clock_time = clock() - clock_time;

    printf("Loop without index in register took %f seconds \n", ((float) clock_time / CLOCKS_PER_SEC));
    cout<<"Loop without index in register took " << (float) clock_time / CLOCKS_PER_SEC << " seconds" << endl;

    myvec.clear();

    clock_time = clock();
    for (register int t = 0; t < 9999999; t++) {
        myvec2.push_back(999);
    }
    clock_time = clock() - clock_time;

    myvec2.clear();


    printf("Loop with index in register took %f seconds \n", ((float) clock_time / CLOCKS_PER_SEC));

    alignas(16) int a[4];
    alignas(1024) int b[4];

    printf("%p\n", a);
    printf("%p\n", b);

    if (alignof(a) == 16) {
        cout << "int a aligned to 16 bytes" << endl;
    }

    if (alignof(b) == 1024) {
        cout << "int b aligned to 1024 bytes" << endl;
    }
}
