#include <memory>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    auto del_int = [](int *p) {
        cout << "deleting int" << endl;
        delete p;
    };
    {
        unique_ptr<int, decltype(del_int)> p(new int(3), del_int);
        cout << "val: " << *p << endl;
    }

    auto del_int_array = [](int *p) {
        cout << "deleting int array" << endl;
        delete [] p;
    };
    {
        unique_ptr<int[], decltype(del_int_array)> arr(new int[3], 
                                                       del_int_array);
        for (int i = 0; i < 3; i++) {
            arr[i] = i*2;
        }
        for (int i = 0; i < 3; i++) {
            cout << "i: " << arr[i] << endl;;
        }
    }
}
