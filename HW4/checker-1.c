#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 3069

int x , input ;
char first[MAXN] , second[MAXN] , str[MAXN] , key[MAXN] ;

void rand_gen() {
	x = rand() % input + 1 ;
	for ( int i = 0 ; i < x ; i ++ )
		if ( rand() & 1 )
			first[i] = '1' ;
		else
			first[i] = '0' ;
	for ( int i = 0 ; i < x ; i ++ )
		if ( rand() & 1 )
			second[i] = '1' ;
		else
			second[i] = '0' ;
	return ;
}
int shomaresh(char n[100]){
    int tedad=0;
    for (int i = 0; i < 100; i++)
    {
        if (n[i]=='1')
        {
            tedad++;
        }
        if (n[i]=='\0')
        {
            break;
        }   
    }
    return tedad;
}
int run_A() {
    int count=0, t;
        for (int i = 0; i < x; i++)
    {
        if (first[i]==second[i])
        {
            continue;
        }
        
        else if (first[i+1]=='1' && second[i]=='1' && second[i+1]=='0')
        {
            second[i]='0';
            second[i+1]='1';
            count++;
        }
        else if (first[i-1]=='1' && second[i]=='1' && second[i-1]=='0')
        {
            second[i]='0';
            second[i-1]='1';
            count++;
        }
    }
    //printf("%d\n",count);
    //printf("%s\n",second);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (first[j]=='0' && second[j]=='1'){
                t = j;
            }
        }
        
        if (strcmp(first,second))
        {
            if((first[i]=='1' && second[i]=='0') && shomaresh(first)==shomaresh(second)){
                count = count +2;
                second[i]='1';
                second[t] = '0';
            }
            else if ((first[i]=='1' && second[i]=='0') && shomaresh(first)!=shomaresh(second))
            {
                count++;
                second[i]='1';
            }
            else if((first[i]=='0' && second[i]=='1') && shomaresh(first)==shomaresh(second)){
                count = count +1;
                second[i]='0';
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        if (first[i]=='0' && second[i]=='1')
        {
            second[i]='0';
            count++;
        }
        else if (first[i]=='1' && second[i]=='0')
        {
            second[i]='1';
            count++;
        }
        
        
    }
    
    //printf("%s\n",second);
    printf("run_A : %d\n",count);
    return count ;
}
int run_M() {
	int n = x ;
	int cnt_str = 0 , cnt_key = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cnt_str += (str[i] == '1' ? 1 : 0) ;
		cnt_key += (key[i] == '1' ? 1 : 0) ;
	}
	for ( int i = 0 ; i < n ; i ++ )
		if ( key[i] == '1' && str[i] == '1' )
			key[i] = '0' , str[i] = '0' ;
	int ans = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( key[i] == '1' ) {
			if ( i - 1 >= 0 && str[i - 1] == '1' )
				str[i - 1] = '0' , key[i] = '0' , ans ++ ;
			else if ( i + 1 <= n - 1 && str[i + 1] == '1' )
				str[i + 1] = '0' , key[i] = '0' , ans ++ ;
		}
	}
	cnt_str = 0 , cnt_key = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cnt_str += (str[i] == '1' ? 1 : 0) ;
		cnt_key += (key[i] == '1' ? 1 : 0) ;
	}
	if ( cnt_str > cnt_key )
		ans += cnt_str - cnt_key , ans += 2 * cnt_key ;
	else
		ans += cnt_key - cnt_str , ans += 2 * cnt_str ;
	printf("run_M : %d\n" , ans) ;
	return ans ;
}


int main(){
	printf("enter size of string\n") ;
	scanf("%d" , &input) ;
	srand(time(0)) ;
	while ( true ) {
		rand_gen() ;
		printf("len : %d / first : %s / second : %s\n" , x , first , second) ;
		for ( int i = 0 ; i < x ; i ++ )
			str[i] = first[i] , key[i] = second[i] ;
		int ans_M = run_M() ;
		int ans_A = run_A() ;
		if ( ans_M != ans_A ) {
			printf("TEST FOUND !!\n") ;
			break ;
		}
	}
	return 0 ;
}
