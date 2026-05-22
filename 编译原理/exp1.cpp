#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring> // ? 修复 strchr 报错

using namespace std;

// 种别编码（严格对应表2.1）
#define WHILE 1
#define IF 2
#define ELSE 3
#define SWITCH 4
#define CASE 5
#define ID 6
#define NUM 7
#define ADD 8
#define SUB 9
#define MUL 10
#define RELOP 11
#define ASSIGN 12
#define SEMI 13

// 关键字表
const string keywords[] = {"while", "if", "else", "switch", "case"};
const int key_num = 5;

// 词法单元结构体
struct Token
{
    int code;
    string value;
};

vector<Token> tokens;
bool error_flag = false;

// 判断是否为关键字
int isKeyword(const string &str)
{
    for (int i = 0; i < key_num; i++)
    {
        if (str == keywords[i])
            return i + 1;
    }
    return 0;
}

// 词法分析函数
void lex(const string &input)
{
    tokens.clear();
    error_flag = false;

    int i = 0;
    int len = input.length();

    while (i < len)
    {

        // 1. 跳过空白
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        string temp;
        int key_code = 0;

        // 2. 关键字 / 标识符
        if (isalpha(input[i]))
        {
            while (isalnum(input[i]))
            {
                temp += input[i++];
                key_code = isKeyword(temp);
                if (key_code != 0)
                    break;
            }

            Token t;
            t.value = temp;

            if (key_code != 0)
                t.code = key_code;
            else
                t.code = ID;

            tokens.push_back(t);
            continue;
        }

        // 3. 常数
        if (isdigit(input[i]))
        {
            temp.clear();
            while (isdigit(input[i]))
            {
                temp += input[i++];
            }

            Token t;
            t.code = NUM;
            t.value = temp;
            tokens.push_back(t);
            continue;
        }

        // 4. 运算符 + - *
        if (strchr("+-*", input[i]))
        {
            Token t;
            t.value = input[i++];

            if (t.value == "+")
                t.code = ADD;
            if (t.value == "-")
                t.code = SUB;
            if (t.value == "*")
                t.code = MUL;

            tokens.push_back(t);
            continue;
        }

        // 5. 关系运算符 / 赋值符
        if (strchr("<>=", input[i]))
        {
            temp.clear();
            temp += input[i++];

            if (i < len && input[i] == '=')
            {
                temp += input[i++];
            }

            Token t;
            t.value = temp;

            if (temp == "=")
                t.code = ASSIGN;
            else
                t.code = RELOP;

            tokens.push_back(t);
            continue;
        }

        // 6. 界符 ;
        if (input[i] == ';')
        {
            Token t;
            t.code = SEMI;
            t.value = input[i++];
            tokens.push_back(t);
            continue;
        }

        // 7. 错误处理
        Token t;
        t.code = -1;
        t.value = "FOUND ERROR";
        tokens.push_back(t);
        error_flag = true;
        i++;
    }
}

int main()
{
    string input;
    string totalInput; // 用于累积所有输入

    cout << "===== C语言子集词法分析器 (C++版) =====" << endl;
    cout << "请输入源程序字符串（以 # 结束，可以多行输入）：" << endl;

    while (true)
    {
        string line;
        getline(cin, line);

        // 检查这一行是否包含 '#'
        size_t pos = line.find('#');
        if (pos != string::npos)
        {
            // 将 '#' 之前的部分加入 totalInput
            totalInput += line.substr(0, pos);
            break;
        }
        else
        {
            // 否则，将整行加入 totalInput，并添加一个换行符（因为 getline 会丢弃换行符）
            totalInput += line + '\n';
        }
    }

    // 现在 totalInput 包含了所有输入（直到 '#' 之前）
    lex(totalInput);

    cout << "\n词法分析结果 (种别编码, 单词自身)：" << endl;
    for (auto &t : tokens)
    {
        if (t.code == -1)
            cout << t.value << endl;
        else
            cout << "(" << t.code << ", " << t.value << ")" << endl;
    }

    if (!error_flag)
        cout << "分析完成，未发现错误。" << endl;

    return 0;
}