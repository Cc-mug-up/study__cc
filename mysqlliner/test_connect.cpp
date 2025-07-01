#include <iostream>
#include <mysql.h>
using namespace std;
int main()
{
    MYSQL *mysql = mysql_init(0);
    if (!mysql_real_connect(mysql, "localhost", "root", "134121", "test2", 3306, 0, 0)) // ע��ĳ��Լ���
    {
        printf("�������ݿ����%s\n", mysql_error(mysql));
        return -1;
    }
    cout << "DB connect success" << endl;

    // ִ�в�ѯ
    if (mysql_query(mysql, "SELECT * FROM sc"))
    {
        printf("��ѯ����%s\n", mysql_error(mysql));
        mysql_close(mysql);
        return -1;
    }

    // ��ȡ�����
    MYSQL_RES *result = mysql_store_result(mysql);
    if (result == NULL)
    {
        printf("��ȡ���������%s\n", mysql_error(mysql));
        mysql_close(mysql);
        return -1;
    }

    // ��ȡ�ֶ�����
    int num_fields = mysql_num_fields(result);

    // ���������е�ÿһ��
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            cout << row[i] << " ";
        }
        cout << endl;
    }

    // �ͷŽ����
    mysql_free_result(result);

    // �ر����ݿ�����
    mysql_close(mysql);
    return 0;
}
