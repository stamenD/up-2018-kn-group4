#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*
    Задача 1. Да се дефинират три променливи - дължини на страни на триъгълник. Да се
    изведе на конзолата периметърът и лицето на триъгълника.
    */
    cout << "Start problem 1" << endl;
    double a, b, c;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    double p = a + b + c;
    cout << "P=" << p << endl;

    // We need to include the cmath library to use sqrt
    double s = sqrt(p/2 * (p/2 - a) * (p/2 - b) * (p/2 - c));
    cout << "S=" << s << endl;

    /*
    Задача 2. По дадени цяло число n и дробно число a да се пресметне лицето на правилен
    n-ъгълник с дължина на страната a.
    */
    cout << "Start problem 2" << endl;
    int n;
    double sideLength;
    double PI = 3.1415; // we use an approximation
    cout << "n=";
    cin >> n;
    cout << "side=";
    cin >> sideLength;
    // formula taken from https://bg.wikipedia.org/wiki/Правилен_многоъгълник#Лице
    double polygonArea = (n * sideLength * sideLength) / (4 * tan(PI / n));
    cout << "Polygon area=" << polygonArea << endl;

    /*
    Задача 3. Да се провери дали дадено четирицифрено число е симетрично, например
    4334
    */
    cout << "Start problem 3" << endl;
    int number;
    cout << "Enter 4-digit number: ";
    cin >> number; // example: 4334
    int ones = number % 10; // 4334 % 10 is 4
    int tens = (number / 10) % 10; // 4334 / 10 is 433, then 433 % 10 is 3
    int hundreds = (number / 100) % 10;
    int thousands = number / 1000;
    if (ones == thousands && tens == hundreds) {
        cout << number << " is symmetric" << endl;
    } else {
        cout << number << " is not symmetric" << endl;
    }
    /*
    Задача 4. Да се провери дали дадена година е високосна.
    */
    cout << "Start problem 3" << endl;
    int year;
    cout << "Enter year: ";
    cin >> year;
    // The year is a leap year if it is divisible by 4, but not by 100, or it is divisible by 400
    // e.g. 2000 and 2104 are leap years, but 2102 and 2100 are not
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << "is not a leap year" << endl;
    }
    /*
    Задача 5. Да се напише програма, която прочита от конзолата час от денонощието и
    отпечатва подходящ поздрав:
    ● Ако е преди 10ч сутринта, “Добро утро”
    ● Ако е между 10ч и 18ч, “Добър ден”
    ● Ако е между 18ч и 22ч, “Добър вечер”
    ● Ако е преди 10ч или след 22ч, “Защо не спиш?!”
    ● Ако е невалиден час (под 0 или след 23) - “Грешен вход”
    */
    cout << "Start problem 5" << endl;
    int hour;
    cout << "Enter hour: ";
    cin >> hour;
    if (hour < 0 || hour > 23) {
        cout << "Bad input!" << endl;
    } else {
        if (hour < 10) {
            cout << "Good morning!" << endl;
        } else if (hour <= 18) {
            cout << "Good day!" << endl;
        } else if ( hour < 22) {
            cout << "Good evening!" << endl;
        }
        if (hour < 10 || hour >= 22) {
            cout << "Why are you not sleeping?!" << endl;
        }
    }
    /*Задача 6. Да се напише програма, която по дадени страни на триъгълник отпечатва типа
    на триъгълника:
    a. Равностранен, равнобедрен или разностранен
    b. Правоъгълен, остроъгълен или тъпоъгълен
    */
    cout << "Start problem 6" << endl;
    double s1, s2, s3;
    cout << "Enter triangle sides: ";
    cin >> s1 >> s2 >> s3;
    if (s1 == s2 && s1 == s3) {
        cout << "equilateral" << endl; // равностранен
    } else if (s1 == s2 || s1 == s3 || s2 == s3) {
        cout << "isosceles" << endl; // равнобедрен
    } else {
        cout << "scalene" << endl; // разностранен
    }
    // типът според ъглите се определя по типа на ъгъла срещу най-голямата страна
    // смятаме косинуса на ъгъла и според знака му определяме дали е тъп, прав или остър
    double maxSideCosine;
    if (s1 >= s2 && s1 >= s3) {
        // s1 е най-голямата страна
        maxSideCosine = (s2*s2 + s3*s3 - s1*s1) / (2 * s2 * s3);
    } else if (s2 >= s1 && s2 >= s3) {
        // s2 е най-голямата страна
        maxSideCosine = (s1*s1 + s3*s3 - s2*s2) / (2 * s1 * s3);
    } else {
        // s3 е най-голямата страна
        maxSideCosine = (s1*s1 + s2*s2 - s3*s3) / (2 * s1 * s2);
    }
    if (maxSideCosine < 0) {
        cout << "obtuse" << endl;
    } else if (maxSideCosine > 0) {
        cout << "acute" << endl;
    } else {
        cout << "right" << endl;
    }

    /*
    Задача 7. Да се провери дали точка със зададени координати (x, y) лежи на окръжност с
    център точка (c1, c2) и радиус r.
    */
    cout << "Start problem 7" << endl;
    double x, y;
    double c1, c2, r;
    cout << "Enter circle center and radius: ";
    cin >> c1 >> c2 >> r;
    cout <<"Enter point coordinates: ";
    cin >> x >> y;
    // (x,y) лежи на окръжността, ако разстоянието от центъра е точно r
    double squaredDistance = (c1 - x) * (c1 - x) + (c2 - y)*(c2 - y);
    if (squaredDistance == r * r) {
        cout << "(" << x << ", " << y << ") lies on the circle" << endl;
    } else {
        cout << "(" << x << ", " << y << ") doesn't lie on the circle" << endl;
    }
    return 0;
}
