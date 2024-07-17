#include "include/handle.h"
#include "include/_pre_handle.h"
using namespace std;
int main() {
    try {
        vector<string> t = _compile_evaluate("a=4+5;");
        for(string s:t) {
            cout<<s<<endl;
        }
        cout<<"size:" << t.size() << endl;        
    } catch (string str) {
        cout << str << endl;
    }

}