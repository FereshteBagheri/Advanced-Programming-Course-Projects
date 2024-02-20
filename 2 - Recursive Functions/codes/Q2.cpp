
#include <iostream>
#include <string>
using namespace std;
bool is_subsequence(string const &str, string const &sub) {
    if (sub == "")
        return true;
    if (str == "")
        return false;
    if (sub[0] == str[0])
        return is_subsequence(str.substr(1), sub.substr(1));
    else
        return is_subsequence(str.substr(1), sub);
}


string delete_subsequence(string& str, string& sub) {
    if (sub.size() == 0)
        return str;
    else {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == sub[0]) {
                str.erase(i, 1);
                break;
            }
        }
        sub.erase(0, 1);
        return delete_subsequence(str, sub);
    }
}

void final_check(string sub1, string sub2, string str) {
    string str_copy = str;
    if (delete_subsequence(str, sub1) == sub2 || delete_subsequence(str_copy, sub2) == sub1)
        cout << "Interleaving";
    else
        cout<<  "Not Interleaving";
}
void run() {
    string sub1;
    string sub2;
    string str;
    cin >> sub1;
    cin >> sub2;
    cin >> str;
    if (is_subsequence(str, sub1) && is_subsequence(str, sub2)) {
        final_check(sub1, sub2, str);
    }
    else
        cout << "Not Interleaving";

}
int main()
{
    run();
}
