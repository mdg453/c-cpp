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

int check_list (int argc, char *argv[])
{
    char argv1[ARGV1_LEN] = {0} ;
    int argv2 = 0 ;
    sscanf(argv[1],"%s", argv1) ;
    sscanf(argv[2],"%d", &argv2) ;
    if(argc != ARGV2 && argc != ARGV5){
        fprintf(stderr,"The program receives 1 or 4 arguments only.\n" ) ;
        return 0 ;
    }
    if ((strcmp(argv1, "encode") != 0 ) && (strcmp(argv1 , "decode") != 0))
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

int tester()
{
    if(test_encode_non_cyclic_lower_case_positive_k() &&
       test_encode_cyclic_lower_case_special_char_positive_k() &&
        test_encode_non_cyclic_lower_case_special_char_negative_k() &&
            test_encode_cyclic_lower_case_negative_k() &&
                test_encode_cyclic_upper_case_positive_k() &&
                    test_decode_non_cyclic_lower_case_positive_k() &&
        test_decode_cyclic_lower_case_special_char_positive_k() &&
            test_decode_non_cyclic_lower_case_special_char_negative_k() &&
                test_decode_cyclic_lower_case_negative_k() &&
                    test_decode_cyclic_upper_case_positive_k())
    {
        return 1 ;
    }
    return 0 ;
}

int main (int argc, char *argv[])
{

    if(!(check_list(argc, argv)))
    {
        return EXIT_FAILURE ;
    }
    if (argc == ARGV2) {
        if (strcmp(argv[2],"test") == 0)
        {
            fprintf(stderr,"Usage: cipher test\n" ) ;
            return EXIT_FAILURE ;
        }
        if (tester()) {
            return EXIT_SUCCESS ;
        }
    }
    char argv1[ARGV1_LEN] = {0} ;
    int argv2 = 0 ;
    sscanf(argv[1],"%s", argv1) ;
    sscanf(argv[2],"%d", &argv2) ;
    char *input_path = argv[3] ;
    char *output_path = argv[4] ;
    FILE* in = fopen (input_path, "r") ;
    if (in == NULL)
    {
        fprintf(stderr,"The given file is invalid.\n" ) ;
        return EXIT_FAILURE ;
    }
    char s_in[MAX_CHAR] = {0} ;
    fgets(s_in,MAX_CHAR,in) ;
    FILE *outf = fopen(output_path, "w") ;
    //if (outf == NULL)
    //{
    //    fprintf(stderr,"\nThe given file is invalid.\n" ) ;
    //    return EXIT_FAILURE ;
    //}
    if(strcmp(argv1 , "encode"))
    {
        encode(s_in, argv2) ;
        fputs(s_in, outf) ;
    }
    if(strcmp(argv1 , "decode"))
    {
        decode(s_in, 2) ;
        fputs(s_in, outf) ;
    }

    fclose(in) ;
    fclose(outf) ;
    return EXIT_SUCCESS ;
}
