#include "include/handle.h"
#include "include/_pre_handle.h"
// #include <windows.h>
using namespace std;
int main() {
    try {
        auto start = std::chrono::high_resolution_clock::now();
        vector<string> t = _compile_execute("test(114, a=garbage(514));");
        for(string s:t) {
            cout<<s<<endl;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout<<"size:" << t.size() << endl;        
        cout<<"time:" << duration.count() << " us" << endl;
    } catch (string str) {
        cout << str << endl;
    }

}