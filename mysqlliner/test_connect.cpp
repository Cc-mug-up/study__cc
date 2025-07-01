#include <iostream>
#include <mysql.h>
using namespace std;
int main()
{
    MYSQL *mysql = mysql_init(0);
    if (!mysql_real_connect(mysql, "localhost", "root", "134121", "test2", 3306, 0, 0)) // 注意改成自己的
    {
        printf("连接数据库出错：%s\n", mysql_error(mysql));
        return -1;
    }
    cout << "DB connect success" << endl;

    // 执行查询
    if (mysql_query(mysql, "SELECT * FROM sc"))
    {
        printf("查询出错：%s\n", mysql_error(mysql));
        mysql_close(mysql);
        return -1;
    }

    // 获取结果集
    MYSQL_RES *result = mysql_store_result(mysql);
    if (result == NULL)
    {
        printf("获取结果集出错：%s\n", mysql_error(mysql));
        mysql_close(mysql);
        return -1;
    }

    // 获取字段数量
    int num_fields = mysql_num_fields(result);

    // 输出结果集中的每一行
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            cout << row[i] << " ";
        }
        cout << endl;
    }

    // 释放结果集
    mysql_free_result(result);

    // 关闭数据库连接
    mysql_close(mysql);
    return 0;
}
