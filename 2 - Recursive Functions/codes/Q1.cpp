#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string replace_character(string& str, string& temp, int n) {
    if (str.size() == pow(2, n - 1)) {
        return str;
    }
    else {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0')
                temp.append("01");
            else  if (str[i] == '1')
                temp.append("10");
        }
        str = temp;
        temp.clear();
        return replace_character(str, temp, n);
    }
}
void print_charactar(string str, int k) {
    cout << str[k - 1] << endl;
}
void run() {
    int n, k;
    string str = "0";
    string temp;
    cin >> n >> k;
    str = replace_character(str, temp, n);
    print_charactar(str, k);

}
int main()
{
    run();
}