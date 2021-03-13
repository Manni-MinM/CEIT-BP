// BWOTSHEWCHB

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 11

long long int mat[MAXN][MAXN] , mat2[MAXN][MAXN] , n ;

void test_gen(int val) {
	n = val ;
	for ( int i = 0 ; i < n ; i ++ )
		for ( int j = 0 ; j < n ; j ++ )
			mat[i][j] = (long long int)rand() % 10LL , mat2[i + 1][j + 1] = mat[i][j] ;
	return ;
}

long long int solve_A(long long int f[11][11],long long int a);

long long int solve_M(long long int mat[MAXN][MAXN] , long long int n) {
        long long int ans = 0 ;
        if ( n == 1 )
                return (long long int)mat[0][0] ;
        for ( int iter = 0 ; iter < n ; iter ++ ) {
                long long int it = 0 , cur[MAXN][MAXN] ;
                for ( int i = 1 ; i < n ; i ++ ) {
                        int jt = 0 ;
                        for ( int j = 0 ; j < n ; j ++ )
                                if ( j != iter )
                                        cur[it][jt ++] = mat[i][j] ;
                        it ++ ;
                }
                ans += (long long int)pow(-1 , (iter & 1)) * (long long int)mat[0][iter] * solve_M(cur , n - 1) ;
        }
        return ans ;
}

int main() {
	srand(time(0)) ;
/*	while ( true ) {
		test_gen(2) ;
		long long int output_M = solve_M(mat , n) ;
		long long int output_A = solve_A(mat , n) ;
		if ( output_A != output_M ) {
			printf("correct ans : %lld / ret ans : %lld\n" , output_M , output_A) ;
			printf("%lld\n" , n) ;
			for ( int i = 0 ; i < n ; i ++ ) {
				for ( int j = 0 ; j < n ; j ++ )
					printf("%lld " , mat[i][j]) ;
				printf("\n") ;
			}
			break ;
		}
	}*/
	printf("%lld\n" , solve_A(mat2 , n)) ;
	return 0 ;
}

long long int solve_A(long long int f[11][11],long long int x)
{
    long long int pr,c[11],d=0,b[11][11],j,p,q,t;
    if(x==2)
    {
        d=0;
        d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
        return(d);
    }
    else
    {
        for(j=1;j<=x;j++)
        {        
            long long int r=1,s=1;
            for(p=1;p<=x;p++)
            {
                for(q=1;q<=x;q++)
                {
                    if(p!=1&&q!=j)
                    {
                        b[r][s]=f[p][q];
                        s++;
                        if(s>x-1)
                        {
                            r++;
                            s=1;
                        }
                    }
                }
            }
            for(t=1,pr=1;t<=(1+j);t++)
                pr=(-1)*pr;
            c[j]=pr*solve_A(b,x-1);
        }
        for(j=1,d=0;j<=x;j++)
        {
            d=d+(f[1][j]*c[j]);
        }
        return(d);
    }
}
