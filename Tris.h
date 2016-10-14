struct tris_t;
typedef struct tris_t tris_t;

typedef enum mark_e mark_e;

void new_game(tris_t* grid);
int add(tris_t* grid, mark_e mark, int row, int column);
mark_e get(tris_t* grid, int row, int column);
