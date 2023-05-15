#include <string>
struct Avia
{
	char plane_type[12];
	char board_number[11];
	char flights_number[17];
	char plaque_hours[13];
	char plaque_kilometers[14];
};

void create_avia(int num, std::string path);
void fprint(const Avia data[], int num, std::string path);
void print_avia(int num, std::string path);
void helper();
