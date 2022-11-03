#include "cipher.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARGV5 5
#define ARGV1 1

int check_list (int argc, char *argv[])
{
    if(argc != 2 && argc != 5){
        printf("The program receives 1 or 4 arguments only.\n" ) ;
        return 0 ;
    }
    if (argc == 2 && !strcmp(argv[1], "test"))
    {
        printf("Usage: cipher test\n" ) ;
        return 0 ;
    }
    //if ((strcmp(argv[1], "encode") != 0 ) && (strcmp(argv[1] , "decode") != 0))
    //{
    //printf("The given command is invalid.\n");
    //    return EXIT_FAILURE ;
    //}
    if(*argv[4]%1 != 0){
        printf("The given shift value is invalid.\n" ) ;
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
    if (argc == 2) {
        if (tester()) {
            return EXIT_SUCCESS ;
        }
    }
    char *input_path = argv[3] ;
    char *output_path = argv[4] ;
    FILE *in = fopen (input_path, "r") ;
    if (in == NULL)
    {
        printf("\nThe given file is invalid.\n" ) ;
        return EXIT_FAILURE ;
    }
    FILE *out = fopen(output_path, "w") ;
    if (out == NULL)
    {
        printf("\nThe given file is invalid.\n" ) ;
        return EXIT_FAILURE ;
    }
    if(strcmp(argv[1] , "encode"))
    {
        encode(in, argv[2]) ;
        fprintf(out,"%s", in) ;
    }

    fclose(in) ;
    fclose(out) ;
    return 0 ;
}
