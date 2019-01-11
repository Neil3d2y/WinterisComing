#include "Common.h"
#include "DatabaseManager.h"

void print_usage()
{
    printf("usage: [-h] \tprint help\n [-f] \t execute query from file\n");
}

int main(int argc, char **argv)
{
    //Given
    MainMemory mem;
    Disk disk;

    DatabaseManager DBMS(&mem, &disk);
    //string query = "CREATE TABLE course (sid INT, homework INT, project INT, exam INT, grade STR20)¡°
    //string query = "INSERT INTO course (sid, homework, project, exam, grade) VALUES (1, 99, 100, 100, \"A\")";
    //string query = "SELECT DISTINCT * FROM course";
    //string query = "SELECT course.sid, course.grade, course2.grade FROM course, course2 WHERE course.sid = course2.sid";
    //string query = "INSERT INTO course (sid, homework, project, exam, grade) SELECT * FROM course";
    //string query = "SELECT DISTINCT course.grade, course2.grade FROM course, course2 WHERE course.sid = course2.sid";

    //DBMS.ProcessQuery(query);

    string query;
    if (argc > 1)
    {
        char *filename = argv[1];
        fstream fp;
        fp.open(filename, fstream::in);
        if (!fp)
        {
            cout << "query script: " << filename << " open failed!" << endl;
            print_usage();
            return 0;
        }

        while (!fp.eof())
        {
            getline(fp, query);
            cout << "> " << query << endl;
            if (DBMS.ProcessQuery(query))
                cout << "SUCCESS" << endl;
            else
                cout << "FAILED" << endl;
        }
        fp.close();

    }
    else
    {
        while (true)
        {
            cout << ">> ";
            getline(cin, query);
            if (query == "q" || query == "quit") {
                break;
            }
            if (DBMS.ProcessQuery(query))
                cout << "SUCCESS" << endl;
            else
                cout << "FAILED" << endl;
        }
    }

    cout << "BYE!" << endl;

    return 0;
}