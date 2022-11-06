#include "cipher.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARGV5 5
#define ARGV1 1
#define ARGV2 2
#define MAX_CHAR 1025
#define ARGV1_LEN 7


int tester()
{
    int flag = 1 ;
    if(!test_encode_non_cyclic_lower_case_positive_k()){
        flag = 0 ;
    }
    if(!test_encode_cyclic_lower_case_special_char_positive_k()){
        flag = 0 ;
    }
    if(!test_encode_non_cyclic_lower_case_special_char_negative_k()){
        flag = 0 ;
    }
    if(!test_decode_non_cyclic_lower_case_positive_k()){
        flag = 0 ;
    }
    if(!test_encode_cyclic_lower_case_negative_k()){
        flag = 0 ;
    }
    if(!test_encode_cyclic_upper_case_positive_k()){
        flag = 0 ;
    }
    if(!test_encode_non_cyclic_lower_case_positive_k()){
        flag = 0 ;
    }
    if(!test_decode_non_cyclic_lower_case_positive_k()){
        flag = 0 ;
    }
    if(!test_decode_cyclic_lower_case_special_char_positive_k()){
        flag = 0 ;
    }
    if(!test_decode_non_cyclic_lower_case_special_char_negative_k()){
        flag = 0 ;
    }
    if(!test_decode_non_cyclic_lower_case_special_char_negative_k()){
        flag = 0 ;
    }
    if(!test_decode_cyclic_lower_case_negative_k()){
        flag = 0 ;
    }
    if(!test_decode_cyclic_upper_case_positive_k()){
        flag = 0 ;
    }
    return flag ;
}

int check_list (int argc, char *argv[])
{

    if(argc != ARGV2 && argc != ARGV5){
        fprintf(stderr,"The program receives 1 or 4 arguments only.\n" ) ;
        return 0 ;
    }
    if (argc == ARGV2) {
        if (strcmp(argv[1],"test") != 0)
        {
            fprintf(stderr,"Usage: cipher test\n" ) ;
            return 0 ;
        }
        if (tester() == 0) {
            return 0 ;
        }

    }
    long int argv2 = strtol(argv[2], NULL, 10) ;
    if ((strcmp(argv[1], "encode") == 0 ) && (strcmp(argv[1] , "decode") == 0))
    {
        fprintf(stderr,"The given command is invalid.\n");
        return 0 ;
    }
    if(argv2%1 != 0){
        fprintf(stderr,"The given shift value is invalid.\n" ) ;
        return 0 ;
    }
    return 1 ;
}


int main (int argc, char *argv[])
{
    int check = check_list(argc, argv) ;
    if(check == 0)
    {
        return EXIT_FAILURE ;
    }
    long int argv2 = strtol(argv[2], NULL, 10);
    char *input_path = argv[3] ;
    char *output_path = argv[4] ;
    FILE* in = fopen ( input_path, "r") ;
    if (in == NULL)
    {
        fprintf(stderr,"The given file is invalid.\n" ) ;
        return EXIT_FAILURE ;
    }
    char s_in[MAX_CHAR] = {0} ;
    fgets(s_in,MAX_CHAR,in) ;
    FILE *outf = fopen(output_path, "w") ;
    if(strcmp(argv[1] , "encode") != 0)
    {
        encode(s_in, argv2) ;
    }
    if(strcmp(argv[1] , "decode") != 0)
    {
        decode(s_in, argv2) ;
    }
    fputs(s_in, outf) ;
    fclose(in) ;
    fclose(outf) ;
    return EXIT_SUCCESS ;


}
