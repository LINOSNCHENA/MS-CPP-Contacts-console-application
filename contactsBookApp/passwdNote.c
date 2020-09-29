//#include <stdlib.h>
//#include <stdio.h>
//
//#include <mysql.h>
//
////--------------------------------------------------------
//// FUNCTION PROTOTYPES
////--------------------------------------------------------
//void displaydata(char* data);
//void displayerror(char* errormessage);
//void getdata(void(*onsuccess)(char* data), void(*onerror)(char* errormessage));
//
////--------------------------------------------------------
//// FUNCTION main
////--------------------------------------------------------
//MYSQL* mysql = NULL;
//int main(int argc, char* argv[])
//{
//
//    printf("\n I============================= START-MAIN =================================I\n\n");
//   puts("-------------------------------------");
//   puts("| codedrome.com                     |");
//   puts("| on success and on error callbacks |");
//   puts("-------------------------------------\n");
//
//   getdata(displaydata, displayerror);   
// 
//
//    if (mysql_library_init(argc, argv, NULL)) {
//        fprintf(stderr, "could not initialize MySQL client library\n");
//        exit(1);
//    }
//    mysql = mysql_init(mysql);
//
//    if (!mysql) {
//        puts("Init faild, out of memory?");
//        return EXIT_FAILURE;
//    }
//
//    mysql_options(mysql, MYSQL_READ_DEFAULT_FILE, (void*)"./passwdNote.cnf");
//
//    if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
//        NULL,        /* server hostname or IP address */
//        NULL,        /* mysql user */
//        NULL,        /* password */
//        NULL,        /* default database to use, NULL for none */
//        0,           /* port number, 0 for default */
//        NULL,        /* socket file or named pipe name */
//        CLIENT_FOUND_ROWS /* connection flags */)) {
//        printf("\n I=============================FAILURE =================================I\n\n");
//        puts("Connecting to PRESLY failed\n");
//    }
//    else {
//        printf("\n I=============================SUCCESS==================================I\n\n");
//        puts("Connecting to PRESLY OK\n");
//   
//    }
//    mysql_close(mysql);
//       printf("\n I=============================MySQL_END==================================I\n");
//    mysql_library_end();
//   return EXIT_SUCCESS;
//}
//
////--------------------------------------------------------
//// FUNCTION getdata
////--------------------------------------------------------
//void getdata(void(*onsuccess)(char*), void(*onerror)(char*))
//{
//   char* data = "This is the PRESLY data :)";
//   char* errormessage = "Something went wrong :(\n";
//
//   onsuccess(data);
//
//   onerror(errormessage);
//}
//
////--------------------------------------------------------
//// FUNCTION displaydata
////--------------------------------------------------------
//void displaydata(char* data)
//{
//   printf("success Z1: %s\n", data);
//}
//
////--------------------------------------------------------
//// FUNCTION displayerror
////--------------------------------------------------------
//void displayerror(char* errormessage)
//{
//   printf("error Z2: %s\n", errormessage);
//}