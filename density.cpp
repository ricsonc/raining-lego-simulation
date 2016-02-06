#include <array>
#include <cstdlib>
#include <cstdio>

#define N 1000;

struct piece {
    std::size_t x0;
    std::size_t y0;
    std::size_t x1;
    std::size_t y1;
};
typedef struct piece piece;

typedef std::array<std::array<bool, N>, N> grid;

struct board {
    grid height;
    unsigned long long count;
    std::size_t lower;
    std::size_t upper;
};
typedef struct board board;

int rand_index(){
    int discard = (RAND_MAX/N)*N;
    int n = 0;
    do {
        n = rand();
    } while (!(n < N));
    return n;
}

piece rand_piece(){
    std::size_t x0 = rand_index();
    std::size_t y0 = rand_index();
    std::size_t x1 = x0;
    std::size_t y1 = y0;
    std::size_t diff = (rand()%2)*2-1;
    if(rand()%2){
        x1 += diff+N;
        x1 %= N;
    } else {
        y1 += diff+N;
        y1 %= N;
    }
    return {x0, y0, x1, y1};
}

void place(board &B, piece &p){
    std::size_t z = max(B.height[p.x0][p.y0],
                        B.height[p.x1][p.y1])+1;
    B.height[p.x0][p.y0] = z;
    B.height[p.x1][p.y1] = z;
    if (B.lower <= z && z < B.upper) {
        B.count += 2;
    }
}

void minz(board &B){
    std::size_t min_z = B.height[0][0];
    for(std::size_t i = 0; i < N; i++){
        for(std::size_t j = 0; j < N; j++){
            min_z = min(B.height[i][j], min_z);
        }
    }
}

void fill(board &B){
    while (minz(B) <= B.upper){
        for(std::size_t k = 0; k < N*N; k++){
            place(B, rand_piece());
        }
    }
}

int main(){
    srand(0);
    board B = {grid(), 0, 100, 100+N};
    fill(B);
    std::printf("%.6e\n", (double)B.count/((B.upper-B.lower)*N*N));
    return 0;
}
