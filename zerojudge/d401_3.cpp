#include<stdio.h>
#include<string.h>

int main(){
    char A[130] ,B[130] ;

    int num[500] ;

    while  (gets(A),gets(B)){
        if (strcmp(A,"END")== 0 && strcmp(B,"END")== 0 )break ;
        //Password settings are not consistent.
        if (strcmp(A,B)!=0 ){
            puts("Password settings are not consistent.") ;
            continue ;
        }
        //Password should contain 8 to 12 characters.
        if (strlen(A)<8 || strlen(A)>12){
            puts("Password should contain 8 to 12 characters.") ;
            continue ;
        }
        //Password should contain at least one upper-case alphabetical character.
        memset(num,0,sizeof(num)) ;
        for (int i=0 ;i<strlen(A);i++ )num[(int)A[i]+200]++ ;
        bool ok=0 ;
        for (int i='A'+200 ;i<='Z'+200;i++ )if (num[i]>0){
            ok=1 ;
            break ;
        }
        if (!ok){
            puts("Password should contain at least one upper-case alphabetical character.") ;
            continue ;
        }
        //Password should contain at least one lower-case alphabetical character.
        ok=0 ;
        for (int i='a'+200 ;i<='z'+200 ;i++ )if (num[i]>0){
            ok=1 ;
            break ;
        }
        if (!ok){
            puts("Password should contain at least one lower-case alphabetical character.") ;
            continue ;
        }
        //Password should contain at least one number.
        ok=0 ;
        for (int i='0'+200 ;i<='9'+200;i++ )if (num[i]>0){
            ok=1 ;
            break ;
        }
        if (!ok){
            puts("Password should contain at least one number.") ;
            continue ;
        }
        //Password should contain at least one special character.
        char P[]=" ~!@#$%^&*()_+|`-=\{}[]:\\\";\'<>?,./" ;
        ok=0 ;
        for (int i=0 ;i<strlen(P);i++ )if (num[P[i]+200]>0){
            ok=1 ;
            break ;
        }
        if (!ok){
            puts("Password should contain at least one special character.") ;
            continue ;
        }
        //Symmetric password is not allowed.
        ok=0 ;
        for (int i=0 ,l=strlen(A);i<l/2 ;i++ )if (A[i]!=A[l-1-i]){
            ok=1 ;
            break ;
        }
        if (!ok){
            puts("Symmetric password is not allowed.") ;
            continue ;
        }
        //Circular password is not allowed.
        ok=1 ;
        for (int i=3 ;i<=6 ;i++ ){
            int pass=0 ;
            for (int j=i ;j<strlen(A) ;j++ ){
                if (A[j]!=A[j%i]){
                    pass=1 ;
                    break ;
                }
            }
            if (pass==0){
                ok=0 ;
                break ;
            }
        }
        if (!ok){
            puts("Circular password is not allowed.") ;
            continue ;
        }
        //OK ----------------
        puts("Password is valid.") ;
    }
}
