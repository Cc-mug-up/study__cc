
import java.sql.*;

public class cc {

    public static void main(String[] args) {
        //���ӽӿ�
        Connection con = null;
        //����SQL�ӿ�
        Statement smt = null;
        //������ӿ�
        ResultSet rs = null;
        try {
            //1. ����JDBC��������
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://127.0.0.1:3306/test2?useSSL=false&serverTimezone=UTC&characterEncoding=utf8";
            String userName = "root";
            String password = "134121";
            //2. �������ݿ�
            con = DriverManager.getConnection(url, userName, password);
            smt = con.createStatement();
            String sql = "select * from student " + "where Sname!='����'";
            rs = smt.executeQuery(sql);
            while (rs.next()) {
                int id = rs.getInt(1);
                String name = rs.getString("Sname");
                // int age = rs.getInt(3);
                String studentNo = rs.getString("Sno");
                String major = rs.getString(5);
                //Date date = rs.getDate("Sbirthdate");
                // System.out.println(date);
                System.out.println(id + " ������" + name + " ѧ�ţ�" + studentNo + " רҵ: " + major);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // 5. �ر�����
            if (con != null) {
                try {
                    con.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }

    }
}
