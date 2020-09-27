#include <libpq-fe.h>
#include <stdio.h>
#include <stdlib.h>


void close_connection(PGconn* connection, int code) {
    PQfinish(connection);
    exit(code);
}

// If the retrieved data is not a tuble
void result_error_hanlder(PGconn* conn, PGresult* res) {
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "%s\n", PQresultErrorMessage(res));
        PQclear(res);
        close_connection(conn, 1);
    }
    else if (PQntuples(res) == 0) {
        printf("There's no such a user\n");
        PQclear(res);
        close_connection(conn, 0);
    }
}

// If command not performed
void command_error_handler(PGconn* conn, PGresult* res) {
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "%s\n", PQresultErrorMessage(res));
        PQclear(res);
        close_connection(conn, 1);
    }
}

int main(int argc, char* argv[]) {
    const int LEN = 10;
    const char* paramValues[1];

    if (argc != 3) {
        fprintf(stderr, "Usage: need and Id and a withdraw\n");
        exit(1);
    }

    int rowId;
    int ret = sscanf_s(argv[1], "%d", &rowId);

    if (ret != 1) {
        fprintf(stderr, "Id must be an integer\n");
        exit(1);
    }

    if (rowId < 0) {
        fprintf(stderr, "Error passing a negative rowId\n");
        exit(1);
    }

    int price;
    int rep = sscanf_s(argv[2], "%d", &price);

    if (rep != 1) {
        fprintf(stderr, "withdraw must be an integer");
    }

    //char str[LEN];
    char str="Monze@2";
   // const int LEN = 10 ;
    snprintf(str, LEN, "%d", rowId);
    paramValues[0] = str;

  //  char pstr[LEN];
    const int pstr = 5;
    snprintf(pstr, LEN, "%d", price);
    paramValues[1] = pstr;

       PGconn* conn = PQconnectdb("user=postgres password=Monze@2019 dbname=presly");
  //  PGconn* conn = PQconnectdb("user=elias password=root dbname=testdb");

    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        close_connection(conn, 1);
    }

    // Begin the transaction
    PGresult* response = PQexec(conn, "BEGIN");
    command_error_handler(conn, response);
    PQclear(response);

    // Check if user exists
    char* stm = "SELECT * FROM account WHERE user_id=$1";
    response = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);
    result_error_hanlder(conn, response);
    PQclear(response);

    // Update user balance and subtract the withdraw amount
    char* udt = "UPDATE account SET balance = balance - $2 WHERE user_id=$1";
    response = PQexecParams(conn, udt, 2, NULL, paramValues, NULL, NULL, 0);
    command_error_handler(conn, response);
    PQclear(response);

    // Commit the transaction
    response = PQexec(conn, "COMMIT");
    command_error_handler(conn, response);
    PQclear(response);

    // retrieve updated user
    response = PQexecParams(conn, stm, 1, NULL, paramValues, NULL, NULL, 0);
    result_error_hanlder(conn, response);
    printf("Following user updated:\n %s %s %s\n", PQgetvalue(response, 0, 0),
        PQgetvalue(response, 0, 1), PQgetvalue(response, 0, 2));

    PQclear(response);
    PQfinish(conn);
    return 0;
}