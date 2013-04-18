#include <iostream>
#include <string>
#include <vector>
using namespace std;

//字符串分割函数
vector<string> split(string str, string pattern)
{
    string::size_type pos;
    vector<string> result;
    str += pattern; //扩展字符串以方便操作
    int size = str.size();

    for (int i = 0; i < size; i++) {
        pos = str.find(pattern, i);

        if (pos < size) {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }

    return result;
}

int main()
{
    int T;
    cin >> T;

    while (T --) {
        int N, M;
        cin >>N >> M;
        string a[110], b[110];

        for (int i = 0; i < M; i++) {
            cin >> a[i] >> b[i];
        }

        string str;
        getline(cin, str);
        string pattern = " ";
        cout << "str: " << str << endl;
        vector<string> result = split(str, pattern);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }


    return 0;
}
