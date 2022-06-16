#define ME_M 0
#define US_M 1

void set_mode(int *mode);
void get_info(int mode, double *distance, double *fuel_consu);
void show_info(int mode, double distance, double fuel_consu);
