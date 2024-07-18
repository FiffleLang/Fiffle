#include "include/handle.h"
#include "include/_pre_handle.h"
using namespace std;
int main() {
    try {
        vector<string> t = _compile_execute("test(114, a=514);");
        for(string s:t) {
            cout<<s<<endl;
        }
        cout<<"size:" << t.size() << endl;        
    } catch (string str) {
        cout << str << endl;
    }

}