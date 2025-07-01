
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnectionTest {

    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/root";
        String user = "root";
        String password = "134121";
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url, user, password);
            System.out.println("数据库连接成功！");
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
