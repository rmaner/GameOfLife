void CopyMap(Grid_type, Grid_type);
void Initialize(Grid_type);
void WriteMap(Grid_type);
void WriteMapToFile(Grid_type);
int NeighborCount(int, int, Grid_type);
Boolean_type Enquire(Grid_type);


/* NeighborCount: count neighbors of row,col */
int NeighborCount(int row, int col, Grid_type map)
{
    int i,j;
    int rlow, rhigh;
    int clow, chigh;
    int count;

    if (row <= 0)
        rlow = 0;
    else 
        rlow = row - 1;
    
    if (row >= MAXROW - 1)
        rhigh = MAXROW - 1;
    else 
        rhigh = row + 1;
    
    if (col <= 0)
        clow = 0;
    else 
        clow = col - 1;
    if (col >= MAXCOL - 1)
        chigh = MAXCOL -1;
    else
        chigh = col + 1;
    
    count = 0;      /* Nested loops count neighbors */
    for (i=rlow; i<=rhigh; i++)
        for (j=clow; j<=chigh; j++)
            if (map[i][j] == ALIVE)
                count++;
    
    if(map[row][col] == ALIVE)
        count--;
    
    return count;
}

/* Initialize: initialize grid map */
void Initialize(Grid_type map)
{
    int row, col;
    printf("This program is a simulation of the game of Life.\n");
    for (row=0; row<MAXROW; row++)
        for (col=0; col<MAXCOL; col++)
            map[row][col] = DEAD;
    
    printf("On each line give a pair of co-ordinates for a living cell.\n");
    printf("Terminate the list with the special pair -1 -1\n");

    scanf("%d %d",&row, &col);
    while (row!=-1 || col!=-1)
    {    
        if(row>=0 && row<=MAXROW && col>=0 && col<=MAXCOL)
            map[row][col] = ALIVE;
        else
            printf("Values are not within range.\r");
        scanf("%d %d",&row, &col);
    }    
}

/* WriteMap: write grid map */
void WriteMap(Grid_type map)
{
    int row, col;
    printf("\n\n");
    for (row=0; row<MAXROW; row++)
    {
        for (col=0; col<MAXCOL; col++)
            if(map[row][col] == ALIVE)
                printf("*");
            else
                printf("-");
        printf("\n");
    }
}

/* CopyMap: copy newmap into map */
void CopyMap(Grid_type map, Grid_type newmap)
{
    int row, col;
    for (row=0; row<MAXROW; row++)
        for (col=0; col<MAXCOL; col++)
            map[row][col] = newmap[row][col];
}

/* Enquire: TRUE if the user wants to continue execution */
Boolean_type Enquire(Grid_type map)
{
    int c;
    printf("Continue (y,n)? : ");
    c=getch();
    
    if (c=='w') {
        WriteMapToFile(map);
        printf("Continue after write (y,n)? : "); 
        c=getch();
    }

    if (c=='n' || c=='N')
        return FALSE;
    else
        return TRUE;
}

// ------------- my functions 

/* autoInitialize: initialize grid map */
void autoInitialize(Grid_type map)
{
    int row, col, count=0;
    char ch;

    printf("This program is a simulation of the game of Life.\n");
    for (row=0; row<MAXROW; row++)
        for (col=0; col<MAXCOL; col++)
            map[row][col] = DEAD;
    
    FILE *fp=fopen ("inputGrid.txt", "r+");

    if (fp != NULL) {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '*')  map[count/MAXCOL][count%MAXCOL] = ALIVE; 
            if (ch != '\n') count++;
        }
    }
    fclose(fp);
}


/* WriteMapToFile: write current grid map to a file */
void WriteMapToFile(Grid_type map)
{
    int row, col;
    FILE *fp=fopen ("currentGridMap.txt", "w");

    for (row=0; row<MAXROW; row++)
    {
        for (col=0; col<MAXCOL; col++)
            if(map[row][col] == ALIVE)
                fputc('*',fp);
            else
                fputc('-',fp);
        fputc('\n',fp);
    }
    fclose(fp);
}

