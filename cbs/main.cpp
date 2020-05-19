#include<iostream>
#include<windows.h>
#include<mysql.h>

using namespace std;

int main()
{
   // cout << "Hello world!" << endl;

    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    int query;
    conn = mysql_init(0);
    if(conn){
        cout << "Connected" << endl;
    }
    else{
        cout << "Connection Failed " << mysql_error(conn) << endl;
    }

    conn = mysql_real_connect(conn, "localhost", "root", "root", "mca", 0, NULL, 0);
    if(conn){
        cout << "Connected to mca" << endl;
        query = mysql_query(conn, "SELECT * FROM fymca");
        if(!query){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){
                cout << row[2] << "  ";
                cout << row[1] << endl;
            }
        }
        else{
            cout << "cannot read from db." << mysql_error(conn) << endl;
        }
    }
    else{
        cout << "Connection Failed to mca" << mysql_error(conn) << endl;
    }

    return 0;
}
