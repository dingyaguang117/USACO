/* 
ID: dingyag1
TASK: job 
LANG: C++ 
*/  
#include <stdio.h>
#include <iostream>  
using namespace std;  
const int _n_mach_type_(2), _max_job_(1000), _max_mach_(30), _max_val_(0x7fffffff);  
int n_job, n_mach[_n_mach_type_], tneed[_n_mach_type_][_max_mach_];  
int free_time[_n_mach_type_][_max_mach_], finish_time[_n_mach_type_][_max_job_];  
  
int main(){  
    freopen("job.in", "r", stdin);  
    freopen("job.out", "w", stdout);  
    cin >> n_job >> n_mach[0] >> n_mach[1] ;  
    for( int it=0; it<_n_mach_type_; it++ ) {  
        for( int im=0; im<n_mach[it]; im++)  
            cin >> tneed[it][im];  
        for(int ij=0; ij<n_job; ij++) {  
            register int min_finish = _max_val_, mach_asgn ;   
            for (int im=0; im<n_mach[it]; im++) {  
                if( min_finish <= free_time[it][im] + tneed[it][im] )  
                    continue ;  
                min_finish = free_time[it][im] + tneed[it][im] , mach_asgn = im;   
            }  
            free_time[it][mach_asgn] = finish_time[it][ij] = min_finish ;  
        }  
    }  
    cout << finish_time[0][n_job-1] <<' ';  
   
    int max_finish = 0 ;   
    for( int ij=0; ij<n_job; ij++)  
        if( max_finish < finish_time[0][ij] + finish_time[1][n_job-ij-1] )  
            max_finish = finish_time[0][ij] + finish_time[1][n_job-ij-1] ;  
    cout << max_finish <<endl;  
    return 0;  
} 