//Board-card-variability -- Generates random border and shows the desired conclusion to be satisfying


/*
We are given an n × n board, where n is an odd number. In
each cell of the board either +1 or −1 is written. Let a(sub)k and b(sub)k denote the
products of numbers in the kth row and in the kth column respectively.
Prove that the sum a(sub)1 +a(sub)2 +· · ·+a(sub)n +b(sub)1 +b(sub)2 +· · ·+b(sub)n cannot be equal
to zero.
*/

/*
Below Algorithm randonly assigns +1 and -1 to fill the board and checks the above condition
to prove the desired conclusion.
*/

#include <stdio.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int i, j;
	int SIZE = 0;
	while(SIZE % 2 == 0){
		SIZE = rand()%100+1;
	}
	int board[SIZE][SIZE];
	int random;
	
	int prod_row = 1;
	int prod_col = 1;
	int sum = 0;
	int REP = 100000;
	int arr_sum[REP];
	int t = 0;
	while(t != REP){
		for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			do{
				random = rand()%3-1;
			}while(random != -1 && random != 1);
			board[i][j] = random;
			}
		}
		
		for(i = 0; i < SIZE; i++){
			for(j = 0; j < SIZE; j++){
				prod_row = prod_row * board[i][j];
				prod_col = prod_col * board[j][i];
			}
			sum = sum + prod_row + prod_col;
			prod_row = 1;
			prod_col = 1;
		}
		arr_sum[t] = sum;
		sum = 0;
		t++;
	}
	
	int tem = 0;
	for(t = 0; t < REP; t++){
		if(arr_sum[t] == 0){
			tem++;
		}
	}
	printf("%d random boards were generated\n", REP);
	if(tem == 0){
		printf("No zero sum were found. Algorithm works :)\n");
	}
	else{
		printf("Found zero sum. Algorithm failed :(\n");
	}
	return 0;
}
