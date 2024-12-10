    #include <iostream>
    #include <vector>
    #include <string>
    #include <windows.h> 
    using namespace std;
    class Student {
    public:
        string name;
        Student(string n) : name(n) {}
    };
    class Course {
    protected:
        string courseName;
        int credits;
        vector<string> students; 
    public:
        Course(string name, int cr) : courseName(name), credits(cr) {}
        void enroll(Student student) {
            students.push_back(student.name);
            cout << student.name << " записаний на курс " << courseName << endl;
        }
        void showCourseInfo() {
            cout << "Курс: " << courseName << ", Кредити: " << credits << ", Студенти: ";
            for (const auto& s : students) {
                cout << s << " ";
            }
            cout << endl;
        }
    };
    class OnlineCourse : public Course {
        string url;
    public:
        OnlineCourse(string name, int cr, string courseUrl) : Course(name, cr), url(courseUrl) {}
        void startSession() {
            cout << "Онлайн-сесія курсу " << courseName << " почалася за посиланням: " << url << endl;
        }
    };
    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        Course basicCourse("Програмування", 3);
        basicCourse.enroll(Student("Дмитро"));
        basicCourse.enroll(Student("Павло"));
        basicCourse.showCourseInfo();
        OnlineCourse onlineCourse("Алгоритми", 4, "http://online.course.com");
        onlineCourse.enroll(Student("Олексій"));
        onlineCourse.startSession();
        return 0;
    }
