#include "answer3.h"

void recPaintRoom( RoomData room, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/ );
int findRowofA( RoomData room );
int findColofA( RoomData room );
/* declare any other helper functions here*/

/* TODO
 * paintRoom
 * input: the room to process
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial call to recursive function recPaintRoom.
 */
void paintRoom( RoomData room )
{
    /* Call any other helper functions (a helper function to find the location of 'A' in room may be handy) */
    int row = findRowofA(room);
    int col = findColofA(room);

    /* Call your recursive function here */
    recPaintRoom( room, row, col, 0 );
    return ;
}

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */
void recPaintRoom( RoomData room, int row, int col, int distanceFromA/* feel free to remove/add any other parameters here*/ )
{
    /* Base cases: */
    if(room.roomArray[row][col]=='*') {
        return ;
    }
    /* print 'distanceFromA+65' */
    if(distanceFromA<26||room.roomArray[row][col]>distanceFromA+'A') {
        room.roomArray[row][col]=distanceFromA+'A';
    }
    /* print 'Z' if distanceFromA>=26 */
    else if(room.roomArray[row][col]) {
        room.roomArray[row][col]='Z';
    }
    /* Recursive cases: */
    if(room.roomArray[row][col+1]==' '||room.roomArray[row][col]+1<room.roomArray[row][col+1]) {
        recPaintRoom(room, row, col+1, distanceFromA+1); /* right */
    }
    if(room.roomArray[row][col-1]==' '||room.roomArray[row][col]+1<room.roomArray[row][col-1]) {
        recPaintRoom(room, row, col-1, distanceFromA+1); /* left */
    }
    if(room.roomArray[row-1][col]==' '||room.roomArray[row][col]+1<room.roomArray[row-1][col]) {
        recPaintRoom(room, row-1, col, distanceFromA+1); /* up */
    }
    if(room.roomArray[row+1][col]==' '||room.roomArray[row][col]+1<room.roomArray[row+1][col]) {
        recPaintRoom(room, row+1, col, distanceFromA+1); /* down */
    }
    
    return ;
}

/*
 * Finds and returns the x location of A
 *
 */
int findRowofA( RoomData room ) {
    int i = 0;
    int j = 0;
    for(i=1;i<room.numrows;i++) {
        for(j=0;j<room.numcols;j++) {
            if(room.roomArray[i][j]=='A')
                return i;
        }
    }
    return 0;
}

/*
 * Finds and returns the x and y location of A
 *
 */
int findColofA( RoomData room ) {
    int i = 0;
    int j = 0;
    for(i=1;i<room.numrows;i++) {
        for(j=0;j<room.numcols;j++) {
            if(room.roomArray[i][j]=='A')
                return j;
        }
    }
    return 0;
}

