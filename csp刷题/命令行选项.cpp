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
            mp[s[i]] = 2; // �в��ַ������Ϊ2
        else if (s[i] != ':')
            mp[s[i]] = 1; // �޲��ַ������Ϊ1
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
        map<char, string> mq; // ��map�洢ÿ������ĺϷ���
        getline(cin, s);
        stringstream ssin(s); // ���ַ�������s
        vector<string> str;
        while (ssin >> s)
            str.push_back(s);                // ��ÿ���ַ������뵽str��
        for (int j = 1; j < str.size(); j++) // str[0]Ϊ"ls"��ʡ�ԣ�ֱ�Ӵ�1��ʼ
        {
            if (str[j][0] != '-' || str[j][1] < 'a' || str[j].size() != 2)
                break; // �Ժ���'-'���ַ��������ж�(�޲Ρ��в��ַ��Ŀ�ͷ)
            char c = str[j][1];
            if (mp[c] == 1)
                mq[c] = c;
            else if (mp[c] == 2 && (j + 1) < str.size())
                mq[c] = str[j + 1], j++; // ���в��ַ���ֵ��ֵΪ������һ��Ԫ�أ�j++ֱ����������
            else
                break; // �������Ϸ���ֱ������ѭ��
        }
        cout << "Case " << i << ":";
        for (auto x : mq)
            if (mp[x.first] == 1)
                cout << " -" << x.second; // ����޲�
            else
                cout << " -" << x.first << " " << x.second; // ����в�
        cout << endl;
    }
    return 0;
}