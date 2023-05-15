#include <cstdio>
#include <string>
#include <fstream>
#include <iomanip>
#include "head.h"

using std::setw;

void create_avia(const int num, std::string path)
{
    Avia transp[num];
    for (int i = 0; i < num; i++)
    {
        printf("\nТип самолета : ");
        scanf("%s", &transp[i].plane_type);
        printf("\nНомер борта : ");
        scanf("%s", &transp[i].board_number);
        printf("\nКоличество рейсов : ");
        scanf("%s", &transp[i].flights_number);
        printf("\nНалет в часах : ");
        scanf("%s", &transp[i].plaque_hours);
        printf("\nНалет, тыс. км : ");
        scanf("%s", &transp[i].plaque_kilometers);
    }
    fprint(transp, num, path);
}

void fprint(const Avia data[], int num, std::string path)
{
    std::ofstream fout;
    fout.open(path);
    if (fout.is_open())
    {
        fout << "|№ |"
             << "Тип самолета |"
             << "Номер борта |"
             << "Количество рейсов |"
             << "Налет в часах |"
             << "Налет, тыс. км|\n";
        for (int i = 0; i < num; i++)
        {
            fout << setw(2) << i+1
                 << setw(14) << data[i].plane_type
                 << setw(13) << data[i].board_number
                 << setw(19) << data[i].flights_number
                 << setw(15) << data[i].plaque_hours
                 << setw(16) << data[i].plaque_kilometers << "\n";
        }
        fout.close();
    }
    else
        perror("\nНе удалось открыть файл : ");
}

void print_avia(int num, std::string path)
{
    std::ifstream fin;
    fin.open(path);
    if (fin.is_open())
    {
        if (fin.peek() != EOF)
        {
            std::string str;
            for (int i = 0; i < num+1; i++)
            {
                getline(fin, str);
                printf("%s\n", str.c_str());
            }
        }
        else
        {
            printf("Пустой файл\n");
        }
        fin.close();
    }
    else
        printf("Не удалось открыть файл\n");
}

void printer(int num, std::string path)
{
    
}
void helper()
{
    {
        printf("Help:\nДля использования программы необходимо запустить ее с помощью терминала,"
               "введя \nопции (-h,--help,-r,--read,-c,--create), количество объектов и название \nтекстового файла.\n"
               "Например : ./lab -c 2 in.txt\n"
               "Для создания объектов используйте опцию -c или --create\n"
               "Для вывода объектов на экран используйте опцию -r или --read\n"
               "Не забывайте, что необходимо указывать количество объектов для создания или \nчтения\n");
    }
}
