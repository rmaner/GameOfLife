#define MAXROW 15
#define MAXCOL 30

typedef enum status_tag
{
    DEAD,
    ALIVE
} Status_type;
typedef Status_type Grid_type[MAXROW][MAXCOL];
