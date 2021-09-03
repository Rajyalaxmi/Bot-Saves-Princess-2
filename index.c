#include <stdio.h>
#include <stdlib.h>

void nextMove(int n, int r, int c, char **grid){
    char *dir;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]=='P' || grid[i][j]=='p'){
                if(i == r)
                    dir = (j < c)? "LEFT" : "RIGHT";
                else if(j == c)
                    dir = (i < r)? "UP" : "DOWN";
                else if(r < i)
                    dir = "DOWN";
                else if(i < r && j > c)
                    dir = "RIGHT";
                else
                    dir = "LEFT";
                printf("%s\n", dir);
                return;
            }
        }
    }
}

int main(void) {

    int n, r, c;
    scanf("%d%d%d", &n, &r, &c);
    char **grid = (char **)malloc(n*sizeof(char *));
    
    for(int i=0; i<n; i++) {
        grid[i] = (char *)malloc(n*sizeof(char));
        scanf("%s", grid[i]);
    }
    nextMove(n, r, c, grid);
    return 0;
}
