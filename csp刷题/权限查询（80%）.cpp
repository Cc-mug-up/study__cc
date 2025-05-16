#include <bits/stdc++.h>
using namespace std;
struct node
{
    string name;
    int hie;
    node()
    {
        name = "";
        hie = -1;
    }
    node(string n) : name(n), hie(-1) {}
    node(string n, int h)
    {
        name = n;
        hie = h;
    }
};
map<string, node> fis;
map<string, vector<node>> sec;
map<string, vector<string>> user;
void first()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str, str1;
        getline(cin, str);
        int h = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ':')
            {
                h = stoi(str.substr(i + 1));
                str1 = str.substr(0, i);
                // cout << h << str1 << endl;
                break;
            }
        }
        if (h == -1)
        {
            node no(str);
            fis.insert({str, no});
        }
        else
        {
            node no(str1, h);
            fis.insert({str1, no});
        }
    }
    // cout << 222;
}
void second()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str, real, de;
        vector<node> val;
        int cur = 0, num = 0;
        getline(cin, str);
        str += " ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ' && cur == 0)
            {
                real = str.substr(cur, i);
                cur = i + 1;
            }
            else if (str[i] == ' ' && cur != 0)
            {
                de = str.substr(cur, i - cur);
                cur = i + 1;
                if (de[0] >= 48 && de[0] <= 57)
                {
                    num = stoi(de);
                }
                else
                {
                    int h = -1;
                    string s;
                    for (int j = 0; j < de.size(); j++)
                    {
                        if (de[j] == ':')
                        {
                            s = de.substr(0, j);
                            h = stoi(de.substr(j + 1));
                            break;
                        }
                    }
                    if (h == -1)
                    {
                        if (fis.find(de) != fis.end())
                        {
                            val.push_back(fis[de]);
                        }
                    }
                    else
                    {
                        if (fis.find(s) != fis.end())
                        {
                            node no(fis[s].name, h);
                            val.push_back(no);
                        }
                    }
                }
            }
        }
        sec.insert({real, val});
    }
}
void third()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str, real, de;
        vector<string> strs;
        int cur = 0;
        getline(cin, str);
        str += " ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ' && cur == 0)
            {
                real = str.substr(0, i);
                cur = i + 1;
            }
            else if (str[i] == ' ' && cur != 0)
            {
                de = str.substr(cur, i - cur);
                cur = i + 1;
                if (de[0] > 57 || de[0] < 48)
                    strs.push_back(de);
            }
        }
        user.insert({real, strs});
    }
}
int main()
{
    first();
    // cout << 1111;
    second();
    third();
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str, real, de;
        int cur = 0;
        getline(cin, str);
        str += " ";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ' && cur == 0)
            {
                real = str.substr(0, i);
                cur = i + 1;
            }
            else if (str[i] == ' ' && cur != 0)
            {
                de = str.substr(cur, i - cur);
                cur = i + 1;
                int h = -1;
                string s;
                for (int j = 0; j < de.size(); j++)
                {
                    if (de[j] == ':')
                    {
                        s = de.substr(0, j);
                        h = stoi(de.substr(j + 1));
                    }
                }
                if (h != -1)
                    de = s;
                if (user.find(real) == user.end())
                {
                    cout << "false" << endl;
                }
                else if (h == -1 && fis[de].hie == -1)
                {
                    int cnt = 0;
                    bool flag = false;
                    vector<string> now = user[real];
                    for (auto &x : now)
                    {
                        for (auto y : sec[x])
                        {
                            if (y.name == de && y.hie == -1)
                                flag = true;
                        }
                    }
                    if (flag)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                }
                else if (h == -1 && fis[de].hie != -1)
                {

                    int cnt = 0;
                    bool flag = false;
                    vector<string> now = user[real];
                    for (auto &x : now)
                    {
                        for (auto y : sec[x])
                        {
                            if (y.name == de && y.hie > cnt)
                                cnt = y.hie;
                        }
                    }
                    if (cnt == 0)
                        cout << "false" << endl;
                    else
                        cout << cnt << endl;
                }
                else if (h != -1)
                {
                    // cout << " " << h << " " << fis[de].hie << " " << de << " ";
                    bool flag = false;
                    vector<string> now = user[real];
                    for (auto &x : now)
                    {
                        for (auto y : sec[x])
                        {
                            if (y.name == de && y.hie >= h)
                                flag = true;
                        }
                    }
                    if (flag)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                }
            }
        }
    }
    return 0;
}