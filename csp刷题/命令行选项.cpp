#include <bits/stdc++.h>
using namespace std;
int n;
string s;
unordered_map<char, int> mp;
void work()
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ' ')
            break;
        if (s[i] != ':' && s[i + 1] == ':')
            mp[s[i]] = 2; // 有参字符，标记为2
        else if (s[i] != ':')
            mp[s[i]] = 1; // 无参字符，标记为1
    }
}
int main()
{
    cin >> s;
    s = s + ' ';
    work();
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++)
    {
        map<char, string> mq; // 用map存储每行命令的合法项
        getline(cin, s);
        stringstream ssin(s); // 用字符流处理s
        vector<string> str;
        while (ssin >> s)
            str.push_back(s);                // 将每个字符串加入到str中
        for (int j = 1; j < str.size(); j++) // str[0]为"ls"，省略，直接从1开始
        {
            if (str[j][0] != '-' || str[j][1] < 'a' || str[j].size() != 2)
                break; // 对含有'-'的字符串进行判断(无参、有参字符的开头)
            char c = str[j][1];
            if (mp[c] == 1)
                mq[c] = c;
            else if (mp[c] == 2 && (j + 1) < str.size())
                mq[c] = str[j + 1], j++; // 将有参字符的值赋值为它的下一个元素，j++直接跳过参数
            else
                break; // 条件不合法，直接跳出循环
        }
        cout << "Case " << i << ":";
        for (auto x : mq)
            if (mp[x.first] == 1)
                cout << " -" << x.second; // 输出无参
            else
                cout << " -" << x.first << " " << x.second; // 输出有参
        cout << endl;
    }
    return 0;
}