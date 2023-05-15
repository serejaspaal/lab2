#include <cstdio>
#include <fstream>
#include "head.cpp"

int main(int argc, char *argv[])
{
    printf("********************************************************************************\n"
           "*            Нижегородский  государственный  технический университет           *\n"
           "*            Лабораторная  работа №1.  Задание  3.                             *\n"
           "*            Выполнил  студент группы:  22-ИВТ-3.  Игнатушин Серёжа            *\n"
           "********************************************************************************\n");
    std::string help{"-h"}, HELP{"--help"}, create{"-c"}, CREATE{"--create"}, read{"-r"}, READ{"--read"};
    if (argc == 1)
    {
        printf("Ошибка.\nЗапустите программу с опцией -h или --help, чтобы узнать как ей пользоваться.\n"
               "Для этого введите в терминале ./lab -h\n");
    }
    else if ((argc < 4) and (argv[1]!=help) and (argv[1]!=HELP))
    {
        helper();
    }
    else
    {
		int key = 3;
        if (argv[1] == help)
		{
			key = 3;
		}
		if (argv[1] == HELP)
		{
			key = 3;
		}
		if (argv[1] == create)
		{
			key = 1;
		}
		if (argv[1] == CREATE)
		{
			key = 1;
		}
		if (argv[1] == read)
		{
			key = 2;
		}
		if (argv[1] == READ)
		{
			key = 2;
		}
        int count;
        try
        {
            count = std::stoi(argv[2]);
            if (count <= 0){ throw 1;}
        }
        catch(const std::exception& e)
        {
            printf("\nВы неверно ввели количество объектов, по умолчанию выбран 1 объект\n\n");
            count = 1;
        }
        catch(int)
        {
            printf("\nВы неверно ввели количество объектов, по умолчанию выбран 1 объект\n\n");
            count = 1;
        }

        switch (key)
        {
        case 1:
            create_avia(count, argv[3]);
            break;
        case 2:
            print_avia(count, argv[3]);
            break;
        case 3:
            helper();
            break;
        }
    }
    return 0;
}
