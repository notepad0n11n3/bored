#include <stdio.h>

int main(){

  printf("%i %i %c %i %i %c %i %i %c %i %i %s", 
      '1'+'5'+'9',    // 159      %i
      '9'-'2',        // 7        %i
      '9'- 2,         // still 7  %c
      '9'- 2,         // lol jk it's 55   %i
      '5'+ 2,         // 55  'inserte meme tirando una mesa here'  %i
      '5'+ 2,         // actually no, it's 7    %c
       1 * 1,         // one      %i
       0 *'1',        // zero     %i
      '0'*'1',        // fuck yeah still zero   %c
      '1'*'1',        // 2401  'esto es del diable we XD'   %i
      '1'*'0',        // gimme my zero back!                %i
     "  UmU" );       //                                    %s

  return 0;
}
