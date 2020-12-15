#include <iostream>
#include <string.h>//работа со строками
using namespace std;

int fun3(int m, int y)
{
    int x1;//промежуточная переменная
    if ((y / 4 * 4 == y && y / 100 * 100 != y) || y / 400 * 400 == y)
        switch (m)//переключатель
        {
        case 1: x1 = 1;
            break;
        case 2: x1 = 0;
            break;
        case 3: x1 = 1;
            break;
        case 4: x1 = 1;
            break;
        case 5: x1 = 2;
            break;
        case 6: x1 = 2;
            break;
        case 7: x1 = 3;
            break;
        case 8: x1 = 4;
            break;
        case 9: x1 = 4;
            break;
        case 10: x1 = 5;
            break;
        case 11: x1 = 5;
            break;
        case 12: x1 = 6;
            break;
        }
    else
        switch (m)//переключатель
        {
        case 1: x1 = 1;
            break;
        case 2: x1 = -1;
            break;
        case 3: x1 = 0;
            break;
        case 4: x1 = 0;
            break;
        case 5: x1 = 1;
            break;
        case 6: x1 = 1;
            break;
        case 7: x1 = 2;
            break;
        case 8: x1 = 3;
            break;
        case 9: x1 = 3;
            break;
        case 10: x1 = 4;
            break;
        case 11: x1 = 4;
            break;
        case 12: x1 = 5;
            break;
        }
    return x1;//значение которое возвращает функция
} 

/*функция просчёта дня недели*/
int fun1(int d, int m, int y)
{
    int a, b, c = 0;//промежуточные значения
    b = fun3 (m, y);
    a = (y - 1) / 4;
    if ((y / 4 * 4 == y && y / 100 * 100 != y) || y / 400 * 400 == y)//проверка на високосный год
        c = -1;
    if (m == 2)//если февраль считать по этой формуле
        return y * 365 + m * 30 + d + a + b - (y - 1) / 100 + (y - 1) / 400 - 4 + c;
    else
    {
        if (m == 4 || m == 6 || m == 9 || m == 11)//если эти месяцы – апрель, июнь, сентябрь, ноябрь, то считать по этой формуле
            return y * 365 + m * 30 + d + a + b - (y - 1) / 100 + (y - 1) / 400 + 1;
        else return y * 365 + m * 30 + d + a + b - (y - 1) / 100 + (y - 1) / 400;//при остальных месяцах считать по этой формуле
    }
}

/*функция проверки корректности задания дат*/
int fun2(int y1)
{
    int x1;//промежуточная переменная
    switch (y1)//переключатель
    {
    case 1: x1 = 1;
        break;
    case 2: x1 = -2;
        break;
    case 3: x1 = 1;
        break;
    case 4: x1 = 0;
        break;
    case 5: x1 = 1;
        break;
    case 6: x1 = 0;
        break;
    case 7: x1 = 1;
        break;
    case 8: x1 = 1;
        break;
    case 9: x1 = 0;
        break;
    case 10: x1 = 1;
        break;
    case 11: x1 = 0;
        break;
    case 12: x1 = 1;
        break;
    }
    return x1;//значение которое возвращает функция
}


/*главная функция*/
int main()
{
    int  d, m, y, x, a, n = 1;//переменные которые, соответственно: день, месяц, год, день недели, выбор формата, промежуточная переменная
    char q1[] = "yes", q2[4];//переменные которые проверяют продолжать работу с программой или нет
    cout << "Select the format of writing dates,then:  1 - normal (ex. 01 jan 2008),  other  number - american (ex. 01 01 2008) \n";
    cin >> a;
    cout << "\n";

    while (true)//вечный цикл
    {
        if (a == 1)//если выбран обычный формат
        {
            cout << "Imput data, month, year \n";
            cin >> d >> q2 >> y;//ввод даты
            /*переход от обычного формата к цифровому*/
            if (strcmp(q2, "jan") == 0) m = 1;
            if (strcmp(q2, "feb") == 0) m = 2;
            if (strcmp(q2, "mar") == 0) m = 3;
            if (strcmp(q2, "apr") == 0) m = 4;
            if (strcmp(q2, "may") == 0) m = 5;
            if (strcmp(q2, "jun") == 0) m = 6;
            if (strcmp(q2, "jul") == 0) m = 7;
            if (strcmp(q2, "aug") == 0) m = 8;
            if (strcmp(q2, "sep") == 0) m = 9;
            if (strcmp(q2, "oct") == 0) m = 10;
            if (strcmp(q2, "nov") == 0) m = 11;
            if (strcmp(q2, "dec") == 0) m = 12;
        }
        else//если выбран цифровой формат
        {
            cout << "Imput data, month, year \n";
            cin >> d >> m >> y;//ввод даты
        }
        if (d > 0 && m > 0 && y >= 0 && d < 32 && m < 13)//поверхностная проверка корректности даты
        {
            if ((fun2(m) == 1 && d < 32) || (fun2(m) == 0 && d < 31) || (fun2(m) == -2 && d < 29) || (fun2(m) == -2 && ((y / 4 * 4 == y && y / 100 * 100 != y) || y / 400 * 400 == y)) && d < 30)//проверка корректности даты
            {
                x = fun1(d, m, y) % 7;//вызов функции просчёта дня недели
                switch (x)
                {
                case 5: cout << "it is Monday \n\n";
                    break;
                case 6: cout << "it is Tuesday \n\n";
                    break;
                case 0: cout << "it is Wednesday \n\n";
                    break;
                case 1: cout << "it is Thursday \n\n";
                    break;
                case 2: cout << "it is Friday \n\n";
                    break;
                case 3: cout << "it is Saturday \n\n";
                    break;
                case 4: cout << "it is Sunday \n\n";
                    break;
                default: cout << "Sistem error \n\n" << "\a";
                }
            }
            else cout << "Error, does not correct record date \n\n";//сообщение об ошибке
        }
        else cout << "Error, does not correct record date \n\n";//сообщение об ошибке
        cout << "Would you like to continue working with the program? (yes/no)\n";//запрос на продолжение работы с программой
        cin >> q2;//ввод да или нет
        cout << "_______________________________________________________________________________\n\n";;
        if (strcmp(q1, q2) != 0)//проверка на продолжение работы с программой 
            break;// выход из вечного цикла
        else n++;//продолжение работы с программой
    }
    cout << "Made by , Tubik. \n";//конечное сообщение
    cin >> y;
}