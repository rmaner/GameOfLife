/* 
   # Sourced from "Data Structures and Program Design in C"
   # Authors Robert L. Kruse, Bruce P.Leung, Clovis L.Tondo
*/

/* Simulation of Conway's game of Life on a bounded grid */
/* Version 1 */

#include "general.h"
#include "lifedef.h"
#include "calls.h"

void main(void)
{
    int row,col;
    Grid_type map;
    Grid_type newmap;

    autoInitialize(map);
    WriteMap(map);
    while(Enquire(map)){
        for (row = 0; row < MAXROW; row++)
            for (col = 0; col < MAXCOL; col++)
                switch(NeighborCount(row,col,map)){
                    case 0:
                    case 1:
                            newmap[row][col]=DEAD;
                            break;
                    case 2:
                            newmap[row][col]=map[row][col];
                            break;
                    case 3:
                            newmap[row][col]=ALIVE;
                            break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                            newmap[row][col]=DEAD;
                            break;
                }
            CopyMap(map,newmap);
            WriteMap(map);
    }
}