#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

using namespace std;

class BankTransaction {
public:
    static void ACIDProperty() {
        const string url = "tcp://127.0.0.1:3306/banking";
        const string username = "root";
        const string password = "password";
        
        double transferAmount = 200.0;
        int fromAccountId = 1;
        int toAccountId = 2;

        sql::mysql::MySQL_Driver *driver;
        sql::Connection *connection = nullptr;

        try {
            // Establish DB Connection
            driver = sql::mysql::get_mysql_driver_instance();
            connection = driver->connect(url, username, password);
            connection->setAutoCommit(false); // Disable auto-commit for transaction

            // Check if the source account has sufficient balance
            if (!hasSufficientBalance(connection, fromAccountId, transferAmount)) {
                cout << "Insufficient balance in account " << fromAccountId << endl;
                return;
            }

            // Debit from Account A
            sql::PreparedStatement *debitStmt = connection->prepareStatement(
                "UPDATE accounts SET balance = balance - ? WHERE account_id = ?");
            debitStmt->setDouble(1, transferAmount);
            debitStmt->setInt(2, fromAccountId);
            debitStmt->executeUpdate();
            delete debitStmt;

            // Credit to Account B
            sql::PreparedStatement *creditStmt = connection->prepareStatement(
                "UPDATE accounts SET balance = balance + ? WHERE account_id = ?");
            creditStmt->setDouble(1, transferAmount);
            creditStmt->setInt(2, toAccountId);
            creditStmt->executeUpdate();
            delete creditStmt;

            // Commit the transaction
            connection->commit();
            cout << "Transaction successful! Transferred $" << transferAmount << endl;

        } catch (sql::SQLException &ex) {
            // Rollback transaction in case of error
            if (connection != nullptr) {
                try {
                    connection->rollback();
                    cout << "Transaction failed! Rolled back." << endl;
                } catch (sql::SQLException &rollbackEx) {
                    cerr << "Rollback failed: " << rollbackEx.what() << endl;
                }
            }
            cerr << "SQL Exception: " << ex.what() << endl;
            cerr << "MySQL error code: " << ex.getErrorCode() << endl;
            cerr << "SQLState: " << ex.getSQLState() << endl;
        } catch (exception &ex) {
            cerr << "Exception: " << ex.what() << endl;
        }

        // Close connection
        if (connection != nullptr) {
            delete connection;
        }
    }

private:
    static bool hasSufficientBalance(sql::Connection *connection, int accountId, double amount) {
        try {
            sql::PreparedStatement *checkStmt = connection->prepareStatement(
                "SELECT balance FROM accounts WHERE account_id = ?");
            checkStmt->setInt(1, accountId);
            
            sql::ResultSet *res = checkStmt->executeQuery();
            bool sufficient = false;
            
            if (res->next()) {
                double balance = res->getDouble("balance");
                sufficient = (balance >= amount);
            }
            
            delete res;
            delete checkStmt;
            return sufficient;
            
        } catch (sql::SQLException &ex) {
            cerr << "SQL Exception in balance check: " << ex.what() << endl;
            return false;
        }
    }
};

int main() {
    BankTransaction::ACIDProperty();
    return 0;
}